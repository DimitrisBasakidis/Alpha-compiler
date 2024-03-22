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