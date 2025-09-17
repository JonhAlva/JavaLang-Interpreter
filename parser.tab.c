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
    #include <stdlib.h>
    #include "./Functions/AST.h"

    extern int yylex();
    extern int yylineno;
    void yyerror(const char* s);  

    Nodo* raiz = NULL;

#line 83 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_S_PUNTO_COMA = 3,               /* S_PUNTO_COMA  */
  YYSYMBOL_PARENTESIS_OPEN = 4,            /* PARENTESIS_OPEN  */
  YYSYMBOL_PARENTESIS_CLOSE = 5,           /* PARENTESIS_CLOSE  */
  YYSYMBOL_S_PUNTO_PUNTO = 6,              /* S_PUNTO_PUNTO  */
  YYSYMBOL_SWITCH_WORD = 7,                /* SWITCH_WORD  */
  YYSYMBOL_CASE_WORD = 8,                  /* CASE_WORD  */
  YYSYMBOL_BREAK_WORD = 9,                 /* BREAK_WORD  */
  YYSYMBOL_DEFAULT_WORD = 10,              /* DEFAULT_WORD  */
  YYSYMBOL_WHILE_WORD = 11,                /* WHILE_WORD  */
  YYSYMBOL_OP_AUMENTO = 12,                /* OP_AUMENTO  */
  YYSYMBOL_OP_DECREMENTO = 13,             /* OP_DECREMENTO  */
  YYSYMBOL_PRINT_SENTENCE = 14,            /* PRINT_SENTENCE  */
  YYSYMBOL_FUNC_EQUALS = 15,               /* FUNC_EQUALS  */
  YYSYMBOL_IF_WORD = 16,                   /* IF_WORD  */
  YYSYMBOL_LLAVE_OPEN = 17,                /* LLAVE_OPEN  */
  YYSYMBOL_LLAVE_CLOSE = 18,               /* LLAVE_CLOSE  */
  YYSYMBOL_ELSE_WORD = 19,                 /* ELSE_WORD  */
  YYSYMBOL_FOR_WORD = 20,                  /* FOR_WORD  */
  YYSYMBOL_CONTINUE_WORD = 21,             /* CONTINUE_WORD  */
  YYSYMBOL_RETURN_WORD = 22,               /* RETURN_WORD  */
  YYSYMBOL_CORCHETE_OPEN = 23,             /* CORCHETE_OPEN  */
  YYSYMBOL_CORCHETE_CLOSE = 24,            /* CORCHETE_CLOSE  */
  YYSYMBOL_COMA = 25,                      /* COMA  */
  YYSYMBOL_JOIN_STRING = 26,               /* JOIN_STRING  */
  YYSYMBOL_ARRAY_INDEX = 27,               /* ARRAY_INDEX  */
  YYSYMBOL_FUNC_LENGTH = 28,               /* FUNC_LENGTH  */
  YYSYMBOL_FUNC_ADD = 29,                  /* FUNC_ADD  */
  YYSYMBOL_MAIN_STRING = 30,               /* MAIN_STRING  */
  YYSYMBOL_FLOAT_SUFFIX = 31,              /* FLOAT_SUFFIX  */
  YYSYMBOL_LOGIC_NOT = 32,                 /* LOGIC_NOT  */
  YYSYMBOL_INT_NUMBER = 33,                /* INT_NUMBER  */
  YYSYMBOL_OP_MENOR_A = 34,                /* OP_MENOR_A  */
  YYSYMBOL_OP_MAYOR_A = 35,                /* OP_MAYOR_A  */
  YYSYMBOL_36_ = 36,                       /* '+'  */
  YYSYMBOL_37_ = 37,                       /* '-'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* '*'  */
  YYSYMBOL_40_ = 40,                       /* '%'  */
  YYSYMBOL_FLOAT_NUMBER = 41,              /* FLOAT_NUMBER  */
  YYSYMBOL_STRING_COMILLAS = 42,           /* STRING_COMILLAS  */
  YYSYMBOL_PARSE_INT = 43,                 /* PARSE_INT  */
  YYSYMBOL_PARSE_FLOAT = 44,               /* PARSE_FLOAT  */
  YYSYMBOL_PARSE_DOUBLE = 45,              /* PARSE_DOUBLE  */
  YYSYMBOL_PARSE_STRING = 46,              /* PARSE_STRING  */
  YYSYMBOL_BOOL_VALUE = 47,                /* BOOL_VALUE  */
  YYSYMBOL_NULL_VALUE = 48,                /* NULL_VALUE  */
  YYSYMBOL_OP_MENOR_IGUAL_A = 49,          /* OP_MENOR_IGUAL_A  */
  YYSYMBOL_OP_MAYOR_IGUAL_A = 50,          /* OP_MAYOR_IGUAL_A  */
  YYSYMBOL_OP_IGUAL_IGUAL = 51,            /* OP_IGUAL_IGUAL  */
  YYSYMBOL_OP_DISTINTO_A = 52,             /* OP_DISTINTO_A  */
  YYSYMBOL_LOGIC_AND = 53,                 /* LOGIC_AND  */
  YYSYMBOL_LOGIC_OR = 54,                  /* LOGIC_OR  */
  YYSYMBOL_IDENTIFICADOR = 55,             /* IDENTIFICADOR  */
  YYSYMBOL_S_IGUAL = 56,                   /* S_IGUAL  */
  YYSYMBOL_OP_MAS_IGUAL = 57,              /* OP_MAS_IGUAL  */
  YYSYMBOL_OP_MENOS_IGUAL = 58,            /* OP_MENOS_IGUAL  */
  YYSYMBOL_OP_MULTI_IGUAL = 59,            /* OP_MULTI_IGUAL  */
  YYSYMBOL_OP_DIV_IGUAL = 60,              /* OP_DIV_IGUAL  */
  YYSYMBOL_OP_MOD_IGUAL = 61,              /* OP_MOD_IGUAL  */
  YYSYMBOL_OP_AND_IGUAL = 62,              /* OP_AND_IGUAL  */
  YYSYMBOL_OP_OR_IGUAL = 63,               /* OP_OR_IGUAL  */
  YYSYMBOL_OP_POT_IGUAL = 64,              /* OP_POT_IGUAL  */
  YYSYMBOL_OP_MAYOR_IGUAL = 65,            /* OP_MAYOR_IGUAL  */
  YYSYMBOL_OP_MENOR_IGUAL = 66,            /* OP_MENOR_IGUAL  */
  YYSYMBOL_DATA_TYPE = 67,                 /* DATA_TYPE  */
  YYSYMBOL_NEW_WORD = 68,                  /* NEW_WORD  */
  YYSYMBOL_YYACCEPT = 69,                  /* $accept  */
  YYSYMBOL_input = 70,                     /* input  */
  YYSYMBOL_lista_instrucciones = 71,       /* lista_instrucciones  */
  YYSYMBOL_instruccion = 72,               /* instruccion  */
  YYSYMBOL_print = 73,                     /* print  */
  YYSYMBOL_declaration = 74,               /* declaration  */
  YYSYMBOL_parse_expretion = 75,           /* parse_expretion  */
  YYSYMBOL_string_join = 76,               /* string_join  */
  YYSYMBOL_array_funcs = 77,               /* array_funcs  */
  YYSYMBOL_vector = 78,                    /* vector  */
  YYSYMBOL_vector_type = 79,               /* vector_type  */
  YYSYMBOL_vector_values = 80,             /* vector_values  */
  YYSYMBOL_matriz = 81,                    /* matriz  */
  YYSYMBOL_matriz_type = 82,               /* matriz_type  */
  YYSYMBOL_matriz_values = 83,             /* matriz_values  */
  YYSYMBOL_dynamic_array = 84,             /* dynamic_array  */
  YYSYMBOL_dynamic_corchete = 85,          /* dynamic_corchete  */
  YYSYMBOL_dynamic_data_declaration = 86,  /* dynamic_data_declaration  */
  YYSYMBOL_asignation = 87,                /* asignation  */
  YYSYMBOL_expr_bridge = 88,               /* expr_bridge  */
  YYSYMBOL_op_expr = 89,                   /* op_expr  */
  YYSYMBOL_native_func = 90,               /* native_func  */
  YYSYMBOL_variable_access = 91,           /* variable_access  */
  YYSYMBOL_if_sentence = 92,               /* if_sentence  */
  YYSYMBOL_if_else_one = 93,               /* if_else_one  */
  YYSYMBOL_if_else_chain = 94,             /* if_else_chain  */
  YYSYMBOL_for_sentence = 95,              /* for_sentence  */
  YYSYMBOL_for_condition = 96,             /* for_condition  */
  YYSYMBOL_for_option = 97,                /* for_option  */
  YYSYMBOL_switch_case = 98,               /* switch_case  */
  YYSYMBOL_switch_case_one = 99,           /* switch_case_one  */
  YYSYMBOL_switch_case_list = 100,         /* switch_case_list  */
  YYSYMBOL_switch_default = 101,           /* switch_default  */
  YYSYMBOL_while_sentence = 102,           /* while_sentence  */
  YYSYMBOL_function_sentence = 103,        /* function_sentence  */
  YYSYMBOL_parameters_bridge = 104,        /* parameters_bridge  */
  YYSYMBOL_function_parameters_declaration = 105, /* function_parameters_declaration  */
  YYSYMBOL_function_parameters_access = 106, /* function_parameters_access  */
  YYSYMBOL_expr = 107                      /* expr  */
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
#define YYLAST   1046

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  323

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   318


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
       2,     2,     2,     2,     2,     2,     2,    40,     2,     2,
       2,     2,    39,    36,     2,    37,     2,    38,     2,     2,
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
      35,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    70,    71,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    89,    90,    94,    97,   100,   103,
     105,   107,   109,   112,   115,   117,   122,   123,   124,   125,
     129,   134,   137,   143,   148,   151,   154,   160,   162,   168,
     174,   177,   183,   185,   191,   195,   196,   200,   201,   207,
     208,   209,   221,   222,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   243,   246,   249,   252,   255,
     258,   264,   267,   273,   276,   279,   284,   289,   309,   318,
     324,   326,   331,   332,   336,   342,   348,   369,   378,   382,
     387,   393,   399,   402,   405,   414,   423,   437,   446,   460,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   484,   485,   486,   487,   488,
     489,   490,   491,   493
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
  "\"end of file\"", "error", "\"invalid token\"", "S_PUNTO_COMA",
  "PARENTESIS_OPEN", "PARENTESIS_CLOSE", "S_PUNTO_PUNTO", "SWITCH_WORD",
  "CASE_WORD", "BREAK_WORD", "DEFAULT_WORD", "WHILE_WORD", "OP_AUMENTO",
  "OP_DECREMENTO", "PRINT_SENTENCE", "FUNC_EQUALS", "IF_WORD",
  "LLAVE_OPEN", "LLAVE_CLOSE", "ELSE_WORD", "FOR_WORD", "CONTINUE_WORD",
  "RETURN_WORD", "CORCHETE_OPEN", "CORCHETE_CLOSE", "COMA", "JOIN_STRING",
  "ARRAY_INDEX", "FUNC_LENGTH", "FUNC_ADD", "MAIN_STRING", "FLOAT_SUFFIX",
  "LOGIC_NOT", "INT_NUMBER", "OP_MENOR_A", "OP_MAYOR_A", "'+'", "'-'",
  "'/'", "'*'", "'%'", "FLOAT_NUMBER", "STRING_COMILLAS", "PARSE_INT",
  "PARSE_FLOAT", "PARSE_DOUBLE", "PARSE_STRING", "BOOL_VALUE",
  "NULL_VALUE", "OP_MENOR_IGUAL_A", "OP_MAYOR_IGUAL_A", "OP_IGUAL_IGUAL",
  "OP_DISTINTO_A", "LOGIC_AND", "LOGIC_OR", "IDENTIFICADOR", "S_IGUAL",
  "OP_MAS_IGUAL", "OP_MENOS_IGUAL", "OP_MULTI_IGUAL", "OP_DIV_IGUAL",
  "OP_MOD_IGUAL", "OP_AND_IGUAL", "OP_OR_IGUAL", "OP_POT_IGUAL",
  "OP_MAYOR_IGUAL", "OP_MENOR_IGUAL", "DATA_TYPE", "NEW_WORD", "$accept",
  "input", "lista_instrucciones", "instruccion", "print", "declaration",
  "parse_expretion", "string_join", "array_funcs", "vector", "vector_type",
  "vector_values", "matriz", "matriz_type", "matriz_values",
  "dynamic_array", "dynamic_corchete", "dynamic_data_declaration",
  "asignation", "expr_bridge", "op_expr", "native_func", "variable_access",
  "if_sentence", "if_else_one", "if_else_chain", "for_sentence",
  "for_condition", "for_option", "switch_case", "switch_case_one",
  "switch_case_list", "switch_default", "while_sentence",
  "function_sentence", "parameters_bridge",
  "function_parameters_declaration", "function_parameters_access", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-227)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-87)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,    15,    18,    29,    48,    51,    89,    34,   382,   132,
     -15,    97,     6,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,  -227,    54,  -227,  -227,  -227,  -227,  -227,    52,  -227,
     196,   110,   196,    53,  -227,  -227,   196,   196,  -227,   106,
     113,  -227,  -227,   139,   404,     2,  -227,  -227,   196,  -227,
    -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
     562,   166,   143,     8,  -227,  -227,   196,   170,   591,   114,
     179,   613,   634,   -13,   196,   197,   641,  -227,  -227,   200,
     201,  -227,   196,   196,   196,   196,   196,   196,   196,   196,
     196,   196,   196,   196,   196,  -227,   154,   206,   190,   193,
     966,   854,    33,   214,  -227,   966,  -227,    37,  -227,     2,
     199,   441,    -5,   463,   208,   209,   233,   238,   225,    65,
     487,   228,  -227,   196,   196,   195,   195,   182,   182,  -227,
    -227,  -227,   195,   195,   470,   470,   994,   987,  -227,   245,
     185,   196,   226,  -227,   229,   198,   250,  -227,    58,   253,
     257,  -227,  -227,  -227,  -227,   107,   258,   261,   271,   508,
     252,   213,  -227,   275,     6,  -227,  -227,     6,   230,   545,
     234,     6,   677,   684,  -227,   235,   966,   196,   236,   -10,
     277,   287,   259,   240,   196,  -227,   196,  -227,  -227,  -227,
    -227,   232,   196,  -227,   192,   249,  -227,    80,   111,   266,
    -227,  -227,  -227,   875,   256,   196,   285,   251,  -227,     6,
     264,   298,   300,    11,   705,   307,   812,    86,  -227,   310,
    -227,  -227,  -227,    -3,    45,   966,   327,   312,   289,   334,
     196,   196,   335,   337,   196,    43,     6,   196,   336,   330,
     133,  -227,   332,   283,  -227,   349,   196,   196,   321,  -227,
    -227,    84,   727,  -227,  -227,   896,  -227,   196,   152,   833,
       6,  -227,   353,     6,   340,   196,   121,   346,  -227,   966,
     748,   339,   364,  -227,  -227,   917,   368,     6,     6,   196,
     306,   164,   135,   371,   359,   196,   375,   381,  -227,  -227,
     130,   380,   755,  -227,   384,     6,  -227,  -227,   196,   938,
    -227,  -227,   387,   376,   196,   325,   146,   372,   168,     6,
     791,  -227,  -227,   196,   344,   386,   959,  -227,     6,   394,
     361,  -227,  -227
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     4,     7,     5,    24,    19,    20,    21,
       6,     9,     0,     8,    12,    10,    11,    13,     0,    67,
       0,     0,     0,     0,    66,    68,     0,     0,   106,   108,
     109,   110,   111,   112,     0,    95,    82,    83,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     1,     3,     0,     0,     0,   112,
       0,     0,     0,     0,     0,     0,     0,   121,   107,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    94,     0,     0,    92,    93,
      99,     0,   112,     0,    53,    52,    65,     0,    16,    95,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   105,     0,     0,   113,   114,   100,   101,   103,
     102,   104,   115,   116,   117,   118,   119,   120,    97,     0,
       0,     0,    71,    49,     0,     0,     0,    46,     0,     0,
       0,    26,    28,    27,    29,   112,     0,     0,     0,     0,
       0,     0,    50,     0,     0,    15,    14,     0,     0,     0,
       0,     0,     0,     0,    70,     0,    98,     0,     0,     0,
       0,     0,     0,     0,     0,    32,     0,    25,    22,    17,
      45,     0,     0,    87,     0,     0,    81,   112,     0,     0,
     123,   122,    96,     0,     0,     0,     0,     0,    33,     0,
       0,     0,     0,     0,     0,     0,     0,    89,    90,    73,
      80,    79,    72,     0,     0,    38,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,    39,     0,     0,     0,     0,    91,
      18,     0,     0,    51,    23,     0,    44,     0,     0,     0,
       0,    84,     0,     0,     0,     0,     0,     0,    35,    37,
       0,     0,     0,    31,    48,     0,     0,     0,    88,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    30,    47,
      67,     0,     0,    74,     0,     0,    43,    41,     0,     0,
      36,    34,     0,     0,     0,     0,     0,     0,    67,     0,
       0,    75,    42,     0,     0,     0,     0,    76,     0,     0,
       0,    40,    77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -227,  -227,  -162,   -12,  -227,   365,  -227,  -227,  -227,  -227,
    -227,  -226,  -227,  -227,  -227,  -227,  -227,  -227,  -227,  -227,
    -227,   373,   -57,  -227,  -227,  -227,  -227,  -227,   207,  -227,
    -227,  -227,  -227,  -227,  -227,   297,  -227,   224,    -7
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,   156,    16,   157,    17,
     208,   224,    18,   244,   266,    19,   112,   235,    20,   103,
      60,    21,    22,    23,   241,   264,    24,    75,    61,    25,
     193,   217,   239,    26,    27,    97,    98,    99,   225
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    44,   194,   104,   251,   195,    36,   205,    62,   199,
      62,   108,   109,     1,   242,     2,   232,     3,   160,    28,
       4,    29,     5,    68,    71,    72,     6,     7,     8,    76,
      77,   110,    95,    30,    37,    38,   141,    34,   100,   282,
      63,   101,   119,    39,    40,   206,   256,   228,    80,    41,
      42,   161,    31,   105,   158,    32,    48,    43,   207,   113,
     144,     9,    36,   245,   111,   243,   257,   120,   108,    96,
     246,   168,   306,    10,   258,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   110,   272,
      37,    38,   145,    33,   237,    80,   238,    64,   278,    39,
      40,   280,   100,    48,   159,    41,    42,    67,   185,   246,
      66,   184,   158,    43,    36,   291,   172,   173,    45,     2,
      73,   169,    80,    46,    47,   181,    46,    47,    79,    80,
      48,     7,     8,   305,   176,   185,    45,    78,   -85,   283,
     -85,    76,    37,    38,    46,    47,   284,   314,   -85,   262,
     263,    39,    40,   296,    80,    48,   320,    41,    42,     1,
     246,   276,   159,     3,   312,    69,     4,   107,     5,   106,
     203,   246,     6,     7,     8,   114,   -86,   100,   -86,   214,
     294,   295,    65,    65,   116,   216,   -86,    65,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,     1,
      36,     2,   121,     3,   123,   124,     4,     9,     5,   138,
     218,   139,     6,     7,     8,   140,    65,   143,   141,    10,
      86,    87,    88,   147,   252,   163,   164,   255,    37,    38,
     259,    84,    85,    86,    87,    88,   165,    39,    40,   269,
     270,   166,   167,    41,    42,   171,    65,     9,   174,   177,
     275,    43,   175,   178,   179,   180,     1,   182,     2,    10,
       3,   183,   186,     4,   187,     5,    65,   219,    65,     6,
       7,     8,   292,     1,   188,     2,   190,     3,   299,    65,
       4,   191,     5,   192,   221,   196,     6,     7,     8,   198,
     202,   204,   210,    65,   209,   212,     1,   310,     2,   215,
       3,   211,    65,     4,     9,     5,   316,   249,    65,     6,
       7,     8,   223,     1,   226,     2,    10,     3,   227,   229,
       4,     9,     5,   230,   293,   231,     6,     7,     8,   240,
     234,   247,     1,    10,     2,   248,     3,   250,   253,     4,
     254,     5,   260,   311,     9,     6,     7,     8,   261,   265,
     267,     1,   268,     2,   271,     3,    10,   279,     4,   281,
       5,     9,   317,   287,     6,     7,     8,   288,     1,   285,
       2,   290,     3,    10,   297,     4,   298,     5,   300,   322,
       9,     6,     7,     8,   301,    35,    36,     1,   304,   302,
     308,     3,    10,   309,     4,   313,     5,   321,    74,     9,
       6,     7,     8,   318,    70,   220,   146,    81,   213,     0,
       0,    10,     0,     0,    37,    38,     9,     0,     0,     0,
       0,     0,     0,    39,    40,     0,     0,     0,    10,    41,
      42,     0,     0,     0,     0,     9,     0,    43,    82,    83,
      84,    85,    86,    87,    88,   148,     0,    10,     0,     0,
       0,     0,     0,    89,    90,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,     0,   162,   149,   150,     0,
       0,     0,     0,    37,    38,     0,     0,     0,     0,     0,
       0,     0,    39,    40,   151,   152,   153,   154,    41,    42,
     170,     0,     0,     0,     0,     0,   155,    82,    83,    84,
      85,    86,    87,    88,    82,    83,    84,    85,    86,    87,
      88,   189,    89,    90,    91,    92,    93,    94,     0,    89,
      90,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
      93,    94,    82,    83,    84,    85,    86,    87,    88,   148,
       0,     0,     0,     0,     0,     0,     0,    89,    90,    91,
      92,    93,    94,     0,     0,     0,    36,     0,     0,     0,
       0,   149,   150,     0,     0,     0,     0,    37,    38,     0,
       0,     0,     0,     0,     0,     0,    39,    40,   151,   152,
     153,   154,    41,    42,    37,    38,   115,     0,     0,     0,
     197,     0,     0,    39,    40,     0,     0,     0,     0,    41,
      42,     0,     0,     0,     0,     0,     0,   102,   117,     0,
       0,     0,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,     0,     0,     0,     0,   118,
      89,    90,    91,    92,    93,    94,   122,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,     0,     0,     0,
       0,     0,    89,    90,    91,    92,    93,    94,    82,    83,
      84,    85,    86,    87,    88,    82,    83,    84,    85,    86,
      87,    88,   200,    89,    90,    91,    92,    93,    94,   201,
      89,    90,    91,    92,    93,    94,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     233,    82,    83,    84,    85,    86,    87,    88,    82,    83,
      84,    85,    86,    87,    88,     0,    89,    90,    91,    92,
      93,    94,   273,    89,    90,    91,    92,    93,    94,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,     0,
       0,     0,     0,   286,    89,    90,    91,    92,    93,    94,
     303,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
      93,    94,    82,    83,    84,    85,    86,    87,    88,    82,
      83,    84,    85,    86,    87,    88,   315,    89,    90,    91,
      92,    93,    94,     0,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,   236,     0,
       0,     0,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,     0,     0,     0,     0,   277,
      89,    90,    91,    92,    93,    94,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,    89,    90,    91,    92,    93,    94,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,     0,   142,     0,
       0,     0,    89,    90,    91,    92,    93,    94,    82,    83,
      84,    85,    86,    87,    88,     0,     0,     0,     0,   222,
       0,     0,     0,    89,    90,    91,    92,    93,    94,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,     0,
     274,     0,     0,     0,    89,    90,    91,    92,    93,    94,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
       0,   289,     0,     0,     0,    89,    90,    91,    92,    93,
      94,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,     0,   307,     0,     0,     0,    89,    90,    91,    92,
      93,    94,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,   319,     0,     0,     0,    89,    90,    91,
      92,    93,    94,    82,    83,    84,    85,    86,    87,    88,
      82,    83,    84,    85,    86,    87,    88,     0,    89,    90,
      91,    92,    93,    94,     0,    89,    90,    91,    92,    93,
      94,    82,    83,    84,    85,    86,    87,    88,    82,    83,
      84,    85,    86,    87,    88,     0,    89,    90,    91,    92,
      93,     0,     0,    89,    90,    91,    92
};

static const yytype_int16 yycheck[] =
{
      12,     8,   164,    60,   230,   167,     4,    17,    23,   171,
      23,     3,     4,     7,    17,     9,     5,    11,    23,     4,
      14,     3,    16,    30,    31,    32,    20,    21,    22,    36,
      37,    23,    30,     4,    32,    33,    25,     3,    45,   265,
      55,    48,    55,    41,    42,    55,     3,   209,    15,    47,
      48,    56,     4,    60,   111,     4,    23,    55,    68,    66,
      23,    55,     4,    18,    56,    68,    23,    74,     3,    67,
      25,     6,   298,    67,   236,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    23,     5,
      32,    33,    55,     4,     8,    15,    10,     0,   260,    41,
      42,   263,   109,    23,   111,    47,    48,    55,    28,    25,
      56,     4,   169,    55,     4,   277,   123,   124,     4,     9,
      67,    56,    15,    12,    13,    67,    12,    13,    15,    15,
      23,    21,    22,   295,   141,    28,     4,    31,     8,    18,
      10,   148,    32,    33,    12,    13,    25,   309,    18,    16,
      17,    41,    42,    18,    15,    23,   318,    47,    48,     7,
      25,     9,   169,    11,    18,    55,    14,    24,    16,     3,
     177,    25,    20,    21,    22,     5,     8,   184,    10,   186,
      16,    17,   194,   195,     5,   192,    18,   199,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     7,
       4,     9,     5,    11,     4,     4,    14,    55,    16,    55,
      18,     5,    20,    21,    22,    25,   228,     3,    25,    67,
      38,    39,    40,    24,   231,    17,    17,   234,    32,    33,
     237,    36,    37,    38,    39,    40,     3,    41,    42,   246,
     247,     3,    17,    47,    48,    17,   258,    55,     3,    23,
     257,    55,    67,    24,    56,     5,     7,     4,     9,    67,
      11,     4,     4,    14,     3,    16,   278,    18,   280,    20,
      21,    22,   279,     7,     3,     9,    24,    11,   285,   291,
      14,    68,    16,     8,    18,    55,    20,    21,    22,    55,
      55,    55,     5,   305,    17,    55,     7,   304,     9,    67,
      11,    42,   314,    14,    55,    16,   313,    18,   320,    20,
      21,    22,    56,     7,    29,     9,    67,    11,    67,    55,
      14,    55,    16,    25,    18,    25,    20,    21,    22,    19,
      23,     4,     7,    67,     9,    23,    11,     3,     3,    14,
       3,    16,     6,    18,    55,    20,    21,    22,    18,    17,
      67,     7,     3,     9,    33,    11,    67,     4,    14,    19,
      16,    55,    18,    24,    20,    21,    22,     3,     7,    23,
       9,     3,    11,    67,     3,    14,    17,    16,     3,    18,
      55,    20,    21,    22,     3,     3,     4,     7,     4,     9,
       3,    11,    67,    17,    14,    23,    16,     3,    33,    55,
      20,    21,    22,    17,    31,   198,   109,     3,   184,    -1,
      -1,    67,    -1,    -1,    32,    33,    55,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    -1,    -1,    -1,    67,    47,
      48,    -1,    -1,    -1,    -1,    55,    -1,    55,    34,    35,
      36,    37,    38,    39,    40,     4,    -1,    67,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    26,    27,    -1,
      -1,    -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    43,    44,    45,    46,    47,    48,
       3,    -1,    -1,    -1,    -1,    -1,    55,    34,    35,    36,
      37,    38,    39,    40,    34,    35,    36,    37,    38,    39,
      40,     3,    49,    50,    51,    52,    53,    54,    -1,    49,
      50,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    34,    35,    36,    37,    38,    39,    40,     4,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,     4,    -1,    -1,    -1,
      -1,    26,    27,    -1,    -1,    -1,    -1,    32,    33,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,
      45,    46,    47,    48,    32,    33,     5,    -1,    -1,    -1,
      55,    -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    47,
      48,    -1,    -1,    -1,    -1,    -1,    -1,    55,     5,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
      49,    50,    51,    52,    53,    54,     5,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    34,    35,
      36,    37,    38,    39,    40,    34,    35,    36,    37,    38,
      39,    40,     5,    49,    50,    51,    52,    53,    54,     5,
      49,    50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,    34,    35,    36,    37,    38,    39,    40,    34,    35,
      36,    37,    38,    39,    40,    -1,    49,    50,    51,    52,
      53,    54,     5,    49,    50,    51,    52,    53,    54,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     5,    49,    50,    51,    52,    53,    54,
       5,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    34,    35,    36,    37,    38,    39,    40,    34,
      35,    36,    37,    38,    39,    40,     5,    49,    50,    51,
      52,    53,    54,    -1,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      49,    50,    51,    52,    53,    54,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    24,    -1,
      -1,    -1,    49,    50,    51,    52,    53,    54,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    24,
      -1,    -1,    -1,    49,    50,    51,    52,    53,    54,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      24,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    24,    -1,    -1,    -1,    49,    50,    51,    52,
      53,    54,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    34,    35,    36,    37,    38,    39,    40,
      34,    35,    36,    37,    38,    39,    40,    -1,    49,    50,
      51,    52,    53,    54,    -1,    49,    50,    51,    52,    53,
      54,    34,    35,    36,    37,    38,    39,    40,    34,    35,
      36,    37,    38,    39,    40,    -1,    49,    50,    51,    52,
      53,    -1,    -1,    49,    50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     9,    11,    14,    16,    20,    21,    22,    55,
      67,    70,    71,    72,    73,    74,    76,    78,    81,    84,
      87,    90,    91,    92,    95,    98,   102,   103,     4,     3,
       4,     4,     4,     4,     3,     3,     4,    32,    33,    41,
      42,    47,    48,    55,   107,     4,    12,    13,    23,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      89,    97,    23,    55,     0,    72,    56,    55,   107,    55,
      90,   107,   107,    67,    74,    96,   107,   107,    31,    15,
      15,     3,    34,    35,    36,    37,    38,    39,    40,    49,
      50,    51,    52,    53,    54,    30,    67,   104,   105,   106,
     107,   107,    55,    88,    91,   107,     3,    24,     3,     4,
      23,    56,    85,   107,     5,     5,     5,     5,     5,    55,
     107,     5,     5,     4,     4,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,    55,     5,
      25,    25,    24,     3,    23,    55,   104,    24,     4,    26,
      27,    43,    44,    45,    46,    55,    75,    77,    91,   107,
      23,    56,     3,    17,    17,     3,     3,    17,     6,    56,
       3,    17,   107,   107,     3,    67,   107,    23,    24,    56,
       5,    67,     4,     4,     4,    28,     4,     3,     3,     3,
      24,    68,     8,    99,    71,    71,    55,    55,    55,    71,
       5,     5,    55,   107,    55,    17,    55,    68,    79,    17,
       5,    42,    55,   106,   107,    67,   107,   100,    18,    18,
      97,    18,    24,    56,    80,   107,    29,    67,    71,    55,
      25,    25,     5,     5,    23,    86,     6,     8,    10,   101,
      19,    93,    17,    68,    82,    18,    25,     4,    23,    18,
       3,    80,   107,     3,     3,   107,     3,    23,    71,   107,
       6,    18,    16,    17,    94,    17,    83,    67,     3,   107,
     107,    33,     5,     5,    24,   107,     9,     6,    71,     4,
      71,    19,    80,    18,    25,    23,     5,    24,     3,    24,
       3,    71,   107,    18,    16,    17,    18,     3,    17,   107,
       3,     3,     9,     5,     4,    71,    80,    24,     3,    17,
     107,    18,    18,    23,    71,     5,   107,    18,    17,    24,
      71,     3,    18
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    75,    75,    75,    75,
      76,    77,    77,    78,    79,    79,    79,    80,    80,    81,
      82,    82,    83,    83,    84,    85,    85,    86,    86,    87,
      87,    87,    88,    88,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    90,    90,    90,
      90,    91,    91,    92,    92,    92,    93,    94,    94,    95,
      96,    96,    97,    97,    98,    99,   100,   100,   101,   101,
     102,   103,   104,   104,   104,   104,   105,   105,   106,   106,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     3,     5,     8,     1,
       1,     1,     5,     8,     1,     5,     1,     1,     1,     1,
      10,     6,     2,     6,     6,     4,     6,     3,     1,     8,
       9,     4,     5,     3,     8,     3,     2,     4,     3,     4,
       4,     8,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     2,     2,     3,
       5,     4,     7,     7,    11,    13,     8,     9,     0,     7,
       5,     4,     1,     1,     9,     6,     7,     0,     3,     0,
       7,     8,     1,     1,     1,     0,     4,     2,     3,     1,
       3,     3,     3,     3,     3,     3,     1,     2,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     5,     5
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
  case 2: /* input: lista_instrucciones  */
#line 66 "parser.y"
                                                    { raiz = (yyvsp[0].nodo); yylineno = 1; }
#line 1538 "parser.tab.c"
    break;

  case 3: /* lista_instrucciones: lista_instrucciones instruccion  */
#line 70 "parser.y"
                                                    { (yyval.nodo) = ListaInstrucciones((yyvsp[-1].nodo), (yyvsp[0].nodo)); }
#line 1544 "parser.tab.c"
    break;

  case 4: /* lista_instrucciones: instruccion  */
#line 71 "parser.y"
                                                    { (yyval.nodo) = ListaInstrucciones((yyvsp[0].nodo), NULL); }
#line 1550 "parser.tab.c"
    break;

  case 5: /* instruccion: declaration  */
#line 75 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1556 "parser.tab.c"
    break;

  case 6: /* instruccion: asignation  */
#line 76 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1562 "parser.tab.c"
    break;

  case 7: /* instruccion: print  */
#line 77 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1568 "parser.tab.c"
    break;

  case 8: /* instruccion: if_sentence  */
#line 78 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1574 "parser.tab.c"
    break;

  case 9: /* instruccion: native_func  */
#line 79 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1580 "parser.tab.c"
    break;

  case 10: /* instruccion: switch_case  */
#line 80 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1586 "parser.tab.c"
    break;

  case 11: /* instruccion: while_sentence  */
#line 81 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1592 "parser.tab.c"
    break;

  case 12: /* instruccion: for_sentence  */
#line 82 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1598 "parser.tab.c"
    break;

  case 13: /* instruccion: function_sentence  */
#line 83 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1604 "parser.tab.c"
    break;

  case 14: /* print: PRINT_SENTENCE PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 89 "parser.y"
                                                                                    { (yyval.nodo) = Print((yyvsp[-2].nodo)); }
#line 1610 "parser.tab.c"
    break;

  case 15: /* print: PRINT_SENTENCE PARENTESIS_OPEN native_func PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 90 "parser.y"
                                                                                    { (yyval.nodo) = Print((yyvsp[-2].nodo)); }
#line 1616 "parser.tab.c"
    break;

  case 16: /* declaration: DATA_TYPE IDENTIFICADOR S_PUNTO_COMA  */
#line 95 "parser.y"
            {  (yyval.nodo) = Var_Declaration((yyvsp[-2].data_type), (yyvsp[-1].identificador), Terminal_Null("DEFAULT")); /* VARIABLE SIN VALOR*/ }
#line 1622 "parser.tab.c"
    break;

  case 17: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL expr S_PUNTO_COMA  */
#line 98 "parser.y"
            { (yyval.nodo) = Var_Declaration((yyvsp[-4].data_type), (yyvsp[-3].identificador), (yyvsp[-1].nodo)); }
#line 1628 "parser.tab.c"
    break;

  case 18: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL PARENTESIS_OPEN DATA_TYPE PARENTESIS_CLOSE IDENTIFICADOR S_PUNTO_COMA  */
#line 101 "parser.y"
            { (yyval.nodo) = Casteo_Narrowing((yyvsp[-7].data_type), (yyvsp[-6].identificador), (yyvsp[-3].data_type), (yyvsp[-1].identificador)); /* CASTEO NARROWING*/ }
#line 1634 "parser.tab.c"
    break;

  case 19: /* declaration: vector  */
#line 103 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); /* DECLARATION VECTOR */ }
#line 1640 "parser.tab.c"
    break;

  case 20: /* declaration: matriz  */
#line 105 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); /* MATRIZ */ }
#line 1646 "parser.tab.c"
    break;

  case 21: /* declaration: dynamic_array  */
#line 107 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("DYNAMIC_ARRAY NO IMPLEMENTADO AUN"); /* DYNAMIC_ARRAY */ }
#line 1652 "parser.tab.c"
    break;

  case 22: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL variable_access S_PUNTO_COMA  */
#line 110 "parser.y"
            { (yyval.nodo) = Vector_Asignation((yyvsp[-4].data_type), (yyvsp[-3].identificador), (yyvsp[-1].nodo)); /* ASIGNACION DE VARIABLE A VECTOR O MATRIZ */ }
#line 1658 "parser.tab.c"
    break;

  case 23: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL parse_expretion PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 113 "parser.y"
            { (yyval.nodo) = Parse_Expression((yyvsp[-6].identificador), (yyvsp[-7].data_type), (yyvsp[-4].identificador), (yyvsp[-2].nodo)); /* PARSEO DE TIPOS */ }
#line 1664 "parser.tab.c"
    break;

  case 24: /* declaration: string_join  */
#line 115 "parser.y"
                           { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1670 "parser.tab.c"
    break;

  case 25: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL array_funcs S_PUNTO_COMA  */
#line 118 "parser.y"
            { (yyval.nodo) = Array_func_Declaration((yyvsp[-4].data_type), (yyvsp[-3].identificador), (yyvsp[-1].nodo)); /* FUNCIONES DE ARRAYS */ }
#line 1676 "parser.tab.c"
    break;

  case 26: /* parse_expretion: PARSE_INT  */
#line 122 "parser.y"
                                     { (yyval.identificador) = "int"; }
#line 1682 "parser.tab.c"
    break;

  case 27: /* parse_expretion: PARSE_DOUBLE  */
#line 123 "parser.y"
                                     { (yyval.identificador) = "double"; }
#line 1688 "parser.tab.c"
    break;

  case 28: /* parse_expretion: PARSE_FLOAT  */
#line 124 "parser.y"
                                     { (yyval.identificador) = "float"; }
#line 1694 "parser.tab.c"
    break;

  case 29: /* parse_expretion: PARSE_STRING  */
#line 125 "parser.y"
                                     { (yyval.identificador) = "String"; }
#line 1700 "parser.tab.c"
    break;

  case 30: /* string_join: DATA_TYPE IDENTIFICADOR S_IGUAL JOIN_STRING PARENTESIS_OPEN STRING_COMILLAS COMA vector_values PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 130 "parser.y"
            { (yyval.nodo) = Var_Declaration((yyvsp[-9].data_type), (yyvsp[-8].identificador), Make_StringJoin((yyvsp[-9].data_type), (yyvsp[-4].string_comillas), (yyvsp[-2].lista_nodos))); }
#line 1706 "parser.tab.c"
    break;

  case 31: /* array_funcs: ARRAY_INDEX PARENTESIS_OPEN IDENTIFICADOR COMA expr PARENTESIS_CLOSE  */
#line 135 "parser.y"
            { (yyval.nodo) = Array_Index_Of((yyvsp[-3].identificador), (yyvsp[-1].nodo)); /* FUNCION INDEX OF PARA VECTORES */ }
#line 1712 "parser.tab.c"
    break;

  case 32: /* array_funcs: IDENTIFICADOR FUNC_LENGTH  */
#line 138 "parser.y"
            { (yyval.nodo) = Array_Length((yyvsp[-1].identificador)); /* FUNCION LENGTH PARA VECTORES */ }
#line 1718 "parser.tab.c"
    break;

  case 33: /* vector: DATA_TYPE CORCHETE_OPEN CORCHETE_CLOSE IDENTIFICADOR S_IGUAL vector_type  */
#line 144 "parser.y"
        { (yyval.nodo) = Declaration_Vector((yyvsp[-5].data_type), (yyvsp[-2].identificador), (yyvsp[0].nodo)); /* REGRESAMOS EL NODO QUE GENERA */ }
#line 1724 "parser.tab.c"
    break;

  case 34: /* vector_type: NEW_WORD DATA_TYPE CORCHETE_OPEN INT_NUMBER CORCHETE_CLOSE S_PUNTO_COMA  */
#line 149 "parser.y"
            { (yyval.nodo) = Vector_Auto((yyvsp[-4].data_type), (yyvsp[-2].int_number)); }
#line 1730 "parser.tab.c"
    break;

  case 35: /* vector_type: LLAVE_OPEN vector_values LLAVE_CLOSE S_PUNTO_COMA  */
#line 152 "parser.y"
            { (yyval.nodo) = Valores_Vector((yyvsp[-2].lista_nodos)); /* VECTOR CON VALORES */ }
#line 1736 "parser.tab.c"
    break;

  case 36: /* vector_type: IDENTIFICADOR FUNC_ADD PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 155 "parser.y"
            { (yyval.nodo) = Array_Add_Ref((yyvsp[-5].identificador), (yyvsp[-2].nodo)); /* FUNCION ADD EN VECTORES*/}
#line 1742 "parser.tab.c"
    break;

  case 37: /* vector_values: vector_values COMA expr  */
#line 161 "parser.y"
            { (yyval.lista_nodos) = Add_Valor_Vector((yyvsp[-2].lista_nodos), (yyvsp[0].nodo)); }
#line 1748 "parser.tab.c"
    break;

  case 38: /* vector_values: expr  */
#line 163 "parser.y"
            { (yyval.lista_nodos) = Lista_Vector((yyvsp[0].nodo)); }
#line 1754 "parser.tab.c"
    break;

  case 39: /* matriz: DATA_TYPE CORCHETE_OPEN CORCHETE_CLOSE CORCHETE_OPEN CORCHETE_CLOSE IDENTIFICADOR S_IGUAL matriz_type  */
#line 169 "parser.y"
        { (yyval.nodo) = Declaration_Matriz((yyvsp[-7].data_type), (yyvsp[-2].identificador), (yyvsp[0].nodo)); /* REGRESAMOS EL NODO QUE GENERA */ }
#line 1760 "parser.tab.c"
    break;

  case 40: /* matriz_type: NEW_WORD DATA_TYPE CORCHETE_OPEN expr CORCHETE_CLOSE CORCHETE_OPEN expr CORCHETE_CLOSE S_PUNTO_COMA  */
#line 175 "parser.y"
            { (yyval.nodo) = Matriz_Auto((yyvsp[-7].data_type), (yyvsp[-5].nodo), (yyvsp[-2].nodo)); /* valores definidos en matriz*/ }
#line 1766 "parser.tab.c"
    break;

  case 41: /* matriz_type: LLAVE_OPEN matriz_values LLAVE_CLOSE S_PUNTO_COMA  */
#line 178 "parser.y"
            { (yyval.nodo) = Nodo_Vacio("VALORES DE MATRIZ NO IMPLEMENTADO AUN"); /* valores definidos en matriz*/ }
#line 1772 "parser.tab.c"
    break;

  case 43: /* matriz_values: LLAVE_OPEN vector_values LLAVE_CLOSE  */
#line 186 "parser.y"
            { /* valores definidos en matriz*/}
#line 1778 "parser.tab.c"
    break;

  case 49: /* asignation: IDENTIFICADOR op_expr expr_bridge S_PUNTO_COMA  */
#line 207 "parser.y"
                                                                       { (yyval.nodo) = Asignacion_Variable((yyvsp[-3].identificador), (yyvsp[-2].identificador), (yyvsp[-1].nodo)); /* 'OPERADOR ASIGNACION' PARA UNA VARIABLE Y ASIGNACION NORMAL*/ }
#line 1784 "parser.tab.c"
    break;

  case 50: /* asignation: variable_access S_IGUAL expr S_PUNTO_COMA  */
#line 208 "parser.y"
                                                                       { (yyval.nodo) = Nodo_Vacio("VAR ACCEESS NO IMPLEMENTADO AUN");}
#line 1790 "parser.tab.c"
    break;

  case 51: /* asignation: DATA_TYPE IDENTIFICADOR S_IGUAL IDENTIFICADOR PARENTESIS_OPEN function_parameters_access PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 210 "parser.y"
            {
                Nodo* temp = Function_Call_Parameters((yyvsp[-4].identificador), (yyvsp[-2].lista_nodos));
                (yyval.nodo) = Asignation_function((yyvsp[-7].data_type), (yyvsp[-6].identificador), temp); /* ASIGNACION DE VARIABLE A UNA FUNCION CON PARAMETROS */
            }
#line 1799 "parser.tab.c"
    break;

  case 52: /* expr_bridge: expr  */
#line 221 "parser.y"
                                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1805 "parser.tab.c"
    break;

  case 53: /* expr_bridge: variable_access  */
#line 222 "parser.y"
                                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1811 "parser.tab.c"
    break;

  case 54: /* op_expr: S_IGUAL  */
#line 227 "parser.y"
                                { (yyval.identificador) = "="; }
#line 1817 "parser.tab.c"
    break;

  case 55: /* op_expr: OP_MAS_IGUAL  */
#line 228 "parser.y"
                                { (yyval.identificador) = "+="; }
#line 1823 "parser.tab.c"
    break;

  case 56: /* op_expr: OP_MENOS_IGUAL  */
#line 229 "parser.y"
                                { (yyval.identificador) = "-="; }
#line 1829 "parser.tab.c"
    break;

  case 57: /* op_expr: OP_MULTI_IGUAL  */
#line 230 "parser.y"
                                { (yyval.identificador) = "*="; }
#line 1835 "parser.tab.c"
    break;

  case 58: /* op_expr: OP_DIV_IGUAL  */
#line 231 "parser.y"
                                { (yyval.identificador) = "/="; }
#line 1841 "parser.tab.c"
    break;

  case 59: /* op_expr: OP_MOD_IGUAL  */
#line 232 "parser.y"
                                { (yyval.identificador) = "%="; }
#line 1847 "parser.tab.c"
    break;

  case 60: /* op_expr: OP_AND_IGUAL  */
#line 233 "parser.y"
                                { (yyval.identificador) = "&="; }
#line 1853 "parser.tab.c"
    break;

  case 61: /* op_expr: OP_OR_IGUAL  */
#line 234 "parser.y"
                                { (yyval.identificador) = "|="; }
#line 1859 "parser.tab.c"
    break;

  case 62: /* op_expr: OP_POT_IGUAL  */
#line 235 "parser.y"
                                { (yyval.identificador) = "^="; }
#line 1865 "parser.tab.c"
    break;

  case 63: /* op_expr: OP_MAYOR_IGUAL  */
#line 236 "parser.y"
                                { (yyval.identificador) = ">>="; }
#line 1871 "parser.tab.c"
    break;

  case 64: /* op_expr: OP_MENOR_IGUAL  */
#line 237 "parser.y"
                                { (yyval.identificador) = "<<="; }
#line 1877 "parser.tab.c"
    break;

  case 65: /* native_func: IDENTIFICADOR for_option S_PUNTO_COMA  */
#line 244 "parser.y"
            {(yyval.nodo) = Plus_Minus_Var((yyvsp[-2].identificador), (yyvsp[-1].identificador));}
#line 1883 "parser.tab.c"
    break;

  case 66: /* native_func: CONTINUE_WORD S_PUNTO_COMA  */
#line 247 "parser.y"
            { (yyval.nodo) = Continue_Word(); /* CONTINUE PARA CICLOS */ }
#line 1889 "parser.tab.c"
    break;

  case 67: /* native_func: BREAK_WORD S_PUNTO_COMA  */
#line 250 "parser.y"
            { (yyval.nodo) = Break_Word(); /* BREAK PARA CICLOS */ }
#line 1895 "parser.tab.c"
    break;

  case 68: /* native_func: RETURN_WORD S_PUNTO_COMA  */
#line 253 "parser.y"
            { (yyval.nodo) = Return_Word(); /* RETURN PARA FUNCIONES */ }
#line 1901 "parser.tab.c"
    break;

  case 69: /* native_func: RETURN_WORD expr S_PUNTO_COMA  */
#line 256 "parser.y"
            { (yyval.nodo) = Return_Value((yyvsp[-1].nodo)); /* RETURN PARA FUNCIONES */ }
#line 1907 "parser.tab.c"
    break;

  case 70: /* native_func: IDENTIFICADOR PARENTESIS_OPEN parameters_bridge PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 259 "parser.y"
            { (yyval.nodo) = Function_Call_No_Param((yyvsp[-4].identificador)); }
#line 1913 "parser.tab.c"
    break;

  case 71: /* variable_access: IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE  */
#line 265 "parser.y"
                {(yyval.nodo) = Vector_Reference((yyvsp[-3].identificador), (yyvsp[-1].nodo));/* ACCESO A VALOR EN UN VECTOR*/}
#line 1919 "parser.tab.c"
    break;

  case 72: /* variable_access: IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE CORCHETE_OPEN expr CORCHETE_CLOSE  */
#line 268 "parser.y"
                {(yyval.nodo) = Nodo_Vacio("MATRIZ NO IMPLEMENTADO AUN");/* ACCESO A VALOR EN UNA MATRIZ */}
#line 1925 "parser.tab.c"
    break;

  case 73: /* if_sentence: IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 274 "parser.y"
            { (yyval.nodo) = Sentencia_If_Simple((yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 1931 "parser.tab.c"
    break;

  case 74: /* if_sentence: IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE ELSE_WORD LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 277 "parser.y"
            { (yyval.nodo) = Sentencia_If_Else((yyvsp[-8].nodo), (yyvsp[-5].nodo), (yyvsp[-1].nodo)); }
#line 1937 "parser.tab.c"
    break;

  case 75: /* if_sentence: IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE if_else_one if_else_chain ELSE_WORD LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 280 "parser.y"
            { (yyval.nodo) = Sentencia_If_ElseIf_Else((yyvsp[-10].nodo), (yyvsp[-7].nodo), (yyvsp[-5].nodo), (yyvsp[-4].lista_nodos), (yyvsp[-1].nodo)); /* IF - ELSE IF - ELSE CON LISTA DE ELSE IF */ }
#line 1943 "parser.tab.c"
    break;

  case 76: /* if_else_one: ELSE_WORD IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 285 "parser.y"
            { (yyval.nodo) = If_Else_One((yyvsp[-4].nodo), (yyvsp[-1].nodo)); /* INSTRUCCIONES DEL ELSE IF SI SOLSO VIENE UNA VEZ */ }
#line 1949 "parser.tab.c"
    break;

  case 77: /* if_else_chain: if_else_chain ELSE_WORD IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 290 "parser.y"
                {  
                    // Obtener el tamaño actual de la lista
                    int size = 0;
                    while ((yyvsp[-8].lista_nodos) && (yyvsp[-8].lista_nodos)[size] != NULL) size++;
                    
                    // Crear nueva lista con un espacio adicional
                    (yyval.lista_nodos) = malloc(sizeof(Nodo*) * (size + 2));  // +1 para el nuevo nodo, +1 para NULL
                    
                    // Copiar nodos existentes
                    for(int i = 0; i < size; i++) {
                        (yyval.lista_nodos)[i] = (yyvsp[-8].lista_nodos)[i];
                    }
                    
                    // Agregar nuevo nodo else-if
                    (yyval.lista_nodos)[size] = Sentencia_ElseIf((yyvsp[-4].nodo), (yyvsp[-1].nodo), NULL);
                    (yyval.lista_nodos)[size + 1] = NULL;  // Terminar lista con NULL
                }
#line 1971 "parser.tab.c"
    break;

  case 78: /* if_else_chain: %empty  */
#line 309 "parser.y"
                { 
                // Inicializar lista vacía
                    (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 1);
                    (yyval.lista_nodos)[0] = NULL;
                }
#line 1981 "parser.tab.c"
    break;

  case 79: /* for_sentence: FOR_WORD PARENTESIS_OPEN for_condition PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 319 "parser.y"
            { (yyval.nodo) = For_Sentence((yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 1987 "parser.tab.c"
    break;

  case 80: /* for_condition: declaration expr S_PUNTO_COMA IDENTIFICADOR for_option  */
#line 325 "parser.y"
            { (yyval.nodo) = For_Condition((yyvsp[-4].nodo), (yyvsp[-3].nodo), (yyvsp[-1].identificador), (yyvsp[0].identificador)); }
#line 1993 "parser.tab.c"
    break;

  case 81: /* for_condition: DATA_TYPE IDENTIFICADOR S_PUNTO_PUNTO IDENTIFICADOR  */
#line 327 "parser.y"
            {  Nodo_Vacio("ESTRUCTURA FOR EACH"); /* Implementacion con los vectores */}
#line 1999 "parser.tab.c"
    break;

  case 82: /* for_option: OP_AUMENTO  */
#line 331 "parser.y"
                       { (yyval.identificador) = "++"; }
#line 2005 "parser.tab.c"
    break;

  case 83: /* for_option: OP_DECREMENTO  */
#line 332 "parser.y"
                            { (yyval.identificador) = "--"; }
#line 2011 "parser.tab.c"
    break;

  case 84: /* switch_case: SWITCH_WORD PARENTESIS_OPEN IDENTIFICADOR PARENTESIS_CLOSE LLAVE_OPEN switch_case_one switch_case_list switch_default LLAVE_CLOSE  */
#line 337 "parser.y"
            { (yyval.nodo) = Switch_Sentence((yyvsp[-6].identificador), (yyvsp[-3].nodo), (yyvsp[-2].lista_nodos), (yyvsp[-1].nodo)); }
#line 2017 "parser.tab.c"
    break;

  case 85: /* switch_case_one: CASE_WORD expr S_PUNTO_PUNTO lista_instrucciones BREAK_WORD S_PUNTO_COMA  */
#line 343 "parser.y"
                { (yyval.nodo) = Switch_Case_One((yyvsp[-4].nodo), (yyvsp[-2].nodo)); }
#line 2023 "parser.tab.c"
    break;

  case 86: /* switch_case_list: switch_case_list CASE_WORD expr S_PUNTO_PUNTO lista_instrucciones BREAK_WORD S_PUNTO_COMA  */
#line 349 "parser.y"
                {
                    // Obtener el tamaño actual de la lista
                    int size = 0;
                    while ((yyvsp[-6].lista_nodos) && (yyvsp[-6].lista_nodos)[size] != NULL) size++;
                    
                    // Crear nueva lista con un espacio adicional
                    (yyval.lista_nodos) = malloc(sizeof(Nodo*) * (size + 2));  // +1 para el nuevo nodo, +1 para NULL
                    
                    // Copiar nodos existentes
                    for(int i = 0; i < size; i++) {
                        (yyval.lista_nodos)[i] = (yyvsp[-6].lista_nodos)[i];
                    }
                    
                    // Agregar nuevo nodo case
                    (yyval.lista_nodos)[size] = Switch_Case_One((yyvsp[-4].nodo), (yyvsp[-2].nodo));
                    (yyval.lista_nodos)[size + 1] = NULL;  // Terminar lista con NULL
                }
#line 2045 "parser.tab.c"
    break;

  case 87: /* switch_case_list: %empty  */
#line 369 "parser.y"
                { 
                // Inicializar lista vacía
                    (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 1);
                    (yyval.lista_nodos)[0] = NULL;
                }
#line 2055 "parser.tab.c"
    break;

  case 88: /* switch_default: DEFAULT_WORD S_PUNTO_PUNTO lista_instrucciones  */
#line 379 "parser.y"
                { (yyval.nodo) = Switch_Default((yyvsp[0].nodo)); }
#line 2061 "parser.tab.c"
    break;

  case 89: /* switch_default: %empty  */
#line 382 "parser.y"
                { (yyval.nodo) = Nodo_Vacio("NO DEFAULT"); }
#line 2067 "parser.tab.c"
    break;

  case 90: /* while_sentence: WHILE_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 388 "parser.y"
                { (yyval.nodo) = While_Sentence((yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 2073 "parser.tab.c"
    break;

  case 91: /* function_sentence: DATA_TYPE IDENTIFICADOR PARENTESIS_OPEN parameters_bridge PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 394 "parser.y"
                { (yyval.nodo) = Funtion_Declaration((yyvsp[-7].data_type), (yyvsp[-6].identificador), (yyvsp[-4].lista_nodos), (yyvsp[-1].nodo)); /* DECLARACION DE FUNCIONES */ }
#line 2079 "parser.tab.c"
    break;

  case 92: /* parameters_bridge: function_parameters_declaration  */
#line 400 "parser.y"
                { (yyval.lista_nodos) = (yyvsp[0].lista_nodos); }
#line 2085 "parser.tab.c"
    break;

  case 93: /* parameters_bridge: function_parameters_access  */
#line 403 "parser.y"
                { (yyval.lista_nodos) = (yyvsp[0].lista_nodos); }
#line 2091 "parser.tab.c"
    break;

  case 94: /* parameters_bridge: MAIN_STRING  */
#line 406 "parser.y"
                {
                    // Create empty list with single node
                    (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 2);
                    (yyval.lista_nodos)[0] = Nodo_Vacio("NO PARAMETROS");
                    (yyval.lista_nodos)[1] = NULL;
                }
#line 2102 "parser.tab.c"
    break;

  case 95: /* parameters_bridge: %empty  */
#line 414 "parser.y"
                {
                    // Create empty list
                    (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 1);
                    (yyval.lista_nodos)[0] = Nodo_Vacio("NO PARAMETROS");
                }
#line 2112 "parser.tab.c"
    break;

  case 96: /* function_parameters_declaration: function_parameters_declaration COMA DATA_TYPE IDENTIFICADOR  */
#line 424 "parser.y"
                    {
                        int size = 0;
                        while ((yyvsp[-3].lista_nodos) && (yyvsp[-3].lista_nodos)[size] != NULL) size++;
                        
                        (yyval.lista_nodos) = malloc(sizeof(Nodo*) * (size + 2));
                        
                        for(int i = 0; i < size; i++) {
                            (yyval.lista_nodos)[i] = (yyvsp[-3].lista_nodos)[i];
                        }
                        
                        (yyval.lista_nodos)[size] = Var_Declaration((yyvsp[-1].data_type), (yyvsp[0].identificador), Terminal_Null("DEFAULT"));
                        (yyval.lista_nodos)[size + 1] = NULL;
                    }
#line 2130 "parser.tab.c"
    break;

  case 97: /* function_parameters_declaration: DATA_TYPE IDENTIFICADOR  */
#line 438 "parser.y"
                    {
                        (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 2);
                        (yyval.lista_nodos)[0] = Var_Declaration((yyvsp[-1].data_type), (yyvsp[0].identificador), Terminal_Null("DEFAULT"));
                        (yyval.lista_nodos)[1] = NULL;
                    }
#line 2140 "parser.tab.c"
    break;

  case 98: /* function_parameters_access: function_parameters_access COMA expr  */
#line 447 "parser.y"
                    {
                        int size = 0;
                        while ((yyvsp[-2].lista_nodos) && (yyvsp[-2].lista_nodos)[size] != NULL) size++;
                        
                        (yyval.lista_nodos) = malloc(sizeof(Nodo*) * (size + 2));
                        
                        for(int i = 0; i < size; i++) {
                            (yyval.lista_nodos)[i] = (yyvsp[-2].lista_nodos)[i];
                        }
                        
                        (yyval.lista_nodos)[size] = (yyvsp[0].nodo);
                        (yyval.lista_nodos)[size + 1] = NULL;
                    }
#line 2158 "parser.tab.c"
    break;

  case 99: /* function_parameters_access: expr  */
#line 461 "parser.y"
                    {
                        (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 2);
                        (yyval.lista_nodos)[0] = (yyvsp[0].nodo);
                        (yyval.lista_nodos)[1] = NULL;
                    }
#line 2168 "parser.tab.c"
    break;

  case 100: /* expr: expr '+' expr  */
#line 469 "parser.y"
                                                { (yyval.nodo) = Suma((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2174 "parser.tab.c"
    break;

  case 101: /* expr: expr '-' expr  */
#line 470 "parser.y"
                                                { (yyval.nodo) = Resta((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2180 "parser.tab.c"
    break;

  case 102: /* expr: expr '*' expr  */
#line 471 "parser.y"
                                                { (yyval.nodo) = Multiplicacion((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2186 "parser.tab.c"
    break;

  case 103: /* expr: expr '/' expr  */
#line 472 "parser.y"
                                                { (yyval.nodo) = Division((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2192 "parser.tab.c"
    break;

  case 104: /* expr: expr '%' expr  */
#line 473 "parser.y"
                                                { (yyval.nodo) = Modulo((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2198 "parser.tab.c"
    break;

  case 105: /* expr: PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 474 "parser.y"
                                                { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2204 "parser.tab.c"
    break;

  case 106: /* expr: INT_NUMBER  */
#line 475 "parser.y"
                                                { (yyval.nodo) = Terminal_Int((yyvsp[0].int_number)); }
#line 2210 "parser.tab.c"
    break;

  case 107: /* expr: FLOAT_NUMBER FLOAT_SUFFIX  */
#line 476 "parser.y"
                                                { (yyval.nodo) = Terminal_Float((yyvsp[-1].float_number)); }
#line 2216 "parser.tab.c"
    break;

  case 108: /* expr: FLOAT_NUMBER  */
#line 477 "parser.y"
                                                { (yyval.nodo) = Terminal_Double((yyvsp[0].float_number)); }
#line 2222 "parser.tab.c"
    break;

  case 109: /* expr: STRING_COMILLAS  */
#line 478 "parser.y"
                                                { if (strlen((yyvsp[0].string_comillas)) == 3) { (yyval.nodo) = Terminal_Char((yyvsp[0].string_comillas)[1]); } else { (yyval.nodo) = Terminal_String((yyvsp[0].string_comillas)); }}
#line 2228 "parser.tab.c"
    break;

  case 110: /* expr: BOOL_VALUE  */
#line 479 "parser.y"
                                                { (yyval.nodo) = Terminal_Bool((yyvsp[0].bool_true)); }
#line 2234 "parser.tab.c"
    break;

  case 111: /* expr: NULL_VALUE  */
#line 480 "parser.y"
                                                { (yyval.nodo) = Terminal_Null((yyvsp[0].null_value)); }
#line 2240 "parser.tab.c"
    break;

  case 112: /* expr: IDENTIFICADOR  */
#line 481 "parser.y"
                                                { (yyval.nodo) = Identificador_Ref((yyvsp[0].identificador));}
#line 2246 "parser.tab.c"
    break;

  case 113: /* expr: expr OP_MENOR_A expr  */
#line 482 "parser.y"
                                                { (yyval.nodo) = Menor_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2252 "parser.tab.c"
    break;

  case 114: /* expr: expr OP_MAYOR_A expr  */
#line 483 "parser.y"
                                                { (yyval.nodo) = Mayor_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2258 "parser.tab.c"
    break;

  case 115: /* expr: expr OP_MENOR_IGUAL_A expr  */
#line 484 "parser.y"
                                                { (yyval.nodo) = Menor_Igual_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2264 "parser.tab.c"
    break;

  case 116: /* expr: expr OP_MAYOR_IGUAL_A expr  */
#line 485 "parser.y"
                                                { (yyval.nodo) = Mayor_Igual_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2270 "parser.tab.c"
    break;

  case 117: /* expr: expr OP_IGUAL_IGUAL expr  */
#line 486 "parser.y"
                                                { (yyval.nodo) = Igual_Igual((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2276 "parser.tab.c"
    break;

  case 118: /* expr: expr OP_DISTINTO_A expr  */
#line 487 "parser.y"
                                                { (yyval.nodo) = Diferente_Que((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2282 "parser.tab.c"
    break;

  case 119: /* expr: expr LOGIC_AND expr  */
#line 488 "parser.y"
                                                { (yyval.nodo) = And((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2288 "parser.tab.c"
    break;

  case 120: /* expr: expr LOGIC_OR expr  */
#line 489 "parser.y"
                                                { (yyval.nodo) = Or((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2294 "parser.tab.c"
    break;

  case 121: /* expr: LOGIC_NOT expr  */
#line 490 "parser.y"
                                                { (yyval.nodo) = Not((yyvsp[0].nodo)); }
#line 2300 "parser.tab.c"
    break;

  case 122: /* expr: IDENTIFICADOR FUNC_EQUALS PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 492 "parser.y"
    { (yyval.nodo) = Equals_Compare((yyvsp[-4].identificador), (yyvsp[-1].nodo)); /* PRINT FUNC .EQUALS PARA UNA VARIABLE */ }
#line 2306 "parser.tab.c"
    break;

  case 123: /* expr: STRING_COMILLAS FUNC_EQUALS PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 494 "parser.y"
    { (yyval.nodo) = Equals_Compare((yyvsp[-4].string_comillas), (yyvsp[-1].nodo)); /* PRINT FUNC .EQUALS PARA UNA VARIABLE */ }
#line 2312 "parser.tab.c"
    break;


#line 2316 "parser.tab.c"

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

#line 497 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error: sintáctico en linea: %d\n", yylineno);
}
