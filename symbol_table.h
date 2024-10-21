#include"symbol_table.c"

//this is using to store in symbol table in 
//used to handle scoping
typedef struct StackElement{
    struct StackElement* parent;
    symbol_table* symbol_table_ptr;
}stack_element;

enum enum_datatype{
    CHAR,
    INT,
    LONG,
    BOOL,
    FLOAT,
    STRING,

    //structs
    VOID
};

typedef struct ParameterList{
    struct ParameterList* next;
    char* id;
    enum_datatype id_datatype;
    int ndim;
    bool reference;
}parameter_list;

//there is a map from function name to func_details
typedef struct FuncDetails{
    enum_datatype return_type;
    bool is_return_type_reference;
    parameter_list* param_list_head;
}func_details;

stack_element* init_stack(){
    stack_element* top = symbol_table_init(0);
    return top;
}

stack_element* push_symbol_table(stack_element* top){
    stack_elem
}