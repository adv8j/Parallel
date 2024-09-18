all: lex
	
	./a.out
lex: 
	yacc -d parser.y
	lex parallel_lex.l
	gcc lex.yy.c y.tab.c -o parser.out

lex_tests:
	gcc test/lex/generate_token.c -o test/lex/token_header.out
	cd test/lex/ && ./token_header.out
	gcc test/lex/lex_tester.c -o test/lex/lex_tester.out
	cd test/lex/ && ./lex_tester.out