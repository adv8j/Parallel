#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct MemberData {
    struct MemberData* next;
    char* id;  // Identifier for the struct member
} member_data;

typedef struct StructDetails {
    char* id;  // Identifier for the struct
    member_data* member_data_list;  // Linked list of members
    int line_number;  // Line number where the struct is defined
    struct StructDetails* next;  // For chaining in the hash table
} struct_details;

typedef struct StructTable {
    struct_details** table;
    int size;
} StructTable;

// Initialize the struct table
StructTable* init_struct_table(int size) {
    StructTable* st = (StructTable*)malloc(sizeof(StructTable));
    st->size = size;
    st->table = (struct_details**)malloc(size * sizeof(struct_details*));
    for (int i = 0; i < size; ++i) {
        st->table[i] = NULL;
    }
    return st;
}

// Hash function for struct names
int hash_struct_name(char* name, int size) {
    unsigned long hash = 5381;
    int c;
    while ((c = *name++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash % size;
}

// Insert a struct entry into the struct table
void insert_struct(StructTable* st, struct_details* sd) {
    int key = hash_struct_name(sd->id, st->size);
    sd->next = st->table[key];
    st->table[key] = sd;
}

// Search for a struct in the struct table
struct_details* search_struct(StructTable* st, char* id) {
    int key = hash_struct_name(id, st->size);
    struct_details* sd = st->table[key];
    while (sd != NULL) {
        if (strcmp(sd->id, id) == 0) {
            return sd;
        }
        sd = sd->next;
    }
    return NULL;
}

// Add member data to the member data list of a struct
void add_member_data(member_data** head, char* id) {
    member_data* new_member = (member_data*)malloc(sizeof(member_data));
    new_member->id = strdup(id);
    new_member->next = *head;
    *head = new_member;
}

// Initialize member data list for a struct
member_data* init_member_data_list() {
    return NULL; // Returns NULL as the head of an empty list
}
