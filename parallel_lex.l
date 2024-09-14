%{
#include "y.tab.h"
%}

%%

=                 { return ASSIGN;   /*operators*/ }
\+                 { return PLUS; }
\-               { return MINUS; }
\*                 { return MUL; }
\/                 { return DIV; }
\%                 { return MOD; }
==                { return EQ; }
!=                { return NEQ; }
>                 { return GT; }
\<                 { return LT; }
>=                { return GTE; }
\<=                { return LTE; }
\&&               { return AND; }
\|\|               { return OR; }
\!                { return NOT; }
\+=                { return ADD_ASSIGN; }
\-=                { return SUB_ASSIGN; }
\*=                { return MUL_ASSIGN; }
\/=                { return DIV_ASSIGN; }
\%=                { return MOD_ASSIGN; }


"//".*           {/*comments*/ printf("single line comment");} 
"/*"([^(\*\/)])*"*/"  printf("multi line comment");


\;                 { return SEMICOLON; /* Symbols and Separators */}
\:                 { return COLON; /* will be useful for type inference at many places, like shared variables and all.*/} 
\(                 { return LPAREN; }
\)                 { return RPAREN; }
\[                 { return LBRACKET; }
\]                 { return RBRACKET; }
\{                 { return LBRACE; }
\}                 { return RBRACE; }
\,                 { return COMMA; }
\.                 { return DOT; }
\.\.                { return RANGE; }
\..=               { return RANGE_INCL; } 
\"                { return QUOTE; }
\&                { return REFERENCE; }


[0-9]+(\.[0-9]+)?   { return NUMBER; }
\"([^"(\\\")\n]*(\\\")?)*\"        { return STRING_LITERAL; } 
\'.\'        { return CHARACTER;}

@TaskGroup  {return TASKGROUP;}
@Task      {return TASK;}
@Properties {return PROPERTIES;}
@Order   {return ORDER;}
@Channel {return CHANNEL;}
@Mem    {return MEM;}
@Shared {return _SHARED;}
@Supervisor {return SUPERVISOR;}
all {return ALL;}
unsafe {return UNSAFE;}
join {return JOIN; /* note that now join is a keyword called as join tid;*/ }  
call      {return CALL;}

\<-                { return CHN_SEND; }
\.wt             { return CHANNEL_WAIT; }
\.ct             { return TASK_CHANNEL; }
log               { return LOG;  /*what should we do about k*/}
\->                { return ARROW; }

@parallel {return PARALLEL;}
shared {return SHARED;}
private {return PRIVATE;}
reduction {return REDUCTION;}
schedule {return SCHEDULE;}
num_threads {return NUM_THREADS;}
dynamic {return DYNAMIC_SCHEDULE;}
static {return STATIC_SCHEDULE;}
mut {return MUT;}

int {return INT;}
char {return CHAR;}
long {return LONG;}
bool {return BOOL;}
float {return FLOAT;}
string {return STRING;}

func {return FUNC;}
return {return RETURN;}
struct {return STRUCT;}
if {return IF;}
else {return ELSE;}
for {return FOR;}
in {return IN;}


[a-zA-Z][a-zA-Z0-9_]*  { return IDENTIFIER; }
[a-zA-Z0-9_]+ {return SHARED_IDENTIFIER; /*dont shared variables always start with an underscore*/}

[ \t\n]+            { /* Ignore whitespace */ }

.                   { yyerror("Syntax Error!!!"); }

%%

void yyerror(const char *s){
    fprintf(stderr, "%s\n", s);
}


int yywrap(void) {
    return 1;
}


int main(){

    /*also shouldn't we give something like scanf and printf and also handle the format specifiers*/
    while(1)
        yylex();
    return 0;
}