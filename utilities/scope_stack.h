#ifndef SCOPE_STACK
#define SCOPE_STACK

#include <stdio.h>
#include <stdlib.h>

typedef struct scopestack_t {
    unsigned int x;
    struct scopestack_t *prev;
}scopestack_t;

typedef struct scope_stack {
    scopestack_t *s;
} scope_stack;

scope_stack *create_scope_stack(void);
void push(scope_stack *top, unsigned int a);
scopestack_t *pop(scope_stack *top);




#endif