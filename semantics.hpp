#ifndef SEMANTICS_HPP
#define SEMANTICS_HPP


#include "headers.hpp"
#include "AST.cpp"
#include "symbol_table.cpp"
// Global Variables to check for current scope: for scope dependent expressions:

int num_loops = 0;
std::string scope_name = "";
std::unordered_set<std::string> forbidden_names;
std::vector<std::string> code_lines;
int yy_sem_error(const std::string msg, int row_num , int col_num );

int yy_sem_warning(const std::string msg);

bool match_list_init_struct(ASTNode *node, Struct *struct_info);

bool check_valid_function_call(ASTNode *node, SymbolTable *current, SymbolTable *global, Function *func);

DataType retrieveType(ASTNode *node, SymbolTable *current, SymbolTable *global);

bool match_list_init(ASTNode *node, DataType type, SymbolTable *current, SymbolTable *global);

bool match_list_init_struct(ASTNode *node, Struct *struct_info, SymbolTable *current, SymbolTable *global);
bool match_list_init_array(ASTNode *node, DataType type, std::vector<int> &dims, int dim_number, SymbolTable *current, SymbolTable *global);

void second_pass(ASTNode *node, SymbolTable *current, SymbolTable *global);

void handle_statement(ASTNode *node, SymbolTable *current, SymbolTable *global);
void resolve_expression(ASTNode* curNode, SymbolTable* current, SymbolTable* global);


#endif // SEMANTICS_HPP

