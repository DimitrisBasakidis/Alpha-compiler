#include "scope_stack.h"


scope_stack *create_scope_stack(void){
    scope_stack *tmp = malloc(sizeof(scope_stack));

    return tmp;
}

void push(scope_stack *top, unsigned int a){

    if (top == NULL) return;

    scopestack_t *tmp = malloc(sizeof(scopestack_t));
    tmp->x =a;
    tmp->prev = NULL;

    if (top->s == NULL){
        top->s = tmp;
        return;
    }
    tmp->prev = top->s;
    top->s = tmp;
}

scopestack_t *pop(scope_stack *top){
    if (top == NULL) return NULL;

    scopestack_t *tmp = top->s;
    top->s = top->s->prev;
    return tmp;
}


indexed_list_t* create_indexlist_node(expr* index,expr* value){
    indexed_list_t *new = malloc(sizeof(indexed_list_t));
    new->index = index;
    new->value = value;
    return new;
}

scopestack_t *peek(scope_stack *stack) {
    if (stack == NULL) return NULL;

    return stack->s;    
}
