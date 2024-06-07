#ifndef AVM_UTILITIES
#define AVM_UTILITIES


#include "../Compiler/utilities/final_code.h"
#include "avm_structs.hpp"
#include "decodeBinary.hpp"


#define AVM_STACKENV_SIZE 4
#define AVM_STACKSIZE 4096

extern avm_memcell ax, bx, cx;
extern avm_memcell retval;
extern unsigned top, topsp;

double consts_getnumber(unsigned index);
char* consts_getstring(unsigned index);
char* libfuncs_getused(unsigned index);
userfunc userfuncs_getfunc(unsigned index);
avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg);

#endif