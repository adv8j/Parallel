#include"ast.c"

typedef struct stmt_list{
    stmt* head;
    stmt* tail;
} stmt_list;

// Function to add a statement to the AST list
void add_statement(stmt_list* list, stmt_t kind, void* s, int line_number) {
    stmt* statement = (stmt*) malloc(sizeof(stmt));
    

}

// Adds a declaration statement to the AST
void add_declaration(stmt_list* list, declaration_stmt* s, int line_number) {
    add_statement(list, STMT_DECL, (void*)s, line_number);
}

// Adds an iterative statement to the AST
void add_iterative(stmt_list* list, iterative_stmt* s, int line_number) {
    add_statement(list, STMT_ITERATIVE, (void*)s, line_number);
}

// Adds a selection statement to the AST
void add_selection(stmt_list* list,selection_stmt* s, int line_number) {
    add_statement(list, STMT_SELECTION, (void*)s, line_number);
}

// Adds an expression statement to the AST
void add_expression(stmt_list* list,expression_stmt* s, int line_number) {
    add_statement(list, STMT_EXPR, (void*)s, line_number);
}

// Adds a compound statement to the AST
void add_compound(stmt_list* list,stmt* s, int line_number) {
    add_statement(list, STMT_COMPOUND, (void*)s, line_number);
}

// Adds a function statement to the AST
void add_function(stmt_list* list,function_stmt* s, int line_number) {
    add_statement(list, STMT_FUNCTION, (void*)s, line_number);
}

// Adds a parallel statement to the AST
void add_parallel(stmt_list* list,parallel_stmt* s, int line_number) {
    add_statement(list, STMT_PARALLEL, (void*)s, line_number);
}

// Adds a struct statement to the AST
void add_struct(stmt_list* list,struct_stmt* s, int line_number) {
    add_statement(list, STMT_STRUCT, (void*)s, line_number);
}

// Adds a task group statement to the AST
void add_taskgroup(stmt_list* list,taskgroup_stmt* s, int line_number) {
    add_statement(list, STMT_TASKGROUP, (void*)s, line_number);
}

