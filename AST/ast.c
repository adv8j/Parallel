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
} expr;

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
} decl;
typedef enum
{
	STMT_DECL,
	STMT_EXPR,
	STMT_IF_ELSE,
	STMT_FOR,
	STMT_PRINT,
	STMT_RETURN,
	STMT_BLOCK
} stmt_t;

typedef struct stmt
{
	stmt_t kind; // tells the statment type
	decl* decl;
	expr* init_expr;
	expr* expr;
	struct expr* next_expr;
	struct stmt* body;
	struct stmt* else_body;
	struct stmt* next;
	int line_number;
} stmt ;


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


