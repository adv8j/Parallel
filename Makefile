# Compiler and LLVM configuration
CXX = g++
CXXFLAGS = -g -Wall
LLVM_FLAGS = `llvm-config --cxxflags --ldflags --system-libs --libs core support passes`

TARGET = parser.out

# Capture options passed to make
ast := false
debug := false
codegen := true

# Capture all flags passed to make (like --ast, --debug, --codegen)
FLAGS := $(if $(filter true,$(ast)),--ast) $(if $(filter true,$(debug)),--debug) $(if $(filter true,$(codegen)),--codegen)

# Build parser and lexer
build: parser.y parallel_lex.l AST.cpp symbol_table.cpp semantics.cpp 
	yacc -dtv parser.y
	lex $(LEXFLAGS) parallel_lex.l
	$(CXX) $(CXXFLAGS) y.tab.c $(LLVM_FLAGS) -o $(TARGET)


run: build
	@./parser.out $(FLAGS) < $(input)
	@exit 0


build_lex_tests:
	g++ test/lex/generate_token.c -o test/lex/token_header.out
	cd test/lex/ && ./token_header.out
	g++ test/lex/lex_tester.c -o test/lex/lex_tester.out


lex_tests: build build_lex_tests	;
	@cd test/lex/ && ./lex_tester.out ;

yacc_tests: build 
	@bash test/parser/yacc_tester.sh $(PRINT_OUT);

clean:
	rm -f y.tab.c y.tab.h lex.yy.c parser.out ./test/lex/lex_tester.out ./test/lex/token_header.out codegen.ll 

code_gen_test:
	@./parser.out $(debug) --ast< codegen_test_input/$(input);
	@exit 0;