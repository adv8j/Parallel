%{
#include "y.tab.h"
#include <stdio.h>
#include <string.h>

#define CUR_MAX_LEN 10000

void yyerror(char *s);
int cur_char = 1;
int syntax_error_flag = 0;
char cur_line[CUR_MAX_LEN];
%}


%%
"//".*           {
	strcat(cur_line, yytext);
    int len = strlen(yytext);
    cur_char += len;
} 
\/\*([^*]|\*+[^*/])*\**\*\/ {
	strcat(cur_line, yytext);
    int len = strlen(yytext);
    cur_char += len;
}

\+=                {
	strcat(cur_line, yytext);
    int len = strlen(yytext);
    cur_char += len;
	return ADD_ASSIGN; 
}

\-=                {
	strcat(cur_line, yytext);
    int len = strlen(yytext);
    cur_char += len;
	return SUB_ASSIGN;
}

\*=                {
	strcat(cur_line, yytext);
    int len = strlen(yytext);
    cur_char += len;
	return MUL_ASSIGN; 
}

\/=                {
	strcat(cur_line, yytext);
    int len = strlen(yytext);
    cur_char += len;
	return DIV_ASSIGN; 
}

\%=                {
	strcat(cur_line, yytext);
    int len = strlen(yytext);
    cur_char += len;
	return MOD_ASSIGN;
}

=                 {
	strcat(cur_line, yytext);
    int len = strlen(yytext);
    cur_char += len;
	return ASSIGN; 
}


\+                 {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return PLUS;
}

\-               {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return MINUS;
}

\*                 {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return MUL;
}

\/                 {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return DIV;
}

\%                 {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return MOD;
}

==                {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return EQ;
}

!=                {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return NEQ;
}

>                 {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return GT;
}

\<                 {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return LT;
}

>=                {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return GTE;
}

\<=                {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return LTE;
}

&&               {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return AND;
}

\|\|               {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return OR;
}

!                {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return NOT;
}



;                 {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return SEMICOLON;
}

:                 {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return COLON;
}
 
\(                 {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return LPAREN;
}

\)                 {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return RPAREN;
}

\[                 {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return LBRACKET;
}

\]                 {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return RBRACKET;
}

\{				{
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return LBRACE;
}

\}                 {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return RBRACE;
}

,                 {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return COMMA;
}

\.\.                {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return RANGE;
}

\.\.=               {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return RANGE_INCL;
}

&                {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return REFERENCE;
}
	
@TaskGroup  {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return TASKGROUP;
}

@Task      {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return TASK;
}

@Properties {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return PROPERTIES;
}

@Order   {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return ORDER;
}

@Mem    {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return MEM;
}

@Shared {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return SHARED_DIRECTIVE;
}

@Supervisor {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return SUPERVISOR;
}

all {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return ALL;
}

unsafe {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return UNSAFE;
}

join {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return JOIN;
}
  
call      {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return CALL;
}


\<-                {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return CHN_SEND;
}

\.wt             {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return CHANNEL_WAIT;
}

\.ct             {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return TASK_CHANNEL;
}

log               {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return LOG;
}

\->                {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return ARROW;
}


@parallel {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return PARALLEL;
}

shared {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return SHARED;
}

private {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return PRIVATE;
}

reduction {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return REDUCTION;
}

schedule {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return SCHEDULE;
}

num_threads {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return NUM_THREADS;
}

dynamic {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return DYNAMIC_SCHEDULE;
}

static {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return STATIC_SCHEDULE;
}

mut {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return MUT;
}


int {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return INT;
}

char {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return CHAR;
}

long {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return LONG;
}

bool {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return BOOL;
}

float {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return FLOAT;
}

string {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return STRING;
}


func {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return FUNC;
}

	
return {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return RETURN;
}

struct {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return STRUCT;
}

if {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return IF;
}

else {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return ELSE;
}

for {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return FOR;
}

in {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return IN;
}


true {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return TRUE;
}

false {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return FALSE;
}

[a-zA-Z][a-zA-Z0-9_]*  {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return IDENTIFIER;
}

[a-zA-Z_][a-zA-Z0-9_]* {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return SHARED_IDENTIFIER;
}


([1-9][0-9]*)|0   {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return INT_LITERAL;
}
 
[0-9]+\.[^\.][0-9]*   {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return FLOAT_LITERAL;
}

(([1-9][0-9]*)|0)e(([1-9][0-9]*)|0) {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return FLOAT_LITERAL;
}


\"([^\"\n]|(\\\"))*\"        {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return STRING_LITERAL;
}
 
\'([^\\\']|(\\[nr\'\"]))\'        {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return CHARACTER_LITERAL;
}
 

\.                 {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
	return DOT;
}



[ \t]+            {
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
}

\n    {
	memset(cur_line, 0, 10000);
    yylineno++; 
    cur_char = 1; 
}

. {
	char err_message[15500];
	memset(err_message, 0, 15500);
	sprintf(err_message, "\n\033[1;31mSyntax Error:\033[0m\nLine \033[1;36m%3d\033[0m: %s\033[1;31m%s\033[0m\nUnrecognized character \033[1;33m%s\033[0m at line \033[1;36m%d\033[0m, character \033[1;36m%d\033[0m\n",yylineno ,cur_line, yytext, yytext, yylineno, cur_char);
	yyerror(err_message);
	return YYerror;
}
%%

void yyerror(char* s){
	printf("%s", s);
}

int yywrap(void) {
	strcat(cur_line, yytext);
	return 1;
}

    

