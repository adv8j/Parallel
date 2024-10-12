

build: 
	yacc -dtv parser.y 
	lex $(LEXFLAGS) parallel_lex.l
	gcc lex.yy.c y.tab.c -o parser.out
	
all: lex
	./parser.out

run: build
	@./parser.out $(debug) < $(input); \
	exit 0;


build_lex_tests:
	gcc test/lex/generate_token.c -o test/lex/token_header.out
	cd test/lex/ && ./token_header.out
	gcc test/lex/lex_tester.c -o test/lex/lex_tester.out


lex_tests: build build_lex_tests	;
	@cd test/lex/ && ./lex_tester.out ;

yacc_tests: build 
	@bash test/parser/yacc_tester.sh $(PRINT_OUT);

clean:
	rm -f y.tab.c y.tab.h lex.yy.c parser.out ./test/lex/lex_tester.out ./test/lex/token_header.out
