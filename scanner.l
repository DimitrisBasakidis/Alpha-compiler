%{
#include <stdio.h>
#include <stdlib.h>
#include "utilities/token_list.h"

 
#define YY_DECL int alpha_yylex(void *list)

#define BUFZ 1024

%}

%option noyywrap 
%option yylineno



and               "and"
assign            "="
brk               "break"
colon             ":"
comma             ","
cont              "continue"
decrement         "--"
dot               "."
double_colon      "::"
double_dot        ".."
else              "else"
endl              "endl"
equal             "=="
for               "for"
false             "false"
func              "function"
greater_equal_than ">="
greater_than      ">"
if                "if"
increment         "++"
left_brk          "{"
left_parenthesis  "("
left_sqr_brk      "["
less_equal_than   "<="
less_than         "<"
local             "local"
minus             "-"
modulo            "%"
multiply          "*"
nil               "nil"
not               "not"
not_equal         "!="
or                "or"
plus              "+"
right_brk         "}"
right_parenthesis ")"
right_sqr_brk     "]"
ret               "return"
semicolon         ";"
slash             "/"
true              "true"
while             "while"

id              [a-zA-Z][a-zA-Z_0-9]*
integer         [0-9][0-9]*
real            [0-9]+[.][0-9]+
whitespace      " \t\n\r"


%%



{integer} {
  insert(list, yylineno, strdup(yytext), "integer");
}

{real} {
  insert(list, yylineno, strdup(yytext), "double");
}


{and} {
  insert(list, yylineno, strdup(yytext), "logical");
}

{assign} {
  insert(list, yylineno, strdup(yytext), "assignment");
}

{brk} {
  insert(list, yylineno, strdup(yytext), "control");
}

{colon} {
  insert(list, yylineno, strdup(yytext), "colon");
}

{comma} {
  insert(list, yylineno, strdup(yytext), "comma");
}

{cont} {
  insert(list, yylineno, strdup(yytext), "control");
}

{decrement} {
  insert(list, yylineno, strdup(yytext), "decrement");
}

{dot} {
  insert(list, yylineno, strdup(yytext), "dot");
}

{double_colon} {
  insert(list, yylineno, strdup(yytext), "double_colon");
}

{if} {
  insert(list, yylineno, strdup(yytext), "if");
}

{else} {
  insert(list, yylineno, strdup(yytext), "else");
}

{while} {
  insert(list, yylineno, strdup(yytext), "while");
}

{for} {
  insert(list, yylineno, strdup(yytext), "for");
}

{func} {
  insert(list, yylineno, strdup(yytext), "function");
}

{ret} {
  insert(list, yylineno, strdup(yytext), "return");
}

{brk} { // error
  insert(list, yylineno, strdup(yytext), "break");
}

{cont} { //error
  insert(list, yylineno, strdup(yytext), "continue");
}

{and} { // error
  insert(list, yylineno, strdup(yytext), "logical");
}

{not} {
  insert(list, yylineno, strdup(yytext), "logical");
}

{or} {
  insert(list, yylineno, strdup(yytext), "logical");
}

{local} {
  insert(list, yylineno, strdup(yytext), "local");
}

{true} {
  insert(list, yylineno, strdup(yytext), "bool");
}

{false} {
  insert(list, yylineno, strdup(yytext), "bool");
}

{nil} {
  insert(list, yylineno, strdup(yytext), "nil");
}

{left_parenthesis} {
  insert(list, yylineno, strdup(yytext), "left perenthesis");
}

{right_parenthesis} {
  insert(list, yylineno, strdup(yytext), "right perenthesis");
}

{left_brk} {
  insert(list, yylineno, strdup(yytext), "left break");
}

{right_brk} {
  insert(list, yylineno, strdup(yytext), "right break");
}

{not_equal} {
  insert(list, yylineno, strdup(yytext), "not equal");
}

{equal} {
  insert(list, yylineno, strdup(yytext), "equal");
}

{id} {
  insert(list, yylineno, strdup(yytext), "char *");
}

"\n" {}

{whitespace} {}

"\"" { //add FSM for string  
  char c;
  char *str = malloc(sizeof(char *) * BUFZ);
  unsigned int counter = 0;
  //printf("\"");

  while ((c = input()) != '"') {
    str[counter++] = c;
    //printf("%c", c);
  }
  printf("str = %s\n", str);  
}


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
