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
  char* id;
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

%type <int_val>   expression

%%


program:
      expressions {;}
      | {;}
      ;
 
expressions:
      expressions expr {;}
      | expr {;}
      ;

expr: expression SEMICOLON {
  printf("result : %d\n", $1);
  }

expression: INTEGER { $$ = $1; }
          | ID  ASSIGN expression { printf("%s = %d\n", $1, $3);}
          | expression PLUS expression { $$ = $1 + $3; }
          | expression MINUS expression { $$ = $1 - $3; }
          | expression SLASH expression { $$ = $1 / $3; }
          | expression MULTIPLY expression { $$ = $1 * $3; }
          | LEFT_PARENTHESIS expression RIGHT_PARENTHESIS { $$ = $2; }
          | MINUS expression %prec UMINUS { $$ = -$2; }
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
