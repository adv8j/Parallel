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
  YYSYMBOL_generic_dtypes = 85,            /* generic_dtypes  */
  YYSYMBOL_dtype = 86,                     /* dtype  */
  YYSYMBOL_array = 87,                     /* array  */
  YYSYMBOL_array_element = 88,             /* array_element  */
  YYSYMBOL_dims = 89,                      /* dims  */
  YYSYMBOL_initializer_dims = 90,          /* initializer_dims  */
  YYSYMBOL_statement = 91,                 /* statement  */
  YYSYMBOL_inner_statement = 92,           /* inner_statement  */
  YYSYMBOL_return_statement = 93,          /* return_statement  */
  YYSYMBOL_compound_statement = 94,        /* compound_statement  */
  YYSYMBOL_expression_statement = 95,      /* expression_statement  */
  YYSYMBOL_expression = 96,                /* expression  */
  YYSYMBOL_unary_operator = 97,            /* unary_operator  */
  YYSYMBOL_arithmetic_expression = 98,     /* arithmetic_expression  */
  YYSYMBOL_assignment_expression = 99,     /* assignment_expression  */
  YYSYMBOL_unary_expression = 100,         /* unary_expression  */
  YYSYMBOL_comparison_expression = 101,    /* comparison_expression  */
  YYSYMBOL_logical_expression = 102,       /* logical_expression  */
  YYSYMBOL_declaration_statement = 103,    /* declaration_statement  */
  YYSYMBOL_declaration_list = 104,         /* declaration_list  */
  YYSYMBOL_declaration = 105,              /* declaration  */
  YYSYMBOL_value_assign = 106,             /* value_assign  */
  YYSYMBOL_iterative_statement = 107,      /* iterative_statement  */
  YYSYMBOL_container = 108,                /* container  */
  YYSYMBOL_iterator = 109,                 /* iterator  */
  YYSYMBOL_range = 110,                    /* range  */
  YYSYMBOL_number = 111,                   /* number  */
  YYSYMBOL_selection_statement = 112,      /* selection_statement  */
  YYSYMBOL_if_chain_statement = 113,       /* if_chain_statement  */
  YYSYMBOL_selection_expression = 114,     /* selection_expression  */
  YYSYMBOL_function_declaration = 115,     /* function_declaration  */
  YYSYMBOL_datatype_and_ref = 116,         /* datatype_and_ref  */
  YYSYMBOL_argument_list = 117,            /* argument_list  */
  YYSYMBOL_argument_declaration = 118,     /* argument_declaration  */
  YYSYMBOL_array_arg_dimension = 119,      /* array_arg_dimension  */
  YYSYMBOL_array_arg_dimension_increase = 120, /* array_arg_dimension_increase  */
  YYSYMBOL_parallel_statement = 121,       /* parallel_statement  */
  YYSYMBOL_parallel_stmt_argument_list = 122, /* parallel_stmt_argument_list  */
  YYSYMBOL_parallel_stmt_argument = 123,   /* parallel_stmt_argument  */
  YYSYMBOL_schedule_list = 124,            /* schedule_list  */
  YYSYMBOL_reduction_list = 125,           /* reduction_list  */
  YYSYMBOL_reduction_operator_list = 126,  /* reduction_operator_list  */
  YYSYMBOL_channel_statement = 127,        /* channel_statement  */
  YYSYMBOL_signal_statement = 128,         /* signal_statement  */
  YYSYMBOL_wait_statement = 129,           /* wait_statement  */
  YYSYMBOL_taskgroup_statement = 130,      /* taskgroup_statement  */
  YYSYMBOL_taskgroup_definition = 131,     /* taskgroup_definition  */
  YYSYMBOL_task_declaration_list = 132,    /* task_declaration_list  */
  YYSYMBOL_task_declaration = 133,         /* task_declaration  */
  YYSYMBOL_task_statements = 134,          /* task_statements  */
  YYSYMBOL_properties_declaration = 135,   /* properties_declaration  */
  YYSYMBOL_taskgroup_properties = 136,     /* taskgroup_properties  */
  YYSYMBOL_taskgroup_property = 137,       /* taskgroup_property  */
  YYSYMBOL_order_block = 138,              /* order_block  */
  YYSYMBOL_order_rule_list = 139,          /* order_rule_list  */
  YYSYMBOL_order_rule = 140,               /* order_rule  */
  YYSYMBOL_order_rule_start = 141,         /* order_rule_start  */
  YYSYMBOL_order_rule_mid = 142,           /* order_rule_mid  */
  YYSYMBOL_order_rule_end = 143,           /* order_rule_end  */
  YYSYMBOL_identifier_list = 144,          /* identifier_list  */
  YYSYMBOL_shared_block = 145,             /* shared_block  */
  YYSYMBOL_shared_rule_list = 146,         /* shared_rule_list  */
  YYSYMBOL_shared_rule = 147,              /* shared_rule  */
  YYSYMBOL_mem_block = 148,                /* mem_block  */
  YYSYMBOL_mem_statement_list = 149,       /* mem_statement_list  */
  YYSYMBOL_mem_statement = 150,            /* mem_statement  */
  YYSYMBOL_mem_taskgroup_list = 151,       /* mem_taskgroup_list  */
  YYSYMBOL_mem_taskgroup_name = 152,       /* mem_taskgroup_name  */
  YYSYMBOL_array_literal = 153,            /* array_literal  */
  YYSYMBOL_literals = 154,                 /* literals  */
  YYSYMBOL_value = 155                     /* value  */
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
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   606

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  198
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  376
#define YYNSTATES  376

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
       0,    42,    42,    45,    46,    51,    52,    53,    54,    55,
      56,    57,    61,    62,    66,    70,    75,    76,    80,    81,
      87,    88,    89,    90,    91,    92,    93,    94,    98,    99,
     100,   101,   102,   103,   104,   105,   109,   112,   119,   120,
     127,   128,   129,   130,   131,   132,   133,   138,   139,   144,
     145,   146,   147,   148,   152,   153,   154,   155,   156,   157,
     163,   168,   169,   170,   171,   172,   173,   177,   178,   183,
     186,   187,   191,   192,   195,   196,   201,   202,   208,   209,
     212,   213,   217,   218,   222,   223,   228,   229,   233,   234,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   257,   262,   262,   266,
     267,   270,   271,   274,   275,   278,   279,   285,   286,   288,
     289,   292,   293,   294,   295,   296,   299,   299,   303,   304,
     308,   309,   310,   311,   312,   315,   316,   320,   321,   325,
     326,   328,   329,   332,   333,   337,   338,   341,   342,   347,
     348,   349,   350,   351,   352,   353,   357,   358,   363,   364,
     368,   369,   370,   374,   379,   380,   384,   389,   390,   394,
     395,   399,   400,   404,   405,   409,   414,   415,   419,   425,
     426,   432,   433,   438,   443,   444,   449,   450,   455,   459,
     459,   459,   459,   459,   459,   459,   462,   463,   464
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
  "$accept", "program", "statement_list", "generic_dtypes", "dtype",
  "array", "array_element", "dims", "initializer_dims", "statement",
  "inner_statement", "return_statement", "compound_statement",
  "expression_statement", "expression", "unary_operator",
  "arithmetic_expression", "assignment_expression", "unary_expression",
  "comparison_expression", "logical_expression", "declaration_statement",
  "declaration_list", "declaration", "value_assign", "iterative_statement",
  "container", "iterator", "range", "number", "selection_statement",
  "if_chain_statement", "selection_expression", "function_declaration",
  "datatype_and_ref", "argument_list", "argument_declaration",
  "array_arg_dimension", "array_arg_dimension_increase",
  "parallel_statement", "parallel_stmt_argument_list",
  "parallel_stmt_argument", "schedule_list", "reduction_list",
  "reduction_operator_list", "channel_statement", "signal_statement",
  "wait_statement", "taskgroup_statement", "taskgroup_definition",
  "task_declaration_list", "task_declaration", "task_statements",
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

#define YYPACT_NINF (-308)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-86)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     141,  -308,  -308,  -308,     9,   267,   -45,    40,  -308,  -308,
    -308,  -308,  -308,  -308,    49,    81,    47,   -14,  -308,  -308,
      34,   116,  -308,  -308,  -308,    82,   141,   149,   -18,  -308,
    -308,  -308,  -308,  -308,   456,   107,  -308,  -308,  -308,  -308,
    -308,  -308,  -308,   138,  -308,  -308,  -308,  -308,  -308,  -308,
    -308,   362,     9,   135,  -308,  -308,  -308,  -308,  -308,  -308,
    -308,    14,    54,   196,  -308,   150,    -1,   106,  -308,   128,
     107,   182,  -308,  -308,   185,   142,   211,    13,  -308,     9,
       9,     9,     9,     9,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,     9,     9,     9,     9,  -308,  -308,
    -308,  -308,  -308,  -308,   107,  -308,   477,  -308,   173,    39,
     224,   229,   233,   240,   250,    67,  -308,   239,   150,   150,
     409,  -308,    -1,  -308,   122,   221,   107,   107,  -308,   276,
     202,  -308,  -308,   -18,   498,   172,   172,  -308,  -308,  -308,
     148,   148,   422,   422,   422,   422,   541,   517,   498,   498,
     498,   498,   498,  -308,  -308,   261,   213,   217,   274,    -5,
    -308,   264,   270,   215,   228,   290,   -17,    54,   196,  -308,
     432,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   294,     9,   305,   294,  -308,  -308,
     310,    22,   268,  -308,  -308,   269,   311,   321,   328,   350,
    -308,  -308,   309,   309,  -308,  -308,  -308,  -308,   445,  -308,
    -308,  -308,   351,   327,    68,  -308,  -308,   260,   260,  -308,
    -308,  -308,   183,   183,   563,   563,   563,   563,   552,   529,
     316,   386,  -308,  -308,   107,  -308,   383,   246,   246,  -308,
     262,  -308,    35,   120,   387,   407,   408,   410,   430,   146,
    -308,  -308,   258,   294,   196,    -6,  -308,   294,   382,   404,
     426,   447,  -308,  -308,  -308,  -308,  -308,  -308,  -308,   433,
     434,   443,   485,   543,     1,   544,    56,  -308,  -308,  -308,
    -308,  -308,   499,  -308,   309,   309,   309,   309,   309,   445,
    -308,   107,  -308,  -308,   286,  -308,  -308,  -308,  -308,  -308,
    -308,    39,   500,   202,  -308,  -308,  -308,  -308,   531,   309,
     548,   502,  -308,  -308,  -308,   549,   549,   549,   549,   549,
    -308,  -308,   107,  -308,   551,   553,  -308,   528,    -2,  -308,
     309,    -4,   -27,  -308,   309,   558,   -22,  -308,  -308,   560,
     107,  -308,  -308,  -308,     6,   549,   509,  -308,  -308,   -20,
     196,  -308,  -308,  -308,   556,  -308,   -25,  -308,   527,    15,
    -308,  -308,   537,   538,   567,   549,  -308,  -308,   509,   309,
     515,  -308,  -308,    17,  -308,  -308
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    47,    48,    39,     0,    35,     0,     0,     5,    10,
       6,     9,     7,     8,     0,     0,     0,     0,   193,   194,
     197,   189,   190,   191,   192,     0,     2,    12,     0,    13,
     198,     4,    23,    22,     0,     0,    43,    42,    46,    45,
      44,    26,    20,     0,    21,    24,    27,    25,   195,   196,
      40,     0,     0,     0,    34,    31,    30,    32,    28,    29,
      33,     0,     0,     0,    11,     0,     0,     0,    80,     0,
       0,    15,     1,     3,    19,     0,    75,     0,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    85,
      84,    60,    82,    83,     0,    41,     0,    37,     0,   144,
       0,     0,     0,     0,     0,     0,   120,     0,     0,     0,
       0,   105,     0,    81,     0,     0,     0,     0,    14,     0,
       0,    73,    69,     0,    54,    49,    50,    51,    52,    53,
      65,    66,    62,    61,    63,    64,    67,    68,    55,    56,
      57,    58,    59,   188,    36,     0,     0,     0,     0,   157,
     146,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,     0,    79,    17,
       0,     0,     0,    74,    70,     0,     0,     0,     0,     0,
     145,   143,     0,     0,   127,   126,   124,   125,     0,   117,
     118,   119,   107,     0,     0,   109,    92,    93,    94,    95,
      96,    97,   102,   103,    99,    98,   100,   101,    91,    90,
      89,     0,    77,    16,     0,    72,     0,     0,     0,   142,
       0,   174,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   108,   111,     0,     0,     0,    86,     0,     0,     0,
       0,   137,   152,   151,   153,   149,   150,   154,   155,     0,
       0,     0,     0,     0,     0,     0,     0,   159,   160,   161,
     162,   122,     0,   121,     0,     0,     0,     0,     0,     0,
     123,     0,   114,   112,     0,   106,   110,    87,    88,    76,
      18,   144,     0,     0,   135,   136,   147,   148,   168,     0,
       0,     0,   156,   158,   173,   130,   131,   132,   133,   134,
     128,   116,     0,   113,     0,     0,   138,     0,   168,   165,
       0,     0,     0,   182,     0,     0,     0,   177,   115,     0,
       0,   167,   163,   164,     0,   170,     0,   179,   181,     0,
       0,   175,   176,   141,     0,   172,     0,   166,   186,     0,
     185,   180,     0,   139,     0,   169,   187,   183,     0,     0,
       0,   171,   184,     0,   140,   178
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -308,  -308,  -308,  -308,   -62,  -308,  -308,   565,  -308,   568,
    -308,  -308,    -3,     4,    48,  -308,  -308,  -308,  -308,  -308,
    -308,     8,  -308,   460,  -308,     2,  -308,  -308,  -308,   -35,
       0,  -308,   181,  -308,  -308,  -308,   341,  -308,  -308,    10,
    -308,   429,  -308,  -308,   308,  -308,  -308,  -308,  -308,   297,
    -308,   440,   363,  -308,  -308,   324,  -308,  -308,   275,  -308,
    -308,  -308,  -183,  -308,  -308,   266,  -308,   271,  -307,  -308,
     236,   482,  -308,   -59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    25,    26,    27,    28,    29,    30,    71,   128,    31,
      53,    54,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    77,    78,   131,    42,   187,    69,   104,    43,
      44,   256,   120,    45,   213,   214,   215,   293,   294,    46,
     115,   116,   206,   249,   250,   268,   269,   270,    47,   158,
     159,   160,   271,   201,   276,   277,   278,   328,   329,   330,
     344,   357,   331,   279,   336,   337,   280,   332,   333,   359,
     360,    48,    49,    50
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     101,   117,    55,   347,     1,    59,   121,    58,   351,    56,
     361,    66,     5,    57,     1,    60,     2,    75,   364,   242,
     243,    67,     3,     5,     4,   348,     2,   282,   342,   355,
     309,    61,   156,   199,     4,   125,   132,   157,   367,   108,
     375,   327,   348,   109,   133,   310,   368,   346,   282,   241,
     233,   241,    51,   234,   335,    17,   241,   356,    76,   121,
     121,    70,    68,   281,    16,    62,   282,   -85,   -85,   153,
     122,   193,    65,    18,    19,    20,   156,    21,    22,    23,
      24,   157,    72,    18,    19,    20,   312,    21,    22,    23,
      24,   190,   191,   166,   253,   273,   274,   275,   167,   254,
     106,   315,   316,   317,   318,   319,   212,   110,   111,   112,
     113,   114,   121,   121,   121,   121,   121,   121,   121,   121,
     121,   121,   121,   121,   121,    63,   185,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,     1,   345,   283,   -84,
     -84,   282,    80,    81,    82,    83,    84,    64,     2,    87,
      88,    89,    90,   209,     3,   107,     4,   118,   210,   289,
       5,   102,   103,   365,   290,   119,    70,     6,    82,    83,
      84,   230,   123,    99,   232,   100,   373,   171,   172,   173,
     174,   175,   212,     7,   178,   179,   180,   181,   186,   258,
     100,   124,     8,     9,    10,    11,    12,    13,    14,   126,
      15,    16,   127,    17,   130,    18,    19,    20,   129,    21,
      22,    23,    24,   155,    18,    19,    20,   161,    21,    22,
      23,    24,   162,   231,   262,   262,   163,   266,   266,   265,
     265,   263,   263,   164,   326,   264,   264,   267,   267,   189,
     295,     1,   297,   165,   299,   298,   321,     8,     9,    10,
      11,    12,    13,     2,   168,    15,   173,   174,   175,     3,
     195,     4,     1,   204,   205,     5,    18,    19,    20,   192,
      21,    22,    23,    24,     2,   291,   292,   338,   362,   196,
       3,   202,     4,   197,   260,   261,     5,   203,     7,   169,
     170,   273,   274,   275,   198,   354,   207,     8,     9,    10,
      11,    12,    13,   322,   323,    15,    16,   208,    17,     7,
      18,    19,    20,     5,    21,    22,    23,    24,     8,     9,
      10,    11,    12,    13,   -78,    52,    15,    16,   233,    17,
     237,    18,    19,    20,   235,    21,    22,    23,    24,   236,
     238,   239,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,   240,
      93,    94,    95,    96,    97,   241,   251,   255,   105,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,   252,    93,    94,    95,    96,    97,   259,
     300,   284,   257,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,    80,    81,    82,    83,
      84,   285,   286,   301,   287,   184,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   244,
     245,   246,   247,   248,   288,   302,   304,   305,   216,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    92,   306,    93,    94,    95,    96,    97,    98,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,   303,    93,    94,    95,    96,    97,
     154,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,   307,    93,    94,    95,    96,
      97,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   171,   172,   173,
     174,   175,   308,   311,   327,   314,   325,   334,   335,   341,
     282,   339,   350,   353,   340,   358,   363,   366,   369,   370,
     371,   374,    74,   194,    73,   296,   211,   320,   324,   200,
     313,   272,   352,   343,   372,   349,   188
};

static const yytype_int16 yycheck[] =
{
      35,    63,     5,    30,     5,     5,    65,     5,    30,     5,
      30,    25,    29,     5,     5,     5,    17,    35,    43,   202,
     203,    35,    23,    29,    25,   332,    17,    31,    30,    23,
      29,    76,    37,    38,    25,    70,    23,    42,    23,    25,
      23,    43,   349,    29,    31,    44,    31,    51,    31,    76,
      28,    76,     4,    31,    76,    72,    76,    51,    76,   118,
     119,    27,    76,    28,    70,    25,    31,    33,    34,   104,
      66,   130,    25,    74,    75,    76,    37,    78,    79,    80,
      81,    42,     0,    74,    75,    76,    30,    78,    79,    80,
      81,   126,   127,    26,    26,    39,    40,    41,    31,    31,
      52,   284,   285,   286,   287,   288,   168,    53,    54,    55,
      56,    57,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,    76,   122,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,     5,   330,    28,    33,
      34,    31,     4,     5,     6,     7,     8,    76,    17,    11,
      12,    13,    14,   166,    23,    30,    25,    17,   166,    23,
      29,    33,    34,   356,    28,    25,    27,    36,     6,     7,
       8,   184,    76,    76,   187,    78,   369,     4,     5,     6,
       7,     8,   254,    52,    11,    12,    13,    14,    76,   234,
      78,    73,    61,    62,    63,    64,    65,    66,    67,    27,
      69,    70,    27,    72,     3,    74,    75,    76,    76,    78,
      79,    80,    81,    50,    74,    75,    76,     3,    78,    79,
      80,    81,     3,   185,   237,   238,     3,   237,   238,   237,
     238,   237,   238,     3,   303,   237,   238,   237,   238,    28,
     253,     5,   255,     3,   257,   255,   291,    61,    62,    63,
      64,    65,    66,    17,    25,    69,     6,     7,     8,    23,
       9,    25,     5,    58,    59,    29,    74,    75,    76,     3,
      78,    79,    80,    81,    17,    27,    28,   322,   350,    76,
      23,    27,    25,    76,    48,    49,    29,    27,    52,   118,
     119,    39,    40,    41,    30,   340,    78,    61,    62,    63,
      64,    65,    66,    27,    28,    69,    70,    27,    72,    52,
      74,    75,    76,    29,    78,    79,    80,    81,    61,    62,
      63,    64,    65,    66,    29,    68,    69,    70,    28,    72,
      29,    74,    75,    76,    76,    78,    79,    80,    81,    80,
      29,    23,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    29,
      18,    19,    20,    21,    22,    76,    35,    71,    26,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    76,    18,    19,    20,    21,    22,    26,
      28,    24,    26,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     4,     5,     6,     7,
       8,    24,    24,    29,    24,    26,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     4,
       5,     6,     7,     8,    24,    29,    23,    23,    26,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    30,    18,    19,    20,    21,    22,    23,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    47,    18,    19,    20,    21,    22,
      23,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    30,    18,    19,    20,    21,
      22,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,     4,     5,     6,
       7,     8,    29,    29,    43,    76,    76,    29,    76,    51,
      31,    30,    24,    23,    31,    76,    30,    60,    51,    51,
      23,    76,    27,   133,    26,   254,   167,   289,   301,   159,
     276,   238,   336,   328,   368,   334,   124
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    17,    23,    25,    29,    36,    52,    61,    62,
      63,    64,    65,    66,    67,    69,    70,    72,    74,    75,
      76,    78,    79,    80,    81,    83,    84,    85,    86,    87,
      88,    91,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   107,   111,   112,   115,   121,   130,   153,   154,
     155,    96,    68,    92,    93,    94,    95,   103,   107,   112,
     121,    76,    25,    76,    76,    25,    25,    35,    76,   109,
      27,    89,     0,    91,    89,    35,    76,   104,   105,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    18,    19,    20,    21,    22,    23,    76,
      78,   111,    33,    34,   110,    26,    96,    30,    25,    29,
      53,    54,    55,    56,    57,   122,   123,    86,    17,    25,
     114,   155,    95,    76,    73,   111,    27,    27,    90,    76,
       3,   106,    23,    31,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,   111,    23,    50,    37,    42,   131,   132,
     133,     3,     3,     3,     3,     3,    26,    31,    25,   114,
     114,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    26,    95,    76,   108,   153,    28,
     111,   111,     3,   155,   105,     9,    76,    76,    30,    38,
     133,   135,    27,    27,    58,    59,   124,    78,    27,    94,
     107,   123,    86,   116,   117,   118,    26,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
      94,    96,    94,    28,    31,    76,    80,    29,    29,    23,
      29,    76,   144,   144,     4,     5,     6,     7,     8,   125,
     126,    35,    76,    26,    31,    71,   113,    26,   111,    26,
      48,    49,    94,    95,   103,   107,   112,   121,   127,   128,
     129,   134,   134,    39,    40,    41,   136,   137,   138,   145,
     148,    28,    31,    28,    24,    24,    24,    24,    24,    23,
      28,    27,    28,   119,   120,    94,   118,    94,   112,    94,
      28,    29,    29,    47,    23,    23,    30,    30,    29,    29,
      44,    29,    30,   137,    76,   144,   144,   144,   144,   144,
     126,   111,    27,    28,   131,    76,   155,    43,   139,   140,
     141,   144,   149,   150,    29,    76,   146,   147,   111,    30,
      31,    51,    30,   140,   142,   144,    51,    30,   150,   149,
      24,    30,   147,    23,   111,    23,    51,   143,    76,   151,
     152,    30,    86,    30,    43,   144,    60,    23,    31,    51,
      51,    23,   152,   144,    76,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    84,    85,    85,    85,    85,    85,
      85,    85,    86,    86,    87,    88,    89,    89,    90,    90,
      91,    91,    91,    91,    91,    91,    91,    91,    92,    92,
      92,    92,    92,    92,    92,    92,    93,    94,    95,    95,
      96,    96,    96,    96,    96,    96,    96,    97,    97,    98,
      98,    98,    98,    98,    99,    99,    99,    99,    99,    99,
     100,   101,   101,   101,   101,   101,   101,   102,   102,   103,
     104,   104,   105,   105,   106,   106,   107,   107,   108,   108,
     109,   109,   110,   110,   111,   111,   112,   112,   113,   113,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   116,   116,   117,
     117,   118,   118,   119,   119,   120,   120,   121,   121,   122,
     122,   123,   123,   123,   123,   123,   124,   124,   125,   125,
     126,   126,   126,   126,   126,   127,   127,   128,   128,   129,
     129,   130,   130,   131,   131,   132,   132,   133,   133,   134,
     134,   134,   134,   134,   134,   134,   135,   135,   136,   136,
     137,   137,   137,   138,   139,   139,   140,   141,   141,   142,
     142,   143,   143,   144,   144,   145,   146,   146,   147,   148,
     148,   149,   149,   150,   151,   151,   152,   152,   153,   154,
     154,   154,   154,   154,   154,   154,   155,   155,   155
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     3,     2,     4,     3,     5,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     0,     3,     3,     2,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     4,     2,     2,     0,     7,     5,     1,     1,
       1,     2,     1,     1,     1,     1,     6,     7,     2,     0,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     7,     1,     2,     1,
       3,     2,     3,     2,     1,     3,     2,     5,     5,     3,
       1,     5,     5,     5,     3,     3,     1,     1,     3,     1,
       3,     3,     3,     3,     3,     2,     2,     1,     3,     6,
       8,    11,     6,     2,     0,     2,     1,     5,     5,     1,
       1,     1,     1,     1,     1,     1,     4,     0,     2,     1,
       1,     1,     1,     4,     2,     1,     3,     2,     0,     3,
       1,     3,     1,     3,     1,     4,     2,     1,     6,     4,
       5,     2,     1,     4,     3,     1,     1,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 1750 "y.tab.c"
    break;


#line 1754 "y.tab.c"

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

#line 470 "parser.y"

int main(void) {
	yyparse();
}

