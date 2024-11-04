%{
#include <stdio.h>
#include "symbol_table/symbol_table.c"
#include "lex.yy.c"
extern int yylex();
extern void yyerror(const char *s);
extern int num_errs;
// extern int yydebug =0;
ASTNode* root = new ASTNode();
%}

%token ASSIGN PLUS MINUS MUL DIV MOD EQ NEQ GT LT GTE LTE AND OR NOT ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN

%token  SEMICOLON COLON LPAREN RPAREN LBRACKET RBRACKET LBRACE RBRACE COMMA DOT RANGE RANGE_INCL REFERENCE

%token  TASKGROUP TASK PROPERTIES ORDER MEM SHARED_DIRECTIVE SUPERVISOR ALL UNSAFE JOIN CALL

%token CHN_SEND CHANNEL_WAIT TASK_CHANNEL LOG ARROW

%token PARALLEL PRIVATE SHARED SCHEDULE NUM_THREADS REDUCTION DYNAMIC_SCHEDULE STATIC_SCHEDULE MUT

%token INT CHAR LONG BOOL FLOAT STRING

%token FUNC RETURN CONTINUE BREAK STRUCT IF ELSE FOR IN

%token TRUE FALSE IDENTIFIER INT_LITERAL FLOAT_LITERAL STRING_LITERAL CHARACTER_LITERAL

%define parse.error verbose

%start program

// Precedence
%left RANGE RANGE_INCL
%right ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN
%left OR 
%left AND
%left EQ NEQ    
%left GT LT GTE LTE
%left PLUS MINUS
%left MUL DIV MOD
%left DOT
%right NOT  // Unary operator problem




%%
program: statement_list {}
    ;


statement_list: statement_list statement{
        root->add_child($2);
    }
    | statement{root->add_child($1);}
    ;
// ------------------------------------- Data Types ----------------------------------------
generic_dtypes: INT { $$ = new ASTNode(type_t, int_t);}
    | LONG {$$ = new ASTNode(type_t, long_t);}
    | FLOAT {$$ = new ASTNode(type_t, float_t);}
    | STRING {$$ = new ASTNode(type_t, string_t);}
    | BOOL {$$ = new ASTNode(type_t, bool_t);}
    | CHAR {$$ = new ASTNode(type_t, char_t);}
    | STRUCT IDENTIFIER  {$$= new ASTNode(type_t, struct_t);}
    ;

dtype: generic_dtypes { $$ = $1;}
    | array {$$ = $1;}
    ;

array: generic_dtypes dims initializer_dims
    ;

array_element: IDENTIFIER dims ;

dims: dims LBRACKET expression RBRACKET
    | LBRACKET expression RBRACKET
    ; 

initializer_dims: LBRACKET expression COMMA expression RBRACKET
    | 
    ;

statement: iterative_statement
    | selection_statement
    | expression_statement
    | compound_statement
    | function_declaration
    | taskgroup_statement
    | declaration_statement{
        $$ = $1;
    }
    | parallel_statement
    | struct_declaration
    | error SEMICOLON {  yyerrok; }
    ;
    // specifies various types of statements(these are the ones which won't need context of being in a function/Task)
inner_statement: iterative_statement
    | selection_statement
    | expression_statement
    | compound_statement
    | declaration_statement
    | parallel_statement
    | return_statement
    | error SEMICOLON {  yyerrok; }
    ;


inner_statement_list: non_empty_inner_statement_list
    |
    ;

non_empty_inner_statement_list: non_empty_inner_statement_list inner_statement
    | inner_statement
    ;
    // specifies various types of statements(these will be used in a function)

return_statement: RETURN expression SEMICOLON
    |   RETURN SEMICOLON
    |   BREAK SEMICOLON
    |   CONTINUE SEMICOLON
    ;

compound_statement: LBRACE inner_statement_list RBRACE
    | error RBRACE {  yyerrok; }
    ;
    // this non-terminal is for writing compound statement
    // { inner_statement }

struct_declaration: STRUCT IDENTIFIER struct_body SEMICOLON 
    | STRUCT error SEMICOLON {  yyerrok; }
    | STRUCT IDENTIFIER error SEMICOLON {  yyerrok; }
    ;

struct_body: LBRACE decl_stmt_list RBRACE
    | LBRACE error RBRACE {  yyerrok; }

//TODO: Can remove declaration_statement and write something which only allows constant literals to be assigned, currently it allows any expression to be assigned. need some semantic checks here.
decl_stmt_list: decl_stmt_list declaration_statement
    | declaration_statement
    ;


expression_statement: expression SEMICOLON
    | SEMICOLON
    ;
    // this non-terminal is for writing expression statement


expression: value{
       $$=new ASTNode(expr_stmt,$1->type);
       $$->name=to_string($1->value);
       
}
    | LPAREN expression RPAREN
    {  
        $$ = $2;
    }
    | assignment_expression
    {
        $$ = $1;
    }
    | arithmetic_expression
    {
        $$ = $1;
    }
    | logical_expression
    {
        $$ = $1;
    }
    | comparison_expression
    {
        $$ = $1;
    }
    | unary_expression
    {
        $$ = $1;
    }
    | function_call
    {
        $$ = $1;
    }
    ;
    // This is for writing various expressions

function_call: IDENTIFIER LPAREN function_call_tail
            | IDENTIFIER LPAREN error RPAREN {  yyerrok; }
            ;

    // this is for writing function call

function_call_tail : RPAREN 
                    | function_arguments RPAREN
                    ;

function_arguments: list_member initialiser_member_list_tail;


arithmetic_expression: 
    expression PLUS expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "+";

    }
    | expression MINUS expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "-";
    }
    | expression MUL expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "*";
    }
    | expression DIV expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "/";
    }
    | expression MOD expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "%";
    }
    ;
    // this non-terminal is for writing arithmetic expression

assignment_expression: 
    expression ASSIGN expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "=";
    }
    | expression ADD_ASSIGN expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "+=";
    }
    | expression SUB_ASSIGN expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "-=";
    }
    | expression MUL_ASSIGN expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "*=";
    }
    | expression DIV_ASSIGN expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "/=";
    }
    | expression MOD_ASSIGN expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "%=";
    }
    ;
    // this non-terminal is for writing assignment expression



unary_expression: 
    MINUS %prec NOT number_literals
    {
        $$=new ASTNode(expr_stmt);
        $$->name = "-unary";
        $$->add_child($2);
    }
    | NOT expression
    {
        $$=new ASTNode(expr_stmt);
        $$->name = "!unary";
        $$->add_child($2);
    }
    ;
    // this non-terminal is for writing unary expression

number_literals: FLOAT_LITERAL
    | INT_LITERAL
    ;

comparison_expression: 
    expression LT expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "<";

    }
    | expression GT expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = ">";
    }
    | expression GTE expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = ">=";
    }
    | expression LTE expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "<=";
    }
    | expression EQ expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "==";
    }
    | expression NEQ expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "!=";
    }
    ;
    // this non-terminal is for writing comparison expression   

logical_expression: expression AND expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "&&";
    }
    | expression OR expression
    {
        $$ = new ASTNode();
        $$->kind = expr_stmt;
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "||";
    }
    ;
    // this non-terminal is for writing logical expression

// declaration statements
declaration_statement: dtype declaration_list SEMICOLON{
        $$ = new ASTNode(decl_stmt, $1->type);
        $$->add_child($2);
        delete $1;
    }
    | dtype REFERENCE declaration_list SEMICOLON{
        $$ = new ASTNode(decl_stmt, $1->type);
        $$->type.reference = true;
        $$->add_child($2);

        delete $1;
    }
    ;
    // variable declaration

declaration_list : declaration_list COMMA declaration{
        $1->reach_end()->next = $3;
        $$ = $1;
    }
    | declaration {
        $$ = $1;    
    }
    ;

//TODO: references are dicey, should be assigned to variable only? or any expression
declaration: IDENTIFIER optional_value_assignment{
        if($2 == NULL){
            $$ = new ASTNode(variable);
            $$->name = $1->name;
        }
        else{
            $$ = new ASTNode(expr_stmt);
        }
    }
    ;

optional_value_assignment: ASSIGN initializer  {$$ = new ASTNode(expr_stmt);}   //optional value assign
    | { $$ = NULL; }
    ;

// initialisers
initializer : expression    // assign an expression
    | list_initialiser  //this is used to initialise arrays and struct like {{1,2,3},{4,5,6},{7,8,9}}
    ; 

list_initialiser: LBRACE list_member initialiser_member_list_tail RBRACE
    | LBRACE error RBRACE {  yyerrok; }
    ; 

initialiser_member_list_tail: COMMA list_member initialiser_member_list_tail       // (,list_member)*
                            |
                            ;
list_member : list_initialiser  // a single member in a list
        | expression
        ;



iterative_statement:  FOR  iteration_condition compound_statement
    ;

iteration_condition: iteration_type1
    | iteration_type2
    ;

iteration_type1: LPAREN expression_statement expression_statement empty_expression RPAREN 
    | error RPAREN {  yyerrok; }
    ;

iteration_type2: iterator IN container
    | error SEMICOLON {  yyerrok; }
    ;

empty_expression: expression
    | 
    ;


container: variable
    | array_literal
    ;
    // basically arrays
iterator: IDENTIFIER
    |REFERENCE IDENTIFIER
    ; 
    // possibility for iterator variable


number: INT_LITERAL
    | variable
    ;
    // number used for iteration in range

selection_statement: IF selection_condition compound_statement if_chain_statement
    | IF selection_condition compound_statement ELSE compound_statement
    ;
    // if-then-else

selection_condition: LPAREN expression RPAREN
    | error RPAREN  {yyerrok;}
    | LPAREN error RPAREN {yyerrok;}
    | LPAREN expression error SEMICOLON {yyerrok;}
    ;

if_chain_statement: ELSE selection_statement
    |
    ;
    // if else-if else-if else


function_declaration: FUNC IDENTIFIER dtype params  compound_statement
    | FUNC IDENTIFIER dtype params SEMICOLON //function prototype
    | FUNC error RBRACE {  yyerrok; }
    | FUNC IDENTIFIER error RBRACE {  yyerrok; }
    | FUNC IDENTIFIER dtype error RBRACE {  yyerrok; }
    ;

params: LPAREN parameter_list RPAREN
    | LPAREN error RPAREN {  yyerrok; }
    | error RPAREN {  yyerrok; }
    ;



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
    | PARALLEL LPAREN parallel_stmt_argument_list RPAREN iterative_statement // parallel for statement
    ;

parallel_stmt_argument_list: parallel_stmt_argument_list COMMA parallel_stmt_argument
    | parallel_stmt_argument
    ;

// this consists of all the arguments which are inside the parallel construct like shared, private, reduction, etc. 
parallel_stmt_argument: SHARED ASSIGN LBRACKET identifier_list RBRACKET 
    | PRIVATE ASSIGN LBRACKET identifier_list RBRACKET 
    | REDUCTION ASSIGN LBRACKET reduction_list RBRACKET;
    | SCHEDULE ASSIGN schedule_list
    | NUM_THREADS ASSIGN number
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

taskgroup_statement: TASKGROUP IDENTIFIER taskgroup_declaration_list LBRACE taskgroup_definition RBRACE SEMICOLON
	;  // this non-terminal is for @TaskGroup t1{ taskgroup_definition}

taskgroup_declaration_list: LPAREN taskgroup_argument_list RPAREN
    |
    | error RPAREN {  yyerrok; }
    ;

taskgroup_argument_list: taskgroup_argument COMMA taskgroup_argument
    |   taskgroup_argument
    |
    ;

taskgroup_argument: LOG ASSIGN STRING_LITERAL
    | NUM_THREADS ASSIGN expression
    ;

taskgroup_definition:  task_declaration_list properties_declaration 
    ; 


task_declaration_list: task_declaration_list task_declaration
    | 
    ; // this non-terminal is for writing list of tasks

task_declaration: TASK IDENTIFIER task_argument LBRACE task_statement_list RBRACE 
    | SUPERVISOR IDENTIFIER LBRACE supervisor_statement_list RBRACE
    | error RPAREN { yyerrok;}
    ; /* this non-terminal is for writing task or supervisor 
        @Task t1(num_threads = exp){ task_statements} or @Supervisor t1{ task_statements} */

task_argument:  LPAREN NUM_THREADS ASSIGN expression RPAREN
    | 
    |   error RPAREN {  yyerrok; }
    ;

supervisor_statement_list: supervisor_statement_list supervisor_statement
    | 
    ;

supervisor_statement:  iterative_statement
    | selection_statement
    | expression_statement
    | compound_statement
    | declaration_statement
    | parallel_statement
	| channel_statement
    | other_statements
    | return_statement 
    | error SEMICOLON {  yyerrok;}
    ;


task_statement_list: task_statement_list task_statement
    |   
    ;

//TODO: task_statements STILL HAVE TO FIX STUFF HERE.
task_statement: iterative_statement
    | selection_statement
    | expression_statement
    | compound_statement
    | declaration_statement
    | parallel_statement
    | return_statement
    | channel_statement
    | error SEMICOLON {  yyerrok; }
    ;

properties_declaration: PROPERTIES LBRACE taskgroup_properties RBRACE
    |
    | error RBRACE {  yyerrok; }
    ;

taskgroup_properties: taskgroup_properties taskgroup_property
    | 
    ;

taskgroup_property: order_block
                | shared_block
                | mem_block
                | error RBRACE {  yyerrok; }
                ;

order_block: ORDER LBRACE order_rule_list RBRACE
    | error SEMICOLON {  yyerrok; }
    ;

order_rule_list: order_rule_list order_rule 
    | 
    ;
    
order_rule: order_rule_start order_rule_mid order_rule_end 
    ;

order_rule_start: ALL ARROW   
    |
    ;
    // ALL ->m

order_rule_mid: order_rule_mid ARROW identifier_list 
    | identifier_list
    ;

order_rule_end: ARROW ALL SEMICOLON  
    | SEMICOLON
    ;


shared_block: SHARED_DIRECTIVE LBRACE shared_rule_list RBRACE
    ;
    // this non-terminal is for writing shared rules
    // SHARED { shared_rule_list }

shared_rule_list: shared_rule_list shared_rule 
    | 
    ;
    // this non-terminal is for writing list of shared rules

shared_rule: identifier_list COLON dtype ARROW identifier_list SEMICOLON    
    | error SEMICOLON {  yyerrok; } 
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


mem_statement: identifier_list ARROW mem_task_list SEMICOLON
    | error SEMICOLON {  yyerrok; }
    ;

mem_task_list: mem_task_list COMMA mem_task_name
    |	mem_task_name
    ;


mem_task_name: IDENTIFIER
    |   IDENTIFIER MUT
    ;

other_statements: join_statement
    | call_statement
    ;

join_statement: JOIN IDENTIFIER  SEMICOLON
    ;

call_statement: CALL IDENTIFIER  SEMICOLON
    ;


array_literal: expression RANGE expression 
    | expression RANGE_INCL expression
    ;
    // this non-terminal is for writing array literal

literals: INT_LITERAL| FLOAT_LITERAL| STRING_LITERAL| CHARACTER_LITERAL| TRUE| FALSE | array_literal ;
    // constant literals

value: literals 
    | variable
    ;
    // this non-terminal is for writing value

variable: array_element
    | IDENTIFIER 
    | variable DOT variable
    ;

identifier_list: identifier_list COMMA IDENTIFIER
    | IDENTIFIER
    ;
    // this non-terminal is for writing list of identifiers
// no new rules required, if nothing is matched then.

%%
int main(int argc, char** argv) {
    if(argc > 1) {
        yydebug = 1;
    }
	yyparse();
    traverse(root);
    return num_errs;
}

