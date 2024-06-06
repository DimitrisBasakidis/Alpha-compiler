#include "avm_dispatcher.hpp"

extern unsigned char executionFinished;
extern unsigned pc;
extern unsigned currLine;
extern unsigned codeSize;


map<string, library_func_t> lib_map;


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
    execute_jump,
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


string avm_tostring(avm_memcell *m) {
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
    
    assert(lv && ((&stack[AVM_STACKSIZE-1] >= lv && lv > &stack[top] )|| lv == &retval));
    // cout << "PROGRAM COUNTER = " << pc << endl; 
    fflush(stdout);
    // cout << "rv = " << rv << " lv = " << lv << endl;
    assert(rv || lv  == &retval); 
    
    if(rv) avm_assign(lv,rv);
}

void execute_uminus(instruction* inst){
    
}
void execute_and(instruction* inst){
    
}
void execute_or(instruction* inst){
    
}
void execute_not(instruction* inst){
    
}

void execute_jump(instruction* inst){
    assert(inst->result.type == label_a);
    pc = inst->result.val;
}

void execute_jeq(instruction* inst){
  
    assert(inst->result.type == label_a);
   // cout << "arg1 " << inst->arg1.type << " arg2 " << inst->arg2.type << " result " << inst->result.type << endl;
    avm_memcell *rv1 = avm_translate_operand(&(inst->arg1),&ax);
    avm_memcell *rv2 = avm_translate_operand(&(inst->arg2),&bx);
  // cout << "rv1 type ::  " << rv1->type << " rv2 type " << rv2->type << endl;
    unsigned char result = 0;
    if(rv1->type == undef_m || rv2->type == undef_m){
        printf("error ! undef involved in equality");
        exit(-1);
    }else if(rv1->type == bool_m || rv2->type == bool_m){      
     //   printf("AVM TO BOOL RV1 :: %d\n ", avm_tobool(rv1));
       // printf("AVM TO BOOL RV2 :: %d\n ", avm_tobool(rv2));
        result = (avm_tobool(rv1) == avm_tobool(rv2));
    }else if(rv1->type == nil_m || rv2->type == nil_m){
        
        result = rv1->type == nil_m && rv2->type == nil_m;
    }else if(rv1->type != rv2->type ){
            printf("error please be better\n");
            exit(-1);
    }else{
        if(rv1->type == number_m && rv2->type == number_m){
            if(rv1->data.numVal ==  rv2->data.numVal){
                result = 1;
            }
        } 
        if(rv1->type == table_m && rv2->type == table_m){
            if(rv1->data.tableVal ==  rv2->data.tableVal){
                result = 1;
            }
        } 
        if(rv1->type == string_m && rv2->type == string_m){
            if(strcmp(rv1->data.strVal,rv2->data.strVal) == 0 ){
                result = 1;
            }
        }


    }
    if(!executionFinished && result)
        pc = inst->result.val;
   // printf("mphka, to result einai %d , pc :: %d\n", result, pc);    
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
         if(rv1->type == number_m && rv2->type == number_m){
            if(rv1->data.numVal !=  rv2->data.numVal){
                result = 1;
            }
        }
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
        result = (avm_tobool(rv1) < avm_tobool(rv2));
    }else if(rv1->type == nil_m || rv2->type == nil_m){
        result = rv1->type == nil_m && rv2->type == nil_m;
    }else if(rv1->type != rv2->type ){
            printf("error please be better\n");
            exit(-1);
    }else{
        if(rv1->type == number_m && rv2->type == number_m){
            if(rv1->data.numVal <= rv2->data.numVal){
                result = 1;
            }
        }
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
        result = (avm_tobool(rv1) < avm_tobool(rv2));
    }else if(rv1->type == nil_m || rv2->type == nil_m){
        result = rv1->type == nil_m && rv2->type == nil_m;
    }else if(rv1->type != rv2->type ){
            printf("error please be better\n");
            exit(-1);
    }else{
        if(rv1->type == number_m && rv2->type == number_m){
            if(rv1->data.numVal >= rv2->data.numVal){
                result = 1;
            }
        }
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
        if(rv1->type == number_m && rv2->type == number_m){
            if(rv1->data.numVal <  rv2->data.numVal){
                result = 1;
            }
        }
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
        result = (avm_tobool(rv1) < avm_tobool(rv2));
    }else if(rv1->type == nil_m || rv2->type == nil_m){
        result = rv1->type == nil_m && rv2->type == nil_m;
    }else if(rv1->type != rv2->type ){
            printf("error please be better\n");
            exit(-1);
    }else{
        if(rv1->type == number_m && rv2->type == number_m){
            if(rv1->data.numVal > rv2->data.numVal){
                result = 1;
            }
        }
    }
    if(!executionFinished && result)
        pc = inst->result.val;
}


void execute_call(instruction* inst){
    avm_memcell* func = avm_translate_operand(&(inst->arg1),&ax);
    assert(func);
    switch(func->type){
        case userfunc_m: {
            avm_callsaveenvironment();
            pc = func->data.funcVal+1;
            assert(pc<AVM_ENDING_PC);
            assert(code[pc].opcode == funcenter_v);
            break;
        }
        case string_m: avm_calllibfunc(func->data.strVal); break;
        case libfunc_m: avm_calllibfunc(func->data.libfuncVal); break;
        case table_m: avm_call_functor(func->data.tableVal); break;

        default:{
            // char* s = avm_tostring(func);
            string s = avm_tostring(func);
            cout << "cannot bind " << s << "  to a function !" << endl;  // write runtime error
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
    assert(pc-1 == func->data.funcVal);
    totalActuals = 0; 
    userfunc* funcInfo = avm_getfuncinfo(pc);
   // printf("FUNCINFO locals :: %d\n", funcInfo->localSize);
    topsp = top;
    top = top - funcInfo->localSize;
   // print_stack();
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
}
void execute_tablegetelem(instruction* inst){
    avm_memcell *lv = avm_translate_operand(&inst->result, (avm_memcell *) 0);
    avm_memcell *t = avm_translate_operand(&inst->arg1, (avm_memcell *) 0);
    avm_memcell *i = avm_translate_operand(&inst->arg2, (avm_memcell *) &ax);

    assert(lv && &stack[AVM_STACKSIZE - 1] >= lv && lv > &stack[top] || lv == &retval);
    assert (t && &stack[AVM_STACKSIZE - 1] >= t && t> &stack[top]);
    assert(i);

    // avm_memcellclear(lv);
    lv->type = nil_m;

    if (t->type != table_m){
   
        cout << "illegal use of type" << endl;
    }else {
        avm_memcell *content = avm_tablegetelem(t->data.tableVal ,i);
        // cout << "i index: " << i->type << endl;
        // cout << "content: " << content->type << endl;
        if (content) avm_assign(lv,content);
        else {
            // char *ts = avm_tostring(t);
            // char *is = avm_tostring(i);
            string ts = avm_tostring(t);
            string is = avm_tostring(i);
            cout << "notfound"<< endl;
            // free(ts);
            // free(is);
        }
    }
}
void execute_tablesetelem(instruction* inst){
    avm_memcell *t = avm_translate_operand(&inst->result, (avm_memcell * )0);
    avm_memcell *i = avm_translate_operand(&inst->arg1, &ax);
    avm_memcell *c = avm_translate_operand(&inst->arg2, &bx);

    assert(t && &stack[AVM_STACKSIZE - 1] >= t && t > &stack[top]);
    assert(i && c);

    if (t->type != table_m) {
        printf("PC :: %d\n", pc);
        cout << "illegal use of type" << endl;
        exit(0);
    } else {
        avm_tablesetelem(t->data.tableVal, i , c);
    } 

    // print_avm_table(t->data.tableVal);
}


void execute_nop(instruction* inst){
    
}


void avm_push_table_arg(avm_table* t){
    stack[top].type = table_m;
    ++totalActuals;
    avm_dec_top();
}

void print_avm_memcell(const avm_memcell *cell) {
    switch (cell->type) {
        case number_m:
            std::cout << cell->data.numVal;
            break;
        case string_m:
            std::cout << cell->data.strVal;
            break;
        case bool_m:
            std::cout << (cell->data.boolVal ? "true" : "false");
            break;
        case nil_m:
            std::cout << "nil";
            break;
        case undef_m:
            std::cout << "undefined";
            break;
        // Handle other types as needed
        default:
            std::cout << "unsupported type";
            break;
    }
}

void avm_assign(avm_memcell* lv, avm_memcell* rv){
    if(lv == rv) //same memcells 
        return;
    
    if(lv->type == table_m && rv->type == table_m && lv->data.tableVal == rv->data.tableVal) //same tables
        return;

    if(rv->type == undef_m)
        cout << "Warning" << endl;   //avm_warning("assigning from undefined content!!");
    
    avm_memcellclear(lv);
    switch(rv->type){
        case number_m:{
            lv->type = number_m;
            lv->data.numVal = rv->data.numVal;
            break;
        }
        case nil_m: {
            lv->type = nil_m;
            break;
        }
        case string_m: {
            lv->type = string_m;
            lv->data.strVal = strdup(rv->data.strVal);
            break;
        }
        case bool_m: {
            lv->type = bool_m;
            lv->data.boolVal = rv->data.boolVal;
            break;
        }

        case table_m: {
            lv->type = table_m;
            lv->data.tableVal = rv->data.tableVal;
            // avm_table *new_table = new avm_table;
            // new_table->refCounter = rv->data.tableVal->refCounter;
            // for (const auto& pair : rv->data.tableVal->indexedDouble) {
            //   new_table->indexedDouble[pair.first] = pair.second;
            // }
            // for (const auto& pair : rv->data.tableVal->indexedStrVal) {
            //   new_table->indexedStrVal[pair.first] = pair.second;
            // }

            // std::cout << "\n\nnew table" << std::endl;
            // std::cout << "double" << std::endl;
            // for (const auto& pair : new_table->indexedDouble) {
            //     std::cout << pair.first << " => ";
            //     print_avm_memcell(pair.second);
            //     std::cout << std::endl;
            // }
            // std::cout << "str" << std::endl;
            // for (const auto& pair : new_table->indexedStrVal) {
            //     std::cout << pair.first << " => ";
            //     print_avm_memcell(pair.second);
            //     std::cout << std::endl;
            // }

            // std::cout << "\nold table" << std::endl;
            // std::cout << "double" << std::endl;
            // for (const auto& pair : rv->data.tableVal->indexedDouble) {
            //     std::cout << pair.first << " => ";
            //     print_avm_memcell(pair.second);
            //     std::cout << std::endl;
            // }
            // std::cout << "str" << std::endl;
            // for (const auto& pair : rv->data.tableVal->indexedStrVal) {
            //     std::cout << pair.first << " => ";
            //     print_avm_memcell(pair.second);
            //     std::cout << std::endl;
            // }
            // cout << "\n\n";
            //lv->data.tableVal = new_table;
            break; 
        }

        case userfunc_m: {
            lv->type = userfunc_m;
            lv->data.funcVal = rv->data.funcVal;
            break;
        }

        case libfunc_m: {
            lv->type = libfunc_m;
            lv->data.libfuncVal = strdup(rv->data.libfuncVal);
            break;
        }
    }

    if(lv->type == string_m)
        lv->data.strVal = strdup(rv->data.strVal);    
        
    //  if(lv->type == table_m)
    //     lv->data.tableVal->refCounter++;
}

void avm_call_functor(avm_table *t){
    exit(0);
    cx.type = string_m;
    cx.data.strVal = (char *)"()";

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
        exit(0);
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
    return &user_funcs[code[address].result.val];
}

unsigned avm_get_envvalue(unsigned i){
    assert(stack[i].type == number_m);
    unsigned val = (unsigned) stack[i].data.numVal;
    assert(stack[i].data.numVal == ((double) val));
    return val;
}

void avm_calllibfunc (char * id){
    library_func_t f = avm_getlibraryfunc((char *) id);
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

void libfunc_print(void){
    unsigned n = avm_totalactuals();
    for (unsigned i = 0; i<n; ++i){
        string s = avm_tostring(avm_getactual(i)); 
        cout << s;
    }
}

void libfunc_typeof(void) {
    unsigned n = avm_totalactuals();
    string s = "";

    if (n != 1) {
      cout << "typeof is expected 1 argument" << endl;
      exit(0);
    }

    avm_memcellclear(&retval);
    retval.type = string_m;

    avm_memcell *m = avm_getactual(0);
    switch (m->type) {
      case string_m:   s = "string";   break;
      case number_m:   s = "number";   break;
      case bool_m:     s = "bool";     break;
      case table_m:    s = "table";    break;
      case userfunc_m: s = "userfunc"; break;
      case libfunc_m:  s = "libfunc";  break;
      case undef_m:    s = "undef";    break;
      case nil_m:      s = "nil";      break;
    }

    retval.data.strVal = new char[s.size() + 1];
    strcpy(retval.data.strVal, s.c_str());  
}

double to_radian(double num) {
  return num * 3.14159 / 180;
}

void libfunc_cos(void) {
  unsigned n = avm_totalactuals();
  avm_memcell *arg = avm_getactual(0);
  avm_memcellclear(&retval);
  retval.type = nil_m;

  if (n != 1) {
    cout << "cos function is expected to have 1 argument" << endl;
    exit(0);
  }

  if (arg->type != number_m) {
    cout << "cos function is expected a number as an argument" << endl;
    exit(0);
  }

  retval.type = number_m;
  retval.data.numVal = (double)cos(to_radian(arg->data.numVal));

}

void libfunc_sin(void) {
  unsigned n = avm_totalactuals();
  avm_memcell *arg = avm_getactual(0);
  avm_memcellclear(&retval);
  retval.type = nil_m;

  if (n != 1) {
    cout << "sin function is expected to have 1 argument" << endl;
    exit(0);
  }

  if (arg->type != number_m) {
    cout << "sin function is expected a number as an argument" << endl;
    exit(0);
  }

  retval.type = number_m;
  retval.data.numVal = (double)sin(to_radian(arg->data.numVal));
}

void libfunc_argument(void) {
  unsigned n = avm_totalactuals();
  unsigned p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
  avm_memcell *arg = avm_getactual(0);

  avm_memcellclear(&retval);
  retval.type = nil_m;

  if (p_topsp == NO_ACTIVATION_RECORDS) {
    cout << "argument called outside a function " << endl;
    retval.type = nil_m;
    exit(0);
  } 

  if (n != 1) {
    cout << "argument function is expected 1 argument" << endl;
    exit(0);
  }

  if (arg->type) {
    cout << "argument function is expected a number as an argument" << endl;
    exit(0);
  }

  if (arg->data.numVal < 0) {
    cout << "cannot access a negative argument" << endl;
    exit(0);
  }

  if (arg->data.numVal >= avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET)) {
    cout << "the function does not have " << arg->data.numVal << " arguments" << endl;
    exit(0);
  }

  avm_memcell *argument = &stack[p_topsp + (int)avm_getactual(0)->data.numVal + 1 + AVM_STACKENV_SIZE];
  avm_assign(&retval, argument);
}


void avm_registerlibfunc(char * id, library_func_t addr){
    lib_map.insert({id, addr});
}

void execute_arithmetic(instruction *inst) {
    avm_memcell *lv = avm_translate_operand(&inst->result, (avm_memcell *) 0);
    avm_memcell *rv1 = avm_translate_operand(&inst->arg1, &ax);
    avm_memcell *rv2 = avm_translate_operand(&inst->arg2, &bx);

    assert(lv && (&stack[AVM_STACKSIZE - 1] >= lv && lv > &stack[top] || lv == &retval)); // GOTO
    assert(rv1 && rv2);
    if (rv1->type != number_m || rv2->type != number_m) {
        cout << "not a number in arithmetic!" << endl;
        executionFinished = 1;
    } else {
        arithmetic_func_t op = arithmeticFuncs[inst->opcode - add_v];
        avm_memcellclear(lv);
        lv->type = number_m;
        lv->data.numVal = (*op)(rv1->data.numVal, rv2->data.numVal);
    }

}


string number_tostring (avm_memcell* m) {
    ostringstream out;
    out << fixed << setprecision(2) << m->data.numVal;
    //case ama exei dekadika pshfia
    // out << (int)m->data.numVal;
    return out.str();
}


string string_tostring (avm_memcell* m ){return m->data.strVal;}

string bool_tostring (avm_memcell* m){

    if(m->data.boolVal == '0'){
        return (char*) "false";
    }else{
        return (char*) "true";
    }
}

string table_tostring (avm_memcell*m){
    string t = "[ ";
    t += avm_printtable(m->data.tableVal);
    t += "]";
    return t;
}

string userfunc_tostring (avm_memcell*m){
    return lookup_based_on_instr_addr(m->data.funcVal - 1); 
}

string libfunc_tostring (avm_memcell*m) { return m->data.libfuncVal;}
string nil_tostring (avm_memcell*m) { return "nil"; }
string undef_tostring (avm_memcell*m) { return "undef"; }

unsigned char number_tobool(avm_memcell *m){
    if(m->data.numVal != 0 ){
        return '1';
    }else{
        return '0';
    }
}

unsigned char string_tobool(avm_memcell *m){return m->data.strVal[0]!=0;}
unsigned char bool_tobool(avm_memcell *m){return m->data.boolVal;}
unsigned char table_tobool(avm_memcell *m){return '1';}
unsigned char userfunc_tobool(avm_memcell *m){return '1';}
unsigned char libfunc_tobool(avm_memcell *m){return '1';}
unsigned char nil_tobool(avm_memcell *m){return '0';}
unsigned char undef_tobool(avm_memcell *m) {return '0';}

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


library_func_t avm_getlibraryfunc(char *id) { 
    return lib_map[id];
}

void avm_initialize(void) {
    avm_initstack();

    avm_registerlibfunc((char *) "print", libfunc_print);
    avm_registerlibfunc((char *) "typeof", libfunc_typeof);
    avm_registerlibfunc((char *) "totalarguments", libfunc_totalarguments);
    avm_registerlibfunc((char *) "argument", libfunc_argument);
    avm_registerlibfunc((char *) "cos", libfunc_cos);
    avm_registerlibfunc((char *) "sin", libfunc_sin);
    avm_registerlibfunc((char *) "sqrt",libfunc_sqrt);
    avm_registerlibfunc((char *) "strtonum",libfunc_strtonum);
    avm_registerlibfunc((char *) "input", libfunc_input);
    avm_registerlibfunc((char *) "objecttotalmembers", libfunc_objecttotalmembers);
    avm_registerlibfunc((char *) "objectcopy", libfunc_objectcopy);
//    for (const auto& [k, v] : lib_map) {
//         std::cout << "m[" << k << "] = " << reinterpret_cast<void*>(v) << std::endl;
//     }
    // TODO: prepei na to valoume kai gia tis upoloipes
}

void libfunc_objectcopy(void){
    unsigned i = avm_totalactuals();
    avm_memcellclear(&retval);

    if (i!=1){
        cout << "Too many args syntekne" <<endl;
        exit(0);
    }

    if(avm_getactual(0)->type != table_m){
        cout << "Pinakes antigrafw! to leei kai to onoma mou :(" << endl;
        exit(0);
    }

    avm_assign(&retval,avm_getactual(0));
}

void libfunc_objecttotalmembers(void){
    unsigned i = avm_totalactuals();
    avm_memcellclear(&retval);

    if(i!=1){
        cout<<"Lathos reeee evales polla args eprepe mono 1 "<< endl;
        exit(0);
    }
    if(avm_getactual(0)->type != table_m){
        cout << "Pinaka thelw ";
        exit(0);
    }

    retval.type = number_m;
    retval.data.numVal = avm_getactual(0)->data.tableVal->refCounter;



}
void libfunc_input(){

    unsigned i = avm_totalactuals();
    avm_memcellclear (&retval);

    if(i!=0){
        cout<<"Error no args expected! Ena input eixes na valeis ti phge lathos?"<<endl;
        exit(0);
    } 

    string str;
    cin >> str;

    if ( str.compare("true") == 0){
        retval.type = bool_m;
        retval.data.boolVal = true;
        return;
    }

    if (str.compare("false") == 0){
        retval.type = bool_m;
        retval.data.boolVal = false;
        return;
    }

    if (str.compare("nil") == 0){
        retval.type = nil_m;
        return;
    }


    double x;
    char *end;
    x = strtod(str.c_str(),&end);

    if (!(end == str.c_str() || *end != '\0')){
        retval.type = number_m;
        retval.data.numVal = x;
        return;
    }

    char *c = new char[str.length()+1];
    strcpy(c,str.c_str());

    retval.type = string_m;
    retval.data.strVal = c;



}

void libfunc_strtonum(){
    avm_memcell *m = avm_getactual(0);
    avm_memcellclear(&retval);

    if(m->type != string_m){
        cout << "Error! You need to enter a string " << endl;
        exit(0);
    }
    retval.type = number_m;
    retval.data.numVal = atoi(m->data.strVal);
    if(m->data.strVal[0] != '0' && retval.data.numVal == 0){
        retval.type = nil_m;
    }
}

void libfunc_sqrt(){
    avm_memcell *m = avm_getactual(0);
    avm_memcellclear(&retval);
    if(m->type != number_m){
        cout<<"Error! Cannot calculate square root of non arithmetic operand" << endl;
        exit(0);
    }
    if(m->data.numVal>=0){
        retval.type = number_m;
        retval.data.numVal = sqrt(m->data.numVal);
    }else{
        retval.type = nil_m;
    }
}

void libfunc_totalarguments(void) {    
    unsigned p_topsp = avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
    avm_memcellclear(&retval);

    if (p_topsp == NO_ACTIVATION_RECORDS ) {
        cout << "total arguments called outside a function " << endl;
        retval.type = nil_m;
    } else {
        retval.type = number_m;
        retval.data.numVal = avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
    }
}

void print_memcell(avm_memcell *m) {
    switch (m->type) {
        case number_m:
            printf("number: %f\n", m->data.numVal);
            break;
        case string_m:
            printf("string: %s\n", m->data.strVal);
            break;
        case bool_m:
            printf("bool: %s\n", m->data.boolVal ? "true" : "false");
            break;
        case table_m:
            printf("table: %p\n", m->data.tableVal);
            break;
        case userfunc_m:
            printf("userfunc: %u\n", m->data.funcVal);
            break;
        case libfunc_m:
            printf("libfunc: %s\n", m->data.libfuncVal);
            break;
        case nil_m:
            printf("nil\n");
            break;
        case undef_m:
            printf("undef\n");
            break;
        default:
            printf("unknown type\n");
            break;
    }
}

void print_stack() {
    printf("Stack from top address (highest) to topsp (%u):\n", topsp);
    for (unsigned i = AVM_STACKSIZE - 1; i > topsp; --i) {
        printf("stack[%u]: ", i);
        print_memcell(&stack[i]);
        if (i == 0) break;  // To prevent underflow of unsigned
    }
}
