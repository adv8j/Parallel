#include "headers.hpp"

static std::unique_ptr<llvm::LLVMContext> TheContext;
static std::unique_ptr<llvm::Module> TheModule;
static std::unique_ptr<llvm::IRBuilder<>> Builder;

static void InitializeModule() {
  // Open a new context and module.
  TheContext = std::make_unique<llvm::LLVMContext>();
  TheModule = std::make_unique<llvm::Module>("my cool jit", *TheContext);

  // Create a new builder for the module.
  Builder = std::make_unique<llvm::IRBuilder<>>(*TheContext);
}



llvm::Value *LogErrorV(const char *Str) {
    std::cerr << "Error: " << Str << std::endl;  // Print the error message to standard error
    return nullptr;                              // Return nullptr to indicate failure
}

class ASTNode{
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
		: line_number(0), col_number(0), kind(root_t),name(""), next(NULL)
	{
	}
	ASTNode(kind_t kind, DataType type, std::string name = "", int line_no = 0, int col_no = 0)
		: line_number(line_no), col_number(col_no), kind(kind), name(name), type(type), next(NULL)
	{
	}
	ASTNode(kind_t kind, std::string name = "", int line_no = 0, int col_no = 0)
		: line_number(line_no), col_number(col_no), kind(kind), name(name), next(NULL)
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

	llvm::Value* codegen(std::vector<std::map<std::string, llvm::Value*>>& NamedValues, const std::string& func_name);
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

	os << CYAN_COLOR << kind_t_strings[kind] << " : " << YELLOW_COLOR << node->line_number << ":" << node->col_number << RESET_COLOR << " ";
	switch (kind)
	{
	case variable_t:
		if ((node->type).reference)
			os << ": &" << node->name << " -> ";
		else
			os << ": " << node->name << " -> ";

		os<< dtype_strings[(node->type).type] << " " << node->type.name ;
		for(int i : (node->type).ndims)
			os<<"["<<i<<"]";

		os << "\n";
		break;
	case task_stmt:
	case taskgroup_stmt:
		os << ": " << node->name << std::endl;
		break;

	case decl_stmt:
		os << ": ";
		if ((node->type).reference)
			os << "&";
		os << node->type << std::endl;

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
		os << ": " << node->type<< std::endl;
		break;
	case shared_node:
		os << std::endl;
		break;
	case mem_rule:
		os << ": " << node->type<< std::endl;
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
		os << node->name << " : " << node->type << "\n";
		break;
	case cond_stmt:
		os << ": ";
		os << node->name << "\n";
		break;
	case identifier_chain:
		os << "\n";
		break;
	case array_element:
		os << ": "<< node->name <<" -> "<< node->type  << "\n";
		break;
	case struct_decl:
		os << ": " << node -> name << "\n";
		break;
	case function_call_stmt:
		os << ": " << node->name << " " << node->type<< std::endl;
		break;
	case function_decl_stmt:
		os<<": "<<node->name<< " : " << node->type<<std::endl;
		
		
		break;
	case prototype_stmt:
		os<<": "<<node->name<< " : " << node->type<<std::endl;
		
		break;
	case list_init:
		os << ": " << node->type << std::endl;
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
	case jump_stmt:
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
			os << ": for expressions"  << "\n";
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
	case syntax_error_stmt:
		os << "\n";
		break;
	case member_data_t:
		os << " : "<<node -> name << "\n";
		break;
	default:
		break;
	}
	return os;
}

void traverse(ASTNode *node, int tab = 0)
{
	for (int i = 0; i < tab; i++){
		std::cout <<"\t";
	}

	if ((node == NULL) || (node == nullptr)){
		std::cout <<node<<" , tabs = "<<tab;
		return;
	}
	//kind_t kind = node->kind;
	std::cout <<node;
	for (auto child : node->children){
		traverse(child, tab + 1);
	}

	if (node->next != NULL){
		traverse(node->next, tab);
	}
}



// Global map to store defined struct types
std::map<std::string, llvm::StructType*> DefinedStructs;
std::map<std::string, llvm::Function*> FunctionMap;
std::map<std::string, std::map<std::string, unsigned>> StructMemberIndices;


//returns the llvm::type for one dimension variables //includes basic datatypes and struct
llvm::Type* get_type_dim_0(dtypes type, std::string struct_name = ""){
    if(struct_name == ""){       // Handle basic types
        if (type == int_t)       return llvm::Type::getInt32Ty(*TheContext); // 32-bit integer
        if (type == float_type)  return llvm::Type::getFloatTy(*TheContext); // 32-bit float
        if (type == long_t)      return llvm::Type::getInt64Ty(*TheContext); // 64-bit integer
        if (type == bool_t)      return llvm::Type::getInt1Ty(*TheContext);  // 1-bit boolean
        if (type == char_t)      return llvm::Type::getInt8Ty(*TheContext);  // 8-bit character
        if (type == string_t)    return llvm::Type::getInt8PtrTy(*TheContext); // Pointer to 8-bit integer for strings
    }

    else{       //handle struct types
        auto it = DefinedStructs.find(struct_name);
        return it->second;
    }
	return NULL;
}

// returns the llvm::type for struct member data
llvm::Type* struct_member_decl(ASTNode* node){

    llvm::Type* array_type = get_type_dim_0((node -> type).type, (node -> type).name);

    for(int i = (node -> type).ndims.size() - 1 ; i >= 0 ; i-- ){
        array_type = llvm::ArrayType::get(array_type, (node -> type).ndims[i]);
    }
	return array_type;
}

//code gen for struct declaration
llvm::StructType* struct_decl_codegen(ASTNode* node){
    const std::string& name = node -> name;
    std::vector<llvm::Type*> fieldTypes;
	std::map<std::string, unsigned> memberIndices;
    for(int i = 0; (long unsigned int)i < (node -> children).size() ; i++){
        fieldTypes.push_back(struct_member_decl((node -> children[i])));
		memberIndices[node -> children[i] -> name] = i;
    }
    llvm::StructType* struct_type = llvm::StructType::create(*TheContext, fieldTypes, name);
    DefinedStructs[name] = struct_type;
	StructMemberIndices[name] = memberIndices;
    return struct_type;
}

unsigned getStructMemberIndex(const std::string& structName, const std::string& memberName) {
    auto structIt = StructMemberIndices.find(structName);
    if (structIt == StructMemberIndices.end()) {
        std::cerr << "Error: Struct " << structName << " not found.\n";
        return -1;
    }

    auto& memberMap = structIt->second;
    auto memberIt = memberMap.find(memberName);
    if (memberIt == memberMap.end()) {
        std::cerr << "Error: Member " << memberName << " not found in struct " << structName << ".\n";
        return -1;
    }

    return memberIt->second;
}


//TODO: must identify references also (used for variable declaration and function (return type and parameters))
llvm::Type* var_decl_type_codegen(ASTNode* node){
	llvm::Type* array_type = get_type_dim_0((node -> type).type, (node -> type).name);
	for(int i = (node -> type).ndims.size() - 1 ; i >= 0 ; i-- ){
        array_type = llvm::ArrayType::get(array_type, (node -> type).ndims[i]);
    }
	return array_type;
}

llvm::Value* var_decl_codegen(ASTNode* node, std::vector<std::map<std::string, llvm::Value*>>& NamedValues,const std::string& function_name = "main"){
	if(NamedValues.size() == 0) NamedValues.push_back({});
    llvm::Type* var_type = var_decl_type_codegen(node);

	llvm::Function*  current_function = FunctionMap[function_name];
	
	if (!current_function) {
		std::cerr << "Error: No valid function context available for variable declaration.\n";
		return nullptr;
	}

    for (auto itr : node->children) {

        // Use the Builder's current insertion point
        llvm::AllocaInst* alloca_inst = Builder -> CreateAlloca(var_type, nullptr, itr->name);

        // Store the variable in NamedValues for later use
        NamedValues.back()[itr->name] = alloca_inst;

		if (!itr->children.empty() && itr->children[0]->kind != list_init) {
            llvm::Value* initValue = itr->children[0]->codegen(NamedValues, function_name);

            if (!initValue) {
                std::cerr << "Error: Failed to generate initialization value for " << itr->name << ".\n";
                continue;
            }

            // Store the initialization value into the allocated memory
            if (initValue->getType()->isPointerTy()) {
                initValue = Builder->CreateLoad(initValue->getType()->getPointerElementType(), initValue);
            }
            Builder->CreateStore(initValue, alloca_inst);
        }

    }

    return nullptr;
}

llvm::Value* equality_codegen_element(llvm::Value* L, llvm::Value* R, llvm::Type* type, bool isEquality);
llvm::Value* compareComplexTypes(llvm::Value* L, llvm::Value* R, llvm::Type* type, bool isEquality);
llvm::Value* compareStructs(llvm::Value* L, llvm::Value* R, llvm::StructType* structType, bool isEquality);

llvm::Value* compareArrays(llvm::Value* L, llvm::Value* R, llvm::Type* arrayType, bool isEquality) {
    llvm::Type* elementType = arrayType->getArrayElementType();
    unsigned numElements = arrayType->getArrayNumElements();

    llvm::Value* result = llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext), 1); // Start with true

    for (unsigned i = 0; i < numElements; ++i) {
        llvm::Value* idx = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), i);

        llvm::Value* lhsElement = Builder->CreateExtractValue(L, {i}, "lhsElement");
        llvm::Value* rhsElement = Builder->CreateExtractValue(R, {i}, "rhsElement");

        llvm::Value* elementComparison = nullptr;
        if (elementType->isIntegerTy() || elementType->isFloatingPointTy()) {
            elementComparison = equality_codegen_element(lhsElement, rhsElement, elementType, isEquality);
        } else if (elementType->isArrayTy() || elementType->isStructTy()) {
            elementComparison = compareComplexTypes(lhsElement, rhsElement, elementType, isEquality);
        } else {
            std::cerr << "Error: Unsupported array element type.\n";
            return nullptr;
        }

        if (isEquality) {
            result = Builder->CreateAnd(result, elementComparison, "arrayEq");
        } else {
            result = Builder->CreateOr(result, Builder->CreateNot(elementComparison, "arrayNeq"), "arrayNeq");
        }
    }

    return result;
}

llvm::Value* compareComplexTypes(llvm::Value* L, llvm::Value* R, llvm::Type* type, bool isEquality) {
    if (type->isArrayTy()) {
        return compareArrays(L, R, type, isEquality);
    } else if (type->isStructTy()) {
        return compareStructs(L, R, llvm::cast<llvm::StructType>(type), isEquality);
    }

    std::cerr << "Error: Unsupported complex type for comparison.\n";
    return nullptr;
}

llvm::Value* compareStructs(llvm::Value* L, llvm::Value* R, llvm::StructType* structType, bool isEquality) {
    unsigned numElements = structType->getNumElements();

    llvm::Value* result = llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext), 1); // Start with true

    for (unsigned i = 0; i < numElements; ++i) {
        llvm::Value* lhsMember = Builder->CreateExtractValue(L, {i}, "lhsMember");
        llvm::Value* rhsMember = Builder->CreateExtractValue(R, {i}, "rhsMember");

        llvm::Value* memberComparison = nullptr;
        llvm::Type* memberType = structType->getElementType(i);

        if (memberType->isIntegerTy() || memberType->isFloatingPointTy()) {
            memberComparison = equality_codegen_element(lhsMember, rhsMember, memberType, isEquality);
        } else if (memberType->isArrayTy() || memberType->isStructTy()) {
            memberComparison = compareComplexTypes(lhsMember, rhsMember, memberType, isEquality);
        } else {
            std::cerr << "Error: Unsupported struct member type.\n";
            return nullptr;
        }

        if (isEquality) {
            result = Builder->CreateAnd(result, memberComparison, "structEq");
        } else {
            result = Builder->CreateOr(result, Builder->CreateNot(memberComparison, "structNeq"), "structNeq");
        }
    }

    return result;
}

llvm::Value* equality_codegen_element(llvm::Value* L, llvm::Value* R, llvm::Type* type, bool isEquality) {
    llvm::Value* result = nullptr;
    if (type->isIntegerTy()) {
        result = isEquality ? Builder->CreateICmpEQ(L, R, "eqint") : Builder->CreateICmpNE(L, R, "neqint");
    } else if (type->isFloatingPointTy()) {
        llvm::CmpInst::Predicate predicate = isEquality ? llvm::CmpInst::FCMP_OEQ : llvm::CmpInst::FCMP_ONE;
        result = Builder->CreateFCmp(predicate, L, R, "eqfloat");
    }
    return result;
}


llvm::Value* expr_code_gen(ASTNode* node,std::vector<std::map<std::string, llvm::Value*>>& NamedValues, const std::string& function_name){
	if(node == nullptr)	return nullptr;
	llvm::Value* L = (node -> children)[0] -> codegen(NamedValues, function_name);
	llvm::Value* R = (node -> children)[1] -> codegen(NamedValues, function_name);
	llvm::Value* result = nullptr;
	
	//operators +, -, /, *  (except strings)
	if(((node -> type).type != string_t) && ((node -> name == "+") ||(node -> name == "-")  || (node -> name == "*")  || (node -> name == "/")  || (node -> name == "%") )){
		

		// Handle integer arithmetic
        if ((node->type).type == int_t) {
            if (node->name == "+") {
                result = Builder->CreateAdd(L, R, "addtmp");
            } else if (node->name == "-") {
                result = Builder->CreateSub(L, R, "subtmp");
            } else if (node->name == "*") {
                result = Builder->CreateMul(L, R, "multmp");
            } else if (node->name == "/") {
                result = Builder->CreateSDiv(L, R, "divtmp");  // Signed division
            } else if (node->name == "%") {
                result = Builder->CreateSRem(L, R, "modtmp"); // Signed remainder
            }
        }
        // Handle float arithmetic
        else if ((node->type).type == float_type) {
            if (node->name == "+") {
                result = Builder->CreateFAdd(L, R, "faddtmp");
            } else if (node->name == "-") {
                result = Builder->CreateFSub(L, R, "fsubtmp");
            } else if (node->name == "*") {
                result = Builder->CreateFMul(L, R, "fmultmp");
            } else if (node->name == "/") {
                result = Builder->CreateFDiv(L, R, "fdivtmp");
            }
        }
        // Handle long arithmetic (treated as 64-bit integers)
        else if ((node->type).type == long_t) {
            if (node->name == "+") {
                result = Builder->CreateAdd(L, R, "addtmp");
            } else if (node->name == "-") {
                result = Builder->CreateSub(L, R, "subtmp");
            } else if (node->name == "*") {
                result = Builder->CreateMul(L, R, "multmp");
            } else if (node->name == "/") {
                result = Builder->CreateSDiv(L, R, "divtmp");
            } else if (node->name == "%") {
                result = Builder->CreateSRem(L, R, "modtmp");
            }
        }
		return result;
	}
	//handle + for strings
	if((node -> name) == "+" && (node -> type).type == string_t){
		dtypes left_type = node -> children[0] -> type.type;
		dtypes right_type = node -> children[1] -> type.type;

		llvm::Function* stringConcatFunc = TheModule -> getFunction("cancat_strings");
		llvm::Function* stringCharConcatFunc = TheModule -> getFunction("concat_string_char");
		llvm::Function* stringIntConcatFunc = TheModule -> getFunction("concat_string_int");

		if(left_type == string_t && right_type== string_t){
			result = Builder->CreateCall(stringConcatFunc, {L,R}, "str_concat");
		}
		else if (left_type == string_t && right_type == char_t) {
			// string + char
			result = Builder->CreateCall(stringCharConcatFunc, {L, R}, "str_char_concat");
		} else if (left_type == char_t && right_type == string_t) {
			// char + string
			result = Builder->CreateCall(stringCharConcatFunc, {R, L}, "char_str_concat");
		} else if (left_type == string_t && right_type == int_t) {
			// string + int
			result = Builder->CreateCall(stringIntConcatFunc, {L, R}, "str_int_concat");
		}
		return result;
	}

	//Handle comparison operators >, <, <=, >=
	if(node -> name == ">" || node -> name == ">=" || node -> name == "<" || node -> name == "<="){
		dtypes left_type = node -> children[0] -> type.type;
		if (left_type == int_t || left_type == bool_t || left_type == long_t) {
				// Integer, Boolean, or Long comparisons (treated as integers)
				llvm::CmpInst::Predicate predicate;

				if (node->name == "<")
					predicate = llvm::CmpInst::ICMP_SLT;
				else if (node->name == ">")
					predicate = llvm::CmpInst::ICMP_SGT;
				else if (node->name == "<=")
					predicate = llvm::CmpInst::ICMP_SLE;
				else if (node->name == ">=")
					predicate = llvm::CmpInst::ICMP_SGE;
				else {
					std::cerr << "Error: Unsupported comparison operator.\n";
					return nullptr;
				}

				result = Builder->CreateICmp(predicate, L, R, "cmpint");
				return result;

			} else if (left_type == float_type) {
				// Float comparisons
				llvm::CmpInst::Predicate predicate;

				if (node->name == "<")
					predicate = llvm::CmpInst::FCMP_OLT;
				else if (node->name == ">")
					predicate = llvm::CmpInst::FCMP_OGT;
				else if (node->name == "<=")
					predicate = llvm::CmpInst::FCMP_OLE;
				else if (node->name == ">=")
					predicate = llvm::CmpInst::FCMP_OGE;
				else {
					std::cerr << "Error: Unsupported comparison operator.\n";
					return nullptr;
				}

				result = Builder->CreateFCmp(predicate, L, R, "cmpfloat");
				return result;
			}
		}

		//Handle && and ||
		if(node -> name == "&&" || node -> name == "||"){
			dtypes left_type = node -> children[0] -> type.type;
			dtypes right_type = node -> children[1] -> type.type;
			llvm::Value* left_converted_to_bool = nullptr;
			llvm::Value* right_converted_to_bool = nullptr;

			if(left_type == bool_t){
				left_converted_to_bool = L;
			}
			else if(left_type == int_t || left_type == long_t){
				left_converted_to_bool = Builder -> CreateICmpNE(L, llvm::ConstantInt::get(L -> getType(), 0), "convToBool");
			}
			else if(left_type == float_type){
				left_converted_to_bool = Builder -> CreateFCmpUNE(L, llvm::ConstantFP::get(L->getType(), 0.0), "convToBool");
			}
			
			if (right_type == bool_t) {
				right_converted_to_bool = R; // Already i1
			} else if (right_type == int_t || right_type == long_t) {
				right_converted_to_bool = Builder->CreateICmpNE(R, llvm::ConstantInt::get(R->getType(), 0), "convToBool");
			} else if (right_type == float_type) {
				right_converted_to_bool = Builder->CreateFCmpUNE(R, llvm::ConstantFP::get(R->getType(), 0.0), "convToBool");
			} 

			llvm::Value* result = nullptr;
			if (node->name == "&&") {
				result = Builder->CreateAnd(left_converted_to_bool, right_converted_to_bool, "logicalAnd");
			} else if (node->name == "||") {
				result = Builder->CreateOr(left_converted_to_bool, right_converted_to_bool, "logicalOr");
			} else {
				std::cerr << "Error: Unsupported logical operator.\n";
				return nullptr;
			}
		}

		if (node->name == "=") {
			// Ensure L is a pointer
			llvm::Type* lhsType = L->getType();
			// if (!lhsType->isPointerTy()) {
			// 	std::cerr << "Error: Left-hand side of assignment must be a pointer.\n";
			// 	return nullptr;
			// }

			// Ensure R matches the expected type
			llvm::Type* rhsType = R->getType();
			// if (lhsType->getPointerElementType() != rhsType) {
			// 	std::cerr << "Error: Type mismatch in assignment.\n";
			// 	return nullptr;
			// }

			// Perform the store
			result = Builder->CreateStore(R, L);
			return result;
		}


		if (node->name == "+=" || node->name == "-=" || node->name == "*=" || node->name == "/=" || node->name == "%=") {
			// Ensure L is a pointer and load its current value
			// std::cout <<"step 1\n";
			// L -> getType();
			// std::cout <<"step 2\n";
			// llvm::Value* LValue = Builder->CreateLoad(L->getType()->getPointerElementType(), L, "loadtmp");
			
			// llvm::Type* lhsType = L->getType()->getPointerElementType();
			// std::cout <<"step 3\n";
			// llvm::Type* rhsType = R->getType();
			// // Check for type compatibility
			// if (lhsType != rhsType) {
			// 	std::cerr << "Error: Type mismatch in compound assignment.\n";
			// 	return nullptr;
			// }

			// Perform the arithmetic operation
			if (node->name == "+=") {
				result = Builder->CreateAdd(L, R, "addtmp");
			} else if (node->name == "-=") {
				result = Builder->CreateSub(L, R, "subtmp");
			} else if (node->name == "*=") {
				result = Builder->CreateMul(L, R, "multmp");
			} else if (node->name == "/=") {
				//if (lhsType->isFloatingPointTy()) {
					result = Builder->CreateFDiv(L, R, "fdivtmp");
				//} else {
				//	result = Builder->CreateSDiv(L, R, "divtmp");
				//}
			} else if (node->name == "%=") {
				//if (lhsType->isIntegerTy()) {
					result = Builder->CreateSRem(L, R, "modtmp");
				//} else {
				//	std::cerr << "Error: Modulus operator is not supported for floating-point types.\n";
				//	return nullptr;
				//}
			}
			// Store the result back to L
			result = Builder->CreateStore(result, L);
			return result;
		}


		if(node -> name == "==" || node -> name == "!="){
			llvm::Type* lhsType = L->getType();
    		llvm::Type* rhsType = R->getType();
			if (lhsType->isIntegerTy()) {
				if (node->name == "==") {
					result = Builder->CreateICmpEQ(L, R, "eqint");
				} else if (node->name == "!=") {
					result = Builder->CreateICmpNE(L, R, "neqint");
				}
			} else if (lhsType->isFloatingPointTy()) {
				llvm::CmpInst::Predicate predicate = (node->name == "==") ? llvm::CmpInst::FCMP_OEQ : llvm::CmpInst::FCMP_ONE;
				result = Builder->CreateFCmp(predicate, L, R, "eqfloat");
			} else if (lhsType->isPointerTy() && lhsType->getPointerElementType()->isIntegerTy(8)) {
				// Handle strings (pointers to i8)
				llvm::Function* strcmpFunc = TheModule->getFunction("strcmp");
				if (!strcmpFunc) {
					std::cerr << "Error: strcmp function not found.\n";
					return nullptr;
				}
				llvm::Value* strcmpCall = Builder->CreateCall(strcmpFunc, {L, R}, "strcmpCall");
				if (node->name == "==") {
					result = Builder->CreateICmpEQ(strcmpCall, llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), 0), "eqstr");
				} else if (node->name == "!=") {
					result = Builder->CreateICmpNE(strcmpCall, llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), 0), "neqstr");
				}
			} else if (lhsType->isPointerTy()) {
				// Handle arrays and structs
				result = compareComplexTypes(L, R, lhsType, node->name == "==");
			} else {
				std::cerr << "Error: Unsupported type for equality/inequality comparison.\n";
				return nullptr;
			}

			return result;
		}
		return nullptr;

}

// TODO: array literals are left
llvm::Value* literal_codegen(ASTNode* node) {
    dtypes type = node->type.type;
    const std::string& value = node->name; // Assuming the literal value is stored in `node->name`.

    llvm::Value* result = nullptr;

    switch (type) {
        case int_t: {
            // Integer literal
            int intValue = std::stoi(value);
            result = llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), intValue);
            break;
        }
        case float_type: {
            // Float literal
            float floatValue = std::stof(value);
            result = llvm::ConstantFP::get(llvm::Type::getFloatTy(*TheContext), floatValue);
            break;
        }
        case long_t: {
            // Long literal
            long longValue = std::stol(value);
            result = llvm::ConstantInt::get(llvm::Type::getInt64Ty(*TheContext), longValue);
            break;
        }
        case string_t: {
            // String literal
            result = Builder->CreateGlobalStringPtr(value, "strtmp");
            break;
        }
        case bool_t: {
            // Boolean literal
            bool boolValue = (value == "true");
            result = llvm::ConstantInt::get(llvm::Type::getInt1Ty(*TheContext), boolValue);
            break;
        }
        case char_t: {
            // Character literal
            char charValue = value[0]; // Assuming the value is a single character.
            result = llvm::ConstantInt::get(llvm::Type::getInt8Ty(*TheContext), charValue);
            break;
        }
        default:
            std::cerr << "Error: Unsupported literal type.\n";
            return nullptr;
    }

    return result;
}


llvm::Function* function_prototype_codegen(ASTNode* node){
	std::string function_name = node -> name;
	llvm::Type* return_type = var_decl_type_codegen(node);
	std::vector<llvm::Type*> parameter_type;
	for(int i = 0; (unsigned long int)i < (node -> children[0]) -> children.size(); i++){
		parameter_type.push_back((var_decl_type_codegen(((node -> children[0]) -> children)[i])));
	}
	llvm::FunctionType* func_type = llvm::FunctionType::get(return_type, parameter_type, false);
	
	llvm::Function* function = llvm::Function::Create(func_type, llvm::Function::ExternalLinkage, node -> name, *(TheModule));
	//Assign names to parameters
	size_t indx = 0;
	for(auto& arg: function-> args()){
		arg.setName((node -> children[0] -> children[indx++]) -> name);
	}
	FunctionMap[node -> name] = function;
	return function;
}


llvm::BasicBlock* compound_stmt_codegen(ASTNode* node, std::vector<std::map<std::string, llvm::Value*>>& NamedValues, const std::string& function_name = "main") {
    llvm::Function* parent_function = FunctionMap[function_name];
    if (!parent_function) {
        std::cerr << "Error: Parent function is null.\n";
        return nullptr;
    }

    // Create a new basic block for the compound statement
    llvm::BasicBlock* compoundBlock = llvm::BasicBlock::Create(*TheContext, "compound", parent_function);

    // If there is a valid insertion block, branch to the new compound block
    llvm::BasicBlock* currentBlock = Builder->GetInsertBlock();
    if (currentBlock && !currentBlock->getTerminator()) {
        Builder->SetInsertPoint(currentBlock);
        Builder->CreateBr(compoundBlock);
    }

    // Set the builder's insertion point to the compound block
    Builder->SetInsertPoint(compoundBlock);

    // Push a new scope for the compound statement
    NamedValues.push_back({});

    ASTNode* curr_stmt = node->children[0];
    while (curr_stmt) {
        if (curr_stmt->kind == compound_stmt) {
            // Generate nested compound statements
            llvm::BasicBlock* nestedCompound = compound_stmt_codegen(curr_stmt, NamedValues, function_name);
        } else {
            // Generate code for individual statements
            curr_stmt->codegen(NamedValues, function_name);
        }
        curr_stmt = curr_stmt->next;
    }

    // Pop the scope after processing the compound statement
    NamedValues.pop_back();

    llvm::BasicBlock* post_compound = llvm::BasicBlock::Create(*TheContext, "compound", parent_function);
	Builder -> CreateBr(post_compound);
	Builder -> SetInsertPoint(post_compound);
	

    return compoundBlock;
}





void function_body_codegen(ASTNode* node, std::vector<std::map<std::string, llvm::Value*>>& NamedValues, const std::string& function_name = "main") {
    llvm::Function* parent_function = FunctionMap[function_name];
    if (!parent_function) {
        std::cerr << "Error: Parent function is null.\n";
    }

    // Push a new scope for the compound statement
    NamedValues.push_back({});

    ASTNode* curr_stmt = node->children[0];
    while (curr_stmt) {
        curr_stmt->codegen(NamedValues, function_name);
        curr_stmt = curr_stmt->next;
    }

    // Pop the scope after processing the compound statement
    NamedValues.pop_back();
}


llvm::Function* function_declaration_codegen(ASTNode* node){
	llvm::Function* function;
	if(FunctionMap.find(node -> name) == FunctionMap.end()){
		function = function_prototype_codegen(node);
	}
	else{
		function = FunctionMap[node -> name];
	}
	if (!function) {
        std::cerr << "Error: Could not create function prototype.\n";
        return nullptr;
    }
	// Save the current builder insertion point
    llvm::IRBuilder<>::InsertPoint savedInsertionPoint = Builder->saveIP();
	// Create the entry basic block
    llvm::BasicBlock* entry = llvm::BasicBlock::Create(*TheContext, "entry", function);
    Builder->SetInsertPoint(entry);

    std::vector<std::map<std::string, llvm::Value*>> NamedValues;

    // Generate code for the function's compound statement
    function_body_codegen(node->children[1], NamedValues, node->name);

	// Restore the saved insertion point
    Builder->restoreIP(savedInsertionPoint);
    return function;

}

void addMainFunction(ASTNode* node, std::vector<std::map<std::string, llvm::Value*>>& NamedValues) {
    // Define the function type for `void main()`
    llvm::FunctionType* funcType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(*TheContext), // Return type: void
        false                          // No parameters
    );

    // Create the function and add it to the module
    llvm::Function* mainFunction = llvm::Function::Create(
        funcType,
        llvm::Function::ExternalLinkage, // Linkage type
        "main",                          // Function name
        *TheModule                           // Module to add the function to
    );
	FunctionMap["main"] = mainFunction;
    // Create the entry block for the function
    llvm::BasicBlock* entry = llvm::BasicBlock::Create(*TheContext, "entry", mainFunction);

    // Set the builder's insertion point to the entry block
    Builder->SetInsertPoint(entry);
	
	ASTNode* curr_stmt = node -> next;
	while(curr_stmt){
		curr_stmt -> codegen(NamedValues, "main");
		curr_stmt = curr_stmt -> next;
	}

	// Check if the entry block already has a terminator
    if (!entry->getTerminator()) {
        // If not, add a return void instruction at the end of the function
        Builder->CreateRetVoid();
    }
}

// llvm::Value* function_call_codegen(ASTNode* node, const std::string& function_name = "main",std::vector<std::map<std::string, llvm::Value*>> NamedValues = MainNamedValues ){
// 	std::string called_func_name = node -> name;
// 	llvm::Function* called_func = FunctionMap[called_func_name];

// 	std::vector<llvm::Value*> args;
// 	for(auto& argNode: node -> children)
// }

llvm::BasicBlock* selective_body_codegen(ASTNode* node, std::vector<std::map<std::string, llvm::Value*>>& NamedValues, const std::string& function_name = "main") {
    llvm::Function* parent_function = FunctionMap[function_name];
    if (!parent_function) {
        std::cerr << "Error: Parent function is null.\n";
        return nullptr;
    }

    // Push a new scope for the compound statement
    NamedValues.push_back({});

    ASTNode* curr_stmt = node->children[0];
    while (curr_stmt) {
        if (curr_stmt->kind == compound_stmt) {
            // Generate nested compound statements
            llvm::BasicBlock* nestedCompound = compound_stmt_codegen(curr_stmt, NamedValues, function_name);
        } else {
            // Generate code for individual statements
            curr_stmt->codegen(NamedValues, function_name);
        }
        curr_stmt = curr_stmt->next;
    }

    // Pop the scope after processing the compound statement
    NamedValues.pop_back();

	

}

llvm::Value* selective_stmt_codegen(ASTNode* node, std::vector<std::map<std::string, llvm::Value*>>& NamedValues, const std::string& function_name = "main"){
	
	llvm::Function* parent_function = FunctionMap[function_name];

	ASTNode* selection_node = node;
	ASTNode* if_node = node -> children[0];
	ASTNode* else_node;
	if(node ->children.size() > 1)	else_node = node -> children[1];
	llvm::Value* condition = if_node -> children[0]-> codegen(NamedValues, function_name);

	// Convert the condition to a boolean (if necessary)
    if (condition->getType()->isFloatingPointTy()) {
        condition = Builder->CreateFCmpONE(condition, llvm::ConstantFP::get(condition->getType(), 0.0), "ifcond");
    } else if (condition->getType()->isIntegerTy()) {
        condition = Builder->CreateICmpNE(condition, llvm::ConstantInt::get(condition->getType(), 0), "ifcond");
    }
	llvm::BasicBlock* ifBlock = llvm::BasicBlock::Create(*TheContext, "if", parent_function);
	llvm::BasicBlock* elseBlock = llvm::BasicBlock::Create(*TheContext, "else", parent_function);

	Builder -> CreateCondBr(condition, ifBlock, elseBlock);
	llvm::BasicBlock* endBlock = llvm::BasicBlock::Create(*TheContext, "end if", parent_function);
	Builder -> SetInsertPoint(ifBlock);
	selective_body_codegen(if_node -> children[1], NamedValues, function_name);
	Builder->CreateBr(endBlock);
	Builder -> SetInsertPoint(elseBlock);
	if(else_node){
		selective_body_codegen(else_node -> children[0], NamedValues, function_name);
		Builder-> CreateBr(endBlock);
	}
	
	
	Builder->SetInsertPoint(endBlock);
	return nullptr;
}

//TODO: this is only for `for loop`
llvm::Value* iterative_stmt_codegen(ASTNode* node, std::vector<std::map<std::string, llvm::Value*>>& NamedValues, const std::string& function_name = "main") {
    llvm::Function* parent_function = FunctionMap[function_name];
    if (!parent_function) {
        std::cerr << "Error: Parent function is null.\n";
        return nullptr;
    }
	

    // Create blocks for the loop
    llvm::BasicBlock* initBlock = llvm::BasicBlock::Create(*TheContext, "for.init", parent_function);
    llvm::BasicBlock* condBlock = llvm::BasicBlock::Create(*TheContext, "for.cond", parent_function);
    llvm::BasicBlock* bodyBlock = llvm::BasicBlock::Create(*TheContext, "for.body", parent_function);
    llvm::BasicBlock* stepBlock = llvm::BasicBlock::Create(*TheContext, "for.step", parent_function);
    llvm::BasicBlock* endBlock = llvm::BasicBlock::Create(*TheContext, "for.end", parent_function);
    // Emit the initialization statement
    Builder->CreateBr(initBlock);
    Builder->SetInsertPoint(initBlock);
    node->children[0] -> children[0]->codegen(NamedValues, function_name); // Initialization statement
    Builder->CreateBr(condBlock);

    // Emit the condition check
    Builder->SetInsertPoint(condBlock);
    llvm::Value* condition = node->children[0] -> children[1]->codegen(NamedValues, function_name); // Condition
    if (condition->getType()->isFloatingPointTy()) {
        condition = Builder->CreateFCmpONE(condition, llvm::ConstantFP::get(condition->getType(), 0.0), "forcond");
    } else if (condition->getType()->isIntegerTy()) {
        condition = Builder->CreateICmpNE(condition, llvm::ConstantInt::get(condition->getType(), 0), "forcond");
    }
    Builder->CreateCondBr(condition, bodyBlock, endBlock);

    // Emit the body of the loop
    Builder->SetInsertPoint(bodyBlock);
    node->children[1]->codegen(NamedValues, function_name); // Loop body
    Builder->CreateBr(stepBlock);

    // Emit the increment (step)
    Builder->SetInsertPoint(stepBlock);
    node->children[0] -> children[2]->codegen(NamedValues, function_name); // Step
    Builder->CreateBr(condBlock);

    // Emit the end of the loop
    Builder->SetInsertPoint(endBlock);

    return nullptr;
}


llvm::Value* accessArrayElement(ASTNode* node, std::vector<std::map<std::string, llvm::Value*>>& NamedValues, const std::string& function_name = "main") {
    // Get the base pointer of the array
    llvm::Value* basePtr = NamedValues.back()[node->name];

    if (!basePtr) {
        std::cerr << "Error: Array " << node->name << " not found in current scope.\n";
        return nullptr;
    }

    llvm::Value* currentPtr = basePtr;
    llvm::Type* elementType = basePtr->getType()->getPointerElementType();

    for (ASTNode* indexNode : node->children) {
        // Generate code for each index
        llvm::Value* index = indexNode->codegen(NamedValues, function_name);
        if (!index) {
            std::cerr << "Error: Failed to generate index for array.\n";
            return nullptr;
        }

        // Update the pointer using GEP
        currentPtr = Builder->CreateGEP(elementType, currentPtr, {llvm::ConstantInt::get(llvm::Type::getInt32Ty(*TheContext), 0), index}, "arrayindex");
        elementType = elementType->getArrayElementType(); // Move to the next dimension
    }

    // Load the final value
    return Builder->CreateLoad(elementType, currentPtr, "arrayelement");
}

void print_symbol_table(std::vector<std::map<std::string, llvm::Value*>>& NamedValues){
	for(int i = 0; (unsigned long int)i < NamedValues.size() ; i++){
		for(const auto& item: NamedValues[i]){
			std::cout << item.first<<"\n";
		}
	}
	std::cout <<"-------------------------------------------------------";
}


llvm::Value* accessVariable(ASTNode* node, std::vector<std::map<std::string, llvm::Value*>>& NamedValues, const std::string& function_name = "main") {
    // Lookup variable in the NamedValues map
	llvm::Value* varPtr = nullptr;
	for(int i = NamedValues.size() - 1; i>= 0; i--){
		if(NamedValues[i].find(node -> name) == NamedValues[i].end())	continue;
		varPtr = NamedValues[i][node -> name];
	}
    if (!varPtr) {
        std::cerr << "Error: Variable " << node->name << " not found in current scope.\n";
        return nullptr;
    }
    // Load the variable value
    return Builder->CreateLoad(varPtr->getType()->getPointerElementType(), varPtr, node->name);
}


llvm::Value* accessStructMember(ASTNode* node, std::vector<std::map<std::string, llvm::Value*>>& NamedValues, const std::string& function_name) {
    // Access the base variable or struct
    llvm::Value* basePtr = node->children[0]->codegen(NamedValues, function_name);
    if (!basePtr) {
        std::cerr << "Error: Base pointer for struct access is null.\n";
        return nullptr;
    }

    llvm::StructType* structType = llvm::dyn_cast<llvm::StructType>(basePtr->getType()->getPointerElementType());
    if (!structType) {
        std::cerr << "Error: Expected struct type for member access.\n";
        return nullptr;
    }

    // Find the member index from the member name
    std::string memberName = node->children[1]->name;
    unsigned memberIndex = getStructMemberIndex(node -> type.name, memberName);
    if (memberIndex >= structType->getNumElements()) {
        std::cerr << "Error: Invalid struct member " << memberName << ".\n";
        return nullptr;
    }

    // Generate GEP for the member
    llvm::Value* memberPtr = Builder->CreateStructGEP(structType, basePtr, memberIndex, memberName);

    // Load the value of the member
    return Builder->CreateLoad(memberPtr->getType()->getPointerElementType(), memberPtr, memberName);
}

llvm::Value*function_call_codegen(ASTNode* node, std::vector<std::map<std::string, llvm::Value*>>& NamedValues, const std::string& function_name = "main"){
	std::string called_func_name = node -> name;
	llvm::Function* called_func = TheModule -> getFunction(called_func_name);
	std::vector<llvm::Value*>args;
	for(ASTNode* arg_node: node -> children[0] -> children){
		llvm::Value* arg = arg_node-> codegen(NamedValues, function_name);
		args.push_back(arg);
	}
	return Builder -> CreateCall(called_func ,args, "calltmp");
	
}

llvm::Value* ASTNode::codegen(std::vector<std::map<std::string, llvm::Value*>>& NamedValues, const std::string& function_name = "main") {
    switch(this -> kind){
        case struct_decl:
            struct_decl_codegen(this);
            break;

		case decl_stmt:
			return var_decl_codegen(this, NamedValues, function_name);
		
		case expr_stmt:
			return expr_code_gen(this, NamedValues, function_name);

		case literal:
			return literal_codegen(this);
		case prototype_stmt:
			function_prototype_codegen(this);
			break;
		case function_decl_stmt:
			function_declaration_codegen(this);
			break;
		case compound_stmt:
			compound_stmt_codegen(this,NamedValues,  function_name);
			break;
		// case function_call_stmt:
		// 	function_call_codegen(this, NamedValues, function_name);
		// 	break;
		case selection_stmt:
			selective_stmt_codegen(this, NamedValues, function_name);
			break;
		case variable_t:
            if (this->children.empty()) {
                // Simple variable
                return accessVariable(this, NamedValues, function_name);
            } else {
                // Array element
                return accessArrayElement(this, NamedValues, function_name);
            }
        case array_element:
            // Delegate to array element access
            return accessArrayElement(this, NamedValues, function_name);
        case identifier_chain:
            // Handle struct member access (dot access)
            return accessStructMember(this, NamedValues, function_name);
		case iterative_stmt:
			iterative_stmt_codegen(this, NamedValues, function_name);
			break;
		case function_call_stmt:	
			function_call_codegen(this, NamedValues, function_name);
			break;
		
		
        default:
            break;
    }

    return nullptr;
}
