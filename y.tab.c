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
extern int yyerror(const char *s);
#define YYDEBUG 1

#line 78 "y.tab.c"

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
    INT_LITERAL = 334,             /* INT_LITERAL  */
    FLOAT_LITERAL = 335,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 336,          /* STRING_LITERAL  */
    CHARACTER_LITERAL = 337        /* CHARACTER_LITERAL  */
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
#define INT_LITERAL 334
#define FLOAT_LITERAL 335
#define STRING_LITERAL 336
#define CHARACTER_LITERAL 337

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
  YYSYMBOL_INT_LITERAL = 79,               /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 80,             /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 81,            /* STRING_LITERAL  */
  YYSYMBOL_CHARACTER_LITERAL = 82,         /* CHARACTER_LITERAL  */
  YYSYMBOL_YYACCEPT = 83,                  /* $accept  */
  YYSYMBOL_program = 84,                   /* program  */
  YYSYMBOL_statement_list = 85,            /* statement_list  */
  YYSYMBOL_one_or_more_statements = 86,    /* one_or_more_statements  */
  YYSYMBOL_generic_dtypes = 87,            /* generic_dtypes  */
  YYSYMBOL_dtype = 88,                     /* dtype  */
  YYSYMBOL_array = 89,                     /* array  */
  YYSYMBOL_array_element = 90,             /* array_element  */
  YYSYMBOL_dims = 91,                      /* dims  */
  YYSYMBOL_initializer_dims = 92,          /* initializer_dims  */
  YYSYMBOL_statement = 93,                 /* statement  */
  YYSYMBOL_inner_statement = 94,           /* inner_statement  */
  YYSYMBOL_one_or_more_inner_statements = 95, /* one_or_more_inner_statements  */
  YYSYMBOL_inner_statement_list = 96,      /* inner_statement_list  */
  YYSYMBOL_return_statement = 97,          /* return_statement  */
  YYSYMBOL_compound_statement = 98,        /* compound_statement  */
  YYSYMBOL_struct_declaration = 99,        /* struct_declaration  */
  YYSYMBOL_member_data_list = 100,         /* member_data_list  */
  YYSYMBOL_member_data = 101,              /* member_data  */
  YYSYMBOL_expression_statement = 102,     /* expression_statement  */
  YYSYMBOL_expression = 103,               /* expression  */
  YYSYMBOL_function_call = 104,            /* function_call  */
  YYSYMBOL_function_call_tail = 105,       /* function_call_tail  */
  YYSYMBOL_function_arguments = 106,       /* function_arguments  */
  YYSYMBOL_arithmetic_expression = 107,    /* arithmetic_expression  */
  YYSYMBOL_assignment_expression = 108,    /* assignment_expression  */
  YYSYMBOL_unary_expression = 109,         /* unary_expression  */
  YYSYMBOL_number_literals = 110,          /* number_literals  */
  YYSYMBOL_comparison_expression = 111,    /* comparison_expression  */
  YYSYMBOL_logical_expression = 112,       /* logical_expression  */
  YYSYMBOL_declaration_statement = 113,    /* declaration_statement  */
  YYSYMBOL_declaration_list = 114,         /* declaration_list  */
  YYSYMBOL_declaration = 115,              /* declaration  */
  YYSYMBOL_value_assign = 116,             /* value_assign  */
  YYSYMBOL_initializer = 117,              /* initializer  */
  YYSYMBOL_list_initialiser = 118,         /* list_initialiser  */
  YYSYMBOL_initialiser_member_list_tail = 119, /* initialiser_member_list_tail  */
  YYSYMBOL_list_member = 120,              /* list_member  */
  YYSYMBOL_iterative_statement = 121,      /* iterative_statement  */
  YYSYMBOL_empty_expression = 122,         /* empty_expression  */
  YYSYMBOL_container = 123,                /* container  */
  YYSYMBOL_iterator = 124,                 /* iterator  */
  YYSYMBOL_number = 125,                   /* number  */
  YYSYMBOL_selection_statement = 126,      /* selection_statement  */
  YYSYMBOL_if_chain_statement = 127,       /* if_chain_statement  */
  YYSYMBOL_function_declaration = 128,     /* function_declaration  */
  YYSYMBOL_datatype_and_ref = 129,         /* datatype_and_ref  */
  YYSYMBOL_parameter_dtype = 130,          /* parameter_dtype  */
  YYSYMBOL_parameter_list = 131,           /* parameter_list  */
  YYSYMBOL_parameter_declaration = 132,    /* parameter_declaration  */
  YYSYMBOL_parallel_statement = 133,       /* parallel_statement  */
  YYSYMBOL_parallel_stmt_argument_list = 134, /* parallel_stmt_argument_list  */
  YYSYMBOL_parallel_stmt_argument = 135,   /* parallel_stmt_argument  */
  YYSYMBOL_schedule_list = 136,            /* schedule_list  */
  YYSYMBOL_reduction_list = 137,           /* reduction_list  */
  YYSYMBOL_reduction_operator_list = 138,  /* reduction_operator_list  */
  YYSYMBOL_channel_statement = 139,        /* channel_statement  */
  YYSYMBOL_signal_statement = 140,         /* signal_statement  */
  YYSYMBOL_task_all = 141,                 /* task_all  */
  YYSYMBOL_wait_statement = 142,           /* wait_statement  */
  YYSYMBOL_taskgroup_statement = 143,      /* taskgroup_statement  */
  YYSYMBOL_taskgroup_argument_list = 144,  /* taskgroup_argument_list  */
  YYSYMBOL_taskgroup_argument = 145,       /* taskgroup_argument  */
  YYSYMBOL_taskgroup_definition = 146,     /* taskgroup_definition  */
  YYSYMBOL_task_declaration_list = 147,    /* task_declaration_list  */
  YYSYMBOL_task_declaration = 148,         /* task_declaration  */
  YYSYMBOL_supervisor_statement_list = 149, /* supervisor_statement_list  */
  YYSYMBOL_supervisor_statements = 150,    /* supervisor_statements  */
  YYSYMBOL_task_statement_list = 151,      /* task_statement_list  */
  YYSYMBOL_task_statements = 152,          /* task_statements  */
  YYSYMBOL_properties_declaration = 153,   /* properties_declaration  */
  YYSYMBOL_taskgroup_properties = 154,     /* taskgroup_properties  */
  YYSYMBOL_taskgroup_property = 155,       /* taskgroup_property  */
  YYSYMBOL_order_block = 156,              /* order_block  */
  YYSYMBOL_order_rule_list = 157,          /* order_rule_list  */
  YYSYMBOL_order_rule = 158,               /* order_rule  */
  YYSYMBOL_order_rule_start = 159,         /* order_rule_start  */
  YYSYMBOL_order_rule_mid = 160,           /* order_rule_mid  */
  YYSYMBOL_order_rule_end = 161,           /* order_rule_end  */
  YYSYMBOL_identifier_list = 162,          /* identifier_list  */
  YYSYMBOL_shared_block = 163,             /* shared_block  */
  YYSYMBOL_shared_rule_list = 164,         /* shared_rule_list  */
  YYSYMBOL_shared_rule = 165,              /* shared_rule  */
  YYSYMBOL_mem_block = 166,                /* mem_block  */
  YYSYMBOL_mem_statement_list = 167,       /* mem_statement_list  */
  YYSYMBOL_mem_statement = 168,            /* mem_statement  */
  YYSYMBOL_mem_taskgroup_list = 169,       /* mem_taskgroup_list  */
  YYSYMBOL_mem_taskgroup_name = 170,       /* mem_taskgroup_name  */
  YYSYMBOL_other_statements = 171,         /* other_statements  */
  YYSYMBOL_join_statement = 172,           /* join_statement  */
  YYSYMBOL_call_statement = 173,           /* call_statement  */
  YYSYMBOL_array_literal = 174,            /* array_literal  */
  YYSYMBOL_literals = 175,                 /* literals  */
  YYSYMBOL_value = 176,                    /* value  */
  YYSYMBOL_identifier_chain = 177          /* identifier_chain  */
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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  86
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1242

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  235
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  424

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   337


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
      75,    76,    77,    78,    79,    80,    81,    82
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    45,    45,    48,    49,    50,    51,    56,    57,    58,
      59,    60,    61,    62,    63,    70,    71,    75,    79,    84,
      85,    89,    90,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   107,   108,   110,   111,   113,   114,   115,   116,
     117,   118,   119,   123,   124,   125,   126,   129,   134,   135,
     136,   138,   140,   141,   148,   149,   150,   151,   152,   153,
     154,   155,   159,   163,   164,   166,   169,   170,   171,   172,
     173,   177,   178,   179,   180,   181,   182,   188,   189,   193,
     194,   196,   197,   198,   199,   200,   201,   205,   206,   211,
     214,   215,   219,   220,   223,   224,   226,   227,   229,   231,
     232,   233,   234,   238,   239,   242,   243,   250,   251,   254,
     255,   260,   261,   266,   267,   271,   272,   277,   282,   282,
     285,   286,   289,   290,   291,   294,   295,   300,   301,   302,
     304,   305,   308,   309,   310,   311,   312,   315,   315,   319,
     320,   324,   325,   326,   327,   328,   331,   332,   336,   337,
     340,   341,   345,   346,   349,   350,   353,   354,   356,   357,
     359,   360,   364,   365,   368,   369,   370,   375,   376,   379,
     380,   381,   382,   383,   384,   385,   386,   390,   391,   395,
     396,   397,   398,   399,   400,   401,   405,   406,   411,   412,
     416,   417,   418,   422,   427,   428,   432,   437,   438,   442,
     443,   447,   448,   452,   453,   457,   462,   463,   467,   473,
     474,   480,   481,   486,   491,   492,   497,   498,   503,   504,
     507,   512,   519,   520,   524,   524,   524,   524,   524,   524,
     524,   527,   528,   529,   533,   534
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
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
  "INT_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL", "CHARACTER_LITERAL",
  "$accept", "program", "statement_list", "one_or_more_statements",
  "generic_dtypes", "dtype", "array", "array_element", "dims",
  "initializer_dims", "statement", "inner_statement",
  "one_or_more_inner_statements", "inner_statement_list",
  "return_statement", "compound_statement", "struct_declaration",
  "member_data_list", "member_data", "expression_statement", "expression",
  "function_call", "function_call_tail", "function_arguments",
  "arithmetic_expression", "assignment_expression", "unary_expression",
  "number_literals", "comparison_expression", "logical_expression",
  "declaration_statement", "declaration_list", "declaration",
  "value_assign", "initializer", "list_initialiser",
  "initialiser_member_list_tail", "list_member", "iterative_statement",
  "empty_expression", "container", "iterator", "number",
  "selection_statement", "if_chain_statement", "function_declaration",
  "datatype_and_ref", "parameter_dtype", "parameter_list",
  "parameter_declaration", "parallel_statement",
  "parallel_stmt_argument_list", "parallel_stmt_argument", "schedule_list",
  "reduction_list", "reduction_operator_list", "channel_statement",
  "signal_statement", "task_all", "wait_statement", "taskgroup_statement",
  "taskgroup_argument_list", "taskgroup_argument", "taskgroup_definition",
  "task_declaration_list", "task_declaration", "supervisor_statement_list",
  "supervisor_statements", "task_statement_list", "task_statements",
  "properties_declaration", "taskgroup_properties", "taskgroup_property",
  "order_block", "order_rule_list", "order_rule", "order_rule_start",
  "order_rule_mid", "order_rule_end", "identifier_list", "shared_block",
  "shared_rule_list", "shared_rule", "mem_block", "mem_statement_list",
  "mem_statement", "mem_taskgroup_list", "mem_taskgroup_name",
  "other_statements", "join_statement", "call_statement", "array_literal",
  "literals", "value", "identifier_chain", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-187)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-205)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     341,  -187,   -45,   247,  -187,   247,   545,   -47,   147,  -187,
    -187,  -187,  -187,  -187,  -187,   -41,   -30,    71,   -10,  -187,
    -187,    48,  -187,  -187,  -187,  -187,   135,  -187,   409,   114,
     -19,  -187,  -187,  -187,  -187,  -187,  -187,   889,  -187,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,   120,  -187,  -187,  -187,  -187,   921,   119,
     136,   155,   109,   116,   627,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,  -187,   177,   163,  -187,   174,   176,   247,   226,
     131,  -187,   138,   148,   247,   183,  -187,  -187,   184,   144,
     211,    10,  -187,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,  -187,   247,   247,   154,  -187,  -187,   953,  -187,
    -187,  -187,  -187,  -187,    42,    95,   218,   230,   231,   241,
     243,   108,  -187,   222,  -187,   985,   226,  -187,   258,  -187,
     236,  1177,  -187,   233,  -187,   217,  1017,   247,   247,  -187,
     257,   236,  -187,  -187,   -19,  1177,    22,    22,    92,    92,
      92,   348,   348,   123,   123,   123,   123,   629,  1208,  1177,
    1177,  1177,  1177,  1177,  -187,  -187,  -187,  -187,   263,   264,
     242,   239,   193,   196,   246,    12,  -187,   251,   253,   134,
      90,   255,    -2,   163,    16,   118,   256,   247,    68,  1177,
     256,   268,   259,   217,  -187,   236,  -187,  -187,  1049,   857,
     223,  1177,  -187,  -187,  -187,   219,   247,   280,    42,   178,
     281,   296,   292,  -187,  -187,   244,   244,  -187,  -187,  -187,
    -187,  -187,  -187,   120,   250,  -187,  -187,  -187,   -14,   297,
     265,  -187,   112,  -187,   308,   266,  -187,   260,  1177,   319,
    -187,   269,   318,   217,  -187,   247,  -187,  -187,  1177,    95,
    -187,   293,  -187,  -187,  -187,  -187,  -187,   139,   157,   326,
     327,   333,   339,   343,   143,  -187,    -8,  -187,   362,   256,
     174,  -187,   211,    14,  -187,   256,  -187,  -187,  -187,  1081,
     338,   366,   709,   477,   110,  -187,  -187,   244,   244,   244,
     244,   244,   250,  -187,   247,  -187,  -187,   349,  -187,  -187,
    -187,  -187,   350,   247,  -187,   342,   351,  -187,  -187,  -187,
    -187,  -187,  -187,  -187,   352,   355,  -187,  -187,   301,   305,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
    -187,  -187,   345,    -5,   356,  -187,  -187,  -187,  -187,   268,
     268,   268,   268,   268,  -187,  1177,  -187,  -187,  1113,   306,
     344,   354,  -187,  -187,   363,   367,  -187,  -187,   368,  -187,
     370,   360,   369,   247,  -187,  -187,     2,   -16,  -187,    -4,
    -187,   247,  -187,  1177,  -187,   365,  -187,   244,  -187,   -11,
    -187,     6,  -187,    29,  -187,   777,  1145,  -187,     0,   268,
     346,  -187,   174,  -187,   374,  -187,   -21,  -187,   371,    15,
    -187,   376,   357,   388,   268,  -187,  -187,   346,   244,  -187,
    -187,  -187,    21,  -187
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    14,     0,     0,    53,     0,     0,     0,     0,     7,
      12,     8,    11,     9,    10,     0,     0,     0,     0,   228,
     229,   235,   224,   225,   226,   227,     0,     2,     0,    15,
       0,    16,   233,     6,    26,    31,    25,     0,    61,    57,
      56,    60,    59,    58,    29,    23,    24,    27,    30,    28,
     230,   231,    54,   232,    80,    79,    77,    78,     0,     0,
       0,     0,     0,     0,     0,    35,    42,    39,    38,    40,
      36,    37,    41,     0,     0,   128,     0,    13,     0,     0,
       0,   109,     0,     0,     0,    18,     1,     5,    22,     0,
      95,     0,    91,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    52,     0,     0,     0,    55,    44,     0,    46,
      45,    13,    47,    34,     0,   161,     0,     0,     0,     0,
       0,     0,   131,     0,    50,     0,     0,   110,     0,    63,
       0,   102,    62,     0,   101,   100,     0,     0,     0,    17,
       0,     0,    93,    89,     0,    71,    66,    67,    68,    69,
      70,    85,    86,    82,    81,    83,    84,    87,    88,    72,
      73,    74,    75,    76,   222,   223,   234,    43,     0,     0,
       0,   157,     0,     0,     0,   187,   163,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,   235,     0,
       0,   107,   230,   100,    64,     0,    65,    20,     0,     0,
       0,    96,    94,    97,    90,     0,     0,     0,     0,     0,
       0,     0,     0,   162,   160,     0,     0,   138,   137,   135,
     235,   111,   136,   112,     0,   127,   129,   130,    15,     0,
       0,   118,     0,   123,     0,     0,    49,   116,   105,     0,
     104,     0,     0,   100,    19,     0,    92,   158,   159,   161,
     156,     0,   178,   168,   155,   189,   204,     0,     0,     0,
       0,     0,     0,     0,     0,   140,    22,   119,   125,     0,
       0,    48,    95,     0,   113,     0,   203,    98,    99,     0,
       0,     0,     0,     0,     0,   133,   132,     0,     0,     0,
       0,     0,     0,   134,     0,   117,   122,     0,   114,   115,
     103,    21,     0,     0,   164,     0,   151,   182,   181,   183,
     179,   180,   184,   185,     0,     0,   177,   166,     0,     0,
     172,   171,   173,   169,   170,   174,   175,   167,   176,   218,
     219,   186,     0,     0,     0,   188,   190,   191,   192,   141,
     142,   143,   144,   145,   139,   126,    51,   154,     0,     0,
       0,   149,   146,   147,     0,     0,   195,   212,     0,   207,
       0,     0,     0,     0,   220,   221,   198,     0,   212,     0,
     178,     0,   150,   148,   193,     0,   194,     0,   209,     0,
     211,     0,   205,     0,   206,     0,     0,   197,     0,   200,
       0,   210,     0,   165,   152,   202,     0,   196,   216,     0,
     215,     0,     0,     0,   199,   217,   213,     0,     0,   153,
     201,   214,     0,   208
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -187,  -187,  -187,  -187,  -186,   -72,  -187,  -187,   -23,  -187,
     400,  -187,  -187,   372,  -187,    -6,  -187,  -187,  -187,    -3,
       7,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,
       3,  -187,   275,   151,  -187,   279,  -182,  -122,    -1,  -187,
    -187,  -187,  -187,     1,  -187,  -187,  -187,  -187,  -187,   159,
       5,  -187,   248,  -187,  -187,   140,   150,  -187,  -187,  -187,
    -187,  -187,   228,   181,  -187,   252,  -187,  -187,    64,  -187,
    -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -187,  -137,
    -187,  -187,  -187,  -187,    69,  -187,  -187,    31,  -187,  -187,
    -187,   311,  -187,  -187,   261
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    26,    27,    28,    29,    30,    31,    32,    85,   149,
      33,    63,    64,    65,    66,    34,    35,   195,   246,    36,
      37,    38,   142,   143,    39,    40,    41,    56,    42,    43,
      44,    91,    92,   152,   212,   144,   206,   145,    45,   249,
     200,    82,   232,    46,   284,    47,   240,   241,   242,   243,
      48,   131,   132,   229,   274,   275,   323,   324,   361,   325,
      49,   180,   181,   184,   185,   186,   293,   337,   292,   326,
     224,   294,   345,   346,   376,   386,   387,   398,   407,   389,
     347,   379,   394,   348,   377,   390,   409,   410,   338,   339,
     340,    50,    51,    52,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,   201,    75,    68,   133,    70,    88,    71,   238,    69,
      57,    72,    58,    84,   388,    79,    89,     1,   203,   148,
     251,   252,   413,   405,   367,    80,   392,     6,    96,    97,
      98,    73,   384,   153,    54,    55,   401,    76,   416,   368,
     400,   154,  -124,     6,   423,   385,   417,  -124,    77,   182,
     222,   406,   251,   402,   183,   113,   114,   266,    67,    90,
     251,    68,   266,    70,  -120,    71,   118,    69,    81,    72,
    -121,   288,    18,    83,   266,    84,   136,     9,    10,    11,
      12,    13,    14,   253,   266,   135,    17,    62,   267,   268,
     141,   146,   178,    83,   238,    84,    78,  -204,   179,  -204,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,     1,
     174,   175,   239,   245,     2,   113,   114,    94,    95,    96,
      97,    98,   182,   197,   192,    86,     3,   183,   279,   193,
     341,    84,   117,   280,     5,   199,   122,   141,   244,   342,
     343,   344,   115,     2,   208,   209,   113,   114,   211,   119,
     349,   350,   351,   352,   353,     3,   302,   295,   230,   231,
     251,   303,    74,     5,   139,     1,     6,   140,   120,     9,
      10,    11,    12,    13,    14,   296,   235,   121,   251,    62,
     247,   236,   227,   228,   250,    19,    20,    21,    22,    23,
      24,    25,   124,   261,   248,   134,   125,   262,   239,   137,
     147,   148,   141,   138,   151,   276,   126,   127,   128,   129,
     130,   187,   150,   258,    19,    20,    21,    22,    23,    24,
      25,     2,   176,   188,   189,     9,    10,    11,    12,    13,
      14,     2,   393,     3,   190,    62,   191,   194,   205,     4,
     399,     5,     2,     3,   269,   270,   271,   272,   273,   204,
     210,     5,   289,     2,     3,   140,   215,   216,   217,   414,
     218,   219,     5,   305,   220,     3,   221,   308,   225,   310,
     226,   422,   234,     5,   309,     6,   317,   330,  -108,   318,
     331,   320,   333,   321,   334,   319,   332,   322,   335,   251,
     257,   256,    19,    20,    21,    22,    23,    24,    25,   259,
     263,   355,    19,    20,    21,    22,    23,    24,    25,   264,
     358,   265,   266,    19,    20,    21,    22,    23,    24,    25,
     411,   281,   277,   283,    19,    20,   198,    22,    23,    24,
      25,    -4,     1,   278,   282,   285,     2,   286,   287,   291,
     297,   298,    94,    95,    96,    97,    98,   299,     3,   101,
     102,   103,   104,   300,     4,   304,     5,   301,   312,   313,
       6,   359,   356,   357,   366,   362,   360,     7,   363,   364,
     383,   113,   114,   365,   371,   369,   374,   372,   396,   317,
     375,   381,   318,     8,   320,   382,   321,   378,   319,   380,
     322,   373,     9,    10,    11,    12,    13,    14,    15,    -3,
       1,   420,    16,    17,     2,    18,   397,    19,    20,    21,
      22,    23,    24,    25,   408,   412,     3,   418,    87,   214,
     213,   415,     4,   307,     5,   419,   123,   223,     6,   306,
     290,   237,   354,   336,   395,     7,   260,   391,   421,   202,
       0,   233,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       9,    10,    11,    12,    13,    14,    15,     0,     1,     0,
      16,    17,     2,    18,     0,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     3,     0,     0,     0,     0,     0,
       4,     0,     5,     0,     0,     0,     6,   327,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   328,   329,     0,   315,   316,     0,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     9,    10,
      11,    12,    13,    14,     0,     0,     1,     0,    62,    17,
       2,    18,     0,    19,    20,    21,    22,    23,    24,    25,
       0,     0,     3,     0,     0,     0,     0,     0,     4,     0,
       5,     0,     0,     0,     6,   -33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     9,    10,    11,    12,
      13,    14,     0,    59,    60,    61,    62,    17,     0,    18,
       0,    19,    20,    21,    22,    23,    24,    25,     1,     0,
       0,     0,     2,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     3,     0,     0,     0,     0,     0,
       4,     0,     5,     0,     0,     0,     6,   -32,     0,     0,
       0,     0,   113,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     9,    10,
      11,    12,    13,    14,     0,    59,    60,    61,    62,    17,
       0,    18,     0,    19,    20,    21,    22,    23,    24,    25,
       1,     0,     0,     0,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,     0,     0,     0,
       0,     0,     4,     0,     5,     0,     0,     0,     6,   314,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   315,   316,     0,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       9,    10,    11,    12,    13,    14,     0,     0,     1,     0,
      62,    17,     2,    18,     0,    19,    20,    21,    22,    23,
      24,    25,     0,     0,     3,     0,     0,     0,     0,     0,
       4,     0,     5,     0,     0,     0,     6,   403,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   315,   316,     0,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,     9,    10,
      11,    12,    13,    14,     0,     0,     0,     0,    62,    17,
       0,    18,     0,    19,    20,    21,    22,    23,    24,    25,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,     0,   254,     0,     0,   255,     0,
     113,   114,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,     0,   107,   108,   109,
     110,   111,   112,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   113,   114,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,     0,   107,
     108,   109,   110,   111,     0,     0,     0,   116,     0,     0,
       0,     0,     0,     0,   113,   114,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,   107,   108,   109,   110,   111,   177,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   113,   114,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,   196,     0,     0,     0,     0,     0,     0,   113,   114,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,     0,   207,     0,     0,     0,     0,
     113,   114,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,     0,   107,   108,   109,
     110,   111,     0,     0,     0,     0,     0,   254,     0,     0,
       0,     0,   113,   114,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,     0,   107,
     108,   109,   110,   111,     0,     0,     0,     0,     0,   311,
       0,     0,     0,     0,   113,   114,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,   107,   108,   109,   110,   111,     0,     0,     0,   370,
       0,     0,     0,     0,     0,     0,   113,   114,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,     0,   107,   108,   109,   110,   111,     0,     0,
       0,     0,     0,     0,     0,   404,     0,     0,   113,   114,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,     0,   107,   108,   109,   110,   111,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     113,   114,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,   114
};

static const yytype_int16 yycheck[] =
{
       6,   138,     8,     6,    76,     6,    29,     6,   194,     6,
       3,     6,     5,    27,    30,    25,    35,     1,   140,    27,
      31,   203,    43,    23,    29,    35,    30,    29,     6,     7,
       8,    78,    30,    23,    79,    80,    30,    78,    23,    44,
      51,    31,    26,    29,    23,    43,    31,    31,    78,    37,
      38,    51,    31,    24,    42,    33,    34,    78,    64,    78,
      31,    64,    78,    64,    78,    64,    59,    64,    78,    64,
      78,   253,    74,    25,    78,    27,    79,    61,    62,    63,
      64,    65,    66,   205,    78,    78,    72,    71,   225,   226,
      83,    84,    50,    25,   280,    27,    25,    29,    56,    31,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,     1,
     113,   114,   194,   195,     5,    33,    34,     4,     5,     6,
       7,     8,    37,   136,    26,     0,    17,    42,    26,    31,
      30,    27,    23,    31,    25,   138,    30,   140,    30,    39,
      40,    41,    32,     5,   147,   148,    33,    34,   151,    23,
     297,   298,   299,   300,   301,    17,    23,    28,    78,    79,
      31,    28,    25,    25,    26,     1,    29,    29,    23,    61,
      62,    63,    64,    65,    66,    28,   192,    78,    31,    71,
     196,   192,    58,    59,   200,    76,    77,    78,    79,    80,
      81,    82,    25,    25,   197,    29,    29,    29,   280,    78,
      27,    27,   205,    75,     3,   238,    53,    54,    55,    56,
      57,     3,    78,   216,    76,    77,    78,    79,    80,    81,
      82,     5,    78,     3,     3,    61,    62,    63,    64,    65,
      66,     5,   379,    17,     3,    71,     3,    25,    31,    23,
     387,    25,     5,    17,     4,     5,     6,     7,     8,    26,
       3,    25,   255,     5,    17,    29,     3,     3,    26,   406,
      31,    78,    25,   279,    78,    17,    30,   283,    27,   285,
      27,   418,    27,    25,   283,    29,   292,   293,    29,   292,
     293,   292,   293,   292,   293,   292,   293,   292,   293,    31,
      81,    78,    76,    77,    78,    79,    80,    81,    82,    29,
      29,   304,    76,    77,    78,    79,    80,    81,    82,    23,
     313,    29,    78,    76,    77,    78,    79,    80,    81,    82,
     402,    23,    35,    73,    76,    77,    78,    79,    80,    81,
      82,     0,     1,    78,    78,    26,     5,    78,    30,    56,
      24,    24,     4,     5,     6,     7,     8,    24,    17,    11,
      12,    13,    14,    24,    23,     3,    25,    24,    30,     3,
      29,    29,    23,    23,    29,    23,    25,    36,    23,    78,
     373,    33,    34,    78,    78,    29,    23,    43,   381,   395,
      23,    31,   395,    52,   395,    26,   395,    29,   395,    29,
     395,    47,    61,    62,    63,    64,    65,    66,    67,     0,
       1,    23,    71,    72,     5,    74,    51,    76,    77,    78,
      79,    80,    81,    82,    78,    51,    17,    51,    28,   154,
     151,    60,    23,   282,    25,    78,    64,   185,    29,   280,
     259,   193,   302,   293,   380,    36,   218,   378,   417,   138,
      -1,   190,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    67,    -1,     1,    -1,
      71,    72,     5,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    25,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    46,    -1,    48,    49,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    66,    -1,    -1,     1,    -1,    71,    72,
       5,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
      -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,    23,    -1,
      25,    -1,    -1,    -1,    29,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    66,    -1,    68,    69,    70,    71,    72,    -1,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,     1,    -1,
      -1,    -1,     5,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    17,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    25,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    -1,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    66,    -1,    68,    69,    70,    71,    72,
      -1,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
       1,    -1,    -1,    -1,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    23,    -1,    25,    -1,    -1,    -1,    29,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,    49,    -1,
      -1,    52,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    -1,    -1,     1,    -1,
      71,    72,     5,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    -1,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      23,    -1,    25,    -1,    -1,    -1,    29,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    48,    49,    -1,    -1,    52,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    -1,    71,    72,
      -1,    74,    -1,    76,    77,    78,    79,    80,    81,    82,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    31,    -1,
      33,    34,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    33,    34,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    34,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    -1,    33,    34,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,    -1,    -1,
      33,    34,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    -1,    18,    19,    20,
      21,    22,    -1,    -1,    -1,    -1,    -1,    28,    -1,    -1,
      -1,    -1,    33,    34,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    -1,    18,
      19,    20,    21,    22,    -1,    -1,    -1,    -1,    -1,    28,
      -1,    -1,    -1,    -1,    33,    34,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    -1,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    33,    34,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    -1,    18,    19,    20,    21,    22,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,    34,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    -1,    18,    19,    20,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      33,    34,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     5,    17,    23,    25,    29,    36,    52,    61,
      62,    63,    64,    65,    66,    67,    71,    72,    74,    76,
      77,    78,    79,    80,    81,    82,    84,    85,    86,    87,
      88,    89,    90,    93,    98,    99,   102,   103,   104,   107,
     108,   109,   111,   112,   113,   121,   126,   128,   133,   143,
     174,   175,   176,   177,    79,    80,   110,   103,   103,    68,
      69,    70,    71,    94,    95,    96,    97,    98,   102,   113,
     121,   126,   133,    78,    25,    98,    78,    78,    25,    25,
      35,    78,   124,    25,    27,    91,     0,    93,    91,    35,
      78,   114,   115,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    18,    19,    20,
      21,    22,    23,    33,    34,    32,    26,    23,   103,    23,
      23,    78,    30,    96,    25,    29,    53,    54,    55,    56,
      57,   134,   135,    88,    29,   103,   102,    78,    75,    26,
      29,   103,   105,   106,   118,   120,   103,    27,    27,    92,
      78,     3,   116,    23,    31,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,    78,    23,    50,    56,
     144,   145,    37,    42,   146,   147,   148,     3,     3,     3,
       3,     3,    26,    31,    25,   100,    26,   102,    78,   103,
     123,   162,   174,   120,    26,    31,   119,    28,   103,   103,
       3,   103,   117,   118,   115,     3,     3,    26,    31,    78,
      78,    30,    38,   148,   153,    27,    27,    58,    59,   136,
      78,    79,   125,   177,    27,    98,   121,   135,    87,    88,
     129,   130,   131,   132,    30,    88,   101,    98,   103,   122,
      98,    31,   119,   120,    28,    31,    78,    81,   103,    29,
     145,    25,    29,    29,    23,    29,    78,   162,   162,     4,
       5,     6,     7,     8,   137,   138,    91,    35,    78,    26,
      31,    23,    78,    73,   127,    26,    78,    30,   119,   103,
     146,    56,   151,   149,   154,    28,    28,    24,    24,    24,
      24,    24,    23,    28,     3,    98,   132,   116,    98,   126,
      98,    28,    30,     3,    30,    48,    49,    98,   102,   113,
     121,   126,   133,   139,   140,   142,   152,    30,    45,    46,
      98,   102,   113,   121,   126,   133,   139,   150,   171,   172,
     173,    30,    39,    40,    41,   155,   156,   163,   166,   162,
     162,   162,   162,   162,   138,   103,    23,    23,   103,    29,
      25,   141,    23,    23,    78,    78,    29,    29,    44,    29,
      26,    78,    43,    47,    23,    23,   157,   167,    29,   164,
      29,    31,    26,   103,    30,    43,   158,   159,    30,   162,
     168,   167,    30,   162,   165,   151,   103,    51,   160,   162,
      51,    30,    24,    30,    30,    23,    51,   161,    78,   169,
     170,    88,    51,    43,   162,    60,    23,    31,    51,    78,
      23,   170,   162,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    87,    87,    87,    88,    88,    89,    90,    91,
      91,    92,    92,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    94,    94,    95,    95,    96,    96,    96,    96,
      96,    96,    96,    97,    97,    97,    97,    98,    99,   100,
     100,   101,   102,   102,   103,   103,   103,   103,   103,   103,
     103,   103,   104,   105,   105,   106,   107,   107,   107,   107,
     107,   108,   108,   108,   108,   108,   108,   109,   109,   110,
     110,   111,   111,   111,   111,   111,   111,   112,   112,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   119,
     119,   120,   120,   121,   121,   122,   122,   123,   123,   124,
     124,   125,   125,   126,   126,   127,   127,   128,   129,   129,
     130,   130,   131,   131,   131,   132,   132,   133,   133,   133,
     134,   134,   135,   135,   135,   135,   135,   136,   136,   137,
     137,   138,   138,   138,   138,   138,   139,   139,   140,   140,
     141,   141,   142,   142,   143,   143,   144,   144,   145,   145,
     146,   146,   147,   147,   148,   148,   148,   149,   149,   150,
     150,   150,   150,   150,   150,   150,   150,   151,   151,   152,
     152,   152,   152,   152,   152,   152,   153,   153,   154,   154,
     155,   155,   155,   156,   157,   157,   158,   159,   159,   160,
     160,   161,   161,   162,   162,   163,   164,   164,   165,   166,
     166,   167,   167,   168,   169,   169,   170,   170,   171,   171,
     172,   173,   174,   174,   175,   175,   175,   175,   175,   175,
     175,   176,   176,   176,   177,   177
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     3,     2,     4,
       3,     5,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     2,     2,     3,     6,     2,
       0,     4,     2,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     1,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     4,     2,     2,     0,     1,     1,     4,     3,
       0,     1,     1,     7,     5,     1,     0,     1,     1,     1,
       2,     1,     1,     6,     7,     2,     0,     7,     1,     2,
       1,     2,     3,     1,     0,     2,     4,     5,     2,     5,
       3,     1,     5,     5,     5,     3,     3,     1,     1,     3,
       1,     3,     3,     3,     3,     3,     2,     2,     4,     2,
       3,     0,     6,     8,     9,     6,     3,     1,     3,     3,
       2,     0,     2,     1,     5,    10,     5,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     0,     1,
       1,     1,     1,     1,     1,     1,     4,     0,     2,     0,
       1,     1,     1,     4,     2,     0,     3,     2,     0,     3,
       1,     3,     1,     3,     1,     4,     2,     0,     6,     4,
       5,     2,     0,     4,     3,     1,     1,     2,     1,     1,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 14: /* generic_dtypes: error  */
#line 63 "parser.y"
            { 
        char error_message[10000];

    }
#line 2214 "y.tab.c"
    break;


#line 2218 "y.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 538 "parser.y"

int main(void) {
	yyparse();
}

