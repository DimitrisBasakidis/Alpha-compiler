#ifndef AVM_DISPATCHER
#define AVM_DISPATCHER

#include "../Compiler/utilities/final_code.h"
#include "avm_utilities.hpp"
#include "avm_structs.hpp"
#include "avm_tables.hpp"
#include "decodeBinary.hpp"
#include <cassert>
#include <sstream>
#include <assert.h>
#include <iomanip>
#include <math.h>
#include <map>

typedef void (*execute_func_t) (instruction*);
typedef string (*to_stringfunc_t)(avm_memcell*);
typedef double (*arithmetic_func_t)(double x, double y);
typedef void (*library_func_t)(void);
typedef unsigned char (*tobool_func_t)(avm_memcell*);

extern map<string, library_func_t> lib_map;

#define AVM_MAX_INSTRUCTIONS (unsigned) nop_v
#define AVM_ENDING_PC codeSize

#define AVM_NUMACTUALS_OFFSET 4
#define AVM_SAVEDPC_OFFSET    3
#define AVM_SAVEDTOP_OFFSET   2
#define AVM_SAVEDTOPSP_OFFSET 1

#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mul execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic

extern to_stringfunc_t tostringFuncs[];

extern arithmetic_func_t arithmeticFuncs[];

extern tobool_func_t toboolFuncs[];

library_func_t avm_getlibraryfunc(char *id);

extern string number_tostring (avm_memcell*);
extern string string_tostring (avm_memcell*);
extern string bool_tostring (avm_memcell*);
extern string table_tostring (avm_memcell*);
extern string userfunc_tostring (avm_memcell*);
extern string libfunc_tostring (avm_memcell*);
extern string nil_tostring (avm_memcell*);
extern string undef_tostring (avm_memcell*);

extern unsigned codeSize;
extern unsigned totalActuals;
extern execute_func_t executeFuncs[];


extern void execute_assign (instruction*);
extern void execute_add (instruction*);
extern void execute_sub (instruction*);
extern void execute_mul (instruction*);
extern void execute_div (instruction*);
extern void execute_mod (instruction*);
extern void execute_uminus (instruction*);
extern void execute_and (instruction*);
extern void execute_or (instruction*);
extern void execute_not (instruction*);
extern void execute_jump(instruction*);
extern void execute_jeq (instruction*);
extern void execute_jne (instruction*);
extern void execute_jle (instruction*);
extern void execute_jge (instruction*);
extern void execute_jlt (instruction*);
extern void execute_jgt (instruction*);
extern void execute_call (instruction*);
extern void execute_pusharg (instruction*);
extern void execute_funcenter (instruction*);
extern void execute_funcexit (instruction*);
extern void execute_newtable (instruction*);
extern void execute_tablegetelem (instruction*);
extern void execute_tablesetelem (instruction*);
extern void execute_nop (instruction*);

extern void avm_warning (char* format, ...);
extern void avm_assign (avm_memcell* lv, avm_memcell *rv);
void avm_push_table_arg(avm_table* t);
void avm_call_functor(avm_table* t);

extern void execute_cycle(void);
void avm_dec_top (void);
void avm_push_envvalue (unsigned val);
void avm_callsaveenvironment(void);
userfunc* avm_getfuncinfo(unsigned address);
unsigned avm_get_envvalue(unsigned i);

unsigned avm_totalactuals(void);
void avm_calllibfunc ( char * id);
avm_memcell *avm_getactual(unsigned i);
void libfunc_print (void);
void libfunc_typeof (void);
void avm_registerlibfunc(char * id, library_func_t addr);

string avm_tostring(avm_memcell *m);
double add_impl(double x, double y);
double sub_impl(double x, double y);
double mul_impl(double x, double y);
double div_impl(double x, double y);
double mod_impl(double x, double y);


void execute_arithmetic(instruction *inst);

unsigned char number_tobool(avm_memcell *m);
unsigned char string_tobool(avm_memcell *m);
unsigned char bool_tobool(avm_memcell *m);
unsigned char table_tobool(avm_memcell *m);
unsigned char userfunc_tobool(avm_memcell *m);
unsigned char libfunc_tobool(avm_memcell *m);
unsigned char nil_tobool(avm_memcell *m);
unsigned char undef_tobool(avm_memcell *m);

extern tobool_func_t toboolFuncs[];
unsigned char avm_tobool(avm_memcell *m);

void avm_initialize(void);
void libfunc_totalarguments(void);
library_func_t avm_getlibraryfunc(char *id);

void print_stack();
void print_memcell(avm_memcell *m);

#endif
