DSL Name:
Parallel

Description:
Parallel is a domain-specific language (DSL) that makes parallel programming easier and more efficient. It combines features from Go and Rust to create a simple, clean syntax for managing parallel tasks and threads.

The core concept in Parallel is the Task, which works like a thread but gives you more control over memory and locking. This makes it easier to manage resources and improve performance in parallel programs.

Parallel also takes inspiration from OpenMP, allowing you to write short, efficient code for handling parallel tasks quickly. Whether you're working on small or large tasks, Parallel helps you get the job done without the complexity of traditional thread management.

In short, Parallel is designed to make parallel programming more accessible, while giving you the control and flexibility needed for performance.
=======================================================================================================================================================
Running Instructions:

To run the project with a given test file, use the following command:

make run input=<testFileName>

Example:

make run input=codegen_test.txt

This command will:

Process the provided testFileName (e.g., codegen_test.txt).
Print the Abstract Syntax Tree (AST) for the provided test file.
Generate the corresponding LLVM code based on the input.

=======================================================================================================================================================
Work Progress:

Completed:

Lexical analysis (Lexer)
Parser
Abstract Syntax Tree (AST) generation
Symbol Table
Semantics (type checking, symbol tables)

Partially completed:

Code generation (LLVM)

Currently we are trying to complete Code generation


=======================================================================================================================================================



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