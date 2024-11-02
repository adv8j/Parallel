#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef enum
{
	EXPR_ADD,
	EXPR_SUB,
	EXPR_MUL,
	EXPR_DIV,
	EXPR_MOD,
	EXPR_ASSIGN,
	EXPR_ADD_ASSIGN,
	EXPR_SUB_ASSIGN,
	EXPR_MUL_ASSIGN,
	EXPR_DIV_ASSIGN,
	EXPR_MOD_ASSIGN,
	EXPR_LT,
	EXPR_GT,
	EXPR_GTE,
	EXPR_LTE,
	EXPR_EQ,
	EXPR_NEQ,
	EXPR_AND,
	EXPR_OR,
	EXPR_UNARY_NOT,
	EXPR_UNARY_MINUS,
	EXPR_NAME,
	EXPR_INTEGER_LITERAL,
	EXPR_STRING_LITERAL,
	EXPR_ARRAY_INDEX, //HAVE TO THINK ABOUT THIS
	EXPR_STRUCT_MEMBER,
	EXPR_FUNC_CALL,
	EXPR_FLOAT_LITERAL,
	EXPR_CHAR_LITERAL
} expr_t;

typedef struct terminal{
	const char* name;
	int integer_value;
	const char* string_literal;
	float float_value;
	char char_value;
	bool bool_literal;
}terminal;

typedef struct expr
{
	expr_t kind;
	struct expr* left;
	struct expr* right;
	struct terminal* value;
} expression_stmt;

typedef struct decl
{
	const char* name;
	const struct type* type; // to decided , const char* or type*
	int ndim;
	bool reference;
	bool constant_ptr;
	int line_number;
	struct expr* value;
	struct stmt* code;
	struct decl* next;		//int i,j;  here next will be for j
} declaration_stmt;
typedef enum
{
	STMT_DECL,
	STMT_EXPR,
	STMT_ITERATIVE,
	STMT_SELECTION,
	STMT_COMPOUND,
	STMT_FUNCTION,
	STMT_STRUCT,
	STMT_PARALLEL,
	STMT_TASKGROUP
} stmt_t;

typedef struct parameter_list
{
	char* name;
	char* type;
	bool reference;
	struct parameter_list* next;
}param_list;

typedef struct iteration_type1
{
	expression_stmt* init;		// if they are empty point towards NULL
	expression_stmt* condition;
	expression_stmt* update;


}iteration_t1;

typedef struct iteration_type2
{
	char*name_iterator;
	bool reference;
	char*name_container;

}iteration_t2;

typedef struct itr_stmt
{
	
	bool type; // type of iteration// normal for loop, or for loop using in keyword
	iteration_t1 type1;
	iteration_t2 type2;
	struct stmt* comp_stmt;


} iterative_stmt;
typedef struct selc_stmt
{
	expression_stmt* condition;
	struct stmt* if_stmt;
	struct selc_stmt* else_stmt;

} selection_stmt;

typedef struct func_stmt
{
	char* function_name;
	char* return_types;
	param_list* param;
	struct stmt* comp_stmt;
} function_stmt;
typedef struct struct_decl
{
	char* struct_name;
	param_list* member_list;

} struct_decl;


typedef struct stmt
{
	stmt_t kind; // tells the statment type
	void * statement; // to store the statement type cast as per use
	int line_number;
	struct stmt* next;
} stmt ;
typedef struct order_stmt{
	char** name;
} order_stmt;

typedef struct task_stmt{
	char* name;
	stmt* code;	
} task_stmt;

typedef struct mem_stmt{
	char* name;
	char** tasks;
	bool accesses;
} mem_stmt;

typedef struct shared_stmt{
	char* name;
	char** tasks;
	char* type;
} shared_stmt;
typedef struct taskgroup_stmt{
	task_stmt* task;
	order_stmt* order;
	mem_stmt* mem;
	shared_stmt* shared;
};



struct decl* decl_create( char *name, struct type* type, int ndim,bool reference, int line_number, struct expr *value, struct stmt *code, struct decl *next ) {
	struct decl *d = malloc(sizeof(struct decl));
	d->name = name;
	d->type = type;
	d->ndim = ndim;
	d-> reference = reference;
	d->line_number = line_number;
	d->value = value;
	d->code = code;
	d->next = next;
	return d;
}


struct stmt * stmt_create( stmt_t kind, struct decl *decl, struct expr *init_expr, struct expr *expr, struct expr *next_expr, struct stmt *body, struct stmt *else_body, struct stmt *next ) {
    struct stmt *st = malloc(sizeof(struct stmt));
    if (!st) {
        // fprintf(stderr, "Error: Could not allocate memory for stmt\n");
		// print 
		printf("Error: Could not allocate memory for stmt\n");

        exit(1);
    }

    st->kind = kind;
    st->decl = decl;
    st->init_expr = init_expr;
    st->expr = expr;
    st->next_expr = next_expr;
    st->body = body;
    st->else_body = else_body;
    st->next = next;

    return st;
}

struct expr* expr_create(expr_t kind, struct expr* left, struct expr* right, const char* name, int integer_value, const char* string_literal) {
    struct expr* e = malloc(sizeof(struct expr));
    if (!e) {
        printf( "Error: Could not allocate memory for expr\n");
        exit(1);
    }

    e->kind = kind;
    e->left = left;
    e->right = right;
    e->name = name;
    e->integer_value = integer_value;
    e->string_literal = string_literal;

    return e;
}

stmt * add_node(stmt * head, stmt * node) {
	if (head == NULL) {
		return node;
	}
	stmt * temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = node;
	return head;
}


