#ifndef HEADERS_HPP
#define HEADERS_HPP

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>


int yy_sem_error(const std::string);
int yy_sem_warning(const std::string);

enum entry_type
{
    function,
    prototype,
    variable,
    taskgroup,
    task,
    struct_data,
    supervisor,
    _struct
};

const std::string entry_type_strings[] = {
    "function",
    "prototype",
    "variable",
    "taskgroup",
    "task",
    "struct_data",
    "supervisor",
    "_struct"
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
    arg_list,
    syntax_error_stmt,
    member_data_t,
    identifier_chain
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
    "loop_type",
    "selection_stmt",
    "params_list",
    "params_t",
    "arg_list",
    "syntax_error_stmt",
    "member_data_t",
    "identifier_chain"
};


enum check_status{
    success,
    variable_not_found,
    variable_declared,
    identifier_declared_different_type,
};

const std::string check_status_strings[] = {
    "success",
    "variable_not_found",
    "variable_declared",
    "identifier_declared_different_type",
};

class Variable;
class Function;
class Struct;
class SymbolTableEntry;
class SymbolTable;
class TaskGroup;



// AST Node
class ASTNode;

struct DataType
{
	dtypes type;
	std::vector<int> ndims;
	bool reference;
    std::string name = "";           // used to store the name of struct
	ASTNode *init_exp_or_id = NULL; // used in case of initialiser dims, or used to store name identifier of struct
	DataType() {}
	DataType(dtypes name, std::vector<int> ndim, bool reference)
		: type(name), ndims(ndim), reference(reference)
	{
	}
	DataType(dtypes type, bool ref = false)
		: type(type), ndims({}), reference(ref)
	{
	}

    DataType(dtypes type, std::string name, bool ref = false, int line_no = 0, int col_no = 0)
        : type(type), ndims({}), reference(ref), name(name)
    {
    }

    bool operator==(const DataType &parameter) const{
        bool x1 = this->type == parameter.type;

        if(this->type == struct_t)
            x1 &= this->name == parameter.name;
        

        if(this->ndims.size() != parameter.ndims.size())
            return false;
        

        for(int i = 0; i < this->ndims.size(); i++)
            x1 &= this->ndims[i] == parameter.ndims[i];
        
        return x1;
    }

    bool operator!=(const DataType &parameter) const{
        return !(*this == parameter);
    }
};

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

void sem_test(ASTNode* curNode, SymbolTable* current, SymbolTable* global);

#endif
