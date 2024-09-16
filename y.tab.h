/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ASSIGN = 258,
     PLUS = 259,
     MINUS = 260,
     MUL = 261,
     DIV = 262,
     MOD = 263,
     EQ = 264,
     NEQ = 265,
     GT = 266,
     LT = 267,
     GTE = 268,
     LTE = 269,
     AND = 270,
     OR = 271,
     NOT = 272,
     ADD_ASSIGN = 273,
     SUB_ASSIGN = 274,
     MUL_ASSIGN = 275,
     DIV_ASSIGN = 276,
     MOD_ASSIGN = 277,
     SEMICOLON = 278,
     COLON = 279,
     LPAREN = 280,
     RPAREN = 281,
     LBRACKET = 282,
     RBRACKET = 283,
     LBRACE = 284,
     RBRACE = 285,
     COMMA = 286,
     DOT = 287,
     RANGE = 288,
     RANGE_INCL = 289,
     QUOTE = 290,
     REFERENCE = 291,
     NUMBER = 292,
     STRING = 293,
     CHAR = 294,
     TASKGROUP = 295,
     TASK = 296,
     PROPERTIES = 297,
     ORDER = 298,
     CHANNEL = 299,
     MEM = 300,
     _SHARED = 301,
     SUPERVISOR = 302,
     ALL = 303,
     UNSAFE = 304,
     JOIN = 305,
     CALL = 306,
     CHN_SEND = 307,
     CHANNEL_WAIT = 308,
     TASK_CHANNEL = 309,
     LOG = 310,
     ARROW = 311,
     PARALLEL = 312,
     SHARED = 313,
     PRIVATE = 314,
     SCHEDULE = 315,
     NUM_THREADS = 316,
     DYNAMIC_SCHEDULE = 317,
     STATIC_SCHEDULE = 318,
     INT = 319,
     LONG = 320,
     BOOL = 321,
     IDENTIFIER = 322,
     SHARED_IDENTIFIER = 323,
     REDUCTION = 324,
     MUT = 325,
     FUNC = 326,
     RETURN = 327,
     STRUCT = 328,
     IF = 329,
     ELSE = 330,
     FOR = 331,
     IN = 332,
     FLOAT = 333,
     STRING_LITERAL = 334,
     CHARACTER = 335
   };
#endif
/* Tokens.  */
#define ASSIGN 258
#define PLUS 259
#define MINUS 260
#define MUL 261
#define DIV 262
#define MOD 263
#define EQ 264
#define NEQ 265
#define GT 266
#define LT 267
#define GTE 268
#define LTE 269
#define AND 270
#define OR 271
#define NOT 272
#define ADD_ASSIGN 273
#define SUB_ASSIGN 274
#define MUL_ASSIGN 275
#define DIV_ASSIGN 276
#define MOD_ASSIGN 277
#define SEMICOLON 278
#define COLON 279
#define LPAREN 280
#define RPAREN 281
#define LBRACKET 282
#define RBRACKET 283
#define LBRACE 284
#define RBRACE 285
#define COMMA 286
#define DOT 287
#define RANGE 288
#define RANGE_INCL 289
#define QUOTE 290
#define REFERENCE 291
#define NUMBER 292
#define STRING 293
#define CHAR 294
#define TASKGROUP 295
#define TASK 296
#define PROPERTIES 297
#define ORDER 298
#define CHANNEL 299
#define MEM 300
#define _SHARED 301
#define SUPERVISOR 302
#define ALL 303
#define UNSAFE 304
#define JOIN 305
#define CALL 306
#define CHN_SEND 307
#define CHANNEL_WAIT 308
#define TASK_CHANNEL 309
#define LOG 310
#define ARROW 311
#define PARALLEL 312
#define SHARED 313
#define PRIVATE 314
#define SCHEDULE 315
#define NUM_THREADS 316
#define DYNAMIC_SCHEDULE 317
#define STATIC_SCHEDULE 318
#define INT 319
#define LONG 320
#define BOOL 321
#define IDENTIFIER 322
#define SHARED_IDENTIFIER 323
#define REDUCTION 324
#define MUT 325
#define FUNC 326
#define RETURN 327
#define STRUCT 328
#define IF 329
#define ELSE 330
#define FOR 331
#define IN 332
#define FLOAT 333
#define STRING_LITERAL 334
#define CHARACTER 335




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

