#ifndef AVM_TABLES
#define AVM_TABLES

#include "avm_structs.hpp"

#define AVM_TABLE_HASHSIZE 211

struct avm_table* avm_tablenew(void);
void avm_tabledestroy (avm_table* t);
avm_memcell* avm_tablegetelem(avm_memcell* key);
void  avm_tablesetelem(avm_memcell *key, avm_memcell *value);

struct avm_table_bucket{
    avm_memcell key;
    avm_memcell value;
    struct avm_table_bucket* next;
};

struct avm_table{
    unsigned refCounter;
    avm_table_bucket* strIndexed[AVM_TABLE_HASHSIZE];
    avm_table_bucket* numIndexed[AVM_TABLE_HASHSIZE];
    unsigned total;
};

void avm_tableincrefcounter(avm_table* t);

void avm_tabledecrefcounter(avm_table* t);

void avm_tablebucketsinit(avm_table_bucket ** p);

void avm_memcellclear(avm_memcell* m);
void avm_tablebucketsdestroy(avm_table_bucket **p);


#endif