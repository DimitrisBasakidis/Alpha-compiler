#include "avm_tables.hpp"

memclear_func_t memclearFuncs[]= {
    0,
    memclear_string,
    0,
    memclear_table,
    0,
    0,
    0,
    0
};


void avm_tableincrefcounter(avm_table* t){
    ++t->refCounter;
}

void avm_tabledecrefcounter(avm_table* t){
    assert(t->refCounter>0);
    if(!--t->refCounter)
        avm_tabledestroy(t);
}

void avm_tablebucketsinit(avm_table_bucket ** p){
    for(unsigned i = 0; i<AVM_TABLE_HASHSIZE;++i){
        p[i] = (avm_table_bucket*) 0;
    }
}

avm_table* avm_tablenew(void){
    avm_table *t = (avm_table* ) malloc(sizeof(avm_table));
    AVM_WIPEOUT(*t);

    t->refCounter = t->total = 0;
    avm_tablebucketsinit(t->numIndexed);
    avm_tablebucketsinit(t->strIndexed);
    
    return t;
}

void avm_tablebucketsdestroy(avm_table_bucket **p){
    for(unsigned i=0; i<AVM_TABLE_HASHSIZE;++i,++p){
        for(avm_table_bucket* b = *p; b;){
            avm_table_bucket* del = b;
            b = b->next;
            avm_memcellclear(&del->key);
            avm_memcellclear(&del->value);
            free(del);
        }
        p[i] = (avm_table_bucket*) 0;
    }
}

void avm_tabledestroy (avm_table* t ){
    avm_tablebucketsdestroy(t->strIndexed);
    avm_tablebucketsdestroy(t->numIndexed);
    free(t);
}

void memclear_table(avm_memcell* m) {
    assert(m->data.tableVal);
    avm_tabledecrefcounter(m->data.tableVal);
}


void memclear_string(avm_memcell* m) {
    assert(m->data.strVal);
    free(m->data.strVal);
}

void avm_memcellclear (avm_memcell* m){
    if(m->type != undef_m){
        memclear_func_t f = memclearFuncs[m->type];
        if(f)
            (*f)(m);
        m->type = undef_m;
    }
}

void avm_tablesetelem(avm_memcell *key, avm_memcell *value) {
    return;
}

avm_memcell* avm_tablegetelem(avm_table *t, avm_memcell* key) {
    return nullptr;
}