#ifndef AVM_STRUCTS
#define AVM_STRUCTS


#include <iostream>
#include <assert>
#include <stdio.h>


#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m) memset(&m,0,sizeof(m))

avm_memcell stack[AVM_STACKSIZE];


typedef enum avm_memcell_t {
    number_m = 0,
    string_m = 1,
    bool_m = 2,
    table_m = 3,
    userfunc_m = 4,
    libfunc_m = 5,
    nil_m = 6,
    undef_m = 7
}avm_memcell_t;

struct avm_table;
struct avm_memcell{
    avm_memcell_t type;
    union{
        double numVal;
        char* strVal;
        unsigned char boolVal;
        struct avm_table* tableVal;
        unsigned funcVal;
        char* libfuncVal;
    }data;
};

static void avm_initstack(void);


#endif
