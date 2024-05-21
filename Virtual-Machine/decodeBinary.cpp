#include "decodeBinary.hpp"
#include <iostream>
#include <vector>

using namespace std;

unsigned currInstruction = 0U;
unsigned currNumConsts = 0U;
unsigned currStringConsts = 0U;
unsigned currNamedLibFuncs = 0U;
unsigned currUserFuncs = 0U;
unsigned globalVarsNo = 0U;

vector<instruction> instr;
vector<double> num;
vector<userfunc> user_funcs;
vector<string> lib_funcs;
vector<string> strings;

string read_string(FILE *ptr) {
    char c;
    string str = "";
    while((c = fgetc(ptr)) != '\0'){
        str += c;
    }
    return str;
}

void decode_binary_file(const char *binary) {
    unsigned int magic_number = 340200501;
    unsigned int magic_mike = 0;

    FILE *ptr = fopen(binary, "rb");

   fread(&magic_mike, sizeof(unsigned), 1, ptr);

    if (magic_mike != magic_number) {
        // cout << "incorrect file format" << endl;
    }
    // cout << magic_mike << endl;

    fread(&currInstruction, sizeof(unsigned), 1, ptr);
    // cout << "currInstruction: " << currInstruction << endl;
    for (int i = 0; i < currInstruction; i++) {
        instruction temp;
        fread(&temp, sizeof(instruction), 1, ptr);
        instr.push_back(temp);
    }

    fread(&currNumConsts, sizeof(unsigned), 1, ptr);
    // cout << "currNumConsts: " << currNumConsts << endl;
    for (int i = 0; i < currNumConsts; i++) {
        double d;
        fread(&d, sizeof(double), 1, ptr);
        num.push_back(d);
        // cout << d << endl;
    }

    fread(&currStringConsts, sizeof(unsigned), 1, ptr);
    // cout << "currStringConsts: " << currStringConsts << endl;
    for (int i = 0; i < currStringConsts; i++) {
        strings.push_back(read_string(ptr));
    }

    fread(&currNamedLibFuncs,sizeof(currNamedLibFuncs),1,ptr);
    // cout << "currNamedLibFuncs: " << currStringConsts << endl;
    for (int i = 0; i < currNamedLibFuncs; i++){ 
        lib_funcs.push_back(read_string(ptr));
    }

    fread(&currUserFuncs, sizeof(currUserFuncs), 1, ptr);
    // cout << "currUserFuncs: " << currUserFuncs << endl;
    for (int i = 0; i < currUserFuncs; i++) {
        userfunc usrf;
        fread(&usrf.address, sizeof(unsigned), 1, ptr);
        fread(&usrf.localSize, sizeof(unsigned), 1, ptr);
        string s = read_string(ptr);
        usrf.id = strdup(s.c_str());
        user_funcs.push_back(usrf);
        // cout << usrf.id <<  " " <<  usrf.localSize << " " << usrf.address <<  endl;
    }

    fread(&globalVarsNo, sizeof(globalVarsNo), 1, ptr);

    // cout << "global var no(binary) " << globalVarsNo << endl;
    return;

}

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

void printInstructions(void) {
    for (int i = 0; i < currInstruction; i++) {
        if (i == 0) continue;
        printf("%-4d| ",i);
        printOpcode(instr[i].opcode);
        printVMarg(&instr[i].arg1);
        printVMarg(&instr[i].arg2);
        printVMarg(&instr[i].result);
        printf("\n");
        fflush(stdout);
    }

    printf("\n-----------------StringConstsTable------------------\n");
        // if(strings)
        for(int j=0; j<currStringConsts; j++){
            printf("%-4d| \"%s\"\n",j, (char *)strings[j].c_str());
        }
        printf("\n-----------------NumConstsTable------------------\n");
        // if(num)
        for(int j=0; j<currNumConsts; j++){
            printf("%-4d| %lf\n",j, num[j]);
        }
        printf("\n-----------------LibConstsTable------------------\n");
        // if(lib_funcs)
        for(int j=0; j<currNamedLibFuncs; j++){
            printf("%-4d| \"%s\"\n",j, (char *)lib_funcs[j].c_str());
        }
        printf("\n-----------------UserFuncsTable------------------\n");
        // if(user_funcs)
        for(int j=0; j<currUserFuncs; j++){
            printf("%-4d| \"%s\" address=%d | local=%d\n",j, (char *)user_funcs[j].id, user_funcs[j].address, user_funcs[j].localSize);
        }   
}
