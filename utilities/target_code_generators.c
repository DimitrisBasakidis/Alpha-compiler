#include "target_code_generators.h"

void generate_targetcode(void){
    for(unsigned i = 0;i<total;++i){
        (*generators[quads[i].op]) (quads+i);
    }
}

void generate(vmopcode op, quad *q){
    instruction t;
    t.opcode = op;
    make_operand(q->arg1,&t.arg1);
    make_operand(q->arg2,&t.arg2);
    make_operand(q->result, t.result);
    q->taddress = nextinstructionlabel();
    femit(t);
}

void generate_relational(vmopcode op, quad *q){
    instruction t; 
    t.opcode = op;
    make_operand(q->arg1,&t.arg1);
    make_operand(q->arg2,&t.arg2);
    t.result.type = label_a;

}

void generate_ADD (quad* q) { generate(add_v, q); }
void generate_SUB (quad* q) { generate(sub_v, q); }
void generate_MUL (quad* q) { generate(mul_v, q); }
void generate_DIV (quad* q) { generate(div_v, q); }
void generate_MOD (quad* q) { generate(mod_v, q); }
void generate_TABLECREATE (quad* q) { generate(newtable_v, q); }
void generate_TABLEGETELM (quad* q) { generate(tablegetelem_v, q); }
void generate_TABLESETELEM (quad* q) { generate(tablesetelem_v, q); }
void generate_ASSIGN (quad* q) { generate(assign_v, q); }
void generate_NOP () { instruction t; t.opcode=nop; emit(t); }
