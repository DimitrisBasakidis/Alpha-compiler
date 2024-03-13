%{

%}

%union {
  int int_val;
  char* id;
}

%token <int_val>  INTEGER
%token <id>       ID

%type <int_val>   expression

%destructor { free($$); } ID

%%

program:  assignments expressions {;}
          | {;}
          ;


%%

int main() {
  yyparse();

  return 0;
}
