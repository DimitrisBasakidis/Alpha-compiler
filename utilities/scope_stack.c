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




// int main(){
//     index_list* list = create_list();
//     insert(list,create_node("i1","v1"));
//     insert(list,create_node("i2","v2"));
//     insert(list,create_node("i3","v3"));
//     insert(list,create_node("i4","v4"));
//     print_indexedlist(list);
// }
