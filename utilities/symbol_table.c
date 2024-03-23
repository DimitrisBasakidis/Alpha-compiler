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
    case GLOBAL:
    case LOCAL:
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

int insert(SymTable *symtable, SymbolTableEntry *entry) {
  if (table == NULL) return FALSE;



  if (symtable->table[entry->hash_value] != NULL) {
    entry->next = symtable->table[entry->hash_value];
  }

  symtable->table[entry->hash_value] = entry;
 

  
}



int main(int argc, char *argv[])
{

  SymTable *table = create_table();

  SymbolTableEntry *node = create_node("x", 2, 2, GLOBAL, ACTIVE);
  printf("%s, %d, %d, %d, %d, %p, %p, %d\n", node->value.varVal->name, node->value.varVal->scope, node->value.varVal->line, node->type, node->isActive, node->next, node->snext, node->hash_value);

  SymbolTableEntry *node2 = create_node("func", 0, 18, USERFUNC, ACTIVE);
  printf("%s, %d, %d, %d, %d, %p, %p, %d\n", node2->value.varVal->name, node2->value.varVal->scope, node2->value.varVal->line, node2->type, node2->isActive, node2->next, node2->snext, node2->hash_value);

  SymbolTableEntry *node3 = create_node("lempesis", 1, 2, LIBFUNC, INACTIVE);
  printf("%s, %d, %d, %d, %d, %p, %p, %d\n", node3->value.varVal->name, node3->value.varVal->scope, node3->value.varVal->line, node3->type, node3->isActive, node3->next, node->snext, node3->hash_value);

  free_table(table);

  return EXIT_SUCCESS;
}
