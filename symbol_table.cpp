#include "headers.hpp"


// Variable Entry for the Symbol Table
class Variable{
public:
    std::string name;
    DataType type;
    int line_number;
    int col_no;

    Variable(std::string name, DataType type, int line_number = 0, int col_no = 0) : name(name), type(type), line_number(line_number), col_no(col_no) {}
    
    bool operator==(const Variable &v) const{
        bool return_val = this->name == v.name && this->type == v.type;
        return return_val;
    }

    bool operator!=(const Variable &v) const{
        return !(*this == v);
    }

};

// Function Entry for the Symbol Table
class Function{
public:
    std::string name;
    DataType return_type;
    std::vector<Variable> param_list;
    int line_number;
    int col_no;

    Function(std::string name, DataType return_type, std::vector<Variable> param_list = {}, int line_number = 0, int col_no = 0) : name(name), return_type(return_type), param_list(param_list), line_number(line_number), col_no(col_no) {}

};

class Struct{
public:
    std::string name;
    std::vector<Variable> members;
    int line_number;
    int col_no;

    Struct(std::string name, std::vector<Variable> members = {}, int line_number = 0, int col_no = 0) : name(name), members(members), line_number(line_number), col_no(col_no) {}


};

class SymbolTableEntry{
public:
    entry_type type;
    std::string name;
    void *ptr;
    SymbolTableEntry() {}
    SymbolTableEntry(entry_type type, std::string name, void *ptr = NULL) : type(type), name(name), ptr(ptr) {}
};

class SymbolTable
{
public:
    std::unordered_map<std::string, SymbolTableEntry> table;
    SymbolTable *next = nullptr;

public:
    void addEntry(const SymbolTableEntry &entry){
        table[entry.name] = entry;
    }

    // add a variable to the symbol table
    void addVariable(const std::string &name, const Variable *v){
        SymbolTableEntry e(variable, name, (void*) v);
        this->addEntry(e);
    }


    // add a function to the symbol table
    void addFunction(const std::string &name, const Function *f){
        SymbolTableEntry e(function, name, (void *)f);
        this->addEntry(e);
    }

    // add a struct to the symbol table
    void addStruct(const std::string &name, const Struct *s){
        SymbolTableEntry e(_struct, name, (void *)s);
        this->addEntry(e);
    }
    

    SymbolTableEntry *getEntry(const std::string &name){
        auto it = table.find(name);
        if (it != table.end()){
            return &(it->second);
        }
        return nullptr;
    }

    SymbolTableEntry* getEntryNested(const std::string &name){
        SymbolTable *temp = this;
        while (temp != nullptr){
            SymbolTableEntry *e = temp->getEntry(name);
            if (e != nullptr){
                return e;}
            temp = temp->next;
        }
        return nullptr;
    }

    bool checkName(const std::string &name){
        return this->getEntry(name) != nullptr;
    }

    bool checkNameNested(const std::string &name){      //if name is present return true else return false
        SymbolTable *temp = this;
        while (temp != nullptr){
            if (temp->checkName(name))
                return true;
            temp = temp->next;
        }
        return false;
    }

    // check if the name is of the given type
    bool checkName(const std::string &name, const entry_type entry){
        SymbolTableEntry *e = getEntry(name);
        return e != nullptr && e->type == entry;
    }

    // check if the name is of the given type in the nested symbol tables
    bool checkNameNested(const std::string &name, const entry_type entry){
        SymbolTable *temp = this;
        while (temp != nullptr){
            if (temp->checkName(name, entry))
                return true;
            temp = temp->next;
        }
        return false;
    }

    void addTaskGroup(const std::string name);
    

    bool removeEntry(const std::string &name){
        return table.erase(name) > 0;
    }

    void print(){
        std::cout << "Name | Type" << std::endl;
        for (auto it = table.begin(); it != table.end(); it++){
            std::cout  << it->first << " | " << entry_type_strings[it->second.type] << std::endl;
        }
    }
};



class TaskGroup{
public:
    std::string name;
    int line_number;
    int col_no;
    std::unordered_map<std::string, SymbolTable*> task_table;
    std::unordered_map<std::string, SymbolTable*> supervisor_table;
    TaskGroup(std::string name, int line_number = 0, int col_no = 0) : name(name), line_number(line_number), col_no(col_no) {}

    void addTask(const std::string &task_name){
        task_table[task_name] = new SymbolTable();
    }

    SymbolTable *retrieveTask(const std::string &task_name){
        auto it = task_table.find(task_name);
        if (it != task_table.end())
        {
            return it->second;
        }
        return nullptr;
    }

    void addSupervisor(const std::string &supervisor_name){
        supervisor_table[supervisor_name] = new SymbolTable();
    }

    SymbolTable *retrieveSupervisor(const std::string &supervisor_name){
        auto it = supervisor_table.find(supervisor_name);
        if (it != supervisor_table.end())
            return it->second;
            
        return nullptr;
    }

   

};

void SymbolTable::addTaskGroup(const std::string name){
    TaskGroup *t = new TaskGroup(name);
    SymbolTableEntry e(taskgroup, name, (void *)t);
    this->addEntry(e);
}