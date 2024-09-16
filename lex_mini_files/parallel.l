%{
#include <stdio.h>
#include <stdlib.h>

// Declare the yyerror function
void yyerror(const char *s);
%}



%%
\"([^\\\"\n]|\\.)*\" printf("String literal");
%%

void yyerror(const char *s){
    fprintf(stderr, "%s\n", s);
}
int yywrap(){
    return 1;
}
int main(){
    yylex();
    return 0;
}