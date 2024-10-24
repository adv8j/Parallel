#pragma once
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct MemberData{
    struct MemberData* next;
    char* id;
    char* datatype;
    int ndim;
    bool reference;
} member_data;

typedef struct StructDetails{
    char* id;
    member_data* member_data_list;
    int line_number;
} struct_details;

typedef struct struct_node
{
    struct_details* info;
    struct struct_node* next;
} struct_node;

typedef struct struct_table{
    int size;
    struct_node** table;
    int p; // prime number used for hashing
} struct_table;
int bin_exp(int base, int power, int mod) {
    // Recursive binary exponentiation
    if (power == 0) return 1;
    if (power % 2 == 0) {
        int x = bin_exp(base, power / 2, mod);
        return (x * x) % mod;
    }
    return (base * bin_exp(base, power - 1, mod)) % mod;
}

int get_key(char* name, int size, int p) {
    int key = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        key = (key % size + (name[i] * bin_exp(p, i, size)) % size) % size;
    }
    return key % size;
}

struct_table* struct_table_init(int size){
    struct_table* st = (struct_table*)malloc(sizeof(struct_table));
    st->size = size;
    st->table = (struct_node**)calloc(size, sizeof(struct_node*));
    st->p = 1e4+7;
    return st;
}

void insert_struct(struct_table* st, struct_details* s){
    int key = get_key(s->id, st->size, st->p);
    struct_node* node = (struct_node*)malloc(sizeof(struct_node));
    node->info = s;
    node->next = st->table[key];
    st->table[key] = node;
}

struct_details* search_struct(struct_table* st, char* name){
    int key = get_key(name, st->size, st->p);
    struct_node* temp = st->table[key];
    while(temp != NULL){
        if(strcmp(temp->info->id, name) == 0){
            return temp->info;
        }
        temp = temp->next;
    }
    return NULL;
}

void insert_member_data(member_data** head, char* id, char* datatype, int ndim, bool reference){
    member_data* temp = (member_data*)malloc(sizeof(member_data));
    temp->id = id;
    temp->datatype = datatype;
    temp->ndim = ndim;
    temp->reference = reference;
    temp->next = *head;
    *head = temp;
}

void initialise_member_data_list(member_data** head){
    *head = NULL;
}
