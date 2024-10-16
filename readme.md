## Prerequisites:
Before running or building the project, ensure the following tools are installed:

1. Flex (for lexical analysis)
2. Yacc (for parser generation)
3. GCC (for compilation)

## How to run the project:
1. To build the entire project, run the following command:
```make build```

    This will:

- Run Yacc to generate the parser.
- Run Flex to generate the lexer.
- Compile the lexer and parser together using gcc.


2. To execute the parser after building it, use: 
```make run input=<input-file> ```\
If you want to enable debugging, pass debug=1:
```make run input=<input-file> debug=1```

3. To remove all generated files, run:```make clean```

4. To run the lexer tests:``` make lex_tests```

- This will build the ```parallel_lex.l file``` and execute the test case files present in test/lex/input.
The expected output is given in ```test/lex/expected``` and output generated is in ```test/lex/output```.

5. To run the Yacc parser tests: ```make yacc_tests```.
- To print the output during tests, run: ```make yacc_tests PRINT_OUT=1```
- It will run the test cases present in test/parser/input. Files whose name has _wrong.txt are files with incorrect test cases.


## Directory Structure:
- parser.y: The yacc grammar file.
- parallel_lex.l: The Flex lexer definition file.
- test/lex/: Contains lexer-related test files.
- test.parser/: Contains parser-related test files.