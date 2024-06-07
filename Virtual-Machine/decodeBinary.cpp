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
        cout << "incorrect file format" << endl;
        exit(0);
    }

    fread(&currInstruction, sizeof(unsigned), 1, ptr);
    for (int i = 0; i < currInstruction; i++) {
        instruction temp;
        fread(&temp, sizeof(instruction), 1, ptr);
        instr.push_back(temp);
    }

    fread(&currNumConsts, sizeof(unsigned), 1, ptr);
    for (int i = 0; i < currNumConsts; i++) {
        double d;
        fread(&d, sizeof(double), 1, ptr);
        num.push_back(d);
    }

    fread(&currStringConsts, sizeof(unsigned), 1, ptr);
    for (int i = 0; i < currStringConsts; i++) {
        strings.push_back(read_string(ptr));
    }

    fread(&currNamedLibFuncs,sizeof(currNamedLibFuncs),1,ptr);
    for (int i = 0; i < currNamedLibFuncs; i++){ 
        lib_funcs.push_back(read_string(ptr));
    }

    fread(&currUserFuncs, sizeof(currUserFuncs), 1, ptr);
    for (int i = 0; i < currUserFuncs; i++) {
        userfunc usrf;
        fread(&usrf.address, sizeof(unsigned), 1, ptr);
        fread(&usrf.localSize, sizeof(unsigned), 1, ptr);
        string s = read_string(ptr);
        usrf.id = strdup(s.c_str());
        user_funcs.push_back(usrf);
    }

    fread(&globalVarsNo, sizeof(globalVarsNo), 1, ptr);

    return;
}