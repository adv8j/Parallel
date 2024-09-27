%{
#include <stdio.h>
int yylex(void);
extern void yyerror(char *s);
%}


%token ASSIGN PLUS MINUS MUL DIV MOD EQ NEQ GT LT GTE LTE AND OR NOT ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN

%token  SEMICOLON COLON LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE COMMA DOT RANGE RANGE_INCL REFERENCE

%token  TASKGROUP TASK PROPERTIES ORDER MEM SHARED_DIRECTIVE SUPERVISOR ALL UNSAFE JOIN CALL

%token CHN_SEND CHANNEL_WAIT TASK_CHANNEL LOG ARROW

%token PARALLEL PRIVATE SHARED SCHEDULE NUM_THREADS REDUCTION DYNAMIC_SCHEDULE STATIC_SCHEDULE MUT

%token INT CHAR LONG BOOL FLOAT STRING

%token FUNC RETURN CONTINUE BREAK STRUCT IF ELSE FOR IN

%token TRUE FALSE IDENTIFIER SHARED_IDENTIFIER INT_LITERAL FLOAT_LITERAL STRING_LITERAL CHARACTER_LITERAL

%define parse.error verbose

%start program

// Precedence

%right ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%left OR 
%left AND
%left EQ NEQ
%left GT LT GTE LTE
%left PLUS MINUS
%left MUL DIV MOD
%right NOT  // Unary operator problem




%%
program: statement_list {printf("Program is correct\n");}
    ;

statement_list: one_or_more_statements
|   ;
one_or_more_statements: one_or_more_statements statement
    | statement
    ;
    // this non-terminal is for writing list of statements


generic_dtypes: INT 
    | LONG
    | FLOAT
    | STRING
    | BOOL
    | CHAR
    | STRUCT IDENTIFIER 
    ;
    // for struct still have to find better solution

dtype: generic_dtypes
    | array
    ;
    // this non-terminal is for writing data type

array: generic_dtypes dims initializer_dims
    ;
    // this non-terminal is for writing array data type

array_element: IDENTIFIER dims ;
    // this non-terminal is for writing array element
    // x[2][3]

// Needs work for array initialization and all : TODO
dims: dims LBRACKET number RBRACKET
    | LBRACKET number RBRACKET
    ; 
    // this non-terminal is for writing array dimensions

initializer_dims: LBRACKET number COMMA number RBRACKET
    | 
    ;
    // this non-terminal is for writing array dimensions in initialization



statement: iterative_statement
    | selection_statement
    | expression_statement
    | compound_statement
    | function_declaration
    | taskgroup_statement
    | declaration_statement
    | parallel_statement
    | struct_declaration
    ;
    // specifies various types of statements(these are the ones which won't need context of being in a function/Task)
inner_statement: one_or_more_inner_statements
| ;

one_or_more_inner_statements: one_or_more_inner_statements inner_statement_list
|   inner_statement_list;

inner_statement_list: iterative_statement
    | selection_statement
    | expression_statement
    | compound_statement
    | declaration_statement
    | parallel_statement
    | return_statement
    ;
    // specifies various types of statements(these will be used in a function)

return_statement: RETURN expression SEMICOLON
|   BREAK SEMICOLON
|   CONTINUE SEMICOLON
	;

compound_statement: LBRACE inner_statement RBRACE
    ;
    // this non-terminal is for writing compound statement
    // { inner_statement }

struct_declaration: STRUCT IDENTIFIER LBRACE member_data_list RBRACE SEMICOLON;
member_data_list: member_data_list member_data      // list for member data of struct  // this is used while declaring a struct
                | ;

member_data: dtype IDENTIFIER value_assign SEMICOLON        //one member data of a struct   // used while initialising a struct

expression_statement: expression SEMICOLON
    | SEMICOLON
    ;
    // this non-terminal is for writing expression statement




expression: value
    | LPAREN expression RPAREN
    | assignment_expression
    | arithmetic_expression
    | logical_expression
    | comparison_expression
    | unary_expression
    | function_call
    ;
    // This is for writing various expressions

function_call: IDENTIFIER LPAREN RPAREN
|   IDENTIFIER LPAREN fn_call_argument_list RPAREN;

fn_call_argument_list: fn_call_argument_list COMMA expression
    | expression
    |
    ;
    // this is for writing function call



unary_operator: MINUS
    | NOT
    ;
    // this non-terminal is for writing unary operators


arithmetic_expression: expression PLUS expression
    | expression MINUS expression
    | expression MUL expression
    | expression DIV expression
    | expression MOD expression
    ;
    // this non-terminal is for writing arithmetic expression

assignment_expression: expression ASSIGN expression
    | expression ADD_ASSIGN expression
    | expression SUB_ASSIGN expression
    | expression MUL_ASSIGN expression
    | expression DIV_ASSIGN expression
    | expression MOD_ASSIGN expression
    ;
    // this non-terminal is for writing assignment expression



unary_expression: unary_operator number
    ;
    // this non-terminal is for writing unary expression


comparison_expression: expression LT expression
    | expression GT expression
    | expression GTE expression
    | expression LTE expression
    | expression EQ expression
    | expression NEQ expression
    ;
    // this non-terminal is for writing comparison expression   

logical_expression: expression AND expression
    | expression OR expression
    ;
    // this non-terminal is for writing logical expression


declaration_statement: dtype declaration_list SEMICOLON;
    // variable declaration

declaration_list : declaration_list COMMA declaration
    | declaration
    ;


declaration: REFERENCE IDENTIFIER ASSIGN IDENTIFIER
    | IDENTIFIER value_assign
    ;

value_assign: ASSIGN initializer    //optional value assign
    | 
    ;
initializer : expression    // assign an expression
    | list_initialiser ; //this is used to initialise arrays and struct like {{1,2,3},{4,5,6},{7,8,9}}

list_initialiser: LBRACE list_member initialiser_member_list_tail RBRACE;

initialiser_member_list_tail: COMMA list_member initialiser_member_list_tail       // (,list_member)*
                            | ;
list_member : list_initialiser  // a single member in a list
        | expression;


iterative_statement:  FOR LPAREN expression_statement expression_statement expression RPAREN compound_statement
    |FOR iterator IN container  compound_statement
    ;
    // 1. for(.. ;.. ; ..)
    // 2. for(id in 1..2)
    // 3. for x in arr

container: IDENTIFIER
    | array_literal 
    ;
    // basically arrays
iterator: IDENTIFIER
    |REFERENCE IDENTIFIER
    ; 
    // possibility for iterator variable

range: RANGE
    |RANGE_INCL
    ;
    // types of range operators

number: INT_LITERAL
    |IDENTIFIER
    ;
    // number used for iteration in range

selection_statement: 
    IF LPAREN expression RPAREN compound_statement if_chain_statement
    | IF LPAREN expression RPAREN compound_statement ELSE compound_statement
    ;
    // if-then-else

if_chain_statement: ELSE selection_statement
    |
    ;
    // if else-if else-if else


function_declaration: FUNC IDENTIFIER dtype LPAREN parameter_list RPAREN compound_statement
    ;
    // Function declaration, (return can never be ref)


datatype_and_ref: parameter_dtype| dtype REFERENCE;
// includes the data types and references (like: int&)

parameter_dtype : generic_dtypes
    | generic_dtypes dims 
    ;

parameter_list: parameter_list COMMA parameter_declaration
	| parameter_declaration
    | 
	;

parameter_declaration: datatype_and_ref IDENTIFIER 
    | datatype_and_ref IDENTIFIER ASSIGN expression // for default arguments
    ; 


//parallel statements
parallel_statement: PARALLEL LPAREN parallel_stmt_argument_list RPAREN compound_statement // parallel block statement
    | PARALLEL compound_statement
    | PARALLEL LPAREN parallel_stmt_argument_list RPAREN iterative_statement; // parallel for statement

parallel_stmt_argument_list: parallel_stmt_argument_list COMMA parallel_stmt_argument
    | parallel_stmt_argument;

// this consists of all the arguments which are inside the parallel construct like shared, private, reduction, etc. 
parallel_stmt_argument: SHARED ASSIGN LBRACKET identifier_list RBRACKET 
    | PRIVATE ASSIGN LBRACKET identifier_list RBRACKET 
    | REDUCTION ASSIGN LBRACKET reduction_list RBRACKET;
    | SCHEDULE ASSIGN schedule_list
    | NUM_THREADS ASSIGN INT_LITERAL
    ;

schedule_list: STATIC_SCHEDULE|	DYNAMIC_SCHEDULE;


// reduction list contains operator: identifier list. for eg. +: a,b,c
reduction_list: reduction_list SEMICOLON reduction_operator_list 
    | reduction_operator_list 
    ;

// reduction operator list contains all the reduction operators like +, -, *, /, % and the reduction is applied on operator assign versions (like +=, -=, *=, /=, %=).
reduction_operator_list: PLUS COLON identifier_list
    | MINUS COLON identifier_list
    | MUL COLON identifier_list
    | DIV COLON identifier_list
    | MOD COLON identifier_list
    ; 
// conditional signals and return statements
channel_statement: signal_statement SEMICOLON
    | wait_statement SEMICOLON
    ;

// signal statement which can be either .ct or .ct <- <any-value>, or .ct(all) or .ct(all) <- x;
signal_statement: TASK_CHANNEL task_all CHN_SEND expression
    | TASK_CHANNEL task_all
    ;

task_all: LPAREN ALL RPAREN 
    |
    ;

// wait statement which can be either .wt{<task-name>, number} or .wt{<task-name>, number} -> <identifier> ;
wait_statement: CHANNEL_WAIT LBRACE IDENTIFIER COMMA expression RBRACE 
    | CHANNEL_WAIT LBRACE IDENTIFIER COMMA expression RBRACE ARROW IDENTIFIER
    ;

taskgroup_statement: TASKGROUP IDENTIFIER LPAREN taskgroup_argument_list RPAREN LBRACE taskgroup_definition RBRACE SEMICOLON
	| TASKGROUP IDENTIFIER  LBRACE  taskgroup_definition RBRACE SEMICOLON
	;  // this non-terminal is for @TaskGroup t1{ taskgroup_definition}

taskgroup_argument_list: taskgroup_argument COMMA taskgroup_argument
|   taskgroup_argument;

taskgroup_argument: LOG ASSIGN STRING_LITERAL
    | NUM_THREADS ASSIGN number
    ;
taskgroup_definition:  task_declaration_list properties_declaration 
    |
    ; // this non-terminal is for writing list of tasks followed by properties


task_declaration_list: task_declaration_list task_declaration
    | task_declaration
    ; // this non-terminal is for writing list of tasks

task_declaration: TASK IDENTIFIER LBRACE task_statement_list RBRACE 
    | TASK IDENTIFIER LPAREN NUM_THREADS ASSIGN number RPAREN LBRACE task_statement_list RBRACE 
    | SUPERVISOR IDENTIFIER LBRACE supervisor_statement_list RBRACE
    ; /* this non-terminal is for writing task or supervisor 
        @Task t1{ task_statements} or @Supervisor t1{ task_statements} */


supervisor_statement_list: supervisor_statement_list supervisor_statements
    | 
    ;

supervisor_statements:  iterative_statement
    | selection_statement
    | expression_statement
    | compound_statement
    | declaration_statement
    | parallel_statement
	| channel_statement
    | other_statements
    ;


task_statement_list: task_statement_list task_statements
    |   
    ;

// #TODO: task_statements STILL HAVE TO FIX STUFF HERE.
task_statements: iterative_statement
    | selection_statement
    | expression_statement
    | compound_statement
    | declaration_statement
    | parallel_statement
	| channel_statement
    ;
    // this non-terminal is for writing list of statements in a task (basically allowed statements in a task)

properties_declaration: PROPERTIES LBRACE taskgroup_properties RBRACE
    |
    ;
    // this non-terminal is for writing properties of a taskgroup
    // PROPERTIES { taskgroup_properties }

taskgroup_properties: taskgroup_properties taskgroup_property
    | 
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
    | 
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
    | 
    ;
    // this non-terminal is for writing list of shared rules

shared_rule: identifier_list COLON dtype ARROW identifier_list SEMICOLON
    ;
    // this non-terminal is for writing shared rule
    // IDENTIFIER : dtype -> IDENTIFIER


mem_block: MEM LBRACE mem_statement_list RBRACE
    |	MEM UNSAFE LBRACE mem_statement_list RBRACE
    ;
    // this non-terminal is for writing mem rules
    // @Mem { mem_statement_list }


mem_statement_list: mem_statement_list mem_statement 
    |   
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

other_statements: join_statement
    | call_statement
    ;

join_statement: JOIN IDENTIFIER  SEMICOLON
    ;
    // this non-terminal is for writing join statement
    // JOIN t1 ;

call_statement: CALL IDENTIFIER  SEMICOLON
    ;
    // this non-terminal is for writing call statement, calling a task from supervisor
    // CALL t1 ;

array_literal: number range number 
    ;
    // this non-terminal is for writing array literal

literals: INT_LITERAL| FLOAT_LITERAL| STRING_LITERAL| CHARACTER_LITERAL| TRUE| FALSE | array_literal ;
    // constant literals

value: literals 
    | identifier_chain
    | array_element
    ;
    // this non-terminal is for writing value

identifier_chain : identifier_chain DOT IDENTIFIER
    | IDENTIFIER
    ;
// no new rules required, if nothing is matched then.

%%
int main(void) {
	yyparse();
}

