%{

  //these #define are temporary
#define ASSIGN printf("ASSIGN\n");
#define PLUS printf("PLUS\n");
#define MINUS printf("MINUS\n");
#define MUL printf("MUL\n");
#define DIV printf("DIV\n");
#define MOD printf("MOD\n");
#define EQ printf("EQ\n");
#define NEQ printf("NEQ\n");
#define GT printf("GT\n");
#define LT printf("LT\n");
#define GTE printf("GTE\n");
#define LTE printf("LTE\n");
#define AND printf("AND\n");
#define OR printf("OR\n");
#define NOT printf("NOT\n");
#define ADD_ASSIGN printf("ADD_ASSIGN\n");
#define SUB_ASSIGN printf("SUB_ASSIGN\n");
#define MUL_ASSIGN printf("MUL_ASSIGN\n");
#define DIV_ASSIGN printf("DIV_ASSIGN\n");
#define MOD_ASSIGN printf("MOD_ASSIGN\n");
#define SEMICOLON printf("SEMICOLON\n");
#define COLON printf("COLON\n");
#define LPAREN printf("LPAREN\n");
#define RPAREN printf("RPAREN\n");
#define LBRACKET printf("LBRACKET\n");
#define RBRACKET printf("RBRACKET\n");
#define LBRACE printf("LBRACE\n");
#define RBRACE printf("RBRACE\n");
#define COMMA printf("COMMA\n");
#define DOT printf("DOT\n");
#define RANGE printf("RANGE\n");
#define RANGE_INCL printf("RANGE_INCL\n");
#define QUOTE printf("QUOTE\n");
#define REFERENCE printf("REFERENCE\n");
#define NUMBER printf("NUMBER\n");
#define STRING printf("STRING\n");
#define CHAR printf("CHAR\n");
#define TASKGROUP printf("TASKGROUP\n");
#define TASK printf("TASK\n");
#define PROPERTIES printf("PROPERTIES\n");
#define ORDER printf("ORDER\n");
#define CHANNEL printf("CHANNEL\n");
#define MEM printf("MEM\n");
#define _SHARED printf("_SHARED\n");
#define SUPERVISOR printf("SUPERVISOR\n");
#define ALL printf("ALL\n");
#define UNSAFE printf("UNSAFE\n");
#define JOIN printf("JOIN\n");
#define CALL printf("CALL\n");
#define CHN_SEND printf("CHN_SEND\n");
#define CHANNEL_WAIT printf("CHANNEL_WAIT\n");
#define TASK_CHANNEL printf("TASK_CHANNEL\n");
#define LOG printf("LOG\n");
#define ARROW printf("ARROW\n");
#define PARALLEL printf("PARALLEL\n");
#define SHARED printf("SHARED\n");
#define PRIVATE printf("PRIVATE\n");
#define SCHEDULE printf("SCHEDULE\n");
#define NUM_THREADS printf("NUM_THREADS\n");
#define DYNAMIC_SCHEDULE printf("DYNAMIC_SCHEDULE\n");
#define STATIC_SCHEDULE printf("STATIC_SCHEDULE\n");
#define INT printf("INT\n");
#define LONG printf("LONG\n");
#define BOOL printf("BOOL\n");
#define IDENTIFIER printf("IDENTIFIER\n");
#define SHARED_IDENTIFIER printf("SHARED_IDENTIFIER\n");
#define REDUCTION printf("REDUCTION\n");
#define MUT printf("MUT\n");
#define FUNC printf("FUNC\n");
#define RETURN printf("RETURN\n");
#define STRUCT printf("STRUCT\n");
#define IF printf("IF\n");
#define ELSE printf("ELSE\n");
#define FOR printf("FOR\n");
#define IN printf("IN\n");
#define FLOAT printf("FLOAT\n");
#define STRING_LITERAL printf("STRING_LITERAL\n");
#define CHARACTER printf("CHARACTER\n");
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