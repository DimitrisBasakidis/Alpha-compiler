#include "symbol_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
      new_entry->value.varVal = malloc(sizeof(struct Variable));
      new_entry->value.varVal->name = malloc(sizeof(char) * length);
      strncpy(new_entry->value.varVal->name, name, length);
      new_entry->value.varVal->scope = scope;
      new_entry->value.varVal->line = line;
      new_entry->hash_value = hash(new_entry->value.varVal->name);

      break;
    case FORMAL:
      break;

    case LIBFUNC:
    case USERFUNC:
      new_entry->value.funcVal = malloc(sizeof(struct Function));
      new_entry->value.funcVal->name = malloc(sizeof(char) * length);
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

int insert_symbol(SymTable *symtable, SymbolTableEntry *entry) {
  if (symtable == NULL) return FALSE;


  if (symtable->table[entry->hash_value] != NULL) {
    entry->next = symtable->table[entry->hash_value];
  }

  symtable->table[entry->hash_value] = entry;
  

 return TRUE; 
}

int lookup(SymTable *symtable, char *token, enum SymbolType type) {
  if (symtable == NULL) return FALSE;

  int index = hash(token);
  SymbolTableEntry *ptr = symtable->table[index];

  if (symtable->table[index] != NULL) {
    while(ptr != NULL) {
      // printf("inside lookup %s\n",(type == GLOBALVAR || type == LOCALVAR) ? 
      //     ptr->value.varVal->name : 
      //     ptr->value.funcVal->name );
      if (strncmp((type == GLOBALVAR || type == LOCALVAR) ? 
          ptr->value.varVal->name : 
          ptr->value.funcVal->name, 
          token, strlen(token)) == 0) {
        return TRUE;
      }
    }
  }
  
  return FALSE;
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


void add_lib_func(SymTable *symtable) {
  if (symtable == NULL) return;
  
  insert_symbol(symtable, create_node("sin", 0, 0, LIBFUNC, ACTIVE));
  insert_symbol(symtable, create_node("cos", 0, 0, LIBFUNC, ACTIVE));
  insert_symbol(symtable, create_node("sqrt", 0, 0, LIBFUNC, ACTIVE));
  insert_symbol(symtable, create_node("strtonum", 0, 0, LIBFUNC, ACTIVE));
  insert_symbol(symtable, create_node("typeof", 0, 0, LIBFUNC, ACTIVE));
  insert_symbol(symtable, create_node("argument", 0, 0, LIBFUNC, ACTIVE));
  insert_symbol(symtable, create_node("totalarguments", 0, 0, LIBFUNC, ACTIVE));
  insert_symbol(symtable, create_node("objectcopy", 0, 0, LIBFUNC, ACTIVE));
  insert_symbol(symtable, create_node("objectotalmembers", 0, 0, LIBFUNC, ACTIVE));
  insert_symbol(symtable, create_node("objectmemberkeys", 0, 0, LIBFUNC, ACTIVE));
  insert_symbol(symtable, create_node("input", 0, 0, LIBFUNC, ACTIVE));
  insert_symbol(symtable, create_node("print", 0, 0, LIBFUNC, ACTIVE));

}



// int main(int argc, char *argv[])
// {
//   printf("peos\n");
//   SymTable *table = create_table();
//
//   SymbolTableEntry *node = create_node("x", 2, 2, GLOBAL, ACTIVE);
//   printf("%s, %d, %d, %d, %d, %p, %p, %d\n", node->value.varVal->name, node->value.varVal->scope, node->value.varVal->line, node->type, node->isActive, node->next, node->snext, node->hash_value);
//
//   SymbolTableEntry *node2 = create_node("func", 0, 18, USERFUNC, ACTIVE);
//   printf("%s, %d, %d, %d, %d, %p, %p, %d\n", node2->value.funcVal->name, node2->value.funcVal->scope, node2->value.funcVal->line, node2->type, node2->isActive, node2->next, node2->snext, node2->hash_value);
//
//   SymbolTableEntry *node3 = create_node("lempesis", 1, 2, LIBFUNC, INACTIVE);
//   printf("%s, %d, %d, %d, %d, %p, %p, %d\n\n", node3->value.funcVal->name, node3->value.funcVal->scope, node3->value.funcVal->line, node3->type, node3->isActive, node3->next, node->snext, node3->hash_value);
//
//   insert(table, node);
//   insert(table, node2);
//   insert(table, node3);
//
//   print_hash(table);
//
//   free_table(table);
//
//   return EXIT_SUCCESS;
// }
