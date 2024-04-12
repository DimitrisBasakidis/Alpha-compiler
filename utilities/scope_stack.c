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



// int main(){
//    scope_stack *tmp = create_stack();


//     // stack = push(stack,2);
//     // stack = push(stack,3);
//     // stack = pop(stack);
//     // stack = pop(stack);

//     //print(stack);
// }
