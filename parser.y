%{
#include <stdio.h>
int yylex(void);
int yyerror(char *s);
%}


%token ASSIGN
%token PLUS
%token MINUS
%token MUL
%token DIV
%token MOD
%token EQ
%token NEQ
%token GT
%token LT
%token GTE
%token LTE
%token AND
%token OR
%token NOT
%token ADD_ASSIGN
%token SUB_ASSIGN
%token MUL_ASSIGN
%token DIV_ASSIGN
%token MOD_ASSIGN
%token SEMICOLON
%token COLON
%token LPAREN
%token RPAREN
%token LBRACKET
%token RBRACKET
%token LBRACE
%token RBRACE
%token COMMA
%token DOT
%token RANGE
%token RANGE_INCL
%token QUOTE
%token REFERENCE
%token NUMBER
%token STRING
%token CHAR
%token TASKGROUP
%token TASK
%token PROPERTIES
%token ORDER
%token CHANNEL
%token MEM
%token _SHARED
%token SUPERVISOR
%token ALL
%token UNSAFE
%token JOIN
%token CALL
%token CHN_SEND
%token CHANNEL_WAIT
%token TASK_CHANNEL
%token LOG
%token ARROW
%token PARALLEL
%token SHARED
%token PRIVATE
%token SCHEDULE
%token NUM_THREADS
%token DYNAMIC_SCHEDULE
%token STATIC_SCHEDULE
%token INT
%token LONG
%token BOOL
%token IDENTIFIER
%token SHARED_IDENTIFIER
%token REDUCTION
%token MUT
%token FUNC
%token RETURN
%token STRUCT
%token IF
%token ELSE
%token FOR
%token IN
%token FLOAT
%token STRING_LITERAL
%token CHARACTER

%%
statement:;
%%

int yyerror(char *s) {
	fprintf(stderr, "%s\n", s);
	return 0;
}
int main(void) {
	yyparse();
}