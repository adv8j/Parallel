

all: lex
	./parser.out

run: build 
	./parser.out

run_sample: build 
	./parser.out < sample.txt

build: 
	yacc -d parser.y
	lex $(LEXFLAGS) parallel_lex.l
	gcc lex.yy.c y.tab.c -o parser.out

lex_tests:
	gcc $(YACCFLAGS) test/lex/generate_token.c -o test/lex/token_header.out
	cd test/lex/ && ./token_header.out
	gcc $(YACCFLAGS) test/lex/lex_tester.c -o test/lex/lex_tester.out
	cd test/lex/ && ./lex_tester.out

yacc_tests: build 
	bash test/parser/yacc_tester.sh $(PRINT_OUT)

clean:
	rm -f y.tab.c y.tab.h lex.yy.c parser.out