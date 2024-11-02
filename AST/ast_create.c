#include"ast.c"

struct Node{
    int line_no;
    int col_no;
    enum_t kind;
    vector<Node*> children;
    string content;
    Node* next;
};
