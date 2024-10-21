#include "symbol_table.c"
#include"functions_table.c"


//this is using to store in symbol table in 
//used to handle scoping
typedef struct StackElement{
    struct StackElement* parent;
    symbol_table* symbol_table_ptr;
}stack_element;

//used to initialise stack
stack_element* init_stack(){
    stack_element* top = (stack_element*) malloc(sizeof(stack_element));
    top -> parent = NULL;
    top -> symbol_table_ptr = symbol_table_init(0);
    return top;
}

//used to push push a new symbol table in the stack
stack_element* push_symbol_table(stack_element* top){
    stack_element* new_table = (stack_element*) malloc(sizeof(stack_element));
    new_table -> parent = top;
    new_table -> symbol_table_ptr = symbol_table_init(0);
    return new_table;
}

//return 1 if found, else returns 0
bool search_id_curr_scope(stack_element*top, char* id){
    symbol_table* table = top -> symbol_table_ptr;
    return search(table, id);
}

//function to add an identifier in symbol table         //make return type int//to check if sucessful or not
void push_entry_in_current_scope(stack_element* top , char* name, bool has_value, char* type, int ndim, int line_number, bool reference){
    symbol_table* table = top -> symbol_table_ptr;
    IdentifierDetails* new_entry = symbol_init(name, has_value, type, ndim, reference, line_number);
    insert(table, new_entry);
}

//function to get the details of the element
IdentifierDetails* get_id_entry(stack_element* top, char* name){
    stack_element* curr_stack_element = top;
    while(curr_stack_element){
        IdentifierDetails* id_entry = get_id_details(curr_stack_element -> symbol_table_ptr, name);
        if(id_entry){
            return id_entry;
        }
        curr_stack_element = curr_stack_element -> parent;
    }
    return NULL;
}

//pops symbol table from stack
IdentifierDetails* pop_stack(stack_element* top){
    stack_element* next = top -> parent;
    //free everything in top
}

