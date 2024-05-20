#ifndef AVM_TABLES
#define AVM_TABLES

#include "avm_structs.hpp"

#define AVM_TABLE_HASHSIZE 211

extern memclear_func_t memclearFuncs[];


typedef struct avm_table_bucket{
    avm_memcell key;
    avm_memcell value;
    struct avm_table_bucket* next;
} avm_table_bucket;

typedef struct avm_table {
    unsigned refCounter;
    avm_table_bucket* strIndexed[AVM_TABLE_HASHSIZE];
    avm_table_bucket* numIndexed[AVM_TABLE_HASHSIZE];
    unsigned total;
} avm_table;

struct avm_memcell;

struct avm_table* avm_tablenew(void);
void avm_tabledestroy (avm_table* t);
avm_memcell* avm_tablegetelem(avm_table *t, avm_memcell* key);
void  avm_tablesetelem(avm_memcell *key, avm_memcell *value);

void avm_tableincrefcounter(avm_table* t);

void avm_tabledecrefcounter(avm_table* t);

void avm_tablebucketsinit(avm_table_bucket ** p);

void avm_memcellclear(avm_memcell* m);
void avm_tablebucketsdestroy(avm_table_bucket **p);

void memclear_table(avm_memcell* m);

void memclear_string(avm_memcell* m);



void avm_memclear (avm_memcell* m);


#endif