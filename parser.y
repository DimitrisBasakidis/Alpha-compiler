%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "grammatical_rules/grammar_functions.h"

#include "utilities/quads.h"

#include "utilities/elist.h"

#define YYERROR_VERBOSE 1

int yylex(void);
void yyerror(const char *error_msg);
void print_errors(const char *error_msg, char *token, const char *error_type);
const char *file_name;

quad* quads = (quad*)0;
unsigned total = 0;
unsigned int currQuad = 0;

int scope = 0;
int func_in_between = 0;
int is_return_kw = 0;
int from_func_call = 0;
int in_loop = 0;
int from_elist = 0;
int while_loop = 0;
int for_loop = 0;
int if_stmt = 0;
int global_val_exists = 0;
int is_local_kw = 0;
int boolflag = 0;

unsigned programVarOffset = 0;
unsigned functionLocalOffset = 0;
unsigned formalArgOffset = 0;
unsigned scopeSpaceCounter = 1;

int temp_count = 0;

extern int yylineno;
extern char *yytext;
extern FILE *yyin;

extern int column;
extern char *lineptr;

SymTable *symtable;
scopeLists *lists;
scope_stack *stack;
scope_stack *loop_stack;
scope_stack *func_scopes;

size_t nfuncs = 0U;
SymbolTableEntry *entry;

%}

%union {
  int int_val;
  char *str_val;
  float real_val;
  struct expr *ex;
  struct call_t *elist_call;
  struct stmt_t* statement_struct;
  struct SymbolTableEntry *symbol;
  struct forstruct_t *forprefix_struct;
  struct indexed_list_t *indexedlist_node;

}

%token <int_val>  INTEGER
%token <str_val>  ID STRING
%token <real_val> REAL

%right ASSIGN
%left OR
%left AND
%nonassoc EQUAL NOT_EQUAL
%nonassoc GREATER_THAN GREATER_EQUAL LESSER_THAN LESSER_EQUAL LOWER_THAN_ELSE 
%left PLUS MINUS
%left MULTIPLY SLASH MODULO
%right UMINUS NOT INCREMENT DECREMENT
%left DOT DOUBLE_DOT
%left LEFT_SQUARE_BRACKET RIGHT_SQUARE_BRACKET
%left LEFT_PARENTHESIS RIGHT_PARENTHESIS
%token SEMICOLON LEFT_BRACKET RIGHT_BRACKET COMMA COLON DOUBLE_COLON
%token IF ELSE WHILE FOR FUNCTION RETURN_KW BRK CONTINUE LOCAL TRUE_KW FALSE_KW ENDL NIL

%type <ex> lvalue call const member primary assignexpr term objectdef expr elist tablemake tableitem 
%type <symbol> funcprefix funcdef
%type <str_val> funcname 
%type <int_val> funcbody ifprefix elseprefix open_while whilecond N M N_right_par
%type <elist_call> callsuffix normcall methodcall
%type <indexedlist_node> indexedelem indexed
%type <str_val> idlist
%type <statement_struct> loopstmt statements stmt ifstmt block whilestmt forstmt returnstmt
%type <forprefix_struct> forprefix

%%


program: statements {}
      | {;}
       ;

statements: statements stmt {
        resettemp();
        $$ = malloc(sizeof(struct stmt_t));
        int brk_statemenets = 0, brk_stmt = 0;
        int cont_statements = 0, cont_stmt = 0;

        if ($1) {
          brk_statemenets = $1->breakList;
          cont_statements = $1->contList;
        }

        if ($2) {
          brk_stmt = $2->breakList;
          cont_stmt = $2->contList;
        }

        $$->breakList = mergelist(brk_statemenets, brk_stmt);
        $$->contList = mergelist(cont_statements , cont_stmt);
  }
| stmt { resettemp();   $$ = $1; };

stmt: expr SEMICOLON {  
          $$ = make_stmt($$);
          if (boolflag !=1) $1 = manage_bool_expr($1,symtable,lists,scope,yylineno);
          boolflag = 0;
        }
| ifstmt     { $$ = $1; }
| whilestmt  { $$ = NULL; }
| forstmt    { $$ = NULL; }
| returnstmt { $$ = $1; }
| BRK SEMICOLON 
            { 
            manage_break(print_errors);
            $$ = make_stmt($$);
            $$->breakList = newlist(nextquadlabel()); 
            emit(jump,NULL,NULL,NULL,0,yylineno);   
            }      
| CONTINUE SEMICOLON 
            {
              manage_continue(print_errors);
              $$ = make_stmt($$);
              $$->contList = newlist(nextquadlabel()); 
              emit(jump,NULL,NULL,NULL,0,yylineno);
            }
| block      { $$ = $1;}
| funcdef    { $$ = NULL; }
| SEMICOLON  { $$ = NULL; }
      ;

expr: assignexpr {$$ = $1;}
    | expr PLUS expr {
      // diafaneia 5 dialeksh 3 
      check_expr($1,$3,print_errors);
      $$ = create_and_emit_arith_expr(symtable,lists,scope,yylineno,$1,$3,add);
    }
    | expr MINUS expr {
      check_expr($1,$3,print_errors);
      $$ = create_and_emit_arith_expr(symtable,lists,scope,yylineno,$1,$3,sub);
    }
    | expr MULTIPLY expr {
      check_expr($1,$3,print_errors);
      $$ = create_and_emit_arith_expr(symtable,lists,scope,yylineno,$1,$3,mul);
    }
    | expr SLASH expr {
      check_expr($1,$3,print_errors);
      $$ = create_and_emit_arith_expr(symtable,lists,scope,yylineno,$1,$3,divide);
    }
    | expr MODULO expr {
      check_expr($1,$3,print_errors);
      $$ = create_and_emit_arith_expr(symtable,lists,scope,yylineno,$1,$3,mod);
    }
    | expr GREATER_THAN expr {
      $$ = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      $$->trueList = newlist(nextquadlabel());
      $$->falseList = newlist(nextquadlabel() + 1);
      emit(if_greater,NULL,$1,$3,0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
    | expr GREATER_EQUAL expr {
      $$ = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      $$->trueList = newlist(nextquadlabel());
      $$->falseList = newlist(nextquadlabel() + 1);
      emit(if_greatereq,NULL,$1,$3,0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
    | expr LESSER_THAN expr {
      $$ = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      $$->trueList = newlist(nextquadlabel());
      $$->falseList = newlist(nextquadlabel() + 1);
      emit(if_less,NULL,$1,$3,0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
    | expr LESSER_EQUAL expr {
      $$ = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      $$->trueList = newlist(nextquadlabel());
      $$->falseList = newlist(nextquadlabel() + 1);
      emit(if_lesseq,NULL,$1,$3,0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
    | expr EQUAL { $1 = manage_bool_expr($1,symtable,lists,scope,yylineno); } expr {
      $4 = manage_bool_expr($4,symtable,lists,scope,yylineno);
      $$ = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      $$->trueList = newlist(nextquadlabel());
      $$->falseList = newlist(nextquadlabel() + 1);
      emit(if_eq,NULL,$1,$4,0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
    | expr NOT_EQUAL { $1 = manage_bool_expr($1,symtable,lists,scope,yylineno); } expr {
      $4 = manage_bool_expr($4,symtable,lists,scope,yylineno);
      $$ = create_expr(boolexpr_e, NULL, NULL, 0, NULL, '\0');
      $$->trueList = newlist(nextquadlabel());
      $$->falseList = newlist(nextquadlabel() + 1);
      emit(if_noteq,NULL,$1,$4,0,yylineno);
      emit(jump,NULL,NULL,NULL,0,yylineno);
    }
    | expr AND { $1 = do_bool($1,yylineno); } M expr {
      $$ = create_expr(boolexpr_e, NULL , NULL, 0.0f, NULL, '\0');
      $5 = do_bool($5,yylineno);
      patchlist($1->trueList,$4);
      $$->trueList = $5->trueList;
      $$->falseList = mergelist($1->falseList,$5->falseList);
    }
    | expr OR { $1 = do_bool($1,yylineno); } M expr {
      $$ = create_expr(boolexpr_e, NULL, NULL, 0.0f, NULL, '\0');
      $5 = do_bool($5,yylineno);
      patchlist($1->falseList,$4);
      $$->trueList = mergelist($1->trueList,$5->trueList);
      $$->falseList = $5->falseList;
    }
    | term {$$=$1;}


term: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS {$$ = $2;}
| MINUS expr { $$ = create_and_emit_arith_expr(symtable,lists,scope,yylineno,$2,NULL,uminus); } %prec UMINUS
| NOT expr { $2 = do_bool($2,yylineno); 
            $$ = $2;
            int tmp = $$->trueList;
            $$->trueList = $2->falseList;
            $$->falseList = tmp;
          }
| INCREMENT lvalue { 
  manage_increment(symtable, lists, $2->sym->value.varVal->name, print_errors);
  check_arith($2, "++lvalue");
  if ($2->type == tableitem_e) {
    $$ = emit_iftableitem($2, symtable, lists, scope, yylineno);
    emit(add, $$, newexpr_constnum(1), $$, 0, yylineno);
    emit(tablesetelem, $2, $2->index, $$, 0, yylineno);
  } else {
    emit(add, $2, newexpr_constnum(1), $2, 0, yylineno);
    $$ = create_expr(arithexpr_e, newtemp(symtable, lists, scope, yylineno), $2, 0.0f, NULL, '\0');
    emit(assign, $2, NULL, $$, 0, yylineno);
  }
}
| lvalue INCREMENT {
  
  manage_increment(symtable, lists, $1->sym->value.varVal->name, print_errors);
  check_arith($1, "lvalue++");
  $$ = create_expr(var_e, newtemp(symtable, lists, scope, yylineno), $1, 0.0f, NULL, '\0');
  if ($1->type == tableitem_e) {
    expr *val = emit_iftableitem($1, symtable, lists, scope, yylineno);
    emit(assign, val, NULL, $$, 0, yylineno);
    emit(add, val, newexpr_constnum(1), val, 0, yylineno);
    emit(tablesetelem, $1, $1->index, val, 0, yylineno);
  } else {
    emit(assign, $1, NULL, $$, 0, yylineno);
    emit(add, $1, newexpr_constnum(1), $1, 0, yylineno);
  }
  
}
| DECREMENT lvalue {
  manage_decrement(symtable, lists, $2->sym->value.varVal->name, print_errors);
  check_arith($2, "--lvalue");
  if ($2->type == tableitem_e) {
    $$ = emit_iftableitem($2, symtable, lists, scope, yylineno);
    emit(add, $$, newexpr_constnum(1), $$, 0, yylineno);
    emit(tablesetelem, $2, $2->index, $$, 0, yylineno);
  } else {
    emit(add, $2, newexpr_constnum(1), $2, 0, yylineno);
    $$ = create_expr(arithexpr_e, newtemp(symtable, lists, scope, yylineno), $2, 0.0f, NULL, '\0');
    emit(assign, $2, NULL, $$, 0, yylineno);
  }
}
| lvalue DECREMENT {

  manage_decrement(symtable, lists, $1->sym->value.varVal->name, print_errors);
  check_arith($1, "lvalue--");
  $$ = create_expr(var_e, newtemp(symtable, lists, scope, yylineno), $1, 0.0f, NULL, '\0');
  if ($1->type == tableitem_e) {
    expr *val = emit_iftableitem($1, symtable, lists, scope, yylineno);
    emit(assign, val, NULL, $$, 0, yylineno);
    emit(sub, val, newexpr_constnum(1), val, 0, yylineno);
    emit(tablesetelem, $1, $1->index, val, 0, yylineno);
  } else {
    emit(assign, $1, NULL, $$, 0, yylineno);
    emit(sub, $1, newexpr_constnum(1), $1, 0, yylineno);
  }
}
| primary { $$ = $1;}
; 


assignexpr: lvalue ASSIGN expr {
  $$ = $3;
  if($1->type == tableitem_e){
      emit(tablesetelem,$1,$1->index,$3,0,yylineno);
      $$ = emit_iftableitem($1,symtable,lists,scope,yylineno);
      $$->type = assignexpr_e;
  }else{
    expr* new = manage_bool_expr($3,symtable,lists,scope,yylineno);
    emit(assign, $1, new, NULL, 0, yylineno);
    expr* tmp = NULL ;
    tmp = lvalue_expr(newtemp(symtable, lists, scope, yylineno));
    emit(assign, tmp,$1, NULL, 0, yylineno);
    boolflag = 1;
  }
  is_local_kw = 0;
  if (from_func_call > 0) from_func_call--;
} 
;

primary: lvalue { 
  $$ = emit_iftableitem($1, symtable, lists, scope, yylineno);
  is_return_kw = 0;
  if (from_elist) from_elist = 0;
}
| call { 
  entry = lookup(symtable, lists, $1->sym->value.varVal->name, (lookup_lib_func($1->sym->value.varVal->name) == TRUE) ? LIBFUNC : USERFUNC , scope, HASH);
  manage_call(symtable, lists, entry, $1->sym->value.varVal->name, print_errors, yylineno);
}
| objectdef {;}
| LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS {$$ = create_expr(programfunc_e,$2,0,0,"",'\0');} // gia na briskei tis unnamed functions
| const { $$ = $1;}
;


lvalue: ID {
  entry = manage_id(symtable, lists, $1, yylineno, scope, (peek(func_scopes) != NULL) ? peek(func_scopes)->x : -1, print_errors);
  $$ = lvalue_expr(entry);
} 

| LOCAL ID { // kanoume lookup sto trexon scope kai ama einai libfunction tote exoyme shadowing kai meta ama einai null tote to vazoume sto table 
  is_local_kw = 1;

  entry = manage_local_id(symtable, lists, $2, print_errors, yylineno);
  $$ = lvalue_expr(entry);
}

| DOUBLE_COLON ID { 
  entry = manage_double_colon_id(symtable, lists, $2, print_errors);
  $$ = lvalue_expr(entry);
}
| member {$$=$1;}
| tableitem  {$$ = $1;}
;

tableitem: lvalue DOT ID { $$ = member_item($1,$3,symtable,lists,scope,yylineno); }
| lvalue LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET{
  $1 = emit_iftableitem($1, symtable, lists, scope, yylineno);
  $$ = create_expr(tableitem_e, $1->sym, $3, 0.0f, NULL, '\0');
};

member: call DOT ID {from_func_call++;}
      | call LEFT_SQUARE_BRACKET expr RIGHT_SQUARE_BRACKET {;}
      ;

call: call LEFT_PARENTHESIS {from_elist = 1; } elist RIGHT_PARENTHESIS {
  $$ = make_call($1, reverse_elist($4),yylineno,symtable,lists,scope);
  
}
| lvalue callsuffix {
    $1 = emit_iftableitem($1,symtable,lists,scope,yylineno);
    if ($2->method) {
      expr* last = get_last($2->elist);
    
      if(last == NULL){
        $2->elist = $1;
      }else{
        last->next = $1;
      }
      $1 = emit_iftableitem(member_item($$, $2->name,symtable,lists,scope,yylineno),symtable,lists,scope,yylineno);
    }
    $$ = make_call($1, reverse_elist($2->elist) ,yylineno, symtable, lists, scope);
  }
| LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
  expr* func = create_expr(programfunc_e, $2, NULL, 0.0f, NULL, '\0'); 
  $$ = make_call(func, reverse_elist($5), yylineno, symtable, lists, scope);
};

callsuffix: normcall {$$ = $1;}
          | methodcall {$$ = $1;};

normcall: LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
  $$ = malloc(sizeof(struct call_t));
  $$->elist = $2;
  $$->method = 0;
  $$->name = NULL;
};

methodcall: DOUBLE_DOT ID LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
  $$ = malloc(sizeof(struct call_t));
  $$->elist = $4;
  $$->method = 1;
  $$->name = strdup($2);
};

elist: expr { $$->next = NULL; $$ = manage_bool_expr($1,symtable,lists,scope,yylineno); }
| expr COMMA elist { $1->next = $3; $$=$1; }
| { $$ = NULL;};

objectdef: tablemake {;};

tablemake: LEFT_SQUARE_BRACKET elist RIGHT_SQUARE_BRACKET {
  expr* t = create_expr(newtable_e, newtemp(symtable, lists, scope, yylineno), NULL, 0.0f, NULL, '\0');
  emit(tablecreate, t, NULL, NULL, 0, yylineno);
  expr *tmp = $2;
  for (int i = 0; tmp; tmp = tmp->next) {
    
    emit(tablesetelem, t, newexpr_constnum(i++), tmp, 0, yylineno);
  }
  $$ = t;
};
  | LEFT_SQUARE_BRACKET indexed RIGHT_SQUARE_BRACKET  {
        expr* t = create_expr(newtable_e,NULL,NULL,0.0f,"",'\0');
        t->sym = newtemp(symtable,lists,scope,yylineno);
        emit(tablecreate,t,NULL,NULL,0,yylineno);
        indexed_list_t *tmp = $2;
        while(tmp!=NULL){
          emit(tablesetelem,t,tmp->index,tmp->value,0,yylineno);
          tmp = tmp->next;
        }
        $$ = t;
    }
    ;

indexed: indexedelem {$$ = $1; $$->next = NULL;}
       | indexedelem COMMA indexed {$1->next = $3; $$=$1;}
       |{$$ = NULL;}
       ;

indexedelem: LEFT_BRACKET expr COLON expr RIGHT_BRACKET {$$ = create_indexlist_node($2,$4); $4 = manage_bool_expr($4,symtable,lists,scope,yylineno);}
           ;


block: LEFT_BRACKET {scope++;  } statements RIGHT_BRACKET { hide_scope(lists, scope--); $$ = $3; }
     | LEFT_BRACKET {scope++;} RIGHT_BRACKET {hide_scope(lists, scope--); $$ = NULL;}
     ;

funcname: ID { $$ = $1;}
        | {
          unsigned int count = 0, n = nfuncs;
          while (n != 0) { n /= 10; count++;}
          char *temp = malloc(sizeof(char) * nfuncs + 6);
          sprintf(temp , "_func_%u", (unsigned int) nfuncs++);
          $$ = temp;
          }
        ;

funcprefix: FUNCTION funcname { // elegxoume ama uparxoyn ta entries sto hashtable kai einai active, an nai ektypwnoyme ta katallhla error messages
// alliws ta vazoume sto table
  
  $$ = manage_function(symtable, lists, $2, print_errors, yylineno);
  /* gia tin epomenh fash */ 
  emit(jump, NULL, NULL, NULL, 0, yylineno); // GOTO
  //$$->iaddress = nextquadlabel();// deixnei sto funcstart command tou quad poy antistoixei sthn sunarthsh poy orizetai
  emit(funcstart, lvalue_expr($$), NULL, NULL, 0, 0);
  push(stack, currscopeoffset());
  enterscopespace();
  resetformalargsoffset();
};

funcargs: idlist  { enterscopespace(); resetfunctionlocaloffset(); }
                | { enterscopespace(); resetfunctionlocaloffset(); };

funcbody: block { $$ = currscopeoffset(); exitscopespace(); };

funcblockstart: { push(func_scopes, scope); push(loop_stack, in_loop); in_loop = 0; }

funcblockend: { scopestack_t *temp = pop(loop_stack); pop(func_scopes); in_loop = temp->x; }

funcdef: funcprefix LEFT_PARENTHESIS funcargs RIGHT_PARENTHESIS { func_in_between++; } funcblockstart funcbody funcblockend {
  exitscopespace();
  $$->total_locals = $7;
  scopestack_t *temp = pop(stack);
  int offset = temp->x;
  restorecurrentscopeoffset(offset);
  $$ = $1;
  emit(funcend, lvalue_expr($1), NULL, NULL, 0, 0);
  
  func_in_between--;
};

const: INTEGER {$$ = create_expr(constnum_e, NULL, NULL, $1, "vaggelis", '\0');} 
     | REAL { $$ = create_expr(constnum_e, NULL, NULL, $1, "", '\0');} 
     | STRING { $$ = create_expr(conststring_e, NULL, NULL, 0, $1, '\0');} 
     | NIL {$$ = create_expr(nil_e, NULL, NULL, 0, "lempesis", '\0');} 
     | TRUE_KW {$$ = create_expr(constbool_e, NULL, NULL, 0, "", '1');}
     | FALSE_KW {$$ = create_expr(constbool_e, NULL, NULL, 0, "", '0');}
     ;

idlist_id: ID { 

  SymbolTableEntry *entry_l = NULL;

  manage_lib_function($1, print_errors);

  entry = lookup(symtable, lists, $1, GLOBALVAR, scope, SCOPE);
  entry_l = lookup(symtable, lists, $1, FORMAL, scope + 1, SCOPE);
  
  manage_id_list(symtable, lists, entry, entry_l, $1, print_errors, yylineno);
};

open_while: WHILE {while_loop++; $$ = nextquadlabel();};

whilecond: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS
    { 
      $2 = manage_bool_expr($2,symtable,lists,scope,yylineno);
      emit(if_eq,$2,create_expr(constbool_e,NULL,NULL,0.0f,"",'1'),NULL,nextquadlabel()+2,yylineno);
      $$ = nextquadlabel();
      emit(jump,NULL,NULL,NULL,0,yylineno);
    };

ifprefix :  IF  { if_stmt++; } LEFT_PARENTHESIS expr RIGHT_PARENTHESIS {
        $4 = manage_bool_expr($4,symtable,lists,scope,yylineno);
        emit (if_eq, $4, create_expr(constbool_e,NULL,NULL,0.0f,"",'1'),NULL,nextquadlabel() + 2, yylineno);
        $$ = nextquadlabel();
        emit(jump,NULL,NULL,NULL,0,yylineno);
      };

elseprefix : ELSE { $$ = nextquadlabel(); emit(jump,NULL,NULL,NULL,0,yylineno);}

idlist: idlist_id {;}
      | idlist_id COMMA idlist {;}
      ;

ifstmt: ifprefix stmt { if_stmt--; patchlabel($1,nextquadlabel()); $$=$2; } %prec LOWER_THAN_ELSE 
      | ifprefix stmt elseprefix stmt 
      { 
        if_stmt--;
        $$ = make_stmt($$);
        patchlabel($1,$3+1);
        patchlabel($3,nextquadlabel());
        fflush(stdout);
        
        int brk_statemenets = 0, cont_statements = 0;
        int brk_stmt = 0, cont_stmt = 0;

        if($2){
          brk_statemenets = $2->breakList;
          if($4) cont_statements = $4->contList;
        }

        if($4){
          brk_stmt = $4->breakList;
          if($2) cont_stmt = $2->contList;
        }

        $$->breakList = mergelist(brk_statemenets, brk_stmt);
        $$->contList = mergelist(cont_statements , cont_stmt);
      };

loopstart: { in_loop++; };

loopend: { in_loop--; };

loopstmt: loopstart stmt loopend { $$ = $2; };

whilestmt: open_while whilecond loopstmt {
                                      in_loop--; while_loop--;
                                      emit(jump,NULL,NULL,NULL,$1,yylineno);
                                      patchlabel($2,nextquadlabel());
                                      if($3) {patchlist($3->breakList,nextquadlabel()); //$3->breaklist: index tou quad opou briskontai ta breaks, nextquadlabel(): quad label opou bazoume ta brakes na deixnoun 
                                            patchlist($3->contList,$1);}
                                      } 
         ;

N: {$$ = nextquadlabel(); emit(jump,NULL,NULL,NULL,0,yylineno);}
M: {$$ = nextquadlabel();}

forprefix : FOR {for_loop++; in_loop++; } LEFT_PARENTHESIS elist SEMICOLON M expr SEMICOLON {
              $$ = malloc(sizeof(struct forstruct_t));
              $7 = manage_bool_expr($7,symtable,lists,scope,yylineno);
              $$->test = $6;
              $$->enter = nextquadlabel();
              emit(if_eq,$7,create_expr(constbool_e,NULL,NULL,0.0f,"",'1'),NULL,0,yylineno);
          }
          ;

N_right_par: RIGHT_PARENTHESIS N { $$ = $2; };

forstmt: forprefix N elist N_right_par loopstmt { in_loop--; for_loop--;} N {
  $$ = make_stmt($$);
  patchlabel($1->enter,$4+1);
  patchlabel($2,nextquadlabel());
  patchlabel($4,$1->test);
  patchlabel($7,$2 +1);
  
  if ($5) patchlist($5->breakList,nextquadlabel());
  if ($5) patchlist($5->contList,$2+1);
};

returnstmt: RETURN_KW { manage_return(print_errors); } SEMICOLON {emit(ret,NULL,NULL,NULL,0,0);
                                      $$ = make_stmt($$);
                                      emit(jump,NULL,NULL,NULL,0,yylineno);
                                    }
| RETURN_KW { manage_return(print_errors); } expr SEMICOLON { emit(ret,$3,NULL,NULL,0,0); is_return_kw = 1; 
                                  $3 = manage_bool_expr($3,symtable,lists,scope,yylineno);
                                  $$ = make_stmt($$);
                                  emit(jump,NULL,NULL,NULL,0,yylineno);
                                }

%%

void yyerror(const char *error_msg) {
  print_errors(yylval.str_val, yytext, "syntax");
  exit(0);
}

void print_errors(const char *error_msg, char *token, const char *error_type) {
  int count = 1;
  int temp = yylineno;

  printf("%p, %p\n", error_msg, token);
  fflush(stdout);

  fprintf(stderr, "%s:%d ",file_name + 1, yylineno);
  printf("\033[31merror:\033[0m %s\n", error_type);   

  while (temp) {temp /= 10; count++;}; 
  if (error_msg == NULL) {
    printf("  %d | ",yylineno);
  } else {
    printf("  %d | %s",yylineno, error_msg);
  }
  printf("\033[31m");
  printf(" %s", token);
  printf("\033[0m\n");
  printf("%*s|", count + 2, "");
  if (error_msg != NULL) {
    for (int i = 0; i < strlen(error_msg) + 2; i++) printf(" ");
    printf("\033[31m^\033[0m");
    if (strlen(token) > 1) {
      for (int i = 0; i < strlen(token) - 1; i++) printf("\033[31m~\033[0m");
    }
  }
  
  printf("\n%*s|\n", count + 2, "");
}

int main(int argc, char **argv) {

  FILE* fptr = NULL;

  if (argc > 1) {
    if (!(yyin = fopen(argv[1], "r"))) {
      perror("Cant open file"); 
      return 1;
    }
  }

  if (argc == 3) {
    fptr = fopen(argv[2], "wb+");
    if (fptr == NULL) {
      perror("error opening file");
      exit(-1);
    }
  }

  file_name = strrchr(argv[1], '/');

  lists = create_scope_lists();
  symtable = create_table();
  stack = create_scope_stack();
  loop_stack = create_scope_stack();
  func_scopes = create_scope_stack();

  emit(jump,NULL,NULL,NULL,1,0);

  add_lib_func(symtable, lists);
  yyparse();
  
  print_scopes(lists, (fptr == NULL) ? stdout : fptr);

  fprintf((fptr == NULL) ? stdout : fptr, "\n\n\n");

  print_quads((fptr == NULL) ? stdout : fptr);

  free_table(symtable);

  return 0;
}
