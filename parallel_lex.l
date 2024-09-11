%{

  //these #define are temporary
#define ASSIGN 1
#define PLUS 2
#define MINUS 3
#define MUL 4
#define DIV 5
#define MOD 6
#define EQ 7
#define NEQ 8
#define GT 9
#define LT 10
#define GTE 11
#define LTE 12
#define AND 13
#define OR 14
#define NOT 15
#define ADD_ASSIGN 16
#define SUB_ASSIGN 17
#define MUL_ASSIGN 18
#define DIV_ASSIGN 19
#define MOD_ASSIGN 20
#define SEMICOLON 21
#define COLON 22
#define LPAREN 23
#define RPAREN 24
#define LBRACKET 25
#define RBRACKET 26
#define LBRACE 27
#define RBRACE 28
#define COMMA 29
#define DOT 30
#define RANGE 31
#define RANGE_INCL 32
#define QUOTE 33
#define REFERENCE 34
#define FLOAT 35
#define STRING 36
#define CHAR 37
#define TASKGROUP 38
#define TASK 39
#define PROPERTIES 40
#define ORDER 41
#define CHANNEL 42
#define MEM 43
#define _SHARED 44
#define SUPERVISOR 45
#define ALL 46
#define UNSAFE 47
#define JOIN 48
#define CALL 49
#define CHN_SEND 50
#define CHANNEL_WAIT 51
#define TASK_CHANNEL 52
#define LOG 53
#define ARROW 54
#define PARALLEL 55
#define SHARED 56
#define PRIVATE 57
#define SCHEDULE 58
#define NUM_THREADS 59
#define DYNAMIC_SCHEDULE 60
#define STATIC_SCHEDULE 61
#define INT 62
#define LONG 63
#define BOOL 64
#define IDENTIFIER 65
#define SHARED_IDENTIFIER 66
%}

%%

"="                 { return ASSIGN;   /*operators*/ }
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


"//".*           {/*comments*/ printf("single line comment");} 
"/*"([^(\*\/)])*"*/"  printf("multi line comment");


";"                 { return SEMICOLON; /* Symbols and Separators */}
":"                 { return COLON; /* will be useful for type inference at many places, like shared variables and all.*/} 
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"["                 { return LBRACKET; }
"]"                 { return RBRACKET; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
","                 { return COMMA; }
"."                 { return DOT; }
".."                { return RANGE; }
"..="               { return RANGE_INCL; } 
 "\""                { return QUOTE; }
"&"                { return REFERENCE; }


[0-9]+(\.[0-9]+)?   { return FLOAT; }
\".*\"        { printf("string\n");return STRING; } 
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
join {return JOIN; /* note that now join is a keyword called as join tid;*/ }  
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

int {return INT;}
char {return CHAR;}
long {return LONG;}
bool {return BOOL;}
float {return FLOAT;}
string {return STRING;}

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

    yylex();
    return 0;
}