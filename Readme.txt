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
