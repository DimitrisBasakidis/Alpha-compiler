#include "grammar_functions.h"


int manage_break(void (*print_errors)(const char *, char *, const char *)) {
    if (in_loop == 0){
        print_errors("use of keyword outside of function", "break", "grammar");
        exit(TRUE);
    }
}

int manage_continue(void (*print_errors)(const char *, char *, const char *)) {
    if (in_loop == 0){
        print_errors("use of keyword outside of function", "continue", "grammar");
        exit(TRUE);
    }
}

int manage_increment(SymbolTableEntry *entry, char *token, void (*print_errors)(const char *, char *, const char *)) {
    if (entry != NULL && entry->type == USERFUNC || entry->type == LIBFUNC) {
          char *msg = (entry->type == USERFUNC) ? "cannot increment user function" : "cannot increment library function";
          print_errors(msg, token, "grammar");
          exit(TRUE); 
      }
}

int manage_decrement(SymbolTableEntry *entry, char *token, void (*print_errors)(const char *, char *, const char *)) {
    if (entry != NULL && entry->type == USERFUNC || entry->type == LIBFUNC) {
          char *msg = (entry->type == USERFUNC) ? "cannot decriment user function" : "cannot decriment library function";
          print_errors(msg, token, "grammar");
          exit(TRUE); 
      }
}

int manage_assignexpr(SymTable *symtable, scopeLists *lists, SymbolTableEntry *entry, char *token, void (*print_errors)(const char *, char *, const char *), int line) {
    
    if (entry == NULL) {
        if (from_func_call) {
        print_errors("accessing undefined function", token, "grammar");
        exit(TRUE); 
        }
        SymbolTableEntry *node = create_node(token, scope, line, (scope == 0) ? GLOBALVAR : LOCALVAR, ACTIVE);
        insert_symbol(symtable, node);
        insert_to_scope(lists, node, scope);
    } else {
        if ((func_in_between > 1 || entry->value.varVal->scope >= scope) && !global_val_exists) {

        switch (entry->type) {

            case LOCALVAR:
            if (entry->value.varVal->scope == scope) {
                if (is_local_kw == 1 && entry->value.varVal->line != line) {
                print_errors("redefinition of variable", token, "grammar");
                exit(TRUE); 
                }
            } else if (!for_loop && !while_loop) {
                print_errors("cant access local varible outside of scope", token, "grammar");
                exit(TRUE);  
            }
            break;

            case LIBFUNC:
            case USERFUNC: 
            if (from_func_call) break;

            char *msg = (entry->type == LIBFUNC) ? "redefining library function" : "redefining user function";
            print_errors(msg, token, "grammar");
            exit(TRUE); 

            case FORMAL:
            if (entry->value.varVal->scope != scope) {
                print_errors("cant access formal argument outside of scope", token, "grammar");
                exit(TRUE);
            }
            
        }
        } else if (entry->type == USERFUNC || entry->type == LIBFUNC) {
        char *temp = (entry->type == USERFUNC) ? "cannot assign value to user function" : "cannot assign value to library function";
        print_errors(temp, token, "grammar");
        exit(TRUE);
        }
    if (!global_val_exists) global_val_exists = 0;
  }
}




int manage_call(SymTable *symtable, scopeLists *lists, SymbolTableEntry *entry, char *token, void (*print_errors)(const char *, char *, const char *), int line) {
    SymbolTableEntry *temp = NULL;
    if (entry == NULL) {
        print_errors("calling undefined function:", token, "grammar");        
        exit(TRUE);  
     } else {

    switch (entry->type) {
      
      case LOCALVAR:
      case GLOBALVAR:

        temp = is_func(lists, token, scope);
        if (temp != NULL && temp->value.funcVal->scope <= scope) break;
        char *msg = (entry->type == LIBFUNC) ? "calling local variable as a function" : "calling global variable as a function";
        print_errors(msg, token, "grammar");
        exit(TRUE);  
    }
  };
}

SymbolTableEntry *manage_local_id(SymTable *symtable, scopeLists *lists, char *token, void (*print_errors)(const char *, char *, const char *), int line) {
    SymbolTableEntry *entry = lookup(symtable, lists, token, LOCALVAR, scope, SCOPE); 
    
    if (lookup_lib_func(token) == TRUE) {
        print_errors("shadowing library function:", token, "grammar");
        exit(TRUE);  
    }

    if (entry == NULL) {
        SymbolTableEntry *node = create_node(token, scope, line, (scope == 0) ? GLOBALVAR : LOCALVAR, ACTIVE);
        insert_symbol(symtable, node);
        insert_to_scope(lists, node, scope);
        node->space = currscopespace();  // dialeksh 9 slide 49 sto site tou pratikakh
        node->offset = currscopeoffset(); 
        incurrscopeoffset();
        return node;
    } else {
        if (entry->type == USERFUNC) {
            print_errors("redefining user function:", token, "grammar");
            exit(TRUE);  
        } else if (entry->type == FORMAL) {
            print_errors("redefining formal argument:", token, "grammar");
            exit(TRUE);
        }
    }

    return entry;
}

SymbolTableEntry *manage_double_colon_id(SymTable *symtable, scopeLists *lists, char *token, void (*print_errors)(const char *, char *, const char *)) {
    SymbolTableEntry *entry = lookup(symtable, lists, token, GLOBALVAR, 0, SCOPE); 
    
    if (entry == NULL) {
        print_errors("no global variable exists", token, "grammar");
        exit(TRUE);  
    } else global_val_exists = 1;

    return entry;
}

SymbolTableEntry *manage_function(SymTable *symtable, scopeLists *lists, char *token, void (*print_errors)(const char *, char *, const char *), int line) {
    SymbolTableEntry *entry = lookup(symtable, lists, token, USERFUNC, scope, SCOPE);

    if (entry == NULL) {
        SymbolTableEntry *node = create_node(token, scope, line, USERFUNC, ACTIVE);
        insert_symbol(symtable, node);
        insert_to_scope(lists, node, scope);
        printf("before: currenct scope space enum %d, current scope offset %d\n", currscopespace(), currscopeoffset());
        node->space = FUNC_SPACE;  // dialeksh 9 slide 49 sto site tou pratikakh
        node->offset = FUNC_SPACE; 
        // node-
        incurrscopeoffset();
        printf("after: currenct scope space enum %d, current scope offset %d\n", currscopespace(), currscopeoffset());

        return node;
    } else {

    char *print = NULL;
    switch (entry->type) {

      case LIBFUNC:
        print = "redefining library function";
        break;
      case USERFUNC: 
        print = "redefining user function";
        break;

      case GLOBALVAR:
        print = "redefining global variable";
        break; 

      case LOCALVAR: 
        print = "redefining local variable";
        break;
      case FORMAL:
        print = "redefining formal argument";
        break;

      default:
        print = "vaggeli agapiesai";  
        break;
    }

    print_errors(print, token, "grammar");
    exit(TRUE);
  }

  return entry;
}

int manage_lib_function(char *token, void (*print_errors)(const char *, char *, const char *)) {
    if (lookup_lib_func(token) == TRUE) {
        print_errors("shadowing lib function:", token, "grammar");
        exit(TRUE);
    }
}

int manage_id_list(SymTable *symtable, scopeLists *lists, SymbolTableEntry *entry_g, SymbolTableEntry *entry_l, char *token, void (*print_errors)(const char *, char *, const char *), int line) {
    if (entry_g != NULL && entry_g->value.varVal->scope != 0 && entry_g->type == USERFUNC) {
        print_errors("redefining argument", token, "grammar");
        exit(TRUE);
    } 

    if (entry_l != NULL) {
        print_errors("redefining argument", token, "grammar");
        exit(TRUE);
    } 
  
    SymbolTableEntry *node = create_node(token, scope + 1, line, FORMAL, ACTIVE);
    insert_symbol(symtable, node);
    insert_to_scope(lists, node, scope + 1);
    node->space = currscopespace();  // dialeksh 9 slide 49 sto site tou pratikakh
    node->offset = currscopeoffset(); 
    incurrscopeoffset();
}

int manage_return(void (*print_errors)(const char *, char *, const char *)) {
    if (func_in_between == 0){    
        print_errors("use of keyword outside of function", "return", "grammar");
        exit(TRUE);
    }
}

SymbolTableEntry *manage_id(SymTable *symtable, scopeLists *lists, char *token, int line, int scope, void (*print_errors)(const char *, char *, const char *)) {
    SymbolTableEntry *entry = NULL;
    int index = 0;

    assert(scope >= 0);

    for (index = scope; index >= 0; index--) {
        entry = lookup(symtable, lists, token, (index == 0) ? GLOBALVAR : LOCALVAR, index, SCOPE);

        if (entry != NULL) break;
    }

    if (entry == NULL) {
        SymbolTableEntry *node = create_node(token, scope, line, (scope == 0) ? GLOBALVAR : LOCALVAR, ACTIVE);
        insert_symbol(symtable, node);
        insert_to_scope(lists, node, scope);
        node->space = currscopespace();  // dialeksh 9 slide 49 sto site tou pratikakh
        node->offset = currscopeoffset(); 
        incurrscopeoffset();
        return node;
    }


    switch (entry->type) {

        case FORMAL: 
          if (entry->value.varVal->scope != index) {
            print_errors("calling formal argument outside of scope", token, "grammar");
            exit(TRUE);
          }

          if (entry->value.varVal->scope != scope) {
            print_errors("calling formal argument outside of scope", token, "grammar");
            exit(TRUE);
          }
          break;

        case LOCALVAR:
          if (entry->value.varVal->scope != scope && func_in_between != 0  && !for_loop && !if_stmt && !while_loop) {
            print_errors("calling local variable outside of scope", token, "grammar");
            exit(TRUE);
          }
          break;

    }

    return entry;
}

void lookup_func_id(SymTable *symtable, scopeLists *lists, expr *e, void (*print_errors)(const char *, char *, const char *)) {
    SymbolTableEntry *entry = lookup(symtable, lists, e->sym->value.varVal->name, 0, 0, HASH);

    if (entry != NULL && entry->type != USERFUNC && entry->type != LIBFUNC && e->type != programfunc_e && e->type !=libraryfunc_e) {
        //checking if var_e kai an einai tote peraiterw ktl paparies den prokeitai na ta kanoyme pote

        print_errors("calling undefined user function",  e->sym->value.varVal->name, "grammar");
        exit(0);
    }

}