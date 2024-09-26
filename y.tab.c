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
  YYSYMBOL_statement = 85,                 /* statement  */
  YYSYMBOL_inner_statement = 86,           /* inner_statement  */
  YYSYMBOL_return_statement = 87,          /* return_statement  */
  YYSYMBOL_compound_statement = 88,        /* compound_statement  */
  YYSYMBOL_expression_statement = 89,      /* expression_statement  */
  YYSYMBOL_literals = 90,                  /* literals  */
  YYSYMBOL_expression = 91,                /* expression  */
  YYSYMBOL_unary_operator = 92,            /* unary_operator  */
  YYSYMBOL_arithmetic_expression = 93,     /* arithmetic_expression  */
  YYSYMBOL_assignment_expression = 94,     /* assignment_expression  */
  YYSYMBOL_unary_expression = 95,          /* unary_expression  */
  YYSYMBOL_comparison_expression = 96,     /* comparison_expression  */
  YYSYMBOL_logical_expression = 97,        /* logical_expression  */
  YYSYMBOL_declaration_statement = 98,     /* declaration_statement  */
  YYSYMBOL_declaration_list = 99,          /* declaration_list  */
  YYSYMBOL_declaration = 100,              /* declaration  */
  YYSYMBOL_declaration_extension = 101,    /* declaration_extension  */
  YYSYMBOL_value_or_identifier = 102,      /* value_or_identifier  */
  YYSYMBOL_iterative_statement = 103,      /* iterative_statement  */
  YYSYMBOL_iterator = 104,                 /* iterator  */
  YYSYMBOL_range = 105,                    /* range  */
  YYSYMBOL_number = 106,                   /* number  */
  YYSYMBOL_selection_statement = 107,      /* selection_statement  */
  YYSYMBOL_if_chain_statement = 108,       /* if_chain_statement  */
  YYSYMBOL_selection_expression = 109,     /* selection_expression  */
  YYSYMBOL_function_declaration = 110,     /* function_declaration  */
  YYSYMBOL_data_type = 111,                /* data_type  */
  YYSYMBOL_datatype_and_ref = 112,         /* datatype_and_ref  */
  YYSYMBOL_argument_list = 113,            /* argument_list  */
  YYSYMBOL_argument_declaration = 114,     /* argument_declaration  */
  YYSYMBOL_array_arg_dimension = 115,      /* array_arg_dimension  */
  YYSYMBOL_array_arg_dimension_increase = 116, /* array_arg_dimension_increase  */
  YYSYMBOL_array_dimension_list = 117,     /* array_dimension_list  */
  YYSYMBOL_array_dimension_tail = 118,     /* array_dimension_tail  */
  YYSYMBOL_array_dimension_increase = 119, /* array_dimension_increase  */
  YYSYMBOL_parallel_statement = 120,       /* parallel_statement  */
  YYSYMBOL_parallel_stmt_argument_list = 121, /* parallel_stmt_argument_list  */
  YYSYMBOL_parallel_stmt_argument = 122,   /* parallel_stmt_argument  */
  YYSYMBOL_schedule_list = 123,            /* schedule_list  */
  YYSYMBOL_reduction_list = 124,           /* reduction_list  */
  YYSYMBOL_reduction_operator_list = 125,  /* reduction_operator_list  */
  YYSYMBOL_channel_statement = 126,        /* channel_statement  */
  YYSYMBOL_signal_statement = 127,         /* signal_statement  */
  YYSYMBOL_wait_statement = 128,           /* wait_statement  */
  YYSYMBOL_taskgroup_statement = 129,      /* taskgroup_statement  */
  YYSYMBOL_taskgroup_definition = 130,     /* taskgroup_definition  */
  YYSYMBOL_task_declaration_list = 131,    /* task_declaration_list  */
  YYSYMBOL_task_declaration = 132,         /* task_declaration  */
  YYSYMBOL_task_statements = 133,          /* task_statements  */
  YYSYMBOL_properties_declaration = 134,   /* properties_declaration  */
  YYSYMBOL_taskgroup_properties = 135,     /* taskgroup_properties  */
  YYSYMBOL_taskgroup_property = 136,       /* taskgroup_property  */
  YYSYMBOL_order_block = 137,              /* order_block  */
  YYSYMBOL_order_rule_list = 138,          /* order_rule_list  */
  YYSYMBOL_order_rule = 139,               /* order_rule  */
  YYSYMBOL_order_rule_start = 140,         /* order_rule_start  */
  YYSYMBOL_order_rule_mid = 141,           /* order_rule_mid  */
  YYSYMBOL_order_rule_end = 142,           /* order_rule_end  */
  YYSYMBOL_identifier_list = 143,          /* identifier_list  */
  YYSYMBOL_shared_block = 144,             /* shared_block  */
  YYSYMBOL_shared_rule_list = 145,         /* shared_rule_list  */
  YYSYMBOL_shared_rule = 146,              /* shared_rule  */
  YYSYMBOL_mem_block = 147,                /* mem_block  */
  YYSYMBOL_mem_statement_list = 148,       /* mem_statement_list  */
  YYSYMBOL_mem_statement = 149,            /* mem_statement  */
  YYSYMBOL_mem_taskgroup_list = 150,       /* mem_taskgroup_list  */
  YYSYMBOL_mem_taskgroup_name = 151,       /* mem_taskgroup_name  */
  YYSYMBOL_value = 152                     /* value  */
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
#define YYFINAL  64
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   624

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  192
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  373

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
       0,    42,    42,    45,    46,    52,    53,    54,    55,    56,
      57,    58,    59,    63,    64,    65,    66,    67,    68,    69,
      70,    74,    77,    84,    85,    89,    93,    94,    95,    96,
      97,    98,    99,   110,   111,   116,   117,   118,   119,   120,
     124,   125,   126,   127,   128,   129,   135,   140,   141,   142,
     143,   144,   145,   149,   150,   155,   158,   159,   163,   164,
     167,   168,   169,   173,   178,   179,   180,   187,   188,   192,
     193,   197,   198,   203,   204,   208,   209,   213,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   232,   236,   236,   236,   236,   236,   236,
     236,   240,   240,   244,   245,   248,   249,   252,   253,   256,
     257,   262,   265,   266,   269,   273,   274,   276,   277,   280,
     281,   282,   283,   284,   287,   287,   291,   292,   296,   297,
     298,   299,   300,   303,   304,   308,   309,   313,   314,   316,
     317,   320,   321,   325,   326,   329,   330,   335,   336,   337,
     338,   339,   340,   341,   345,   346,   351,   352,   356,   357,
     358,   362,   367,   368,   372,   377,   378,   382,   383,   387,
     388,   392,   393,   397,   402,   403,   407,   439,   440,   446,
     447,   452,   457,   458,   463,   464,   469,   469,   469,   469,
     469,   469,   469
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
  "$accept", "program", "statement_list", "statement", "inner_statement",
  "return_statement", "compound_statement", "expression_statement",
  "literals", "expression", "unary_operator", "arithmetic_expression",
  "assignment_expression", "unary_expression", "comparison_expression",
  "logical_expression", "declaration_statement", "declaration_list",
  "declaration", "declaration_extension", "value_or_identifier",
  "iterative_statement", "iterator", "range", "number",
  "selection_statement", "if_chain_statement", "selection_expression",
  "function_declaration", "data_type", "datatype_and_ref", "argument_list",
  "argument_declaration", "array_arg_dimension",
  "array_arg_dimension_increase", "array_dimension_list",
  "array_dimension_tail", "array_dimension_increase", "parallel_statement",
  "parallel_stmt_argument_list", "parallel_stmt_argument", "schedule_list",
  "reduction_list", "reduction_operator_list", "channel_statement",
  "signal_statement", "wait_statement", "taskgroup_statement",
  "taskgroup_definition", "task_declaration_list", "task_declaration",
  "task_statements", "properties_declaration", "taskgroup_properties",
  "taskgroup_property", "order_block", "order_rule_list", "order_rule",
  "order_rule_start", "order_rule_mid", "order_rule_end",
  "identifier_list", "shared_block", "shared_rule_list", "shared_rule",
  "mem_block", "mem_statement_list", "mem_statement", "mem_taskgroup_list",
  "mem_taskgroup_name", "value", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-309)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-101)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       4,  -309,  -309,  -309,   365,   287,   -44,     9,  -309,  -309,
    -309,  -309,  -309,  -309,   -21,    37,   -18,  -309,  -309,   -12,
    -309,  -309,  -309,  -309,    73,     4,  -309,  -309,  -309,  -309,
     514,   -50,  -309,  -309,  -309,  -309,  -309,  -309,  -309,  -309,
    -309,    -4,  -309,  -309,  -309,  -309,   388,   365,    45,  -309,
    -309,  -309,  -309,  -309,  -309,  -309,   130,   108,    31,   135,
     169,    24,  -309,     8,  -309,  -309,   365,   365,   365,   365,
     365,   365,   365,   365,   365,   365,   365,   365,   365,   365,
     365,   365,   365,   365,   365,  -309,  -309,  -309,  -309,    36,
      16,    18,  -309,  -309,   535,  -309,    74,    10,   155,   179,
     182,   187,   190,    88,  -309,  -309,   152,   135,   135,  -309,
     467,   127,   300,  -309,   131,   556,   173,   173,  -309,  -309,
    -309,   295,   295,   191,   191,   191,   191,   268,   575,   556,
     556,   556,   556,   556,   200,    42,   -50,  -309,  -309,  -309,
      -4,  -309,   199,   136,   141,   188,    49,  -309,   204,   207,
     114,   158,   211,   -11,   108,    31,  -309,   490,   135,   135,
     135,   135,   135,   135,   135,   135,   135,   135,   135,   135,
     135,   212,   -50,   365,   212,   164,  -309,  -309,   125,  -309,
     166,   240,   241,   270,   265,  -309,  -309,   220,   220,  -309,
    -309,  -309,  -309,   247,  -309,  -309,  -309,   262,   222,   118,
    -309,  -309,   181,   181,  -309,  -309,  -309,   610,   610,   280,
     280,   280,   280,   599,   587,   248,    56,   444,  -309,  -309,
     284,   -50,  -309,   294,   266,   266,  -309,   106,  -309,   139,
     140,   297,   298,   302,   309,   310,     2,  -309,  -309,   148,
     212,    31,     7,  -309,  -309,  -309,   -50,   212,   -50,  -309,
     296,   306,   308,   307,  -309,  -309,  -309,  -309,  -309,  -309,
    -309,   320,   333,   328,   330,   335,     6,   340,    69,  -309,
    -309,  -309,  -309,  -309,   301,  -309,   220,   220,   220,   220,
     220,   247,  -309,   -50,  -309,  -309,   174,  -309,  -309,  -309,
    -309,   347,  -309,   125,  -309,    10,   311,    42,  -309,  -309,
    -309,  -309,   341,   220,   354,   312,  -309,  -309,  -309,   355,
     355,   355,   355,   355,  -309,  -309,   -50,  -309,   212,  -309,
     359,   374,  -309,   334,    -6,  -309,   220,    -9,   -25,  -309,
     220,   387,   -19,  -309,  -309,  -309,   389,   -50,  -309,  -309,
    -309,    -7,   355,   337,  -309,  -309,   -16,    31,  -309,  -309,
    -309,   385,  -309,   -28,  -309,   356,    22,  -309,  -309,   366,
     367,   396,   355,  -309,  -309,   337,   220,   344,  -309,  -309,
      23,  -309,  -309
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    33,    34,    24,     0,    20,     0,     0,    94,    95,
      96,    97,    98,    99,     0,     0,     0,   190,   191,   192,
     186,   187,   188,   189,     0,     2,     4,     8,     7,    26,
       0,     0,    29,    28,    32,    31,    30,    11,     5,     6,
       9,     0,    12,    10,    25,   192,     0,     0,     0,    19,
      16,    15,    17,    13,    14,    18,     0,     0,     0,     0,
       0,     0,    67,     0,     1,     3,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    23,    72,    71,    46,     0,
      62,     0,    57,    27,     0,    22,     0,   142,     0,     0,
       0,     0,     0,     0,   118,   100,     0,     0,     0,    92,
       0,   192,     0,    68,     0,    40,    35,    36,    37,    38,
      39,    51,    52,    48,    47,    49,    50,    53,    54,    41,
      42,    43,    44,    45,     0,     0,     0,    59,    60,    55,
       0,    21,     0,     0,     0,     0,   155,   144,     0,     0,
       0,     0,     0,     0,     0,     0,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    63,    61,     0,    56,
       0,     0,     0,     0,     0,   143,   141,     0,     0,   125,
     124,   122,   123,     0,   115,   116,   117,   101,     0,     0,
     103,    79,    80,    81,    82,    83,    84,    89,    90,    86,
      85,    87,    88,    78,    77,    76,     0,     0,    66,    58,
       0,     0,   111,     0,     0,     0,   140,     0,   172,     0,
       0,     0,     0,     0,     0,     0,     0,   127,   102,   105,
       0,     0,     0,    73,    69,    70,     0,     0,     0,   112,
       0,     0,     0,   135,   150,   149,   151,   147,   148,   152,
     153,     0,     0,     0,     0,     0,     0,     0,     0,   157,
     158,   159,   160,   120,     0,   119,     0,     0,     0,     0,
       0,     0,   121,     0,   108,   106,     0,    93,   104,    74,
      75,     0,    64,     0,   113,   142,     0,     0,   133,   134,
     145,   146,   166,     0,     0,     0,   154,   156,   171,   128,
     129,   130,   131,   132,   126,   110,     0,   107,     0,   114,
       0,     0,   136,     0,   166,   163,     0,     0,     0,   180,
       0,     0,     0,   175,   109,    65,     0,     0,   165,   161,
     162,     0,   168,     0,   177,   179,     0,     0,   173,   174,
     139,     0,   170,     0,   164,   184,     0,   183,   178,     0,
     137,     0,   167,   185,   181,     0,     0,     0,   169,   182,
       0,   138,   176
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -309,  -309,  -309,   410,  -309,  -309,    -5,    -1,    98,    59,
    -309,  -309,  -309,  -309,  -309,  -309,     3,  -309,   281,  -309,
    -309,     1,  -309,  -309,  -133,    -3,  -309,   264,  -309,   -57,
    -309,  -309,   195,  -309,  -309,  -309,   144,  -309,     5,  -309,
     288,  -309,  -309,   157,  -309,  -309,  -309,  -309,   172,  -309,
     315,   243,  -309,  -309,   201,  -309,  -309,   160,  -309,  -309,
    -309,  -175,  -309,  -309,   153,  -309,   156,  -308,  -309,   122,
     192
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    24,    25,    26,    48,    49,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    91,    92,   137,
     177,    38,    63,   246,    88,    39,   243,   110,    40,    41,
     198,   199,   200,   285,   286,   138,   222,   249,    42,   103,
     104,   191,   236,   237,   260,   261,   262,    43,   145,   146,
     147,   263,   186,   268,   269,   270,   324,   325,   326,   341,
     354,   327,   271,   332,   333,   272,   328,   329,   356,   357,
      44
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      50,   106,    54,   178,    51,   344,    53,    60,    52,     1,
      55,   348,   229,   230,   358,   361,   352,    61,     5,   135,
     345,     2,   274,  -100,   339,   281,    86,     3,    87,     4,
     282,    89,    56,     5,    57,   303,     5,   323,   345,   216,
       6,   139,   343,   136,   353,   364,   372,   143,   228,   140,
     304,   228,   144,   365,   274,    58,     7,   331,    62,   112,
     228,    16,    59,    46,  -100,     8,     9,    10,    11,    12,
      13,    14,    90,    64,    15,    95,    16,    15,    17,    18,
      19,   114,    20,    21,    22,    23,   143,   184,   250,   244,
     245,   144,     8,     9,    10,    11,    12,    13,   197,   306,
     113,   309,   310,   311,   312,   313,    94,   105,   265,   266,
     267,   173,   134,   291,   153,   293,    17,    18,    45,   154,
      20,    21,    22,    23,   142,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   240,   265,   266,   267,   194,   241,
     315,   342,   107,   220,   195,    96,   221,   109,   148,    97,
     108,    98,    99,   100,   101,   102,   215,   273,   275,   218,
     274,   274,   189,   190,     1,   283,   284,   155,   362,    69,
      70,    71,   149,   334,   197,   150,     2,   160,   161,   162,
     151,   370,     3,   152,     4,    67,    68,    69,    70,    71,
     172,   316,   317,   175,   351,   109,   109,   174,   180,    17,
      18,    45,   181,    20,    21,    22,    23,   182,   183,   254,
     254,   258,   258,   255,   255,   257,   257,   256,   256,   259,
     259,   187,   217,   176,   188,   287,   192,   289,   193,   290,
     219,     5,   292,    17,    18,   111,   223,    20,    21,    22,
      23,   231,   232,   233,   234,   235,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   224,
     225,     1,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,     2,   158,   159,   160,   161,   162,     3,
     359,     4,     1,   226,   227,     5,   228,   238,   239,    67,
      68,    69,    70,    71,     2,     1,    74,    75,    76,    77,
       3,   248,     4,   335,   252,   253,     5,     2,     7,   242,
     251,   276,   277,     3,   294,     4,   278,     8,     9,    10,
      11,    12,    13,   279,   280,   295,    15,   296,    16,     7,
      17,    18,    19,   298,    20,    21,    22,    23,     8,     9,
      10,    11,    12,    13,   297,    47,   299,    15,   300,    16,
     301,    17,    18,    19,   302,    20,    21,    22,    23,   305,
       1,   156,   157,   318,    17,    18,    45,   308,    20,    21,
      22,    23,     2,   330,   323,   338,   274,   321,   331,   336,
       4,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,   337,    80,    81,    82,    83,
      84,   347,   350,   355,    93,   360,   363,   366,   367,   368,
     371,   179,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,    65,   288,   319,   314,    17,
      18,    45,   196,    20,    21,    22,    23,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,   185,    80,    81,    82,    83,    84,   320,   264,   307,
     247,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   340,   349,   346,   369,     0,   322,
       0,     0,     0,   171,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   201,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,    80,    81,    82,    83,    84,    85,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     0,    80,    81,    82,    83,    84,   141,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,    80,    81,    82,    83,    84,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   158,   159,   160,   161,   162,     0,
       0,   165,   166,   167,   168
};

static const yytype_int16 yycheck[] =
{
       5,    58,     5,   136,     5,    30,     5,    25,     5,     5,
       5,    30,   187,   188,    30,    43,    23,    35,    29,     3,
     328,    17,    31,    35,    30,    23,    76,    23,    78,    25,
      28,    35,    76,    29,    25,    29,    29,    43,   346,   172,
      36,    23,    51,    27,    51,    23,    23,    37,    76,    31,
      44,    76,    42,    31,    31,    76,    52,    76,    76,    60,
      76,    72,    25,     4,    76,    61,    62,    63,    64,    65,
      66,    67,    76,     0,    70,    30,    72,    70,    74,    75,
      76,    73,    78,    79,    80,    81,    37,    38,   221,    33,
      34,    42,    61,    62,    63,    64,    65,    66,   155,    30,
      76,   276,   277,   278,   279,   280,    47,    76,    39,    40,
      41,   112,    76,   246,    26,   248,    74,    75,    76,    31,
      78,    79,    80,    81,    50,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    26,    39,    40,    41,   153,    31,
     283,   326,    17,    28,   153,    25,    31,    59,     3,    29,
      25,    53,    54,    55,    56,    57,   171,    28,    28,   174,
      31,    31,    58,    59,     5,    27,    28,    25,   353,     6,
       7,     8,     3,   316,   241,     3,    17,     6,     7,     8,
       3,   366,    23,     3,    25,     4,     5,     6,     7,     8,
      73,    27,    28,     3,   337,   107,   108,    76,     9,    74,
      75,    76,    76,    78,    79,    80,    81,    76,    30,   224,
     225,   224,   225,   224,   225,   224,   225,   224,   225,   224,
     225,    27,   173,   135,    27,   240,    78,   242,    27,   242,
      76,    29,   247,    74,    75,    76,    80,    78,    79,    80,
      81,     4,     5,     6,     7,     8,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,    29,
      29,     5,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    17,     4,     5,     6,     7,     8,    23,
     347,    25,     5,    23,    29,    29,    76,    35,    76,     4,
       5,     6,     7,     8,    17,     5,    11,    12,    13,    14,
      23,    27,    25,   318,    48,    49,    29,    17,    52,    71,
      26,    24,    24,    23,    28,    25,    24,    61,    62,    63,
      64,    65,    66,    24,    24,    29,    70,    29,    72,    52,
      74,    75,    76,    23,    78,    79,    80,    81,    61,    62,
      63,    64,    65,    66,    47,    68,    23,    70,    30,    72,
      30,    74,    75,    76,    29,    78,    79,    80,    81,    29,
       5,   107,   108,    26,    74,    75,    76,    76,    78,    79,
      80,    81,    17,    29,    43,    51,    31,    76,    76,    30,
      25,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    31,    18,    19,    20,    21,
      22,    24,    23,    76,    26,    30,    60,    51,    51,    23,
      76,   140,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,    25,   241,   293,   281,    74,
      75,    76,   154,    78,    79,    80,    81,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,   146,    18,    19,    20,    21,    22,   295,   225,   268,
      26,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,   324,   332,   330,   365,    -1,   297,
      -1,    -1,    -1,    26,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    -1,    18,    19,    20,    21,    22,    23,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    23,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -1,    18,    19,    20,    21,    22,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,     4,     5,     6,     7,     8,    -1,
      -1,    11,    12,    13,    14
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    17,    23,    25,    29,    36,    52,    61,    62,
      63,    64,    65,    66,    67,    70,    72,    74,    75,    76,
      78,    79,    80,    81,    83,    84,    85,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,   103,   107,
     110,   111,   120,   129,   152,    76,    91,    68,    86,    87,
      88,    89,    98,   103,   107,   120,    76,    25,    76,    25,
      25,    35,    76,   104,     0,    85,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      18,    19,    20,    21,    22,    23,    76,    78,   106,    35,
      76,    99,   100,    26,    91,    30,    25,    29,    53,    54,
      55,    56,    57,   121,   122,    76,   111,    17,    25,    90,
     109,    76,    89,    76,    73,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,    76,     3,    27,   101,   117,    23,
      31,    23,    50,    37,    42,   130,   131,   132,     3,     3,
       3,     3,     3,    26,    31,    25,   109,   109,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    26,    73,    89,    76,     3,    90,   102,   106,   100,
       9,    76,    76,    30,    38,   132,   134,    27,    27,    58,
      59,   123,    78,    27,    88,   103,   122,   111,   112,   113,
     114,    26,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,    88,   106,    91,    88,    76,
      28,    31,   118,    80,    29,    29,    23,    29,    76,   143,
     143,     4,     5,     6,     7,     8,   124,   125,    35,    76,
      26,    31,    71,   108,    33,    34,   105,    26,    27,   119,
     106,    26,    48,    49,    88,    89,    98,   103,   107,   120,
     126,   127,   128,   133,   133,    39,    40,    41,   135,   136,
     137,   144,   147,    28,    31,    28,    24,    24,    24,    24,
      24,    23,    28,    27,    28,   115,   116,    88,   114,    88,
     107,   106,    88,   106,    28,    29,    29,    47,    23,    23,
      30,    30,    29,    29,    44,    29,    30,   136,    76,   143,
     143,   143,   143,   143,   125,   106,    27,    28,    26,   118,
     130,    76,   152,    43,   138,   139,   140,   143,   148,   149,
      29,    76,   145,   146,   106,    88,    30,    31,    51,    30,
     139,   141,   143,    51,    30,   149,   148,    24,    30,   146,
      23,   106,    23,    51,   142,    76,   150,   151,    30,   111,
      30,    43,   143,    60,    23,    31,    51,    51,    23,   151,
     143,    76,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    82,    83,    84,    84,    85,    85,    85,    85,    85,
      85,    85,    85,    86,    86,    86,    86,    86,    86,    86,
      86,    87,    88,    89,    89,    90,    91,    91,    91,    91,
      91,    91,    91,    92,    92,    93,    93,    93,    93,    93,
      94,    94,    94,    94,    94,    94,    95,    96,    96,    96,
      96,    96,    96,    97,    97,    98,    99,    99,   100,   100,
     101,   101,   101,   102,   103,   103,   103,   104,   104,   105,
     105,   106,   106,   107,   107,   108,   108,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   110,   111,   111,   111,   111,   111,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   118,   118,   119,   120,   120,   121,   121,   122,
     122,   122,   122,   122,   123,   123,   124,   124,   125,   125,
     125,   125,   125,   126,   126,   127,   127,   128,   128,   129,
     129,   130,   130,   131,   131,   132,   132,   133,   133,   133,
     133,   133,   133,   133,   134,   134,   135,   135,   136,   136,
     136,   137,   138,   138,   139,   140,   140,   141,   141,   142,
     142,   143,   143,   144,   145,   145,   146,   147,   147,   148,
     148,   149,   150,   150,   151,   151,   152,   152,   152,   152,
     152,   152,   152
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       0,     3,     3,     2,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     4,     2,
       1,     2,     0,     1,     7,     9,     5,     1,     2,     1,
       1,     1,     1,     6,     7,     2,     0,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     1,     7,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     3,     2,     3,     2,     1,     3,
       2,     3,     2,     3,     3,     5,     5,     3,     1,     5,
       5,     5,     3,     3,     1,     1,     3,     1,     3,     3,
       3,     3,     3,     2,     2,     1,     3,     6,     8,    11,
       6,     2,     0,     2,     1,     5,     5,     1,     1,     1,
       1,     1,     1,     1,     4,     0,     2,     1,     1,     1,
       1,     4,     2,     1,     3,     2,     0,     3,     1,     3,
       1,     3,     1,     4,     2,     1,     6,     4,     5,     2,
       1,     4,     3,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     1
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
#line 1748 "y.tab.c"
    break;


#line 1752 "y.tab.c"

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

#line 473 "parser.y"

int main(void) {
	yyparse();
}

