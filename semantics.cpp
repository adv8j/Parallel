#include "headers.hpp"
#include "symbol_table.cpp"
#include "AST.cpp"



int yy_sem_error(const std::string msg){
    std::cerr << msg << std::endl;
    return 0;
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

// Takes a current rule node and fills the graph_edges with the order of the tasks(directed)
bool build_order_graph(ASTNode* curRule,  std::vector<std::vector<bool>>& graph_edges, std::unordered_map<std::string, int>& task_mapping){
    std::vector<ASTNode*> children = curRule->children;

    // check both the starting and ending must not be all
    if(children.size() < 2){
        std::string message = "Order rule must have atleast two nodes";
        yy_sem_error(message);
        return false;
    }

    bool flag = false;
    for(auto child: children){
        for(auto grandchild: child->children){
            if(task_mapping.find(grandchild->name) == task_mapping.end() && grandchild->name != "all"){
                std::string message = "Task " + grandchild->name + " not declared";
                yy_sem_error(message);
                flag = true;
            }
        }
    }

    if(flag) return false;

    if(children[0]->children[0]->name == "all" && children[children.size() -1]->children[0]->name == "all"){
        std::string message = "Can't Resolve the Order due to all";
        yy_sem_error(message);
        return false;
    }

    std::vector<std::string> all_nodes;
    std::unordered_map<std::string, bool> used_nodes;
    // resolve the first all :: all nodes except those which come after it
    if(children[0]->children[0]->name == "all"){
        for(int i = 1; i < children.size(); i++){
            for(int j = 0; j < children[i]->children.size(); j++){
                used_nodes[children[i]->children[j]->name]= true;
            }
        }
        for(auto kv: task_mapping){
            if(used_nodes.find(kv.first) == used_nodes.end()){
                all_nodes.push_back(kv.first);
            }
        }
    
        delete children[0]->children[0];
        children[0]->children.pop_back();

        for(int i = 0; i < all_nodes.size(); i++){
            children[0]->children.push_back(new ASTNode(task_t, all_nodes[i]));
            // std::cout << "Debugging: " << all_nodes[i] << std::endl;
        }
    }

    // resolve the last all :: all nodes except those which come before it
    if(children[children.size() - 1]->children[0]->name == "all"){
        for(int i = 0; i < children.size() - 1; i++){
            for(int j = 0; j < children[i]->children.size(); j++){
                used_nodes[children[i]->children[j]->name]= true;
            }
        }
        for(auto kv: task_mapping){
            if(used_nodes.find(kv.first) == used_nodes.end()){
                all_nodes.push_back(kv.first);
            }
        }

        children[children.size() - 1]->children.pop_back();
        delete children[children.size() - 1]->children[0];
        for(int i = 0; i < all_nodes.size(); i++){
            children[children.size() - 1]->children.push_back(new ASTNode(task_t, all_nodes[i]));
        }
    }
    
    std::vector<int> prev_nodes;
    for(int i = 0; i < children.size(); i++){
        std::vector<int> cur_nodes;
        std::cout << "i = " << i << std::endl;
        for(int j = 0; j < children[i]->children.size(); j++){
            cur_nodes.push_back(task_mapping[children[i]->children[j]->name]);
            // std::cout << "Debugging: " << children[i]->children[j]->name << std::endl;
        }
        for(int j = 0; j < prev_nodes.size(); j++){
            for(int k = 0; k < cur_nodes.size(); k++){
                graph_edges[prev_nodes[j]][cur_nodes[k]] = 1;
                // std::cout << "Debugging: edge between " << prev_nodes[j] << " and " << cur_nodes[k] << std::endl;
            }
        }
        prev_nodes = cur_nodes;
    }

    return true;
    
}

bool check_circular(int i, std::vector<std::vector<bool>>& graph_edges, std::vector<int>& visited){
    if(visited[i] == 1){
        return false;
    }
    visited[i] = 1;
    for(int j = 0; j < graph_edges.size(); j++){
        if(graph_edges[i][j]){
            if(check_circular(j, graph_edges, visited)){
                return true;
            }
        }
    }
    return false;
}



void resolve_properties(ASTNode* curNode,  TaskGroup* taskGroupEntry, SymbolTable* global, std::unordered_set<std::string>& identifiers){
    std::vector<ASTNode*> children = curNode->children;
    std::string taskGroupName = curNode->name;
    std::cout << "Resolving properties for " << taskGroupName << std::endl;
    std::vector<std::string> task_names;
    for(auto kv : taskGroupEntry->task_table){
        task_names.push_back(kv.first);
        std::cout << "Task: " << kv.first << std::endl;
    }

    std::unordered_map<std::string, int> task_mapping; // writing a task_mapping
    for(int i = 0; i < task_names.size(); i++){
        task_mapping[task_names[i]] = i;
    }

    // building a graph based on order nodes
    std::vector<std::vector<bool>> graph_edges(task_names.size(), std::vector<bool>(task_names.size(), 0));

    for(auto child: children){
        if(child->kind == order_rule){
            // fill the graph_edges with the order of the tasks(directed)
            if(!build_order_graph(child, graph_edges, task_mapping)){
                return;
            }
        }
        else if (child->kind == shared_rule){
            ASTNode* left = child->children[0];
            ASTNode* right = child->children[1];
            DataType type = child->type;

            // checking if children of left are all valid task_names/supervisor names
            for(auto grandchild: right->children){
                if(identifiers.find(grandchild->name) == identifiers.end()){
                    std::string message = "Task/Supervisor " + grandchild->name + " not declared";
                    yy_sem_error(message);
                }
            }

            // checking if names on right are not declared as Function/Struct/TaskGroup
            for(auto grandchild: left->children){
                grandchild->type = type;
                SymbolTableEntry* entry = global->getEntry(grandchild->name);
                if(entry != nullptr && entry->type != variable){ // if the entry is not a variable
                    std::string message = "Variable " + grandchild->name + " already declared as a " + entry_type_strings[entry->type];
                    yy_sem_error(message);
                    continue;
                }

                if(identifiers.find(grandchild->name) != identifiers.end()){
                    std::string message = "Variable " + grandchild->name + " already declared as a Task/Supervisor";
                    yy_sem_error(message);
                    continue;
                }

                for(auto tasks: right->children){
                    if(identifiers.find(tasks->name) == identifiers.end())
                        continue;
                    
                    SymbolTable* task_table = taskGroupEntry->retrieveTask(tasks->name);
                    
                    if(task_table->checkName(grandchild->name)){
                        std::string message = "Variable " + grandchild->name + " already declared in task " + tasks->name;
                        yy_sem_error(message);
                    }

                    task_table->addVariable(grandchild->name, type.type, false, type.reference, type.ndims, "", 0, 0);
                }
            }

        }
    }   

    if(curNode->name=="order"){
        // checking if the graph is cyclic or not
        std::vector<int> visited(task_names.size(), 0);
        std::vector<int> in_degree(task_names.size(), 0);
        for(int i = 0; i < task_names.size(); i++){
            for(int j = 0; j < task_names.size(); j++){
                if(graph_edges[i][j])
                    in_degree[j]++;
            }
        }

        std::queue<int> q;
        for(int i = 0; i < task_names.size(); i++){
            if(in_degree[i] == 0){
                q.push(i);
            }
        }

        int count = 0;
        while(q.size()){
            int u = q.front();
            q.pop();
            for(int i = 0; i < task_names.size(); i++){
                if(graph_edges[u][i]){
                    in_degree[i]--;
                    if(in_degree[i] == 0){
                        q.push(i);
                    }
                }
            }
            count++;
        }

        if(count != task_names.size()){
            // detect exact cycle
            std::string message = "";
            message+= "Tasks: ";

            for(int i = 0 ; i < task_names.size(); i++){
                if(!visited[i]){
                    message+= (task_names[i] + " ");
                }
            }
            message += "form parts of cycle";
            yy_sem_error(message);
        }
    }
}


void resolve_taskgroup(ASTNode* curNode, SymbolTable* current, SymbolTable* global){
    int order_count = 0, mem_count =0, shared_count = 0;
    std::vector<ASTNode*> children = curNode->children;

    std::string taskGroupName = curNode->name;
    if(global->checkNameNested(taskGroupName)){ // Checking if similar named any other thing exists
        std::string message = "Taskgroup " + taskGroupName + " already declared as " + entry_type_strings[global->getEntry(taskGroupName)->type];
        yy_sem_error(message);
        return;
    }

    global->addTaskGroup(taskGroupName); 
    TaskGroup* taskGroupEntry= (TaskGroup*)global->getEntry(taskGroupName)->ptr;
    std::unordered_map<std::string, SymbolTable*>& task_table = taskGroupEntry->task_table; // getting reference to the task_table
    std::unordered_map<std::string, SymbolTable*>& supervisor_table = taskGroupEntry->supervisor_table; // getting reference to the supervisor_table
    std::unordered_set<std::string> identifiers;

    for(ASTNode* child: children){
        if(child->kind == properties_stmt){
            order_count += (child->name == "order");
            mem_count += (child->name == "mem");
            shared_count += (child->name == "shared");
            continue;
        }
        if(identifiers.find(child->name) != identifiers.end()){ // Checking if the task/supervisor is declared multiple times
            std::string message = "Task/Supervisor " + child->name + " declared multiple times in taskgroup " + taskGroupName;
            yy_sem_error(message);
            return;
        }

        if(global->checkNameNested(child->name)){ // Checking if the task/supervisor is declared in the global scope
            std::string message = "Task/Supervisor " + child->name + " already declared as a " + entry_type_strings[global->getEntry(child->name)->type];
            yy_sem_error(message);
            return;
        }
        identifiers.insert(child->name);

        if(child->kind == task_stmt ) taskGroupEntry->addTask(child->name); // Adding the task to the task_table
        else if(child->kind == supervisor_stmt) taskGroupEntry->addSupervisor(child->name); // Adding the supervisor to the supervisor_table
    }



    if(order_count > 1 || mem_count > 1 || shared_count > 1){ // Checking if the properties are declared multiple times
            std::string message = "Property declared multiple times in taskgroup " + taskGroupName;
            yy_sem_error(message);
            return;
    }
    std::reverse(children.begin(), children.end());

    for(ASTNode* child: children){
        if(child->kind == properties_stmt){
            resolve_properties(child, taskGroupEntry, global, identifiers);
        }
        else if(child->kind == task_stmt){
            SymbolTable* current_table = taskGroupEntry->retrieveTask(child->name);
            std::cout << "I am here for task: " << child->name << std::endl;
            current_table->next = current;
            current_table->print();
            sem_test(child->children[0], current_table, global);
            current_table->next = nullptr;
        }
    }
}


void sem_test(ASTNode* curNode, SymbolTable* current, SymbolTable* global){
    if(curNode == nullptr)
        return;
    switch(curNode->kind){
        case decl_stmt:{
            dtypes type = curNode->getType();
            bool ref = curNode->type.reference;

            for(ASTNode* node: curNode->children){

                if(current->checkName(node->name)){
                    std::string message = "Variable " + node->name + " already declared";
                    yy_sem_error(message);
                    continue;
                }
                if(global->checkName(node->name, variable)){  
                    std::string message = "Variable " + node->name + " already declared as a " + entry_type_strings[global->getEntry(node->name)->type];
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
                Variable v(param->name, param->getType(), param->type.ndims, param->type.reference, false, param->name);
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
        case function_call_stmt:
        {
            std::cout << "Checking function call" << std::endl;
            std::string name = curNode->name;
            if(!global->checkName(name, function)){
                std::string message = "Function " + name + " not declared";
                yy_sem_error(message);
                return;
            }
            Function* func = (Function*)global->getEntry(name)->ptr;
            std::vector<Variable> params = func->param_list;
            for(int i = 0; i < params.size(); i++){
                Variable v = params[i];
                ASTNode*temp= curNode->children[0]->children[i];
                SymbolTableEntry* entry = global->getEntry(temp->name);
                if(temp->kind==variable_t && entry != nullptr && entry->type != variable){ // if the entry is not a variable
                    std::string message = "Variable " + temp->name + " already declared as a " + entry_type_strings[entry->type];
                    yy_sem_error(message);
                    return;
                }
                
                if((temp->kind==variable_t) && !(current->checkNameNested(temp->name))){
                    std::string message = "Variable " + temp->name + " not declared";
                    yy_sem_error(message);
                    continue;
                }
                else if(temp->kind==literal)
                {
                    
                    temp->type.reference=false;
                    
                }
                else{
                    SymbolTableEntry*symbolnode=current->getEntryNested(temp->name);
                    temp->type.type = ((Variable*)symbolnode->ptr)->type;
                    temp->type.reference = ((Variable*)symbolnode->ptr)->reference;
                }

                
               if(!v.typecheck(temp->type)){
                   std::string message = "Type mismatch in function " + name;
                   yy_sem_error(message);
               }
            }
            break;
        }
        case taskgroup_stmt:
        {
            std::cout << "Checking taskgroup" << std::endl;
            resolve_taskgroup(curNode, current, global);
            break;
        }

        case parallel_stmt:
        {
            std::cout << "Checking parallel statement" << std::endl;
            for(ASTNode* node: curNode->children){
                if((node->kind == variable_t))
                {
                    SymbolTableEntry *curEntry = (current->getEntryNested(node->name));
                    if((curEntry==nullptr)||(curEntry->type == function))
                    {
                        std::string message = "Variable " + node->name +" inside "+ node->name+ " list not declared";
                        yy_sem_error(message);
                        return;
                    }
                    entry_type node_exists = curEntry->type;

                    // setting the metadata of variables inside the shared, reduction, private
                    node->type.type = ((Variable *)(curEntry->ptr))->type;
                    node->type.reference = ((Variable *)(curEntry->ptr))->reference;
                    node->type.ndims = ((Variable *)(curEntry->ptr))->dims;

                }
            }

            for(ASTNode* node: curNode->children){
                if((node->kind == compound_stmt)||(node->kind == iterative_stmt))
                    sem_test(node, current, global);
            }
            break;
        }

        case compound_stmt:
        {
            std::cout << "Checking compound statement" << std::endl;
            for(ASTNode* node: curNode->children){
                sem_test(node, current, global);
            }
            break;
        }

        case err_t:
        {
            std::string message = "Error in parsing, skipping further checks for this node ...";
            yy_sem_error(message);
            break;
        }

        case iterative_stmt:
        {
            std::cout << "Checking iterative statement" << std::endl;
            for(ASTNode* node: curNode->children){
                sem_test(node, current, global);
            }
            break;
        }

        case channel_stmt:
        {
            std::cout << "Checking channel statement" << std::endl;
            for(ASTNode* node: curNode->children){
                sem_test(node, current, global);
            }
            break;
        }

        case keyword:
        {
            std::cout << "Reached keyword" << std::endl;
            break;
        }
    }
    if(curNode->next != nullptr)
        sem_test(curNode->next, current, global);
}