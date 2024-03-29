#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#define SCOPE_SIZE 5

#define SIZE 1024
#define HASH_MULTIPLIER 65599

#define HASH  0
#define SCOPE 1

#define ACTIVE   1
#define INACTIVE 0

#define TRUE  0
#define FALSE 1

typedef struct Variable {
    char *name;
    unsigned int scope;
    unsigned int line;
} Variable;

typedef struct Function {
    char *name;
    //arg list
    unsigned int scope;
    unsigned int line;
} Function;

enum varFlag {
  NO_KW, LOCAL_KW, FUNC, LOCAL_FUNC
};

enum SymbolType  {
    GLOBALVAR, LOCALVAR, FORMAL,
    USERFUNC, LIBFUNC
};

typedef struct SymbolTableEntry {
    int isActive;
    union {
        Variable *varVal;
        Function *funcVal;
    } value;
    enum SymbolType type;
    struct SymbolTableEntry *next;
    struct SymbolTableEntry *snext;
    unsigned int hash_value;
} SymbolTableEntry;

typedef struct scopeLists {
  unsigned int max_scope;
  SymbolTableEntry **slist;   //slist[0];
} scopeLists;

typedef struct SymTable {
    unsigned int count;
    SymbolTableEntry *table[SIZE];
} SymTable;

SymTable *create_table(void);

scopeLists *create_scope_lists(void);

void free_table(SymTable *table);

SymbolTableEntry *create_node(char *name, unsigned int scope, unsigned int line, enum SymbolType type, int status);

SymbolTableEntry *lookup(SymTable *symtable, scopeLists *lists, char *token, enum SymbolType type, int scope, int flag);

int insert_symbol(SymTable *table, SymbolTableEntry *entry);

int insert_to_scope(scopeLists *scope_list, SymbolTableEntry *token, unsigned int scope);

int exists_in_scope(SymbolTableEntry *head, char *token);

void print_scopes(scopeLists *scope_list);

void add_lib_func(SymTable *table, scopeLists *lists);

int lookup_lib_func(char *token);

void print_hash(SymTable *symtable);

SymbolTableEntry *is_func(scopeLists *lists, char *token, int start_scope);

int hide_scope(scopeLists *scope_list, int scope_to_hide);

int find_scope_from_hash(SymTable *symtable, char* token);

#endif
