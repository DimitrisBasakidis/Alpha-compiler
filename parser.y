%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utilities/structs.h"

int yylex(void);
int yyerror(const char *error_msg);

extern int yylineno;
extern char *yytext;
extern FILE *yyin;

%}

%union {
  int int_val;
  char *str_val;
  float real_val;
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

%type <int_val> expr term assignexpr
//%type <expr_token> 
%type <str_val> lvalue
%type <str_val> member primary call objectdef funcdef const idlist ifstmt whilestmt forstmt returnstmt elist block callsuffix normcall methodcall indexed indexedelem

%%


program: statements {;}
       ;

statements: statements stmt {;}
          |
          ;


stmt: expr SEMICOLON {;}
      | ifstmt {;}
      | whilestmt {;}
      | forstmt {;}
      | returnstmt {;}
      | BRK SEMICOLON {;}
      | CONTINUE SEMICOLON {;}
      | block {;}
      | funcdef {;}
      | SEMICOLON {;}
      ;

expr: assignexpr {;}
    | expr PLUS expr { $$ = $1 + $3; }
    | expr MINUS expr { $$ = $1 - $3; }
    | expr SLASH expr { $$ = $1 / $3; }
    | expr MULTIPLY expr { $$ = $1 * $3; }
    | expr MODULO expr { $$ = $1 % $3; }
    | expr GREATER_THAN expr { $$ = $1 > $3; }
    | expr GREATER_EQUAL expr { $$ = $1 >= $3; }
    | expr LESSER_THAN expr { $$ = $1 < $3; }
    | expr LESSER_EQUAL expr { $$ = $1 <= $3; }
    | expr EQUAL expr { $$ = $1 == $3; }
    | expr NOT_EQUAL expr { $$ = $1 != $3; }
    | expr AND expr { $$ = $1 && $3; }
    | expr OR expr { $$ = $1 || $3; }
    | term {;}

term:  NOT expr {;}
    | INCREMENT lvalue {;}
    | lvalue INCREMENT {;}
    | DECREMENT lvalue {;}
    | lvalue DECREMENT {;}
    | primary {;}
    ; 

assignexpr: lvalue ASSIGN expr {printf("%s = %d\n", $1, $3); } 
          ;

primary: lvalue
      | call {;}
      | objectdef {;}
      | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS {;}
      | const {;}
      ;

lvalue: ID {;}
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

block: LEFT_BRACKET stmt RIGHT_BRACKET {;}
     | LEFT_BRACKET RIGHT_BRACKET {;}
     ;

funcdef: FUNCTION ID LEFT_PARENTHESIS idlist RIGHT_PARENTHESIS block {;}
       | FUNCTION ID LEFT_PARENTHESIS RIGHT_PARENTHESIS block {;}
       ;

const: INTEGER  { printf("int %d\n", yyval.int_val);} 
     | REAL { printf("real %f\n", yyval.real_val);} 
     | STRING { printf("str %s\n",yyval.str_val);} 
     | NIL {;} 
     | TRUE_KW {;}
     | FALSE_KW {;}
     ;

idlist: ID {;}
      | COMMA ID idlist {;}
      {;}
      ;

ifstmt: IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt ELSE stmt {;}
      | IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt {;}
      ;

whilestmt: WHILE LEFT_PARENTHESIS expr RIGHT_PARENTHESIS stmt {;}
         ;

forstmt: FOR LEFT_PARENTHESIS elist SEMICOLON expr SEMICOLON elist SEMICOLON RIGHT_PARENTHESIS stmt {;}
       ;

returnstmt: RETURN_KW SEMICOLON {;}
          | RETURN_KW expr SEMICOLON {;}
          ;

%%

int yyerror(const char *error_msg) {
  fprintf(stderr, "something went bad %s\n", error_msg);

  return 1;
}

int main(int argc, char **argv) {
  if (argc > 1) {
    if (!(yyin = fopen(argv[1], "r"))) {
      perror("Cant open file"); 
      return 1;
    }
  }

  yyparse();

  return 0;
}
