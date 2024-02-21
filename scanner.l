%{
#include <stdio.h>
#include <stdlib.h>
#include "utilities/token_list.h"

#define YY_DECL int alpha_yylex(void *list)

#define BUFSIZE 1024

#define REALLOC_MEM(token, size) \
  token = (char *) realloc(token, sizeof(char) * BUFSIZE * size)

%}

%option noyywrap 
%option yylineno


/* KEYWORDS */
and               "and"
brk               "break"
cont              "continue"
else              "else"
endl              "endl"
for               "for"
false             "false"
func              "function"
if                "if"
local             "local"
nil               "nil"
not               "not"
or                "or"
ret               "return"
true              "true"
while             "while"

/* PUNCTUATION */
colon              ":"
comma              ","
left_brk           "{"
right_brk          "}"
left_sqr_brk       "["
right_sqr_brk      "]"
left_parenthesis   "("
right_parenthesis  ")"
semicolon          ";"
dot                "."
double_colon       "::"
double_dot         ".."

/* OPERATORS */
assign             "="
equal              "=="
greater_equal_than ">="
greater_than       ">"
minus              "-"
modulo             "%"
multiply           "*"
increment          "++"
less_equal_than    "<="
less_than          "<"
slash              "/"
plus               "+"
not_equal          "!="
decrement          "--"

/* INT/REAL CONST */
id              [a-zA-Z][a-zA-Z_0-9]*
integer         [0-9][0-9]*
real            [0-9]+[.][0-9]+
whitespace      " \t\n\r"


%%


{brk} { 
  insert(list, yylineno, strdup(yytext), "KEYWORD");
}

{endl} { 
  insert(list, yylineno, strdup(yytext), "KEYWORD");
}

{cont} {
  insert(list, yylineno, strdup(yytext), "KEYWORD");
}

{and} {
  insert(list, yylineno, strdup(yytext), "KEYWORD");
}

{if} {
  insert(list, yylineno, strdup(yytext), "KEYWORD");
}

{else} {
  insert(list, yylineno, strdup(yytext), "KEYWORD");
}

{while} {
  insert(list, yylineno, strdup(yytext), "KEYWORD");
}

{for} {
  insert(list, yylineno, strdup(yytext), "KEYWORD");
}

{func} {
  insert(list, yylineno, strdup(yytext), "KEYWORD");
}

{ret} {
  insert(list, yylineno, strdup(yytext), "KEYWORD");
}

{not} {
  insert(list, yylineno, strdup(yytext), "KEYWORD");
}

{or} {
  insert(list, yylineno, strdup(yytext), "KEYWORD");
}

{local} {
  insert(list, yylineno, strdup(yytext), "KEYWORD");
}

{true} {
  insert(list, yylineno, strdup(yytext), "KEYWORD");
}

{false} {
  insert(list, yylineno, strdup(yytext), "KEYWORD");
}

{nil} {
  insert(list, yylineno, strdup(yytext), "KEYWORD");
}


{greater_than} {
  insert(list, yylineno, strdup(yytext), "OPERATOR");
}

{equal} {
  insert(list, yylineno, strdup(yytext), "OPERATOR");
}

{assign} {
  insert(list, yylineno, strdup(yytext), "OPERATOR");
}

{decrement} {
  insert(list, yylineno, strdup(yytext), "OPERATOR");
}

{not_equal} {
  insert(list, yylineno, strdup(yytext), "OPERATOR");
}

{minus} {
  insert(list, yylineno, strdup(yytext), "OPERATOR");
}

{multiply} {
  insert(list, yylineno, strdup(yytext), "OPERATOR");
}

{modulo} {
  insert(list, yylineno, strdup(yytext), "OPERATOR");
}

{greater_equal_than} {
  insert(list, yylineno, strdup(yytext), "OPERATOR");
}

{plus} {
  insert(list, yylineno, strdup(yytext), "OPERATOR");
}

{less_than} {
  insert(list, yylineno, strdup(yytext), "OPERATOR");
}

{less_equal_than} {
  insert(list, yylineno, strdup(yytext), "OPERATOR");
}

{increment} {
  insert(list, yylineno, strdup(yytext), "OPERATOR");
}

{slash} {
  insert(list, yylineno, strdup(yytext), "OPERATOR");
}

{colon} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION");
}

{comma} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION");
}

{semicolon} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION");
}

{double_dot} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION");
}

{dot} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION");
}

{double_colon} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION");
}

{left_parenthesis} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION");
}

{right_parenthesis} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION");
}

{left_brk} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION");
}

{right_brk} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION");
}

{left_sqr_brk} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION");
}

{right_sqr_brk} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION");
}



{integer} {
  insert(list, yylineno, strdup(yytext), "INTCONST");
}

{real} {
  insert(list, yylineno, strdup(yytext), "REALCONST");
}

{id} {
  insert(list, yylineno, strdup(yytext), "IDENT");
}

"\n" {}

{whitespace} {}

"\"" { //add FSM for string  
  char c, peak, special_char;
  char *token = malloc(sizeof(char *) * BUFSIZE);
  unsigned int counter = 0, realloc_size = 1;

  while ((c = input()) != '"') {

    if (counter >= BUFSIZE) {
      REALLOC_MEM(token, realloc_size++);
    }

    if (c == '\\') {
      peak = input();

      switch (peak) {
        case 'n':
          special_char = '\n';
          break;

        case 't':
          special_char = '\t';
          break;

        case 'r':
          special_char = '\r';
          break;

        case '\\':
          special_char = '\\';
          break;

        case '\"':
          special_char = '\"';
          break;

        default:
          token[counter++] = c;
          special_char = peak;
      }

      token[counter++] = special_char;
      continue;
    }

    token[counter++] = c;
  }

  insert(list, yylineno, token, "STRING");
}


%%

int main(int argc, char* argv[]){
  FILE* file;

  if (argc > 1) {
    if (!(yyin = fopen(argv[1], "r"))) {
      perror("Cant open file"); 
      return 1;
    }
  }

  token_list *list = create_list();

  alpha_yylex(list);

  print_list(list, stdout);
  free_list(list);
  return  0;
}
