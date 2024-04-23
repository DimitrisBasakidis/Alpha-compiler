%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parser.h"

#include "utilities/token_list.h"
#include "utilities/comment_stack.h"

#define BUFSIZE 1024

#define TRUE    0
#define FALSE   1

#define FOUND_SPECIAL_CHAR    (c == '\\')

#define STRING_NOT_CLOSING    (c == 0)
#define STRING_CLOSING        (c == '\"' || c == '\0')

#define OPENING_BLOCK_COMMENT (c == '*' && prev_c == '/')
#define CLOSING_BLOCK_COMMENT (prev_c == '*' && c == '/')

#define REALLOC_MEM(token, size) \
  token = (char *) realloc(token, sizeof(char) * BUFSIZE * size)

#define HANDLE_COLUMN column = next_column; next_column += strlen(yytext)

static int next_column = 1;
int column = 1;

char *lineptr = NULL;
size_t n = 0;
size_t consumed = 0;
size_t available = 0;

size_t min(size_t a, size_t b);


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
  return BRK;
}

{endl} { 
  return ENDL;
}

{cont} {
  return CONTINUE;
}

{and} {
  return AND;
}

{if} {
  return IF;
}

{else} {
  return ELSE;
}

{while} {
  return WHILE;
}

{for} {
  return FOR;
}

{func} {
  return FUNCTION;
}

{ret} {
  return RETURN_KW;
}

{not} {
  return NOT;
}

{or} {
  return OR;
}

{local} {
  return LOCAL;
}

{true} {
  return TRUE_KW;
}

{false} {
  return FALSE_KW;
}

{nil} {
  return NIL;
}

{greater_than} {
  return GREATER_THAN;
}

{equal} {
  return EQUAL;
}

{assign} {
  return ASSIGN;
}

{decrement} {
  return DECREMENT;
}

{not_equal} {
  return NOT_EQUAL;
}

{minus} {
  return MINUS;
}

{multiply} {
  return MULTIPLY;
}

{modulo} {
  return MODULO;
}

{greater_equal_than} {
  return GREATER_EQUAL;
}

{plus} {
  return PLUS;
}

{less_than} {
  return LESSER_THAN;
}

{less_equal_than} {
  return LESSER_EQUAL;
}

{increment} {
  return INCREMENT;
}

{slash} {
  return SLASH;
}

{colon} {
  return COLON;
}

{comma} {
  return COMMA;
}

{semicolon} {
  return SEMICOLON;
}

{double_dot} {
  return DOUBLE_DOT;
}

{dot} {
  return DOT;
}

{double_colon} {
  return DOUBLE_COLON;
}

{left_parenthesis} {
  return LEFT_PARENTHESIS;
}

{right_parenthesis} {
  return RIGHT_PARENTHESIS;
}

{left_brk} {
  return LEFT_BRACKET;
}

{right_brk} {
  return RIGHT_BRACKET;
}

{left_sqr_brk} {
  return LEFT_SQUARE_BRACKET;
}

{right_sqr_brk} {
  return RIGHT_SQUARE_BRACKET;
}

{integer} {
  yylval.int_val = atoi(yytext); 
  return INTEGER;
}

{real} {
  yylval.real_val = atof(yytext); 
  return REAL;
}

{id} {
  yylval.str_val = strdup(yytext);
  return ID;
}

[ \n\t\r\v\f] {
lineptr = strdup(yytext);
    if (lineptr == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory\n");
        exit(EXIT_FAILURE);
    }

}

"\"" {
  char c, peak, special_char;
  char *token = malloc(sizeof(char *) * BUFSIZE);
  unsigned int counter = 0, realloc_size = 1;

  while ((c = input()) != EOF) {
  
    if (STRING_CLOSING) {
      break;
    }

    if (counter >= BUFSIZE) {
      REALLOC_MEM(token, realloc_size++);
    }

    if (token == NULL) {
      fprintf(stderr, "Error allocating memory\n");
    }

    if (FOUND_SPECIAL_CHAR) {
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

  if (STRING_NOT_CLOSING) {
    //print_list(list, output);
    //fprintf(output, "%d:\t\t#%d\t\t“%s”\t\tERROR STRING DOENS'T CLOSE\n", yylineno, ((token_list *)list)->token_count + 1, token);
    exit(0);
  }

  yylval.str_val = strdup(token);
  return STRING;
}

"//" {
  char c;
  while((c=input())!= EOF){
    if (c == '\n' || c == '\0') {
     break;
    }
  }
}

"/*" {

  char c, prev_c;
  int flag = FALSE, flagc = FALSE;
  comment_stack *temp = create_stack();
  comment_stack *stack = create_stack();

  stack = insert_comment(stack, yylineno, 0);

  while((c=input())!= EOF){

    if ((!is_empty(stack)) && (c == prev_c) && (c == 0)) break; 

    if (OPENING_BLOCK_COMMENT && flag == FALSE && flagc == FALSE) {
      flag = TRUE;
      stack = insert_comment(stack, yylineno, 0);
    } else if (CLOSING_BLOCK_COMMENT && flagc == FALSE && flag == FALSE) {
      flagc = TRUE;
      comment_t *comment = pop_comment(stack, yylineno, 0);
      temp = insert_comment(temp, comment->start_line, yylineno);
    } else {
      flag = FALSE;
      flagc = FALSE;
    }

    if (is_empty(stack)) {
      break;
    }
    prev_c = c;
  }

  if (!is_empty(stack)) {
    //print_list((token_list *)list, output);
    //fprintf(output, "%d:\t\t#%d\t\tERROR: NOT ALL BLOCK COMMENTS CLOSING\n", yylineno, ((token_list *)list)->token_count + 1); //line not correct
    exit(0);
  }

  while (!is_empty(temp)) {
    char tmp[128];
    comment_t *comment = pop_comment(temp, 1, 1);
    sprintf(tmp, "%d-%d", comment->start_line, comment->end_line);
  }
} 

. {
   //print_list(list, output);
   fprintf(stdout, "unrecognized token %s in line %d\n", yytext, yylineno);
   exit(-1);
   }

%%

size_t min(size_t a, size_t b) {
    return b < a ? b : a;
}
