#ifndef HEADERS_HPP
#define HEADERS_HPP

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

enum entry_type
{
    function,
    prototype,
    variable,
    taskgroup,
    task,
    struct_data,
    supervisor,
};

const std::string entry_type_strings[] = {
    "function",
    "prototype",
    "variable",
    "taskgroup",
    "task",
    "struct_data",
    "supervisor",
};


enum dtypes
{
    int_t,
    float_t,
    long_t,
    bool_t,
    char_t,
    string_t,
    unknown_t,
    struct_t,
    void_t,
    error_type
};

const std::string dtype_strings[] = {
    "int",
    "float",
    "long",
    "bool",
    "char",
    "string",
    "unknown",
    "struct",
    "void",
    "error",
};

enum kind_t
{
    root_t,
    decl_stmt,
    expr_stmt,
    cond_stmt,
    if_stmt,
    else_stmt,
    elseif_stmt,
    loop_stmt,
    compound_stmt,
    return_stmt,
    call_stmt,
    join_stmt,
    variable_stmt,
    array_stmt,
    function_decl_stmt,
    prototype_stmt,
    function_call_stmt,
    literal,
    variable_t,
    type_t,
    list_init,
    taskgroup_stmt,
    task_stmt,
    supervisor_stmt,
    properties_stmt,
    order_rule,
    order_node,
    array_element, // eg: arr[1][2]
    struct_decl,
    parallel_stmt,
    keyword,
    reduction_operator,
    channel_stmt,
    iterative_stmt,
    shared_rule,
    shared_node,
    task_t,
    mem_rule,
    mem_node,
    empty_expr_stmt,
    itr_type,
    selection_stmt,
    params_list,
    params_t,
};

const std::string kind_t_strings[] = {
    "root_t",
    "decl_stmt",
    "expr_stmt",
    "cond_stmt",
    "if_stmt",
    "else_stmt",
    "elseif_stmt",
    "loop_stmt",
    "compound_stmt",
    "return_stmt",
    "call_stmt",
    "join_stmt",
    "variable_stmt",
    "array_stmt",
    "function_decl_stmt",
    "prototype_stmt",
    "function_call_stmt",
    "literal",
    "variable_t",
    "type_t",
    "list_init",
    "taskgroup_stmt",
    "task_stmt",
    "supervisor_stmt",
    "properties_stmt",
    "order_rule",
    "order_node",
    "array_element",
    "struct_decl",
    "parallel_stmt",
    "keyword",
    "reduction_operator",
    "channel_stmt",
    "iterative_stmt",
    "shared_rule",
    "shared_node",
    "task_t",
    "mem_rule",
    "mem_node",
    "empty_expr_stmt",
    "itr_type",
    "selection_stmt",
    "params_list",
    "params_t",
};

class Variable;
class Function;
class Struct;
class SymbolTableEntry;
class SymbolTable;
class TaskGroup;


// AST Node
class ASTNode;
struct DataType;

int kind = 0; // Change this to test different values

// ANSI escape codes for coloring text
const std::string RED_COLOR = "\033[31m";
const std::string CYAN_COLOR = "\033[36m";
const std::string GREEN_COLOR = "\033[32m";
const std::string YELLOW_COLOR = "\033[33m";
const std::string RESET_COLOR = "\033[0m";

// Output colored text
std::ostream &operator<<(std::ostream &os, const ASTNode *node);

void traverse(ASTNode , int);

#endif
