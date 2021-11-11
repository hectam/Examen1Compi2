%option noyywrap
%option yylineno

%{
    #include "tokens.h"
%}
DIGIT [0-9]


%%
{DIGIT}+ { yylval.float_t = atoi(yytext); return TK_FLOAT; }
{DIGIT}+"."{DIGIT}+ { yylval.float_t = atof(yytext); return TK_FLOAT; }
[a-zA-Z]({DIGIT}|[a-zA-Z_0-9]|_)* { yylval.string_t = strdup(yytext); return TK_ID; }
"+" { return ADD; }
"=" { return '='; }
"-" { return SUB; }
"*" { return MUL; }
"/" { return DIV; }
"(" { return '('; }
")" { return ')'; }
"," { return ','; }
";" { return ';'; }
">" { return '>'; }
">" { return '<'; }
"let" { return LET; }
"while" { return WHILE; }
"do" { return DO; }
"done" { return DONE; }
[\n] { return EOL; }
[ \t] { /* ignorar */ }
. { printf("\ninvalido %c\n", yytext[0]); }
%%