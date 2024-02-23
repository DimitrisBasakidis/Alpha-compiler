%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utilities/token_list.h"
#include "utilities/comment_stack.h"

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

%%


{brk} { 
  insert(list, yylineno, strdup(yytext), "KEYWORD", "BREAK");
}

{endl} { 
  insert(list, yylineno, strdup(yytext), "KEYWORD", "ENDL");
}

{cont} {
  insert(list, yylineno, strdup(yytext), "KEYWORD", "CONTINUE");
}

{and} {
  insert(list, yylineno, strdup(yytext), "KEYWORD", "AND");
}

{if} {
  insert(list, yylineno, strdup(yytext), "KEYWORD", "IF");
}

{else} {
  insert(list, yylineno, strdup(yytext), "KEYWORD", "ELSE");
}

{while} {
  insert(list, yylineno, strdup(yytext), "KEYWORD", "WHILE");
}

{for} {
  insert(list, yylineno, strdup(yytext), "KEYWORD", "FOR");
}

{func} {
  insert(list, yylineno, strdup(yytext), "KEYWORD", "FUNCTION");
}

{ret} {
  insert(list, yylineno, strdup(yytext), "KEYWORD", "RETURN");
}

{not} {
  insert(list, yylineno, strdup(yytext), "KEYWORD", "NOT");
}

{or} {
  insert(list, yylineno, strdup(yytext), "KEYWORD", "OR");
}

{local} {
  insert(list, yylineno, strdup(yytext), "KEYWORD", "LOCAL");
}

{true} {
  insert(list, yylineno, strdup(yytext), "KEYWORD", "TRUE");
}

{false} {
  insert(list, yylineno, strdup(yytext), "KEYWORD", "FALSE");
}

{nil} {
  insert(list, yylineno, strdup(yytext), "KEYWORD", "NIL");
}


{greater_than} {
  insert(list, yylineno, strdup(yytext), "OPERATOR", "GREATER_THAN");
}

{equal} {
  insert(list, yylineno, strdup(yytext), "OPERATOR", "EQUAL");
}

{assign} {
  insert(list, yylineno, strdup(yytext), "OPERATOR", "ASSIGN");
}

{decrement} {
  insert(list, yylineno, strdup(yytext), "OPERATOR", "DECREMENT");
}

{not_equal} {
  insert(list, yylineno, strdup(yytext), "OPERATOR", "NOT_EQUAL");
}

{minus} {
  insert(list, yylineno, strdup(yytext), "OPERATOR","MINUS");
}

{multiply} {
  insert(list, yylineno, strdup(yytext), "OPERATOR","MULTIPLY");
}

{modulo} {
  insert(list, yylineno, strdup(yytext), "OPERATOR","MODULO");
}

{greater_equal_than} {
  insert(list, yylineno, strdup(yytext), "OPERATOR","GREATER_EQUAL_THAN");
}

{plus} {
  insert(list, yylineno, strdup(yytext), "OPERATOR", "PLUS");
}

{less_than} {
  insert(list, yylineno, strdup(yytext), "OPERATOR", "LESS_THAN");
}

{less_equal_than} {
  insert(list, yylineno, strdup(yytext), "OPERATOR", "LESS_EQUAL_THAN");
}

{increment} {
  insert(list, yylineno, strdup(yytext), "OPERATOR", "INCREMENT");
}

{slash} {
  insert(list, yylineno, strdup(yytext), "OPERATOR", "SLASH");
}

{colon} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION", "COLON");
}

{comma} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION", "COMMA");
}

{semicolon} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION", "SEMICOLON");
}

{double_dot} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION", "DOUBLE_DOT");
}

{dot} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION","DOT");
}

{double_colon} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION","DOUBLE_COLON");
}

{left_parenthesis} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION","LEFT_PARENTHESIS");
}

{right_parenthesis} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION", "RIGHT_PARENTHESIS");
}

{left_brk} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION", "LEFT_BRACKET");
}

{right_brk} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION", "RIGHT_BRACKET");
}

{left_sqr_brk} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION", "LEFT_SQUARE_BRACKET");
}

{right_sqr_brk} {
  insert(list, yylineno, strdup(yytext), "PUNCTUATION", "RIGHT_SQUARE_BRACKET");
}

{integer} {
  insert(list, yylineno, strdup(yytext), "INTCONST", "INTEGER");
}

{real} {
  insert(list, yylineno, strdup(yytext), "REALCONST", strdup(yytext));
}

{id} {
  insert(list, yylineno, strdup(yytext), "IDENT", strdup(yytext));
}

[ \n\t\r\v\f] {}

"\"" {
  char c, peak, special_char;
  char *token = malloc(sizeof(char *) * BUFSIZE);
  unsigned int counter = 0, realloc_size = 1;

  while ((c = input()) != EOF) {
  
    if (c == '\"' || c == '\0') {
      break;
    }

    if (counter >= BUFSIZE) {
      REALLOC_MEM(token, realloc_size++);
    }

    if (token == NULL) {
      fprintf(stderr, "Error allocating memory\n");
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

  insert(list, yylineno, token, "STRING", token);
}

"//" {
  char c;
  while((c=input())!= EOF){
    if (c == '\n' || c == '\0') {
     break;
    }
  }
  insert(list,yylineno,"","COMMENT", "LINE COMMENT");
}

"/*" {
  char c, prev_c;
  stack_t *stack = create_stack();
  stack_t *temp = create_stack();

  stack = insert_comment(stack, yylineno, 0);

  while((c=input())!= EOF){

    if (is_empty(stack)) break;

    if (c == '*' && prev_c == '/') {
      stack = insert_comment(stack, yylineno, 0);
    } else if (prev_c == '*' && c == '/') {
      comment_t *comment = pop_comment(stack, yylineno, 0);
      temp = insert_comment(temp, comment->start_line, yylineno);
    }

    prev_c = c;
  }

  while (!is_empty(temp)) {
    char tmp[128];
    comment_t *comment = pop_comment(temp, 1, 1);
    sprintf(tmp, "%d-%d", comment->start_line, comment->end_line);
    // printf("%s\n", tmp);
    insert(list,yylineno,strdup(tmp),"COMMENT", "BLOCK COMMENT");
    // printf("comment from %d, to %d\n", comment->start_line, comment->end_line);
  }
} 

. {
   print_list(list,stdout);
   printf("unrecognized token %s in line %d\n", yytext, yylineno);
   exit(0);
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
