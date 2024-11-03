#include <string>
#include <vector>


enum kind_t{
    decl_stmt,
    expr_stmt,
    cond_stmt,
    if_stmt,
    loop_stmt,
    compound_stmt,
    return_stmt,
    call_stmt,
    join_stmt,
    type_stmt,
    variable_stmt,
    array_stmt,
    function_decl_stmt,
    function_call_stmt,
    literal,
    variable,
};


enum dtypes{
    int_t,
    float_t,
    long_t,
    bool_t,
    char_t,
    string_t,
    unknown_t,
};

struct DataType{
    dtypes type;
    int ndim;
    bool reference;
    DataType(){}
    DataType(dtypes name, int ndim, bool reference):type(name),ndim(ndim),reference(reference){}
    DataType(dtypes type) : type(type), ndim(0), reference(false){}
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
    ASTNode() {}
    ASTNode(int line_no, int col_no,kind_t kind, std::string name, DataType type):line_number(line_no), col_number(col_no),kind(kind),name(name), type(DataType(type)), next(NULL){}
    void addChild(ASTNode* child){
        children.push_back(child);
    }
};
