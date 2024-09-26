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
    STRUCT = 324,                  /* STRUCT  */
    IF = 325,                      /* IF  */
    ELSE = 326,                    /* ELSE  */
    FOR = 327,                     /* FOR  */
    IN = 328,                      /* IN  */
    TRUE = 329,                    /* TRUE  */
    FALSE = 330,                   /* FALSE  */
    IDENTIFIER = 331,              /* IDENTIFIER  */
    SHARED_IDENTIFIER = 332,       /* SHARED_IDENTIFIER  */
    INT_LITERAL = 333,             /* INT_LITERAL  */
    FLOAT_LITERAL = 334,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 335,          /* STRING_LITERAL  */
    CHARACTER_LITERAL = 336        /* CHARACTER_LITERAL  */
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
#define STRUCT 324
#define IF 325
#define ELSE 326
#define FOR 327
#define IN 328
#define TRUE 329
#define FALSE 330
#define IDENTIFIER 331
#define SHARED_IDENTIFIER 332
#define INT_LITERAL 333
#define FLOAT_LITERAL 334
#define STRING_LITERAL 335
#define CHARACTER_LITERAL 336

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



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
  YYSYMBOL_STRUCT = 69,                    /* STRUCT  */
  YYSYMBOL_IF = 70,                        /* IF  */
  YYSYMBOL_ELSE = 71,                      /* ELSE  */
  YYSYMBOL_FOR = 72,                       /* FOR  */
  YYSYMBOL_IN = 73,                        /* IN  */
  YYSYMBOL_TRUE = 74,                      /* TRUE  */
  YYSYMBOL_FALSE = 75,                     /* FALSE  */
  YYSYMBOL_IDENTIFIER = 76,                /* IDENTIFIER  */
  YYSYMBOL_SHARED_IDENTIFIER = 77,         /* SHARED_IDENTIFIER  */
  YYSYMBOL_INT_LITERAL = 78,               /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 79,             /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 80,            /* STRING_LITERAL  */
  YYSYMBOL_CHARACTER_LITERAL = 81,         /* CHARACTER_LITERAL  */
  YYSYMBOL_YYACCEPT = 82,                  /* $accept  */
  YYSYMBOL_program = 83,                   /* program  */
  YYSYMBOL_statement_list = 84,            /* statement_list  */
  YYSYMBOL_one_or_more_statements = 85,    /* one_or_more_statements  */
  YYSYMBOL_generic_dtypes = 86,            /* generic_dtypes  */
  YYSYMBOL_dtype = 87,                     /* dtype  */
  YYSYMBOL_array = 88,                     /* array  */
  YYSYMBOL_array_element = 89,             /* array_element  */
  YYSYMBOL_dims = 90,                      /* dims  */
  YYSYMBOL_initializer_dims = 91,          /* initializer_dims  */
  YYSYMBOL_statement = 92,                 /* statement  */
  YYSYMBOL_inner_statement = 93,           /* inner_statement  */
  YYSYMBOL_one_or_more_inner_statements = 94, /* one_or_more_inner_statements  */
  YYSYMBOL_inner_statement_list = 95,      /* inner_statement_list  */
  YYSYMBOL_return_statement = 96,          /* return_statement  */
  YYSYMBOL_compound_statement = 97,        /* compound_statement  */
  YYSYMBOL_expression_statement = 98,      /* expression_statement  */
  YYSYMBOL_expression = 99,                /* expression  */
  YYSYMBOL_unary_operator = 100,           /* unary_operator  */
  YYSYMBOL_arithmetic_expression = 101,    /* arithmetic_expression  */
  YYSYMBOL_assignment_expression = 102,    /* assignment_expression  */
  YYSYMBOL_unary_expression = 103,         /* unary_expression  */
  YYSYMBOL_comparison_expression = 104,    /* comparison_expression  */
  YYSYMBOL_logical_expression = 105,       /* logical_expression  */
  YYSYMBOL_declaration_statement = 106,    /* declaration_statement  */
  YYSYMBOL_declaration_list = 107,         /* declaration_list  */
  YYSYMBOL_declaration = 108,              /* declaration  */
  YYSYMBOL_value_assign = 109,             /* value_assign  */
  YYSYMBOL_iterative_statement = 110,      /* iterative_statement  */
  YYSYMBOL_container = 111,                /* container  */
  YYSYMBOL_iterator = 112,                 /* iterator  */
  YYSYMBOL_range = 113,                    /* range  */
  YYSYMBOL_number = 114,                   /* number  */
  YYSYMBOL_selection_statement = 115,      /* selection_statement  */
  YYSYMBOL_if_chain_statement = 116,       /* if_chain_statement  */
  YYSYMBOL_function_declaration = 117,     /* function_declaration  */
  YYSYMBOL_datatype_and_ref = 118,         /* datatype_and_ref  */
  YYSYMBOL_argument_list = 119,            /* argument_list  */
  YYSYMBOL_argument_declaration = 120,     /* argument_declaration  */
  YYSYMBOL_array_arg_dimension = 121,      /* array_arg_dimension  */
  YYSYMBOL_array_arg_dimension_increase = 122, /* array_arg_dimension_increase  */
  YYSYMBOL_parallel_statement = 123,       /* parallel_statement  */
  YYSYMBOL_parallel_stmt_argument_list = 124, /* parallel_stmt_argument_list  */
  YYSYMBOL_parallel_stmt_argument = 125,   /* parallel_stmt_argument  */
  YYSYMBOL_schedule_list = 126,            /* schedule_list  */
  YYSYMBOL_reduction_list = 127,           /* reduction_list  */
  YYSYMBOL_reduction_operator_list = 128,  /* reduction_operator_list  */
  YYSYMBOL_channel_statement = 129,        /* channel_statement  */
  YYSYMBOL_signal_statement = 130,         /* signal_statement  */
  YYSYMBOL_wait_statement = 131,           /* wait_statement  */
  YYSYMBOL_taskgroup_statement = 132,      /* taskgroup_statement  */
  YYSYMBOL_taskgroup_definition = 133,     /* taskgroup_definition  */
  YYSYMBOL_task_declaration_list = 134,    /* task_declaration_list  */
  YYSYMBOL_task_declaration = 135,         /* task_declaration  */
  YYSYMBOL_task_statements = 136,          /* task_statements  */
  YYSYMBOL_one_or_more_task_statements = 137, /* one_or_more_task_statements  */
  YYSYMBOL_task_statement_list = 138,      /* task_statement_list  */
  YYSYMBOL_properties_declaration = 139,   /* properties_declaration  */
  YYSYMBOL_taskgroup_properties = 140,     /* taskgroup_properties  */
  YYSYMBOL_taskgroup_property = 141,       /* taskgroup_property  */
  YYSYMBOL_order_block = 142,              /* order_block  */
  YYSYMBOL_order_rule_list = 143,          /* order_rule_list  */
  YYSYMBOL_order_rule = 144,               /* order_rule  */
  YYSYMBOL_order_rule_start = 145,         /* order_rule_start  */
  YYSYMBOL_order_rule_mid = 146,           /* order_rule_mid  */
  YYSYMBOL_order_rule_end = 147,           /* order_rule_end  */
  YYSYMBOL_identifier_list = 148,          /* identifier_list  */
  YYSYMBOL_shared_block = 149,             /* shared_block  */
  YYSYMBOL_shared_rule_list = 150,         /* shared_rule_list  */
  YYSYMBOL_shared_rule = 151,              /* shared_rule  */
  YYSYMBOL_mem_block = 152,                /* mem_block  */
  YYSYMBOL_mem_statement_list = 153,       /* mem_statement_list  */
  YYSYMBOL_mem_statement = 154,            /* mem_statement  */
  YYSYMBOL_mem_taskgroup_list = 155,       /* mem_taskgroup_list  */
  YYSYMBOL_mem_taskgroup_name = 156,       /* mem_taskgroup_name  */
  YYSYMBOL_array_literal = 157,            /* array_literal  */
  YYSYMBOL_literals = 158,                 /* literals  */
  YYSYMBOL_value = 159                     /* value  */
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
#define YYFINAL  75
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   539

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  78
/* YYNRULES -- Number of rules.  */
#define YYNRULES  191
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  351

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   336


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
      75,    76,    77,    78,    79,    80,    81
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    42,    42,    45,    46,    47,    48,    53,    54,    55,
      56,    57,    58,    59,    63,    64,    68,    72,    77,    78,
      82,    83,    89,    90,    91,    92,    93,    94,    95,    96,
      99,   100,   102,   103,   105,   106,   107,   108,   109,   110,
     111,   115,   118,   125,   126,   133,   134,   135,   136,   137,
     138,   139,   144,   145,   150,   151,   152,   153,   154,   158,
     159,   160,   161,   162,   163,   169,   174,   175,   176,   177,
     178,   179,   183,   184,   189,   192,   193,   197,   198,   201,
     202,   207,   208,   214,   215,   218,   219,   223,   224,   228,
     229,   234,   235,   239,   240,   245,   250,   250,   254,   255,
     258,   259,   262,   263,   266,   267,   273,   274,   276,   277,
     280,   281,   282,   283,   284,   287,   287,   291,   292,   296,
     297,   298,   299,   300,   303,   304,   308,   309,   313,   314,
     316,   317,   320,   321,   325,   326,   329,   330,   334,   335,
     337,   338,   340,   341,   342,   343,   344,   345,   346,   350,
     351,   356,   357,   361,   362,   363,   367,   372,   373,   377,
     382,   383,   387,   388,   392,   393,   397,   398,   402,   407,
     408,   412,   418,   419,   425,   426,   431,   436,   437,   442,
     443,   448,   452,   452,   452,   452,   452,   452,   452,   455,
     456,   457
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
  "BOOL", "FLOAT", "STRING", "FUNC", "RETURN", "STRUCT", "IF", "ELSE",
  "FOR", "IN", "TRUE", "FALSE", "IDENTIFIER", "SHARED_IDENTIFIER",
  "INT_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL", "CHARACTER_LITERAL",
  "$accept", "program", "statement_list", "one_or_more_statements",
  "generic_dtypes", "dtype", "array", "array_element", "dims",
  "initializer_dims", "statement", "inner_statement",
  "one_or_more_inner_statements", "inner_statement_list",
  "return_statement", "compound_statement", "expression_statement",
  "expression", "unary_operator", "arithmetic_expression",
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
  "taskgroup_definition", "task_declaration_list", "task_declaration",
  "task_statements", "one_or_more_task_statements", "task_statement_list",
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

#define YYPACT_NINF (-288)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-91)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     118,  -288,  -288,  -288,    36,   284,   -58,     1,  -288,  -288,
    -288,  -288,  -288,  -288,   -29,   -25,    38,   -11,  -288,  -288,
     105,   209,  -288,  -288,  -288,   122,  -288,   118,   113,   -14,
    -288,  -288,  -288,  -288,  -288,   435,    58,  -288,  -288,  -288,
    -288,  -288,  -288,  -288,   225,  -288,  -288,  -288,  -288,  -288,
    -288,  -288,   363,    36,   130,   284,  -288,  -288,  -288,  -288,
    -288,  -288,  -288,  -288,    96,    46,   439,  -288,    36,   128,
      92,  -288,   100,    58,   139,  -288,  -288,   168,   152,   229,
      21,  -288,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      36,  -288,  -288,  -288,  -288,  -288,  -288,    58,  -288,   456,
    -288,  -288,   184,    -9,   237,   241,   260,   263,   266,    93,
    -288,   251,   387,   128,  -288,    68,   244,    58,    58,  -288,
     280,    36,  -288,  -288,   -14,   477,   142,   142,  -288,  -288,
    -288,   151,   151,   218,   218,   218,   218,   206,   242,   477,
     477,   477,   477,   477,  -288,  -288,   275,   211,   217,   268,
     163,  -288,   272,   273,   203,   230,   283,   -16,    46,   439,
     299,    36,   305,   299,  -288,  -288,   307,    45,   236,   477,
    -288,   257,   309,   310,   317,   313,  -288,  -288,   267,   267,
    -288,  -288,  -288,  -288,   298,  -288,  -288,  -288,   316,   279,
     111,  -288,   286,   411,  -288,  -288,    58,  -288,   318,   216,
     216,  -288,   197,  -288,   146,   158,   337,   356,   362,   364,
     380,    22,  -288,  -288,   243,   299,   439,    43,  -288,   299,
     359,   381,   382,   365,  -288,  -288,  -288,  -288,  -288,  -288,
    -288,   405,   412,   404,   216,  -288,   406,   423,   -10,   444,
      90,  -288,  -288,  -288,  -288,  -288,   418,  -288,   267,   267,
     267,   267,   267,   298,  -288,    58,  -288,  -288,   247,  -288,
    -288,  -288,  -288,  -288,  -288,    -9,   430,    36,  -288,  -288,
    -288,  -288,  -288,   464,   267,   480,   434,  -288,  -288,  -288,
     481,   481,   481,   481,   481,  -288,  -288,    58,  -288,   483,
     484,   477,   460,    -3,  -288,   267,    24,    -8,  -288,   267,
     490,    -7,  -288,  -288,   493,    36,  -288,  -288,  -288,    19,
     481,   441,  -288,  -288,    -5,   439,  -288,  -288,  -288,   311,
    -288,   -28,  -288,   458,    23,  -288,  -288,   468,   469,   498,
     481,  -288,  -288,   441,   267,   446,  -288,  -288,    95,  -288,
    -288
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    52,    53,    44,     0,    31,     0,     0,     7,    12,
       8,    11,     9,    10,     0,     0,     0,     0,   186,   187,
     190,   182,   183,   184,   185,     0,     2,     3,    14,     0,
      15,   191,     6,    25,    24,     0,     0,    48,    47,    51,
      50,    49,    28,    22,     0,    23,    26,    29,    27,   188,
     189,    45,     0,     0,     0,    30,    33,    40,    37,    36,
      38,    34,    35,    39,     0,     0,     0,    13,     0,     0,
       0,    85,     0,     0,    17,     1,     5,    21,     0,    80,
       0,    76,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    43,    90,    89,    65,    87,    88,     0,    46,     0,
      42,    32,     0,   133,     0,     0,     0,     0,     0,     0,
     109,     0,     0,     0,    86,     0,     0,     0,     0,    16,
       0,     0,    78,    74,     0,    59,    54,    55,    56,    57,
      58,    70,    71,    67,    66,    68,    69,    72,    73,    60,
      61,    62,    63,    64,   181,    41,     0,     0,     0,     0,
     150,   135,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    90,     0,    84,    19,     0,     0,     0,    79,
      75,     0,     0,     0,     0,     0,   134,   132,     0,     0,
     116,   115,   113,   114,     0,   106,   107,   108,    96,     0,
       0,    98,    94,     0,    82,    18,     0,    77,     0,   139,
     139,   131,     0,   167,     0,     0,     0,     0,     0,     0,
       0,     0,   118,    97,   100,     0,     0,     0,    91,     0,
       0,     0,     0,   126,   145,   144,   146,   142,   143,   147,
     148,     0,     0,     0,   138,   141,     0,     0,     0,     0,
       0,   152,   153,   154,   155,   111,     0,   110,     0,     0,
       0,     0,     0,     0,   112,     0,   103,   101,     0,    95,
      99,    92,    93,    81,    20,   133,     0,     0,   124,   125,
     136,   140,   137,   161,     0,     0,     0,   149,   151,   166,
     119,   120,   121,   122,   123,   117,   105,     0,   102,     0,
       0,   127,     0,   161,   158,     0,     0,     0,   175,     0,
       0,     0,   170,   104,     0,     0,   160,   156,   157,     0,
     163,     0,   172,   174,     0,     0,   168,   169,   130,     0,
     165,     0,   159,   179,     0,   178,   173,     0,   128,     0,
     162,   180,   176,     0,     0,     0,   164,   177,     0,   129,
     171
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -288,  -288,  -288,  -288,  -288,   -65,  -288,  -288,   495,  -288,
     497,  -288,  -288,   470,  -288,     2,     5,    -4,  -288,  -288,
    -288,  -288,  -288,  -288,    11,  -288,   392,  -288,     4,  -288,
    -288,  -288,   -30,     3,  -288,  -288,  -288,  -288,   301,  -288,
    -288,    12,  -288,   360,  -288,  -288,   269,  -288,  -288,  -288,
    -288,   254,  -288,   370,   321,  -288,   289,  -288,  -288,   285,
    -288,  -288,   231,  -288,  -288,  -288,  -153,  -288,  -288,   226,
    -288,   227,  -287,  -288,   195,   414,  -288,  -288
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    25,    26,    27,    28,    29,    30,    31,    74,   129,
      32,    54,    55,    56,    57,   234,   235,    35,    36,    37,
      38,    39,    40,    41,   236,    80,    81,   132,   237,   173,
      72,   107,    44,   238,   228,    46,   199,   200,   201,   267,
     268,   239,   119,   120,   192,   221,   222,   240,   241,   242,
      48,   159,   160,   161,   243,   244,   245,   187,   250,   251,
     252,   303,   304,   305,   319,   332,   306,   253,   311,   312,
     254,   307,   308,   334,   335,    49,    50,    51
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,   121,    33,    45,    43,    34,   104,    58,    62,    61,
      59,    42,    47,     5,    69,   339,    60,    63,    64,   284,
     323,    78,   322,   326,    70,   336,    65,   317,   157,    33,
      45,    43,    34,   158,   285,   214,   215,   323,    42,    47,
     302,     1,   330,   126,   133,   263,   342,    66,   213,   109,
     264,    67,   134,     2,   343,   256,    17,    58,    62,    61,
      59,     4,    79,    68,   122,    71,    60,    63,   213,   310,
     331,   213,     5,   205,   123,   321,   206,   154,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   176,   177,   114,
     115,   116,   117,   118,   198,   290,   291,   292,   293,   294,
      18,    19,    20,    16,    21,    22,    23,    24,   350,   167,
     287,   112,    75,     1,   168,   113,   256,   179,   171,   247,
     248,   249,    73,     1,   102,     2,   103,   225,   -90,   -90,
      73,     3,   226,     4,   172,     2,   103,     5,    85,    86,
      87,     3,   320,     4,     6,    83,    84,    85,    86,    87,
     110,   198,    90,    91,    92,    93,   127,   203,   124,   195,
       7,   196,   202,   125,   255,   204,   230,   256,   340,     8,
       9,    10,    11,    12,    13,    14,   257,    15,    16,   256,
      17,   348,    18,    19,    20,   128,    21,    22,    23,    24,
     157,   185,    18,    19,    20,   158,    21,    22,    23,    24,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,     1,    83,    84,    85,    86,    87,   269,   130,   271,
     272,   273,   131,     2,   156,   296,   247,   248,   249,     3,
     162,     4,   -89,   -89,   163,     5,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,   105,   106,
     337,   190,   191,   164,   232,   233,   165,   313,     7,   166,
     265,   266,   175,   301,   297,   298,   169,     8,     9,    10,
      11,    12,    13,   178,   181,    15,    16,   182,    17,     1,
      18,    19,    20,   183,    21,    22,    23,    24,   184,   188,
     189,     2,   216,   217,   218,   219,   220,     3,   193,     4,
     194,   329,   207,     5,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,     5,    96,
      97,    98,    99,   100,   -83,   205,     7,   208,   209,   210,
     211,   338,   212,   213,   231,     8,     9,    10,    11,    12,
      13,   223,    53,    15,    16,   224,    17,   227,    18,    19,
      20,   258,    21,    22,    23,    24,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
     259,    96,    97,    98,    99,   100,   260,   274,   261,   108,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   262,    96,    97,    98,    99,   100,
     275,   276,   277,   170,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,   278,    96,
      97,    98,    99,   100,   280,   279,   282,   229,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,   283,    96,    97,    98,    99,   100,   101,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,   286,    96,    97,    98,    99,   100,   155,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,   289,    96,    97,    98,    99,   100,
       8,     9,    10,    11,    12,    13,   300,   302,    15,   309,
     310,   316,   256,   314,   325,   315,   328,   333,   341,   344,
     345,   346,   349,    77,    76,   111,   180,   270,   197,   299,
     186,   246,   295,   281,   318,   288,   324,   327,   347,   174
};

static const yytype_int16 yycheck[] =
{
       4,    66,     0,     0,     0,     0,    36,     5,     5,     5,
       5,     0,     0,    29,    25,    43,     5,     5,    76,    29,
     307,    35,    30,    30,    35,    30,    25,    30,    37,    27,
      27,    27,    27,    42,    44,   188,   189,   324,    27,    27,
      43,     5,    23,    73,    23,    23,    23,    76,    76,    53,
      28,    76,    31,    17,    31,    31,    72,    55,    55,    55,
      55,    25,    76,    25,    68,    76,    55,    55,    76,    76,
      51,    76,    29,    28,    69,    51,    31,   107,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   127,   128,    53,
      54,    55,    56,    57,   169,   258,   259,   260,   261,   262,
      74,    75,    76,    70,    78,    79,    80,    81,    23,    26,
      30,    25,     0,     5,    31,    29,    31,   131,   123,    39,
      40,    41,    27,     5,    76,    17,    78,    26,    33,    34,
      27,    23,    31,    25,    76,    17,    78,    29,     6,     7,
       8,    23,   305,    25,    36,     4,     5,     6,     7,     8,
      30,   226,    11,    12,    13,    14,    27,   171,    76,   167,
      52,   167,   170,    73,    28,   173,   206,    31,   331,    61,
      62,    63,    64,    65,    66,    67,    28,    69,    70,    31,
      72,   344,    74,    75,    76,    27,    78,    79,    80,    81,
      37,    38,    74,    75,    76,    42,    78,    79,    80,    81,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,     5,     4,     5,     6,     7,     8,   225,    76,   227,
     227,   229,     3,    17,    50,   265,    39,    40,    41,    23,
       3,    25,    33,    34,     3,    29,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    33,    34,
     325,    58,    59,     3,    48,    49,     3,   297,    52,     3,
      27,    28,    28,   277,    27,    28,    25,    61,    62,    63,
      64,    65,    66,     3,     9,    69,    70,    76,    72,     5,
      74,    75,    76,    76,    78,    79,    80,    81,    30,    27,
      27,    17,     4,     5,     6,     7,     8,    23,    78,    25,
      27,   315,    76,    29,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    29,    18,
      19,    20,    21,    22,    29,    28,    52,    80,    29,    29,
      23,    30,    29,    76,    26,    61,    62,    63,    64,    65,
      66,    35,    68,    69,    70,    76,    72,    71,    74,    75,
      76,    24,    78,    79,    80,    81,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      24,    18,    19,    20,    21,    22,    24,    28,    24,    26,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    24,    18,    19,    20,    21,    22,
      29,    29,    47,    26,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    23,    18,
      19,    20,    21,    22,    30,    23,    30,    26,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    29,    18,    19,    20,    21,    22,    23,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    29,    18,    19,    20,    21,    22,    23,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    76,    18,    19,    20,    21,    22,
      61,    62,    63,    64,    65,    66,    76,    43,    69,    29,
      76,    51,    31,    30,    24,    31,    23,    76,    60,    51,
      51,    23,    76,    28,    27,    55,   134,   226,   168,   275,
     160,   210,   263,   244,   303,   250,   309,   311,   343,   125
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    17,    23,    25,    29,    36,    52,    61,    62,
      63,    64,    65,    66,    67,    69,    70,    72,    74,    75,
      76,    78,    79,    80,    81,    83,    84,    85,    86,    87,
      88,    89,    92,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   110,   114,   115,   117,   123,   132,   157,
     158,   159,    99,    68,    93,    94,    95,    96,    97,    98,
     106,   110,   115,   123,    76,    25,    76,    76,    25,    25,
      35,    76,   112,    27,    90,     0,    92,    90,    35,    76,
     107,   108,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    18,    19,    20,    21,
      22,    23,    76,    78,   114,    33,    34,   113,    26,    99,
      30,    95,    25,    29,    53,    54,    55,    56,    57,   124,
     125,    87,    99,    98,    76,    73,   114,    27,    27,    91,
      76,     3,   109,    23,    31,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,   114,    23,    50,    37,    42,   133,
     134,   135,     3,     3,     3,     3,     3,    26,    31,    25,
      26,    98,    76,   111,   157,    28,   114,   114,     3,    99,
     108,     9,    76,    76,    30,    38,   135,   139,    27,    27,
      58,    59,   126,    78,    27,    97,   110,   125,    87,   118,
     119,   120,    97,    99,    97,    28,    31,    76,    80,    29,
      29,    23,    29,    76,   148,   148,     4,     5,     6,     7,
       8,   127,   128,    35,    76,    26,    31,    71,   116,    26,
     114,    26,    48,    49,    97,    98,   106,   110,   115,   123,
     129,   130,   131,   136,   137,   138,   136,    39,    40,    41,
     140,   141,   142,   149,   152,    28,    31,    28,    24,    24,
      24,    24,    24,    23,    28,    27,    28,   121,   122,    97,
     120,    97,   115,    97,    28,    29,    29,    47,    23,    23,
      30,   138,    30,    29,    29,    44,    29,    30,   141,    76,
     148,   148,   148,   148,   148,   128,   114,    27,    28,   133,
      76,    99,    43,   143,   144,   145,   148,   153,   154,    29,
      76,   150,   151,   114,    30,    31,    51,    30,   144,   146,
     148,    51,    30,   154,   153,    24,    30,   151,    23,    99,
      23,    51,   147,    76,   155,   156,    30,    87,    30,    43,
     148,    60,    23,    31,    51,    51,    23,   156,   148,    76,
      23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    84,    85,    85,    86,    86,    86,
      86,    86,    86,    86,    87,    87,    88,    89,    90,    90,
      91,    91,    92,    92,    92,    92,    92,    92,    92,    92,
      93,    93,    94,    94,    95,    95,    95,    95,    95,    95,
      95,    96,    97,    98,    98,    99,    99,    99,    99,    99,
      99,    99,   100,   100,   101,   101,   101,   101,   101,   102,
     102,   102,   102,   102,   102,   103,   104,   104,   104,   104,
     104,   104,   105,   105,   106,   107,   107,   108,   108,   109,
     109,   110,   110,   111,   111,   112,   112,   113,   113,   114,
     114,   115,   115,   116,   116,   117,   118,   118,   119,   119,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   125,   125,   125,   126,   126,   127,   127,   128,
     128,   128,   128,   128,   129,   129,   130,   130,   131,   131,
     132,   132,   133,   133,   134,   134,   135,   135,   136,   136,
     137,   137,   138,   138,   138,   138,   138,   138,   138,   139,
     139,   140,   140,   141,   141,   141,   142,   143,   143,   144,
     145,   145,   146,   146,   147,   147,   148,   148,   149,   150,
     150,   151,   152,   152,   153,   153,   154,   155,   155,   156,
     156,   157,   158,   158,   158,   158,   158,   158,   158,   159,
     159,   159
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     3,     2,     4,     3,
       5,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     2,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     4,     2,     2,
       0,     7,     5,     1,     1,     1,     2,     1,     1,     1,
       1,     6,     7,     2,     0,     7,     1,     2,     1,     3,
       2,     3,     2,     1,     3,     2,     5,     5,     3,     1,
       5,     5,     5,     3,     3,     1,     1,     3,     1,     3,
       3,     3,     3,     3,     2,     2,     1,     3,     6,     8,
      11,     6,     2,     0,     2,     1,     5,     5,     1,     0,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       0,     2,     1,     1,     1,     1,     4,     2,     1,     3,
       2,     0,     3,     1,     3,     1,     3,     1,     4,     2,
       1,     6,     4,     5,     2,     1,     4,     3,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1
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
#line 1733 "y.tab.c"
    break;


#line 1737 "y.tab.c"

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

#line 463 "parser.y"

int main(void) {
	yyparse();
}

