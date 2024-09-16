%{
#include "y.tab.h"
#include <stdio.h>
#include <string.h>
void yyerror(char *s);
int cur_char = 1;
FILE *output_file;
%}

%%
"//".*           {
    fprintf(output_file,"single_line_comment\n");
    int len = strlen(yytext);
    cur_char += len;

} 
\/\*([^*]|\*+[^*/])*\**\*\/ {fprintf(output_file,"multi_line_comment\n");
    int len = strlen(yytext);
    cur_char += len;
}

\+=                { fprintf(output_file,"ADD_ASSIGN\n");return ADD_ASSIGN; 
    int len = strlen(yytext);
    cur_char += len;
}

\-=                { fprintf(output_file,"SUB_ASSIGN\n");return SUB_ASSIGN;
    int len = strlen(yytext);
    cur_char += len;
}

\*=                { fprintf(output_file,"MUL_ASSIGN\n");return MUL_ASSIGN; 
    int len = strlen(yytext);
    cur_char += len;
}

\/=                { fprintf(output_file,"DIV_ASSIGN\n");return DIV_ASSIGN; 
    int len = strlen(yytext);
    cur_char += len;
}

\%=                { fprintf(output_file,"MOD_ASSIGN\n");return MOD_ASSIGN;
    int len = strlen(yytext);
    cur_char += len;
}

=                 { fprintf(output_file,"ASSIGN\n");return ASSIGN; 
    int len = strlen(yytext);
    cur_char += len;
}


\+                 { fprintf(output_file,"PLUS\n");return PLUS;
	int len = strlen(yytext);
	cur_char += len;
}

\-               { fprintf(output_file,"MINUS\n");return MINUS;
	int len = strlen(yytext);
	cur_char += len;
}

\*                 { fprintf(output_file,"MUL\n");return MUL;
	int len = strlen(yytext);
	cur_char += len;
}

\/                 { fprintf(output_file,"DIV\n");return DIV;
	int len = strlen(yytext);
	cur_char += len;
}

\%                 { fprintf(output_file,"MOD\n");return MOD;
	int len = strlen(yytext);
	cur_char += len;
}

==                { fprintf(output_file,"EQ\n");return EQ;
	int len = strlen(yytext);
	cur_char += len;
}

!=                { fprintf(output_file,"NEQ\n");return NEQ;
	int len = strlen(yytext);
	cur_char += len;
}

>                 { fprintf(output_file,"GT\n");return GT;
	int len = strlen(yytext);
	cur_char += len;
}

\<                 { fprintf(output_file,"LT\n");return LT;
	int len = strlen(yytext);
	cur_char += len;
}

>=                { fprintf(output_file,"GTE\n");return GTE;
	int len = strlen(yytext);
	cur_char += len;
}

\<=                { fprintf(output_file,"LTE\n");return LTE;
	int len = strlen(yytext);
	cur_char += len;
}

&&               { fprintf(output_file,"AND\n");return AND;
	int len = strlen(yytext);
	cur_char += len;
}

\|\|               { fprintf(output_file,"OR\n");return OR;
	int len = strlen(yytext);
	cur_char += len;
}

!                { fprintf(output_file,"NOT\n");return NOT;
	int len = strlen(yytext);
	cur_char += len;
}



;                 { fprintf(output_file,"SEMICOLON\n");return SEMICOLON;
	int len = strlen(yytext);
	cur_char += len;
}

:                 { fprintf(output_file,"COLON\n");return COLON;
	int len = strlen(yytext);
	cur_char += len;
}
 
\(                 { fprintf(output_file,"LPAREN\n");return LPAREN;
	int len = strlen(yytext);
	cur_char += len;
}

\)                 { fprintf(output_file,"RPAREN\n");return RPAREN;
	int len = strlen(yytext);
	cur_char += len;
}

\[                 { fprintf(output_file,"LBRACKET\n");return LBRACKET;
	int len = strlen(yytext);
	cur_char += len;
}

\]                 { fprintf(output_file,"RBRACKET\n");return RBRACKET;
	int len = strlen(yytext);
	cur_char += len;
}

\{                 { fprintf(output_file,"LBRACE\n");return LBRACE;
	int len = strlen(yytext);
	cur_char += len;
}

\}                 { fprintf(output_file,"RBRACE\n");return RBRACE;
	int len = strlen(yytext);
	cur_char += len;
}

,                 { fprintf(output_file,"COMMA\n");return COMMA;
	int len = strlen(yytext);
	cur_char += len;
}

\.\.                { fprintf(output_file,"RANGE\n");return RANGE;
	int len = strlen(yytext);
	cur_char += len;
}

\.\.=               { fprintf(output_file,"RANGE_INCL\n");return RANGE_INCL;
	int len = strlen(yytext);
	cur_char += len;
}

&                { fprintf(output_file,"REFERENCE\n");return REFERENCE;
	int len = strlen(yytext);
	cur_char += len;
}




@TaskGroup  {fprintf(output_file,"TASKGROUP\n");return TASKGROUP;
	int len = strlen(yytext);
	cur_char += len;
}

@Task      {fprintf(output_file,"TASK\n");return TASK;
	int len = strlen(yytext);
	cur_char += len;
}

@Properties {fprintf(output_file,"PROPERTIES\n");return PROPERTIES;
	int len = strlen(yytext);
	cur_char += len;
}

@Order   {fprintf(output_file,"ORDER\n");return ORDER;
	int len = strlen(yytext);
	cur_char += len;
}

@Mem    {fprintf(output_file,"MEM\n");return MEM;
	int len = strlen(yytext);
	cur_char += len;
}

@Shared {fprintf(output_file,"SHARED_DIRECTIVE\n");return SHARED_DIRECTIVE;
	int len = strlen(yytext);
	cur_char += len;
}

@Supervisor {fprintf(output_file,"SUPERVISOR\n");return SUPERVISOR;
	int len = strlen(yytext);
	cur_char += len;
}

all {fprintf(output_file,"ALL\n");return ALL;
	int len = strlen(yytext);
	cur_char += len;
}

unsafe {fprintf(output_file,"UNSAFE\n");return UNSAFE;
	int len = strlen(yytext);
	cur_char += len;
}

join {fprintf(output_file,"JOIN\n");return JOIN;
	int len = strlen(yytext);
	cur_char += len;
}
  
call      {fprintf(output_file,"CALL\n");return CALL;
	int len = strlen(yytext);
	cur_char += len;
}


\<-                { fprintf(output_file,"CHN_SEND\n");return CHN_SEND;
	int len = strlen(yytext);
	cur_char += len;
}

\.wt             { fprintf(output_file,"CHANNEL_WAIT\n");return CHANNEL_WAIT;
	int len = strlen(yytext);
	cur_char += len;
}

\.ct             { fprintf(output_file,"TASK_CHANNEL\n");return TASK_CHANNEL;
	int len = strlen(yytext);
	cur_char += len;
}

log               { fprintf(output_file,"LOG\n");return LOG;
	int len = strlen(yytext);
	cur_char += len;
}

\->                { fprintf(output_file,"ARROW\n");return ARROW;
	int len = strlen(yytext);
	cur_char += len;
}


@parallel {fprintf(output_file,"PARALLEL\n");return PARALLEL;
	int len = strlen(yytext);
	cur_char += len;
}

shared {fprintf(output_file,"SHARED\n");return SHARED;
	int len = strlen(yytext);
	cur_char += len;
}

private {fprintf(output_file,"PRIVATE\n");return PRIVATE;
	int len = strlen(yytext);
	cur_char += len;
}

reduction {fprintf(output_file,"REDUCTION\n");return REDUCTION;
	int len = strlen(yytext);
	cur_char += len;
}

schedule {fprintf(output_file,"SCHEDULE\n");return SCHEDULE;
	int len = strlen(yytext);
	cur_char += len;
}

num_threads {fprintf(output_file,"NUM_THREADS\n");return NUM_THREADS;
	int len = strlen(yytext);
	cur_char += len;
}

dynamic {fprintf(output_file,"DYNAMIC_SCHEDULE\n");return DYNAMIC_SCHEDULE;
	int len = strlen(yytext);
	cur_char += len;
}

static {fprintf(output_file,"STATIC_SCHEDULE\n");return STATIC_SCHEDULE;
	int len = strlen(yytext);
	cur_char += len;
}

mut {fprintf(output_file,"MUT\n");return MUT;
	int len = strlen(yytext);
	cur_char += len;
}


int {fprintf(output_file,"INT\n");return INT;
	int len = strlen(yytext);
	cur_char += len;
}

char {fprintf(output_file,"CHAR\n");return CHAR;
	int len = strlen(yytext);
	cur_char += len;
}

long {fprintf(output_file,"LONG\n");return LONG;
	int len = strlen(yytext);
	cur_char += len;
}

bool {fprintf(output_file,"BOOL\n");return BOOL;
	int len = strlen(yytext);
	cur_char += len;
}

float {fprintf(output_file,"FLOAT\n");return FLOAT;
	int len = strlen(yytext);
	cur_char += len;
}

string {fprintf(output_file,"STRING\n");return STRING;
	int len = strlen(yytext);
	cur_char += len;
}


func {fprintf(output_file,"FUNC\n");return FUNC;
	int len = strlen(yytext);
	cur_char += len;
}

return {fprintf(output_file,"RETURN\n");return RETURN;
	int len = strlen(yytext);
	cur_char += len;
}

struct {fprintf(output_file,"STRUCT\n");return STRUCT;
	int len = strlen(yytext);
	cur_char += len;
}

if {fprintf(output_file,"IF\n");return IF;
	int len = strlen(yytext);
	cur_char += len;
}

else {fprintf(output_file,"ELSE\n");return ELSE;
	int len = strlen(yytext);
	cur_char += len;
}

for {fprintf(output_file,"FOR\n");return FOR;
	int len = strlen(yytext);
	cur_char += len;
}

in {fprintf(output_file,"IN\n");return IN;
	int len = strlen(yytext);
	cur_char += len;
}


true {fprintf(output_file,"TRUE\n");return TRUE;
	int len = strlen(yytext);
	cur_char += len;
}

false {fprintf(output_file,"FALSE\n");return FALSE;
	int len = strlen(yytext);
	cur_char += len;
}

[a-zA-Z][a-zA-Z0-9_]*  { fprintf(output_file,"IDENTIFIER\n");return IDENTIFIER;
	int len = strlen(yytext);
	cur_char += len;
}

[a-zA-Z_][a-zA-Z0-9_]* {fprintf(output_file,"SHARED_IDENTIFIER\n");return SHARED_IDENTIFIER;
	int len = strlen(yytext);
	cur_char += len;
}


([1-9][0-9]*)|0   { fprintf(output_file,"INT_LITERAL\n");return INT_LITERAL;
	int len = strlen(yytext);
	cur_char += len;
}
 
[0-9]+\.[^\.][0-9]*   { fprintf(output_file,"FLOAT_LITERAL\n");return FLOAT_LITERAL;
	int len = strlen(yytext);
	cur_char += len;
}

(([1-9][0-9]*)|0)e(([1-9][0-9]*)|0) { fprintf(output_file,"FLOAT_LITERAL\n");return FLOAT_LITERAL;
	int len = strlen(yytext);
	cur_char += len;
}


\"([^\"\n]|(\\\"))*\"        { fprintf(output_file,"STRING_LITERAL\n");return STRING_LITERAL;
	int len = strlen(yytext);
	cur_char += len;
}
 
\'([^\\\']|(\\[nr\'\"]))\'        { fprintf(output_file,"CHARACTER_LITERAL\n");return CHARACTER_LITERAL;
	int len = strlen(yytext);
	cur_char += len;
}
 

\.                 { fprintf(output_file,"DOT\n");return DOT;
	int len = strlen(yytext);
	cur_char += len;
}



[ \t]+            { /* Ignore whitespace */ }
\n    {
    yylineno++; 
    cur_char = 1; 
}

. {
    yyerror("Syntax Error!!!");
    printf("\033[1;31mSyntax Error\033[0m ");
    printf("Unrecognized character \033[1;33m%s\033[0m ", yytext); 
    printf("at line \033[1;36m%d\033[0m, character \033[1;36m%d\033[0m\n", yylineno, cur_char);
}
%%


void yyerror(char *s) {
	fprintf(output_file, "%s\n", s);
}

int yywrap(void) {
    return 1;
}


