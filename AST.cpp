#include "headers.hpp"



class ASTNode
{
public:
	int line_number;
	int col_number;
	kind_t kind;
	std::string name;
	DataType type;
	std::vector<ASTNode *> children;
	ASTNode *next;
	std::vector<std::string> metadata;
	ASTNode()
		: kind(root_t), line_number(0), col_number(0), next(NULL)
	{
	}
	ASTNode(kind_t kind, DataType type, std::string name = "", int line_no = 0, int col_no = 0)
		: kind(kind), line_number(line_no), name(name), col_number(col_no), type(type), next(NULL)
	{
		// std::cout << "Creating node of type " << kind_t_strings[kind] << std::endl;
	}
	ASTNode(kind_t kind, std::string name = "", int line_no = 0, int col_no = 0)
		: kind(kind), line_number(line_no), col_number(col_no), name(name), next(NULL)
	{
	}
	ASTNode(int line_no, int col_no, kind_t kind, std::string name, DataType type)
		: line_number(line_no), col_number(col_no), kind(kind), name(name), type(DataType(type)), next(NULL)
	{
	}

	void sem_test(SymbolTable* current);
	void add_child(ASTNode *child)
	{
		if (child==nullptr)
		{
			return;
		}
		children.push_back(child);
	}

	void add_to_metadata(ASTNode *node)
	{
		ASTNode *tail = node;

		while (tail != NULL)
		{
			this->metadata.push_back(tail->name);
			ASTNode *temp = tail;
			tail = tail->next;
			delete temp;
		}
	}

	ASTNode *reach_end()
	{
		ASTNode *temp = this;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		return temp;
	}

	void traverse_next()
	{
		ASTNode *temp = this;
		while (temp != NULL)
		{
			std::cout << temp;
			temp = temp->next;
		}
	}

	void convert_to_children(ASTNode *head)
	{
		ASTNode *temp = head;
		while (temp != NULL)
		{
			children.push_back(temp);
			ASTNode *x = temp;
			temp = temp->next;
			x->next = NULL;
		}
	}
	// Returns true if the node has children
	bool childExists(){
		return this->children.size() != 0;
	}

	dtypes getType(){
		return this->type.type;
	}
};

// Output colored text
std::ostream &operator<<(std::ostream &os, const ASTNode *node)
{
	if (node == NULL || node == nullptr)
	{
		os << "NULL" << std::endl;
		return os;
	}
	kind_t kind = node->kind;

	os << CYAN_COLOR << kind_t_strings[kind] << RESET_COLOR;
	switch (kind)
	{
	case variable_t:
		if ((node->type).reference)
			os << ": &" << node->name << " -> ";
		else
			os << ": " << node->name << " -> ";

		os<< dtype_strings[(node->type).type] << "\n";
		break;
	case task_stmt:
	case taskgroup_stmt:
		os << ": " << node->name << std::endl;
		break;

	case decl_stmt:
		os << ": ";
		if ((node->type).reference)
			os << "&";
		os << dtype_strings[node->type.type] << "\t";
		for (int i : (node->type).ndims)
			std::cout << i << " ";
		if ((node->type).init_exp_or_id)
			std::cout << ((node->type).init_exp_or_id) << "\t";
		std::cout << "\n";
		break;
	case channel_stmt:
		os << ": " << node->name << std::endl;
		break;
	case keyword:
		os << ": " << node->name << std::endl;
		break;
	case parallel_stmt:
		os << ": " << node->name << std::endl;
		break;
	case reduction_operator:
		os << ": " << node->name << std::endl;
		break;
	case root_t:
	case order_rule:
	case order_node:
		os << std::endl;
		break;
	case properties_stmt:
		os << ": " << node->name;
		if (node->metadata.size() > 0)
		{
			os << "-> ";
			for (auto data : node->metadata)
			{
				os << data << " ";
			}
		}
		os << std::endl;

		break;

	case task_t:
		os << ": ";
		os << node->name;
		for (auto data : node->metadata)
		{
			os << "-> " << data;
		}
		os << std::endl;
		break;

	case shared_rule:
		os << ": " << dtype_strings[node->type.type] << std::endl;
		break;
	case shared_node:
		os << std::endl;
		break;
	case mem_rule:
		os << ": " << dtype_strings[node->type.type] << std::endl;
		break;

	case mem_node:
		os << std::endl;
		break;
	case literal:
		os << ": ";
		os << node->name << " ";
		os << "\n";
		break;
	case expr_stmt:
		os << ": ";
		os << node->name << " : " << dtype_strings[node->type.type] << "\n";
		break;
	case cond_stmt:
		os << ": ";
		os << node->name << "\n";
		break;
	case array_element:
		os << ": \n";
		break;
	case struct_decl:
		os << ":\n";
		break;
	case function_call_stmt:
		os << ": " << node->name << std::endl;
		break;
	case function_decl_stmt:
		os<<": "<<node->name<< " : " << dtype_strings[node->type.type]<<std::endl;
		
		
		break;
	case prototype_stmt:
		os<<": "<<node->name<< " : " << dtype_strings[node->type.type]<<std::endl;
		
		break;
	case list_init:
		os << ": \n";
		break;

	case join_stmt:
		os << ": " << node->name << std::endl;
		break;
	case call_stmt:
		os << ": " << node->name << std::endl;
		break;
	case supervisor_stmt:
		os << ": " << node->name << std::endl;
		break;
	case return_stmt:
		os << ": " << node->name << std::endl;
		break;
	case compound_stmt:
		os << ":\n";
		break;
	case empty_expr_stmt:
		os << ":\n";
		break;
	case itr_type:
	{
		if(node->name=="type1")
			os << ": for"  << "\n";
		else
			os << ": for range" << "\n";
		break;
	}
	case iterative_stmt:
		os << ":\n";
		break;
	case selection_stmt:
		os << ":\n";
		break;
	case if_stmt:
		os << ":\n";
		break;
	case else_stmt:
		os << ":\n";
		break;
	case elseif_stmt:
		os << ":\n";
		break;
	case params_list:

		os << ":\n";
		break;
	case params_t:
		os<<": "<<node->name<< " : " << dtype_strings[node->type.type]<<((node->type.reference)?"&":"")<<std::endl;
		break;
	case arg_list:
		os << ":\n";
		break;
	case err_t:
		os << "\n";
		break;
	}
	return os;
}

void traverse(ASTNode *node, int tab = 0)
{
	for (int i = 0; i < tab; i++){
		std::cout << "\t";
	}

	if ((node == NULL) || (node == nullptr)){
		std::cout << node << " , tabs = " << tab;
		return;
	}
	kind_t kind = node->kind;
	std::cout << node;
	for (auto child : node->children){
		traverse(child, tab + 1);
	}

	if (node->next != NULL){
		traverse(node->next, tab);
	}
}
