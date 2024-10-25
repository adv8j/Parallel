#pragma once
#include <cstddef>
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

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
}struct_details;
typedef struct struct_node
{
    struct_details* info;
    struct struct_node* next;
} struct_node;
typedef struct struct_table
{
    int size;
    struct_node** table;
    int p;//prime number
}struct_table;
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

//function to initialise struct table
struct_table* struct_table_init(int size)
{
    struct_table* st = (struct_table*)malloc(sizeof(struct_table));
    st->size = size;
    st->table = (struct_node**)calloc(size,sizeof(struct_node*));
    st->p = 1e4+7;
    return st;
}

//function to insert an entry in struct table
void struct_table_insert(struct_table* table, char* id, member_data* member_data_list, int line_number)
{
    struct_details* s = (struct_details*)malloc(sizeof(struct_details));
    s->id = id;
    s->member_data_list = member_data_list;
    s->line_number = line_number;
    int key = get_key(id,table->size,table->p);
    struct_node* node = (struct_node*)malloc(sizeof(struct_node));
    node->info = s;
    node->next = table->table[key];
    table->table[key] = node;
}
//function to search in struct table and return its entry
struct_details* struct_table_search(struct_table* table, char* id)
{
    int key = get_key(id,table->size,table->p);
    struct_node* temp = table->table[key];
    while(temp!=NULL)
    {
        if(strcmp(temp->info->id,id)==0)
        {
            return temp->info;
        }
        temp = temp->next;
    }
    return NULL;

}
//function to add member_data to member data list
void add_member(member_data* list, char* id)
{
    member_data* temp = list;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    member_data* new_member = (member_data*)malloc(sizeof(member_data));
    new_member->id = id;
    new_member->next = NULL;
    temp->next = new_member;
}

//function to initialise member data list for a struct
void initialise_member_data_list(member_data ** head)
{
    *head=NULL;
}