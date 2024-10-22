#pragma once
#include<stdbool.h>

typedef struct MemberData{
    struct MemberData* next;
    char* id;
    //doubt regarding member data
} member_data;

typedef struct StructDetails{
    char* id;
    member_data* member_data_list;
    int line_number;
}struct_details;

//function to initialise struct table

//function to insert an entry in struct table

//function to search in struct table and return its entry

//function to add member_data to member data list


//function to initialise member data list for a struct
