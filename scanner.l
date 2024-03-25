%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "parser.h"

#include "utilities/token_list.h"
#include "utilities/comment_stack.h"

//#define YY_DECL int alpha_yylex(void *list, FILE *output)

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
  // insert(list, yylineno, strdup(yytext), "KEYWORD", "BREAK");
  return BRK;
}

{endl} { 
  //insert(list, yylineno, strdup(yytext), "KEYWORD", "ENDL");
  return ENDL;
}

{cont} {
  //insert(list, yylineno, strdup(yytext), "KEYWORD", "CONTINUE");
  return CONTINUE;
}

{and} {
  //insert(list, yylineno, strdup(yytext), "KEYWORD", "AND");
  return AND;
}

{if} {
  //insert(list, yylineno, strdup(yytext), "KEYWORD", "IF");
  return IF;
}

{else} {
  //insert(list, yylineno, strdup(yytext), "KEYWORD", "ELSE");
  return ELSE;
}

{while} {
  //insert(list, yylineno, strdup(yytext), "KEYWORD", "WHILE");
  return WHILE;
}

{for} {
  //insert(list, yylineno, strdup(yytext), "KEYWORD", "FOR");
  return FOR;
}

{func} {
  //insert(list, yylineno, strdup(yytext), "KEYWORD", "FUNCTION");
  return FUNCTION;
}

{ret} {
  //insert(list, yylineno, strdup(yytext), "KEYWORD", "RETURN");
  return RETURN_KW;
}

{not} {
  //insert(list, yylineno, strdup(yytext), "KEYWORD", "NOT");
  return NOT;
}

{or} {
  //insert(list, yylineno, strdup(yytext), "KEYWORD", "OR");
  return OR;
}

{local} {
  //insert(list, yylineno, strdup(yytext), "KEYWORD", "LOCAL");
  return LOCAL;
}

{true} {
  //insert(list, yylineno, strdup(yytext), "KEYWORD", "TRUE");
  return TRUE_KW;
}

{false} {
  //insert(list, yylineno, strdup(yytext), "KEYWORD", "FALSE");
  return FALSE_KW;
}

{nil} {
  //insert(list, yylineno, strdup(yytext), "KEYWORD", "NIL");
  return NIL;
}

{greater_than} {
  //insert(list, yylineno, strdup(yytext), "OPERATOR", "GREATER_THAN");
  return GREATER_THAN;
}

{equal} {
  //insert(list, yylineno, strdup(yytext), "OPERATOR", "EQUAL");
  return EQUAL;
}

{assign} {
  //insert(list, yylineno, strdup(yytext), "OPERATOR", "ASSIGN");
  return ASSIGN;
}

{decrement} {
  //insert(list, yylineno, strdup(yytext), "OPERATOR", "DECREMENT");
  return DECREMENT;
}

{not_equal} {
  //insert(list, yylineno, strdup(yytext), "OPERATOR", "NOT_EQUAL");
  return NOT_EQUAL;
}

{minus} {
  //insert(list, yylineno, strdup(yytext), "OPERATOR","MINUS");
  return MINUS;
}

{multiply} {
  //insert(list, yylineno, strdup(yytext), "OPERATOR","MULTIPLY");
  return MULTIPLY;
}

{modulo} {
  //insert(list, yylineno, strdup(yytext), "OPERATOR","MODULO");
  return MODULO;
}

{greater_equal_than} {
  //insert(list, yylineno, strdup(yytext), "OPERATOR","GREATER_EQUAL_THAN");
  return GREATER_EQUAL;
}

{plus} {
  //insert(list, yylineno, strdup(yytext), "OPERATOR", "PLUS");
  return PLUS;
}

{less_than} {
  //insert(list, yylineno, strdup(yytext), "OPERATOR", "LESS_THAN");
  return LESSER_THAN;
}

{less_equal_than} {
  //insert(list, yylineno, strdup(yytext), "OPERATOR", "LESS_EQUAL_THAN");
  return LESSER_EQUAL;
}

{increment} {
  //insert(list, yylineno, strdup(yytext), "OPERATOR", "INCREMENT");
  return INCREMENT;
}

{slash} {
  //insert(list, yylineno, strdup(yytext), "OPERATOR", "SLASH");
  return SLASH;
}

{colon} {
  //insert(list, yylineno, strdup(yytext), "PUNCTUATION", "COLON");
  return COLON;
}

{comma} {
  //insert(list, yylineno, strdup(yytext), "PUNCTUATION", "COMMA");
  return COMMA;
}

{semicolon} {
  //insert(list, yylineno, strdup(yytext), "PUNCTUATION", "SEMICOLON");
  return SEMICOLON;
}

{double_dot} {
  //insert(list, yylineno, strdup(yytext), "PUNCTUATION", "DOUBLE_DOT");
  return DOUBLE_DOT;
}

{dot} {
  //insert(list, yylineno, strdup(yytext), "PUNCTUATION","DOT");
  return DOT;
}

{double_colon} {
  //insert(list, yylineno, strdup(yytext), "PUNCTUATION","DOUBLE_COLON");
  return DOUBLE_COLON;
}

{left_parenthesis} {
  //insert(list, yylineno, strdup(yytext), "PUNCTUATION","LEFT_PARENTHESIS");
  return LEFT_PARENTHESIS;
}

{right_parenthesis} {
  //insert(list, yylineno, strdup(yytext), "PUNCTUATION", "RIGHT_PARENTHESIS");
  return RIGHT_PARENTHESIS;
}

{left_brk} {
  //insert(list, yylineno, strdup(yytext), "PUNCTUATION", "LEFT_BRACKET");
  return LEFT_BRACKET;
}

{right_brk} {
  //insert(list, yylineno, strdup(yytext), "PUNCTUATION", "RIGHT_BRACKET");
  return RIGHT_BRACKET;
}

{left_sqr_brk} {
  //insert(list, yylineno, strdup(yytext), "PUNCTUATION", "LEFT_SQUARE_BRACKET");
  return LEFT_SQUARE_BRACKET;
}

{right_sqr_brk} {
  //insert(list, yylineno, strdup(yytext), "PUNCTUATION", "RIGHT_SQUARE_BRACKET");
  return RIGHT_SQUARE_BRACKET;
}

{integer} {
  yylval.int_val = atoi(yytext); 
  //insert(list, yylineno, strdup(yytext), "INTCONST", "INTEGER");
  return INTEGER;
}

{real} {
  yylval.real_val = atoi(yytext); 
  //insert(list, yylineno, strdup(yytext), "REALCONST", strdup(yytext));
  return REAL;
}

{id} {
  yylval.str_val = strdup(yytext);
  //insert(list, yylineno, strdup(yytext), "IDENT", strdup(yytext));
  return ID;
}

[ \n\t\r\v\f] {}

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

  //insert(list, yylineno, token, "STRING", token);
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
  //insert(list,yylineno,"","COMMENT", "LINE COMMENT");
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
    //insert(list,yylineno,strdup(tmp),"COMMENT", "BLOCK COMMENT");
  }
} 

. {
   //print_list(list, output);
   fprintf(stdout, "unrecognized token %s in line %d\n", yytext, yylineno);
   exit(-1);
   }

%%

// int main(int argc, char* argv[]){
//   FILE* file;

//   if (argc > 1) {
//     if (!(yyin = fopen(argv[1], "r"))) {
//       perror("Cant open file"); 
//       return 1;
//     }
//   }

//   if (argc > 2) {
//     if (!(file = fopen(argv[2], "w"))) {
//       perror("Cannot open output file");
//       fclose(file);
//       return 1;
//     }
//   }

//   token_list *list = create_list();

//   alpha_yylex(list, (argc > 2) ? file : stdout);
 
//   print_list(list, (argc > 2) ? file : stdout);
//   free_list(list);
//   return 0;
// }
