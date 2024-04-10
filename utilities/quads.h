#ifndef QUADS 
#define QUADS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "symbol_table.h"

#define EXPAND_SIZE 1024
#define CURR_SIZE (total * sizeof(quad))
#define NEW_SIZE (EXPAND_SIZE * sizeof(quad) + CURR_SIZE)

typedef enum expr_t {
    var_e,
    tableitem_e,

    programfunc_e,
    libraryfunc_e,

    arithexpr_e,
    boolexpr_e,
    assignexpr_e,
    newtable_e,

    constnum_e,
    constbool_e,
    conststring_e,

    nil_e
} expr_t;

typedef enum iopcode{
    assign,add,sub,
    mul,divide,mod,
    uminus,and,or,
    not,if_eq,if_noteq,
    if_lesseq,if_greatereq,if_less,
    if_greater,call,param,
    ret,getretval,funcstart,
    funcend,tablecreate,
    tablegetelem,tablesetelem
} iopcode;

typedef struct expr{
    expr_t type;
    SymbolTableEntry* sym;
    struct expr* index;
    double numConst;
    char* strConst;
    unsigned char boolConst;
    struct expr* next;
}expr;

typedef struct quad
{
    iopcode op;
    expr* result;
    expr* arg1;
    expr* arg2;
   unsigned label;
   unsigned line;

}quad;

void emit (enum iopcode op, expr* result, expr* arg1, expr* arg2, unsigned label, unsigned line);
void expand (void);

extern quad* quads; // for parser file
extern unsigned total;
extern unsigned int currQuad;
extern int temp_count;

// quad* quads = (quad*)0;
// unsigned total = 0;
// unsigned int currQuad = 0;
// int temp_count = 0;

expr* create_expr(expr_t type, SymbolTableEntry* sym, expr* index, double numConst,char* strConst,unsigned char boolConst);

void print_expr(expr* e);
void print_quads(void);
void printOpcode(int value);

char *newtempname(void);
void resettemp(void);
SymbolTableEntry* newtemp(SymTable *symtable, scopeLists *lists, int scope, int line);

expr *lvalue_expr(SymbolTableEntry *sym);

#endif

