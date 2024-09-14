all:
	yacc -d parser.y
	lex parallel_lex.l
	gcc lex.yy.c
	./a.out