#include "quads.h"

void expand (void){
    assert (total == currQuad);
    quad* p = (quad*) malloc(NEW_SIZE);

    if(quads){
        memcpy(p, quads,CURR_SIZE);
        free(quads);
    }
    quads = p;
    total += EXPAND_SIZE;
}

void emit (
    iopcode op,
    expr* result,
    expr* arg1,
    expr* arg2,
   unsigned label,
   unsigned line)
   {
    if(currQuad == total) expand();

    quad* p = quads + currQuad++;
    p->op = op;
    p->arg1 = arg1;
    p->arg2 = arg2;
    p->result = result;
    p->label = label;
    p->line = line;
}

expr* create_expr(expr_t type, SymbolTableEntry* sym, expr* index, double numConst,char* strConst,unsigned char boolConst){
    expr* new = (expr*) malloc(sizeof(expr));
    new->type = type;
    new->sym = sym;
    if(index != NULL){
        new->index = index;
    }
    switch(type){
        case constbool_e:
        new->boolConst = boolConst;
        break;
        case conststring_e:
        new->strConst = malloc(strlen(strConst) + 1);
        strcpy(new->strConst,strConst);
        break;
        case constnum_e:
        new->numConst = numConst;
        break;
    }
    return new;
}

void print_quads(void){
    quad* tmp = quads;
    printf("quad#\topcode\t\tresult\t\targ1\t\targ2\t\tlabel\n");
    printf("------------------------------------------------------------------------------\n");
    for(int i = 0; i< currQuad;i++){
        printf("%d:\t",i+1);
        printOpcode(tmp->op);
        printf("\t\t");
        print_expr(tmp->result);
        print_expr(tmp->arg1);
        print_expr(tmp->arg2);
        printf("%d", tmp->label);
        tmp = tmp + sizeof(quad);
        printf("\n");
    }

}

void print_expr(expr* e){
    switch(e->type){
        case constnum_e:
        printf("%.3f\t\t", e->numConst);
        break;
        case constbool_e:
        printf("%d\t\t",e->boolConst);
        break;
        case conststring_e:
        printf("%s\t\t",e->strConst);
    }
}


void printOpcode(int value) {
    switch(value) {
        case assign:
            printf("assign");
            break;
        case add:
            printf("add");
            break;
        case sub:
            printf("sub");
            break;
        case mul:
            printf("mul");
            break;
        case divide:
            printf("divide");
            break;
        case mod:
            printf("mod");
            break;
        case uminus:
            printf("uminus");
            break;
        case and:
            printf("and");
            break;
        case or:
            printf("or");
            break;
        case not:
            printf("not");
            break;
        case if_eq:
            printf("if_eq");
            break;
        case if_noteq:
            printf("if_noteq");
            break;
        case if_lesseq:
            printf("if_lesseq");
            break;
        case if_greatereq:
            printf("if_greatereq");
            break;
        case if_less:
            printf("if_less");
            break;
        case if_greater:
            printf("if_greater");
            break;
        case call:
            printf("call");
            break;
        case param:
            printf("param");
            break;
        case ret:
            printf("ret");
            break;
        case getretval:
            printf("getretval");
            break;
        case funcstart:
            printf("funcstart");
            break;
        case funcend:
            printf("funcend");
            break;
        case tablecreate:
            printf("tablecreate");
            break;
        case tablegetelem:
            printf("tablegetelem");
            break;
        case tablesetelem:
            printf("tablesetelem");
            break;
        default:
            printf("O baggelis sou xakare ton upologisth! Steiltoy to poyli sou gia na ston afhsei\n");
            break;
    }
}

char *newtempname(void) {
    unsigned int count = 0, n = temp_count;
    char *temp = (char *)malloc(sizeof(char) * temp_count + 2);

    while (n != 0) { 
        n /= 10; 
        count++;
    }

    sprintf(temp , "_t%u", (unsigned int) temp_count++);
    return temp;
}

void resettemp(void) {
    temp_count = 0;
}

SymbolTableEntry* newtemp(SymTable *symtable, scopeLists *lists, int scope, int line) {
    char *name = newtempname();
    SymbolTableEntry *sym = lookup(symtable, lists, name, (scope == 0) ? GLOBALVAR : LOCALVAR, scope, SCOPE);

    if (sym == NULL) { // ama h synartish einai null tote shmainei oti exoyme kanei insert alliws epistrefei to hdh uparxon
        insert_symbol(symtable, create_node(name, scope, line, (scope == 0) ? GLOBALVAR : LOCALVAR, ACTIVE));
    } else {
        return sym;
    }

    return NULL;
}


int main (){
    expr* new = create_expr(constnum_e,NULL,NULL,1,NULL,0);
    emit(if_eq,new,new,new,0,0);
    
    // for (int i = 0; i < 10; i++) printf("%s\n", newtempname());
    
    print_quads();
}