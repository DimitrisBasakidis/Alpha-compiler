#include "avm_structs.hpp"
#include <iostream>
using namespace std;


void avm_initstack(void){
    for(unsigned i = 0;i<AVM_STACKSIZE;++i){
        AVM_WIPEOUT(stack[i]);
        stack[i].type = undef_m;
    }
}
