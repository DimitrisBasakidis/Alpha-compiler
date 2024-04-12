#include "scope_stack.h"


scope_stack *create_stack(){
    scope_stack *tmp = malloc(sizeof(scope_stack));
    return tmp;
}

void push(scope_stack *top, int a){
    scopestack_t *tmp = malloc(sizeof(scopestack_t));
    tmp->x = a;
    tmp->prev = NULL;
    if (top->s == NULL){
        top->s = tmp;
        return;
    }
    tmp->prev=top->s;
    top->s = tmp;

}

scopestack_t *pop(scope_stack *top){
    scopestack_t *tmp = top->s;
    scopestack_t *newtop = top->s->prev;
    top->s =newtop;

    return tmp;
}

int main(){
   scope_stack *tmp = create_stack();
    push(tmp,1);
  
    push(tmp,2);
   
    push(tmp,3);
    

    printf("top %d\n", pop(tmp)->x);
    printf("top %d\n", pop(tmp)->x);
    printf("top %d\n", pop(tmp)->x);



    // stack = push(stack,2);
    // stack = push(stack,3);
    // stack = pop(stack);
    // stack = pop(stack);

    //print(stack);
}
