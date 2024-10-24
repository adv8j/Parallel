#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//stores info about an object or basic variable created
typedef struct IdentifierDetails{
    char* name;
    bool has_value;
    char* type;
    int ndim;        //dimension = 0, if id is just a normal variable //dimension = 1 for 1-D array
    int line_number;
    bool reference;
} IdentifierDetails;

//entry in a symbol table
typedef struct symbol_node {
    IdentifierDetails *info;
    struct symbol_node *next;
} symbol_node;

typedef struct symbol_table{
    symbol_node** table;
    int size;
    int p; // prime number used for hashing
} symbol_table;

//creating a symbol table
symbol_table* symbol_table_init(int size) {
    symbol_table* st = (symbol_table*)malloc(sizeof(symbol_table));
    st->table = (symbol_node**)malloc(size * sizeof(symbol_node*));
    st->size = size;
    st->p = 1e4+7;
    return st;
}

//binary exponentiation hash function used for hashing the entries in symbol table
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

//insert an entry in symbol table when a new identifier is found
void insert(symbol_table* st, IdentifierDetails* s) {
    int key = get_key(s->name, st->size, st->p);
    symbol_node* node = (symbol_node*)malloc(sizeof(symbol_node));
    node->next = st->table[key];
    node->info = s;
    st->table[key] = node;
}

//initialises an entry in symbol table and returns it
IdentifierDetails* symbol_init(char *name, bool has_value, char *type, int ndim, bool reference, int line_number) {
    IdentifierDetails *s = (IdentifierDetails*)malloc(sizeof(IdentifierDetails));
    s->name = name;
    s->has_value = has_value;
    s->type = type;
    s->ndim = ndim;
    s->reference = reference;
    s->line_number=line_number;
    return s;
}

//returns 1 if found, else returns 0
bool search(symbol_table* st, char* name) {
    int key = get_key(name, st->size, st->p);
    symbol_node* node = st->table[key];
    while (node != NULL) {
        if (strcmp(node->info->name, name) == 0) {
            return true;
        }
        node = node->next;
    }
    return false;
}

//function to return details for an id from symbol table
IdentifierDetails* get_id_details(symbol_table* st, char* name){
    int key = get_key(name, st->size, st->p);
    symbol_node* node = st->table[key];
    while (node != NULL) {
        if (strcmp(node->info->name, name) == 0) {
            return node -> info;
        }
        node = node -> next;
    }
    return NULL;
}

void symbol_insert(symbol_table* st, char *name, bool has_value, char *type,int ndim,bool reference, int line_number) {
    IdentifierDetails *s = symbol_init(name, has_value, type, ndim, reference, line_number);
    insert(st, s);
}

// free this symbol table
void free_table(symbol_table* st) {
    for (int i = 0; i < st->size; i++) {
        symbol_node* node = st->table[i];
        while (node != NULL) {
            symbol_node* temp = node;
            node = node->next;
            free(temp->info);
            free(temp);
        }
    }
    free(st->table);
    free(st);
}