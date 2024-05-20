#include <iostream>
#include "decodeBinary.hpp"
#include "avm_dispatcher.hpp"
#include "avm_structs.hpp"
#include "avm_utilities.hpp"

using namespace std;

avm_memcell stack[AVM_STACKSIZE];
avm_memcell ax, bx, cx;
avm_memcell retval;
unsigned top, topsp;
unsigned char executionFinished = 0;
unsigned pc = 1;
unsigned currLine = 0;
unsigned codeSize = 0;
unsigned totalActuals=0;

instruction* code = (instruction *)0;

int main(int argc, char **argv) {
    decode_binary_file(argv[1]);

    codeSize = instr.size()-1;
    code = &instr[1];
    cout<< "\ninstr size :: " << codeSize << endl;

    top = topsp = AVM_STACKSIZE - 1 - globalVarsNo;

    while(executionFinished == 0){
        printf("executing\n");
        execute_cycle();
    }


    cout << "top of the stack: " << top << topsp << endl;
    return 0;
}
