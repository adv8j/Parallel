#include <string>
#include <vector>
#include <iostream>

enum kind_t{
    root_t,
    decl_stmt,
    expr_stmt,
    cond_stmt,
    if_stmt,
    loop_stmt,
    compound_stmt,
    return_stmt,
    call_stmt,
    join_stmt,
    variable_stmt,
    array_stmt,
    function_decl_stmt,
    function_call_stmt,
    literal,
    variable,
    type_t,
    expr_init_stmt,
    list_init
};

const std::string kind_t_strings[] = {
    "root_t",
    "decl_stmt",
    "expr_stmt",
    "cond_stmt",
    "if_stmt",
    "loop_stmt",
    "compound_stmt",
    "return_stmt",
    "call_stmt",
    "join_stmt",
    "variable_stmt",
    "array_stmt",
    "function_decl_stmt",
    "function_call_stmt",
    "literal",
    "variable",
    "type_t",
    "expr_init_stmt",
    "list_init"
};

enum dtypes{
    int_t,
    float_t,
    long_t,
    bool_t,
    char_t,
    string_t,
    unknown_t,
    struct_t,
};

const std::string dtype_strings[] = {
    "int_t",
    "float_t",
    "long_t",
    "bool_t",
    "char_t",
    "string_t",
    "unknown_t",
    "struct_t",
};


struct DataType{
    dtypes type;
    std::vector<int> ndims;
    bool reference;
    string struct_name;
    DataType(){}
    DataType(dtypes name, std::vector<int> ndim, bool reference):type(name),ndims(ndim),reference(reference){}
    DataType(dtypes type, bool ref = false) : type(type), ndims({}), reference(ref){}
};

class ASTNode{
public:
    int line_number;
    int col_number;
    kind_t kind;
    std::string name;
    DataType type;
    std::vector<ASTNode*> children;
    ASTNode* next;
    ASTNode(): kind(root_t), line_number(0), col_number(0), next(NULL){}
    ASTNode(kind_t kind, DataType type): kind(kind), line_number(0), col_number(0), type(type), next(NULL){
        // std::cout << "Creating node of type " << kind_t_strings[kind] << std::endl;
    }
    ASTNode(kind_t kind): kind(kind), line_number(0), col_number(0), next(NULL){}
    ASTNode(int line_no, int col_no,kind_t kind, std::string name, DataType type):line_number(line_no), col_number(col_no),kind(kind),name(name), type(DataType(type)), next(NULL){}
    void add_child(ASTNode* child){
        children.push_back(child);
    }

    ASTNode* reach_end(){
        ASTNode* temp = this;
        while(temp->next != NULL){
            temp = temp->next;
        }
        return temp;
    }

};

std::ostream& operator<<(std::ostream& os, const ASTNode* node) {
    kind_t kind = node->kind;

    os << kind_t_strings[kind];

    switch(kind){
        case variable: 
        case literal: 
            os << " " << node->name << std::endl; 
            break;

        case decl_stmt:
            os << " " << dtype_strings[node->type.type] << std::endl;
            break;
        
        case root_t:
            os << std::endl;
            break;
    }

    return os;

}


void traverse(ASTNode* node, int tab = 0){
    kind_t kind = node->kind;

    
    if(node == NULL){
        return;
    }
    for(int i = 0; i < tab; i++){
        std::cout << "\t";
    }
    
    std::cout << node ;
    for(auto child : node->children){
        traverse(child,tab+1);
    }

    if(node->next != NULL){
        traverse(node->next, tab);
    }
}