# Default DBG flag is 0 (no debugging symbols)
DBG ?= 0
DEBUG_FLAGS = $(if $(filter 1,$(DBG)),-g,)

build: 
	yacc -d parser.y
	lex $(LEXFLAGS) parallel_lex.l
	gcc lex.yy.c y.tab.c -o parser.out
	
all: lex
	./parser.out

run: build
	@./parser.out < $(input) \
	exit 0;
	

run_sample: build 
	@-./parser.out < sample.txt ;\
	exit 0;


build_lex_tests:
	gcc $(YACCFLAGS) $(DEBUG_FLAGS) test/lex/generate_token.c -o test/lex/token_header.out
	cd test/lex/ && ./token_header.out
	gcc $(YACCFLAGS) $(DEBUG_FLAGS) test/lex/lex_tester.c -o test/lex/lex_tester.out


lex_tests: build_lex_tests	
	cd test/lex/ && ./lex_tester.out

yacc_tests: build 
	bash test/parser/yacc_tester.sh $(PRINT_OUT)

clean:
	rm -f y.tab.c y.tab.h lex.yy.c parser.out
