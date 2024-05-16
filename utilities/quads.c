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
    expr* result = create_expr(arithexpr_e, entry, NULL, 0, NULL, '\0');
    emit(op, result, arg1, arg2, 0, yylineno);
    return result;
}

expr* create_and_emit_bool_expr(SymTable* symtable,scopeLists *lists,int scope,int yylineno,expr* arg1, expr* arg2,iopcode op){
    SymbolTableEntry *entry = newtemp(symtable, lists, scope, yylineno);
    expr* result = create_expr(boolexpr_e, entry, NULL, 0, NULL, '\0');
    
    emit(op,NULL, arg1, arg2, nextquadlabel() + 3, yylineno);
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

void print_quads(FILE *ptr) {
    quad* tmp = quads;
    expr_t type ;
    int total_space = 20;
    int curr_space;
    char str[10];
    int len = 0 ;
    tmp++;
    fprintf(ptr, "quad#%-*sopcode%-*sresult%-*sarg1%-*sarg2%-*slabel%-*soffset%-*sspace\n", 14, "", 14, "", 14, "", 16, "", 15, "", 14, "", 14, "");
    fprintf(ptr, "------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for(int i = 1; i< currQuad;i++){
        sprintf(str,"%d",i);
        fprintf(ptr, "%d:%-*s",i,(int) (18-strlen(str)),"");
        memset(str,'\0',10);
        int opcodeLength = print_opcode(tmp->op, ptr);
        fprintf(ptr, "%-*s", 20 - opcodeLength, "");
        
        if(tmp->result != NULL){
            len = strlen(print_expr(tmp->result, ptr));
            if(tmp->result->type == conststring_e){
                len+=2;
            }
        }else{
            len = 0;
        }
        fprintf(ptr, "%-*s", 20-len,"");
         if(tmp->arg1 !=NULL){

            len = strlen(print_expr(tmp->arg1, ptr));
            if(tmp->arg1->type == conststring_e){
                len+=2;
            }
        }else{
            len = 0;
        }
        fprintf(ptr, "%-*s", 20-len,"");
        if(tmp->arg2 !=NULL){
          len = strlen(print_expr(tmp->arg2, ptr));
            if(tmp->arg2->type == conststring_e){
                len+=2;
            }
        }else{
            len = 0;
        }
        fprintf(ptr, "%-*s", 20-len,"");

        fprintf(ptr, "%d", tmp->label);
        sprintf(str,"%d",tmp->label);
        fprintf(ptr, "%-*s",(int)(20-strlen(str)),"");
        memset(str,'\0',10);
        // printf("\t\t%d", (tmp->result->sym != NULL) ? tmp->result->sym->offset : 0);
        // printf("\t\t%d", (tmp->result->sym != NULL) ? tmp->result->sym->space : 0);    
        tmp++;
        fprintf(ptr, "\n");
    }
}

char* print_expr(expr* e, FILE *ptr){
    char *str = malloc(20);

    switch(e->type){
        case var_e:
        case arithexpr_e:
        case boolexpr_e:
            if(e->sym!=NULL){
                fprintf(ptr, "%s", e->sym->value.varVal->name);
                return e->sym->value.varVal->name;
            }else{
                return "";
            }    
        case constnum_e:
            fprintf(ptr, "%.2f", e->numConst);
            sprintf(str,"%.2f",e->numConst);
            return str;
        case constbool_e:
            fprintf(ptr, "%s", (e->boolConst == '1') ? "true" : "false");
        return (e->boolConst == '1') ? "true" : "false";
        case conststring_e:
            fprintf(ptr, "'%s'", e->strConst);
        return e->strConst;
        case programfunc_e:
        case libraryfunc_e:
        case newtable_e:
        case tableitem_e:
        case assignexpr_e:
            fprintf(ptr, "%s", e->sym->value.funcVal->name);
        return e->sym->value.funcVal->name;
        default:
        return "";
    }
}



int print_opcode(int value, FILE *ptr) {
    switch(value) {
        case assign:
            fprintf(ptr, "ASSIGN");
            return 6;
        case add:
            fprintf(ptr, "ADD");
            return 3;
        case sub:
            fprintf(ptr, "SUB");
            return 3;
        case mul:
            fprintf(ptr, "MUL");
            return 3;
        case divide:
            fprintf(ptr, "DIVIDE");
            return 6;
        case mod:
            fprintf(ptr, "MOD");
            return 3;
        case uminus:
            fprintf(ptr, "UMINUS");
            return 6;
        case and:
            fprintf(ptr, "AND");
            return 3;
        case or:
            fprintf(ptr, "OR");
            return 2;
        case not:
            fprintf(ptr, "NOT");
            return 3;
        case if_eq:
            fprintf(ptr, "IF_EQ");
            return 5;
        case if_noteq:
            fprintf(ptr, "IF_NOTEQ");
            return 8;
        case if_lesseq:
            fprintf(ptr, "if_lesseq");
            return 9;
        case if_greatereq:
            fprintf(ptr, "IF_GREATEREQ");
            return 12;
        case if_less:
            fprintf(ptr, "IF_LESS");
            return 7;
        case if_greater:
            fprintf(ptr, "IF_GREATER");
            return 10;
        case call:
            fprintf(ptr, "CALL");
            return 4;
        case param:
            fprintf(ptr, "PARAM");
            return 5;
        case ret:
            fprintf(ptr, "RET");
            return 3;
        case getretval:
            fprintf(ptr, "GETRETVAL");
            return 9;
        case funcstart:
            fprintf(ptr, "FUNCSTART");
            return 9;
        case funcend:
            fprintf(ptr, "FUNCEND");
            return 7;
        case tablecreate:
            fprintf(ptr, "TABLECREATE");
            return 11;
        case tablegetelem:
            fprintf(ptr, "TABLEGETELEM");
            return 12;
        case tablesetelem:
            fprintf(ptr, "TABLESETELEM");
            return 12;
        case jump:
            fprintf(ptr, "JUMP");
            return 4; 
        default:
            fprintf(ptr, "O baggelis sou xakare ton upologisth!\n");
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

expr* manage_bool_expr(expr* boolean,SymTable *symtable, scopeLists *lists, int scope, int yylineno){
    if(boolean->type ==  boolexpr_e){
        SymbolTableEntry *tmp = newtemp(symtable,lists,scope,yylineno);
        expr *e = create_expr(boolexpr_e,tmp,NULL,0.0,"",'a');
        patchlist(boolean->trueList, nextquadlabel());
        emit(assign,e,create_expr(constbool_e,NULL,NULL,0.0,"",'1'),NULL,0,yylineno);
        emit(jump,NULL,NULL,NULL,nextquadlabel()+2,yylineno);
        patchlist(boolean->falseList, nextquadlabel());
        emit(assign,e,create_expr(constbool_e,NULL,NULL,0.0,"",'0'),NULL,0,yylineno);
        return e;
    }
    return boolean;
}

expr* do_bool(expr* e,int yylineno){
    if(e->type != boolexpr_e){
        expr* new = create_expr(boolexpr_e,e->sym,NULL,0.0f,"",'9');
        new->trueList = newlist(nextquadlabel());
        new->falseList = newlist(nextquadlabel() + 1);
        emit(if_eq,new,create_expr(constbool_e, NULL, NULL, 0,"",'1'),NULL,0,yylineno);
        emit(jump,NULL,NULL,NULL,0,yylineno);
        return new;
   }
   return e;
}