typedef struct StackElement{
    struct StackElement* parent;
    //pointer to map identifier to identifier details
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

typedef struct IdentifierDetails{
    enum_datatype id_datatype;    //stores the data type of the id. // enum is used for ease
    int ndim;        //dimension = 0, if id is just a normal variable //dimension = 1 for 1-D array
    bool reference;
}identifier_details;

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

