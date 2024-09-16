all:
	yacc -d parser.y
	lex parallel_lex.l
	gcc lex.yy.c y.tab.c
	./a.out
tests:
	yacc -d parser.y
	lex parallel_lex.l
	gcc test/lex/lex_tester.c -o test/lex/lex_tester
	cd test/lex && ./lex_tester