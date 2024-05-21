#ifndef AVM_STRUCTS
#define AVM_STRUCTS

// #include "avm_tables.hpp"
#include <iostream>
#include <cstring>
#include <assert.h>
#include <stdio.h>

#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m) memset(&m,0,sizeof(m))

typedef enum avm_memcell_t {
    number_m = 0,
    string_m = 1,
    bool_m = 2,
    table_m = 3,
    userfunc_m = 4,
    libfunc_m = 5,
    nil_m = 6,
    undef_m = 7
} avm_memcell_t;

struct avm_table;

typedef struct avm_memcell {
    avm_memcell_t type;
    union {
        double numVal;
        char *strVal;
        unsigned char boolVal;
        struct avm_table *tableVal;
        unsigned funcVal;
        char *libfuncVal;
    } data;
} avm_memcell;

extern avm_memcell stack[AVM_STACKSIZE];

void avm_initstack(void);

void avm_memclear(avm_memcell* m);

typedef void (*memclear_func_t) (avm_memcell*);

extern memclear_func_t memclearFuncs[];

#endif
