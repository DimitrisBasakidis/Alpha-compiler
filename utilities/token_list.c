#include "token_list.h" 
#include <string.h>

#define TRUE  0
#define FALSE 1 

token_list *create_list(void) {
  token_list *new_list = malloc(sizeof(token_list));

  if (new_list == NULL) {
    return NULL;
  }

  new_list->head = NULL;
  new_list->last = NULL;
  new_list->token_count = 0U;

  return new_list;
}

void print_list(token_list *list, FILE *stream) {
  alpha_token_t *ptr = list->head;
  char *category = NULL;

  fprintf(stream, "Lexical analyis phase 1\n");
  fprintf(stream, "line   \ttoken number  \t\tvalue    \ttype\t  \tcategory\n");

  while (ptr != NULL) {
    if (strcmp(ptr->token_type, "PUNCTUATION") == 0 || strcmp(ptr->token_type, "KEYWORD") == 0 || strcmp(ptr->token_type, "OPERATOR") == 0 || strcmp(ptr->token_type, "COMMENT") == 0) {
      category = "enumerated";
      fprintf(stream, "%d:\t\t#%d\t\t“%s”\t\t%s\t\t%s  <-%s\n", ptr->line, ptr->token_number, ptr->token, ptr->token_type,ptr->token_category, category);

    } else if (strcmp(ptr->token_type, "IDENT") == 0 || strcmp(ptr->token_type, "STRING") == 0) {
      category = "char *";
      fprintf(stream, "%d:\t\t#%d\t\t“%s”\t\t%s\t\t“%s”  <-%s\n", ptr->line, ptr->token_number, ptr->token, ptr->token_type,ptr->token_category, category);

    }  
    ptr = ptr->next;
  }
}

int free_list(token_list *list) {
  if (list == NULL) {
    return FALSE;
  }

  alpha_token_t *ptr = list->head;
  alpha_token_t *to_free = NULL;

  while (ptr != NULL) {
    to_free = ptr;
    ptr = ptr->next;
    free(to_free);
  }

  return TRUE;
}

int insert(token_list *list, int line, char *token, char *type,char* category) {
  if (list == NULL) {
    return FALSE;
  }

  alpha_token_t *head = list->head;
  alpha_token_t *new_token = malloc(sizeof(struct alpha_token_t));

  if (new_token == NULL) {
    return FALSE;
  }

  new_token->line = line;
  new_token->token = token;
  new_token->token_type = type;
  new_token->token_category = category;
  new_token->token_number = ++(list->token_count);

  if (head == NULL) {
    list->head = new_token;
  } else {
    list->last->next = new_token;
  }

  list->last = new_token;

  return TRUE;  
}
