#include "avm_tables.hpp"
#include "decodeBinary.hpp"
// #include "avm_utilities.cpp"


memclear_func_t memclearFuncs[]= {
    0,
    memclear_string,
    0,
    memclear_table,
    0,
    0,
    0,
    0
};

avm_table* avm_tablenew(void){
    avm_table* t = new avm_table;
    t->refCounter = 0;
    return t;
}



void avm_tabledestroy (avm_table* t ){
    free(t);
}

void memclear_table(avm_memcell* m) {

}


void memclear_string(avm_memcell* m) {
    assert(m->data.strVal);
    free(m->data.strVal);
}

void avm_memcellclear (avm_memcell* m){
    // if(m->type != undef_m){
    //     memclear_func_t f = memclearFuncs[m->type];
    //     if(f)
    //         (*f)(m);
    //     m->type = undef_m;
    // }
}

void avm_tablesetelem(struct avm_table *table, avm_memcell *key, avm_memcell *value) {
    avm_memcell *temp = (avm_memcell *) malloc(sizeof(avm_memcell));
    temp->type = value->type;

    switch (key->type) {    
        case number_m:
            temp->data.numVal = value->data.numVal;
            table->indexedDouble.insert(pair<double, avm_memcell*>(key->data.numVal, temp));
            break;
        
        case string_m:
            temp->data.strVal = value->data.strVal;
            table->indexedStrVal.insert(pair<string, avm_memcell*>(key->data.strVal, temp));
            break;
    }
}

avm_memcell* avm_tablegetelem(avm_table *t, avm_memcell* key) {
    switch (key->type) {
        case number_m: return t->indexedDouble.at(key->data.numVal);
        case string_m: return t->indexedStrVal.at(key->data.strVal);
        default: assert(0);
    }
    return nullptr;
}

char* lookup_based_on_instr_addr(unsigned addr){
    for(int i =0; i<user_funcs.size();i++){
        if(user_funcs[i].address == addr){
            return user_funcs[i].id;
        }
    }

    return (char *)"";
}

string print_avm_memcell(const avm_memcell* cell, string tablestr) {
    if (cell == nullptr) {
        std::cout << "null";
        return "nil, ";
    }
    
    switch (cell->type) {
        case number_m:
            // std::cout << "numVal: " << cell->data.numVal;
            tablestr += to_string(cell->data.numVal);
            tablestr += ", ";
            break;
        case string_m:
            // std::cout << "strVal: " << cell->data.strVal;
            tablestr += cell->data.strVal;
            tablestr += ", ";
            break;
        case bool_m:
            tablestr += (cell->data.boolVal == '1') ? "true, " : "false, ";
            break;
        case table_m:
            tablestr += "[ ";
            tablestr += avm_printtable(cell->data.tableVal) + "], ";
            break;
        case userfunc_m:
            // cout << "index "  << cell->data.funcVal << endl; 
            // tablestr += instr[cell->data.funcVal].result.val;
            tablestr += lookup_based_on_instr_addr(cell->data.funcVal);
            tablestr += ", ";
            break;            
        case libfunc_m:
            tablestr += cell->data.libfuncVal;
            tablestr += ", ";
            break;
        case nil_m:
            tablestr += "nil, ";
            break;
        case undef_m:
            tablestr += "undef, ";
            break;
        default:
            // std::cout << "Unknown type";
            tablestr += "[], ";
    }
    // tablestr += ", ";

    return tablestr;
}

// Function to print avm_table
string avm_printtable(const avm_table* table) {
    string tablestr;

    if (table == nullptr) {
        // std::cout << "Table is null" << std::endl;
        return "undef";
    }
    
    // std::cout << "refCounter: " << table->refCounter << std::endl;
    
    // std::cout << "indexedDouble:" << std::endl;
    for (const auto& pair : table->indexedDouble) {
        // std::cout << "  Key: " << pair.first << " -> Value: ";
        tablestr = print_avm_memcell(pair.second, tablestr);
        // std::cout << std::endl;
    }
    
    // std::cout << "indexedStrVal:" << std::endl;
    for (const auto& pair : table->indexedStrVal) {
        // std::cout << "  Key: " << pair.first << " -> Value: ";
        tablestr =  print_avm_memcell(pair.second, tablestr);
        // std::cout << std::endl;
    }

    return tablestr;
}

// int main() {

//     avm_table *t = avm_tablenew();
//     avm_memcell *n = (avm_memcell *) malloc(sizeof(avm_memcell));
//     n->data.strVal = (char *)malloc(sizeof(char *));
//     n->data.strVal = (char *)"index";
//     n->type = string_m;

//     avm_memcell *nn = (avm_memcell *) malloc(sizeof(avm_memcell));
//     nn->data.strVal = (char *)malloc(sizeof(char *));
//     nn->data.strVal = (char *)"vaggelis kai mitsos";
//     nn->type = string_m;

//     avm_memcell *n2 = (avm_memcell *) malloc(sizeof(avm_memcell));
//     n2->data.numVal = 3.343;
//     n2->type = number_m;

//     avm_memcell *nn2 = (avm_memcell *) malloc(sizeof(avm_memcell));
//     nn2->data.numVal = 3.3;
//     nn2->type = number_m;

//    avm_tablesetelem(t, n, nn);
//     avm_tablesetelem(t, n2, nn2);

//     print_avm_table(t);

//     cout << "index: 3.343 = " << avm_tablegetelem(t, n2)->data.numVal << endl;
//     cout << "index: index = " << avm_tablegetelem(t, n)->data.strVal << endl;
// }