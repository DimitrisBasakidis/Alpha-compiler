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
%type <expression> expr stmt assignexpr
//%type <expr_token> 
%type <str_val> lvalue
%type <str_val> member primary call objectdef funcdef const idlist ifstmt whilestmt forstmt returnstmt elist block callsuffix normcall methodcall indexed indexedelem

%%


program: statements {printf("My program:: \n");}
       ;

statements: statements stmt {;}
          | stmt
          ;


stmt: expr SEMICOLON {printf("Stmt::%p \n",$1);}
      | ifstmt {printf("found ifstmt %p\n", yyval.str_val);}
      | whilestmt {printf("found whilestmt\n");}
      | forstmt {printf("found forstmt\n");}
      | returnstmt {printf("found returnstmt\n");}
      | BRK SEMICOLON {printf("found brk stmt\n");}
      | CONTINUE SEMICOLON {printf("found continuestmt\n");}
      | block {printf("found block\n");}
      | funcdef {printf("found funcdef\n");}
      | SEMICOLON {printf("found semicolon\n");}
      ;

expr: assignexpr {printf("Expr :: %p\n", $$);}
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

assignexpr: lvalue ASSIGN expr {printf("Assign expr :: %s \n", $$); insert_symbol(symtable, create_node($1, scope, yylineno, (scope == 0) ? GLOBALVAR : LOCALVAR, ACTIVE)); } 
          ;

primary: lvalue {printf("Primary :: %p\n",$1);}
      | call {;}
      | objectdef {;}
      | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS {;}
      | const {;}
      ;

lvalue: ID {printf("ID :: %p scope %d\n", $$, scope);}
      | LOCAL ID {;}
      | DOUBLE_COLON ID {;}
      | member {;}
      ;
      
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

elist: expr {;}
     | expr COMMA elist {;}
     {;}
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

block: LEFT_BRACKET {scope++;} statements RIGHT_BRACKET {scope--;}
     | LEFT_BRACKET {scope++;} RIGHT_BRACKET {scope--;}

     ;

funcdef: FUNCTION ID LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block {;}
       | FUNCTION ID LEFT_PARENTHESIS RIGHT_PARENTHESIS block {;}
       ;

const: INTEGER  { printf("int %d scope %d\n", yyval.int_val, scope);} 
     | REAL { printf("real %f scope %d\n", yyval.real_val, scope);} 
     | STRING { printf("str %s scope %d\n",yyval.str_val, scope);} 
     | NIL {;} 
     | TRUE_KW {;}
     | FALSE_KW {;}
     ;


idlist: ID {;}
      | ID COMMA idlist {;}
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

  symtable = create_table();

  yyparse();
  
  print_hash(symtable);

  free_table(symtable);

  return 0;
}
