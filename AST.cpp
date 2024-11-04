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
    list_init,
    taskgroup_stmt,
    task_stmt,
    supervisor_stmt,
    properties_stmt,
    order_rule,
    order_node,
    array_element, // eg: arr[1][2]
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
    "list_init",
    "taskgroup_stmt",
    "task_stmt",
    "supervisor_stmt",
    "properties_stmt",
    "order_rule",
    "order_node",
    "array_element"
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
    task_t,
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
    "task_t",
};

class ASTNode;

struct DataType{
    dtypes type;
    std::vector<int> ndims;
    bool reference;
    std::string struct_name;  //used to store name of struct
    ASTNode* init_exp; // used in case of initialiser dims
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
    std::vector<std::string> metadata;
    ASTNode(): kind(root_t), line_number(0), col_number(0), next(NULL){}
    ASTNode(kind_t kind, DataType type, std::string name ="",int line_no = 0, int col_no = 0): kind(kind), line_number(line_no), name(name),col_number(col_no), type(type), next(NULL){
        // std::cout << "Creating node of type " << kind_t_strings[kind] << std::endl;
    }
    ASTNode(kind_t kind, std::string name = "", int line_no = 0, int col_no =0): kind(kind), line_number(line_no), col_number(col_no), name(name), next(NULL){}
    ASTNode(int line_no, int col_no,kind_t kind, std::string name, DataType type):line_number(line_no), col_number(col_no),kind(kind),name(name), type(DataType(type)), next(NULL){}
    void add_child(ASTNode* child){
        children.push_back(child);
    }

    void add_to_metadata(ASTNode* node){
        ASTNode * tail = node;

        while(tail != NULL){
            this->metadata.push_back(tail->name);
            ASTNode* temp = tail;
            tail = tail->next;
            delete temp;
        }
    }

    ASTNode* reach_end(){
        ASTNode* temp = this;
        while(temp->next != NULL){
            temp = temp->next;
        }
        return temp;
    }

    void traverse_next(){
        ASTNode* temp = this;
        while(temp != NULL){
            std::cout << temp;
            temp = temp->next;
        }
    }

    void convert_to_children(ASTNode* head){
        ASTNode* temp = head;
        while(temp != NULL){
            children.push_back(temp);
            ASTNode* x = temp;
            temp = temp->next;
            x->next = NULL;
        }
    }

};

int kind = 0;  // Change this to test different values

    // ANSI escape codes for coloring text
const std::string RED_COLOR = "\033[31m";
const std::string CYAN_COLOR = "\033[36m";
const std::string GREEN_COLOR = "\033[32m";
const std::string YELLOW_COLOR = "\033[33m";
const std::string RESET_COLOR = "\033[0m";

    // Output colored text
std::ostream& operator<<(std::ostream& os, const ASTNode* node) {
    if (node == NULL){
        os << "NULL" << std::endl;
        return os;
    }
    kind_t kind = node->kind;

    os << CYAN_COLOR << kind_t_strings[kind] << RESET_COLOR;

    switch(kind){
        case variable: 
        case literal: 
        case task_stmt:
        case taskgroup_stmt:
            os << ": " << node->name << std::endl; 
            break;

        case decl_stmt:
            os << ": " << dtype_strings[node->type.type] << std::endl;
            break;
        
        case root_t:
        case order_rule:
            os << std::endl;
            break;
        case properties_stmt:
            os << ": " << node->name << std::endl;
            break;

        case order_node:
            os << ": ";
            if (node->name== "task"){
                for(std::string s : node->metadata){
                    os << s << " ";
                }
            }
            else os << node->name;
            
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
