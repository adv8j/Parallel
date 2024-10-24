#pragma once
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>

typedef struct ParameterList{
    struct ParameterList* next;
    char* id;
    char* id_datatype;
    int ndim;
    bool reference;
}parameter_list;

//there is a map from function name to func_details
typedef struct FuncDetails{
    char* id;
    char* return_type;
    bool is_return_type_reference;
    parameter_list* param_list_head;
    int line_number;
}func_details;

typedef struct function_node
{
    func_details* info;
    struct function_node* next;
} function_node;

typedef struct function_table{
    int size;
    function_node** table;
    int p;//prime number
} function_table;
int bin_exp(int base, int power, int mod) {
    // Recursive binary exponentiation
    if (power == 0) return 1;
    if (power % 2 == 0) {
        int x = bin_exp(base, power/2, mod);
        return (x * x) % mod;
    }
    return (base * bin_exp(base, power-1, mod)) % mod;
}

// used to get the key for an identifier for searching or inserting in hash table
int get_key(char* name, int size, int p) {
    int key = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        key = (key % size + (name[i] * bin_exp(p, i, size)) % size) % size;
    }
    return key % size;
}

//function to initialise function table
function_table* function_table_init(int size){
    function_table* ft = (function_table*)malloc(sizeof(function_table));
    ft->size = size;
    ft->table = (function_node**)calloc(size,sizeof(function_node*));
    ft->p = 1e4+7;
    return ft;
}
//function to insert an entry in function table
void insert_function(function_table* ft, func_details* f){
    int key = get_key(f->id, ft->size, ft->p);
    function_node* node = (function_node*)malloc(sizeof(function_node));
    node->info = f;
    node->next = ft->table[key];
    ft->table[key] = node;
}
//function to search in function table and return its entry
func_details* search_function(function_table* ft, char* name){
    int key = get_key(name, ft->size, ft->p);
    function_node* temp = ft->table[key];
    while(temp!=NULL){
        if(strcmp(temp->info->id,name)==0){
            return temp->info;
        }
        temp = temp->next;
    }
    return NULL;
}
//function to add parameter in parameter list
void insert_parameter(parameter_list** head, char* id, char* id_datatype, int ndim, bool reference){
    parameter_list* temp = (parameter_list*)malloc(sizeof(parameter_list));
    temp->id = id;
    temp->id_datatype = id_datatype;
    temp->ndim = ndim;
    temp->reference = reference;
    temp->next = *head;
    *head = temp;
}
//function to initialise parameter list for a function
void initialise_parameter_list(parameter_list** head){
    *head = NULL;
}