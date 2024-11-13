#include "headers.hpp"
#include "symbol_table.cpp"
#include "AST.cpp"



int yy_sem_error(const std::string msg){
    std::cerr << msg << std::endl;
    exit(1);
}

int yy_sem_warning(const std::string msg){
    std::cerr << msg << std:: endl;
    return 0;
}


// useful for checking if the current node is a variable
bool checkVariable(ASTNode* current){
    return current->kind == variable_t;
}

// Function to check variable types and operator compatibility
dtypes coerceTypesOverOperator(std::string op, dtypes left_type, dtypes right_type, kind_t left_kind, kind_t right_kind){

    if(op == "="){
        if(left_kind != variable_t) // If the left is not a variable, then it is an error
            return error_type;
        
        
        goto arith_check; // to avoid code duplication
    }
    else if(op == "+" || op == "-" || op == "*" || op == "/" || op == "%"){

arith_check:
        if(left_type == int_t && right_type == int_t) // handling numerical cases
            return int_t;
        else if(left_type == float_t && right_type == float_t)
            return float_t;
        else if(left_type == long_t && right_type == long_t)
            return long_t;
        else if(left_type == float_t && right_type == int_t)
            return float_t;
        else if(left_type == int_t && right_type == float_t)
            return float_t;
        else if(left_type == long_t && right_type == int_t)
            return long_t;
        else if(left_type == int_t && right_type == long_t)
            return long_t;
        else if(left_type == long_t && right_type == float_t)
            return float_t;
        else if(left_type == float_t && right_type == long_t)
            return float_t;
             
        if(left_type == bool_t && right_type == bool_t) // handling boolean cases
            return int_t;
        else if(left_type == bool_t && right_type == int_t)
            return int_t;
        else if(left_type == int_t && right_type == bool_t)
            return int_t;
        else if(left_type == bool_t && right_type == float_t)
            return float_t;
        else if(left_type == float_t && right_type == bool_t)
            return float_t;
        else if(left_type == bool_t && right_type == long_t)
            return long_t;
        else if(left_type == long_t && right_type == bool_t)
            return long_t;


        // handling string/char
        if(left_type== string_t && right_type == string_t && (op == "+" || op == "+="))
            return string_t;
        if(left_type == string_t && right_type == char_t && (op == "+" || op == "+="))
            return string_t;
        
        if(left_type == char_t && right_type == string_t && op == "+")
            return string_t;
        
        if(left_type == char_t && right_type == char_t && op == "+")
            return string_t;

        if(left_type == string_t && right_type == int_t && op == "+") // basically I can things like as worse as Javascript :()
            return string_t;

        if(op == "=" && left_type == right_type)
            return left_type;
        

        return error_type;
    
    }
    else if(op == "==" || op == "!=" || op == "<" || op == ">" || op == "<=" || op == ">="){
        if(!(left_type == int_t || left_type == float_t || left_type == long_t || left_type == bool_t))
            return error_type;

        if(!(right_type == int_t || right_type == float_t || right_type == long_t || right_type == bool_t))
            return error_type;

        return bool_t;
    }
    else if(op == "&&" || op == "||"){
        if(!(left_type == int_t || left_type == long_t || left_type == float_t || left_type == bool_t)){
            return error_type;
        }

        if(!(right_type == int_t || right_type == long_t || right_type == float_t || right_type == bool_t)){
            return error_type;
        }

        return bool_t;
    }
    else if(op == "+=" || op == "-=" || op == "*=" || op == "/=" || op == "%="){ 
        if(left_kind != variable_t) // If the left is not a variable, then it is an error
            return error_type;
        
        goto arith_check; // to avoid code duplication
    }
    else return error_type;
}



// Check if variable is declared, but nested check
bool checkVariableDeclared(ASTNode* current, SymbolTable* current_table){
    // std:: cout << current << std::endl;
    if(!current_table->checkNameNested(current->name)){
        std::string message = "Variable " + current->name + " not declared";
        yy_sem_error(message);
        return false;
    }
    if(! current_table->checkNameNested(current->name, variable)){
        std::string message = "Variable " + current->name + " already declared as a " + entry_type_strings[current_table->getEntry(current->name)->type];
        yy_sem_error(message);
        return false;
    }
    return true;
}

// Resolve the operator: Check if the variables are declared, check if the types are correct, check if the operators are correct
bool resolve_operator(ASTNode* curNode, SymbolTable* current, SymbolTable* global){
    if(curNode->getType() == error_type) // if this is the case, then some error must have occured below this level. Abort
        return false;
    

    std::string op = curNode->name;

    ASTNode* left = curNode->children[0];

    if(curNode->children.size() < 2){ // Handling Unary Operators
        if(op != "-" && op != "!"){ // Check if the operator is unary
            std::string message = "Operator " + op + " requires two operands";
            yy_sem_error(message);
            return false;
        }

        if(checkVariable(curNode) && !checkVariableDeclared(left, current)) // If the node is variable, check if it is declared
            return false;

        if(op == "-"){ // Checking valid types for unary operator
            dtypes type = left->type.type;
            if(type != int_t && type != float_t && type != long_t){
                std::string message = "Type mismatch in operator " + op;
                yy_sem_error(message);
                return false;
            }
            curNode->type = left->type;
        }else{
            curNode->type.type = bool_t;
        }
        return true;
    }
    ASTNode* right = curNode->children[1];
    kind_t left_kind = left->kind, right_kind = right->kind;
    
    if(checkVariable(right) && !checkVariableDeclared(right, current)) // Check if the right variable is declared
        return false;
    if(right_kind == variable_t) // annotating the type of the variable
        right->type.type = ((Variable*)current->getEntryNested(right->name)->ptr)->type;
    if(checkVariable(left) &&  !current->checkNameNested(left->name)){ // Check if the left variable is declared
        if(op == "=" && right->type.type != error_type) // If the operator is assignment, then declare the variable implicitly
            current->addVariable(left->name, (right->type).type, true);
        else if(!(right->type.type != unknown_t)){ // Else throw an error
            std::string message = "Variable " + left->name + " not declared";
            yy_sem_error(message);
            return false;
        }
    }
    if(checkVariable(left) && !checkVariableDeclared(left, current)) // Check if the left variable is declared
        return false;
    
    if(left_kind == variable_t) // annotating the type of the variable
        left->type.type = ((Variable*)current->getEntryNested(left->name)->ptr)->type;

    
    curNode->type.type = coerceTypesOverOperator(op, left->type.type, right->type.type, left_kind, right_kind);

    if(curNode->type.type == error_type){
        std::string message = "Type mismatch in operator " + op + " between " + dtype_strings[left->type.type] + " and " + dtype_strings[right->type.type];
        yy_sem_error(message);
    }

    return curNode->type.type != error_type;

    // curNode->type = left->type; //TODO: This is not complete just for testing
    // curNode->children.clear();
 
}



// Resolve the expression: Recursively resolve the expression
bool resolve_expression(ASTNode* curNode, SymbolTable* current, SymbolTable* global){
    // std::cout << "Resolving expression " << curNode->name << std::endl;
    switch(curNode->kind){
        case variable_t:
        case literal:
            return true;
    }
    if(!resolve_expression(curNode->children[0], current, global)) return false;
   
    if(curNode->children.size() > 1 && !resolve_expression(curNode->children[1], current, global)) return false;

    if(!resolve_operator(curNode, current, global)) return false;
    return true;
}



void sem_test(ASTNode* curNode, SymbolTable* current, SymbolTable* global){
    switch(curNode->kind){
        case decl_stmt:{
            dtypes type = curNode->getType();
            bool ref = curNode->type.reference;
            for(ASTNode* node: curNode->children){
                
                if(current->checkName(curNode->name)){
                    std::string message = "Variable " + curNode->name + " already declared";
                    yy_sem_error(message);
                    continue;
                }
                if(global->checkName(curNode->name, variable)){  
                    std::string message = "Variable " + curNode->name + " already declared as a " + entry_type_strings[global->getEntry(curNode->name)->type];
                    yy_sem_error(message);
                    continue;
                }
                bool has_value = false;

                if(node->childExists()){ // If a child exists, then it is an assignment
                    sem_test(node->children[0], current, global);
                    if(type != node->getType()){
                        std::string message = "Type mismatch in variable " + node->name;
                        yy_sem_error(message);
                        continue;
                    }
                    has_value = true;
                }
                // TODO: Struct Handling still left
                current->addVariable(node->name, type, has_value,ref,node->type.ndims);// 
            }
            break;
        }

        case expr_stmt:{
            std::cout << "Checking expression statement" << std::endl;
            resolve_expression(curNode, current, global);
            break;
        }
        case function_decl_stmt:
        {
            std::cout << "Checking function declaration" << std::endl;
            std::string name = curNode->name;
            if(current->checkName(name)){
                std::string message = "Function " + name + " already declared as a " +entry_type_strings[current->getEntry(name)->type];
                yy_sem_error(message);
            }
            if(current->checkName(name, function) ){

                std::string message = "Function " + name + " already declared";
                yy_sem_error(message);
            }
            if(global->checkName(name, prototype)){
                Function* func = (Function*)global->getEntry(name)->ptr;
                std::vector<Variable> params = func->param_list;
                for(int i = 0; i < params.size(); i++){
                    Variable v = params[i];
                    ASTNode*temp= curNode->children[0]->children[i];
                    Variable v2(temp->name, (temp->type).type,(temp->type).ndims, (temp->type).reference,false, temp->name);
                    if(v != v2){
                        std::string message = "Type mismatch in function " + name;
                        yy_sem_error(message);
                    }
                }
            }
            std::vector<Variable> params;
           ASTNode* params_list = curNode->children[0];
              for(ASTNode* param: params_list->children){
                Variable v(param->name, param->getType());
                params.push_back(v);
              }
            global->addFunction(name, curNode->getType(), false, params, curNode->name);
            break;
        }
        case prototype_stmt:
        {
            std::cout << "Checking function prototype" << std::endl;
            std::string name = curNode->name;
            if(current->checkName(name)){
                std::string message = "Function " + name + " already declared";
                yy_sem_error(message);
            }
            std::vector<Variable> params;
            ASTNode* params_list = curNode->children[0];
            for(ASTNode* param: params_list->children){
                Variable v(param->name, param->type.type, param->type.ndims, param->type.reference, false, param->name);
                params.push_back(v);
            }
            global->addFunction(name, curNode->getType(), true, params,curNode->name);
            auto entry = global->getEntry(name);
            if(entry != nullptr){
                entry->type = prototype;
            }
            break;
        }
    }
    if(curNode->next != nullptr)
        sem_test(curNode->next, current, global);
}
