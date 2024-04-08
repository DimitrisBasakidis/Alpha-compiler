#ifndef GRAMMAR
#define GRAMMAR

#include "../utilities/symbol_table.h"
#include "../utilities/structs.h"

#include <stdlib.h>

enum iopcode{
    assign,add,sub,
    mul,div,mod,
    uminus,and,or,
    not,if_eq,if_noteq,
    if_lesseq,if_greatereq,if_less,
    if_greater,call,param,
    ret,getretval,funcstart,
    funcend,tablecreate,
    tablegetelem,tablesetelem
};
typedef struct expr expr;

typedef struct quad
{
    enum iopcode op;
    expr* result;
    expr* arg1;
    expr* arg2;
   unsigned label;
   unsigned line;

}quad;

quad* quads = (quad*)0;
unsigned total = 0;

extern int scope;
extern int func_in_between;
extern int is_return_kw;
extern int from_func_call;
extern int in_loop;
extern int from_elist;
extern int while_loop;
extern int for_loop;
extern int if_stmt;
extern int global_val_exists;
extern int is_local_kw;

int manage_break(void (*print_errors)(const char *, char *, const char *));
int manage_continue(void (*print_errors)(const char *, char *, const char *));
int manage_increment(SymbolTableEntry *entry, char *token, void (*print_errors)(const char *, char *, const char *));
int manage_decrement(SymbolTableEntry *entry, char *token, void (*print_errors)(const char *, char *, const char *));
int manage_assignexpr(SymTable *symtable, scopeLists *lists, SymbolTableEntry *entry, char *token, void (*print_errors)(const char *, char *, const char *), int line);
int manage_lvalue(SymTable *symtable, scopeLists *lists, SymbolTableEntry *entry, char *token, void (*print_errors)(const char *, char *, const char *), int line);
int manage_call(SymTable *symtable, scopeLists *lists, SymbolTableEntry *entry, char *token, void (*print_errors)(const char *, char *, const char *), int line);
int manage_local_id(SymTable *symtable, scopeLists *lists, SymbolTableEntry *entry, char *token, void (*print_errors)(const char *, char *, const char *), int line);
int manage_double_colon_id(SymbolTableEntry *entry, char *token, void (*print_errors)(const char *, char *, const char *));
int manage_function(SymTable *symtable, scopeLists *lists, SymbolTableEntry *entry, char *token, void (*print_errors)(const char *, char *, const char *), int line);
int manage_lib_function(char *token, void (*print_errors)(const char *, char *, const char *));
int manage_id(SymTable *symtable, scopeLists *lists, SymbolTableEntry *entry_g, SymbolTableEntry *entry_l, char *token, void (*print_errors)(const char *, char *, const char *), int line);
int manage_return(void (*print_errors)(const char *, char *, const char *));

#endif