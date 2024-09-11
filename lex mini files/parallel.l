%{
#include <stdio.h>
#include <stdlib.h>
%}

identifier [a-zA-Z][a-zA-Z_0-9]*

%%
{identifier}\(\) { printf("function: %s, ", yytext); }
{identifier} { printf("identifier: %s, ", yytext); }
\. { printf("dot operator, "); }
[\ ] { printf("whitespace, "); }
\n { printf("Line Number Ended: %d\n", yylineno); }
. {yyerror("Invalid Character");}
%%

yyerror(char *s){
    fprintf(stderr, "%s\n", s);
}
int yywrap(){
    return 1;
}
int main(){
    yylex();
    return 0;
}