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
    // entry->space = currscopespace();  // dialeksh 9 slide 49 sto site tou pratikakh
    // entry->offset = currscopeoffset(); 
    // incurrscopeoffset();
    expr* result = create_expr(arithexpr_e, entry, NULL, 0, NULL, '\0');
    emit(op, result, arg1, arg2, 0, yylineno);
    return result;
}

expr* create_and_emit_bool_expr(SymTable* symtable,scopeLists *lists,int scope,int yylineno,expr* arg1, expr* arg2,iopcode op){
    SymbolTableEntry *entry = newtemp(symtable, lists, scope, yylineno);
    // entry->space = currscopespace();  // dialeksh 9 slide 49 sto site tou mpila
    // entry->offset = currscopeoffset(); 
    // incurrscopeoffset();
    expr* result = create_expr(boolexpr_e, entry, NULL, 0, NULL, '\0');
    
    emit(op,NULL, arg1, arg2, nextquadlabel() + 3, yylineno);
    emit(assign,result,create_expr(constbool_e,NULL,NULL,0.0f,"",'0'),NULL,0,yylineno);
    emit(jump,NULL,NULL,NULL,nextquadlabel()+2,yylineno);
    emit(assign,result,create_expr(constbool_e,NULL,NULL,0.0f,"",'1'),NULL,0,yylineno);
    return result;

}

void check_expr(expr* a , expr* b,void (*print_errors)(const char *, char *, const char *)){
   if(a->type == programfunc_e || a->type == libraryfunc_e || a->type == boolexpr_e || a->type == newtable_e || a->type == constbool_e
        || a->type == conststring_e || a->type == nil_e){
            print_errors("invalid arithmetic operation operand",a->sym->value.varVal->name,"grammar");
            exit(0);
    }

    if(b->type == programfunc_e || b->type == libraryfunc_e || b->type == boolexpr_e || b->type == newtable_e || b->type == constbool_e
        || b->type == conststring_e || b->type == nil_e){
            print_errors("invalid arithmetic operation operand", b->sym->value.varVal->name,"grammar");
            exit(0);
    } 
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
    if( e->type == constbool_e   ||
        e->type == conststring_e ||
        e->type == nil_e         || 
        e->type == newtable_e    ||
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
    tmp++;
    printf("quad#%-*sopcode%-*sresult%-*sarg1%-*sarg2%-*slabel%-*soffset%-*sspace\n", 14, "", 14, "", 14, "", 16, "", 15, "", 14, "", 14, "");
    printf("------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for(int i = 1; i< currQuad;i++){
        sprintf(str,"%d",i);
        printf("%d:%-*s",i,(int) (18-strlen(str)),"");
        memset(str,'\0',10);
        int opcodeLength = printOpcode(tmp->op);
        printf("%-*s", 20 - opcodeLength, "");
        
        if(tmp->result != NULL){
          //  printf("here pointer::%d\n",tmp->result );

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
        // printf("\t\t%d", (tmp->result->sym != NULL) ? tmp->result->sym->offset : 0);
        // printf("\t\t%d", (tmp->result->sym != NULL) ? tmp->result->sym->space : 0);    
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
        case libraryfunc_e:
        case newtable_e:
        case tableitem_e:
        case assignexpr_e:
        printf("%s", e->sym->value.funcVal->name);
        return e->sym->value.funcVal->name;
        default:
        return "";
    }
}


int printOpcode(int value) {
    switch(value) {
        case assign:
            printf("ASSIGN");
            return 6;
        case add:
            printf("ADD");
            return 3;
        case sub:
            printf("SUB");
            return 3;
        case mul:
            printf("MUL");
            return 3;
        case divide:
            printf("DIVIDE");
            return 6;
        case mod:
            printf("MOD");
            return 3;
        case uminus:
            printf("UMINUS");
            return 6;
        case and:
            printf("AND");
            return 3;
        case or:
            printf("OR");
            return 2;
        case not:
            printf("NOT");
            return 3;
        case if_eq:
            printf("IF_EQ");
            return 5;
        case if_noteq:
            printf("IF_NOTEQ");
            return 8;
        case if_lesseq:
            printf("if_lesseq");
            return 8;
        case if_greatereq:
            printf("IF_GREATEREQ");
            return 12;
        case if_less:
            printf("IF_LESS");
            return 7;
        case if_greater:
            printf("IF_GREATER");
            return 10;
        case call:
            printf("CALL");
            return 4;
        case param:
            printf("PARAM");
            return 5;
        case ret:
            printf("RET");
            return 3;
        case getretval:
            printf("GETRETVAL");
            return 9;
        case funcstart:
            printf("FUNCSTART");
            return 9;
        case funcend:
            printf("FUNCEND");
            return 7;
        case tablecreate:
            printf("TABLECREATE");
            return 11;
        case tablegetelem:
            printf("TABLEGETELEM");
            return 12;
        case tablesetelem:
            printf("TABLESETELEM");
            return 12;
        case jump:
            printf("JUMP");
            return 4; 
        default:
            printf("O baggelis sou xakare ton upologisth! Steiltoy to istioploiko sou gia na ston afhsei\n");
            return 0;
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
        node->space = currscopespace();  // dialeksh 9 slide 49 sto site tou mpila
        node->offset = currscopeoffset(); 
        incurrscopeoffset();
    } else {
        return sym;
    }

    return node;
}

stmt_t *make_stmt (struct stmt_t* s){
    s = malloc(sizeof(struct stmt_t));
    s->breakList = 0;
    s->contList = 0; 

    return s;
}

int newlist (int i) { 
    quads[i].label = 0;
    return i; 
}

int mergelist (int l1, int l2) {
    if (!l1)
        return l2;
    else
    if (!l2)
        return l1;
    else {
        int i = l1;
        while (quads[i].label){
            i = quads[i].label;
        }    
        quads[i].label = l2;
        return l1;
    }
}


void patchlist (int list, int label) {
    while (list) {
        int next = quads[list].label;
        quads[list].label = label;
        list = next;
    }
}