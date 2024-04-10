#ifndef GRAMMAR
#define GRAMMAR

#include "../utilities/symbol_table.h"


#include <stdlib.h>

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
SymbolTableEntry *manage_lvalue(SymTable *symtable, scopeLists *lists, char *token, void (*print_errors)(const char *, char *, const char *), int line);
int manage_call(SymTable *symtable, scopeLists *lists, SymbolTableEntry *entry, char *token, void (*print_errors)(const char *, char *, const char *), int line);
int manage_local_id(SymTable *symtable, scopeLists *lists, SymbolTableEntry *entry, char *token, void (*print_errors)(const char *, char *, const char *), int line);
int manage_double_colon_id(SymbolTableEntry *entry, char *token, void (*print_errors)(const char *, char *, const char *));
int manage_function(SymTable *symtable, scopeLists *lists, SymbolTableEntry *entry, char *token, void (*print_errors)(const char *, char *, const char *), int line);
int manage_lib_function(char *token, void (*print_errors)(const char *, char *, const char *));
int manage_id_list(SymTable *symtable, scopeLists *lists, SymbolTableEntry *entry_g, SymbolTableEntry *entry_l, char *token, void (*print_errors)(const char *, char *, const char *), int line);
int manage_return(void (*print_errors)(const char *, char *, const char *));
int manage_id(SymTable *symtable, scopeLists *lists, char *token, int line, int scope, void (*print_errors)(const char *, char *, const char *));

#endif