%{
#include <stdio.h>
int yylex(void);
extern void yyerror(char *s);
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
%token REFERENCE

%token TASKGROUP
%token TASK
%token PROPERTIES
%token ORDER
%token MEM
%token SHARED_DIRECTIVE
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
%token PRIVATE
%token SHARED
%token SCHEDULE
%token NUM_THREADS
%token REDUCTION
%token DYNAMIC_SCHEDULE
%token STATIC_SCHEDULE
%token MUT

%token INT
%token CHAR
%token LONG
%token BOOL
%token FLOAT
%token STRING

%token FUNC
%token RETURN
%token STRUCT
%token IF
%token ELSE
%token FOR
%token IN

%token TRUE
%token FALSE

%token IDENTIFIER
%token SHARED_IDENTIFIER

%token INT_LITERAL
%token FLOAT_LITERAL
%token STRING_LITERAL
%token CHARACTER_LITERAL
%start program

%%
program:statement_list;
statement_list:statement_list statement|statement;

statement:
iterative_statement
|selection_statement
|expression_statement
|compound_statement
|function_declaration
|taskgroup_statement
|declaration_statement
|parallel_statement;

inner_statement:
iterative_statement
|selection_statement
|expression_statement
|compound_statement
|declaration_statement
|parallel_statement;

compound_statement:
LBRACE inner_statement RBRACE
;

iterative_statement: 
FOR LPAREN expression_statement expression_statement expression RPAREN inner_statement
|FOR IDENTIFIER IN IDENTIFIER range IDENTIFIER inner_statement // this is flawed
|FOR LPAREN temp1 IN IDENTIFIER inner_statement;

temp1: IDENTIFIER|REFERENCE IDENTIFIER;
range: RANGE|RANGE_INCL;

selection_statement: 
IF LPAREN expression RPAREN inner_statement
|IF LPAREN expression RPAREN inner_statement ELSE inner_statement;

expression
%%
int main(void) {
	yyparse();
}