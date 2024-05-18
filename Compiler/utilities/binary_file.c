#include "binary_file.h"
#include "final_code.h"


void convert_to_binary(void) {
    FILE *ptr = NULL;
    ptr = fopen("binary.abc", "w");

    if (ptr == NULL) {
        perror("Cant open file"); 
        return;
    }

    unsigned magic_number = 340200501;
    userfunc user_func;
    instruction inst; 

    fwrite(&magic_number, sizeof(magic_number), 1, ptr);
    
    fwrite(&currInstruction, sizeof(currInstruction), 1, ptr);
    for (int i = 0; i < currInstruction; i++) {
        inst = instructions[i];
        fwrite(&inst, sizeof(inst), 1, ptr);
    }

    fwrite(&currNumConsts, sizeof(currNumConsts), 1, ptr);

    for (int i = 0; i < currNumConsts; i++) {
        fwrite(numConsts + i, sizeof(numConsts + i), 1, ptr);
    }

    fwrite(&currStringConsts, sizeof(currStringConsts), 1, ptr);
    char* str;
    for (int i = 0; i < currStringConsts; i++) {
        str = stringConsts[i];
        fwrite(str, strlen(str)+1, 1, ptr);
    }

    fwrite(&currNamedLibFuncs, sizeof(currNamedLibFuncs), 1, ptr);
    char* lib;
    for (int i = 0; i < currNamedLibFuncs; i++) {
        lib = namedLibFuncs[i];
        fwrite(lib, strlen(lib)+1, 1, ptr);
    }

    fwrite(&currUserFuncs, sizeof(currUserFuncs), 1, ptr);
    for (int i = 0; i < currUserFuncs; i++) {
        user_func = userFuncs[i];
        printf("userfunc localsize %d\n", user_func.localSize);
        fwrite(&user_func.address, sizeof(user_func.address), 1, ptr);
        fwrite(&user_func.localSize, sizeof(user_func.localSize), 1, ptr);
        fwrite(user_func.id, strlen(user_func.id) + 1, 1, ptr);
    }


    fclose(ptr);
}

void write_to_file(void) {
    FILE *ptr = NULL;
    ptr = fopen("regural.txt", "w");

    if (ptr == NULL) {
        perror("Cant open file"); 
        return;
    }
    fprintf(ptr, "NumConsts\n");
    for (int i = 0; i < currNumConsts; i++) {
        fprintf(ptr, "%f, ", numConsts[i]);
    }
    
    fprintf(ptr, "\nStringConsts\n");
    for (int i = 0; i < currStringConsts; i++) {
        fprintf(ptr, "%s, ", stringConsts[i]);
    }

    fprintf(ptr, "\nNamedLibFuncs\n");
    for (int i = 0; i < currNamedLibFuncs; i++) {
        fprintf(ptr, "%s, ", namedLibFuncs[i]);
    }

    fprintf(ptr, "\nUserFuncs\n");
    for (int i = 0; i < currUserFuncs; i++) {
        fprintf(ptr, "%s, ", userFuncs[i].id);
    }

    fclose(ptr);



}