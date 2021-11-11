%code requires{
    #include "ast.h"
}

%{

    #include <cstdio>
    using namespace std;
    int yylex();
    extern int yylineno;
    void yyerror(const char * s){
        fprintf(stderr, "Line: %d, error: %s\n", yylineno, s);
    }

    #define YYERROR_VERBOSE 1
%}

%union{
  Expr * expr_t;
  float float_t;
  const char * string_t;
  StatementList * statement_list_t;
}

%token EOL
%token ADD SUB MUL DIV IF THEN ENDIF WHILE DO DONE ELSE LET
%token<string_t> TK_ID
%token<float_t>  TK_FLOAT
%type<expr_t> constant expression additive_expression multiplicative_expression relational_expression
%type<expr_t> primary_expression
%type<statement_list_t> statement_list input


%%
start: 
    | start additive_expression EOL
     ;





multiplicative_expression: multiplicative_expression MUL primary_expression { $$ = new MulExpr($1, $3); }
      | multiplicative_expression DIV primary_expression { $$ = new DivExpr($1, $3); }
      | primary_expression
      ;

additive_expression:  additive_expression ADD multiplicative_expression { $$ = new AddExpr($1, $3); }
                    | additive_expression SUB multiplicative_expression { $$ = new SubExpr($1, $3); }
                    | multiplicative_expression 
                    ;



primary_expression: constant 
    ;

constant: TK_FLOAT {$$ = new NumExpr($1);$$->evaluate();}
        ;





%%