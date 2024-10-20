#pragma once
#include"symbol_table.c"

typedef struct ParameterList{
    struct ParameterList* next;
    char* id;
    char* id_datatype;
    int ndim;
    bool reference;
}parameter_list;

//there is a map from function name to func_details
typedef struct FuncDetails{
    char* return_type;
    bool is_return_type_reference;
    parameter_list* param_list_head;
    int line_number;
}func_details;

//function to initialise function table

//function to insert an entry in function table

//function to search in function table and return its entry
