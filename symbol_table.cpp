#include "headers.hpp"
class Variable
{
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
    Variable(std::string name, dtypes type, std::vector<int> dims = {}, bool reference = false, bool has_value = false, std::string struct_name = "", int line_number = 0, int col_no = 0) : name(name), type(type), dims(dims), reference(reference), has_value(has_value), line_number(line_number), col_no(col_no), struct_name(struct_name) {}

    bool similar_dtype(dtypes func_para, dtypes func_arg) const
    {
        if(func_para==func_arg)
            return true;
        else if(func_para==float_t && func_arg==int_t)
            return true;
        else if(func_para==long_t && func_arg==int_t)
            return true;
        else if(func_para==float_t && func_arg==long_t)
            return true;
        else {
            return false;
        }
        
    }

    // overload != operator
    bool operator!=(const Variable &v) const
    {
        bool return_val = this->name != v.name || this->type != v.type || this->reference != v.reference || this->struct_name != v.struct_name;
        return return_val;
    }
    bool typecheck(DataType parameter) const
    {
        
        return similar_dtype(this->type,parameter.type)&&this->reference == parameter.reference;
    }
};

class Function
{
public:
    std::string name;
    bool is_prototype = false;
    dtypes return_type;
    std::string return_struct_name;
    std::vector<Variable> param_list;
    int line_number;
    int col_no;

    Function(std::string name, dtypes return_type,bool is_prototype, std::vector<Variable> param_list = {},std::string return_struct_name = "", int line_number = 0, int col_no = 0 ) : name(name),is_prototype(is_prototype), return_type(return_type), param_list(param_list), line_number(line_number), col_no(col_no), return_struct_name(return_struct_name) {}
};

class Struct
{
public:
    std::string name;
    std::vector<Variable> member_data;
    int line_number;
    int col_no;
    Struct(std::string name, std::vector<Variable> member_data = {}, int line_number = 0, int col_no = 0) : name(name), member_data(member_data), line_number(line_number), col_no(col_no) {}
    //searches for a member data in the struct and returns its struct (copy)
    Variable get_member(std::string name){
        for(const auto& member: member_data){
            if(member.name == name){
                return member;
            }
        }
    }
};

class SymbolTableEntry
{
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

    void addVariable(const std::string &name, const dtypes type, bool has_value = false, bool reference = false,
                std::vector<int> dims = {}, std::string struct_name = "", int line_no = 0, int col_no = 0)
    {
        Variable *v = new Variable(name, type, dims, reference, has_value, struct_name, line_no, col_no);
        SymbolTableEntry e(variable, name, (void *)v);
        this->addEntry(e);
        std:: cout << "Added variable " << name << " of type " << dtype_strings[type] << std::endl;
    }
    void addFunction(const std::string &name, const dtypes return_type,bool is_prototype,std::vector<Variable> param_list = {},std::string return_struct_name = "",  int line_no = 0, int col_no = 0 )
    {
        Function *f = new Function(name, return_type,is_prototype, param_list,return_struct_name, line_no, col_no );
        SymbolTableEntry e(function, name, (void *)f);
        this->addEntry(e);
    }

    void addStruct(std::string name, std::vector<Variable> members = {}, int line_no = 0, int col_no = 0){
        Struct* new_struct = new Struct(name, members, line_no, col_no);
        SymbolTableEntry e(_struct, name, (void*)new_struct);
        this -> addEntry(e);
        std::cout <<"Added new struct" << name << "with" << members.size() << "members\n";
    }
    

    SymbolTableEntry *getEntry(const std::string &name){
        auto it = table.find(name);
        if (it != table.end())
        {
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



class TaskGroup
{
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