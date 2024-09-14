%{

FILE *inp;
FILE *out;

  //these #define are temporary
#define ASSIGN fprintf(out, "ASSIGN\n");
#define PLUS fprintf(out, "PLUS\n");
#define MINUS fprintf(out, "MINUS\n");
#define MUL fprintf(out, "MUL\n");
#define DIV fprintf(out, "DIV\n");
#define MOD fprintf(out, "MOD\n");
#define EQ fprintf(out, "EQ\n");
#define NEQ fprintf(out, "NEQ\n");
#define GT fprintf(out, "GT\n");
#define LT fprintf(out, "LT\n");
#define GTE fprintf(out, "GTE\n");
#define LTE fprintf(out, "LTE\n");
#define AND fprintf(out, "AND\n");
#define OR fprintf(out, "OR\n");
#define NOT fprintf(out, "NOT\n");
#define ADD_ASSIGN fprintf(out, "ADD_ASSIGN\n");
#define SUB_ASSIGN fprintf(out, "SUB_ASSIGN\n");
#define MUL_ASSIGN fprintf(out, "MUL_ASSIGN\n");
#define DIV_ASSIGN fprintf(out, "DIV_ASSIGN\n");
#define MOD_ASSIGN fprintf(out, "MOD_ASSIGN\n");
#define SEMICOLON fprintf(out, "SEMICOLON\n");
#define COLON fprintf(out, "COLON\n");
#define LPAREN fprintf(out, "LPAREN\n");
#define RPAREN fprintf(out, "RPAREN\n");
#define LBRACKET fprintf(out, "LBRACKET\n");
#define RBRACKET fprintf(out, "RBRACKET\n");
#define LBRACE fprintf(out, "LBRACE\n");
#define RBRACE fprintf(out, "RBRACE\n");
#define COMMA fprintf(out, "COMMA\n");
#define DOT fprintf(out, "DOT\n");
#define RANGE fprintf(out, "RANGE\n");
#define RANGE_INCL fprintf(out, "RANGE_INCL\n");
#define QUOTE fprintf(out, "QUOTE\n");
#define REFERENCE fprintf(out, "REFERENCE\n");
#define NUMBER fprintf(out, "NUMBER\n");
#define STRING fprintf(out, "STRING\n");
#define CHAR fprintf(out, "CHAR\n");
#define TASKGROUP fprintf(out, "TASKGROUP\n");
#define TASK fprintf(out, "TASK\n");
#define PROPERTIES fprintf(out, "PROPERTIES\n");
#define ORDER fprintf(out, "ORDER\n");
#define CHANNEL fprintf(out, "CHANNEL\n");
#define MEM fprintf(out, "MEM\n");
#define _SHARED fprintf(out, "_SHARED\n");
#define SUPERVISOR fprintf(out, "SUPERVISOR\n");
#define ALL fprintf(out, "ALL\n");
#define UNSAFE fprintf(out, "UNSAFE\n");
#define JOIN fprintf(out, "JOIN\n");
#define CALL fprintf(out, "CALL\n");
#define CHN_SEND fprintf(out, "CHN_SEND\n");
#define CHANNEL_WAIT fprintf(out, "CHANNEL_WAIT\n");
#define TASK_CHANNEL fprintf(out, "TASK_CHANNEL\n");
#define LOG fprintf(out, "LOG\n");
#define ARROW fprintf(out, "ARROW\n");
#define PARALLEL fprintf(out, "PARALLEL\n");
#define SHARED fprintf(out, "SHARED\n");
#define PRIVATE fprintf(out, "PRIVATE\n");
#define SCHEDULE fprintf(out, "SCHEDULE\n");
#define NUM_THREADS fprintf(out, "NUM_THREADS\n");
#define DYNAMIC_SCHEDULE fprintf(out, "DYNAMIC_SCHEDULE\n");
#define STATIC_SCHEDULE fprintf(out, "STATIC_SCHEDULE\n");
#define INT fprintf(out, "INT\n");
#define LONG fprintf(out, "LONG\n");
#define BOOL fprintf(out, "BOOL\n");
#define IDENTIFIER fprintf(out, "IDENTIFIER\n");
#define SHARED_IDENTIFIER fprintf(out, "SHARED_IDENTIFIER\n");
#define REDUCTION fprintf(out, "REDUCTION\n");
#define MUT fprintf(out, "MUT\n");
#define FUNC fprintf(out, "FUNC\n");
#define RETURN fprintf(out, "RETURN\n");
#define STRUCT fprintf(out, "STRUCT\n");
#define IF fprintf(out, "IF\n");
#define ELSE fprintf(out, "ELSE\n");
#define FOR fprintf(out, "FOR\n");
#define IN fprintf(out, "IN\n");
#define FLOAT fprintf(out, "FLOAT\n");
#define STRING_LITERAL fprintf(out, "STRING_LITERAL\n");
#define CHARACTER fprintf(out, "CHARACTER\n");
%}

%%

=                 {  ASSIGN;   /*operators*/ }
\+                 {  PLUS; }
\-               {  MINUS; }
\*                 {  MUL; }
\/                 {  DIV; }
\%                 {  MOD; }
==                {  EQ; }
!=                {  NEQ; }
>                 {  GT; }
\<                 {  LT; }
>=                {  GTE; }
\<=                {  LTE; }
\&&               {  AND; }
\|\|               {  OR; }
\!                {  NOT; }
\+=                {  ADD_ASSIGN; }
\-=                {  SUB_ASSIGN; }
\*=                {  MUL_ASSIGN; }
\/=                {  DIV_ASSIGN; }
\%=                {  MOD_ASSIGN; }


"//".*           {/*comments*/ fprintf(out, "single line comment");} 
"/*"([^(\*\/)])*"*/"  fprintf(out, "multi line comment");


\;                 {  SEMICOLON; /* Symbols and Separators */}
\:                 {  COLON; /* will be useful for type inference at many places, like shared variables and all.*/} 
\(                 {  LPAREN; }
\)                 {  RPAREN; }
\[                 {  LBRACKET; }
\]                 {  RBRACKET; }
\{                 {  LBRACE; }
\}                 {  RBRACE; }
\,                 {  COMMA; }
\.                 {  DOT; }
\.\.                {  RANGE; }
\..=               {  RANGE_INCL; } 
\"                {  QUOTE; }
\&                {  REFERENCE; }


[0-9]+(\.[0-9]+)?   {  NUMBER; }
\"([^"(\\\")\n]*(\\\")?)*\"        {  STRING_LITERAL; } 
\'.\'        {  CHARACTER;}

@TaskGroup  { TASKGROUP;}
@Task      { TASK;}
@Properties { PROPERTIES;}
@Order   { ORDER;}
@Channel { CHANNEL;}
@Mem    { MEM;}
@Shared { _SHARED;}
@Supervisor { SUPERVISOR;}
all { ALL;}
unsafe { UNSAFE;}
join { JOIN; /* note that now join is a keyword called as join tid;*/ }  
call      { CALL;}

\<-                {  CHN_SEND; }
\.wt             {  CHANNEL_WAIT; }
\.ct             {  TASK_CHANNEL; }
log               {  LOG;  /*what should we do about k*/}
\->                {  ARROW; }

@parallel { PARALLEL;}
shared { SHARED;}
private { PRIVATE;}
reduction { REDUCTION;}
schedule { SCHEDULE;}
num_threads { NUM_THREADS;}
dynamic { DYNAMIC_SCHEDULE;}
static { STATIC_SCHEDULE;}
mut { MUT;}

int { INT;}
char { CHAR;}
long { LONG;}
bool { BOOL;}
float { FLOAT;}
string { STRING;}

func { FUNC;}
return { RETURN;}
struct { STRUCT;}
if { IF;}
else { ELSE;}
for { FOR;}
in { IN;}


[a-zA-Z][a-zA-Z0-9_]*  {  IDENTIFIER; }
[a-zA-Z0-9_]+ { SHARED_IDENTIFIER; /*dont shared variables always start with an underscore*/}

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

    for(int i=0;i<23;i++)
    {
        char in_name[10];
        char out_name[20];

        sprintf(in_name, "%d.txt", (i+1));
        sprintf(out_name, "%d_out.txt", (i+1));
        printf("%s\n%s\n",in_name,out_name);
        out = fopen(out_name, "w");
        inp = fopen(in_name, "r");
        if (!inp) {
            printf("Can't open the inp!");
            return -1;
        }
        if(!out)
        {
           printf("Can't open the out!");
            return -1; 
        }
        yyin = inp;
        yylex();
        fclose(inp);
        fclose(out);        
    }
    return 0;
}