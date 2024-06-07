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

    memcpy(temp,value,sizeof(avm_memcell));
    switch (key->type) {    
        case number_m: {
            std::map<double, avm_memcell*>::iterator it = (table->indexedDouble).find(key->data.numVal);
            if(it == table->indexedDouble.end()){
                table->indexedDouble.insert(pair<double, avm_memcell*>(key->data.numVal, temp));
                table->refCounter++;
            } else {
                it->second = temp;
            }
            break;
        }
        case string_m:
            std::map<string, avm_memcell*>::iterator it = (table->indexedStrVal).find(key->data.strVal);
            if(it == table->indexedStrVal.end()){
                table->indexedStrVal.insert(pair<string, avm_memcell*>(key->data.strVal, temp));
                table->refCounter++;
            } else {
                it->second = temp;
            }
            //temp->data.strVal = value->data.strVal;
            // table->indexedStrVal.insert(pair<string, avm_memcell*>(key->data.strVal, temp));
            break;
    }
}


avm_memcell* avm_tablegetelem(avm_table *t, avm_memcell* key) {
    switch (key->type) {
        case number_m: return t->indexedDouble.at(key->data.numVal);
        case string_m: return t->indexedStrVal.at(key->data.strVal);
        default:  assert(0);
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

string print_avm_memcell(const avm_memcell* cell, string tablestr, int flag) {
    if (cell == nullptr) {
        std::cout << "null";
        return "nil, ";
    }
    
    switch (cell->type) {
        case number_m:
            // ostringstream out;
            // out << fixed << setprecision(2) << m->data.numVal;
            // return out.str();
            tablestr += to_string(cell->data.numVal);
            break;
        case string_m:
            tablestr += "\"";
            tablestr += cell->data.strVal;
            tablestr += "\"";
            break;
        case bool_m:
            tablestr += (cell->data.boolVal == '1') ? "true" : "false";
            break;
        case table_m:
            tablestr += "[ ";
            tablestr += avm_printtable(cell->data.tableVal) + "]";
            break;
        case userfunc_m:
            tablestr += lookup_based_on_instr_addr(cell->data.funcVal);
            break;            
        case libfunc_m:
            tablestr += cell->data.libfuncVal;
            break;
        case nil_m:
            tablestr += "nil";
            break;
        case undef_m:
            tablestr += "undef";
            break;
        default:
            tablestr += "[]";
    }
    if (flag) tablestr += ", ";

    return tablestr;
}

string avm_printtable(const avm_table* table) {
    string tablestr;

    if (table == nullptr) {
        return "undef";
    }
    
    for (const auto& pair : table->indexedDouble) {
        tablestr += "{ "  + to_string((int)pair.first) + " : " + print_avm_memcell(pair.second, "", 0) + " }, ";
    }
    
    for (const auto& pair : table->indexedStrVal) {
        tablestr += "{ \""  + pair.first + "\" : " + print_avm_memcell(pair.second, "", 0) + " }, ";
    }
    tablestr = tablestr.substr(0, tablestr.size() - 2);

    return tablestr += " ";
}
