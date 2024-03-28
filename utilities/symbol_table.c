#include "symbol_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *lib_func_arr[12] = {"print", "input", "ojectmemberkeys", "objecttotalmembers", "objectcopy", "totalarguments", "argument", "typeof", "strtonum", "sqrt", "cos", "sin"};

SymTable *create_table(void) {
    SymTable *new_table = malloc(sizeof(struct SymTable));

    if (new_table == NULL) {
        return NULL;
    }

    new_table->count = 0;

    for (size_t i = 0; i < SIZE; i++) {
        new_table->table[i] = NULL;
    }

    return new_table;
}

static unsigned int hash(const char *pcKey){
	size_t ui;
	unsigned int uiHash = 0U;
	for (ui = 0U; pcKey[ui] != '\0'; ui++)
		uiHash = uiHash * HASH_MULTIPLIER + pcKey[ui];
	return uiHash % SIZE; 
}

void free_table(SymTable *table) {
    SymbolTableEntry *ptr = NULL;

    for (size_t i = 0; i < SIZE; i++) {
        ptr = table->table[i];
        free(ptr);
    }

    free(table);
}

SymbolTableEntry *create_node(char *name, unsigned int scope, unsigned int line, enum SymbolType type, int status) {
  SymbolTableEntry *new_entry = malloc(sizeof(struct SymbolTableEntry));  
  unsigned int length = strlen(name);

  if (new_entry == NULL) return NULL;

  switch (type) {
    case GLOBALVAR:
    case LOCALVAR:
    case FORMAL:
      new_entry->value.varVal = malloc(sizeof(struct Variable));
      new_entry->value.varVal->name = malloc(sizeof(char) * length + 1);
      strncpy(new_entry->value.varVal->name, name, length);
      new_entry->value.varVal->scope = scope;
      new_entry->value.varVal->line = line;
      new_entry->hash_value = hash(new_entry->value.varVal->name);

      break;

    case LIBFUNC:
    case USERFUNC:
      new_entry->value.funcVal = malloc(sizeof(struct Function));
      new_entry->value.funcVal->name = malloc(sizeof(char) * length + 1);
      strncpy(new_entry->value.funcVal->name, name, length);
      new_entry->value.funcVal->scope = scope;
      new_entry->value.funcVal->line = line;
      new_entry->hash_value = (type == USERFUNC) ? hash(new_entry->value.funcVal->name) : 0;

      break;
  }

  new_entry->isActive = status;
  new_entry->type = type;
  new_entry->next = NULL;
  new_entry->snext = NULL;

  return new_entry;
}

int lookup_lib_func(char *token) {
  for (int i = 0; i < 12; i++) {
    if (strncmp(lib_func_arr[i], token, strlen(token)) == TRUE && (strlen(token) == strlen(lib_func_arr[i]))) return TRUE;
  }

  return FALSE;
}

int insert_symbol(SymTable *symtable, SymbolTableEntry *entry) {
  if (symtable == NULL) return FALSE;


  if (symtable->table[entry->hash_value] != NULL) {
    entry->next = symtable->table[entry->hash_value];
  }

  symtable->table[entry->hash_value] = entry;
  
 return TRUE; 
}

// int exists_in_scope(SymbolTableEntry *head, char *token) {
//   if (head == NULL) return FALSE;
//   int flag;
//   SymbolTableEntry *ptr = head;

//   while (ptr != NULL) {

//     flag = (ptr->type == USERFUNC || ptr->type == LIBFUNC) ? 1 : 0;

//     if (flag == 1){
//       if(!strncmp(ptr->value.funcVal->name,token,strlen(token)))
//         return ptr->type;
//     }else{
//         if(!strncmp(ptr->value.varVal->name,token,strlen(token)))
//         return ptr->type;
//     }
//     ptr = ptr->snext;
//   }
//   return FALSE;
// }

// int find_scope_from_hash(SymTable *symtable, char* token){
//   if (symtable == NULL) return FALSE;
//   int index = hash(token);
//   SymbolTableEntry *ptr = symtable->table[index];
//   if(symtable->table[index] == NULL){
//     printf("hi\n");
//     return -1;
//   }
//   while(ptr!=NULL){
//     if(ptr->type == USERFUNC || ptr->type == LIBFUNC){
//       if(strcmp(token,ptr->value.funcVal->name) == 0){
//         return ptr->value.funcVal->scope;
//       }
//     }else{
//       if(strcmp(token,ptr->value.varVal->name) == 0){
//         return ptr->value.varVal->scope;
//       }
//     }
//     ptr = ptr->next;
//   }
//   return -1;
  
// }

// int lookup(SymTable *symtable, char *token, enum SymbolType type, unsigned int scope, enum varFlag flag) {
//   if (symtable == NULL) return FALSE;

//   int index = hash(token);
//   SymbolTableEntry *ptr = symtable->table[index];

//   if (lookup_lib_func(token) == TRUE) return IS_LIBFUNC;

//   if (symtable->table[index] != NULL) {
//     while(ptr != NULL) {
//       if (strncmp((type == GLOBALVAR || type == LOCALVAR || type == FORMAL) ? 
//           ptr->value.varVal->name : 
//           ptr->value.funcVal->name, 
//           token, strlen(token)) == TRUE) {
            
//           printf("TYPE %d name %s\n",type , token);
      
//         if (flag == LOCAL_KW && ptr->value.varVal->scope < scope && type == LOCALVAR) return FALSE;
//         if (flag == LOCAL_FUNC && ptr->value.funcVal->scope < scope && type == USERFUNC) return FALSE;

//         int statement;
//         (type == GLOBALVAR || type == LOCALVAR) ? 
//           (statement = (ptr->value.varVal->scope <= scope && ptr->isActive == ACTIVE) ? TRUE : FALSE) :
//           (statement = (ptr->value.funcVal->scope <= scope && ptr->isActive == ACTIVE) ? TRUE : FALSE);
//           printf("statement: %s %d is active : %d, scope %d type %d\n",token, statement, ptr->isActive == ACTIVE, ptr->value.varVal->scope, ptr->type);
//           return statement;
//         return TRUE;
//       }
//     }
//   }
  
//   return FALSE;
// }

// SymbolTableEntry *lookup_scope()

SymbolTableEntry *lookup(SymTable *symtable, scopeLists *lists, char *token, enum SymbolType type, int scope, int flag) {
  if (symtable == NULL) return NULL;
  SymbolTableEntry *ptr = NULL;

  switch (flag) {

  case HASH:

    int index = (lookup_lib_func(token) == TRUE) ? 0 : hash(token);
    ptr = symtable->table[index];

    while (ptr != NULL) {
      if (strncmp((type == GLOBALVAR || type == LOCALVAR || type == FORMAL) ? 
            ptr->value.varVal->name : 
            ptr->value.funcVal->name, 
            token, strlen(token)) == TRUE 
            && 
            strlen(token) == 
            strlen((type == GLOBALVAR || type == LOCALVAR || type == FORMAL) ? 
            ptr->value.varVal->name : 
            ptr->value.funcVal->name)) 
        {
          if (ptr->isActive) return ptr;
          //return (ptr->isActive == ACTIVE) ? ptr : NULL; 
        } 
        ptr = ptr->next;
      } 
    break;
  
  case SCOPE:

    ptr = lists->slist[(lookup_lib_func(token) == TRUE) ? 0 : scope];
    
    while (ptr != NULL) {

      if (strncmp((type == GLOBALVAR || type == LOCALVAR || type == FORMAL) ? 
            ptr->value.varVal->name : 
            ptr->value.funcVal->name, 
            token, strlen(token)) == TRUE 
            && 
            strlen(token) == 
            strlen((type == GLOBALVAR || type == LOCALVAR || type == FORMAL) ? 
            ptr->value.varVal->name : 
            ptr->value.funcVal->name)) 
        {
          return (ptr->isActive == ACTIVE) ? ptr : NULL; 
        }
        ptr = ptr->snext;
      } 
    break;
  }

  

  return NULL;

}

void print_hash(SymTable *table) {
  for (int i = 0; i < SIZE; i++) {
    if (table->table[i] == NULL) continue;
    
    SymbolTableEntry *ptr = table->table[i];
    printf("bucket %d\n", i);
    while (ptr != NULL) {

      if (ptr->type == GLOBALVAR || ptr->type == LOCALVAR) {
        printf("%s, %d, %d, %d, %d, %p, %p, %d\n", ptr->value.varVal->name, ptr->value.varVal->scope, ptr->value.varVal->line, ptr->type, ptr->isActive, ptr->next, ptr->snext, ptr->hash_value);
      } else {
        printf("%s, %d, %d, %d, %d, %p, %p, %d\n", ptr->value.funcVal->name, ptr->value.funcVal->scope, ptr->value.funcVal->line, ptr->type, ptr->isActive, ptr->next, ptr->snext, ptr->hash_value);
      }

      ptr = ptr->next;

    } 

  }
}


void add_lib_func(SymTable *symtable, scopeLists *lists) {
  if (symtable == NULL) return;

  SymbolTableEntry *node = NULL;

  node = create_node("print", 0, 0, LIBFUNC, ACTIVE);
  insert_symbol(symtable, node);
  insert_to_scope(lists, node, 0);

  node = create_node("input", 0, 0, LIBFUNC, ACTIVE);
  insert_symbol(symtable, node);
  insert_to_scope(lists, node, 0);

  node = create_node("objectmemberkeys", 0, 0, LIBFUNC, ACTIVE);
  insert_symbol(symtable, node);
  insert_to_scope(lists, node, 0);

  node = create_node("objectotalmembers", 0, 0, LIBFUNC, ACTIVE);
  insert_symbol(symtable, node);
  insert_to_scope(lists, node, 0);

  node = create_node("objectcopy", 0, 0, LIBFUNC, ACTIVE);
  insert_symbol(symtable, node);
  insert_to_scope(lists, node, 0);

  node = create_node("totalarguments", 0, 0, LIBFUNC, ACTIVE);
  insert_symbol(symtable, node);
  insert_to_scope(lists, node, 0);

  node = create_node("argument", 0, 0, LIBFUNC, ACTIVE);
  insert_symbol(symtable, node);
  insert_to_scope(lists, node, 0);

  node = create_node("typeof", 0, 0, LIBFUNC, ACTIVE);
  insert_symbol(symtable, node);
  insert_to_scope(lists, node, 0);

  node = create_node("strtonum", 0, 0, LIBFUNC, ACTIVE);
  insert_symbol(symtable, node);
  insert_to_scope(lists, node, 0);

  node = create_node("sqrt", 0, 0, LIBFUNC, ACTIVE);
  insert_symbol(symtable, node);
  insert_to_scope(lists, node, 0);

  node = create_node("cos", 0, 0, LIBFUNC, ACTIVE);
  insert_symbol(symtable, node);
  insert_to_scope(lists, node, 0);

  node = create_node("sin", 0, 0, LIBFUNC, ACTIVE);
  insert_symbol(symtable, node);
  insert_to_scope(lists, node, 0);
}

scopeLists *create_scope_lists(void) {
  scopeLists *new_lists = malloc(sizeof(struct scopeLists));
   
  new_lists->max_scope = SCOPE_SIZE;
  new_lists->slist = malloc(SCOPE_SIZE * sizeof(SymbolTableEntry));
    // new_lists->slist = malloc(sizeof(struct SymbolTableEntry ));

  for (int i = 0; i < SCOPE_SIZE; i++) {
    new_lists->slist[i] = NULL;
  }

  return new_lists;
}

void expand_lists(scopeLists **scope_list) {
  if (scope_list == NULL) return;

  scopeLists *list = *scope_list;

  list->max_scope *= 2;
  list->slist = realloc(list->slist, list->max_scope * sizeof(SymbolTableEntry));

  for (int i = list->max_scope / 2; i < list->max_scope; i++) {
    list->slist[i] = NULL;
  }
}

int insert_to_scope(scopeLists *scope_list, SymbolTableEntry *token, unsigned int scope) {
  if (scope_list == NULL) return FALSE;


  if (scope >= scope_list->max_scope) {
    printf("expanding \n");
    expand_lists(&scope_list);
  }

  if (scope_list->slist[scope] != NULL) {
    SymbolTableEntry *ptr = scope_list->slist[scope];
    while (ptr->snext != NULL) ptr = ptr->snext;
    ptr->snext = token;
  } else scope_list->slist[scope] = token;

  return TRUE;
}

void print_scopes(scopeLists *scope_list) {
  for (int i = 0; i < scope_list->max_scope; i++) {
    SymbolTableEntry *ptr = scope_list->slist[i]; 
    if (ptr == NULL) continue;

    if (i > 0) printf("\n");
    printf("-----------     Scope #%d     -----------\n", i);

    while (ptr != NULL) {
      if (ptr->type == GLOBALVAR || ptr->type == LOCALVAR) {
        
        // printf("\"%s\", %d, %d, %d, %d, %p, %p, %d\n", ptr->value.varVal->name, ptr->value.varVal->scope, ptr->value.varVal->line, ptr->type, ptr->isActive, ptr->next, ptr->snext, ptr->hash_value);
        printf("\"%s\" [%s variable] (line %d) (scope %d)\n", ptr->value.varVal->name, (ptr->value.varVal->scope == 0) ? "global" : "local", ptr->value.varVal->line, ptr->value.varVal->scope);
      } else if (ptr->type == FORMAL) {
        printf("\"%s\" [formal argument] (line %d) (scope %d)\n", ptr->value.varVal->name, ptr->value.varVal->line, ptr->value.varVal->scope);
      } else {
        printf("\"%s\" [%s function] (line %d) (scope %d)\n", ptr->value.varVal->name, (ptr->type == USERFUNC) ? "user" : "library", ptr->value.varVal->line, ptr->value.varVal->scope);
      }
      ptr = ptr->snext;
    }
  }
}

int hide_scope(scopeLists *scope_list, int scope_to_hide){
  if(scope_list == NULL || scope_to_hide == 0){
    return FALSE;
  }
  if(scope_list->slist[scope_to_hide] == NULL){
    return FALSE;
  }
  SymbolTableEntry *ptr = scope_list->slist[scope_to_hide];
  while(ptr != NULL){
    ptr->isActive = INACTIVE;
    ptr = ptr->snext;
  }
  return TRUE;
}

SymbolTableEntry *is_func(scopeLists *lists, char *token, int start_scope) {
  SymbolTableEntry *ret = NULL;
  if (token == NULL || lists == NULL) return NULL;

  for (int i = start_scope; i >= 0; i--) {
    SymbolTableEntry *ptr = lists->slist[i];
    while (ptr != NULL) {
      if (strncmp(ptr->value.funcVal->name, 
        token, strlen(token)) == TRUE 
        && 
        strlen(token) == 
        strlen(ptr->value.funcVal->name)) 
        {
          if (ptr || ptr->type == USERFUNC || ptr->type == LIBFUNC) ret = ptr;  
        }
        ptr = ptr->snext;
    }
  }

  return ret;
}


// int main(int argc, char *argv[])
// {
//   printf("peos\n");
//   // SymTable *table = create_table();
//   //
//   SymbolTableEntry *node = create_node("x", 2, 2, GLOBALVAR, ACTIVE);
//   printf("%s, %d, %d, %d, %d, %p, %p, %d\n", node->value.varVal->name, node->value.varVal->scope, node->value.varVal->line, node->type, node->isActive, node->next, node->snext, node->hash_value);
//
//   SymbolTableEntry *node2 = create_node("func", 0, 18, USERFUNC, ACTIVE);
//   printf("%s, %d, %d, %d, %d, %p, %p, %d\n", node2->value.funcVal->name, node2->value.funcVal->scope, node2->value.funcVal->line, node2->type, node2->isActive, node2->next, node2->snext, node2->hash_value);
//
//   SymbolTableEntry *node3 = create_node("lempesis", 1, 2, LIBFUNC, INACTIVE);
//   printf("%s, %d, %d, %d, %d, %p, %p, %d\n\n", node3->value.funcVal->name, node3->value.funcVal->scope, node3->value.funcVal->line, node3->type, node3->isActive, node3->next, node->snext, node3->hash_value);
//
//
//   SymbolTableEntry *node4 = create_node("str", 9, 9, LIBFUNC, INACTIVE);
//   SymbolTableEntry *node5 = create_node("l", 3, 3, LIBFUNC, INACTIVE);
//   SymbolTableEntry *node8 = create_node("d", 3, 1, LIBFUNC, INACTIVE);
//   SymbolTableEntry *node6 = create_node("r", 4, 4, LIBFUNC, INACTIVE);
//   SymbolTableEntry *node7 = create_node("var", 5, 5, LIBFUNC, INACTIVE);
//   //
//   // insert_symbol(table, node);
//   // insert_symbol(table, node2);
//   // insert_symbol(table, node3);
//   //
//   // print_hash(table);
//   //
//   // free_table(table);
//   //
//   scopeLists *lists = create_scope_lists();
//
//   insert_to_scope(lists, node, 2);
//   insert_to_scope(lists, node2, 0);
//   insert_to_scope(lists, node3, 1);
//    insert_to_scope(lists, node5, 3);
//   insert_to_scope(lists, node6, 4);
//   insert_to_scope(lists, node7, 5);
//   insert_to_scope(lists, node4, 9);
//   insert_to_scope(lists, node8, 3);
//
//   print_scopes(lists);
//
//   return EXIT_SUCCESS;
// }
