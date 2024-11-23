#ifndef SEMANTIcs_HPP
#define SEMANTIcs_HPP


#include "headers.hpp"
#include "AST.cpp"
#include "symbol_table.cpp"
int yy_sem_error(const std::string msg);

int yy_sem_warning(const std::string msg);

bool match_list_init_struct(ASTNode *node, Struct *struct_info);

bool check_valid_function_call(ASTNode *node, SymbolTable *current, SymbolTable *global, Function *func);

DataType retrieveType(ASTNode *node, SymbolTable *current, SymbolTable *global);

bool match_list_init(ASTNode *node, DataType type, SymbolTable *current, SymbolTable *global);

bool match_list_init_struct(ASTNode *node, Struct *struct_info);
bool match_list_init_array(ASTNode *node, DataType type, std::vector<int> &dims, int dim_number, SymbolTable *current, SymbolTable *global);

bool resolve_expression(ASTNode* curNode, SymbolTable* current, SymbolTable* global);

#endif // SEMANTIcs_HPP

