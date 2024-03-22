%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
%token <id>       ID STRING
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

%type <int_val> expr assignexpr term
%type <str_val> lvalue
%type <str_val> member primary call objectdef funcdef const idlist ifstmt whilestmt forstmt returnstmt elist block callsuffix normcall methodcall indexed indexedelem

%%


program: program stmt {;}
       | stmt {;}
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
      ;

expr: assignexpr {;}
    | expr PLUS expr { $$ = $1 + $3; }
    | expr MINUS expr { $$ = $1 - $3; }
    | expr SLASH expr { $$ = $1 / $3; }
    | expr MULTIPLY expr { $$ = $1 * $3; }
    | LEFT_PARENTHESIS expr RIGHT_PARENTHESIS { $$ = $2; }
    | MINUS expr  %prec UMINUS { $$ = -$2; }
    | term {;}
    ;

op: PLUS | MINUS | MULTIPLY | SLASH | MODULO | GREATER_THAN | GREATER_EQUAL | LESSER_THAN | LESSER_EQUAL | EQUAL | NOT_EQUAL | AND | OR
 ;

term: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS {;}
    | MINUS expr {;}
    | NOT expr {;}
    | INCREMENT lvalue {;}
    | lvalue INCREMENT {;}
    | DECREMENT lvalue {;}
    | lvalue DECREMENT {;}
    | primary {;}
    ; 

assignexpr: lvalue ASSIGN expr {printf("%s = %p\n", $1, $3); } // segmentation fault  because $3 is on a temp buffer and its freed after it leaves the rule
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

methodcall: DOUBLE_DOT ID LEFT_PARENTHESIS elist RIGHT_PARENTHESIS
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

const: INTEGER 
     | REAL 
     | STRING { printf("t: %p, %p\n",yyval.str_val, $$);} 
     | NIL 
     | TRUE_KW 
     | FALSE_KW
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

returnstmt: RETURN_KW {;}
          | RETURN_KW expr {;}
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
