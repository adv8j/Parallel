#include <iostream>
#include <string>
#include <vector>

enum dtypes{
    int_t,
    float_t,
    long_t,
    bool_t,
    char_t,
    string_t,
    unknown_t,
    struct_t,
    void_t,
};

const std::string dtype_strings[] = {
    "int",
    "float",
    "long",
    "bool",
    "char",
    "string",
    "unknown",
    "struct",
    "void",
};
