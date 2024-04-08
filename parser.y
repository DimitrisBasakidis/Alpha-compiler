%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilities/symbol_table.h"
#include "utilities/structs.h"

#define YYERROR_VERBOSE 1

int yylex(void);
int yyerror(const char *error_msg);
void print_errors(const char *error_msg, char *token, const char *error_type);

const char *file_name;

int scope = 0;
int func_in_between = 0;
int is_return_kw = 0;
int from_func_call = 0;
int in_loop = 0;
int from_elist = 0;
int while_loop = 0;
int for_loop = 0;
int if_stmt = 0;
int global_val_exists = 0;
int is_local_kw = 0;

extern int yylineno;
extern char *yytext;
extern FILE *yyin;

extern int column;
extern char *lineptr;

SymTable *symtable;
scopeLists *lists;

size_t nfuncs = 0U;
SymbolTableEntry *entry;


%}

%union {
  int int_val;
  char *str_val;
  float real_val;
  struct expr_t* expression;
}

%token <int_val>  INTEGER
%token <str_val>  ID STRING
%token <real_val> REAL

%right ASSIGN
%left OR
%left AND
%nonassoc EQUAL NOT_EQUAL
%nonassoc GREATER_THAN GREATER_EQUAL LESSER_THAN LESSER_EQUAL LOWER_THAN_ELSE 
%left PLUS MINUS
%left MULTIPLY SLASH MODULO
%right UMINUS NOT INCREMENT DECREMENT
%left DOT DOUBLE_DOT
%left LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET
%left LEFT_PARENTHESIS RIGHT_PARENTHESIS
%token SEMICOLON LEFT_BRACKET RIGHT_BRACKET COMMA COLON DOUBLE_COLON
%token IF ELSE WHILE FOR FUNCTION RETURN_KW BRK CONTINUE LOCAL TRUE_KW FALSE_KW ENDL NIL

%type <int_val> term 
%type <expression> stmt assignexpr
%type <str_val> lvalue fname expr
%type <str_val> member primary call objectdef funcdef const idlist ifstmt whilestmt forstmt returnstmt elist block callsuffix normcall methodcall indexed indexedelem

%%


program: statements {}
       ;

statements: statements stmt {;}
          | stmt
          ;


stmt: expr SEMICOLON {}
      | ifstmt {}
      | whilestmt {}
      | forstmt {}
      | returnstmt {}
      | BRK SEMICOLON {if (in_loop == 0){
                         print_errors("use of keyword outside of function", "continue", "grammar");
                         exit(TRUE);
                       }}
      | CONTINUE SEMICOLON {if (in_loop == 0){
                              print_errors("use of keyword outside of function", "continue", "grammar");
                              exit(TRUE);
                            }
                            }
      | block {}
      | funcdef {}
      | SEMICOLON {}
      ;

expr: assignexpr {;}
    | expr PLUS expr {;}
    | expr MINUS expr {;}
    | expr SLASH expr {;}
    | expr MULTIPLY expr {;}
    | expr MODULO expr {;}
    | expr GREATER_THAN expr {;}
    | expr GREATER_EQUAL expr {;}
    | expr LESSER_THAN expr {;}
    | expr LESSER_EQUAL expr {;}
    | expr EQUAL expr {;}
    | expr NOT_EQUAL expr {;}
    | expr AND expr {;}
    | expr OR expr {;}
    | term {;}

term:  NOT expr {;}
    | MINUS expr {;}
    | LEFT_PARENTHESIS expr RIGHT_PARENTHESIS {;}
    | INCREMENT lvalue {
      entry = lookup(symtable, lists, $2, (lookup_lib_func($2) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);

      if (entry != NULL && entry->type == USERFUNC || entry->type == LIBFUNC) {
          char *msg = (entry->type == USERFUNC) ? "cannot increment user function" : "cannot increment library function";
          print_errors(msg, $2, "grammar");
          exit(TRUE); 
      }
    }
    | lvalue INCREMENT {
      entry = lookup(symtable, lists, $1, (lookup_lib_func($1) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);

      if (entry != NULL && entry->type == USERFUNC || entry->type == LIBFUNC) {

          char *msg = (entry->type == USERFUNC) ? "cannot increment user function" : "cannot increment library function";
          print_errors(msg, $1, "grammar");
          exit(TRUE); 
      }
    }
    | DECREMENT lvalue {
      entry = lookup(symtable, lists, $2, (lookup_lib_func($2) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);
      if (entry != NULL && entry->type == USERFUNC || entry->type == LIBFUNC) {
          char *msg = (entry->type == USERFUNC) ? "cannot decriment user function" : "cannot decriment library function";
          print_errors(msg, $2, "grammar");
          exit(TRUE); 
      }
    }
    | lvalue DECREMENT {entry = lookup(symtable, lists, $1, (lookup_lib_func($1) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);

      if (entry != NULL && entry->type == USERFUNC || entry->type == LIBFUNC) {
          char *msg = (entry->type == USERFUNC) ? "cannot decriment user function" : "cannot decriment library function";
          print_errors(msg, $1, "grammar");
          exit(TRUE); 
      }
    }
    | primary {;}
    ; 


assignexpr: lvalue ASSIGN expr { 

  entry = lookup(symtable, lists, $1, (scope == 0) ? GLOBALVAR : LOCALVAR, scope, HASH);

  if (entry == NULL) {
    if (from_func_call) {
      print_errors("accessing undefined function", $1, "grammar");
      exit(TRUE); 
    }
    SymbolTableEntry *node = create_node($1, scope, yylineno, (scope == 0) ? GLOBALVAR : LOCALVAR, ACTIVE);
    insert_symbol(symtable, node);
    insert_to_scope(lists, node, scope);

  } else {
    if ((func_in_between > 1 || entry->value.varVal->scope >= scope) && !global_val_exists) {

      switch (entry->type) {

        case LOCALVAR:
          if (entry->value.varVal->scope == scope) {
            if (is_local_kw == 1 && entry->value.varVal->line != yylineno) {
              print_errors("redefinition of variable", $1, "grammar");
              exit(TRUE); 
            }
          } else if (!for_loop && !while_loop) {
            print_errors("cant access local varible outside of scope", $1, "grammar");
            exit(TRUE);  
          }
          break;

        case LIBFUNC:
        case USERFUNC: 
          if (from_func_call) break;

          char *msg = (entry->type == LIBFUNC) ? "redefining library function" : "redefining user function";
          print_errors(msg, $1, "grammar");
          exit(TRUE); 

        case FORMAL:
          if (entry->value.varVal->scope != scope) {
            print_errors("cant access formal argument outside of scope", $1, "grammar");
            exit(TRUE);
          }
          
      }
    } else if (entry->type == USERFUNC || entry->type == LIBFUNC) {
      char *temp = (entry->type == USERFUNC) ? "cannot assign value to user function" : "cannot assign value to library function";
      print_errors(temp, $1, "grammar");
      exit(TRUE);
    }
  if (!global_val_exists) global_val_exists = 0;
  }
  is_local_kw = 0;
  if (from_func_call > 0) from_func_call--;
} 
;

primary: lvalue { 
  entry = lookup(symtable, lists, $1, (scope == 0) ? GLOBALVAR : LOCALVAR, scope, HASH);

  if (entry == NULL) {
    if (from_elist) {
      print_errors("using undefined variable as call argument", $1, "grammar");
      exit(TRUE);
    }

    else {
      print_errors("using undefined variable", $1, "grammar");
      exit(TRUE);
    }

    SymbolTableEntry *node = create_node($1, scope, yylineno, (scope == 0) ? GLOBALVAR : LOCALVAR, ACTIVE);
    insert_symbol(symtable, node);
    insert_to_scope(lists, node, scope);

  } else {

    switch (entry->type) {

      case LIBFUNC:
      case USERFUNC: 
        if (entry->value.varVal->scope == scope && is_return_kw == 0) {
          char *msg = (entry->type == LIBFUNC) ? "redefining library function" : "redefining user function";
          print_errors(msg, $1, "grammar");
          exit(TRUE);
        }  
        break;


        case FORMAL: 
          if (entry->value.varVal->scope != scope) {
            print_errors("calling formal argument outside of scope", $1, "grammar");
            exit(TRUE);
          }
          break;

        case LOCALVAR:
          if (entry->value.varVal->scope != scope && !for_loop && !if_stmt) {

            print_errors("calling local variable outside of scope", $1, "grammar");
            exit(TRUE);
          }
          break;
    }

  };
  
  is_return_kw = 0;
  if (from_elist) from_elist = 0;
}
| call { 

    entry = lookup(symtable, lists, $1, (lookup_lib_func($1) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);
    SymbolTableEntry *temp = NULL;
    if (entry == NULL) {
        print_errors("calling undefined function:", $1, "grammar");        
        exit(TRUE);  
     } else {

    switch (entry->type) {
      
      case LOCALVAR:
      case GLOBALVAR:

        temp = is_func(lists, $1, scope);
        if (temp != NULL && temp->value.funcVal->scope <= scope) break;
        char *msg = (entry->type == LIBFUNC) ? "calling local variable as a function" : "calling global variable as a function";
        print_errors(msg, $1, "grammar");
        exit(TRUE);  
    }
  };
}
      | objectdef {;}
      | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS {;}
      | const {;}
      ;

lvalue: ID { // ELEGXOYME STON HASHTABLE AN UPARXEI TO ONOMA TOU ID(print error msg gia redefining lib kai user functions) KAI EIANI ACTVIE ALLWS VAZOYME TO ID STO HASHTABLE.
          $$ = $1;
           } 

      | LOCAL ID { // kanoume lookup sto trexon scope kai ama einai libfunction tote exoyme shadowing kai meta ama einai null tote to vazoume sto table 
        entry = lookup(symtable, lists, $2, LOCALVAR, scope, SCOPE); 
        is_local_kw = 1;
        if (lookup_lib_func($2) == TRUE) {
            print_errors("shadowing library function:", $2, "grammar");
            exit(TRUE);  
        }

        if (entry == NULL) {
            SymbolTableEntry *node = create_node($2, scope, yylineno, LOCALVAR, ACTIVE);
            insert_symbol(symtable, node);
            insert_to_scope(lists, node, scope);
        } else {
          if (entry->type == USERFUNC) {
            print_errors("redefining user function:", $2, "grammar");
            exit(TRUE);  
          } else if (entry->type == FORMAL) {
            print_errors("redefining formal argument:", $2, "grammar");
            exit(TRUE);
          }
        }
        $$ = $2;

}

| DOUBLE_COLON ID { 
  entry = lookup(symtable, lists, $2, GLOBALVAR, 0, SCOPE); 
  if (entry == NULL) {
    print_errors("no global variable exists", $2, "grammar");
    exit(TRUE);  
  } else global_val_exists = 1;
  $$ = $2;
  }
| member {;}

      
member: lvalue DOT ID {;}
      | lvalue LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET {;}
      | call DOT ID {from_func_call++;}
      | call LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET {;}
      ;

call: call LEFT_PARENTHESIS {from_elist = 1;} elist  RIGHT_PARENTHESIS {;}
      | lvalue {;} callsuffix {;}
      | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {;}
      ;

callsuffix: normcall {;}
          | methodcall {;}
          ;

normcall: LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {;} 
        ;

methodcall: DOUBLE_DOT ID LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {;}
          ;

elist: expr {;}
     | expr COMMA elist { $$ = $1;}
     | {;}
     ;

objectdef: LEFT_SQUARE_BRACKET elist RIGHT_SQUARE_BRACKET {;}
         | LEFT_SQUARE_BRACKET indexed RIGHT_SQUARE_BRACKET {;}
         ;

indexed: indexedelem {;}
       | indexedelem COMMA indexed {;}
       {;}
       ;

indexedelem: LEFT_BRACKET expr COLON expr RIGHT_BRACKET {;}
           ;


block: LEFT_BRACKET {scope++;} statements RIGHT_BRACKET {hide_scope(lists, scope--);}
     | LEFT_BRACKET {scope++;} RIGHT_BRACKET {hide_scope(lists, scope--);}
     ;

fname: ID { $$ = $1;}
        | {
          unsigned int count = 0, n = nfuncs;
          while (n != 0) { n /= 10; count++;}
          char *temp = malloc(sizeof(char) * nfuncs + 6);
          sprintf(temp , "_func_%u", (unsigned int) nfuncs++);
          $$ = temp;
          }
        ;

func_id: FUNCTION fname{ // elegxoume ama uparxoyn ta entries sto hashtable kai einai active, an nai ektypwnoyme ta katallhla error messages
// alliws ta vazoume sto table
  entry = lookup(symtable, lists, $2, USERFUNC, scope, SCOPE);
  
  if (entry == NULL) {
    SymbolTableEntry *node = create_node($2, scope, yylineno, USERFUNC, ACTIVE);
    insert_symbol(symtable, node);
    insert_to_scope(lists, node, scope);
  } else {
    char *print = NULL;
    switch (entry->type) {

      case LIBFUNC:
        print = "redefining library function";
        break;
      case USERFUNC: 
        print = "redefining user function";
        break;

      case GLOBALVAR:
        print = "redefining global variable";
        break; 

      case LOCALVAR: 
        print = "redefining local variable";
        break;
      case FORMAL:
        print = "redefining formal argument";
        break;

      default:
        print = "vaggeli agapiesai";  
        break;
    }

    print_errors(print, $2, "grammar");
    exit(TRUE);
  }
};

funcdef: func_id LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS {func_in_between++;}block {func_in_between--;}
       | func_id LEFT_PARENTHESIS RIGHT_PARENTHESIS {func_in_between++;} block {func_in_between--;}
       ;

const: INTEGER  {;} 
     | REAL { ;} 
     | STRING { ;} 
     | NIL {;} 
     | TRUE_KW {;}
     | FALSE_KW {;}
     ;

idlist_id: ID { 

  if (lookup_lib_func($1) == TRUE) {
    print_errors("shadowing lib function:", $1, "grammar");
    exit(TRUE);
  }

  entry = lookup(symtable, lists, $1, GLOBALVAR, scope, SCOPE);
  if (entry != NULL && entry->value.varVal->scope != 0 && entry->type == USERFUNC) {
    print_errors("redefining argument", $1, "grammar");
    exit(TRUE);
  } 

  entry = lookup(symtable, lists, $1, FORMAL, scope + 1, SCOPE);
  if (entry != NULL) {
    print_errors("redefining argument", $1, "grammar");
    exit(TRUE);
  } 

  
  SymbolTableEntry *node = create_node($1, scope + 1, yylineno, FORMAL, ACTIVE);
  insert_symbol(symtable, node);
  insert_to_scope(lists, node, scope + 1);
};

open_for: FOR {for_loop++;};

open_while: WHILE {while_loop++;};

open_if: IF {if_stmt++;}

idlist: idlist_id {;}
      | idlist_id COMMA idlist {;}
      ;

ifstmt: open_if LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt {if_stmt--;} %prec LOWER_THAN_ELSE
      | open_if LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt {if_stmt--;}
      ;

whilestmt: open_while LEFT_PARENTHESIS expr RIGHT_PARENTHESIS {in_loop++;}stmt {in_loop--; while_loop--;} 
         ;

forstmt: open_for LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS {in_loop++;} stmt  {in_loop--; for_loop--;}
       ;

returnstmt: RETURN_KW {
  if (func_in_between == 0){
    print_errors("use of keyword outside of function", "return", "grammar");
    exit(TRUE);
  }
}SEMICOLON {;}

| RETURN_KW {
  if (func_in_between == 0){    
    print_errors("use of keyword outside of function", "return", "grammar");

    exit(TRUE);
  }
} expr SEMICOLON { is_return_kw = 1;};

%%

int yyerror(const char *error_msg) {
  print_errors(yylval.str_val, yytext, "syntax");
  exit(0);
}

void print_errors(const char *error_msg, char *token, const char *error_type) {
  int count = 1;
  int temp = yylineno;

  fprintf(stderr, "%s:%d ",file_name + 1, yylineno);
  printf("\033[31merror:\033[0m %s\n", error_type);   

  while (temp) {temp /= 10; count++;}; 
  printf("  %d | %s",yylineno, error_msg);
  printf("\033[31m");
  printf(" %s", token);
  printf("\033[0m\n");
  printf("%*s|", count + 2, "");
  for (int i = 0; i < strlen(error_msg) + 2; i++) printf(" ");
  printf("\033[31m^\033[0m");
  if (strlen(token) > 1) {
    for (int i = 0; i < strlen(token) - 1; i++) printf("\033[31m~\033[0m");
  }
  printf("\n%*s|\n", count + 2, "");



}


int main(int argc, char **argv) {

  if (argc > 1) {
    if (!(yyin = fopen(argv[1], "r"))) {
      perror("Cant open file"); 
      return 1;
    }
  }

  file_name = strrchr(argv[1], '/');
  lists = create_scope_lists();
  
  symtable = create_table();

  add_lib_func(symtable, lists);
  yyparse();
  
  print_scopes(lists);

  free_table(symtable);

  return 0;
}

