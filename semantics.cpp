#include "symbol_table.cpp"
#include "AST.cpp"

int yy_sem_error(const char* msg){
    std::cerr << msg << std::endl;
    exit(1);
}

void sem_test(ASTNode* curNode, SymbolTable* current){
    switch(curNode->kind){
        case decl_stmt:{
            
        }
    }
}