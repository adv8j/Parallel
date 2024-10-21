#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct symbol{
    char* name;
    bool has_value;
    char* type;
    int line_number;
} symbol;

typedef struct symbol_node {
    symbol *sym;
    struct symbol_node *next;
} symbol_node;

typedef struct symbol_table{
    symbol_node** table;
    int size;
    int p;
} symbol_table;

symbol_table* symbol_table_init(int size) {
    symbol_table* st = (symbol_table*)malloc(sizeof(symbol_table));
    st->table = (symbol_node**)malloc(size * sizeof(symbol_node*));
    st->size = size;
    st->p = 1e4+7;
    return st;
}

int bin_exp(int base, int power, int mod) {
    // Recursive binary exponentiation
    if (power == 0) return 1;
    if (power % 2 == 0) {
        int x = bin_exp(base, power/2, mod);
        return (x * x) % mod;
    }
    return (base * bin_exp(base, power-1, mod)) % mod;
}

int get_key(char* name, int size, int p) {
    int key = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        key = (key % size + (name[i] * bin_exp(p, i, size)) % size) % size;
    }
    return key % size;
}

void insert(symbol_table* st, symbol* s) {
    int key = get_key(s->name, st->size, st->p);
    symbol_node* node = (symbol_node*)malloc(sizeof(symbol_node));
    node->next = st->table[key];
    node->sym = s;
    st->table[key] = node;
}

symbol* symbol_init(char *name, bool has_value, char *type, int line_number){
    symbol *s = (symbol*)malloc(sizeof(symbol));
    s->name = name;
    s->has_value = has_value;
    s->type = type;
    s->line_number = line_number;
    return s;
}