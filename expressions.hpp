// expression.hpp
#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include "headers.hpp"  // Include necessary dependencies

bool resolve_expression(ASTNode* curNode, SymbolTable* current, SymbolTable* global);

#endif // EXPRESSION_HPP