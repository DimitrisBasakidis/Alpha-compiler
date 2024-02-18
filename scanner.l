%{
#include <stdio.h>
#include <stdlib.h>
#include "utilities/token_list.h"
 
#define YY_DECL int alpha_yylex(void *list)

%}

%option noyywrap 
%option yylineno

id [a-zA-Z][a-zA-Z_0-9]*
integer [0-9][0-9]*
real [0-9]+[.][0-9]+
whitespace " \t\n\r"

%%
{id} {
  insert(list, yylineno, strdup(yytext));
  //printf("Detected id: %s and line %d\n", yytext, yylineno);
}

{integer} {
  insert(list, yylineno, strdup(yytext));
  //printf("Detected integer: %s and line %d\n", yytext, yylineno);
}

{real} {
  insert(list, yylineno, strdup(yytext));
}

{whitespace} {}

"\"" { //add FSM for string 
  char c;
  printf("\"");

  while ((c = input()) != '"') {
    printf("%c", c);
  }
  printf("\n");
  
}

\n { }

%%

int main(int argc, char* argv[]){
  FILE* file;

  if (argc > 1) {
    if (!(yyin = fopen(argv[1], "r"))) {
      perror("cant open file"); 
      return 1;
    }
  }

  token_list *list = create_list();

  alpha_yylex(list);

  print_list(list, stdout);
  free_list(list);
  return  0;
}
