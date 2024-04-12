#ifndef SCOPES
#define SCOPES

#include <stdio.h>
#include <assert.h>

typedef enum scopespace_t {
    programvar,
    functionlocal,
    formararg
} scopespace_t;


// unsigned programVarOffset = 0;
// unsigned functionLocalOffset = 0;
// unsigned formalArgOffset = 0;
// unsigned scopeSpaceCounter = 1;

extern unsigned programVarOffset;
extern unsigned functionLocalOffset;
extern unsigned formalArgOffset;
extern unsigned scopeSpaceCounter;

enum scopespace_t currscopespace(void);
unsigned currscopeoffset(void);
unsigned incurrscopeoffset(void);

void enterscopespace(void);

void exitscopespace(void);

void resetformalargsoffset(void);

void resetfunctionlocaloffset(void);

void restorecurrentscopeoffset(unsigned n);

unsigned nextquadlabel(void);
void patchlabel(unsigned quadNo, unsigned label);

#endif