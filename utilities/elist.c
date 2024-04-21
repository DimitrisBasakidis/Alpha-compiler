#include "elist.h"

expr *insert_node(expr *head, expr *expression) {
    if (head == NULL) { return expression;}

    expr *ptr = head;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = expression;

    return head;
}

expr *make_call(expr *lv, expr *reversed_elist, unsigned line,SymTable *symtable,scopeLists *lists, unsigned int scope){
    expr* func = emit_iftableitem(lv,symtable,lists,scope,line);
    while (reversed_elist) {
        emit(param, reversed_elist, NULL, NULL, 0, line);
        reversed_elist = reversed_elist->next;
    }
    emit(call, func, NULL, NULL, 0, line);
    expr *result = create_expr(var_e, newtemp(symtable,lists,scope,line), NULL, 0.0f, NULL, '\0');
    emit(getretval, result, NULL, NULL, 0U, line);
    return result;
}

expr *newexpr_constnum(double i) {
    return  create_expr(constnum_e, NULL, NULL, i, NULL, '\0');
}

void print_li2st(expr* head){
    expr* head1 = head;
    printf("list :: ");
    while(head1!=NULL){
        print_expr(head1);
        printf(", ");
        head1 = head1->next;
    }
    printf(" end of list\n");
}

expr *get_last(expr* head){
    expr* tmp = head;
    if(head == NULL){
        return NULL;
    }
    while(tmp->next != NULL){
        tmp = tmp->next;
        
    }
    printf("START OF LIST:");
    print_li2st(head);
    printf("END OF LIST:");
    return tmp;
}

expr* reverse_elist(expr* head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    expr* reversed_tail = reverse_elist(head->next);

    head->next->next = head;
    head->next = NULL;
 
    return reversed_tail;
}


expr *emit_iftableitem(expr *e,SymTable *symtable, scopeLists *lists, unsigned int scope, unsigned int line){
    if (e->type != tableitem_e) {
        return e;
    } else {
        expr *result = create_expr(var_e, NULL, NULL, 0.0f, NULL, '\0');
        result->sym = newtemp(symtable, lists, scope, line);
        emit(tablegetelem, result, e, e->index, 0, line);
        return result;
    }
}   

expr* member_item(expr* lvalue, char* name,SymTable *symtable, scopeLists *lists,unsigned int scope, unsigned int line){
 
    lvalue = emit_iftableitem(lvalue,symtable,lists,scope,line);
    expr* item = create_expr(tableitem_e,lvalue->sym,NULL,0.0f,"",'\0');
    item->index = create_expr(conststring_e,NULL,NULL,0.0f,name,'\0');
    return item;
}