#include "avm_dispatcher.hpp"

extern unsigned char executionFinished;
extern unsigned pc;
extern unsigned currLine;
extern unsigned codeSize;

// unsigned totalActuals = 0;

extern instruction* code;

arithmetic_func_t arithmeticFuncs[] {
    add_impl,
    sub_impl,
    mul_impl,
    div_impl,
    mod_impl
};

to_stringfunc_t tostringFuncs[] {
    number_tostring,
    string_tostring,
    bool_tostring,
    table_tostring,
    userfunc_tostring,
    libfunc_tostring, 
    nil_tostring,
    undef_tostring
};

execute_func_t executeFuncs[] = {
    execute_assign,
    execute_add,
    execute_sub,
    execute_mul,
    execute_div,
    execute_mod,
    execute_uminus,
    execute_and,
    execute_or,
    execute_not,
    execute_jeq,
    execute_jne,
    execute_jle,
    execute_jge,
    execute_jlt,
    execute_jgt,
    execute_call,
    execute_pusharg,
    execute_funcenter,
    execute_funcexit,
    execute_newtable,
    execute_tablegetelem,
    execute_tablesetelem,
    execute_nop
};

double add_impl(double x, double y) { return x + y; }
double sub_impl(double x, double y) { return x - y; }
double mul_impl(double x, double y) { return x * y; }
double div_impl(double x, double y) { return x / y; }
double mod_impl(double x, double y) { 
    return ((unsigned) x) % ((unsigned) y);
}


char *avm_tostring(avm_memcell *m) {
    assert(m->type >= 0 && m->type <= undef_m);
    return (*tostringFuncs[m->type])(m);
}

void execute_cycle(void){
    if(executionFinished)
        return;
    else 
    if(pc == AVM_ENDING_PC){
        executionFinished = 1;
        return;
    }
    else{
        assert(pc<AVM_ENDING_PC);
        instruction* inst = code + pc;
        assert(inst->opcode >= 0 && inst->opcode <= AVM_MAX_INSTRUCTIONS);
        if(inst->srcLine)
            currLine = inst->srcLine;
        unsigned oldPC = pc;
        (*executeFuncs[inst->opcode]) (inst);
        if(pc == oldPC)
            ++pc;
    }
}

void execute_assign(instruction* inst){
    avm_memcell* lv = avm_translate_operand(&(inst->result),(avm_memcell*) 0);
    avm_memcell *rv = avm_translate_operand(&(inst->arg1),&ax);
//  assert(lv && (&stack[N-1] >= lv && lv > &stack[top] || lv == &retval));
    assert(rv); 
    avm_assign(lv,rv);
}

// void execute_add(instruction* inst){

// }
// void execute_sub(instruction* inst){
    
// }
// void execute_div(instruction* inst){
    
// }
// void execute_mul(instruction* inst){
    
// }
// void execute_mod(instruction* inst){
    
// }
void execute_uminus(instruction* inst){
    
}
void execute_and(instruction* inst){
    
}
void execute_or(instruction* inst){
    
}
void execute_not(instruction* inst){
    
}
void execute_jeq(instruction* inst){
    assert(inst->result.type == label_a);
    avm_memcell *rv1 = avm_translate_operand(&(inst->arg1),&ax);
    avm_memcell *rv2 = avm_translate_operand(&(inst->arg2),&bx);
    unsigned char result = 0;
    if(rv1->type == undef_m || rv2->type == undef_m){
        printf("error ! undef involved in equality");
        exit(-1);
    }else if(rv1->type == bool_m || rv2->type == bool_m){
        result = (avm_tobool(rv1) == avm_tobool(rv2));
    }else if(rv1->type == nil_m || rv2->type == nil_m){
        result = rv1->type == nil_m && rv2->type == nil_m;
    }else if(rv1->type != rv2->type ){
            printf("error please be better\n");
            exit(-1);
    }else{
        /*Equality check with dispatching*/ //slide 31
    }
    if(!executionFinished && result)
        pc = inst->result.val;
}
void execute_jne(instruction* inst){
    assert(inst->result.type == label_a);
    avm_memcell *rv1 = avm_translate_operand(&(inst->arg1),&ax);
    avm_memcell *rv2 = avm_translate_operand(&(inst->arg2),&bx);
    unsigned char result = 0;
    if(rv1->type == undef_m || rv2->type == undef_m){
        printf("error ! undef involved in equality");
        exit(-1);
    }else if(rv1->type == bool_m || rv2->type == bool_m){
        result = (avm_tobool(rv1) != avm_tobool(rv2));
    }else if(rv1->type == nil_m || rv2->type == nil_m){
        result = rv1->type == nil_m && rv2->type == nil_m;
    }else if(rv1->type != rv2->type ){
            printf("error please be better\n");
            exit(-1);
    }else{
        /*Equality check with dispatching*/ //slide 31
    }
    if(!executionFinished && result)
        pc = inst->result.val;
    
}
void execute_jle(instruction* inst){
    assert(inst->result.type == label_a);
    avm_memcell *rv1 = avm_translate_operand(&(inst->arg1),&ax);
    avm_memcell *rv2 = avm_translate_operand(&(inst->arg2),&bx);
    unsigned char result = 0;
    if(rv1->type == undef_m || rv2->type == undef_m){
        printf("error ! undef involved in equality");
        exit(-1);
    }else if(rv1->type == bool_m || rv2->type == bool_m){
        result = (avm_tobool(rv1) <= avm_tobool(rv2));
    }else if(rv1->type == nil_m || rv2->type == nil_m){
        result = rv1->type == nil_m && rv2->type == nil_m;
    }else if(rv1->type != rv2->type ){
            printf("error please be better\n");
            exit(-1);
    }else{
        /*Equality check with dispatching*/ //slide 31
    }
    if(!executionFinished && result)
        pc = inst->result.val;
}
void execute_jge(instruction* inst){
    assert(inst->result.type == label_a);
    avm_memcell *rv1 = avm_translate_operand(&(inst->arg1),&ax);
    avm_memcell *rv2 = avm_translate_operand(&(inst->arg2),&bx);
    unsigned char result = 0;
    if(rv1->type == undef_m || rv2->type == undef_m){
        printf("error ! undef involved in equality");
        exit(-1);
    }else if(rv1->type == bool_m || rv2->type == bool_m){
        result = (avm_tobool(rv1) >= avm_tobool(rv2));
    }else if(rv1->type == nil_m || rv2->type == nil_m){
        result = rv1->type == nil_m && rv2->type == nil_m;
    }else if(rv1->type != rv2->type ){
            printf("error please be better\n");
            exit(-1);
    }else{
        /*Equality check with dispatching*/ //slide 31
    }
    if(!executionFinished && result)
        pc = inst->result.val;
}
void execute_jlt(instruction* inst){
    assert(inst->result.type == label_a);
    avm_memcell *rv1 = avm_translate_operand(&(inst->arg1),&ax);
    avm_memcell *rv2 = avm_translate_operand(&(inst->arg2),&bx);
    unsigned char result = 0;
    if(rv1->type == undef_m || rv2->type == undef_m){
        printf("error ! undef involved in equality");
        exit(-1);
    }else if(rv1->type == bool_m || rv2->type == bool_m){
        result = (avm_tobool(rv1) < avm_tobool(rv2));
    }else if(rv1->type == nil_m || rv2->type == nil_m){
        result = rv1->type == nil_m && rv2->type == nil_m;
    }else if(rv1->type != rv2->type ){
            printf("error please be better\n");
            exit(-1);
    }else{
        /*Equality check with dispatching*/ //slide 31
    }
    if(!executionFinished && result)
        pc = inst->result.val;
}
void execute_jgt(instruction* inst){
    assert(inst->result.type == label_a);
    avm_memcell *rv1 = avm_translate_operand(&(inst->arg1),&ax);
    avm_memcell *rv2 = avm_translate_operand(&(inst->arg2),&bx);
    unsigned char result = 0;
    if(rv1->type == undef_m || rv2->type == undef_m){
        printf("error ! undef involved in equality");
        exit(-1);
    }else if(rv1->type == bool_m || rv2->type == bool_m){
        result = (avm_tobool(rv1)  > avm_tobool(rv2));
    }else if(rv1->type == nil_m || rv2->type == nil_m){
        result = rv1->type == nil_m && rv2->type == nil_m;
    }else if(rv1->type != rv2->type ){
            printf("error please be better\n");
            exit(-1);
    }else{
        /*Equality check with dispatching*/ //slide 31
    }
    if(!executionFinished && result)
        pc = inst->result.val;
}


void execute_call(instruction* inst){
    avm_memcell* func = avm_translate_operand(&(inst->result),&ax);
    assert(func);
    switch(func->type){
        case userfunc_m: {
            avm_callsaveenvironment();
            pc = func->data.funcVal;
            assert(pc<AVM_ENDING_PC);
            assert(code[pc].opcode == funcenter_v);
            break;
        }
        case string_m: avm_calllibfunc(func->data.strVal); break;
        case libfunc_m: avm_calllibfunc(func->data.libfuncVal); break;
        case table_m: avm_call_functor(func->data.tableVal); break;

        default:{
            char* s = avm_tostring(func);
            cout << "error" << endl;  // write runtime error
            executionFinished = 1;
        }
    }
}
void execute_pusharg(instruction* inst){
    avm_memcell *arg = avm_translate_operand(&inst->arg1, &ax);
    assert (arg);
    avm_assign(&stack[top],arg);
    ++totalActuals;
    avm_dec_top();
}

void execute_funcenter(instruction* inst){
    avm_memcell* func = avm_translate_operand(&inst->result,&ax);
    assert(func);
    assert(pc == func->data.funcVal);
    totalActuals = 0; 
    userfunc* funcInfo = avm_getfuncinfo(pc);
    topsp = top;
    top = top - funcInfo->localSize;
}
void execute_funcexit(instruction* inst){
    unsigned oldTop = top;
    top = avm_get_envvalue(topsp +  AVM_SAVEDTOP_OFFSET);
    pc = avm_get_envvalue(topsp+AVM_SAVEDPC_OFFSET);
    topsp = avm_get_envvalue(topsp+AVM_SAVEDTOPSP_OFFSET);
    
    while(++oldTop<=top) // intentionally ignoring first
        avm_memcellclear(&stack[oldTop]);
}
void execute_newtable(instruction* inst){
    avm_memcell *lv = avm_translate_operand(&(inst->result),0);
    assert(lv && (&stack[AVM_STACKSIZE] >= lv && lv >&stack[top] || lv == &retval));
    avm_memcellclear(lv);
    lv->type = table_m;
    lv->data.tableVal = avm_tablenew();
    avm_tableincrefcounter(lv->data.tableVal);
}
void execute_tablegetelem(instruction* inst){
    avm_memcell *lv = avm_translate_operand(&inst->result, (avm_memcell *) 0);
    avm_memcell *t = avm_translate_operand(&inst->arg1, (avm_memcell *) 0);
    avm_memcell *i = avm_translate_operand(&inst->arg2, (avm_memcell *) 0);

    assert(lv && &stack[AVM_STACKSIZE - 1] >= lv && lv > &stack[top] || lv == &retval);
    assert (t && &stack[AVM_STACKSIZE - 1] >= t && t> &stack[top]);
    assert(i);

    avm_memcellclear(lv);
    lv->type = nill_m;

    if (t->type != table_m){
        cout << "illeagal use of type" << endl;
    }else {
        avm_memcell *content = avm_tablegetelem(t->data.tableVal ,i);
        if (content) avm_assign(lv,content);
        else {
            char *ts = avm_tostring(t);
            char *is = avm_tostring(i);
            cout << "``notfound"
        }
    }
}
void execute_tablesetelem(instruction* inst){
    
}
void execute_nop(instruction* inst){
    
}


void avm_push_table_arg(avm_table* t){
    stack[top].type = table_m;
    avm_tableincrefcounter(stack[top].data.tableVal = t);
    ++totalActuals;
    avm_dec_top();
}

void avm_assign(avm_memcell* lv, avm_memcell* rv){
    if(lv == rv) //same memcells 
        return;
    
    if(lv->type == table_m && rv->type == table_m && lv->data.tableVal == rv->data.tableVal) //same tables
        return;

    if(rv->type == undef_m)
        cout << "Warning" << endl;   //avm_warning("assigning from undefined content!!");
    
    avm_memcellclear(lv);

    memcpy(lv,rv,sizeof(avm_memcell));

    if(lv->type == string_m)
        lv->data.strVal = strdup(rv->data.strVal);
    else if(lv->type == table_m)
        avm_tableincrefcounter(lv->data.tableVal);    
}

void avm_call_functor(avm_table *t){
    cx.type = string_m;
    // string s = "()";
    // cx.data.strVal = (char *)s.c_str();
    cx.data.strVal = (char *) ("()");

    avm_memcell *f = avm_tablegetelem(t,&cx);

    if(!f)
        cout << "in calling table no ' ()' element found" << endl;
    else 
    if (f->type == table_m)
        avm_call_functor(f->data.tableVal);
    else 
    if (f->type == userfunc_m) {
        avm_push_table_arg(t);
        avm_callsaveenvironment();
        pc = f->data.funcVal;
        assert(pc<AVM_ENDING_PC && code[pc].opcode == funcenter_v);
    } else {
        cout << "Error" << endl;
        exit(0);
    }
}

void avm_dec_top (void) {
    if (!top) { 
        cout << "stack overflow" << endl; 
        executionFinished = 1;
    }
    else
    --top;
}
void avm_push_envvalue (unsigned val) {
    stack[top].type = number_m;
    stack[top].data.numVal = val;
    avm_dec_top();
}
void avm_callsaveenvironment (void) {
    avm_push_envvalue (totalActuals);
    assert(code[pc].opcode == call_v);
    avm_push_envvalue (pc+1);
    avm_push_envvalue (top + totalActuals + 2);
    avm_push_envvalue (topsp);
}


userfunc* avm_getfuncinfo(unsigned address){
    return nullptr;
}

unsigned avm_get_envvalue(unsigned i){
    assert(stack[i].type == number_m);
    unsigned val = (unsigned) stack[i].data.numVal;
    assert(stack[i].data.numVal == ((double) val));
    return val;
}

void avm_calllibfunc (char * id){
    library_func_t f = avm_getlibraryfunc(id);

    if (!f){
        cout << "unsupported lib func " << id << " called" << endl;
        exit(0);
    } else {
        avm_callsaveenvironment();
        topsp = top;
        totalActuals = 0;
        (*f)();
        if (!executionFinished){
            execute_funcexit((instruction *)0);
        }
    }

}

unsigned avm_totalactuals(void){
    return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}

avm_memcell *avm_getactual(unsigned i){
    assert (i < avm_totalactuals());
    return &stack[topsp + AVM_STACKENV_SIZE + 1 + i]; 
}

void libfunc_print ( void){
    unsigned n = avm_totalactuals();
    for (unsigned i = 0; i<n; ++i){
        char * s = avm_tostring(avm_getactual(i)); //tostring????
        puts(s);
        free(s);
    }
}

void avm_registerlibfunc(char * id, library_func_t addr){
    
}


void execute_arithmetic(instruction *inst) {
    avm_memcell *lv = avm_translate_operand(&inst->result, (avm_memcell *) 0);
    avm_memcell *rv1 = avm_translate_operand(&inst->arg1, &ax);
    avm_memcell *rv2 = avm_translate_operand(&inst->arg2, &bx);

    assert(lv && (&stack[AVM_STACKSIZE - 1] >= lv && lv > &stack[top] || lv == &retval)); // GOTO
    assert(rv1 && rv2);

    if (rv1->type != number_m || rv2->type != number_m) {
        // avm_error()
        cout << "not a number in arithmetic!" << endl;
        executionFinished = 1;
    } else {
        arithmetic_func_t op = arithmeticFuncs[inst->opcode - add_v];
        avm_memcellclear(lv);
        lv->type = number_m;
        lv->data.numVal = (*op)(rv1->data.numVal, rv2->data.numVal);
    }

}

char *number_tostring (avm_memcell* m) { return (char *)""; }
char *string_tostring (avm_memcell* m ) { return (char *)""; }
char *bool_tostring (avm_memcell* m) { return (char *)""; }
char *table_tostring (avm_memcell*m) { return (char *)""; }
char *userfunc_tostring (avm_memcell*m) { return (char *)""; }
char *libfunc_tostring (avm_memcell*m) { return (char *)""; }
char *nil_tostring (avm_memcell*m) { return (char *)""; }
char *undef_tostring (avm_memcell*m) { return (char *)""; }

unsigned char number_tobool(avm_memcell *m){return m->data.numVal !=0;}
unsigned char string_tobool(avm_memcell *m){return m->data.strVal[0]!=0;}
unsigned char bool_tobool(avm_memcell *m){return m->data.boolVal;}
unsigned char table_tobool(avm_memcell *m){return 1;}
unsigned char userfunc_tobool(avm_memcell *m){return 1;}
unsigned char libfunc_tobool(avm_memcell *m){return 1;}
unsigned char nil_tobool(avm_memcell *m){return 0;}
unsigned char undef_tobool(avm_memcell *m) {return 0;}

typedef unsigned char (*tobool_func_t)(avm_memcell*);

tobool_func_t toboolFuncs[] = {
    number_tobool,
    string_tobool,
    bool_tobool,
    table_tobool,
    userfunc_tobool,
    libfunc_tobool,
    nil_tobool,
    undef_tobool
};

unsigned char avm_tobool(avm_memcell *m){
    assert(m->type >=0 && m->type <undef_m);
    return (*toboolFuncs[m->type])(m);
}


library_func_t avm_getlibraryfunc(char *id) {return (library_func_t) 0;}

