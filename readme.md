# Parallel

## Description:
Parallel is a domain-specific language (DSL) that makes parallel programming easier and more efficient. It combines features from Go and Rust to create a simple, clean syntax for managing parallel tasks and threads.

The core concept in Parallel is the Task, which works like a thread but gives you more control over memory and locking. This makes it easier to manage resources and improve performance in parallel programs.

Parallel also takes inspiration from OpenMP, allowing you to write short, efficient code for handling parallel tasks quickly. Whether you're working on small or large tasks, Parallel helps you get the job done without the complexity of traditional thread management.

In short, Parallel is designed to make parallel programming more accessible, while giving you the control and flexibility needed for performance.

----------------------------------------------------------------------------------------------------------------------------------------------------
## Running Instructions:

To run the project with a given test file, use the following command:
```bash
make run input=<testFileName> 
```

Example:
```bash
make run input=codegen_test.txt
```

### Supported Flags:
- `debug=1`: To enable debugging mode, where we can see the parsing stack and token details on each input consumed.
- `ast=1`: To print the Abstract Syntax Tree (AST) after parsing(annotated with the node type).
- `codegen=1`: To generate the LLVM IR code after parsing and semantic analysis in `codegen.ll` file.

Example:
```bash
make run input=codegen_test.txt debug=1 ast=1 codegen=1
```


----------------------------------------------------------------------------------------------------------------------------------------------------

## Work Progress:

### Completed:

1. Lexical analysis (Lexer)
2. Parser
3. Abstract Syntax Tree (AST) generation
4. Symbol Table
5. Semantics (type checking, symbol tables)
6. Error handler for Syntax and Semantic errors.


### Partially completed:

1. **Code generation (LLVM)**:

Currently we are trying to complete Code generation. Mostly, codegen is only left for Writing the Parallel constructs in LLVM IR.


-----------------------------------------------------------------------------------------------------------------------------------------------


## Prerequisites:
Before running or building the project, ensure the following tools are installed:

1. Flex (for lexical analysis)
2. Yacc (for parser generation)
3. GCC (for compilation)

## Running Default Testers:
1. To build the entire project, run the following command:
```bash 
make build
```

This will:

- Run **Yacc** to generate the parser.
- Run **Flex** to generate the lexer.
- Compile the lexer and parser together using gcc.


2. To execute the parser after building it, use: 
```bash
make run input=<input-file> ast=1 debug=0 codegen=1
```

3. To remove all generated files, run:
```bash
make clean
```

4. To run the lexer tests:
```bash
 make lex_tests
```

- This will build the ```parallel_lex.l file``` and execute the test case files present in test/lex/input.
The expected output is given in ```test/lex/expected``` and output generated is in ```test/lex/output```.

5. To run the Yacc parser tests: 
```bash
 make yacc_tests
```
- To print the output during tests, run: ```make yacc_tests PRINT_OUT=1```
- It will run the test cases present in test/parser/input. Files whose name has _wrong.txt are files with incorrect test cases.


## Directory Structure:
- parser.y: The yacc grammar file.
- parallel_lex.l: The Flex lexer definition file.
- test/lex/: Contains lexer-related test files.
- test.parser/: Contains parser-related test files.