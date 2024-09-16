%{
#include "y.tab.h"
#include <stdio.h>

void yyerror(char *s);

FILE *output_file;
%}

%%

=                 { fprintf(output_file,"ASSIGN\n");return ASSIGN;   /*operators*/ }
\+                 { fprintf(output_file,"PLUS\n");return PLUS; }
\-               { fprintf(output_file,"MINUS\n");return MINUS; }
\*                 { fprintf(output_file,"MUL\n");return MUL; }
\/                 { fprintf(output_file,"DIV\n");return DIV; }
\%                 { fprintf(output_file,"MOD\n");return MOD; }
==                { fprintf(output_file,"EQ\n");return EQ; }
!=                { fprintf(output_file,"NEQ\n");return NEQ; }
>                 { fprintf(output_file,"GT\n");return GT; }
\<                 { fprintf(output_file,"LT\n");return LT; }
>=                { fprintf(output_file,"GTE\n");return GTE; }
\<=                { fprintf(output_file,"LTE\n");return LTE; }
\&&               { fprintf(output_file,"AND\n");return AND; }
\|\|               { fprintf(output_file,"OR\n");return OR; }
\!                { fprintf(output_file,"NOT\n");return NOT; }
\+=                { fprintf(output_file,"ADD_ASSIGN\n");return ADD_ASSIGN; }
\-=                { fprintf(output_file,"SUB_ASSIGN\n");return SUB_ASSIGN; }
\*=                { fprintf(output_file,"MUL_ASSIGN\n");return MUL_ASSIGN; }
\/=                { fprintf(output_file,"DIV_ASSIGN\n");return DIV_ASSIGN; }
\%=                { fprintf(output_file,"MOD_ASSIGN\n");return MOD_ASSIGN; }


"//".*           {/*comments*/ fprintf(output_file,"single line comment\n");} 
"/*"([^(\*\/)])*"*/"  fprintf(output_file,"multi line comment\n");


\;                 { fprintf(output_file,"SEMICOLON\n");return SEMICOLON; /* Symbols and Separators */}
\:                 { fprintf(output_file,"COLON\n");return COLON; /* will be useful for type inference at many places, like shared variables and all.*/} 
\(                 { fprintf(output_file,"LPAREN\n");return LPAREN; }
\)                 { fprintf(output_file,"RPAREN\n");return RPAREN; }
\[                 { fprintf(output_file,"LBRACKET\n");return LBRACKET; }
\]                 { fprintf(output_file,"RBRACKET\n");return RBRACKET; }
\{                 { fprintf(output_file,"LBRACE\n");return LBRACE; }
\}                 { fprintf(output_file,"RBRACE\n");return RBRACE; }
\,                 { fprintf(output_file,"COMMA\n");return COMMA; }
\.                 { fprintf(output_file,"DOT\n");return DOT; }
\.\.                { fprintf(output_file,"RANGE\n");return RANGE; }
\..=               { fprintf(output_file,"RANGE_INCL\n");return RANGE_INCL; } 
\"                { fprintf(output_file,"QUOTE\n");return QUOTE; }
\&                { fprintf(output_file,"REFERENCE\n");return REFERENCE; }


[0-9]+(\.[0-9]+)?   { fprintf(output_file,"NUMBER\n");return NUMBER; }
\"([^"(\\\")\n]*(\\\")?)*\"        { fprintf(output_file,"STRING_LITERAL\n");return STRING_LITERAL; } 
\'.\'        { fprintf(output_file,"CHARACTER\n");return CHARACTER;}

@TaskGroup  {fprintf(output_file,"TASKGROUP\n");return TASKGROUP;}
@Task      {fprintf(output_file,"TASK\n");return TASK;}
@Properties {fprintf(output_file,"PROPERTIES\n");return PROPERTIES;}
@Order   {fprintf(output_file,"ORDER\n");return ORDER;}
@Channel {fprintf(output_file,"CHANNEL\n");return CHANNEL;}
@Mem    {fprintf(output_file,"MEM\n");return MEM;}
@Shared {fprintf(output_file,"_SHARED\n");return _SHARED;}
@Supervisor {fprintf(output_file,"SUPERVISOR\n");return SUPERVISOR;}
all {fprintf(output_file,"ALL\n");return ALL;}
unsafe {fprintf(output_file,"UNSAFE\n");return UNSAFE;}
join {fprintf(output_file,"JOIN\n");return JOIN; /* note that now join is a keyword called as join tid;*/ }  
call      {fprintf(output_file,"CALL\n");return CALL;}

\<-                { fprintf(output_file,"CHN_SEND\n");return CHN_SEND; }
\.wt             { fprintf(output_file,"CHANNEL_WAIT\n");return CHANNEL_WAIT; }
\.ct             { fprintf(output_file,"TASK_CHANNEL\n");return TASK_CHANNEL; }
log               { fprintf(output_file,"LOG\n");return LOG;  /*what should we do about k*/}
\->                { fprintf(output_file,"ARROW\n");return ARROW; }

@parallel {fprintf(output_file,"PARALLEL\n");return PARALLEL;}
shared {fprintf(output_file,"SHARED\n");return SHARED;}
private {fprintf(output_file,"PRIVATE\n");return PRIVATE;}
reduction {fprintf(output_file,"REDUCTION\n");return REDUCTION;}
schedule {fprintf(output_file,"SCHEDULE\n");return SCHEDULE;}
num_threads {fprintf(output_file,"NUM_THREADS\n");return NUM_THREADS;}
dynamic {fprintf(output_file,"DYNAMIC_SCHEDULE\n");return DYNAMIC_SCHEDULE;}
static {fprintf(output_file,"STATIC_SCHEDULE\n");return STATIC_SCHEDULE;}
mut {fprintf(output_file,"MUT\n");return MUT;}

int {fprintf(output_file,"INT\n");return INT;}
char {fprintf(output_file,"CHAR\n");return CHAR;}
long {fprintf(output_file,"LONG\n");return LONG;}
bool {fprintf(output_file,"BOOL\n");return BOOL;}
float {fprintf(output_file,"FLOAT\n");return FLOAT;}
string {fprintf(output_file,"STRING\n");return STRING;}

func {fprintf(output_file,"FUNC\n");return FUNC;}
return {fprintf(output_file,"RETURN\n");return RETURN;}
struct {fprintf(output_file,"STRUCT\n");return STRUCT;}
if {fprintf(output_file,"IF\n");return IF;}
else {fprintf(output_file,"ELSE\n");return ELSE;}
for {fprintf(output_file,"FOR\n");return FOR;}
in {fprintf(output_file,"IN\n");return IN;}


[a-zA-Z][a-zA-Z0-9_]*  { fprintf(output_file,"IDENTIFIER\n");return IDENTIFIER; }
[a-zA-Z0-9_]+ {fprintf(output_file,"SHARED_IDENTIFIER\n");return SHARED_IDENTIFIER; /*dont shared variables always start with an underscore*/}

[ \t\n]+            { /* Ignore whitespace */ }

.                   { yyerror("Syntax Error!!!"); }

%%


void yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
}

int yywrap(void) {
    return 1;
}


