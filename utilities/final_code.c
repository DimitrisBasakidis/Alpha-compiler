#include "final_code.h"

double *numConsts;
unsigned totalNumConsts;
unsigned currNumConsts;
char **stringConsts;
unsigned totalStringConsts;
unsigned currStringConsts;
char **namedLibFuncs;
unsigned totalNamedLibFuncs;
unsigned currNamedLibFuncs;
userfunc *userFuncs;
unsigned totalUserFuncs;
unsigned currUserFuncs;

void expand_string_consts() {
    assert(totalStringConsts == currStringConsts);

    char **s = (char **) malloc(NEW_STRING_CONSTS_SIZE);

    if (s) {
        memcpy(s, stringConsts, CURR_STRING_CONSTS_SIZE);
        free(stringConsts);
    }

    stringConsts = s;
    totalStringConsts += EXPAND_INSTRUCTION_SIZE;
}

void expand_num_consts() {
    assert(totalNumConsts == currNumConsts);

    double *n = (double *) malloc(NEW_STRING_CONSTS_SIZE);

    if (n) {
        memcpy(n, numConsts, CURR_NUMBER_CONSTS_SIZE);
        free(numConsts);
    }

    numConsts = n;
    totalNumConsts += EXPAND_INSTRUCTION_SIZE;
}

void expand_named_libfuncs() {
    assert(totalNamedLibFuncs == currNamedLibFuncs);

    char **l = (char **) malloc(NEW_NAMED_LIBFUNCS_SIZE);

    if (l) {
        memcpy(l, namedLibFuncs, CURR_NAMED_LIBFUNCS_SIZE);
        free(namedLibFuncs);
    }

    namedLibFuncs = l;
    totalNamedLibFuncs += EXPAND_INSTRUCTION_SIZE;
}

void expand_named_userfuncs() {
    assert(totalUserFuncs == currUserFuncs);

    userfunc *u = (userfunc *) malloc(NEW_USER_FUNCS_SIZE);

    if (u) {
        memcpy(u, userFuncs, CURR_USER_FUNCS_SIZE);
        free(userFuncs);
    }

    userFuncs = u;
    totalUserFuncs += EXPAND_INSTRUCTION_SIZE;

}

unsigned consts_newstring(char* str) {
    if (totalStringConsts == currStringConsts) expand_string_consts();

    for (int i = 0; i < currStringConsts; i++) {
        if (strncmp(stringConsts[i], str, strlen(str)) == 0 && strlen(str) == strlen(stringConsts[i])) return i;
    }

    stringConsts[currStringConsts] = strdup(str);

    return currStringConsts++;
}

unsigned consts_newnumber(double num) {
    if (totalNumConsts == currNumConsts) expand_num_consts();

    for (int i = 0; i < currNumConsts; i++) {
        if (numConsts[i] == num) return i;
    }

    numConsts[currNumConsts] = num;

    return currNumConsts++;    
}

unsigned libfuncs_newused(char* libfunc_name) {
    if (totalNamedLibFuncs == currNamedLibFuncs) expand_named_libfuncs();

    for (int i = 0; i < currNamedLibFuncs; i++) {
        if (strncmp(namedLibFuncs[i], libfunc_name, strlen(libfunc_name)) == 0 && strlen(libfunc_name) == strlen(namedLibFuncs[i])) return i;
    }

    namedLibFuncs[currNamedLibFuncs] = strdup(libfunc_name);

    return currNamedLibFuncs++;
}

unsigned userfuncs_newused(SymbolTableEntry *sym) {
    if (totalUserFuncs == currUserFuncs) expand_named_userfuncs();

    for (int i = 0; i < currUserFuncs; i++) {
        if (strncmp(userFuncs[i].id, sym->value.funcVal->name, strlen(sym->value.funcVal->name)) == 0 && strlen(sym->value.funcVal->name) == strlen(userFuncs[i].id)) return i;
    }

    userFuncs[currUserFuncs].id = strdup(sym->value.funcVal->name);
    userFuncs[currUserFuncs].address = sym->iaddress;
    userFuncs[currUserFuncs].localSize = sym->offset;

    return currUserFuncs++;
}

void fexpand(void){
    assert (total == currInstruction);
    instruction* i = (instruction*) malloc(NEW_SIZE);

    if(instructions){
        memcpy(i, instructions,CURR_SIZE);
        free(instructions);
    }
    instructions = i;
    total_f += EXPAND_SIZE;
}

unsigned nextinstructionlabel(){
    return currInstruction;
}

void make_operand(expr* e, vmarg* arg){
    switch(e->type){
        case var_e:
        case tableitem_e:
        case arithexpr_e:
        case boolexpr_e:
        case newtable_e:{
            arg->val = e->sym->offset;
            switch (e->sym->space) {
                case programvar:    arg->type = global_a; break;
                case functionlocal: arg->type = local_a;  break;
                case formalarg:     arg->type = formal_a; break;
                default: assert(0);
            }
        }
        case constbool_e: {
            arg->val = e->boolConst;
            arg->type = bool_a; break;
        }

        case conststring_e: {
            arg->val = consts_newstring(e->strConst);
            arg->type = string_a; break;
        }

        case constnum_e: {
            arg->val = consts_newnumber(e->numConst);
            arg->type = number_a; 
            break;
        }

        case nil_e: { 
            arg->type = nil_a;
            break;
        }

        case programfunc_e: {
            arg->type = userfunc_a;
            arg->val = userfuncs_newused(e->sym);
            break;
        }

        case libraryfunc_e: {
            arg->type = libfunc_a;
            arg->val = libfuncs_newused(e->sym->value.funcVal->name);
            break;
        }
        default: assert(0);
    }
}

void femit(instruction* t){
    if(currInstruction == total) expand();
    instruction* p = instructions + currInstruction++;

} 

void make_numberoperand(vmarg* arg, double val){
    arg->val = consts_newnumber(val);
    arg->type = number_a;
}

void make_booloperand(vmarg* arg , unsigned val){
    arg->val = val;
    arg->type = bool_a;
}

void make_retvaloperand(vmarg* arg){
    arg->type = retval_a;
}