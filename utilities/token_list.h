#ifndef TOKEN_LIST
#define TOKEN_LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct alpha_token_t {
  int line;
  int token_number;
  char *token;
  struct alpha_token_t *next;
} alpha_token_t;

typedef struct token_list {
  struct alpha_token_t *head;
  struct alpha_token_t *last; 
  unsigned int token_count;
} token_list;

int insert(token_list *list, int line, char *token); //add some params

token_list *create_list(void);

int free_list(token_list *list);

void print_list(token_list *list, FILE *stream);

#endif

