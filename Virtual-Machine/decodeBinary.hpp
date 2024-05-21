#ifndef BINARY_DECODER
#define BINARY_DECODER

#include "../Compiler/utilities/final_code.h"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

struct instruction;
struct userfunc;

extern std::vector<instruction> instr;
extern std::vector<double> num;
extern std::vector<userfunc> user_funcs;
extern std::vector<std::string> lib_funcs;
extern std::vector<std::string> strings;
extern unsigned globalVarsNo;

void decode_binary_file(const char *binary);

void printInstructions(void);

#endif
