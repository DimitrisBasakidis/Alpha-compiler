#include "scopes.h"

enum scopespace_t currscopespace(void) {
    if (scopeSpaceCounter == 1) {
        return programvar;
    } else if (scopeSpaceCounter % 2 == 0) {
        return formararg;
    } else {
        return functionlocal;
    }
}

unsigned currscopeoffset(void) {
    switch (currscopespace()) {
        case programvar    : return programVarOffset;
        case functionlocal : return functionLocalOffset;
        case formararg     : return formalArgOffset;
        default: assert(0);
    }
}

unsigned incurrscopeoffset(void) {
    switch (currscopespace()) {
        case programvar    : ++programVarOffset; break;
        case functionlocal : ++functionLocalOffset; break;
        case formararg     : ++formalArgOffset; break;
        default: assert(0);
    }
}

void enterscopespace(void) { ++scopeSpaceCounter; }

void exitscopespace(void) { assert(scopeSpaceCounter > 1); --scopeSpaceCounter; }

// int main() {
//     printf("awdawd\n");
// }