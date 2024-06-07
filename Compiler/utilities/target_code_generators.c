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
void generate_IF_EQ(quad* q){ generate_relational(jeq_v,q);}
void generate_IF_NOTEQ(quad* q){ generate_relational(jne_v,q);}
void generate_IF_GREATER(quad* q){ generate_relational(jgt_v,q);}
void generate_IF_GREATEREQ(quad* q){ generate_relational(jge_v,q);}
void generate_IF_LESS(quad* q){ generate_relational(jlt_v,q);}
void generate_IF_LESSEQ(quad* q){ generate_relational(jle_v,q);}