#ifndef final_code
#define final_code

#define EXPAND_INSTRUCTION_SIZE 1024
#define CURR_INSTRUCTION_SIZE (total_f * sizeof(instruction))
#define NEW_INSTRUCTION_SIZE  (EXPAND_INSTRUCTION_SIZE * sizeof(instruction) + CURR_INSTRUCTION_SIZE)

#define CURR_STRING_CONSTS_SIZE (totalStringConsts * sizeof(char *))
#define NEW_STRING_CONSTS_SIZE  (EXPAND_INSTRUCTION_SIZE * sizeof(char *) + CURR_STRING_CONSTS_SIZE)

#define CURR_NUMBER_CONSTS_SIZE (totalNumConsts * sizeof(double))
#define NEW_NUMBER_CONSTS_SIZE  (EXPAND_INSTRUCTION_SIZE * sizeof(double) + CURR_NUMBER_CONSTS_SIZE)

#define CURR_NAMED_LIBFUNCS_SIZE (totalNamedLibFuncs * sizeof(char *))
#define NEW_NAMED_LIBFUNCS_SIZE  (EXPAND_INSTRUCTION_SIZE * sizeof(char *) + CURR_NAMED_LIBFUNCS_SIZE)

#define CURR_USER_FUNCS_SIZE (totalUserFuncs * sizeof(userfunc))
#define NEW_USER_FUNCS_SIZE  (EXPAND_INSTRUCTION_SIZE * sizeof(userfunc) + CURR_USER_FUNCS_SIZE)


#include "quads.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum vmarg_t { label_a,global_a,local_a,formal_a,bool_a,string_a,number_a,nil_a,userfunc_a,libfunc_a,retval_a,noarg_a = -69 }vmarg_t;

typedef enum vmopcode {
    assign_v, add_v, sub_v,
    mul_v, div_v, mod_v,
    uminus_v, and_v, or_v,
    not_v,jump_v, jeq_v, jne_v,
    jle_v, jge_v, jlt_v,
    jgt_v, call_v, pusharg_v,
    funcenter_v, funcexit_v, newtable_v,
    tablegetelem_v, tablesetelem_v, nop_v
} vmopcode;

typedef struct vmarg { 
    enum vmarg_t type; 
    unsigned val; 
} vmarg;

typedef struct instruction {
    vmopcode opcode;
    vmarg result;
    vmarg arg1;
    vmarg arg2;
    unsigned srcLine;
} instruction;

typedef struct userfunc {
    unsigned address;
    unsigned localSize;
    char *id;
} userfunc; 

extern double *numConsts;
extern unsigned totalNumConsts;
extern unsigned currNumConsts;
extern char **stringConsts;
extern unsigned totalStringConsts;
extern unsigned currStringConsts;
extern char **namedLibFuncs;
extern unsigned totalNamedLibFuncs;
extern unsigned currNamedLibFuncs;
extern userfunc *userFuncs;
extern unsigned totalUserFuncs;
extern unsigned currUserFuncs;

extern instruction* instructions;
extern unsigned total_f;
extern unsigned int currInstruction;

typedef struct incomplete_jump {
    unsigned instrNo;
    unsigned iaddress;
    struct incomplete_jump *next;
} incomplete_jump; 

extern incomplete_jump *ij_head;
extern unsigned ij_total;

void add_incomplete_jump(unsigned instrNo, unsigned iaddress);

void patch_incomplete_jumps();

void make_operand(expr* e, vmarg* arg);

unsigned consts_newstring(char* s);
unsigned consts_newnumber(double n);
unsigned libfuncs_newused(char* s);
void fexpand (void);
unsigned consts_newstring(char* str);
unsigned consts_newnumber(double num);
unsigned libfuncs_newused(char* libfunc_name);
unsigned userfuncs_newused(SymbolTableEntry *sym);
unsigned nextinstructionlabel();
void make_numberoperand(vmarg* arg, double val);
void make_booloperand(vmarg* arg , unsigned val);
void make_retvaloperand(vmarg* arg);
void femit(instruction* t);

#endif