%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilities/symbol_table.h"
#include "utilities/structs.h"

int yylex(void);
int yyerror(const char *error_msg);

int scope = 0;

extern int yylineno;
extern char *yytext;
extern FILE *yyin;

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
//%type <expr_token> 
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
      | BRK SEMICOLON {}
      | CONTINUE SEMICOLON {}
      | block {}
      | funcdef {}
      | SEMICOLON {}
      ;

expr: assignexpr {}
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
    | INCREMENT lvalue {;}
    | lvalue INCREMENT {;}
    | DECREMENT lvalue {;}
    | lvalue DECREMENT {;}
    | primary {;}

    ; 


assignexpr: lvalue ASSIGN expr { 
  entry = lookup(symtable, lists, $1, (scope == 0) ? GLOBALVAR : LOCALVAR, scope, HASH);
  if (entry == NULL) {
    SymbolTableEntry *node = create_node($1, scope, yylineno, (scope == 0) ? GLOBALVAR : LOCALVAR, ACTIVE);
    insert_symbol(symtable, node);
    insert_to_scope(lists, node, scope);
    
  } else {
    switch (entry->type) {
      
      case LIBFUNC:
      case USERFUNC: 
        printf("redefining %s function:", (entry->type == LIBFUNC) ? "library" : "user");
        printf("\033[31m");
        printf(" %s", $1);
        printf("\033[0m");
        printf(" line: %d\n", yylineno);
        exit(TRUE);  
    }

  }
} 
;

primary: lvalue { entry = lookup(symtable, lists, $1, (scope == 0) ? GLOBALVAR : LOCALVAR, scope, HASH);
  if (entry == NULL) {
    SymbolTableEntry *node = create_node($1, scope, yylineno, (scope == 0) ? GLOBALVAR : LOCALVAR, ACTIVE);
    insert_symbol(symtable, node);
    insert_to_scope(lists, node, scope);
  } else {
    switch (entry->type) {
      
      case LIBFUNC:
      case USERFUNC: 
        printf("redefining %s function:", (entry->type == LIBFUNC) ? "library" : "user");
        printf("\033[31m");
        printf(" %s", $1);
        printf("\033[0m");
        printf(" line: %d\n", yylineno);
        exit(TRUE);  
    }

  };}
      | call {;}
      | objectdef {;}
      | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS {;}
      | const {;}
      ;

lvalue: ID { // ELEGXOYME STON HASHTABLE AN UPARXEI TO ONOMA TOU ID(print error msg gia redefining lib kai user functions) KAI EIANI ACTVIE ALLWS VAZOYME TO ID STO HASHTABLE.
$$ = $1;
  // entry = lookup(symtable, lists, $1, (scope == 0) ? GLOBALVAR : LOCALVAR, scope, HASH);
  // if (entry == NULL) {
  //   SymbolTableEntry *node = create_node($1, scope, yylineno, (scope == 0) ? GLOBALVAR : LOCALVAR, ACTIVE);
  //   insert_symbol(symtable, node);
  //   insert_to_scope(lists, node, scope);
  // } else {
  //   switch (entry->type) {
      
  //     case LIBFUNC:
  //     case USERFUNC: 
  //       printf("redefining %s function:", (entry->type == LIBFUNC) ? "library" : "user");
  //       printf("\033[31m");
  //       printf(" %s", $1);
  //       printf("\033[0m");
  //       printf(" line: %d\n", yylineno);
  //       exit(TRUE);  
  //   }

  // }
} 

      | LOCAL ID { // kanoume lookup sto trexon scope kai ama einai libfunction tote exoyme shadowing kai meta ama einai null tote to vazoume sto table 
        entry = lookup(symtable, lists, $2, LOCALVAR, scope, SCOPE); 

        if (lookup_lib_func($2) == TRUE) {
            printf("shadowing library function: ");
            printf("\033[31m");
            printf(" %s", $2);
            printf("\033[0m");
            printf(" line: %d\n", yylineno);
            exit(TRUE);  
        }

        if (entry == NULL) {
            SymbolTableEntry *node = create_node($2, scope, yylineno, LOCALVAR, ACTIVE);
            insert_symbol(symtable, node);
            insert_to_scope(lists, node, scope);
        } else {
          printf("entr->rype %d %d\n", entry->type, entry->value.funcVal->line);
          if (entry->type == USERFUNC) {
            printf("redefining user function: ");
            printf("\033[31m");
            printf(" %s", $2);
            printf("\033[0m");
            printf(" line: %d\n", yylineno);
            exit(TRUE);  
          } else if (entry->type == FORMAL) {
            printf("redefining formal argument: ");
            printf("\033[31m");
            printf(" %s", $2);
            printf("\033[0m");
            printf(" line: %d\n", yylineno);
            exit(TRUE);
          }
        }

}

      | DOUBLE_COLON ID { 
        entry = lookup(symtable, lists, $2, GLOBALVAR, 0, SCOPE); 

        if (entry == NULL) {
          printf("No global variable");
          printf("\033[31m");
          printf(" ::%s", $2);
          printf("\033[0m");
          printf(" exists  line: %d\n", yylineno);
          exit(TRUE);  
        } 
                        }
      | member {;}
      
      
member: lvalue DOT ID {;}
      | lvalue LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET {;}
      | call DOT ID {;}
      | call LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET {;}
      ;

call: call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {;}
      | lvalue callsuffix {;}
      | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {;}
      ;

callsuffix: normcall {;}
          | methodcall {;}
          ;

normcall: LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {;} 
        ;

methodcall: DOUBLE_DOT ID LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {;}
          ;

elist: expr { printf("here %p\n", $1);}
     | expr COMMA elist { $$ = $1;}
     |{;}
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
        print = "library function";
        break;
      case USERFUNC: 
        print = "user function";
        break;

      case GLOBALVAR:
        print = "global variable";
        break; 

      case LOCALVAR: 
        print = "local variable";
        break;
    }

    printf("redefining %s:", print);
    printf("\033[31m");
    printf(" %s", $2);
    printf("\033[0m");
    printf(" line: %d\n", yylineno);
    exit(TRUE);

  }
  // else {

  // int flag = lookup(symtable, $2, USERFUNC, scope, (scope == 0) ? FUNC : LOCAL_FUNC);
  //                       printf("flag %d\n", flag);
  //                        if (flag == FALSE) {
  //                           SymbolTableEntry *node = create_node($2, scope, yylineno, USERFUNC, ACTIVE);;
  //                           insert_symbol(symtable, node);
  //                           insert_to_scope(lists, node, scope);
  //                         } else if (flag == LOCALVAR) {
                            
  //                         }
                        }
       ;

funcdef: func_id LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block {;}
       | func_id LEFT_PARENTHESIS RIGHT_PARENTHESIS block {;}
       ;

const: INTEGER  { printf("int %d scope %d\n", yyval.int_val, scope);} 
     | REAL { printf("real %f scope %d\n", yyval.real_val, scope);} 
     | STRING { printf("str %s scope %d\n",yyval.str_val, scope);} 
     | NIL {;} 
     | TRUE_KW {;}
     | FALSE_KW {;}
     ;

idlist_id: ID { 

  if (lookup_lib_func($1) == TRUE) {
    printf("shadowing lib function:");
    printf("\033[31m");
    printf(" %s", $1);
    printf("\033[0m");
    printf(" line: %d\n", yylineno);
    exit(TRUE);
  }

  entry = lookup(symtable, lists, $1, GLOBALVAR, scope, SCOPE);
  if (entry != NULL) {
    printf("redefining argument:");
    printf("\033[31m");
    printf(" %s", $1);
    printf("\033[0m");
    printf(" line: %d\n", yylineno);
    exit(TRUE);
  } 

  
  SymbolTableEntry *node = create_node($1, scope + 1, yylineno, FORMAL, ACTIVE);
  insert_symbol(symtable, node);
  insert_to_scope(lists, node, scope + 1);
};

idlist: idlist_id {;}
      | idlist_id COMMA idlist {;}
      ;

ifstmt: IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt {/**/} %prec LOWER_THAN_ELSE
      | IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt {;}
      ;

whilestmt: WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt {;}
         ;

forstmt: FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist RIGHT_PARENTHESIS stmt {;}
       ;

returnstmt: RETURN_KW SEMICOLON {;}
          | RETURN_KW expr SEMICOLON {;}
          ;

%%

int yyerror(const char *error_msg) {
  fprintf(stderr, "something went bad %s, line %d\n", error_msg, yylineno);

  return 1;
}

int main(int argc, char **argv) {

  if (argc > 1) {
    if (!(yyin = fopen(argv[1], "r"))) {
      perror("Cant open file"); 
      return 1;
    }
  }

  lists = create_scope_lists();
  
  symtable = create_table();

  add_lib_func(symtable, lists);
  yyparse();
  
// print_hash(symtable);
print_scopes(lists);

  free_table(symtable);

  return 0;
}

/* x = 2;
function foo() {
  function foo(bar) {
    local foo = 2;
    return bar + foo;
  }
  {
    local foo = [{foo:[{foo:foo}]}];
    foo.foo..foo(::foo);
  }
  x = (function(){});
}
*/
