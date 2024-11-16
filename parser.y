%{
#include <stdio.h>
#include "lex.yy.c"
extern int yylex();
extern void yyerror(const char *s);
extern int num_errs;
// extern int yydebug =0;
ASTNode* root ;
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
%right DOT
%right NOT  // Unary operator problem



%%
program: statement_list {}
    ;


statement_list: statement_list statement{
        root ->reach_end()-> next = $2;
    }
    | statement{root->next = $1;}
    ;
// Data Types
generic_dtypes: INT { $$ = new ASTNode(type_t, int_t);}
    | LONG {$$ = new ASTNode(type_t, long_t);}
    | FLOAT {$$ = new ASTNode(type_t, float_t);}
    | STRING {$$ = new ASTNode(type_t, string_t);}
    | BOOL {$$ = new ASTNode(type_t, bool_t);}
    | CHAR {$$ = new ASTNode(type_t, char_t);}
    | STRUCT IDENTIFIER  {
        $$ = new ASTNode(type_t, struct_t);
        ($$ -> type).init_exp_or_id = $2;
    }
    ;

dtype: generic_dtypes { $$ = $1;}
    | array {$$ = $1;}
    ;

func_dtype: generic_dtypes {$$ = $1;}
        

array: generic_dtypes fixed_dims initializer_dims{
    $$ = $1;
    ASTNode* dims_head = $2;
    while(dims_head){
        ($$ -> type).ndims.push_back(stoi(dims_head -> name));
        ASTNode* temp = dims_head;
        dims_head = dims_head -> next;
        delete temp;
    }

    if($3) {
        ($$ -> type).ndims.push_back(stoi($3 -> name));
        ASTNode* temp = $3;
        $3 = $3 -> next;
        delete temp;
        ($$ -> type).init_exp_or_id = $3;
    }
}
    ;

array_element: IDENTIFIER dims {
    $$ = new ASTNode(array_element);
    $$ -> add_child($1);
    $$ -> add_child($2);
};

fixed_dims: fixed_dims LBRACKET INT_LITERAL RBRACKET{
    $$ = $1;
    $$ -> reach_end() -> next = $3;
}
    | LBRACKET INT_LITERAL RBRACKET{
        $$ = $2;
    }
    ;

dims: dims LBRACKET expression RBRACKET{
    $$ = $1;
    $$ -> reach_end() -> next = $3;
}
    | LBRACKET expression RBRACKET{
        $$ = $2;
    }
    ;

initializer_dims: LBRACKET INT_LITERAL COMMA expression RBRACKET{
    $$ = $2;
    $$ -> reach_end() -> next = $4;
}
    | {$$ = NULL;}
    ;

statement: iterative_statement
    | selection_statement{
        $$ = new ASTNode(selection_stmt);
        $$->convert_to_children($1);
    }
    | expression_statement
    | compound_statement
    | function_declaration
    | taskgroup_statement{$$ = $1;}
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
    | expression_statement  {$$ = $1;} 
    | compound_statement    {}
    | declaration_statement{$$ = $1;}
    | parallel_statement
    | return_statement
    | error SEMICOLON {  yyerrok; }
    ;


inner_statement_list: non_empty_inner_statement_list    {$$ = $1;}
    |   {$$ = nullptr;}
    ;

non_empty_inner_statement_list: non_empty_inner_statement_list inner_statement  {
    $$ = $1;
    $$ -> reach_end() -> next = $2;
}
    | inner_statement   {$$ = $1;}
    ;
    // specifies various types of statements(these will be used in a function)

return_statement: RETURN expression SEMICOLON{
    $$ = new ASTNode(return_stmt);
    $$ -> name = "return";
    $$ -> add_child($1);
}
    |   RETURN SEMICOLON{
        $$ = new ASTNode(return_stmt);
        $$ -> name = "return";
    }
    |   BREAK SEMICOLON{
        $$ = new ASTNode(return_stmt);
        $$ -> name = "break";
    }
    |   CONTINUE SEMICOLON{
        $$ = new ASTNode(return_stmt);
        $$ -> name = "continue";
    }
    ;

compound_statement: LBRACE inner_statement_list RBRACE{
    $$ = new ASTNode(compound_stmt);
    $$ -> next = $2;
}
    | error RBRACE {  yyerrok; }
    ;
    // this non-terminal is for writing compound statement
    // { inner_statement }

struct_declaration: STRUCT IDENTIFIER struct_body SEMICOLON {
    $$ = new ASTNode(struct_decl);
    $$ -> add_child($2);
    $$ -> add_child($3);
}
    | STRUCT error SEMICOLON {  yyerrok; }
    | STRUCT IDENTIFIER error SEMICOLON {  yyerrok; }
    ;

struct_body: LBRACE decl_stmt_list RBRACE{
    $$ = $2;
}
    | LBRACE error RBRACE {  yyerrok; }

//TODO: Can remove declaration_statement and write something which only allows constant literals to be assigned, currently it allows any expression to be assigned. need some semantic checks here.
decl_stmt_list: decl_stmt_list declaration_statement{
    $$ = $1;
    $$ -> reach_end() -> next = $2;
}
    | declaration_statement{
        $$ = $1;
    }
    ;


expression_statement: expression SEMICOLON {$$ = $1;}
    | SEMICOLON {$$ = nullptr;}
    ;
    // this non-terminal is for writing expression statement


expression: value{
       $$ = $1;
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

function_call: IDENTIFIER LPAREN function_call_tail {
    $$ = new ASTNode(function_call_stmt);
    $$->name=$1->name;
    if($3){
        $$ -> add_child($3);
    }
    delete $1;
}
            | IDENTIFIER LPAREN error RPAREN {  yyerrok; }
            ;

    // this is for writing function call

function_call_tail : RPAREN {$$ = NULL;}
                    | function_arguments RPAREN {$$ = new ASTNode(arg_list);
                    $$ -> convert_to_children($1);
                    }
                    ;

function_arguments: function_arguments COMMA expression{
    $$ = $1;
    $3->kind=arg_t;
    $$->next = $3 ;
}
    | expression{
        $$ = $1;
        $$->kind=arg_t;
        
    }




arithmetic_expression: 
    expression PLUS expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "+";

    }
    | expression MINUS expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "-";
    }
    | expression MUL expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "*";
    }
    | expression DIV expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "/";
    }
    | expression MOD expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "%";
    }
    ;
    // this non-terminal is for writing arithmetic expression

assignment_expression: 
    expression ASSIGN expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "=";
    }
    | expression ADD_ASSIGN expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "+=";
    }
    | expression SUB_ASSIGN expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "-=";
    }
    | expression MUL_ASSIGN expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "*=";
    }
    | expression DIV_ASSIGN expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "/=";
    }
    | expression MOD_ASSIGN expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "%=";
    }
    ;
    // this non-terminal is for writing assignment expression



unary_expression: 
    MINUS %prec NOT expression
    {
        $$=new ASTNode(expr_stmt);
        $$->name = "-";
        $$->add_child($2);
    }
    | NOT expression
    {
        $$=new ASTNode(expr_stmt);
        $$->name = "!";
        $$->add_child($2);
    }
    ;
    // this non-terminal is for writing unary expression



comparison_expression: 
    expression LT expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "<";

    }
    | expression GT expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = ">";
    }
    | expression GTE expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = ">=";
    }
    | expression LTE expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "<=";
    }
    | expression EQ expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "==";
    }
    | expression NEQ expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "!=";
    }
    ;
    // this non-terminal is for writing comparison expression   

logical_expression: expression AND expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "&&";
    }
    | expression OR expression
    {
        $$ = new ASTNode(expr_stmt, unknown_t);
        
        $$->add_child($1);
        $$->add_child($3);
        $$->name = "||";
    }
    ;
    // this non-terminal is for writing logical expression

// declaration statements
declaration_statement: dtype declaration_list SEMICOLON{
        $$ = new ASTNode(decl_stmt, $1->type);
        $$->convert_to_children($2);
        delete $1;
    }
    | dtype REFERENCE declaration_list SEMICOLON{
        $$ = new ASTNode(decl_stmt, $1->type);
        $$->type.reference = true;
        $$->convert_to_children($3);
        delete $1;
    }
    ;
    // variable_t declaration

declaration_list : declaration_list COMMA declaration{
        $1->reach_end()->next = $3;
        $$ = $1;
    }
    | declaration {
        $$ = $1;    
    }
    ;

//TODO: references are dicey, should be assigned to variable_t only? or any expression
declaration: IDENTIFIER optional_value_assignment{
        if($2 == NULL){ //when there is no assignment
            $$ = new ASTNode(variable_t);
            $$->name = $1->name;
        }
        else{
            $$ = new ASTNode(variable_t);
            $$-> name = $1 -> name;
            $$ -> add_child($2);
        }
    }
    ;

optional_value_assignment: ASSIGN initializer  {$$ = $2;}   //optional value assign
    | { $$ = NULL; }
    ;

// initialisers
initializer : expression  {
    $$ = $1;
}  // assign an expression
    | list_initialiser{
        $$ = $1;
    }  //this is used to initialise arrays and struct like {{1,2,3},{4,5,6},{7,8,9}}
    ; 

list_initialiser: LBRACE list_member initialiser_member_list_tail RBRACE{
    $$ = new ASTNode(list_init);
    $$ -> add_child($2);
    $2 -> next = $3;

}
    | LBRACE error RBRACE {  yyerrok; }
    ; 

initialiser_member_list_tail: COMMA list_member initialiser_member_list_tail       // (,list_member)*
{
    $$ = $2;
    $$ -> next = $3;
}
|{ $$ = NULL; }
;
list_member : list_initialiser  // a single member in a list
{ $$ = $1; }
    | expression{ $$ = $1 ; }
        ;



iterative_statement:  FOR  iteration_condition compound_statement{
    $$ = new ASTNode(iterative_stmt);
    $$ -> add_child($2);
    $$ -> add_child($3);
}
    ;

iteration_condition: iteration_type1{$$ = $1;}
    | iteration_type2{$$ = $1;}
    ;

iteration_type1: LPAREN expression_statement expression_statement empty_expression RPAREN {
    $$ = new ASTNode(itr_type);
    $$ -> name = "type1";
    $$ -> add_child($2);
    $$ -> add_child($3);
    $$ -> add_child($4);
}
    | error RPAREN {  yyerrok; }
    ;

iteration_type2: iterator IN container{
    $$ = new ASTNode(itr_type);
    $$ -> name = "type2";
    $$ -> add_child($1);
    $$ -> add_child($3);
}
    | error SEMICOLON {  yyerrok; }
    ;

empty_expression: expression{$$ = $1;}
    | {$$ = nullptr;}
    ;


container: variable_t{
    $$ = $1;
}
    | array_literal{
        $$ = $1;
    }
    ;
    // basically arrays
iterator: IDENTIFIER{
    $$ = $1;
}
    |REFERENCE IDENTIFIER{
        $$ = $2;
        ($$ -> type).reference = true;
    }
    ; 
    // possibility for iterator variable_t


number: INT_LITERAL{$$ = $1;}
    | variable_t{$$ = $1;}
    ;
    // number used for iteration in range

selection_statement: IF selection_condition compound_statement if_chain_statement{
        $$ = new ASTNode(if_stmt);
        $$->add_child($2);
        $$->add_child($3);
        $$->next = $4;
    }
    /*
       if else if else if else if else
    */
    ;
    // if-then-else

selection_condition: LPAREN expression RPAREN{
        $$= $2;
        $$->kind=cond_stmt;
    }
    | error RPAREN  {yyerrok;}
    | LPAREN error RPAREN {yyerrok;}
    | LPAREN expression error SEMICOLON {yyerrok;}
    ;

if_chain_statement: ELSE else_case{$$=$2;}
    |   {$$     = NULL;}
    ;
    // if else-if else-if else
else_case: selection_statement{$$=$1;$$->kind=elseif_stmt;}
    | compound_statement{$$=$1;$$->kind=else_stmt;}

    ;

function_declaration: FUNC IDENTIFIER func_dtype params  compound_statement
    {
        $$ = new ASTNode(function_decl_stmt);
        $$->name = $2->name;
        $$->type=$3->type;       
        $$->add_child($4);// first child is the parameters
        $$->add_child($5);// second child is the compound statement

    }
    | FUNC IDENTIFIER func_dtype params SEMICOLON //function prototype
    {
        $$ = new ASTNode(prototype_stmt);
        $$->name = $2->name;
        $$->type=$3->type;
        $$->add_child($4);// first child is the parameters
    }
    | FUNC error RBRACE {  yyerrok; }
    | FUNC IDENTIFIER error RBRACE {  yyerrok; }
    | FUNC IDENTIFIER func_dtype error RBRACE {  yyerrok; }
    ;

params: LPAREN parameter_list RPAREN
    {
        $$ = new ASTNode(params_list);
        $$->convert_to_children($2);
    }
    | LPAREN error RPAREN {  yyerrok; }
    | error RPAREN {  yyerrok; }
    ;



datatype_and_ref: dtype
    {
        $$ = $1;
    }
    | dtype REFERENCE
    {
        $$ = $1;
        ($$ -> type).reference = true;
    }
    ;

// includes the data types and references (like: int&)



parameter_list: parameter_list COMMA parameter_declaration
    {
        $$ = $1;
        $1->reach_end()->next = $3;
    }
	| parameter_declaration
    {
        $$ = $1;
    }
    | // return null node if no parameters
    {
        $$ = NULL;
    }
	;

parameter_declaration: datatype_and_ref IDENTIFIER 
    {
        $$ = new ASTNode(params_t);
        $$->name = $2->name;
        $$->type = $1->type;
    }
    | datatype_and_ref IDENTIFIER ASSIGN expression // for default arguments
    {
        $$ = new ASTNode(params_t);
        $$->name = $2->name;
        $$->type = $1->type;
        $$->add_child($4);// if params_t have any child its expression
    }
    ; 


//parallel statements
parallel_statement: PARALLEL LPAREN parallel_stmt_argument_list RPAREN compound_statement // parallel block statement
    {
            $$ = new ASTNode(parallel_stmt);
            $$->add_child($3);
            // $$->add_child($5); // uncommment this whenever compound stmt is done
            $$->add_child(new ASTNode(compound_stmt));
    }
    | PARALLEL compound_statement
    {
        $$ = new ASTNode(parallel_stmt);
        // $$->add_child($2); // uncommment this whenever compound stmt is done
        $$->add_child(new ASTNode(compound_stmt));
    }
    | PARALLEL LPAREN parallel_stmt_argument_list RPAREN iterative_statement // parallel for statement
    {
        $$ = new ASTNode(parallel_stmt);
        $$->add_child($3);
        // $$->add_child($5); // uncommment this whenever iterative stmt is done
        $$->add_child(new ASTNode(iterative_stmt,"loop"));

    }
    ;

parallel_stmt_argument_list: parallel_stmt_argument_list COMMA parallel_stmt_argument
    {
        $$ = $1;
        $1->reach_end()->next = $3;
    }
    | parallel_stmt_argument
    {
        $$ = $1;
    }
    ;

// this consists of all the arguments which are inside the parallel construct like shared, private, reduction, etc. 
parallel_stmt_argument: SHARED ASSIGN LBRACKET identifier_list RBRACKET 
    {
        $$ = new ASTNode(keyword, "shared");
        $$->add_child($4);
    }
    | PRIVATE ASSIGN LBRACKET identifier_list RBRACKET 
    {
        $$ = new ASTNode(keyword, "private");
        $$->add_child($4);
    }
    | REDUCTION ASSIGN LBRACKET reduction_list RBRACKET
    {
        $$ = new ASTNode(keyword, "reduction");
        $$->add_child($4);
    }
    | SCHEDULE ASSIGN schedule_list
    {
        $$ = new ASTNode(keyword, "schedule");
        $$->add_child($3);
    }
    | NUM_THREADS ASSIGN number
    {
        $$ = new ASTNode(keyword, "num_threads");
        $$->add_child($3);
    }
    ;

schedule_list: STATIC_SCHEDULE
{
    $$ = new ASTNode(keyword, "static");
}
|	DYNAMIC_SCHEDULE
{
    $$ = new ASTNode(keyword, "dynamic");
}
;


// reduction list contains operator: identifier list. for eg. +: a,b,c
reduction_list: reduction_list SEMICOLON reduction_operator_list
    {
        $$ = $1;
        $$->reach_end()->next = $3;
    }
    | reduction_operator_list 
    {
        $$ = $1;
    }
    ;

// reduction operator list contains all the reduction operators like +, -, *, /, % and the reduction is applied on operator assign versions (like +=, -=, *=, /=, %=).
reduction_operator_list: PLUS COLON identifier_list
    {
        $$ = new ASTNode(reduction_operator, "+");
        $$->add_child($3);
    }
    | MINUS COLON identifier_list
    {
        $$ = new ASTNode(reduction_operator, "-");
        $$->add_child($3);
    }
    | MUL COLON identifier_list
    {
        $$ = new ASTNode(reduction_operator, "*");
        $$->add_child($3);
    }
    | DIV COLON identifier_list
    {
        $$ = new ASTNode(reduction_operator, "/");
        $$->add_child($3);
    }
    | MOD COLON identifier_list
    {
        $$ = new ASTNode(reduction_operator, "%");
        $$->add_child($3);
    }
    ;

// conditional signals and return statements
channel_statement: signal_statement SEMICOLON
    {
        $$ = $1;
    }
    | wait_statement SEMICOLON
    {
        $$ = $1;
    }
    ;

// signal statement which can be either .ct or .ct <- <any-value>, or .ct(all) or .ct(all) <- x;
signal_statement: TASK_CHANNEL task_all CHN_SEND expression
    {
        $$ = new ASTNode(channel_stmt,"signal");
        $$->add_child($2);
        $$->add_child($3);
    }
    | TASK_CHANNEL task_all
    {
        $$ = new ASTNode(channel_stmt,"signal");
        $$->add_child($2);
    }
    ;

task_all: LPAREN ALL RPAREN 
    {
        $$ = new ASTNode(keyword, "all");
    }
    |
    {$$ = NULL;}
    ;

// wait statement which can be either .wt{<task-name>, number} or .wt{<task-name>, number} -> <identifier> ;
wait_statement: CHANNEL_WAIT LBRACE IDENTIFIER COMMA expression RBRACE 
    {
        $$ = new ASTNode(channel_stmt,"wait");
        $$->add_child($3);
        $$->add_child($5);
    }
    | CHANNEL_WAIT LBRACE IDENTIFIER COMMA expression RBRACE ARROW IDENTIFIER
    ;

taskgroup_statement: TASKGROUP IDENTIFIER taskgroup_declaration_list LBRACE taskgroup_definition RBRACE SEMICOLON{
        $$ = $5;
        $$->name = $2->name;
    }
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

taskgroup_definition:  task_declaration_list properties_declaration {
        $$ = new ASTNode(taskgroup_stmt);
        $$->convert_to_children($1);
        if($2 != NULL){
            $$->convert_to_children($2);
        }
    }
    ;


task_declaration_list: task_declaration_list task_declaration{
        $1->reach_end()->next = $2;
        $$ = $1;
    }
    | task_declaration {$$ = $1;}
    ; // this non-terminal is for writing list of tasks

task_declaration: TASK IDENTIFIER task_argument LBRACE task_statement_list RBRACE{
        $$ = new ASTNode(task_stmt);
        $$->name = $2->name;
        $$->add_child($5);
    }
    | SUPERVISOR IDENTIFIER LBRACE supervisor_statement_list RBRACE{

        $$ = new ASTNode(supervisor_stmt);
        $$->name = $2->name;
        $$->add_child($4);
    }
    | error RPAREN { yyerrok;}
    ; /* this non-terminal is for writing task or supervisor 
        @Task t1(num_threads = exp){ task_statements} or @Supervisor t1{ task_statements} */

task_argument:  LPAREN NUM_THREADS ASSIGN expression RPAREN
    | 
    |   error RPAREN {  yyerrok; }
    ;

supervisor_statement_list: supervisor_statement_list supervisor_statement{
        $$ = $1;
        $1->reach_end()->next = $2;
    }
    | supervisor_statement {$$ = $1;}
    ;

supervisor_statement:  iterative_statement
    | selection_statement
    | expression_statement
    | compound_statement
    | declaration_statement {$$ = $1;}
    | parallel_statement
	| channel_statement
    | other_statements {$$ = $1;}
    | return_statement 
    | error SEMICOLON {  yyerrok;}
    ;


task_statement_list: task_statement_list task_statement {
        $$ = $1;
        $1->reach_end()->next = $2;
    }
    |   task_statement {$$ = $1;}
    ;

//TODO: task_statements STILL HAVE TO FIX STUFF HERE.
task_statement: iterative_statement
    | selection_statement
    | expression_statement
    | compound_statement
    | declaration_statement {$$ = $1;}
    | parallel_statement
    | return_statement
    | channel_statement
    | error SEMICOLON {  yyerrok; }
    ;

properties_declaration: PROPERTIES LBRACE taskgroup_properties RBRACE{
        $$ = $3;
    }
    |{$$ = NULL;}
    | error RBRACE {  yyerrok; }
    ;

taskgroup_properties: taskgroup_properties taskgroup_property{
        if($2 == NULL){
            $$ = NULL;
        }
        else $1->reach_end()->next = $2;
    }
    | taskgroup_property{ 
        if($1 != NULL){
            $$ = $1;
        }
        else $$ = NULL;
    }
    ;

taskgroup_property : order_block {$$ = $1;}
                | shared_block {$$ = $1;}
                | mem_block {$$ = $1;}
                | error RBRACE {  yyerrok; }
                ;

order_block: ORDER LBRACE order_rule_list RBRACE{
        $$ = new ASTNode(properties_stmt, "order");
        $$->convert_to_children($3);
    }
    | error SEMICOLON {  yyerrok; }
    ;

order_rule_list: order_rule_list order_rule {
        $$ = $1;
        $$->reach_end()->next = $2;
    }
    | order_rule{
        $$ = $1;
    }
    ;
    
order_rule: order_rule_start order_rule_mid order_rule_end {
        $$ = new ASTNode(order_rule);
        if($1 != NULL){
            $$->add_child($1);
        }

        $$->convert_to_children($2);

        if($3 != NULL){
            $$->add_child($3);
        }
    }
    ;

order_rule_start: ALL ARROW{
        $$ = new ASTNode(order_node);
        ASTNode* x = new ASTNode(task_t, "all");
        $$->add_child(x);
    }
    |{ $$ = NULL;}
    ;
    // ALL ->m

order_rule_mid: order_rule_mid ARROW non_struct_identifier_list {
        $$ = $1;   
        ASTNode* x = new ASTNode(order_node);
        x->convert_to_children($3);
        for(ASTNode* child: x->children){
            child->kind = task_t;
        }
        $$->reach_end()->next = x;
    }
    | non_struct_identifier_list {
        $$ = new ASTNode(order_node);
        $$->convert_to_children($1);
        for(ASTNode* child: $$->children){
            child->kind = task_t;
        }
    }
    ;

non_struct_identifier_list: non_struct_identifier_list COMMA IDENTIFIER{
        $$ = $1;
        $1->kind = variable_t;
        $$->reach_end()->next = $3;
    }
    | IDENTIFIER {
        $$ = $1;
        $$->kind = variable_t;
    }
    ;

order_rule_end: ARROW ALL SEMICOLON  {
        $$ = new ASTNode(order_node);
        ASTNode* x = new ASTNode(task_t, "all");
        $$->add_child(x);
    }
    | SEMICOLON { $$ = NULL;}
    ;

shared_block: SHARED_DIRECTIVE LBRACE shared_rule_list RBRACE{
        $$ = new ASTNode(properties_stmt, "shared");
        $$->convert_to_children($3);
    }
    ;
    // this non-terminal is for writing shared rules
    // SHARED { shared_rule_list }

shared_rule_list: shared_rule_list shared_rule {
        $$ = $1;
        $$->reach_end()->next = $2;
    }
    | shared_rule {$$ = $1;}
    ;
    // this non-terminal is for writing list of shared rules

shared_rule: non_struct_identifier_list COLON dtype ARROW non_struct_identifier_list SEMICOLON    {
        $$ = new ASTNode(shared_rule, $3->type);
        ASTNode* left = new ASTNode(shared_node);
        ASTNode* right = new ASTNode(shared_node);
        left->convert_to_children($1);
        for(ASTNode* child: left->children){
            child->kind = variable_t;
        }
        right->convert_to_children($5);
        for(ASTNode* child: right->children){
            child->kind = task_t;
        }
        $$->add_child(left);
        $$->add_child(right);
    }
    | error SEMICOLON {  yyerrok; } 
    ;
    // this non-terminal is for writing shared rule
    // IDENTIFIER : dtype -> IDENTIFIER

mem_block: MEM LBRACE mem_statement_list RBRACE{
        $$ = new ASTNode(properties_stmt, "mem");
        $$->convert_to_children($3);
    }
    |	MEM UNSAFE LBRACE mem_statement_list RBRACE{
        $$ = new ASTNode(properties_stmt, "mem");
        $$->metadata.push_back("unsafe");
        $$->convert_to_children($4);
    }
    ;
    // this non-terminal is for writing mem rules
    // @Mem { mem_statement_list }


mem_statement_list: mem_statement_list mem_statement {
        $$ = $1;
        $$->reach_end()->next = $2;
    }
    |   mem_statement{$$ = $1;}
    ;
    // this non-terminal is for writing list of mem statements


mem_statement: non_struct_identifier_list ARROW mem_task_list SEMICOLON{
        $$ = new ASTNode(mem_rule);
        ASTNode* left = new ASTNode(mem_node);
        ASTNode* right = new ASTNode(mem_node);

        left->convert_to_children($1);
        right->convert_to_children($3);

        $$->add_child(left);
        $$->add_child(right);
    }
    | error SEMICOLON {  yyerrok; }
    ;

mem_task_list: mem_task_list COMMA mem_task_name{
        $$ = $1;
        $$->reach_end()->next = $3;
    }
    |	mem_task_name{$$ = $1;}
    ;


mem_task_name: IDENTIFIER{
        $$ = $1;
        $1->kind = task_t;
    }
    |   IDENTIFIER MUT{
        $$ = $1;
        $1->kind = task_t;
        $$->metadata.push_back("mut");
    }
    ;

other_statements: join_statement{$$ = $1;}
    | call_statement {$$ = $1;}
    ;

join_statement: JOIN IDENTIFIER  SEMICOLON{
        $$ = $2;
        $$->kind = join_stmt;
    }
    ;

call_statement: CALL IDENTIFIER  SEMICOLON{
        $$ = $2;
        $$->kind = call_stmt;
    }
    ;


array_literal: INT_LITERAL RANGE INT_LITERAL {
    $$ = new ASTNode(literal);
    $$ -> name = "range";
    $$ -> add_child($1);
    $$ -> add_child($3);    
}
    | INT_LITERAL RANGE_INCL INT_LITERAL{
        $$ = new ASTNode(literal);
        $$ -> name = "range_incl";
        $$ -> add_child($1);
        $$ -> add_child($3);
    }
    ;
    // this non-terminal is for writing array literal

literals: INT_LITERAL{$$ = $1;}
    | FLOAT_LITERAL{$$ = $1;}
    | STRING_LITERAL{$$ = $1;}
    | CHARACTER_LITERAL{$$ = $1;}
    | TRUE{$$ = $1;}
    | FALSE {$$ = $1;}
    | array_literal {$$ = $1;};
    // constant literals

value: literals {$$ = $1;}
    | variable_t  {$$ = $1;}
    ;
    // this non-terminal is for writing value

variable_t: array_element {$$ = $1;}
    | IDENTIFIER {$$ = $1; $$->kind = variable_t;}
    | variable_t DOT variable_t {
        $$ = new ASTNode(expr_stmt);
        $$ -> name = ".";
        $$ -> add_child($1);
        $$ -> add_child($3);
    }
    ;

identifier_list: identifier_list COMMA IDENTIFIER
    {
        $$ = $1;
        $$ -> reach_end() -> next = new ASTNode(variable_t, $3->name);
    }
    | IDENTIFIER
    {
        $$ = new ASTNode(variable_t, $1->name);
    }
    ;
    // this non-terminal is for writing list of identifiers
// no new rules required, if nothing is matched then.

%%
int main(int argc, char** argv) {
    if(argc > 1) {
        yydebug = 1;
    }
    root = new ASTNode();
	yyparse();
    SymbolTable* st = new SymbolTable();
    sem_test(root, st, st);
    traverse(root);
    return num_errs;
}

