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
statement_list:statement_list statement
|	statement;

statement:
iterative_statement
|	selection_statement
|	expression_statement
|	compound_statement
|	function_declaration
|	taskgroup_statement
|	declaration_statement
|	parallel_statement;

inner_statement:
iterative_statement
|	selection_statement
|	expression_statement
|	compound_statement
|	declaration_statement
|	parallel_statement;

compound_statement:
LBRACE inner_statement RBRACE
;

iterative_statement: 
FOR LPAREN expression_statement expression_statement expression RPAREN inner_statement
|FOR LPAREN IDENTIFIER IN number range number RPAREN inner_statement
|FOR LPAREN iterator IN IDENTIFIER RPAREN inner_statement;

iterator: IDENTIFIER|REFERENCE IDENTIFIER;
range: RANGE|RANGE_INCL;
number: INT_LITERAL|IDENTIFIER;

selection_statement: 
IF LPAREN expression RPAREN inner_statement
|IF LPAREN expression RPAREN inner_statement ELSE inner_statement;


// not complete
function_declaration: FUNC IDENTIFIER return_datatype LPAREN 
data_type: INT| CHAR| LONG| BOOL| FLOAT| STRING| IDENTIFIER		//here identifier is for struct datatypes
return_datatype: data_type| data_type REFERENCE;

//not complete
argument_list: argument_declaration
			| argument_list COMMA argument_declaraction;


// array declaraction 
array_declaration: data_type number array_dimension_list;
array_dimension_list : LBRACKET number array_dimension_tail;
array_dimension_tail:RBRACKET array_dimension_increase
	 				|  COMMA number RBRACKET;
array_dimension_increase: LBRACKET number array_dimension_tail;

//array initialisation is left


//parallel statements
parallel_statement: PARALLEL LPAREN parallel_stmt_argument_list RPAREN compound_statement // parallel block statement
|	PARALLEL LPAREN parallel_stmt_argument_list RPAREN iterative_statement; // parallel for statement

parallel_stmt_argument_list: parallel_stmt_argument_list COMMA parallel_stmt_argument
|	parallel_stmt_argument;

// this consists of all the arguments which are inside the parallel construct like shared, private, reduction, etc. 
parallel_stmt_argument: SHARED ASSIGN LBRACKET parallel_identifier_list RBRACKET 
|	PRIVATE ASSIGN LBRACKET parallel_identifier_list RBRACKET 
|	REDUCTION ASSIGN LBRACKET reduction_list RBRACKET;
| 	SCHEDULE ASSIGN schedule_list
| 	NUM_THREADS ASSIGN INT_LITERAL;

schedule_list: STATIC_SCHEDULE|	DYNAMIC_SCHEDULE;

parallel_identifier_list: parallel_identifier_list COMMA IDENTIFIER
|	IDENTIFIER;

// reduction list contains operator: identifier list. for eg. +: a,b,c
reduction_list: reduction_list COMMA reduction_operator_list COLON parallel_identifier_list
|	reduction_operator_list COLON parallel_identifier_list;

// reduction operator list contains all the reduction operators like +, -, *, /, % and the reduction is applied on operator assign versions (like +=, -=, *=, /=, %=).
reduction_operator_list: PLUS
|	MINUS
|	MUL
|	DIV
|	MOD;

// conditional signals and return statements
channel_statement: signal_statement SEMICOLON| wait_statement SEMICOLON;

// signal statement which can be either .ct or .ct <- <any-value>;
signal_statement: TASK_CHANNEL
|	TASK_CHANNEL CHN_SEND value;

// wait statement which can be either .wt{<task-name>, number} or .wt{<task-name>, number} -> <identifier> ;
wait_statement: CHANNEL_WAIT LBRACE IDENTIFIER COMMA number RBRACE
| CHANNEL_WAIT LBRACE IDENTIFIER COMMA number RBRACE ARROW IDENTIFIER;

value: INT_LITERAL| FLOAT_LITERAL| STRING_LITERAL| CHARACTER_LITERAL| TRUE| FALSE| IDENTIFIER;
%%
int main(void) {
	yyparse();
}