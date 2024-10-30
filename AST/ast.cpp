#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;
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
struct expr
{
	expr_t kind;
	struct expr* left;
	struct expr* right;
	const char* name;
	int integer_value;
	const char* string_literal;
};

struct decl
{
	const char* name;
	const char* type;
	int ndim;
	bool reference;
	int line_number;
	struct expr* value;
	struct stmt* code;
	struct decl* next;
};
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

struct stmt
{
	stmt_t kind; // tells the statment type
	decl* decl;
	expr* init_expr;
	expr* expr;
	struct expr* next_expr;
	stmt* body;
	stmt* else_body;
	stmt* next;
	int line_number = 0;
};
