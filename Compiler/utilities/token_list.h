#ifndef TOKEN_LIST
#define TOKEN_LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct alpha_token_t {
  int line;
  int token_number;
  char *token;
  char *token_type;
  char *token_category;
  struct alpha_token_t *next;
} alpha_token_t;

typedef struct token_list {
  struct alpha_token_t *head;
  struct alpha_token_t *last; 
  unsigned int token_count;
} token_list;

int insert(token_list *list, int line, char *token, char *type, char* category); //add some params

token_list *create_list(void);

int free_list(token_list *list);

void print_list(token_list *list, FILE *stream);

#endif

