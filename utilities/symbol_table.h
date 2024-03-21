#ifndef SYMBOL_TABLE
#define SYMBOL_TABLE

#define SIZE 1024
#define HASH_MULTIPLIER 65599

typedef struct Variable {
    const char *name;
    unsigned int scope;
    unsigned int line;
} Variable;

typedef struct Function {
    const char *name;
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
        Variable  *varVal;
        Function  *funcVal;
    } value;
    enum SymbolType  type;
} SymbolTableEntry;

typedef struct SymTable {
    unsigned int count;
    SymbolTableEntry *table[SIZE];
} SymTable;

SymTable *create_table(void);

void free_table(SymTable *table);

int insert(SymTable *table, SymbolTableEntry *entry);

#endif