#ifndef SCOPES
#define SCOPES

#include <stdio.h>
#include <assert.h>

typedef enum scopespace_t {
    programvar,
    functionlocal,
    formalarg
} scopespace_t;

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