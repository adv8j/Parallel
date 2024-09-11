%{
  #include "y.tab.h"
  void yyerror(const char *s);
%}

%%
/* Operators */
"="                 { return ASSIGN; }
"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return MUL; }
"/"                 { return DIV; }
"%"                 { return MOD; }
"=="                { return EQ; }
"!="                { return NEQ; }
">"                 { return GT; }
"<"                 { return LT; }
">="                { return GTE; }
"<="                { return LTE; }
"&&"                { return AND; }
"||"                { return OR; }
"!"                 { return NOT; }
"+="                { return ADD_ASSIGN; }
"-="                { return SUB_ASSIGN; }
"*="                { return MUL_ASSIGN; }
"/="                { return DIV_ASSIGN; }
"%="                { return MOD_ASSIGN; }

/*comments*/
"//".*            ;
"/*"([^*]|\*+[^/])*"*/"  ;

/* Symbols and Separators */
";"                 { return SEMICOLON; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"["                 { return LBRACKET; }
"]"                 { return RBRACKET; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
","                 { return COMMA; }
"."                 { return DOT; }
"->"                { return ARROW; }
".."                { return RANGE; }
"..="               { return RANGE_INCL; }
"\""                { return QUOTE; }
"<-"                { return CHN_SEND; }
"\\.wt"             { return CHANNEL_WAIT; }
"\\.ct"             { return TASK_CHANNEL; }
"log"               { return LOG; }

/* Number literals */
[0-9]+(\.[0-9]+)?   { yylval.number = atof(yytext); return NUMBER; }

/* Identifiers */
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.identifier = strdup(yytext); return IDENTIFIER; }

/* Whitespace and Newlines (ignored) */
[ \t\n]+            { /* Ignore whitespace */ }

/* Error Handling for invalid tokens */
.                   { printf("Invalid token: %s\n", yytext); return ERROR; }

%%

int yywrap(void) {
    return 1;
}
