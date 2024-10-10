%{
#include "y.tab.h"
#include <stdio.h>
#include <string.h>

#define CUR_MAX_LEN 10000

void yyerror(const char *s);
void process_text(char* yytext);
void raise_error(char* s);
int cur_char = 1;
int syntax_error_flag = 0;
char cur_line[CUR_MAX_LEN];
%}


%%
"//".*           ; 
\/\*([^*]|\*+[^*/])*\**\*\/ {
	char temp[10000];
	memset(temp, 0, 10000);


	int len = strlen(yytext);
	for(int i = 0 ; i< len; i++){
		if(yytext[i] == '\n'){
			memset(temp, 0, 10000);
			yylineno++;
			cur_char = 1;
		}
		else{
			temp[strlen(temp)] = yytext[i];
			cur_char++;
		}
	}
	memset(cur_line, 0, 10000);
	strcpy(cur_line, temp);
	
}

\+=                { process_text(yytext); return ADD_ASSIGN; }

\-=                { process_text(yytext); return SUB_ASSIGN;}

\*=                { process_text(yytext); return MUL_ASSIGN; }

\/=                { process_text(yytext); return DIV_ASSIGN; }

\%=                { process_text(yytext); return MOD_ASSIGN;}

=                 { process_text(yytext); return ASSIGN; }

\+                 { process_text(yytext); return PLUS;}

\-               { process_text(yytext); return MINUS;}

\*                 { process_text(yytext); return MUL;}

\/                 { process_text(yytext); return DIV;}

\%                 { process_text(yytext); return MOD;}

==                { process_text(yytext); return EQ;}

!=                { process_text(yytext); return NEQ;}

>                 { process_text(yytext); return GT;}

\<                 { process_text(yytext); return LT;}

>=                { process_text(yytext); return GTE;}

\<=                { process_text(yytext); return LTE;}

&&               { process_text(yytext); return AND;}

\|\|               { process_text(yytext); return OR;}

!                { process_text(yytext); return NOT;}

;                 { process_text(yytext); return SEMICOLON;}

:                 { process_text(yytext); return COLON;}
 
\(                 { process_text(yytext); return LPAREN;}

\)                 { process_text(yytext); return RPAREN;}

\[                 { process_text(yytext); return LBRACKET;}

\]                 { process_text(yytext); return RBRACKET;}

\{				{ process_text(yytext); return LBRACE;}

\}                 { process_text(yytext); return RBRACE;}

,                 { process_text(yytext); return COMMA;}

\.\.                { process_text(yytext); return RANGE;}

\.\.=               { process_text(yytext); return RANGE_INCL;}

&                { process_text(yytext); return REFERENCE;}
	
@TaskGroup  { process_text(yytext); return TASKGROUP;}

@Task      { process_text(yytext); return TASK;}

@Properties { process_text(yytext); return PROPERTIES;}

@Order   { process_text(yytext); return ORDER;}

@Mem    { process_text(yytext); return MEM;}

@Shared { process_text(yytext); return SHARED_DIRECTIVE;}

@Supervisor { process_text(yytext); return SUPERVISOR;}

all { process_text(yytext); return ALL;}

unsafe { process_text(yytext); return UNSAFE;}

join { process_text(yytext); return JOIN;}
  
call      { process_text(yytext); return CALL;}


\<-                { process_text(yytext); return CHN_SEND;}

\.wt             { process_text(yytext); return CHANNEL_WAIT;}

\.ct             { process_text(yytext); return TASK_CHANNEL;}

log               { process_text(yytext); return LOG;}

\->                { process_text(yytext); return ARROW;}


@parallel { process_text(yytext); return PARALLEL;}

shared { process_text(yytext); return SHARED;}

private { process_text(yytext); return PRIVATE;}

reduction { process_text(yytext); return REDUCTION;}

schedule { process_text(yytext); return SCHEDULE;}

num_threads { process_text(yytext); return NUM_THREADS;}

dynamic { process_text(yytext); return DYNAMIC_SCHEDULE;}

static { process_text(yytext); return STATIC_SCHEDULE;}

mut { process_text(yytext); return MUT;}


int { process_text(yytext); return INT;}

char { process_text(yytext); return CHAR;}

long { process_text(yytext); return LONG;}

bool { process_text(yytext); return BOOL;}

float { process_text(yytext); return FLOAT;}

string { process_text(yytext); return STRING;}


func { process_text(yytext); return FUNC;}

	
return { process_text(yytext); return RETURN;}

continue { process_text(yytext); return CONTINUE;}

break { process_text(yytext); return BREAK;}

struct { process_text(yytext); return STRUCT;}

if { process_text(yytext); return IF;}

else { process_text(yytext); return ELSE;}

for { process_text(yytext); return FOR;}

in { process_text(yytext); return IN;}


true { process_text(yytext); return TRUE;}

false { process_text(yytext); return FALSE;}

[a-zA-Z][a-zA-Z0-9_]*  { process_text(yytext); return IDENTIFIER;}



([1-9][0-9]*)|0   { process_text(yytext); return INT_LITERAL;}
 
[0-9]+\.[^\.][0-9]*   { process_text(yytext); return FLOAT_LITERAL;}

(([1-9][0-9]*)|0)e(([1-9][0-9]*)|0) { process_text(yytext); return FLOAT_LITERAL;}


\"([^\"\n]|(\\\"))*\"        { process_text(yytext); return STRING_LITERAL;}
 
\'([^\\\']|(\\[nr\'\"]))\'        { process_text(yytext); return CHARACTER_LITERAL;}
 

\.                 { process_text(yytext); return DOT;}

[ \t]+            { process_text(yytext);}

\n    {
	memset(cur_line, 0, 10000);
    yylineno++; 
    cur_char = 1; 
}

. {
	char err_message[15500];
	memset(err_message, 0, 15500);
	sprintf(err_message, "\n\033[1;31mSyntax Error:\033[0m\nLine \033[1;36m%3d\033[0m: %s\033[1;31m%s\033[0m\nUnrecognized character \033[1;33m%s\033[0m at line \033[1;36m%d\033[0m, character \033[1;36m%d\033[0m\n",yylineno ,cur_line, yytext, yytext, yylineno, cur_char);
	raise_error(err_message);}
%%

void yyerror(const char* s){
    printf("%s\n", s);
}

void raise_error( char* s){
	fprintf(stderr, "%s\n", s);
}

void process_text(char* yytext){
	strcat(cur_line, yytext);
	int len = strlen(yytext);
	cur_char += len;
}


int yywrap(void) {
	strcat(cur_line, yytext);
	return 1;
}


    

