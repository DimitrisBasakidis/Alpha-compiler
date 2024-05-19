#ifndef QUADS 
#define QUADS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "symbol_table.h"
#include "scope_stack.h"

#define EXPAND_SIZE 1024
#define CURR_SIZE (total * sizeof(quad))
#define NEW_SIZE (EXPAND_SIZE * sizeof(quad) + CURR_SIZE)

typedef struct forstruct_t {
    int enter;
    int test;
}forstruct_t;

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

typedef enum iopcode {
    assign,add,sub,
    mul,divide,mod,
    uminus,and_op,or_op,
    not_op,if_eq,if_noteq,
    if_lesseq,if_greatereq,if_less,
    if_greater,call,param,
    ret,getretval,funcstart,
    funcend,tablecreate,
    tablegetelem,tablesetelem,jump
} iopcode;

typedef struct expr{
    expr_t type;
    SymbolTableEntry* sym;
    struct expr* index;
    double numConst;
    char* strConst;
    unsigned char boolConst;
    int trueList;
    int falseList;
    struct expr* next;
} expr;

typedef struct stmt_t {
    int breakList;
    int contList;
    int retList;
} stmt_t;

typedef struct quad {
    iopcode op;
    expr* result;
    expr* arg1;
    expr* arg2;
   unsigned label;
   unsigned line;
   unsigned taddress;

} quad;

void emit (enum iopcode op, expr* result, expr* arg1, expr* arg2, unsigned label, unsigned line);
void expand (void);

extern quad* quads;
extern unsigned total;
extern unsigned int currQuad;
extern int temp_count;

expr* create_expr(expr_t type, SymbolTableEntry* sym, expr* index, double numConst,char* strConst,unsigned char boolConst);
stmt_t *make_stmt (struct stmt_t* s);
int newlist (int i);
int mergelist (int l1, int l2);
void patchlist (int list, int label);

char* print_expr(expr* e, FILE *ptr);
void print_quads(FILE *ptr);
int print_opcode(int value, FILE *ptr);
void check_arith(expr* e, const char* context);

char *newtempname(void);
void resettemp(void);
SymbolTableEntry* newtemp(SymTable *symtable, scopeLists *lists, int scope, int line);

expr *lvalue_expr(SymbolTableEntry *sym);
expr* create_and_emit_arith_expr(SymTable* symtable,scopeLists *lists,int scope,int yylineno,expr* arg1, expr* arg2,iopcode op);
expr* create_and_emit_bool_expr(SymTable* symtable,scopeLists *lists,int scope,int yylineno,expr* arg1, expr* arg2,iopcode op);
void check_expr(expr* a , expr* b,void (*print_errors)(const char *, char *, const char *));
expr* manage_bool_expr(expr* boolean,SymTable *symtable, scopeLists *lists, int scope, int yylineno);
expr* do_bool(expr* e,int yylineno);


#endif

