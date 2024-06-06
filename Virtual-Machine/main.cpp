#include <iostream>
#include "decodeBinary.hpp"
#include "avm_dispatcher.hpp"
#include "avm_structs.hpp"
#include "avm_utilities.hpp"
#include <stdio.h>

using namespace std;

avm_memcell ax, bx, cx;
avm_memcell retval;
unsigned top, topsp;
unsigned char executionFinished = 0;
unsigned pc = 1;
unsigned currLine = 0;
unsigned codeSize = 0;
unsigned totalActuals=0;

avm_memcell stack[AVM_STACKSIZE];



instruction* code = (instruction *)0;

int main(int argc, char **argv) {

    decode_binary_file(argv[1]);
    printInstructions();
    avm_initialize();

    codeSize = instr.size();
    code = &instr[0];

    top = topsp = AVM_STACKSIZE - 2 - globalVarsNo;

    while(executionFinished == 0){
        execute_cycle();
    }
    return 0;
}


/*tests 23 24 hercules*/