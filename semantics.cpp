#include "semantics.hpp"

int yy_sem_error(const std::string msg){

    std::cerr << msg << std::endl;
    return 0;
}

int yy_sem_warning(const std::string msg){

    std::cerr << msg << std::endl;
    return 0;
}

// matches list initializer against a struct
bool match_list_init_struct(ASTNode *node, Struct *struct_info, SymbolTable* current, SymbolTable* global){
    if (node->children.size() != struct_info->members.size()){
        std::string message = "Struct " + struct_info->name + " expects " + std::to_string(struct_info->members.size()) + " members but got " + std::to_string(node->children.size());
        yy_sem_error(message);
        return false;
    }

    for (int i = 0; i < node->children.size(); i++){
        DataType member_type = struct_info->members[i].type;
        if(member_type.reference && node->children[i]->kind == list_init){
            std::string message = "Struct " + struct_info->name + " expects member " + std::to_string(i) + " to be a reference";
            yy_sem_error(message);
            return false;
        }

        if (node->children[i]->kind != list_init){
            resolve_expression(node->children[i], current, global);
        }
        else{
            if (!match_list_init(node->children[i], struct_info->members[i].type, current, global)){
                return false;
            }
        }
        DataType child_type = node->children[i]->type;
        
        if (member_type.type != child_type.type){
            std::string message = "Struct " + struct_info->name + " expects member " + std::to_string(i) + " of type " + dtype_strings[member_type.type] + " but got " + dtype_strings[child_type.type];
            yy_sem_error(message);
            return false;
        }
        if (member_type.type == struct_t && member_type.name != child_type.name){
            std::string message = "Struct " + struct_info->name + " expects member " + std::to_string(i) + " of type " + member_type.name + " but got " + child_type.name;
            yy_sem_error(message);
            return false;
        }
        if (member_type.ndims.size() != child_type.ndims.size()){
            std::string message = "Struct " + struct_info->name + " expects member " + std::to_string(i) + " with " + std::to_string(member_type.ndims.size()) + " dimensions but got " + std::to_string(child_type.ndims.size());
            yy_sem_error(message);
            return false;
        }
        for (int j = 0; j < member_type.ndims.size(); j++){
            if (member_type.ndims[j] != child_type.ndims[j]){
                std::string message = "Struct " + struct_info->name + " expects member " + std::to_string(i) + " with " + std::to_string(member_type.ndims[j]) + " dimensions but got " + std::to_string(child_type.ndims[j]);
                yy_sem_error(message);
                return false;
            }
        }
        
    }

    return true;
}

// Checks if a function call is valid
bool check_valid_function_call(ASTNode *node, SymbolTable *current, SymbolTable *global, Function *func){

    if (node->children.size() != func->param_list.size()){

        std::string message = "Function " + node->name + " expects " + std::to_string(func->param_list.size()) + " arguments but got " + std::to_string(node->children.size());
        yy_sem_error(message);
        return false;
    }

    for (int i = 0; i < node->children.size(); i++){
        DataType param_type = func->param_list[i].type;
        if(param_type.reference && node->children[i]->kind == list_init){
            std::string message = "Function " + node->name + " expects argument " + std::to_string(i) + " to be a reference";
            yy_sem_error(message);
            return false;
        }
        if(node->children[i]->kind != list_init){
            resolve_expression(node->children[i], current, global);
        }
        else{
            if (!match_list_init(node->children[i], param_type, current, global)){
                return false;
            }
        }
        DataType arg_type = node->children[i]->type;
        
        // TODO : GIve better error messages
        if (param_type.type != arg_type.type){
            std::string message = "Function " + node->name + " expects argument " + std::to_string(i) + " of type " + dtype_strings[param_type.type] + " but got " + dtype_strings[arg_type.type];
            yy_sem_error(message);
            return false;
        }
        if(param_type.type == struct_t && param_type.name != arg_type.name){
            std::string message = "Function " + node->name + " expects argument " + std::to_string(i) + " of type " + param_type.name + " but got " + arg_type.name;
            yy_sem_error(message);
            return false;
        }
        if (param_type.ndims.size() != arg_type.ndims.size()){
            std::string message = "Function " + node->name + " expects argument " + std::to_string(i) + " with " + std::to_string(param_type.ndims.size()) + " dimensions but got " + std::to_string(arg_type.ndims.size());
            yy_sem_error(message);
            return false;
        }
        for (int j = 0; j < param_type.ndims.size(); j++){
            if (param_type.ndims[j] != arg_type.ndims[j]){
                std::string message = "Function " + node->name + " expects argument " + std::to_string(i) + " with " + std::to_string(param_type.ndims[j]) + " dimensions but got " + std::to_string(arg_type.ndims[j]);
                yy_sem_error(message);
                return false;
            }
        }
        
    }
    return true;
}

// Function to resolve the base cases of the expression like a chain of identifiers, literal, variable, array element, function call
DataType retrieveType(ASTNode *node, SymbolTable *current, SymbolTable *global){

    if (node->kind == array_element){

        SymbolTableEntry *e = current->getEntryNested(node->name);
        if (e == NULL){

            std::string message = "Variable " + node->name + " not declared";
            yy_sem_error(message);
            return error_type;
        }

        if (e->type != variable){

            std::string message = "Variable " + node->name + " already declared as a " + entry_type_strings[e->type];
            yy_sem_error(message);
            return error_type;
        }

        DataType type = ((Variable *)(e->ptr))->type;

        if (type.ndims.size() < node->children.size()){
 // if the number of dimensions is less than the number of children
            std::string message = "Array dimension mismatch: Expected " + std::to_string(type.ndims.size()) + " but got " + std::to_string(node->children.size());
            yy_sem_error(message);
            return error_type;
        }

        for (auto child : node->children){

            if (child->kind == literal && (stoi(child->name) >= type.ndims.back() || stoi(child->name) < 0)){

                std::string message = "Array index out of bounds";
                yy_sem_error(message);
                return error_type;
            }
            type.ndims.pop_back();
        }
        return type;
    }
    else if (node->kind == variable_t){

        SymbolTableEntry *e = current->getEntryNested(node->name);
        if (e == NULL){

            std::string message = "Variable " + node->name + " not declared";
            yy_sem_error(message);
            return error_type;
        }

        if (e->type != variable){

            std::string message = "Variable " + node->name + " already declared as a " + entry_type_strings[e->type];
            yy_sem_error(message);
            return error_type;
        }

        Variable *var_entry = (Variable *)(e->ptr);
        return var_entry->type;
    }
    else if (node->kind == literal){
        return node->type;
    }
    else if (node->kind == function_call_stmt){

        SymbolTableEntry *e = global->getEntryNested(node->name);

        if (e == NULL){

            std::string message = "Function " + node->name + " not declared";
            yy_sem_error(message);
            return error_type;
        }

        if (e->type != function){

            std::string message = "Function " + node->name + " already declared as a " + entry_type_strings[e->type];
            yy_sem_error(message);
            return error_type;
        }
        Function *func_entry = (Function *)(e->ptr);
        if (!check_valid_function_call(node, current, global, func_entry)){

            return error_type;
        }
        return func_entry->return_type;
    }
    else if (node->kind == identifier_chain){


        ASTNode *chain_node = node;
        ASTNode *first = node->children[0];
        ASTNode *second;
        SymbolTableEntry *e = current->getEntryNested(first->name);
        if (e == NULL){
            std::string message = "Variable " + node->name + " not declared";
            yy_sem_error(message);
            return error_type;
        }

        if (e->type != variable){
            std::string message = "Variable " + node->name + " already declared as a " + entry_type_strings[e->type];
            yy_sem_error(message);
            return error_type;
        }

        do{
            second = node->children[1];
            if (second->kind == identifier_chain) // basically the left one is definitely a variable
                second = second->children[0];

            if(first->type.type != struct_t){
                std::string message = "Variable " + first->name + " is not a struct";
                yy_sem_error(message);
                return error_type;
            }

            Struct *struct_info = (Struct *)global->getEntry(first->type.name)->ptr;
            std::vector<Variable> members = struct_info->members;
            bool found = false;
            for(auto member: members){
                if(member.name == second->name){
                    found = true;
                    first = second;
                    break;
                }
            }
            if(!found){
                std::string message = "Struct " + first->name + " does not have a member " + second->name;
                yy_sem_error(message);
                return error_type;
            }
            chain_node = chain_node->children[1];
            first = chain_node->children[0];
            second = chain_node->children[1];

        } while (chain_node->kind == identifier_chain);

        return error_type;
    }
    else if(node->kind == expr_stmt){
        resolve_expression(node, current, global);
        return node->type;
    }
    else return error_type;
}
// Function to check if the node of type initialiser_list is valid array
// Here dims is dimensions of the array in reverse(useful for popping)
// type in core type of the array
bool match_list_init_array(ASTNode *node, DataType type, std::vector<int> &dims, int dim_number, SymbolTable *current, SymbolTable *global){

    int x = dims.back();
    dims.pop_back();
    // if not enough children
    if (node->children.size() != x){

        std::string message = "Array dimension mismatch: Expected " + std::to_string(x) + " but got " + std::to_string(node->children.size());
        yy_sem_error(message);
        return false;
    }

    for (auto child : node->children){
        if (dims.size() == 0){
            if (type.type == struct_t && child->kind == list_init){ // structs must be handled separately
                Struct *struct_info = (Struct *)global->getEntry(type.name)->ptr;
                if (!match_list_init_struct(child, struct_info, current, global)){
                    return false;
                }
            }
            else if (child->kind == list_init){   // if the type is not struct, then it should be list_init, which is an error
                std::string message = "Array dimension mismatch: Expected " + std::to_string(dim_number) + " dimensions but got more";
                yy_sem_error(message);
                return false;
            }
            else{  // can be identifier chain, array_element, literal, first call resolve expression
                resolve_expression(child, current, global);
                if (child->type.type != type.type || child->type.name != type.name){
                    std::string message = "Type mismatch in array initialisation: Expected " + dtype_strings[type.type] + " but got " + dtype_strings[child->type.type];
                    yy_sem_error(message);
                    return false;
                }
            }
        }
        else if (child->kind != list_init){ // if the type is not struct, then it is other form of expression
            resolve_expression(child, current, global);
            if (child->type.type != type.type){
                std::string message = "Type mismatch in array initialisation: Expected " + dtype_strings[type.type] + " but got " + dtype_strings[child->type.type];
                yy_sem_error(message);
                return false;
            }

            // match dims
            if(dims.size() != child->type.ndims.size()){
                std::string message = "Array dimension mismatch: Expected " + std::to_string(dim_number) + " dimensions but got more";
                yy_sem_error(message);
                return false;
            } 

            for(int i = 0; i < dims.size(); i++){
                if(dims[i] != child->type.ndims[i]){
                    std::string message = "Array dimension mismatch: Expected " + std::to_string(dim_number) + " dimensions but got more";
                    yy_sem_error(message);
                    return false;
                }
            }

        }
        else{
            if (!match_list_init_array(child, type, dims, dim_number + 1, current, global)){
                return false;
            }
        }
    }

    return true;
}

// Function to check if the node of type initialiser_list is valid
bool match_list_init(ASTNode *node, DataType type, SymbolTable *current, SymbolTable *global){
    
        if (type.type == struct_t){
            Struct *struct_info = (Struct *)global->getEntry(type.name)->ptr;
            return match_list_init_struct(node, struct_info, current, global);
        }
        else if (type.ndims.size() == 0){
            std::string message = "Type mismatch in array initialisation: Expected " + dtype_strings[type.type] + " but got array";
            yy_sem_error(message);
            return false;
        }
        else{
            std::vector<int> dims = type.ndims;
            return match_list_init_array(node, type, dims, 0, current, global);
        }
}


// does type checks against unary operators
DataType resolve_unary_operator(ASTNode* node, std::string op, SymbolTable* current, SymbolTable* global){
    if(op != "-" && op != "!"){ // Check if the operator is unary
        std::string message = "Operator " + op + " requires two operands";
        yy_sem_error(message);
        return error_type;
    }
    if(node->type == error_type){
        return error_type;
    }

    DataType type = node->type;
    if(type.ndims.size() != 0){
        std::string message = "Arrays not allowed in unary expressions";
        yy_sem_error(message);
        return error_type;    
    }

    if(op == "-"){ // Checking valid types for unary operator
        if(type.type != int_t && type.type != float_t && type.type != long_t){
            std::string message = "Type mismatch in operator " + op;
            yy_sem_error(message);
            return error_type;
        }
        return type;
    }

    // handling not operator here
    if(type.type != int_t && type.type != float_t && type.type != long_t && type.type != bool_t){
            std::string message = "Type mismatch in operator " + op;
            yy_sem_error(message);
            return error_type;
    }
    return type;
}

// Function to resolve the expression
void resolve_expression(ASTNode* node, SymbolTable* current, SymbolTable* global){
    if(node->kind != expr_stmt){
        DataType type = retrieveType(node, current, global);
        return;
    }


    resolve_expression(node->children[0], current, global);

    resolve_expression(node->children[1], current, global);



}

// // useful for checking if the current node is a variable
// bool checkVariable(ASTNode* current){
//     return current->kind == variable_t;
// }

// struct type_info{
//     dtypes type;
//     int ndim;
//     std::string name;   //used in case of struct
// };

// // type_info create_info_struct(ASTNode* node, SymbolTable* global, SymbolTable* current){
// //     if(node -> kind == expr_stmt){
// //         return {(node -> type).type, 0,  ""};
// //     }
// //     else if(node -> kind == function_call_stmt){
// //         SymbolTableEntry* e = global -> getEntry(node -> name);
// //         Function* func_entry = (Function*)(e -> ptr);
// //         return {func_entry -> return_type, 0,  func_entry -> name};

// //     }
// //     else if(node -> kind == literal){
// //         return {(node -> type).type, 0, ""};
// //     }
// //     else if(node -> kind == array_element){
// //         SymbolTableEntry* e = current -> getEntryNested(node -> name);
// //         Variable* var_entry = (Variable*)  (e -> ptr);
// //         ASTNode* dims_node = node -> children[0];
// //         int count = 0;
// //         while(dims_node){
// //             count++;
// //             dims_node = dims_node -> next;
// //         }
// //         int dimension = (var_entry -> dims).size() - count;
// //         return {var_entry -> type, dimension, var_entry -> struct_name};
// //     }
// //     else if(variable_t){
// //         SymbolTableEntry* e = current -> getEntryNested(node -> name);
// //         Variable* var_entry = (Variable*)(e -> ptr);
// //         int dimension = (var_entry -> dims).size();
// //         return {var_entry -> type, dimension, var_entry -> struct_name};
// //     }
// //     // others dont have a data type
// // }
// //TODO: this function should return the type, dimension and the name of the struct, check RHS only for struct(happens in resolve_operator)
// // Function to check variable types and operator compatibility
// dtypes coerceTypesOverOperator(ASTNode* left, ASTNode* right, std::string op, SymbolTable* global, SymbolTable* current){
//     type_info left_info = create_info_struct(left, global, current);
//     type_info right_info = create_info_struct(right, global, current);

//     dtypes left_type = left_info.type;
//     dtypes right_type = right_info.type;
//     kind_t left_kind = left -> kind;
//     kind_t right_kind = right -> kind;

//     if(op == "."){  //TODO: left to do
//         if(right -> kind == expr_stmt && right -> name == "."){     //right kid is a dot operator
//             return right_type;
//         }
//         else if(right -> kind == variable_t);
//     }

//     //In assignment statement, if the left is not a variable or an array element or a struct element, then it is an error
//     if(op == "="){
//         if(left_kind != variable_t && left_kind != array_element && left -> name != ".")
//             return error_type;

//         goto arith_check; // to avoid code duplication
//     }
//     else if(op == "+" || op == "-" || op == "*" || op == "/" || op == "%"){

// arith_check:
//         if(left_type == int_t && right_type == int_t) // handling numerical cases
//             return int_t;
//         else if(left_type == float_t && right_type == float_t)
//             return float_t;
//         else if(left_type == long_t && right_type == long_t)
//             return long_t;
//         else if(left_type == float_t && right_type == int_t)
//             return float_t;
//         else if(left_type == int_t && right_type == float_t)
//             return float_t;
//         else if(left_type == long_t && right_type == int_t)
//             return long_t;
//         else if(left_type == int_t && right_type == long_t)
//             return long_t;
//         else if(left_type == long_t && right_type == float_t)
//             return float_t;
//         else if(left_type == float_t && right_type == long_t)
//             return float_t;

//         if(left_type == bool_t && right_type == bool_t) // handling boolean cases
//             return int_t;
//         else if(left_type == bool_t && right_type == int_t)
//             return int_t;
//         else if(left_type == int_t && right_type == bool_t)
//             return int_t;
//         else if(left_type == bool_t && right_type == float_t)
//             return float_t;
//         else if(left_type == float_t && right_type == bool_t)
//             return float_t;
//         else if(left_type == bool_t && right_type == long_t)
//             return long_t;
//         else if(left_type == long_t && right_type == bool_t)
//             return long_t;

//         // handling string/char
//         if(left_type== string_t && right_type == string_t && (op == "+" || op == "+="))
//             return string_t;
//         if(left_type == string_t && right_type == char_t && (op == "+" || op == "+="))
//             return string_t;

//         if(left_type == char_t && right_type == string_t && op == "+")
//             return string_t;

//         if(left_type == char_t && right_type == char_t && op == "+")
//             return string_t;

//         if(left_type == string_t && right_type == int_t && op == "+") // basically I can things like as worse as Javascript :()
//             return string_t;

//         if(op == "=" && left_type == right_type && (left -> type).name == (right -> type).name)
//             return left_type;

//         return error_type;

//     }
//     else if(op == "==" || op == "!=" || op == "<" || op == ">" || op == "<=" || op == ">="){
//         if(!(left_type == int_t || left_type == float_t || left_type == long_t || left_type == bool_t))
//             return error_type;

//         if(!(right_type == int_t || right_type == float_t || right_type == long_t || right_type == bool_t))
//             return error_type;

//         return bool_t;
//     }
//     else if(op == "&&" || op == "||"){
//         if(!(left_type == int_t || left_type == long_t || left_type == float_t || left_type == bool_t)){
//             return error_type;
//         }

//         if(!(right_type == int_t || right_type == long_t || right_type == float_t || right_type == bool_t)){
//             return error_type;
//         }

//         return bool_t;
//     }
//     else if(op == "+=" || op == "-=" || op == "*=" || op == "/=" || op == "%="){
//         if(left_kind != variable_t) // If the left is not a variable, then it is an error
//             return error_type;

//         goto arith_check; // to avoid code duplication
//     }
//     else return error_type;
// }

// // Check if variable is declared, but nested check
// bool checkVariableDeclared(ASTNode* current, SymbolTable* current_table){
//     // std:: cout << current << std::endl;
//     if(!current_table->checkNameNested(current->name)){
//         std::string message = "Variable " + current->name + " not declared";
//         yy_sem_error(message);
//         return false;
//     }
//     if(! current_table->checkNameNested(current->name, variable)){
//         std::string message = "Variable " + current->name + " already declared as a " + entry_type_strings[current_table->getEntry(current->name)->type];
//         yy_sem_error(message);
//         return false;
//     }
//     return true;
// }

// // Resolve the operator: Check if the variables are declared, check if the types are correct, check if the operators are correct
// bool resolve_operator(ASTNode* curNode, SymbolTable* current, SymbolTable* global){
//     if(curNode->getType() == error_type) // if this is the case, then some error must have occured below this level. Abort
//         return false;

//     std::string op = curNode->name;

//     ASTNode* left = curNode->children[0];

//     if(curNode->children.size() < 2){ // Handling Unary Operators
//         if(op != "-" && op != "!"){ // Check if the operator is unary
//             std::string message = "Operator " + op + " requires two operands";
//             yy_sem_error(message);
//             return false;
//         }

//         if(checkVariable(curNode) && !checkVariableDeclared(left, current)) // If the node is variable, check if it is declared
//             return false;

//         if(op == "-"){ // Checking valid types for unary operator
//             dtypes type = left->type.type;
//             if(type != int_t && type != float_t && type != long_t){
//                 std::string message = "Type mismatch in operator " + op;
//                 yy_sem_error(message);
//                 return false;
//             }
//             curNode->type = left->type;
//         }else{
//             curNode->type.type = bool_t;
//         }
//         return true;
//     }
//     ASTNode* right = curNode->children[1];
//     kind_t left_kind = left->kind, right_kind = right->kind;

//     if(checkVariable(right) && !checkVariableDeclared(right, current)) // Check if the right variable is declared
//         return false;
//     if(right_kind == variable_t) // annotating the type of the variable
//         right->type.type = ((Variable*)current->getEntryNested(right->name)->ptr)->type;
//     if(checkVariable(left) &&  !current->checkNameNested(left->name)){ // Check if the left variable is declared
//         if(op == "=" && right->type.type != error_type) // If the operator is assignment, then declare the variable implicitly
//             current->addVariable(left->name, (right->type).type, true);
//         else if(!(right->type.type != unknown_t)){ // Else throw an error
//             std::string message = "Variable " + left->name + " not declared";
//             yy_sem_error(message);
//             return false;
//         }
//     }
//     if(checkVariable(left) && !checkVariableDeclared(left, current)) // Check if the left variable is declared
//         return false;

//     if(left_kind == variable_t) // annotating the type of the variable
//         left->type.type = ((Variable*)current->getEntryNested(left->name)->ptr)->type;

//     curNode->type.type = coerceTypesOverOperator(left,right, op, global, current);

//     if(curNode->type.type == error_type){
//         std::string message = "Type mismatch in operator " + op + " between " + dtype_strings[left->type.type] + " and " + dtype_strings[right->type.type];
//         yy_sem_error(message);
//     }

//     return curNode->type.type != error_type;

// }



// // Takes a current rule node and fills the graph_edges with the order of the tasks(directed)
// bool build_order_graph(ASTNode* curRule,  std::vector<std::vector<bool>>& graph_edges, std::unordered_map<std::string, int>& task_mapping){
//     std::vector<ASTNode*> children = curRule->children;

//     // check both the starting and ending must not be all
//     if(children.size() < 2){
//         std::string message = "Order rule must have atleast two nodes";
//         yy_sem_error(message);
//         return false;
//     }

//     bool flag = false;
//     for(auto child: children){
//         for(auto grandchild: child->children){
//             if(task_mapping.find(grandchild->name) == task_mapping.end() && grandchild->name != "all"){
//                 std::string message = "Task " + grandchild->name + " not declared";
//                 yy_sem_error(message);
//                 flag = true;
//             }
//         }
//     }

//     if(flag) return false;

//     if(children[0]->children[0]->name == "all" && children[children.size() -1]->children[0]->name == "all"){
//         std::string message = "Can't Resolve the Order due to all";
//         yy_sem_error(message);
//         return false;
//     }

//     std::vector<std::string> all_nodes;
//     std::unordered_map<std::string, bool> used_nodes;
//     // resolve the first all :: all nodes except those which come after it
//     if(children[0]->children[0]->name == "all"){
//         for(int i = 1; i < children.size(); i++){
//             for(int j = 0; j < children[i]->children.size(); j++){
//                 used_nodes[children[i]->children[j]->name]= true;
//             }
//         }
//         for(auto kv: task_mapping){
//             if(used_nodes.find(kv.first) == used_nodes.end()){
//                 all_nodes.push_back(kv.first);
//             }
//         }

//         delete children[0]->children[0];
//         children[0]->children.pop_back();

//         for(int i = 0; i < all_nodes.size(); i++){
//             children[0]->children.push_back(new ASTNode(task_t, all_nodes[i]));
//             // std::cout << "Debugging: " << all_nodes[i] << std::endl;
//         }
//     }

//     // resolve the last all :: all nodes except those which come before it
//     if(children[children.size() - 1]->children[0]->name == "all"){
//         for(int i = 0; i < children.size() - 1; i++){
//             for(int j = 0; j < children[i]->children.size(); j++){
//                 used_nodes[children[i]->children[j]->name]= true;
//             }
//         }
//         for(auto kv: task_mapping){
//             if(used_nodes.find(kv.first) == used_nodes.end()){
//                 all_nodes.push_back(kv.first);
//             }
//         }

//         children[children.size() - 1]->children.pop_back();
//         delete children[children.size() - 1]->children[0];
//         for(int i = 0; i < all_nodes.size(); i++){
//             children[children.size() - 1]->children.push_back(new ASTNode(task_t, all_nodes[i]));
//         }
//     }

//     std::vector<int> prev_nodes;
//     for(int i = 0; i < children.size(); i++){
//         std::vector<int> cur_nodes;
//         std::cout << "i = " << i << std::endl;
//         for(int j = 0; j < children[i]->children.size(); j++){
//             cur_nodes.push_back(task_mapping[children[i]->children[j]->name]);
//             // std::cout << "Debugging: " << children[i]->children[j]->name << std::endl;
//         }
//         for(int j = 0; j < prev_nodes.size(); j++){
//             for(int k = 0; k < cur_nodes.size(); k++){
//                 graph_edges[prev_nodes[j]][cur_nodes[k]] = 1;
//                 // std::cout << "Debugging: edge between " << prev_nodes[j] << " and " << cur_nodes[k] << std::endl;
//             }
//         }
//         prev_nodes = cur_nodes;
//     }

//     return true;

// }

// bool check_circular(int i, std::vector<std::vector<bool>>& graph_edges, std::vector<int>& visited){
//     if(visited[i] == 1){
//         return false;
//     }
//     visited[i] = 1;
//     for(int j = 0; j < graph_edges.size(); j++){
//         if(graph_edges[i][j]){
//             if(check_circular(j, graph_edges, visited)){
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// void resolve_properties(ASTNode* curNode,  TaskGroup* taskGroupEntry, SymbolTable* global, std::unordered_set<std::string>& identifiers){
//     std::vector<ASTNode*> children = curNode->children;
//     std::string taskGroupName = curNode->name;
//     std::cout << "Resolving properties for " << taskGroupName << std::endl;
//     std::vector<std::string> task_names;
//     for(auto kv : taskGroupEntry->task_table){
//         task_names.push_back(kv.first);
//         std::cout << "Task: " << kv.first << std::endl;
//     }

//     std::unordered_map<std::string, int> task_mapping; // writing a task_mapping
//     for(int i = 0; i < task_names.size(); i++){
//         task_mapping[task_names[i]] = i;
//     }

//     // building a graph based on order nodes
//     std::vector<std::vector<bool>> graph_edges(task_names.size(), std::vector<bool>(task_names.size(), 0));

//     for(auto child: children){
//         if(child->kind == order_rule){
//             // fill the graph_edges with the order of the tasks(directed)
//             if(!build_order_graph(child, graph_edges, task_mapping)){
//                 return;
//             }
//         }
//         else if (child->kind == shared_rule){
//             ASTNode* left = child->children[0];
//             ASTNode* right = child->children[1];
//             DataType type = child->type;

//             // checking if children of left are all valid task_names/supervisor names
//             for(auto grandchild: right->children){
//                 if(identifiers.find(grandchild->name) == identifiers.end()){
//                     std::string message = "Task/Supervisor " + grandchild->name + " not declared";
//                     yy_sem_error(message);
//                 }
//             }

//             // checking if names on right are not declared as Function/Struct/TaskGroup
//             for(auto grandchild: left->children){
//                 grandchild->type = type;
//                 SymbolTableEntry* entry = global->getEntry(grandchild->name);
//                 if(entry != nullptr && entry->type != variable){ // if the entry is not a variable
//                     std::string message = "Variable " + grandchild->name + " already declared as a " + entry_type_strings[entry->type];
//                     yy_sem_error(message);
//                     continue;
//                 }

//                 if(identifiers.find(grandchild->name) != identifiers.end()){
//                     std::string message = "Variable " + grandchild->name + " already declared as a Task/Supervisor";
//                     yy_sem_error(message);
//                     continue;
//                 }

//                 for(auto tasks: right->children){
//                     if(identifiers.find(tasks->name) == identifiers.end())
//                         continue;

//                     SymbolTable* task_table = taskGroupEntry->retrieveTask(tasks->name);

//                     if(task_table->checkName(grandchild->name)){
//                         std::string message = "Variable " + grandchild->name + " already declared in task " + tasks->name;
//                         yy_sem_error(message);
//                     }

//                     task_table->addVariable(grandchild->name, type.type, false, type.reference, type.ndims, "", 0, 0);
//                 }
//             }

//         }
//     }

//     if(curNode->name=="order"){
//         // checking if the graph is cyclic or not
//         std::vector<int> visited(task_names.size(), 0);
//         std::vector<int> in_degree(task_names.size(), 0);
//         for(int i = 0; i < task_names.size(); i++){
//             for(int j = 0; j < task_names.size(); j++){
//                 if(graph_edges[i][j])
//                     in_degree[j]++;
//             }
//         }

//         std::queue<int> q;
//         for(int i = 0; i < task_names.size(); i++){
//             if(in_degree[i] == 0){
//                 q.push(i);
//             }
//         }

//         int count = 0;
//         while(q.size()){
//             int u = q.front();
//             q.pop();
//             for(int i = 0; i < task_names.size(); i++){
//                 if(graph_edges[u][i]){
//                     in_degree[i]--;
//                     if(in_degree[i] == 0){
//                         q.push(i);
//                     }
//                 }
//             }
//             count++;
//         }

//         if(count != task_names.size()){
//             // detect exact cycle
//             std::string message = "";
//             message+= "Tasks: ";

//             for(int i = 0 ; i < task_names.size(); i++){
//                 if(!visited[i]){
//                     message+= (task_names[i] + " ");
//                 }
//             }
//             message += "form parts of cycle";
//             yy_sem_error(message);
//         }
//     }
// }

// void resolve_taskgroup(ASTNode* curNode, SymbolTable* current, SymbolTable* global){
//     int order_count = 0, mem_count =0, shared_count = 0;
//     std::vector<ASTNode*> children = curNode->children;

//     std::string taskGroupName = curNode->name;
//     if(global->checkNameNested(taskGroupName)){ // Checking if similar named any other thing exists
//         std::string message = "Taskgroup " + taskGroupName + " already declared as " + entry_type_strings[global->getEntry(taskGroupName)->type];
//         yy_sem_error(message);
//         return;
//     }

//     global->addTaskGroup(taskGroupName);
//     TaskGroup* taskGroupEntry= (TaskGroup*)global->getEntry(taskGroupName)->ptr;
//     std::unordered_map<std::string, SymbolTable*>& task_table = taskGroupEntry->task_table; // getting reference to the task_table
//     std::unordered_map<std::string, SymbolTable*>& supervisor_table = taskGroupEntry->supervisor_table; // getting reference to the supervisor_table
//     std::unordered_set<std::string> identifiers;

//     for(ASTNode* child: children){
//         if(child->kind == properties_stmt){
//             order_count += (child->name == "order");
//             mem_count += (child->name == "mem");
//             shared_count += (child->name == "shared");
//             continue;
//         }
//         if(identifiers.find(child->name) != identifiers.end()){ // Checking if the task/supervisor is declared multiple times
//             std::string message = "Task/Supervisor " + child->name + " declared multiple times in taskgroup " + taskGroupName;
//             yy_sem_error(message);
//             return;
//         }

//         if(global->checkNameNested(child->name)){ // Checking if the task/supervisor is declared in the global scope
//             std::string message = "Task/Supervisor " + child->name + " already declared as a " + entry_type_strings[global->getEntry(child->name)->type];
//             yy_sem_error(message);
//             return;
//         }
//         identifiers.insert(child->name);

//         if(child->kind == task_stmt ) taskGroupEntry->addTask(child->name); // Adding the task to the task_table
//         else if(child->kind == supervisor_stmt) taskGroupEntry->addSupervisor(child->name); // Adding the supervisor to the supervisor_table
//     }

//     if(order_count > 1 || mem_count > 1 || shared_count > 1){ // Checking if the properties are declared multiple times
//             std::string message = "Property declared multiple times in taskgroup " + taskGroupName;
//             yy_sem_error(message);
//             return;
//     }
//     std::reverse(children.begin(), children.end());

//     for(ASTNode* child: children){
//         if(child->kind == properties_stmt){
//             resolve_properties(child, taskGroupEntry, global, identifiers);
//         }
//         else if(child->kind == task_stmt){
//             SymbolTable* current_table = taskGroupEntry->retrieveTask(child->name);
//             std::cout << "I am here for task: " << child->name << std::endl;
//             current_table->next = current;
//             current_table->print();
//             sem_test(child->children[0], current_table, global);
//             current_table->next = nullptr;
//         }
//     }
// }

// // Returns true if initialisation is correct. Else returns false
// bool is_correct_init(std::vector<int>& dims, dtypes type, std::string name, ASTNode* init_node, SymbolTable* global, SymbolTable* current){
//     if(init_node == NULL)   return true;    //no init

//     //handling array literal
//     if(type == int_t && dims.size() == 1 && init_node -> kind == literal && (init_node -> name == "range" || init_node -> name == "range_incl")){
//         int range_start = stoi((init_node -> children[0]) -> name);
//         int range_end = stoi((init_node -> children[1]) -> name);
//         int range_length = range_end - range_start;
//         if(init_node -> name == "range_incl")   range_length++;
//         if(range_length != dims[0]){
//             std::string message = "Array literal is of length: " +std::to_string(range_length)+". Expected length: "+std::to_string(dims[0])+".\n";
//         }
//     }

//     if(name == "" && dims.size() == 0){     //neither array, nor a struct
//         if(init_node -> kind == list_init){
//             std::string message = "Expected "+ dtype_strings[type] + " "+name + ". Received a list.\n";
//             yy_sem_error(message);
//             return false;
//         }
//         sem_test(init_node, current, global);
//         if(init_node -> type.type == error_type){      // if there is an issue in the init semantics
//             return false;
//         }
//         type_info rhs_type_info = create_info_struct(init_node, global, current);
//         if(rhs_type_info.ndim != 0 || rhs_type_info.type != type || rhs_type_info.name != name){    // TODO: there is an issue, if I do float x = 1; The current approach will give an error
//             std::string message = "Incorrect type, in initialisation\n";
//         }
//         return true;
//     }

//     else if(name != "" && dims.size() == 0){     // LHS is a struct
//         SymbolTableEntry* e = global -> getEntry(name);     // get the entry for the struct declaration from symbol table
//         Struct* struct_entry = (Struct*) (e -> ptr);

//         //init_node should be a list or a struct type of variable
//         if(init_node -> kind != list_init && init_node -> kind != variable_t){
//             std::string message = "Struct is not instantiated properly.\n";
//             yy_sem_error(message);
//             return false;
//         }

//         // if struct is initialised with another struct (using variable)
//         if(init_node -> kind == variable_t){
//             if(current -> checkNameNested(init_node -> name) == false){
//                 std::string message = init_node -> name +" not declared\n";
//                 yy_sem_error(message);
//                 return false;
//             }
//             type_info rhs_type_info = create_info_struct(init_node, global, current);
//             if(rhs_type_info.type != type || rhs_type_info.name != name){
//                 std::string message = init_node -> name + " is not if the expected type: " +dtype_strings[type] +" " +name+"\n";
//                 yy_sem_error(message);
//                 return false;
//             }
//             return true;
//         }

//         // now initialisation is done using list
//         // check if: no. of members in init list == no. of member data in struct
//         if((init_node -> children).size() != (struct_entry -> member_data).size()){
//             std::string message;
//             if((init_node -> children).size() > (struct_entry -> member_data).size()){
//                 message = "Too many initialisers for struct "+ name + ".\n";
//             }
//             else {
//                 message = "Too few initialisers for struct "+name + ".\n";
//             }
//             yy_sem_error(message);
//             return false;
//         }
//         // now check if each entry is of the expected type
//         for(int i = 0; i < (struct_entry -> member_data).size(); i++){
//             Variable member_data_entry = (struct_entry -> member_data)[i];
//             sem_test((init_node -> children)[i] , current, global);
//             if((init_node -> children)[i] -> type.type == error_type){
//                 return false;
//             }
//             if(is_correct_init(member_data_entry.dims, member_data_entry.type, member_data_entry.struct_name, (init_node -> children)[i] , global, current) == false){
//                 return false;
//             }
//         }
//         return true;
//     }

//     // LHS is array
//     else{
//         if(init_node -> kind != list_init && init_node -> kind != variable_t){
//             std::string message = "Array instantiation not correct!\n";
//             yy_sem_error(message);
//             return false;
//         }

//         //if init_node is a variable
//         if(init_node -> kind == variable_t){
//             if(current -> checkNameNested(init_node -> name) == false){
//                 std::string message = init_node -> name +" not declared\n";
//                 yy_sem_error(message);
//                 return false;
//             }
//             type_info rhs_type_info = create_info_struct(init_node, global, current);
//             if(rhs_type_info.type != type || rhs_type_info.name != name){
//                 std::string message = init_node -> name + " is not if the expected type: " +dtype_strings[type] +" " +name+"\n";
//                 yy_sem_error(message);
//                 return false;
//             }
//             return true;
//         }

//         //now instantiation is done using list
//         //check if the number of members in the list is correct
//         if(dims[0] != (init_node -> children).size()){
//             std::string message = "Incorrect number of members in the list instatiation.\n";
//             yy_sem_error(message);
//             return false;
//         }

//         // now check if each entry is of the expected type
//         for(int i = 0; i < dims[0] ; i++){
//             sem_test((init_node -> children)[i] , current, global);
//             if((init_node -> children)[i] -> type.type == error_type){
//                 return false;
//             }
//             std::vector<int> kid_dims(dims.begin() + 1, dims.end());
//             if(is_correct_init(kid_dims, type, name, (init_node -> children)[i] , global, current) == false){
//                 return false;
//             }

//         }
//         return true;
//     }

// }
// //TODO: give types to all the variable_t
// void sem_test(ASTNode* curNode, SymbolTable* current, SymbolTable* global){
//     if(curNode == nullptr)
//         return;
//     switch(curNode->kind){
//         case array_element:{
//             //TODO: should I check in global also here
//             SymbolTableEntry* e = (current -> getEntryNested(curNode -> name));
//             if(e == NULL){
//                 std::string message = "Variable " + curNode -> name + " is not declared\n";
//                 yy_sem_error(message);
//                 curNode -> type.type = error_type;
//                 break;
//             }
//             Variable* var_entry = (Variable*)(e -> ptr);
//             int ndims = (var_entry -> dims).size();
//             ASTNode* dims_node = curNode -> children[0];
//             int count = 0;
//             while(dims_node){
//                 count++;
//                 dims_node = dims_node -> next;
//             }
//             if(count > ndims){
//                 std::string message = curNode -> name + " is of dimension " + std::to_string(ndims) +". " + std::to_string(count) +" dimensions cannot be accessed.\n";
//                 curNode -> type.type = error_type;
//                 break;
//             }
//         }
//         case variable_t:{ //TODO: I am leaving this for now, bcuz I am lazy. If you want I will remove it later
//             if(!(current -> checkNameNested(curNode -> name))){ //if the name is not found
//                 std::string message = "Variable " + curNode -> name + " is not declared\n";
//                 yy_sem_error(message);
//                 curNode -> type.type = error_type;
//             }
//             break;
//         }
//         case decl_stmt:{
//             dtypes type = curNode->getType();
//             bool ref = curNode->type.reference;

//             if(type == struct_t){       // check if the struct is declared
//                 std::string dtype_struct_name = (curNode -> type).name;
//                 if(global -> checkName(dtype_struct_name, _struct) == false){
//                     std::string message = "Struct " + dtype_struct_name +" is not declared.\n";
//                     yy_sem_error(message);
//                     break;
//                 }
//             }

//             for(ASTNode* node: curNode->children){  //Ensure variable is not already declared

//                 if(current->checkName(node->name)){
//                     std::string message = "Variable " + node->name + " already declared";
//                     yy_sem_error(message);
//                     continue;
//                 }
//                 if(global->checkName(node->name, variable)){
//                     std::string message = "Variable " + node->name + " already declared as a " + entry_type_strings[global->getEntry(node->name)->type];
//                     yy_sem_error(message);
//                     continue;
//                 }
//                 bool has_value = false;

//                 if((node -> type).init_exp_or_id != NULL){  //if init expression is given in the form int[10][10, 10] arr
//                     sem_test((node -> type).init_exp_or_id, current, global);
//                     if(node -> type.type == error_type){
//                         node -> type.type = error_type;
//                         goto end;
//                     }
//                     type_info init_expr_type = create_info_struct((node -> type).init_exp_or_id, global, current);
//                     if(init_expr_type.ndim > 0){
//                         std::string message = "Initialisation expression does not have dimension 0.\n";
//                         yy_sem_error(message);
//                         node -> type.type = error_type;
//                         goto end;
//                     }
//                     if(init_expr_type.type != (curNode -> type).type || init_expr_type.name != (curNode -> type).name){
//                         std::string message = "Initialisation expression is not of the expected type.\n";
//                         yy_sem_error(message);
//                         node -> type.type = error_type;
//                         goto end;
//                     }
//                 }

//                 if(node->childExists()){ // If a child exists, then it is an assignment
//                     sem_test(node->children[0], current, global);
//                     if(is_correct_init(curNode -> type.ndims,curNode -> type.type, curNode -> name, (node -> children)[0], global, current) == false){
//                         break;
//                     }
//                     has_value = true;       //TODO: need to check for reference thing separately
//                     // coerceTypesOverOperator()
//                 }
//                 (node -> type).type = type;
//                 (node -> type).reference = ref;
//                 if((node -> children[0]) -> kind != variable_t){        // Assigning a non-variable to a reference.
//                     std::string message = "Assigning r-value reference to an l-value reference.\n";
//                 }
//                 current->addVariable(node->name, type, has_value,ref,node->type.ndims);
//             }
//             break;
//         }

//         case expr_stmt:{
//             std::cout << "Checking expression statement" << std::endl;
//             resolve_expression(curNode, current, global);
//             break;
//         }
//         case function_decl_stmt:
//         {
//             std::cout << "Checking function declaration" << std::endl;
//             std::string name = curNode->name;
//             if(current->checkName(name)){
//                 std::string message = "Function " + name + " already declared as a " +entry_type_strings[current->getEntry(name)->type];
//                 yy_sem_error(message);
//             }
//             if(current->checkName(name, function) ){

//                 std::string message = "Function " + name + " already declared";
//                 yy_sem_error(message);
//             }
//             if(global->checkName(name, prototype)){
//                 Function* func = (Function*)global->getEntry(name)->ptr;
//                 std::vector<Variable> params = func->param_list;
//                 for(int i = 0; i < params.size(); i++){
//                     Variable v = params[i];
//                     ASTNode*temp= curNode->children[0]->children[i];
//                     Variable v2(temp->name, (temp->type).type,(temp->type).ndims, (temp->type).reference,false, temp->name);
//                     if(v != v2){
//                         std::string message = "Type mismatch in function " + name;
//                         yy_sem_error(message);
//                     }
//                 }
//             }
//             std::vector<Variable> params;
//            ASTNode* params_list = curNode->children[0];
//               for(ASTNode* param: params_list->children){
//                 Variable v(param->name, param->getType(), param->type.ndims, param->type.reference, false, param->name);
//                 params.push_back(v);
//               }
//             global->addFunction(name, curNode->getType(), false, params, curNode->name);
//             break;
//         }
//         case prototype_stmt:
//         {
//             std::cout << "Checking function prototype" << std::endl;
//             std::string name = curNode->name;
//             if(current->checkName(name)){
//                 std::string message = "Function " + name + " already declared";
//                 yy_sem_error(message);
//             }
//             std::vector<Variable> params;
//             ASTNode* params_list = curNode->children[0];
//             for(ASTNode* param: params_list->children){
//                 Variable v(param->name, param->type.type, param->type.ndims, param->type.reference, false, param->name);
//                 params.push_back(v);
//             }
//             global->addFunction(name, curNode->getType(), true, params,curNode->name);
//             auto entry = global->getEntry(name);
//             if(entry != nullptr){
//                 entry->type = prototype;
//             }
//             break;
//         }
//         case function_call_stmt:
//         {
//             std::cout << "Checking function call" << std::endl;
//             std::string name = curNode->name;
//             if(!global->checkName(name, function)){
//                 std::string message = "Function " + name + " not declared";
//                 yy_sem_error(message);
//                 return;
//             }
//             Function* func = (Function*)global->getEntry(name)->ptr;
//             std::vector<Variable> params = func->param_list;
//             for(int i = 0; i < params.size(); i++){
//                 Variable v = params[i];
//                 ASTNode*temp= curNode->children[0]->children[i];
//                 SymbolTableEntry* entry = global->getEntry(temp->name);
//                 if(temp->kind==variable_t && entry != nullptr && entry->type != variable){ // if the entry is not a variable
//                     std::string message = "Variable " + temp->name + " already declared as a " + entry_type_strings[entry->type];
//                     yy_sem_error(message);
//                     return;
//                 }

//                 if((temp->kind==variable_t) && !(current->checkNameNested(temp->name))){
//                     std::string message = "Variable " + temp->name + " not declared";
//                     yy_sem_error(message);
//                     continue;
//                 }
//                 else if(temp->kind==literal)
//                 {

//                     temp->type.reference=false;

//                 }
//                 else{
//                     SymbolTableEntry*symbolnode=current->getEntryNested(temp->name);
//                     temp->type.type = ((Variable*)symbolnode->ptr)->type;
//                     temp->type.reference = ((Variable*)symbolnode->ptr)->reference;
//                 }

//                if(!v.typecheck(temp->type)){
//                    std::string message = "Type mismatch in function " + name;
//                    yy_sem_error(message);
//                }
//             }
//             break;
//         }
//         case taskgroup_stmt:
//         {
//             std::cout << "Checking taskgroup" << std::endl;
//             resolve_taskgroup(curNode, current, global);
//             break;
//         }

//         case parallel_stmt:
//         {
//             std::cout << "Checking parallel statement" << std::endl;
//             for(ASTNode* node: curNode->children){
//                 if((node->kind == variable_t))
//                 {
//                     SymbolTableEntry *curEntry = (current->getEntryNested(node->name));
//                     if((curEntry==nullptr)||(curEntry->type == function))
//                     {
//                         std::string message = "Variable " + node->name +" inside "+ node->name+ " list not declared";
//                         yy_sem_error(message);
//                         return;
//                     }
//                     entry_type node_exists = curEntry->type;

//                     // setting the metadata of variables inside the shared, reduction, private
//                     node->type.type = ((Variable *)(curEntry->ptr))->type;
//                     node->type.reference = ((Variable *)(curEntry->ptr))->reference;
//                     node->type.ndims = ((Variable *)(curEntry->ptr))->dims;

//                 }
//             }

//             for(ASTNode* node: curNode->children){
//                 if((node->kind == compound_stmt)||(node->kind == iterative_stmt))
//                     sem_test(node, current, global);
//             }
//             break;
//         }

//         case compound_stmt:
//         {
//             std::cout << "Checking compound statement" << std::endl;
//             for(ASTNode* node: curNode->children){
//                 sem_test(node, current, global);
//             }
//             break;
//         }

//         case err_t:
//         {
//             std::string message = "Error in parsing, skipping further checks for this node ...";
//             yy_sem_error(message);
//             break;
//         }

//         case iterative_stmt:
//         {
//             std::cout << "Checking iterative statement" << std::endl;
//             for(ASTNode* node: curNode->children){
//                 sem_test(node, current, global);
//             }
//             break;
//         }

//         case channel_stmt:
//         {
//             std::cout << "Checking channel statement" << std::endl;
//             for(ASTNode* node: curNode->children){
//                 sem_test(node, current, global);
//             }
//             break;
//         }

//         case keyword:
//         {
//             std::cout << "Reached keyword" << std::endl;
//             break;
//         }
//         case struct_decl:
//         {
//             std::cout << "Checking struct declaration statement\n";
//             std::string struct_name = curNode -> name;
//             std::vector<Variable> _members;
//             std::unordered_set<std::string> names_found;
//             for(const auto& member_line : curNode -> children){
//                 DataType* _type = &(member_line -> type);
//                 dtypes type = struct_t;
//                 std::vector<int>& dims = _type -> ndims;
//                 bool reference = _type -> reference;
//                 if(reference){
//                     std::string message = "Member data of type " + dtype_strings[curNode -> type.type] +" " + curNode -> type.name + " is a reference. Member data of struct cannot be a reference.\n";
//                     yy_sem_error(message);
//                     continue;
//                 }
//                 bool has_value = false;
//                 std::string struct_name = _type -> name;
//                 for(const auto& member: member_line -> children){
//                     if(names_found.find(member -> name) != names_found.end()){
//                         std::string message = "Member data with name " + member -> name + "has already been declared\n";
//                         yy_sem_error(message);
//                         continue;
//                     }
//                     names_found.insert(member -> name);
//                     Variable* v = new Variable(member -> name, type, dims, reference, has_value, struct_name);
//                     _members.push_back(*v);
//                 }
//             }
//             names_found.clear();
//             if(global -> checkName(struct_name, _struct)){  //struct already declared
//                 std::string message = "Struct " + struct_name + " already declared\n";
//                 yy_sem_error(message);
//                 break;
//             }
//             global -> addStruct(struct_name, _members);
//             break;
//         }
//         case member_data_t:     //If default args are allowed then will have to check for type handling
//             break;
//         case list_init:
//             break;
//     }

// end:
//     if(curNode->next != nullptr)
//         sem_test(curNode->next, current, global);
// }

// Stores the function names and structs in the global symbol table
void first_pass(ASTNode *node, SymbolTable *global){

    if (node == NULL)
        return;

    switch (node->kind){

    case function_decl_stmt:{

        // Check if the function is already declared
        if (global->checkName(node->name)){

            std::string message = "Function " + node->name + " already declared as a " + entry_type_strings[global->getEntry(node->name)->type];
            yy_sem_error(message);
        }

        std::unordered_set<std::string> param_names;
        std::vector<Variable> params;
        for (auto param_node : node->children[0]->children){

            // Handles Previously declared in list
            if (param_names.find(param_node->name) != param_names.end()){

                std::string message = "Variable" + node->name + " previously used in params of the function: " + node->name;
                yy_sem_error(message);
                continue;
            }

            // Handles previously declared variable as some differnt type
            if (global->checkName(param_node->name)){

                std::string message = "Variable" + node->name + " previously declared as a " + entry_type_strings[global->getEntry(node->name)->type];
                yy_sem_error(message);
                continue;
            }

            Variable *v = new Variable(param_node->name, param_node->type, param_node->line_number, param_node->col_number);
            params.push_back(*v);
        }

        global->addFunction(node->name, new Function(node->name, node->type, params, node->line_number, node->col_number));
        break;
    }
    case struct_decl:{

        // Check if the function is already declared
        if (global->checkName(node->name)){

            std::string message = "Struct " + node->name + " already declared as a " + entry_type_strings[global->getEntry(node->name)->type];
            yy_sem_error(message);
            break;
        }

        std::unordered_set<std::string> param_names;
        std::vector<Variable> params;
        for (auto param_node : node->children[0]->children){

            // Handles Previously declared in list
            if (param_names.find(param_node->name) != param_names.end()){

                std::string message = "Variable" + node->name + " previously used in Struct: " + node->name;
                yy_sem_error(message);
                continue;
            }

            // Handles previously declared variable as some differnt type
            if (global->checkName(param_node->name)){

                std::string message = "Variable" + node->name + " previously declared as a " + entry_type_strings[global->getEntry(node->name)->type];
                yy_sem_error(message);
                continue;
            }

            Variable *v = new Variable(param_node->name, param_node->type, param_node->line_number, param_node->col_number);
            params.push_back(*v);
        }

        global->addStruct(node->name, new Struct(node->name, params, node->line_number, node->col_number));
        break;
    }
    case syntax_error_stmt:{

        break;
    }
    }

    // Recursively call the function for the next node
    if (node->next != NULL)
        first_pass(node->next, global);
}

void second_pass(ASTNode *node, SymbolTable *current, SymbolTable *global){

    if (node == nullptr)
        return;

    switch (node->kind){

    case expr_stmt:{

        // resolve_expression(node, current, global);
        break;
    }
    }
    // Recursively call the function for the next node
    if (node->next != NULL)
        first_pass(node->next, global);
}