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

// Precedence

%right ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%left OR 
%left AND
%left EQ NEQ
%left GT LT GTE LTE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT // Unary operator problem




%%
program:statement_list;
statement_list:statement_list statement
|	statement;

assignment_operators:
ASSIGN
|ADD_ASSIGN
|SUB_ASSIGN
|MUL_ASSIGN
|DIV_ASSIGN
|MOD_ASSIGN;



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



expression_statement:
expression SEMICOLON
| SEMICOLON;

expression:
  number
| LPAREN expression RPAREN
| expression PLUS expression
| expression MINUS expression
| expression MUL expression
| expression DIV expression
| expression MOD expression
| expression EQ expression
| expression NEQ expression
| expression GT expression
| expression LT expression
| expression GTE expression
| expression LTE expression
| expression AND expression
| expression OR expression
| expression assignment_operators expression
| NOT expression
| MINUS expression;





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

taskgroup_statement: TASKGROUP IDENTIFIER LPAREN LOG EQ STRING_LITERAL RPAREN LBRACE taskgroup_definition RBRACE SEMICOLON
	| TASKGROUP IDENTIFIER  LBRACE  taskgroup_definition RBRACE SEMICOLON
	;  // this non-terminal is for @TaskGroup t1{ taskgroup_definition}

taskgroup_definition:  task_declaration_list properties_declaration 
    |
    ; // this non-terminal is for writing list of tasks followed by properties


task_declaration_list: task_declaration_list task_declaration
    | task_declaration
    ; // this non-terminal is for writing list of tasks

task_declaration: TASK IDENTIFIER LBRACE task_statements RBRACE 
    | SUPERVISOR IDENTIFIER LBRACE task_statements RBRACE
    ; /* this non-terminal is for writing task or supervisor 
        @Task t1{ task_statements} or @Supervisor t1{ task_statements} */

// #TODO: task_statements STILL HAVE TO FIX STUFF HERE.
task_statements: statement
    ;
    // this non-terminal is for writing list of statements in a task (basically allowed statements in a task)

properties_declaration: PROPERTIES LBRACE taskgroup_properties RBRACE
    ;
    // this non-terminal is for writing properties of a taskgroup
    // PROPERTIES { taskgroup_properties }

taskgroup_properties: taskgroup_properties taskgroup_property
    | taskgroup_property
    ;
    // this non-terminal is for writing list of properties

taskgroup_property: order_block
                | shared_block
                | mem_block
                ;
    // this non-terminal is for deciding between properties @Order, @Shared, @Mem

order_block: ORDER LBRACE order_rule_list RBRACE
    ;
    // this non-terminal is for writing order rules
    // ORDER { order_rule_list }

order_rule_list: order_rule_list order_rule 
    | order_rule 
    ;
    // this non-terminal is for writing list of order rules

order_rule: order_rule_start order_rule_mid order_rule_end 
    ;
    // this non-terminal is for writing order rule
    // order_rule_start order_rule_mid order_rule_end, handles the case that all must be at start and end only

order_rule_start: ALL ARROW     // this non-terminal is for writing order rule start
    |
    ;
    // ALL ->

order_rule_mid: order_rule_mid ARROW identifier_list   // this non-terminal is for writing order rule mid
    | identifier_list
    ;
    // IDENTIFIER, IDENTIFIER -> IDENTIFIER

order_rule_end: ARROW ALL SEMICOLON   // this non-terminal is for writing order rule end
    | SEMICOLON
    ;
    // -> ALL

identifier_list: identifier_list COMMA IDENTIFIER
    | IDENTIFIER
    ;
    // this non-terminal is for writing list of identifiers

shared_block: SHARED_DIRECTIVE LBRACE shared_rule_list RBRACE
    ;
    // this non-terminal is for writing shared rules
    // SHARED { shared_rule_list }

shared_rule_list: shared_rule_list shared_rule 
    | shared_rule
    ;
    // this non-terminal is for writing list of shared rules

shared_rule: IDENTIFIER COLON dtype ARROW identifier_list SEMICOLON
    ;
    // this non-terminal is for writing shared rule
    // IDENTIFIER : dtype -> IDENTIFIER


generic_dtypes: INT 
    | FLOAT
    | STRING
    | BOOL
    | CHAR
    | IDENTIFIER 
    ;
    // for struct still have to find better solution

dtype: generic_dtypes
    | array
    ;
    // this non-terminal is for writing data type

array: generic_dtypes dims 
    ;
    // this non-terminal is for writing array data type


// Needs work for array initialization and all : TODO
dims: dims LBRACKET INT_LITERAL RBRACKET
    | LBRACKET INT_LITERAL RBRACKET
    ;
    // this non-terminal is for writing array dimensions


mem_block: MEM LBRACE mem_statement_list RBRACE
    |	MEM UNSAFE LBRACE mem_statement_list RBRACE
    ;
    // this non-terminal is for writing mem rules
    // @Mem { mem_statement_list }


mem_statement_list: mem_statement_list mem_statement 
    |   mem_statement 
    ;
    // this non-terminal is for writing list of mem statements


mem_statement: identifier_list ARROW mem_taskgroup_list SEMICOLON
    ;
    // this non-terminal is for writing mem statement
    // IDENTIFIER -> t1, t2 mut, t3 ;

mem_taskgroup_list: mem_taskgroup_list COMMA mem_taskgroup_name
    |	mem_taskgroup_name
    ;
    // this non-terminal is for writing list of mem taskgroups


mem_taskgroup_name: IDENTIFIER
    |   IDENTIFIER MUT
    ;
    // this non-terminal is for writing mem taskgroup name
    // IDENTIFIER mut

value: INT_LITERAL| FLOAT_LITERAL| STRING_LITERAL| CHARACTER_LITERAL| TRUE| FALSE| IDENTIFIER;
%%
int main(void) {
	yyparse();
}

