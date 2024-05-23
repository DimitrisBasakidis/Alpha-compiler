#include "target_code_generators.h"



generator_func_t generators[] = {
    generate_ASSIGN,
    generate_ADD,
    generate_SUB,
    generate_MUL,
    generate_DIV,
    generate_MOD,
    generate_UMINUS,
    generate_AND,
    generate_OR,
    generate_NOT,
    generate_IF_EQ,
    generate_IF_NOTEQ,
    generate_IF_LESSEQ,
    generate_IF_GREATEREQ,
    generate_IF_LESS,
    generate_IF_GREATER, 
    generate_CALL,
    generate_PARAM,
    generate_RETURN,
    generate_GETRETVAL,
    generate_FUNCSTART,
    generate_FUNCEND,
    generate_TABLECREATE,
    generate_TABLEGETELEM,
    generate_TABLESETELEM,
    generate_JUMP,
    generate_NOP
};





void generate_targetcode(void){
    for(unsigned i = 0;i<nextquadlabel();i++){
        (*generators[quads[i].op]) (quads+i);
    }
}

void generate(vmopcode op, quad *q){
    instruction *t= malloc(sizeof(instruction));
    t->opcode = op;
    t->srcLine = q->line;
    make_operand(q->arg1,&(t->arg1));
    make_operand(q->arg2,&(t->arg2));
    make_operand(q->result, &(t->result));
    q->taddress = nextinstructionlabel();
    femit(t);
}

void generate_relational(vmopcode op, quad *q){
    instruction *t= malloc(sizeof(instruction));
    t->opcode = op;
    make_operand(q->arg1,&(t->arg1));  
    make_operand(q->arg2,&(t->arg2));
    t->result.type = label_a;
    t->result.val = q->label;
    t->srcLine = q->line;
    q->taddress = nextinstructionlabel();
    femit(t);    

}

void generate_ADD (quad* q) { generate(add_v, q); }
void generate_SUB (quad* q) { generate(sub_v, q); }
void generate_MUL (quad* q) { generate(mul_v, q); }
void generate_DIV (quad* q) { generate(div_v, q); }
void generate_MOD (quad* q) { generate(mod_v, q); }
void generate_TABLECREATE (quad* q) { generate(newtable_v, q); }
void generate_TABLEGETELEM (quad* q) { generate(tablegetelem_v, q); }
void generate_TABLESETELEM (quad* q) { generate(tablesetelem_v, q); }
void generate_ASSIGN (quad* q) { generate(assign_v, q); }
void generate_NOP (quad* q) { instruction* t = malloc(sizeof(instruction)); t->opcode=nop_v; femit(t); }
void generate_OR(quad* q){}
void generate_NOT(quad* q){}
void generate_AND(quad* q){}

void generate_PARAM(quad* q){
    instruction *t = malloc(sizeof(instruction));
    q->taddress = nextinstructionlabel();
    t->opcode = pusharg_v;
    make_operand(q->result,&(t->arg1));
    t->result.type = noarg_a;
    t->arg2.type = noarg_a;
    femit(t);
}

void generate_CALL(quad* q){
    instruction *t = malloc(sizeof(instruction));
    q->taddress = nextinstructionlabel();
    t->opcode = call_v;
    make_operand(q->result,&(t->arg1));
    t->result.type = noarg_a;
    t->arg2.type = noarg_a;
    femit(t);
}

void generate_GETRETVAL(quad* q){
    instruction *t = malloc(sizeof(instruction));
    q->taddress = nextinstructionlabel();
    t->opcode = assign_v;
    make_operand(q->result,&(t->result));
    make_retvaloperand(&(t->arg1));
    t->arg2.type = noarg_a;
    femit(t);
}

void generate_UMINUS(quad* q){
    q->arg2 = create_expr(constnum_e,NULL,NULL,-1,"",'\0');
    generate(mul_v,q);
}

void generate_FUNCSTART(quad* q){
    userfunc *f = malloc(sizeof(userfunc));
    q->taddress = nextinstructionlabel();
    f->id = q->result->sym->value.funcVal->name;
    f->address = q->result->sym->iaddress;
    f->localSize = q->result->sym->total_locals;

    userfuncs_newused(q->result->sym); //
    push_func(funcs,f);
    instruction *t = malloc(sizeof(instruction));
    t->opcode = funcenter_v;
    make_operand(q->result,&(t->result));
    femit(t);
}

void generate_FUNCEND(quad* q){
    userfunc *f = pop_func(funcs)->s; 
    q->taddress = nextinstructionlabel();
    instruction *t = malloc(sizeof(instruction));
    t->opcode = funcexit_v;
    make_operand(q->result,&(t->result));
    femit(t);
}

void generate_RETURN(quad* q){
    q->taddress = nextinstructionlabel();
    instruction *t = malloc(sizeof(instruction));
    t->opcode = assign_v;
    make_retvaloperand(&(t->result));
    make_operand(q->arg1,&(t->arg1));
    femit(t);
    userfunc *f = peek_func(funcs)->s; 
}

void generate_JUMP(quad* q){ generate_relational(jump_v,q);}
void generate_IF_EQ(quad* q){ /*printf("\narg1_type :: %d, arg2_type:: %d\n",q->arg1->type,q->arg2->type);*/generate_relational(jeq_v,q);}
void generate_IF_NOTEQ(quad* q){ generate_relational(jne_v,q);}
void generate_IF_GREATER(quad* q){ generate_relational(jgt_v,q);}
void generate_IF_GREATEREQ(quad* q){ generate_relational(jge_v,q);}
void generate_IF_LESS(quad* q){ generate_relational(jlt_v,q);}
void generate_IF_LESSEQ(quad* q){ generate_relational(jle_v,q);}


void printOpcode(vmopcode vop){
    switch (vop)
    {
    case assign_v:
        printf("assign ");
        break;
    case add_v:
        printf("add ");
        break;
    case sub_v:
        printf("sub ");
        break;
    case mul_v:
        printf("mul ");
        break;
    case div_v:
        printf("div ");
        break;
    case mod_v:
        printf("mod ");
        break;
    case jump_v:
        printf("jump ");
        break;
    case jeq_v:
        printf("jeq ");
        break;
    case jne_v:
        printf("jne ");
        break;
    case jle_v:
        printf("jle ");
        break;
    case jge_v:
        printf("jge ");
        break;
    case jlt_v:
        printf("jlt ");
        break;
    case jgt_v:
        printf("jgt ");
        break;
    case call_v:
        printf("call ");
        break;
    case pusharg_v:
        printf("pusharg ");
        break;
    case funcenter_v:
        printf("funcenter ");
        break;
    case funcexit_v:
        printf("funcexit ");
        break;
    case newtable_v:
        printf("newtable ");
        break;
    case tablegetelem_v:
        printf("tablegetelem ");
        break;
    case tablesetelem_v:
        printf("tablesetelem ");
        break;
    case nop_v:
        printf("nop ");
        break;
    default:
        printf("Error\n");
        break;
    }
}

void printVMarg(vmarg* v){
    if(!v) printf(" -NULL- ");
    switch (v->type)
    {
    case label_a:
        printf("label:");
        break;
    case global_a:
        printf("global:");
        break;
    case formal_a:
        printf("formal:");
        break;
    case local_a:
        printf("local:");
        break;
    case number_a:
        printf("number:");
        break;
    case string_a:
        printf("string:");
        break;
    case bool_a:
        printf("bool:");
        break;
    case nil_a:
        printf("nil:");
        break;
    case userfunc_a:
        printf("userfunc:");
        break;
    case libfunc_a:
        printf("libfunc:");
        break;
    case retval_a:
        printf("retval:() ");
        return;
    default:
        printf("-NULL- ");
        return;
    }
    printf("%d ",v->val);
}

void printInstructions(){
    int i;
    for(i = 0; i<nextinstructionlabel(); i++){
    //    (*generators[quads[i].op])(quads+i);
       if (i == 0) continue;
        printf("%-4d| ",i);
        printOpcode(instructions[i].opcode);
        printVMarg(&instructions[i].arg1);
        printVMarg(&instructions[i].arg2);
        printVMarg(&instructions[i].result);
        printf("\n");
        fflush(stdout);
    }

       /*For debugging*/
        printf("\n-----------------StringConstsTable------------------\n");
        if(stringConsts)
        for(int j=0; j<currStringConsts; j++){
            printf("%-4d| \"%s\"\n",j, stringConsts[j]);
        }
        printf("\n-----------------NumConstsTable------------------\n");
        if(numConsts)
        for(int j=0; j<currNumConsts; j++){
            printf("%-4d| %lf\n",j, numConsts[j]);
        }
        printf("\n-----------------LibConstsTable------------------\n");
        if(namedLibFuncs)
        for(int j=0; j<currNamedLibFuncs; j++){
            printf("%-4d| \"%s\"\n",j, namedLibFuncs[j]);
        }
        printf("\n-----------------UserFuncsTable------------------\n");
        if(userFuncs)
        for(int j=0; j<currUserFuncs; j++){
            printf("%-4d| \"%s\" address=%d | local=%d\n",j, userFuncs[j].id, userFuncs[j].address, userFuncs[j].localSize);
        }   
}