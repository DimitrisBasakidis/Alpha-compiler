#include "scopes.h"
#include "quads.h"

enum scopespace_t currscopespace(void) {
    if (scopeSpaceCounter == 1) {
        return programvar;
    } else if (scopeSpaceCounter % 2 == 0) {
        return formalarg;
    } else {
        return functionlocal;
    }
}

unsigned currscopeoffset(void) {
    switch (currscopespace()) {
        case programvar    : return programVarOffset;
        case functionlocal : return functionLocalOffset;
        case formalarg     : return formalArgOffset;
        default: assert(0);
    }
}

unsigned incurrscopeoffset(void) {
    switch (currscopespace()) {
        case programvar    : ++programVarOffset; break;
        case functionlocal : ++functionLocalOffset; break;
        case formalarg     : ++formalArgOffset; break;
        default: assert(0);
    }
}

void enterscopespace(void) { ++scopeSpaceCounter; }

void exitscopespace(void) { assert(scopeSpaceCounter > 1); --scopeSpaceCounter; }

void resetformalargsoffset(void) { formalArgOffset = 0; }

void resetfunctionlocaloffset(void) { functionLocalOffset = 0; }

void restorecurrentscopeoffset(unsigned n) {
    switch (currscopespace()) {
        case programvar     : programVarOffset = n; break;
        case functionlocal  : functionLocalOffset = n; break;
        case formalarg      : formalArgOffset = n; break;
        default: assert(0);
    }
} 

unsigned nextquadlabel(void) { return currQuad ; }

void patchlabel(unsigned quadNo, unsigned label) {
    assert(quadNo < currQuad);
    quads[quadNo].label = label;    
}

