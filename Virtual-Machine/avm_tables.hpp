#ifndef AVM_TABLES
#define AVM_TABLES

#include "avm_structs.hpp"
#include <map>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <iostream>

using namespace std;

extern memclear_func_t memclearFuncs[];

typedef struct avm_table {
    unsigned refCounter;
    map<double, avm_memcell*> indexedDouble;
    map<string, avm_memcell*> indexedStrVal;
} avm_table;

struct avm_memcell;

struct avm_table* avm_tablenew(void);
void avm_tablesetelem(struct avm_table *table, avm_memcell *key, avm_memcell *value);
avm_memcell* avm_tablegetelem(avm_table *t, avm_memcell* key);
void memclear_string(avm_memcell* m);
void memclear_table(avm_memcell* m);
void avm_tabledestroy (avm_table* t);
void avm_memcellclear (avm_memcell* m);
char* lookup_based_on_instr_addr(unsigned addr);

string avm_printtable(const avm_table* table);


#endif