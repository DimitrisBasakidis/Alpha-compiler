#include "func_stack.h"


funcstack *create_func_stack(void){
    funcstack *tmp = malloc(sizeof(funcstack));

    return tmp;
}

void push_func(funcstack *top, userfunc *f){

    if (top == NULL) return;

    node *tmp = malloc(sizeof(node));
    tmp->s = f;
    tmp->prev = NULL;

    if (top->func == NULL){
        top->func = tmp;
        return;
    }
    tmp->prev = top->func;
    top->func = tmp;
}

node *pop_func(funcstack *top){
    if (top == NULL) return NULL;

    node *tmp = top->func;
    top->func = top->func->prev;
    return tmp;
}



node *peek_func(funcstack *stack) {
    if (stack == NULL) return NULL;

    return stack->func;    
}




// int main() {
//     funcstack *f = create_func_stack();

//     userfunc *node1 = malloc(sizeof(userfunc));
//     node1->id = "1";
//     node1->address = 5;
//     node1->localSize = 4;
//     userfunc *node2 = malloc(sizeof(userfunc));
//     node2->id = "2";
//     node2->address = 12;
//     node2->localSize = 213;
//     userfunc *node3 = malloc(sizeof(userfunc));
//     node3->id = "1123";
//     node3->address = 5123123;
//     node3->localSize = 4124;

//     push_func(f, node1);
//     push_func(f, node2);
//     push_func(f, node3);

//     printf("top = %s\n", pop_func(f)->s->id);
//     printf("top = %s\n", pop_func(f)->s->id);
//     printf("top = %s\n", pop_func(f)->s->id);

// }