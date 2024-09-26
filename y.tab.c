/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
int yylex(void);
extern void yyerror(char *s);

#line 77 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ASSIGN = 258,                  /* ASSIGN  */
    PLUS = 259,                    /* PLUS  */
    MINUS = 260,                   /* MINUS  */
    MUL = 261,                     /* MUL  */
    DIV = 262,                     /* DIV  */
    MOD = 263,                     /* MOD  */
    EQ = 264,                      /* EQ  */
    NEQ = 265,                     /* NEQ  */
    GT = 266,                      /* GT  */
    LT = 267,                      /* LT  */
    GTE = 268,                     /* GTE  */
    LTE = 269,                     /* LTE  */
    AND = 270,                     /* AND  */
    OR = 271,                      /* OR  */
    NOT = 272,                     /* NOT  */
    ADD_ASSIGN = 273,              /* ADD_ASSIGN  */
    SUB_ASSIGN = 274,              /* SUB_ASSIGN  */
    MUL_ASSIGN = 275,              /* MUL_ASSIGN  */
    DIV_ASSIGN = 276,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 277,              /* MOD_ASSIGN  */
    SEMICOLON = 278,               /* SEMICOLON  */
    COLON = 279,                   /* COLON  */
    LPAREN = 280,                  /* LPAREN  */
    RPAREN = 281,                  /* RPAREN  */
    LBRACKET = 282,                /* LBRACKET  */
    RBRACKET = 283,                /* RBRACKET  */
    LBRACE = 284,                  /* LBRACE  */
    RBRACE = 285,                  /* RBRACE  */
    COMMA = 286,                   /* COMMA  */
    DOT = 287,                     /* DOT  */
    RANGE = 288,                   /* RANGE  */
    RANGE_INCL = 289,              /* RANGE_INCL  */
    REFERENCE = 290,               /* REFERENCE  */
    TASKGROUP = 291,               /* TASKGROUP  */
    TASK = 292,                    /* TASK  */
    PROPERTIES = 293,              /* PROPERTIES  */
    ORDER = 294,                   /* ORDER  */
    MEM = 295,                     /* MEM  */
    SHARED_DIRECTIVE = 296,        /* SHARED_DIRECTIVE  */
    SUPERVISOR = 297,              /* SUPERVISOR  */
    ALL = 298,                     /* ALL  */
    UNSAFE = 299,                  /* UNSAFE  */
    JOIN = 300,                    /* JOIN  */
    CALL = 301,                    /* CALL  */
    CHN_SEND = 302,                /* CHN_SEND  */
    CHANNEL_WAIT = 303,            /* CHANNEL_WAIT  */
    TASK_CHANNEL = 304,            /* TASK_CHANNEL  */
    LOG = 305,                     /* LOG  */
    ARROW = 306,                   /* ARROW  */
    PARALLEL = 307,                /* PARALLEL  */
    PRIVATE = 308,                 /* PRIVATE  */
    SHARED = 309,                  /* SHARED  */
    SCHEDULE = 310,                /* SCHEDULE  */
    NUM_THREADS = 311,             /* NUM_THREADS  */
    REDUCTION = 312,               /* REDUCTION  */
    DYNAMIC_SCHEDULE = 313,        /* DYNAMIC_SCHEDULE  */
    STATIC_SCHEDULE = 314,         /* STATIC_SCHEDULE  */
    MUT = 315,                     /* MUT  */
    INT = 316,                     /* INT  */
    CHAR = 317,                    /* CHAR  */
    LONG = 318,                    /* LONG  */
    BOOL = 319,                    /* BOOL  */
    FLOAT = 320,                   /* FLOAT  */
    STRING = 321,                  /* STRING  */
    FUNC = 322,                    /* FUNC  */
    RETURN = 323,                  /* RETURN  */
    CONTINUE = 324,                /* CONTINUE  */
    BREAK = 325,                   /* BREAK  */
    STRUCT = 326,                  /* STRUCT  */
    IF = 327,                      /* IF  */
    ELSE = 328,                    /* ELSE  */
    FOR = 329,                     /* FOR  */
    IN = 330,                      /* IN  */
    TRUE = 331,                    /* TRUE  */
    FALSE = 332,                   /* FALSE  */
    IDENTIFIER = 333,              /* IDENTIFIER  */
    SHARED_IDENTIFIER = 334,       /* SHARED_IDENTIFIER  */
    INT_LITERAL = 335,             /* INT_LITERAL  */
    FLOAT_LITERAL = 336,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 337,          /* STRING_LITERAL  */
    CHARACTER_LITERAL = 338        /* CHARACTER_LITERAL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
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
#define REFERENCE 290
#define TASKGROUP 291
#define TASK 292
#define PROPERTIES 293
#define ORDER 294
#define MEM 295
#define SHARED_DIRECTIVE 296
#define SUPERVISOR 297
#define ALL 298
#define UNSAFE 299
#define JOIN 300
#define CALL 301
#define CHN_SEND 302
#define CHANNEL_WAIT 303
#define TASK_CHANNEL 304
#define LOG 305
#define ARROW 306
#define PARALLEL 307
#define PRIVATE 308
#define SHARED 309
#define SCHEDULE 310
#define NUM_THREADS 311
#define REDUCTION 312
#define DYNAMIC_SCHEDULE 313
#define STATIC_SCHEDULE 314
#define MUT 315
#define INT 316
#define CHAR 317
#define LONG 318
#define BOOL 319
#define FLOAT 320
#define STRING 321
#define FUNC 322
#define RETURN 323
#define CONTINUE 324
#define BREAK 325
#define STRUCT 326
#define IF 327
#define ELSE 328
#define FOR 329
#define IN 330
#define TRUE 331
#define FALSE 332
#define IDENTIFIER 333
#define SHARED_IDENTIFIER 334
#define INT_LITERAL 335
#define FLOAT_LITERAL 336
#define STRING_LITERAL 337
#define CHARACTER_LITERAL 338

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ASSIGN = 3,                     /* ASSIGN  */
  YYSYMBOL_PLUS = 4,                       /* PLUS  */
  YYSYMBOL_MINUS = 5,                      /* MINUS  */
  YYSYMBOL_MUL = 6,                        /* MUL  */
  YYSYMBOL_DIV = 7,                        /* DIV  */
  YYSYMBOL_MOD = 8,                        /* MOD  */
  YYSYMBOL_EQ = 9,                         /* EQ  */
  YYSYMBOL_NEQ = 10,                       /* NEQ  */
  YYSYMBOL_GT = 11,                        /* GT  */
  YYSYMBOL_LT = 12,                        /* LT  */
  YYSYMBOL_GTE = 13,                       /* GTE  */
  YYSYMBOL_LTE = 14,                       /* LTE  */
  YYSYMBOL_AND = 15,                       /* AND  */
  YYSYMBOL_OR = 16,                        /* OR  */
  YYSYMBOL_NOT = 17,                       /* NOT  */
  YYSYMBOL_ADD_ASSIGN = 18,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 19,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 20,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 21,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 22,                /* MOD_ASSIGN  */
  YYSYMBOL_SEMICOLON = 23,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 24,                     /* COLON  */
  YYSYMBOL_LPAREN = 25,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 26,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 27,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 28,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 29,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 30,                    /* RBRACE  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_DOT = 32,                       /* DOT  */
  YYSYMBOL_RANGE = 33,                     /* RANGE  */
  YYSYMBOL_RANGE_INCL = 34,                /* RANGE_INCL  */
  YYSYMBOL_REFERENCE = 35,                 /* REFERENCE  */
  YYSYMBOL_TASKGROUP = 36,                 /* TASKGROUP  */
  YYSYMBOL_TASK = 37,                      /* TASK  */
  YYSYMBOL_PROPERTIES = 38,                /* PROPERTIES  */
  YYSYMBOL_ORDER = 39,                     /* ORDER  */
  YYSYMBOL_MEM = 40,                       /* MEM  */
  YYSYMBOL_SHARED_DIRECTIVE = 41,          /* SHARED_DIRECTIVE  */
  YYSYMBOL_SUPERVISOR = 42,                /* SUPERVISOR  */
  YYSYMBOL_ALL = 43,                       /* ALL  */
  YYSYMBOL_UNSAFE = 44,                    /* UNSAFE  */
  YYSYMBOL_JOIN = 45,                      /* JOIN  */
  YYSYMBOL_CALL = 46,                      /* CALL  */
  YYSYMBOL_CHN_SEND = 47,                  /* CHN_SEND  */
  YYSYMBOL_CHANNEL_WAIT = 48,              /* CHANNEL_WAIT  */
  YYSYMBOL_TASK_CHANNEL = 49,              /* TASK_CHANNEL  */
  YYSYMBOL_LOG = 50,                       /* LOG  */
  YYSYMBOL_ARROW = 51,                     /* ARROW  */
  YYSYMBOL_PARALLEL = 52,                  /* PARALLEL  */
  YYSYMBOL_PRIVATE = 53,                   /* PRIVATE  */
  YYSYMBOL_SHARED = 54,                    /* SHARED  */
  YYSYMBOL_SCHEDULE = 55,                  /* SCHEDULE  */
  YYSYMBOL_NUM_THREADS = 56,               /* NUM_THREADS  */
  YYSYMBOL_REDUCTION = 57,                 /* REDUCTION  */
  YYSYMBOL_DYNAMIC_SCHEDULE = 58,          /* DYNAMIC_SCHEDULE  */
  YYSYMBOL_STATIC_SCHEDULE = 59,           /* STATIC_SCHEDULE  */
  YYSYMBOL_MUT = 60,                       /* MUT  */
  YYSYMBOL_INT = 61,                       /* INT  */
  YYSYMBOL_CHAR = 62,                      /* CHAR  */
  YYSYMBOL_LONG = 63,                      /* LONG  */
  YYSYMBOL_BOOL = 64,                      /* BOOL  */
  YYSYMBOL_FLOAT = 65,                     /* FLOAT  */
  YYSYMBOL_STRING = 66,                    /* STRING  */
  YYSYMBOL_FUNC = 67,                      /* FUNC  */
  YYSYMBOL_RETURN = 68,                    /* RETURN  */
  YYSYMBOL_CONTINUE = 69,                  /* CONTINUE  */
  YYSYMBOL_BREAK = 70,                     /* BREAK  */
  YYSYMBOL_STRUCT = 71,                    /* STRUCT  */
  YYSYMBOL_IF = 72,                        /* IF  */
  YYSYMBOL_ELSE = 73,                      /* ELSE  */
  YYSYMBOL_FOR = 74,                       /* FOR  */
  YYSYMBOL_IN = 75,                        /* IN  */
  YYSYMBOL_TRUE = 76,                      /* TRUE  */
  YYSYMBOL_FALSE = 77,                     /* FALSE  */
  YYSYMBOL_IDENTIFIER = 78,                /* IDENTIFIER  */
  YYSYMBOL_SHARED_IDENTIFIER = 79,         /* SHARED_IDENTIFIER  */
  YYSYMBOL_INT_LITERAL = 80,               /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 81,             /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 82,            /* STRING_LITERAL  */
  YYSYMBOL_CHARACTER_LITERAL = 83,         /* CHARACTER_LITERAL  */
  YYSYMBOL_YYACCEPT = 84,                  /* $accept  */
  YYSYMBOL_program = 85,                   /* program  */
  YYSYMBOL_statement_list = 86,            /* statement_list  */
  YYSYMBOL_one_or_more_statements = 87,    /* one_or_more_statements  */
  YYSYMBOL_generic_dtypes = 88,            /* generic_dtypes  */
  YYSYMBOL_dtype = 89,                     /* dtype  */
  YYSYMBOL_array = 90,                     /* array  */
  YYSYMBOL_array_element = 91,             /* array_element  */
  YYSYMBOL_dims = 92,                      /* dims  */
  YYSYMBOL_initializer_dims = 93,          /* initializer_dims  */
  YYSYMBOL_statement = 94,                 /* statement  */
  YYSYMBOL_inner_statement = 95,           /* inner_statement  */
  YYSYMBOL_one_or_more_inner_statements = 96, /* one_or_more_inner_statements  */
  YYSYMBOL_inner_statement_list = 97,      /* inner_statement_list  */
  YYSYMBOL_return_statement = 98,          /* return_statement  */
  YYSYMBOL_compound_statement = 99,        /* compound_statement  */
  YYSYMBOL_expression_statement = 100,     /* expression_statement  */
  YYSYMBOL_expression = 101,               /* expression  */
  YYSYMBOL_function_call = 102,            /* function_call  */
  YYSYMBOL_fn_call_argument_list = 103,    /* fn_call_argument_list  */
  YYSYMBOL_unary_operator = 104,           /* unary_operator  */
  YYSYMBOL_arithmetic_expression = 105,    /* arithmetic_expression  */
  YYSYMBOL_assignment_expression = 106,    /* assignment_expression  */
  YYSYMBOL_unary_expression = 107,         /* unary_expression  */
  YYSYMBOL_comparison_expression = 108,    /* comparison_expression  */
  YYSYMBOL_logical_expression = 109,       /* logical_expression  */
  YYSYMBOL_declaration_statement = 110,    /* declaration_statement  */
  YYSYMBOL_declaration_list = 111,         /* declaration_list  */
  YYSYMBOL_declaration = 112,              /* declaration  */
  YYSYMBOL_value_assign = 113,             /* value_assign  */
  YYSYMBOL_iterative_statement = 114,      /* iterative_statement  */
  YYSYMBOL_container = 115,                /* container  */
  YYSYMBOL_iterator = 116,                 /* iterator  */
  YYSYMBOL_range = 117,                    /* range  */
  YYSYMBOL_number = 118,                   /* number  */
  YYSYMBOL_selection_statement = 119,      /* selection_statement  */
  YYSYMBOL_if_chain_statement = 120,       /* if_chain_statement  */
  YYSYMBOL_function_declaration = 121,     /* function_declaration  */
  YYSYMBOL_datatype_and_ref = 122,         /* datatype_and_ref  */
  YYSYMBOL_argument_list = 123,            /* argument_list  */
  YYSYMBOL_argument_declaration = 124,     /* argument_declaration  */
  YYSYMBOL_array_arg_dimension = 125,      /* array_arg_dimension  */
  YYSYMBOL_array_arg_dimension_increase = 126, /* array_arg_dimension_increase  */
  YYSYMBOL_parallel_statement = 127,       /* parallel_statement  */
  YYSYMBOL_parallel_stmt_argument_list = 128, /* parallel_stmt_argument_list  */
  YYSYMBOL_parallel_stmt_argument = 129,   /* parallel_stmt_argument  */
  YYSYMBOL_schedule_list = 130,            /* schedule_list  */
  YYSYMBOL_reduction_list = 131,           /* reduction_list  */
  YYSYMBOL_reduction_operator_list = 132,  /* reduction_operator_list  */
  YYSYMBOL_channel_statement = 133,        /* channel_statement  */
  YYSYMBOL_signal_statement = 134,         /* signal_statement  */
  YYSYMBOL_wait_statement = 135,           /* wait_statement  */
  YYSYMBOL_taskgroup_statement = 136,      /* taskgroup_statement  */
  YYSYMBOL_taskgroup_argument_list = 137,  /* taskgroup_argument_list  */
  YYSYMBOL_taskgroup_argument = 138,       /* taskgroup_argument  */
  YYSYMBOL_taskgroup_definition = 139,     /* taskgroup_definition  */
  YYSYMBOL_task_declaration_list = 140,    /* task_declaration_list  */
  YYSYMBOL_task_declaration = 141,         /* task_declaration  */
  YYSYMBOL_task_statements = 142,          /* task_statements  */
  YYSYMBOL_one_or_more_task_statements = 143, /* one_or_more_task_statements  */
  YYSYMBOL_task_statement_list = 144,      /* task_statement_list  */
  YYSYMBOL_properties_declaration = 145,   /* properties_declaration  */
  YYSYMBOL_taskgroup_properties = 146,     /* taskgroup_properties  */
  YYSYMBOL_taskgroup_property = 147,       /* taskgroup_property  */
  YYSYMBOL_order_block = 148,              /* order_block  */
  YYSYMBOL_order_rule_list = 149,          /* order_rule_list  */
  YYSYMBOL_order_rule = 150,               /* order_rule  */
  YYSYMBOL_order_rule_start = 151,         /* order_rule_start  */
  YYSYMBOL_order_rule_mid = 152,           /* order_rule_mid  */
  YYSYMBOL_order_rule_end = 153,           /* order_rule_end  */
  YYSYMBOL_identifier_list = 154,          /* identifier_list  */
  YYSYMBOL_shared_block = 155,             /* shared_block  */
  YYSYMBOL_shared_rule_list = 156,         /* shared_rule_list  */
  YYSYMBOL_shared_rule = 157,              /* shared_rule  */
  YYSYMBOL_mem_block = 158,                /* mem_block  */
  YYSYMBOL_mem_statement_list = 159,       /* mem_statement_list  */
  YYSYMBOL_mem_statement = 160,            /* mem_statement  */
  YYSYMBOL_mem_taskgroup_list = 161,       /* mem_taskgroup_list  */
  YYSYMBOL_mem_taskgroup_name = 162,       /* mem_taskgroup_name  */
  YYSYMBOL_array_literal = 163,            /* array_literal  */
  YYSYMBOL_literals = 164,                 /* literals  */
  YYSYMBOL_value = 165                     /* value  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  80
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   577

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  205
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  382

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   338


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    42,    42,    45,    46,    47,    48,    53,    54,    55,
      56,    57,    58,    59,    63,    64,    68,    72,    77,    78,
      82,    83,    89,    90,    91,    92,    93,    94,    95,    96,
      99,   100,   102,   103,   105,   106,   107,   108,   109,   110,
     111,   115,   116,   117,   120,   127,   128,   135,   136,   137,
     138,   139,   140,   141,   142,   146,   147,   149,   150,   155,
     156,   161,   162,   163,   164,   165,   169,   170,   171,   172,
     173,   174,   180,   185,   186,   187,   188,   189,   190,   194,
     195,   200,   203,   204,   208,   209,   212,   213,   218,   219,
     225,   226,   229,   230,   234,   235,   239,   240,   245,   246,
     250,   251,   256,   261,   261,   265,   266,   269,   270,   273,
     274,   277,   278,   284,   285,   286,   288,   289,   292,   293,
     294,   295,   296,   299,   299,   303,   304,   308,   309,   310,
     311,   312,   315,   316,   320,   321,   322,   326,   327,   329,
     330,   333,   334,   336,   337,   339,   340,   344,   345,   348,
     349,   350,   354,   355,   357,   358,   360,   361,   362,   363,
     364,   365,   366,   370,   371,   376,   377,   381,   382,   383,
     387,   392,   393,   397,   402,   403,   407,   408,   412,   413,
     417,   418,   422,   427,   428,   432,   438,   439,   445,   446,
     451,   456,   457,   462,   463,   468,   472,   472,   472,   472,
     472,   472,   472,   475,   476,   477
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ASSIGN", "PLUS",
  "MINUS", "MUL", "DIV", "MOD", "EQ", "NEQ", "GT", "LT", "GTE", "LTE",
  "AND", "OR", "NOT", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN",
  "DIV_ASSIGN", "MOD_ASSIGN", "SEMICOLON", "COLON", "LPAREN", "RPAREN",
  "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", "COMMA", "DOT", "RANGE",
  "RANGE_INCL", "REFERENCE", "TASKGROUP", "TASK", "PROPERTIES", "ORDER",
  "MEM", "SHARED_DIRECTIVE", "SUPERVISOR", "ALL", "UNSAFE", "JOIN", "CALL",
  "CHN_SEND", "CHANNEL_WAIT", "TASK_CHANNEL", "LOG", "ARROW", "PARALLEL",
  "PRIVATE", "SHARED", "SCHEDULE", "NUM_THREADS", "REDUCTION",
  "DYNAMIC_SCHEDULE", "STATIC_SCHEDULE", "MUT", "INT", "CHAR", "LONG",
  "BOOL", "FLOAT", "STRING", "FUNC", "RETURN", "CONTINUE", "BREAK",
  "STRUCT", "IF", "ELSE", "FOR", "IN", "TRUE", "FALSE", "IDENTIFIER",
  "SHARED_IDENTIFIER", "INT_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL",
  "CHARACTER_LITERAL", "$accept", "program", "statement_list",
  "one_or_more_statements", "generic_dtypes", "dtype", "array",
  "array_element", "dims", "initializer_dims", "statement",
  "inner_statement", "one_or_more_inner_statements",
  "inner_statement_list", "return_statement", "compound_statement",
  "expression_statement", "expression", "function_call",
  "fn_call_argument_list", "unary_operator", "arithmetic_expression",
  "assignment_expression", "unary_expression", "comparison_expression",
  "logical_expression", "declaration_statement", "declaration_list",
  "declaration", "value_assign", "iterative_statement", "container",
  "iterator", "range", "number", "selection_statement",
  "if_chain_statement", "function_declaration", "datatype_and_ref",
  "argument_list", "argument_declaration", "array_arg_dimension",
  "array_arg_dimension_increase", "parallel_statement",
  "parallel_stmt_argument_list", "parallel_stmt_argument", "schedule_list",
  "reduction_list", "reduction_operator_list", "channel_statement",
  "signal_statement", "wait_statement", "taskgroup_statement",
  "taskgroup_argument_list", "taskgroup_argument", "taskgroup_definition",
  "task_declaration_list", "task_declaration", "task_statements",
  "one_or_more_task_statements", "task_statement_list",
  "properties_declaration", "taskgroup_properties", "taskgroup_property",
  "order_block", "order_rule_list", "order_rule", "order_rule_start",
  "order_rule_mid", "order_rule_end", "identifier_list", "shared_block",
  "shared_rule_list", "shared_rule", "mem_block", "mem_statement_list",
  "mem_statement", "mem_taskgroup_list", "mem_taskgroup_name",
  "array_literal", "literals", "value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-314)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-98)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     239,  -314,  -314,  -314,   264,   140,   -53,    92,  -314,  -314,
    -314,  -314,  -314,  -314,   -27,    32,    39,    -8,  -314,  -314,
      89,   102,  -314,  -314,  -314,   160,  -314,   239,   141,   -16,
    -314,  -314,  -314,  -314,  -314,   488,  -314,    66,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,   166,  -314,  -314,  -314,  -314,
    -314,  -314,  -314,   416,   264,   156,   165,   161,   140,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,  -314,    95,   180,  -314,
      87,  -314,   264,    49,   129,  -314,   138,   149,    66,   188,
    -314,  -314,   192,   146,   225,    81,  -314,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
     264,   264,   264,   264,   264,   264,  -314,  -314,  -314,  -314,
    -314,  -314,    66,  -314,   509,  -314,  -314,  -314,  -314,   -11,
      97,   247,   260,   263,   277,   279,     0,  -314,   227,   440,
      49,  -314,   118,  -314,   530,    18,   255,    66,    66,  -314,
     281,   264,  -314,  -314,   -16,   530,   170,   170,  -314,  -314,
    -314,   234,   234,   253,   253,   253,   253,   561,   549,   530,
     530,   530,   530,   530,  -314,  -314,   282,   283,   241,   259,
     214,   215,   265,    38,  -314,   267,   269,   114,   217,   271,
     -14,   180,    87,   278,   264,   280,   278,  -314,  -314,   264,
    -314,   286,    51,   230,   530,  -314,   236,    66,   294,   -11,
     130,   296,   303,   298,  -314,  -314,   250,   250,  -314,  -314,
    -314,  -314,   266,  -314,  -314,  -314,   299,   257,   112,  -314,
     256,   464,  -314,   530,  -314,    66,  -314,  -314,  -314,    97,
    -314,   275,   307,   307,  -314,   154,  -314,   133,   139,   309,
     313,   314,   319,   324,   119,  -314,  -314,   249,   278,    87,
       6,  -314,   278,   321,   320,   348,   323,    -1,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,   330,   331,   327,   307,  -314,
     328,   332,     8,   333,    17,  -314,  -314,  -314,  -314,  -314,
     285,  -314,   250,   250,   250,   250,   250,   266,  -314,    66,
    -314,  -314,   251,  -314,  -314,  -314,  -314,  -314,  -314,   337,
      66,   287,   334,   264,  -314,  -314,  -314,  -314,  -314,   339,
     250,   335,   288,  -314,  -314,  -314,   336,   336,   336,   336,
     336,  -314,  -314,    66,  -314,  -314,   349,   343,   350,   530,
     329,    12,  -314,   250,   -10,   -17,  -314,   250,   362,    -7,
    -314,  -314,   376,   264,  -314,  -314,  -314,  -314,    -3,   336,
     338,  -314,  -314,     3,    87,  -314,  -314,   307,   388,  -314,
     -25,  -314,   351,    88,  -314,  -314,   361,   383,   363,   392,
     336,  -314,  -314,   338,   250,  -314,   355,  -314,  -314,   110,
    -314,  -314
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    59,    60,    46,     0,    31,     0,     0,     7,    12,
       8,    11,     9,    10,     0,     0,     0,     0,   200,   201,
     204,   196,   197,   198,   199,     0,     2,     3,    14,     0,
      15,   205,     6,    25,    24,     0,    54,     0,    50,    49,
      53,    52,    51,    28,    22,     0,    23,    26,    29,    27,
     202,   203,    47,     0,     0,     0,     0,     0,    30,    33,
      40,    37,    36,    38,    34,    35,    39,     0,     0,   114,
       0,    13,     0,     0,     0,    92,     0,     0,     0,    17,
       1,     5,    21,     0,    87,     0,    83,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    45,    97,    96,    72,
      94,    95,     0,    48,     0,    43,    42,    44,    32,     0,
     146,     0,     0,     0,     0,     0,     0,   117,     0,     0,
       0,    93,     0,    55,    58,     0,     0,     0,     0,    16,
       0,     0,    85,    81,     0,    66,    61,    62,    63,    64,
      65,    77,    78,    74,    73,    75,    76,    79,    80,    67,
      68,    69,    70,    71,   195,    41,     0,     0,     0,   142,
       0,     0,     0,   164,   148,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    97,     0,    91,    56,     0,
      19,     0,     0,     0,    86,    82,     0,     0,     0,     0,
       0,     0,     0,     0,   147,   145,     0,     0,   124,   123,
     121,   122,     0,   113,   115,   116,   103,     0,     0,   105,
     101,     0,    89,    57,    18,     0,    84,   143,   144,   146,
     141,     0,   153,   153,   140,     0,   181,     0,     0,     0,
       0,     0,     0,     0,     0,   126,   104,   107,     0,     0,
       0,    98,     0,     0,     0,     0,     0,   134,   159,   158,
     160,   156,   157,   161,   162,     0,     0,     0,   152,   155,
       0,     0,     0,     0,     0,   166,   167,   168,   169,   119,
       0,   118,     0,     0,     0,     0,     0,     0,   120,     0,
     110,   108,     0,   102,   106,    99,   100,    88,    20,     0,
       0,     0,     0,     0,   132,   133,   149,   154,   151,   175,
       0,     0,     0,   163,   165,   180,   127,   128,   129,   130,
     131,   125,   112,     0,   109,   139,     0,     0,     0,   135,
       0,   175,   172,     0,     0,     0,   189,     0,     0,     0,
     184,   111,     0,     0,   136,   174,   170,   171,     0,   177,
       0,   186,   188,     0,     0,   182,   183,   153,     0,   179,
       0,   173,   193,     0,   192,   187,     0,     0,   137,     0,
     176,   194,   190,     0,     0,   150,     0,   178,   191,     0,
     138,   185
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -314,  -314,  -314,  -314,  -314,   -67,  -314,  -314,   389,  -314,
     412,  -314,  -314,   382,  -314,     1,   113,    -4,  -314,  -314,
    -314,  -314,  -314,  -314,  -314,  -314,     7,  -314,   297,  -314,
       9,  -314,  -314,  -314,   -35,     5,  -314,  -314,  -314,  -314,
     208,  -314,  -314,    11,  -314,   284,  -314,  -314,   176,  -314,
    -314,  -314,  -314,  -314,   289,   235,  -314,   308,  -229,  -314,
     219,  -314,  -314,   231,  -314,  -314,   158,  -314,  -314,  -314,
    -177,  -314,  -314,   187,  -314,   210,  -313,  -314,   203,   445,
    -314,  -314
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    25,    26,    27,    28,    29,    30,    31,    79,   139,
      32,    57,    58,    59,    60,   258,   259,    35,    36,   135,
      37,    38,    39,    40,    41,    42,   260,    85,    86,   142,
     261,   186,    76,   112,    45,   262,   251,    47,   217,   218,
     219,   291,   292,   263,   126,   127,   210,   244,   245,   264,
     265,   266,    49,   168,   169,   172,   173,   174,   267,   268,
     269,   205,   274,   275,   276,   331,   332,   333,   348,   361,
     334,   277,   339,   340,   278,   335,   336,   363,   364,    50,
      51,    52
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      53,    33,   109,   128,   270,    46,    61,    43,    69,    44,
      65,    48,    63,   351,    64,     5,    66,    73,   369,    83,
     359,   280,   352,   355,   302,    67,   180,    74,    33,   237,
     238,   181,    46,   365,    43,     5,    44,   310,    48,   166,
     352,   350,   346,   136,   188,   167,   303,   313,   360,   189,
     114,    70,   311,   236,     1,   330,   271,   272,   273,    61,
      17,   236,    84,    65,    72,    63,     2,    64,   129,    66,
      75,   338,     3,   134,     4,   170,   203,   164,    16,   224,
     171,   236,   225,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   191,   192,   143,   316,   317,   318,   319,   320,
      71,   372,   144,    34,    77,   216,    78,    68,    62,   373,
     119,     5,   -97,   -97,   120,    18,    19,    20,   367,    21,
      22,    23,    24,   381,   170,   -96,   -96,   194,   248,   171,
      34,   280,   287,   249,   107,     1,   108,   288,     8,     9,
      10,    11,    12,    13,     1,   231,   349,     2,    15,   232,
      80,   279,   228,     3,   280,     4,     2,   281,    78,     5,
     280,    62,   208,   209,     4,   133,    90,    91,    92,   115,
     221,   213,   216,   370,   220,   223,   130,   222,   116,   214,
     253,   117,     7,   271,   272,   273,   185,   379,   108,   110,
     111,     8,     9,    10,    11,    12,    13,   131,    54,    55,
      56,    15,    16,   132,    17,   137,    18,    19,    20,   138,
      21,    22,    23,    24,   140,    18,    19,    20,   141,    21,
      22,    23,    24,   121,   122,   123,   124,   125,    88,    89,
      90,    91,    92,   184,     1,    95,    96,    97,    98,   293,
     175,   295,   182,   297,   322,   296,     2,    88,    89,    90,
      91,    92,     3,   176,     4,   326,   177,   198,     5,     1,
     239,   240,   241,   242,   243,     6,   289,   290,   323,   324,
     178,     2,   179,   190,   193,   196,   197,   366,   341,     4,
     199,     7,   200,   201,   206,   202,   207,   211,   212,   329,
       8,     9,    10,    11,    12,    13,    14,     5,   226,   -90,
      15,    16,     1,    17,   224,    18,    19,    20,   227,    21,
      22,    23,    24,   229,     2,   233,   234,   235,   236,   250,
       3,   255,     4,   282,   246,   247,     5,   283,   284,   358,
      18,    19,    20,   285,    21,    22,    23,    24,   286,   298,
     299,   300,   301,   304,   305,   256,   257,   306,   308,     7,
     325,   309,   312,   315,   337,   327,   338,   280,     8,     9,
      10,    11,    12,    13,   343,   342,   344,   328,    15,    16,
     345,    17,   330,    18,    19,    20,   354,    21,    22,    23,
      24,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   357,   101,   102,   103,   104,
     105,   371,   374,   375,   376,   377,   362,    82,   368,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   380,   101,   102,   103,   104,   105,    81,
     118,   195,   113,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   294,   101,   102,
     103,   104,   105,   321,   254,   215,   183,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   204,   101,   102,   103,   104,   105,   307,   230,   347,
     252,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   314,   101,   102,   103,   104,
     105,   106,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   356,   101,   102,   103,
     104,   105,   165,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   353,   101,   102,
     103,   104,   105,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,   378,   187
};

static const yytype_int16 yycheck[] =
{
       4,     0,    37,    70,   233,     0,     5,     0,     7,     0,
       5,     0,     5,    30,     5,    29,     5,    25,    43,    35,
      23,    31,   335,    30,    25,    78,    26,    35,    27,   206,
     207,    31,    27,    30,    27,    29,    27,    29,    27,    50,
     353,    51,    30,    78,    26,    56,    47,    30,    51,    31,
      54,    78,    44,    78,     5,    43,    39,    40,    41,    58,
      74,    78,    78,    58,    25,    58,    17,    58,    72,    58,
      78,    78,    23,    77,    25,    37,    38,   112,    72,    28,
      42,    78,    31,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   137,   138,    23,   282,   283,   284,   285,   286,
      78,    23,    31,     0,    25,   182,    27,    25,     5,    31,
      25,    29,    33,    34,    29,    76,    77,    78,   357,    80,
      81,    82,    83,    23,    37,    33,    34,   141,    26,    42,
      27,    31,    23,    31,    78,     5,    80,    28,    61,    62,
      63,    64,    65,    66,     5,    25,   333,    17,    71,    29,
       0,    28,   197,    23,    31,    25,    17,    28,    27,    29,
      31,    58,    58,    59,    25,    26,     6,     7,     8,    23,
     184,   180,   249,   360,   183,   189,    73,   186,    23,   180,
     225,    30,    52,    39,    40,    41,    78,   374,    80,    33,
      34,    61,    62,    63,    64,    65,    66,    78,    68,    69,
      70,    71,    72,    75,    74,    27,    76,    77,    78,    27,
      80,    81,    82,    83,    78,    76,    77,    78,     3,    80,
      81,    82,    83,    53,    54,    55,    56,    57,     4,     5,
       6,     7,     8,   130,     5,    11,    12,    13,    14,   248,
       3,   250,    25,   252,   289,   250,    17,     4,     5,     6,
       7,     8,    23,     3,    25,   300,     3,    26,    29,     5,
       4,     5,     6,     7,     8,    36,    27,    28,    27,    28,
       3,    17,     3,    28,     3,     3,     3,   354,   323,    25,
      31,    52,    78,    78,    27,    30,    27,    80,    27,   303,
      61,    62,    63,    64,    65,    66,    67,    29,    78,    29,
      71,    72,     5,    74,    28,    76,    77,    78,    82,    80,
      81,    82,    83,    29,    17,    29,    23,    29,    78,    73,
      23,    56,    25,    24,    35,    78,    29,    24,    24,   343,
      76,    77,    78,    24,    80,    81,    82,    83,    24,    28,
      30,     3,    29,    23,    23,    48,    49,    30,    30,    52,
      23,    29,    29,    78,    29,    78,    78,    31,    61,    62,
      63,    64,    65,    66,    31,    26,    26,    43,    71,    72,
      51,    74,    43,    76,    77,    78,    24,    80,    81,    82,
      83,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    29,    18,    19,    20,    21,
      22,    60,    51,    30,    51,    23,    78,    28,    30,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    78,    18,    19,    20,    21,    22,    27,
      58,   144,    26,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   249,    18,    19,
      20,    21,    22,   287,   229,   181,    26,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   173,    18,    19,    20,    21,    22,   268,   199,   331,
      26,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   274,    18,    19,    20,    21,
      22,    23,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,   339,    18,    19,    20,
      21,    22,    23,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,   337,    18,    19,
      20,    21,    22,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,   373,   132
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    17,    23,    25,    29,    36,    52,    61,    62,
      63,    64,    65,    66,    67,    71,    72,    74,    76,    77,
      78,    80,    81,    82,    83,    85,    86,    87,    88,    89,
      90,    91,    94,    99,   100,   101,   102,   104,   105,   106,
     107,   108,   109,   110,   114,   118,   119,   121,   127,   136,
     163,   164,   165,   101,    68,    69,    70,    95,    96,    97,
      98,    99,   100,   110,   114,   119,   127,    78,    25,    99,
      78,    78,    25,    25,    35,    78,   116,    25,    27,    92,
       0,    94,    92,    35,    78,   111,   112,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    18,    19,    20,    21,    22,    23,    78,    80,   118,
      33,    34,   117,    26,   101,    23,    23,    30,    97,    25,
      29,    53,    54,    55,    56,    57,   128,   129,    89,   101,
     100,    78,    75,    26,   101,   103,   118,    27,    27,    93,
      78,     3,   113,    23,    31,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   118,    23,    50,    56,   137,   138,
      37,    42,   139,   140,   141,     3,     3,     3,     3,     3,
      26,    31,    25,    26,   100,    78,   115,   163,    26,    31,
      28,   118,   118,     3,   101,   112,     3,     3,    26,    31,
      78,    78,    30,    38,   141,   145,    27,    27,    58,    59,
     130,    80,    27,    99,   114,   129,    89,   122,   123,   124,
      99,   101,    99,   101,    28,    31,    78,    82,   118,    29,
     138,    25,    29,    29,    23,    29,    78,   154,   154,     4,
       5,     6,     7,     8,   131,   132,    35,    78,    26,    31,
      73,   120,    26,   118,   139,    56,    48,    49,    99,   100,
     110,   114,   119,   127,   133,   134,   135,   142,   143,   144,
     142,    39,    40,    41,   146,   147,   148,   155,   158,    28,
      31,    28,    24,    24,    24,    24,    24,    23,    28,    27,
      28,   125,   126,    99,   124,    99,   119,    99,    28,    30,
       3,    29,    25,    47,    23,    23,    30,   144,    30,    29,
      29,    44,    29,    30,   147,    78,   154,   154,   154,   154,
     154,   132,   118,    27,    28,    23,   118,    78,    43,   101,
      43,   149,   150,   151,   154,   159,   160,    29,    78,   156,
     157,   118,    26,    31,    26,    51,    30,   150,   152,   154,
      51,    30,   160,   159,    24,    30,   157,    29,   101,    23,
      51,   153,    78,   161,   162,    30,    89,   142,    30,    43,
     154,    60,    23,    31,    51,    30,    51,    23,   162,   154,
      78,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    84,    85,    86,    86,    87,    87,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    91,    92,    92,
      93,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      95,    95,    96,    96,    97,    97,    97,    97,    97,    97,
      97,    98,    98,    98,    99,   100,   100,   101,   101,   101,
     101,   101,   101,   101,   101,   102,   102,   103,   103,   104,
     104,   105,   105,   105,   105,   105,   106,   106,   106,   106,
     106,   106,   107,   108,   108,   108,   108,   108,   108,   109,
     109,   110,   111,   111,   112,   112,   113,   113,   114,   114,
     115,   115,   116,   116,   117,   117,   118,   118,   119,   119,
     120,   120,   121,   122,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   127,   127,   127,   128,   128,   129,   129,
     129,   129,   129,   130,   130,   131,   131,   132,   132,   132,
     132,   132,   133,   133,   134,   134,   134,   135,   135,   136,
     136,   137,   137,   138,   138,   139,   139,   140,   140,   141,
     141,   141,   142,   142,   143,   143,   144,   144,   144,   144,
     144,   144,   144,   145,   145,   146,   146,   147,   147,   147,
     148,   149,   149,   150,   151,   151,   152,   152,   153,   153,
     154,   154,   155,   156,   156,   157,   158,   158,   159,   159,
     160,   161,   161,   162,   162,   163,   164,   164,   164,   164,
     164,   164,   164,   165,   165,   165
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     3,     2,     4,     3,
       5,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     2,     2,     3,     2,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     4,     2,     2,     0,     7,     5,
       1,     1,     1,     2,     1,     1,     1,     1,     6,     7,
       2,     0,     7,     1,     2,     1,     3,     2,     3,     2,
       1,     3,     2,     5,     2,     5,     3,     1,     5,     5,
       5,     3,     3,     1,     1,     3,     1,     3,     3,     3,
       3,     3,     2,     2,     1,     3,     4,     6,     8,     9,
       6,     3,     1,     3,     3,     2,     0,     2,     1,     5,
      10,     5,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     0,     2,     1,     1,     1,     1,
       4,     2,     1,     3,     2,     0,     3,     1,     3,     1,
       3,     1,     4,     2,     1,     6,     4,     5,     2,     1,
       4,     3,     1,     1,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: statement_list  */
#line 42 "parser.y"
                        {printf("Program is correct\n");}
#line 1770 "y.tab.c"
    break;


#line 1774 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 483 "parser.y"

int main(void) {
	yyparse();
}

