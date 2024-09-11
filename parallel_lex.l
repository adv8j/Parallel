%{
  #include "y.tab.h"
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
":"                 { return COLON; } // will be useful for type inference at many places, like shared variables and all.
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"["                 { return LBRACKET; }
"]"                 { return RBRACKET; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
","                 { return COMMA; }
"."                 { return DOT; }
".."                { return RANGE; }
"..="               { return RANGE_INCL; } /*
 "\""                { return QUOTE; }  */
"&"                { return REFERENCE; }

[0-9]+(\.[0-9]+)?   { return FLOAT; }
[1-9]+([0-9]+)?     { return NUMBER; }
\".*\"        { return STRING; }   // still needs some work
\'.\'        { return CHAR; }


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
join {return JOIN;}  // note that now join is a keyword called as join tid;
call      {return CALL;}

"<-"                { return CHN_SEND; }
"\\.wt"             { return CHANNEL_WAIT; }
"\\.ct"             { return TASK_CHANNEL; }
"log"               { return LOG; }
"->"                { return ARROW; }


@parallel {return PARALLEL;}
shared {return SHARED;}
private {return PRIVATE;}
schedule {return SCHEDULE;}
num_threads {return NUM_THREADS;}
dynamic {return DYNAMIC_SCHEDULE;}
static {return STATIC_SCHEDULE;}



[a-zA-Z][a-zA-Z0-9_]*  { return IDENTIFIER; }
[a-zA-Z0-9_]+ {return SHARED_IDENTIFIER;}

[ \t\n]+            { /* Ignore whitespace */ }

.                   { yyerror("Syntax Error!!!") }

%%

void yyerror(const char *s){
    fprintf(stderr, "%s\n", s);
}


int yywrap(void) {
    return 1;
}
