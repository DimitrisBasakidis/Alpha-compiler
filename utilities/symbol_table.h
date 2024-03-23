#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#define SIZE 1024
#define HASH_MULTIPLIER 65599

#define ACTIVE   1
#define INACTIVE 0

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

enum SymbolType  {
    GLOBAL, LOCAL, FORMAL,
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

// typedef struct scopeList {
//   SymbolTableEntry *head;  
// } scopeList;

typedef struct SymTable {
    unsigned int count;
    SymbolTableEntry *table[SIZE];
} SymTable;

SymTable *create_table(void);

void free_table(SymTable *table);

SymbolTableEntry *create_node(char *name, unsigned int scope, unsigned int line, enum SymbolType type, int status);

int insert(SymTable *table, SymbolTableEntry *entry);

#endif
