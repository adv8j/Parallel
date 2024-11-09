#include "symbol_table.cpp"
#include "AST.cpp"

std::vector<std::string> assignment_operators = {
    "=", "+=" , "-=" , "*=" , "/=", "%="
};

bool isAssignOperator(std::string op){
    int i =0;
    for(i = 0; i < assignment_operators.size(); i++){
        if(assignment_operators[i] == op)
            return true;
    }
    return false;
}


int yy_sem_error(const std::string msg){
    std::cerr << msg << std::endl;
    exit(1);
}

int yy_sem_warning(const std::string msg){
    std::cerr << msg << std:: endl;
    return 0;
}



bool checkVariable(ASTNode* current){
    return current->kind == variable_t;
}
//TODO: Lots of work to be done here
bool coerceTypesOverOperator(std::string op, dtypes left, dtypes right){
    if(left == right){
        return true;
    }
    if(left == unknown_t && isAssignOperator(op)){
        return true;
    }

    if(op == "+" || op == "-" || op == "*" || op == "/"){
        if(left == int_t && right == float_t){
            return true;
        }
        if(left == float_t && right == int_t){
            return true;
        }
    }

    return false;


}



void resolve_operator(ASTNode* curNode, SymbolTable* current){
    std::string op = curNode->name;
    ASTNode* left = curNode->children[0];
    ASTNode* right = curNode->children[1];
    if(checkVariable(left) &&  !current->checkNameNested(left->name)){
        if(isAssignOperator(op)){
            current->addVariable(left->name, (left->type).type);
            std::cout << "Variable " << left->name << " added to symbol table" << std::endl;
        }
        else{
            std::string message = "Variable " + left->name + " not declared";
            yy_sem_error(message);
        }
    }

    if(checkVariable(right) &&  !current->checkNameNested(right->name)){
            std::string message = "Variable " + right->name + " not declared";
            yy_sem_error(message);
    }

    if(!coerceTypesOverOperator(op, (left->type).type, (right->type).type)){
        std::string message = "Type mismatch in operator " + op;
        yy_sem_error(message);
    }
    else if(isAssignOperator(op)){
        Variable* v = (Variable*)current->getEntry(left->name)->ptr;
        if(v->type == unknown_t){
            v->type = (right->type).type;
        }
        v->has_value = true;
        curNode->type.type = left->type.type =  v->type;
    }
    else{
        curNode->type = left->type;
    }

    // curNode->type = left->type; //TODO: This is not complete just for testing
    // curNode->children.clear();
 
}



void resolve_expression(ASTNode* curNode, SymbolTable* current){
    switch(curNode->kind){
        case variable_t:
        case literal:
            return;
    }
    resolve_expression(curNode->children[0], current);
    resolve_expression(curNode->children[1], current);

    resolve_operator(curNode, current);
}



void sem_test(ASTNode* curNode, SymbolTable* current, SymbolTable* global){
    switch(curNode->kind){
        case decl_stmt:{
            dtypes type = curNode->getType();
            for(ASTNode* node: curNode->children){

                if(current->checkName(node->name)){
                    std:: string message = "Variable " + node->name + " already declared";
                    yy_sem_error(message);
                    continue;
                }

                if(global->checkName(node->name)){
                    std::string message = "Variable " + node->name + " already declared";
                    yy_sem_error(message);
                    continue;
                }
                current->addVariable(node->name, type);
            }
            break;
        }

        case expr_stmt:{
            std:: cout << "Checking expression statement" << std::endl;
            resolve_expression(curNode, current);
        }
    }
    if(curNode->next != nullptr)
        sem_test(curNode->next, current, global);
}
