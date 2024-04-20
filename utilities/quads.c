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
    switch (type) {
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
    
    new->next = NULL;
    
    return new;
}

expr* create_and_emit_arith_expr(SymTable* symtable,scopeLists *lists,int scope,int yylineno,expr* arg1, expr* arg2,iopcode op){
    SymbolTableEntry *entry = newtemp(symtable, lists, scope, yylineno);
    entry->space = currscopespace();  // dialeksh 9 slide 49 sto site tou pratikakh
    entry->offset = currscopeoffset(); 
    incurrscopeoffset();
    expr* result = create_expr(arithexpr_e, entry, NULL, 0, NULL, '\0');
    emit(op, result, arg1, arg2, 0, yylineno);
    return result;
}

expr* create_and_emit_bool_expr(SymTable* symtable,scopeLists *lists,int scope,int yylineno,expr* arg1, expr* arg2,iopcode op){
    SymbolTableEntry *entry = newtemp(symtable, lists, scope, yylineno);
    entry->space = currscopespace();  // dialeksh 9 slide 49 sto site tou mpila
    entry->offset = currscopeoffset(); 
    incurrscopeoffset();
    expr* result = create_expr(boolexpr_e, entry, NULL, 0, NULL, '\0');
    
    emit(op, result, arg1, arg2, 0, yylineno);
    return result;
}

expr *lvalue_expr(SymbolTableEntry *sym) {
    assert(sym);
    expr *e = malloc(sizeof(struct expr));
    memset(e, 0, sizeof(struct expr));

    e->next = NULL;
    e->sym = sym;

    switch (sym->type) {
        case LOCALVAR:
        case FORMAL:
        case GLOBALVAR: 
            e->type = var_e; 
            break;
        
        case USERFUNC:
            e->type = programfunc_e;
            break;
        case LIBFUNC:
            e->type = libraryfunc_e;
            break;
    }

    return e;
}

void check_arith(expr* e, const char* context){
    if( e->type == constbool_e ||
        e->type == conststring_e ||
        e->type == nil_e || 
        e->type == newtable_e ||
        e->type == programfunc_e ||
        e->type == libraryfunc_e ||
        e->type == boolexpr_e){
            printf("Illegal expr used in %s!\n", context);
            exit(0);
        }
}

void print_quads(void){
    quad* tmp = quads;
    expr_t type ;
    int total_space = 20;
    int curr_space;
    char str[10];
    int len = 0 ;
    printf("quad#%-*sopcode%-*sresult%-*sarg1%-*sarg2%-*slabel%-*soffset%-*sspace\n", 14, "", 14, "", 14, "", 16, "", 15, "", 14, "", 14, "");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i< currQuad;i++){

        type = tmp->result->type;
        sprintf(str,"%d",i);
        printf("%d:%-*s",i,(int) (18-strlen(str)),"");
        memset(str,'\0',10);
        int opcodeLength = printOpcode(tmp->op);
        printf("%-*s", 20 - opcodeLength, "");
        if(tmp->result !=NULL){
            len = strlen(print_expr(tmp->result));
            if(tmp->result->type == conststring_e){
                len+=2;
            }
        }else{
            len = 0;
        }
        printf("%-*s", 20-len,"");
         if(tmp->arg1 !=NULL){
            len = strlen(print_expr(tmp->arg1));
            if(tmp->arg1->type == conststring_e){
                len+=2;
            }
        }else{
            len = 0;
        }
        printf("%-*s", 20-len,"");
        if(tmp->arg2 !=NULL){
           len = strlen(print_expr(tmp->arg2));
            if(tmp->arg2->type == conststring_e){
                len+=2;
            }
        }else{
            len = 0;
        }
        printf("%-*s", 20-len,"");
        printf("%d", tmp->label);
        sprintf(str,"%d",tmp->label);
        printf("%-*s",(int)(20-strlen(str)),"");
        memset(str,'\0',10);
        printf("\t\t%d", (tmp->result->sym != NULL) ? tmp->result->sym->offset : 0);
        printf("\t\t%d", (tmp->result->sym != NULL) ? tmp->result->sym->space : 0);    
        tmp++;
        printf("\n");
    }
}

char* print_expr(expr* e){
    char *str = malloc(20);
    switch(e->type){
        case var_e:
        case arithexpr_e:
        case boolexpr_e:
        printf("%s", e->sym->value.varVal->name);
        return e->sym->value.varVal->name;
        case constnum_e:
        printf("%.2f", e->numConst);
        sprintf(str,"%.2f",e->numConst);
        return str;
        case constbool_e:
        printf("%s", (e->boolConst == '1') ? "true" : "false");
        return (e->boolConst == '1') ? "true" : "false";
        case conststring_e:
        printf("'%s'", e->strConst);
        return e->strConst;
        case programfunc_e:
        case newtable_e:
        case tableitem_e:
        case assignexpr_e:
        printf("%s", e->sym->value.funcVal->name);
        return e->sym->value.funcVal->name;
    }
}


int printOpcode(int value) {
    switch(value) {
        case assign:
            printf("assign");
            return 6;
        case add:
            printf("add");
            return 3;
        case sub:
            printf("sub");
            return 3;
        case mul:
            printf("mul");
            return 3;
        case divide:
            printf("divide");
            return 6;
        case mod:
            printf("mod");
            return 3;
        case uminus:
            printf("uminus");
            return 6;
        case and:
            printf("and");
            return 3;
        case or:
            printf("or");
            return 2;
        case not:
            printf("not");
            return 3;
        case if_eq:
            printf("if_eq");
            return 5;
        case if_noteq:
            printf("if_noteq");
            return 8;
        case if_lesseq:
            printf("if_lesseq");
            return 8;
        case if_greatereq:
            printf("if_greatereq");
            return 12;
        case if_less:
            printf("if_less");
            return 6;
        case if_greater:
            printf("if_greater");
            return 9;
        case call:
            printf("call");
            return 4;
        case param:
            printf("param");
            return 5;
        case ret:
            printf("ret");
            return 3;
        case getretval:
            printf("getretval");
            return 9;
        case funcstart:
            printf("funcstart");
            return 9;
        case funcend:
            printf("funcend");
            return 7;
        case tablecreate:
            printf("tablecreate");
            return 11;
        case tablegetelem:
            printf("tablegetelem");
            return 12;
        case tablesetelem:
            printf("tablesetelem");
            return 12;
        default:
            printf("O baggelis sou xakare ton upologisth! Steiltoy to poyli sou gia na ston afhsei\n");
            return -1;
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
    SymbolTableEntry *node = NULL;

    if (sym == NULL) { 
        node = create_node(name, scope, line, (scope == 0) ? GLOBALVAR : LOCALVAR, ACTIVE);
        insert_symbol(symtable, node);
        insert_to_scope(lists, node, scope);
    } else {
        return sym;
    }

    return node;
}



// int main (){
//     expr* new = create_expr(constnum_e,NULL,NULL,1,NULL,0);
//     emit(if_eq,new,new,new,0,0);
    
//     // for (int i = 0; i < 10; i++) printf("%s\n", newtempname());
    
//     print_quads();
// }