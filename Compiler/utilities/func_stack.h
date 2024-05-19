#ifndef FUNCTION_STACK
#define FUNCTION_STACK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "final_code.h"

typedef struct funcstack {
    struct node *func;
} funcstack;

typedef struct node {
    userfunc *s;
    struct node *prev;
} node;


funcstack *create_func_stack(void);
void push_func(funcstack *top, userfunc *f);
node *pop_func(funcstack *top);
node *peek_func(funcstack *stack);




#endif