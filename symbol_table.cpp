#include "headers.hpp"




class Variable{
public:
    std::string name;
    dtypes type;
    std::string struct_name;
    std::vector<int> dims;
    int access = 2; // 0-> copy, 1-> read_only, 2-> read_write(useful for TaskGroup)
    bool reference;
    bool has_value;
    int line_number;
    int col_no;
    Variable(std::string name, dtypes type, std::vector<int> dims ={}, bool reference = false, bool has_value = false, int line_number = 0, int col_no = 0, std::string struct_name=""):name(name),type(type),dims(dims),reference(reference),has_value(has_value),line_number(line_number),col_no(col_no), struct_name(struct_name){}
};

class Function{
public:
    std::string name;
    dtypes return_type;
    std::string return_struct_name;
    std::vector<Variable> param_list;
    int line_number;
    int col_no;

    Function(std::string name, dtypes return_type, std::vector<Variable> param_list = {}, int line_number = 0, int col_no = 0, std::string return_struct_name = ""):name(name),return_type(return_type),param_list(param_list),line_number(line_number),col_no(col_no), return_struct_name(return_struct_name){}
};

class Struct{
public:
    std::string name;
    std::vector<Variable> member_data;
    int line_number;
    int col_no;
    Struct(std::string name, std::vector<Variable> member_data = {}, int line_number = 0, int col_no = 0):name(name),member_data(member_data),line_number(line_number),col_no(col_no){}
};


class SymbolTableEntry{
    public:
    entry_type type;
    std::string name;
    void* ptr;
    SymbolTableEntry(){}
    SymbolTableEntry(entry_type type, std::string name, void* ptr):type(type),name(name),ptr(ptr){}
};


class SymbolTable {
private:
    std::unordered_map<std::string, SymbolTableEntry> table;
    SymbolTable* next = nullptr;

public:
    void addEntry(const SymbolTableEntry& entry) {
        table[entry.name] = entry;
    }

    SymbolTableEntry* getEntry(const std::string& name) {
        auto it = table.find(name);
        if (it != table.end()) {
            return &(it->second);
        }
        return nullptr;
    }

    bool removeEntry(const std::string& name) {
        return table.erase(name) > 0;
    }

};

class TaskGroup{
    std::string name;
    int line_number;
    int col_no;
    std::unordered_map<std::string, SymbolTable> task_table;

    TaskGroup(std::string name, int line_number = 0, int col_no = 0):name(name),line_number(line_number),col_no(col_no){}

    void addTask(const std::string& task_name){
        task_table[task_name] = SymbolTable();
    }

    SymbolTable* retrieveTask(const std::string& task_name){
        auto it = task_table.find(task_name);
        if(it != task_table.end()){
            return &(it->second);
        }
        return nullptr;
    }
};


