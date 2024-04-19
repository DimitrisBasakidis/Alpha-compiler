#ifndef ELIST
#define ELIST

#include "quads.h"

typedef struct call_t {
    expr *elist;
    unsigned char method;
    char *name;
} call_t;

expr *insert_node(expr *head, expr *expression);

expr *make_call(expr *lv, expr *reversed_elist, unsigned line, SymbolTableEntry *tempvar);

expr *newexpr_constnum(double i); 

expr *get_last(expr* head);

void print_li2st(expr* head);

expr *emit_iftableitem(expr *e,SymTable *symtable, scopeLists *lists, unsigned int scope, unsigned int line);

expr* member_item(expr* lvalue, char* name,SymTable *symtable, scopeLists *lists,unsigned int scope, unsigned int line);

#endif