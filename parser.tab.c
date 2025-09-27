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
  YYSYMBOL_UMINUS = 69,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 70,                  /* $accept  */
  YYSYMBOL_input = 71,                     /* input  */
  YYSYMBOL_lista_instrucciones = 72,       /* lista_instrucciones  */
  YYSYMBOL_instruccion = 73,               /* instruccion  */
  YYSYMBOL_print = 74,                     /* print  */
  YYSYMBOL_declaration = 75,               /* declaration  */
  YYSYMBOL_parse_expretion = 76,           /* parse_expretion  */
  YYSYMBOL_string_join = 77,               /* string_join  */
  YYSYMBOL_array_funcs = 78,               /* array_funcs  */
  YYSYMBOL_vector = 79,                    /* vector  */
  YYSYMBOL_vector_type = 80,               /* vector_type  */
  YYSYMBOL_vector_values = 81,             /* vector_values  */
  YYSYMBOL_matriz = 82,                    /* matriz  */
  YYSYMBOL_matriz_type = 83,               /* matriz_type  */
  YYSYMBOL_matriz_values = 84,             /* matriz_values  */
  YYSYMBOL_dynamic_array = 85,             /* dynamic_array  */
  YYSYMBOL_dynamic_corchete = 86,          /* dynamic_corchete  */
  YYSYMBOL_dynamic_data_declaration = 87,  /* dynamic_data_declaration  */
  YYSYMBOL_asignation = 88,                /* asignation  */
  YYSYMBOL_expr_bridge = 89,               /* expr_bridge  */
  YYSYMBOL_op_expr = 90,                   /* op_expr  */
  YYSYMBOL_native_func = 91,               /* native_func  */
  YYSYMBOL_variable_access = 92,           /* variable_access  */
  YYSYMBOL_matrix_access = 93,             /* matrix_access  */
  YYSYMBOL_if_sentence = 94,               /* if_sentence  */
  YYSYMBOL_if_else_one = 95,               /* if_else_one  */
  YYSYMBOL_if_else_chain = 96,             /* if_else_chain  */
  YYSYMBOL_for_sentence = 97,              /* for_sentence  */
  YYSYMBOL_for_condition = 98,             /* for_condition  */
  YYSYMBOL_for_option = 99,                /* for_option  */
  YYSYMBOL_switch_case = 100,              /* switch_case  */
  YYSYMBOL_switch_case_one = 101,          /* switch_case_one  */
  YYSYMBOL_switch_case_list = 102,         /* switch_case_list  */
  YYSYMBOL_switch_default = 103,           /* switch_default  */
  YYSYMBOL_while_sentence = 104,           /* while_sentence  */
  YYSYMBOL_function_sentence = 105,        /* function_sentence  */
  YYSYMBOL_parameters_bridge = 106,        /* parameters_bridge  */
  YYSYMBOL_function_parameters_declaration = 107, /* function_parameters_declaration  */
  YYSYMBOL_function_parameters_access = 108, /* function_parameters_access  */
  YYSYMBOL_expr = 109                      /* expr  */
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
#define YYFINAL  66
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1086

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  335

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


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
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    71,    72,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    90,    91,    95,    98,   101,   104,
     106,   108,   110,   113,   116,   119,   121,   124,   129,   130,
     131,   132,   136,   150,   153,   159,   164,   167,   170,   176,
     178,   184,   190,   193,   200,   219,   230,   234,   235,   239,
     240,   246,   249,   252,   255,   267,   268,   269,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   290,
     293,   296,   299,   302,   305,   311,   316,   322,   325,   328,
     333,   338,   358,   367,   373,   375,   380,   381,   385,   391,
     397,   418,   427,   431,   436,   442,   448,   451,   454,   463,
     472,   486,   495,   509,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,   540,   541,   543
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
  "OP_MAYOR_IGUAL", "OP_MENOR_IGUAL", "DATA_TYPE", "NEW_WORD", "UMINUS",
  "$accept", "input", "lista_instrucciones", "instruccion", "print",
  "declaration", "parse_expretion", "string_join", "array_funcs", "vector",
  "vector_type", "vector_values", "matriz", "matriz_type", "matriz_values",
  "dynamic_array", "dynamic_corchete", "dynamic_data_declaration",
  "asignation", "expr_bridge", "op_expr", "native_func", "variable_access",
  "matrix_access", "if_sentence", "if_else_one", "if_else_chain",
  "for_sentence", "for_condition", "for_option", "switch_case",
  "switch_case_one", "switch_case_list", "switch_default",
  "while_sentence", "function_sentence", "parameters_bridge",
  "function_parameters_declaration", "function_parameters_access", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-234)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-91)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     384,     7,    20,    34,    49,    69,    72,   107,   413,   142,
     -13,   100,   384,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,    87,    92,  -234,  -234,  -234,  -234,  -234,    42,
    -234,   630,   611,   630,    58,  -234,  -234,   630,   630,  -234,
     630,   119,   113,  -234,  -234,   138,   498,    94,  -234,  -234,
     630,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,  -234,   632,   155,   135,     9,  -234,  -234,   630,   630,
     161,   665,    59,   162,   686,   693,    -5,   630,   163,   729,
    -234,  -234,  -234,   165,   167,  -234,   630,   630,   630,   630,
     630,   630,   630,   630,   630,   630,   630,   630,   630,  -234,
     117,   168,   149,   150,  1006,   916,    41,   173,  -234,  -234,
    1006,  -234,    -4,  -234,    94,   153,   452,   -19,   522,   543,
     164,   166,   176,   177,   169,    11,   550,   171,  -234,   630,
     630,    75,    75,  -234,  -234,    80,    80,  -234,    75,    75,
     505,   505,  1013,  1034,  -234,   179,   122,   630,   170,  -234,
     160,   134,   190,  -234,    97,   193,   206,  -234,  -234,  -234,
    -234,    24,   208,   211,   212,   214,   588,   195,   157,  -234,
    -234,   213,   384,  -234,  -234,   384,   174,   476,   175,   384,
     736,   757,  -234,   178,  1006,   630,   182,   -10,   209,   223,
     189,   185,   613,  -234,   630,  -234,  -234,  -234,  -234,  -234,
     183,   630,  -234,   202,   227,  -234,    31,   120,   252,  -234,
    -234,  -234,   923,   188,   630,   203,   186,  -234,   384,   191,
     229,   230,   253,    16,   779,   237,   885,    98,  -234,   245,
     260,  -234,  -234,  -234,    -2,     2,  1006,   263,   248,   290,
     272,   630,   630,  -234,   273,   274,   630,    13,   384,   630,
     275,   261,   140,  -234,   266,   218,  -234,   283,   630,   630,
     254,  -234,  -234,    44,   800,  -234,  -234,   947,  -234,   630,
     404,   892,   384,  -234,   284,   384,   270,   630,     4,   269,
    -234,  1006,   807,   271,   293,  -234,  -234,   954,   295,   384,
     384,   630,   314,   146,    50,   297,   276,   630,   299,   300,
    -234,  -234,    85,   420,   843,  -234,   309,   384,  -234,  -234,
     630,   978,  -234,  -234,   312,   305,   630,   330,    74,   294,
      86,   384,   850,  -234,  -234,   630,   352,   307,   985,  -234,
     384,   313,   368,  -234,  -234
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     4,     7,     5,    25,    19,    20,    21,
       6,     9,     0,     0,     8,    12,    10,    11,    13,     0,
      71,     0,     0,     0,     0,    70,    72,     0,     0,   110,
       0,   113,   114,   115,   116,   117,     0,    99,    86,    87,
       0,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,     0,     0,     0,     0,     1,     3,     0,     0,
       0,     0,   117,     0,     0,     0,     0,     0,     0,     0,
     126,   111,   112,     0,     0,    73,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
       0,     0,    96,    97,   103,     0,   117,     0,    56,    57,
      55,    69,     0,    16,    99,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   109,     0,
       0,   118,   119,   104,   105,   107,   106,   108,   120,   121,
     122,   123,   124,   125,   101,     0,     0,     0,    75,    51,
       0,     0,     0,    48,     0,     0,     0,    28,    30,    29,
      31,   117,     0,     0,     0,     0,     0,     0,     0,    52,
      53,     0,     0,    15,    14,     0,     0,     0,     0,     0,
       0,     0,    74,     0,   102,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,    26,    22,    23,    17,    47,
       0,     0,    91,     0,     0,    85,   117,     0,     0,   128,
     127,   100,     0,     0,     0,     0,     0,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    93,    94,    77,
       0,    84,    83,    76,     0,     0,    40,     0,     0,     0,
       0,     0,     0,    27,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,    41,     0,     0,     0,
       0,    95,    18,     0,     0,    54,    24,     0,    46,     0,
       0,     0,     0,    88,     0,     0,     0,     0,     0,     0,
      37,    39,     0,     0,     0,    33,    50,     0,     0,     0,
      92,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      32,    49,    71,     0,     0,    78,     0,     0,    45,    43,
       0,     0,    38,    36,     0,     0,     0,     0,     0,     0,
      71,     0,     0,    79,    44,     0,     0,     0,     0,    80,
       0,     0,     0,    42,    81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -234,  -234,  -170,   -12,  -234,   292,  -234,  -234,  -234,  -234,
    -234,  -233,  -234,  -234,  -234,  -234,  -234,  -234,  -234,  -234,
    -234,   301,   -59,   -56,  -234,  -234,  -234,  -234,  -234,   124,
    -234,  -234,  -234,  -234,  -234,  -234,   215,  -234,   148,    -7
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,   162,    16,   163,    17,
     217,   235,    18,   256,   278,    19,   117,   247,    20,   107,
      62,    21,    22,    23,    24,   253,   276,    25,    78,    63,
      26,   202,   227,   251,    27,    28,   101,   102,   103,   236
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      67,    46,   203,   108,   167,   204,   109,   214,   263,   208,
      64,    29,   113,   114,   113,   254,   268,   176,    64,   150,
     257,   244,   295,    30,    71,    74,    75,   258,   192,   296,
      79,    80,   115,    81,   115,   230,   269,   168,    31,    84,
     104,   147,    65,   105,   294,   215,    84,    50,   239,   284,
     125,   151,   193,    32,    50,   110,    84,   164,   216,   193,
     165,   118,   119,    47,    50,   116,   255,   177,   308,   258,
     126,    48,    49,    33,    84,   258,    34,   318,   270,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   324,   -89,   -90,   -89,   -90,    70,    37,   258,
      66,    37,   290,   -89,   -90,   292,   249,   104,   250,   166,
      35,    88,    89,    90,    91,    92,    88,    89,   164,   303,
      92,   165,   180,   181,    99,    76,    38,    39,    83,    38,
      39,    40,    48,    49,    40,    41,    42,   317,    41,    42,
     184,    43,    44,    68,    43,    44,    47,    79,    69,    45,
      82,   326,    45,    84,    48,    49,   274,   275,   111,   112,
     332,   100,   306,   307,   189,    50,   120,   122,   127,   129,
     166,   130,   144,   145,   146,   147,   149,   153,   212,   173,
     174,   171,   182,   172,   186,   104,   175,   224,   179,   183,
     187,    67,    67,   185,   226,   188,    67,   190,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,     1,
     191,     2,   194,     3,   195,   196,     4,   197,     5,   199,
     228,   201,     6,     7,     8,   200,   218,    67,   219,   205,
     207,   220,   237,   211,     1,   264,     2,   213,     3,   267,
     221,     4,   271,     5,   234,   229,   240,     6,     7,     8,
     225,   281,   282,   238,   241,   242,   243,     9,    67,     1,
     246,     2,   287,     3,   252,   222,     4,   259,     5,    10,
     232,   260,     6,     7,     8,   262,   265,   266,    67,   273,
      67,   272,     9,   277,   304,   279,   280,   283,   291,   293,
     311,    67,   297,   310,    10,   299,   300,     1,   302,     2,
     309,     3,   312,   313,     4,    67,     5,     9,   261,   322,
       6,     7,     8,   316,    67,   320,   333,   325,   328,    10,
      67,     1,   321,     2,   330,     3,    77,     0,     4,   152,
       5,   231,   305,    73,     6,     7,     8,     1,     0,     2,
     223,     3,     0,     0,     4,     9,     5,     0,   323,     0,
       6,     7,     8,     0,     0,     0,     0,    10,     0,     1,
       0,     2,     0,     3,     0,     0,     4,     0,     5,     9,
     329,     0,     6,     7,     8,     1,     0,     2,     0,     3,
       0,    10,     4,     0,     5,     9,   334,     0,     6,     7,
       8,     1,     0,     2,     0,     3,     0,    10,     4,     0,
       5,     0,     0,     0,     6,     7,     8,     9,     0,     0,
       0,     1,     0,   288,     0,     3,    36,    37,     4,    10,
       5,     0,     0,     9,     6,     7,     8,     1,     0,   314,
       0,     3,     0,     0,     4,    10,     5,     0,     0,     9,
       6,     7,     8,     0,     0,    38,    39,     0,     0,     0,
      40,    10,     0,     0,    41,    42,   154,     0,     0,     9,
      43,    44,     0,     0,     0,     0,     0,     0,    45,     0,
       0,    10,     0,     0,     0,     9,     0,     0,   155,   156,
     154,     0,     0,     0,    38,    39,     0,    10,     0,    40,
       0,     0,     0,    41,    42,   157,   158,   159,   160,    43,
      44,    85,   155,   156,     0,     0,     0,   161,    38,    39,
       0,     0,     0,    40,     0,     0,     0,    41,    42,   157,
     158,   159,   160,    43,    44,   169,     0,     0,     0,     0,
       0,   206,    86,    87,    88,    89,    90,    91,    92,    86,
      87,    88,    89,    90,    91,    92,   170,    93,    94,    95,
      96,    97,    98,   178,    93,    94,    86,    87,    88,    89,
      90,    91,    92,     0,     0,     0,     0,     0,     0,     0,
       0,    93,    94,    95,    96,    97,    98,    86,    87,    88,
      89,    90,    91,    92,    86,    87,    88,    89,    90,    91,
      92,   198,    93,    94,    95,    96,    97,    98,     0,    93,
      94,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    37,     0,    37,   222,     0,
       2,     0,    86,    87,    88,    89,    90,    91,    92,     0,
       0,     0,     7,     8,    37,     0,    37,    93,    94,    95,
      96,    97,    98,    38,    39,    38,    39,     0,    40,     0,
      40,     0,    41,    42,    41,    42,     0,     0,    43,    44,
      43,    44,    38,    39,    38,    39,    72,    40,    45,    40,
     121,    41,    42,    41,    42,     0,     0,    43,    44,    43,
      44,     0,     0,     0,     0,    45,     0,   106,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,   124,    86,
      87,    88,    89,    90,    91,    92,     0,     0,     0,     0,
       0,     0,     0,     0,    93,    94,    95,    96,    97,    98,
      86,    87,    88,    89,    90,    91,    92,    86,    87,    88,
      89,    90,    91,    92,   128,    93,    94,    95,    96,    97,
      98,   209,    93,    94,    95,    96,    97,    98,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   210,    86,    87,    88,    89,    90,    91,    92,
      86,    87,    88,    89,    90,    91,    92,     0,    93,    94,
      95,    96,    97,    98,   245,    93,    94,    95,    96,    97,
      98,    86,    87,    88,    89,    90,    91,    92,     0,     0,
       0,     0,     0,     0,     0,   285,    93,    94,    95,    96,
      97,    98,   298,    86,    87,    88,    89,    90,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,    93,    94,
      95,    96,    97,    98,    86,    87,    88,    89,    90,    91,
      92,    86,    87,    88,    89,    90,    91,    92,   315,    93,
      94,    95,    96,    97,    98,   327,    93,    94,    95,    96,
      97,    98,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    86,    87,    88,
      89,    90,    91,    92,    86,    87,    88,    89,    90,    91,
      92,   248,    93,    94,    95,    96,    97,    98,   289,    93,
      94,    95,    96,    97,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    86,
      87,    88,    89,    90,    91,    92,    86,    87,    88,    89,
      90,    91,    92,     0,    93,    94,    95,    96,    97,    98,
     148,    93,    94,    95,    96,    97,    98,   233,     0,     0,
      86,    87,    88,    89,    90,    91,    92,    86,    87,    88,
      89,    90,    91,    92,     0,    93,    94,    95,    96,    97,
      98,   286,    93,    94,    95,    96,    97,    98,   301,     0,
       0,    86,    87,    88,    89,    90,    91,    92,    86,    87,
      88,    89,    90,    91,    92,     0,    93,    94,    95,    96,
      97,    98,   319,    93,    94,    95,    96,    97,    98,   331,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    86,
      87,    88,    89,    90,    91,    92,     0,    93,    94,    95,
      96,    97,    98,     0,    93,    94,    95,    96,    97,    98,
      86,    87,    88,    89,    90,    91,    92,    86,    87,    88,
      89,    90,    91,    92,     0,    93,    94,    95,    96,    97,
      98,     0,    93,    94,    95,    96,     0,    98,    86,    87,
      88,    89,    90,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,    93,    94,    95,    96
};

static const yytype_int16 yycheck[] =
{
      12,     8,   172,    62,    23,   175,    62,    17,   241,   179,
      23,     4,     3,     4,     3,    17,     3,     6,    23,    23,
      18,     5,    18,     3,    31,    32,    33,    25,     4,    25,
      37,    38,    23,    40,    23,     4,    23,    56,     4,    15,
      47,    25,    55,    50,   277,    55,    15,    23,   218,     5,
      55,    55,    28,     4,    23,    62,    15,   116,    68,    28,
     116,    68,    69,     4,    23,    56,    68,    56,    18,    25,
      77,    12,    13,     4,    15,    25,     4,   310,   248,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    18,     8,     8,    10,    10,    55,     4,    25,
       0,     4,   272,    18,    18,   275,     8,   114,    10,   116,
       3,    36,    37,    38,    39,    40,    36,    37,   177,   289,
      40,   177,   129,   130,    30,    67,    32,    33,    15,    32,
      33,    37,    12,    13,    37,    41,    42,   307,    41,    42,
     147,    47,    48,    56,    47,    48,     4,   154,    56,    55,
      31,   321,    55,    15,    12,    13,    16,    17,     3,    24,
     330,    67,    16,    17,    67,    23,     5,     5,     5,     4,
     177,     4,    55,     5,    25,    25,     3,    24,   185,     3,
       3,    17,     3,    17,    24,   192,    17,   194,    17,    67,
      56,   203,   204,    23,   201,     5,   208,     4,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,     7,
       4,     9,     4,    11,     3,     3,    14,     3,    16,    24,
      18,     8,    20,    21,    22,    68,    17,   239,     5,    55,
      55,    42,    29,    55,     7,   242,     9,    55,    11,   246,
      55,    14,   249,    16,    56,    18,    55,    20,    21,    22,
      67,   258,   259,    67,    25,    25,     3,    55,   270,     7,
      23,     9,   269,    11,    19,     5,    14,     4,    16,    67,
      18,    23,    20,    21,    22,     3,     3,     3,   290,    18,
     292,     6,    55,    17,   291,    67,     3,    33,     4,    19,
     297,   303,    23,    17,    67,    24,     3,     7,     3,     9,
       3,    11,     3,     3,    14,   317,    16,    55,    18,   316,
      20,    21,    22,     4,   326,     3,     3,    23,   325,    67,
     332,     7,    17,     9,    17,    11,    34,    -1,    14,   114,
      16,   207,    18,    32,    20,    21,    22,     7,    -1,     9,
     192,    11,    -1,    -1,    14,    55,    16,    -1,    18,    -1,
      20,    21,    22,    -1,    -1,    -1,    -1,    67,    -1,     7,
      -1,     9,    -1,    11,    -1,    -1,    14,    -1,    16,    55,
      18,    -1,    20,    21,    22,     7,    -1,     9,    -1,    11,
      -1,    67,    14,    -1,    16,    55,    18,    -1,    20,    21,
      22,     7,    -1,     9,    -1,    11,    -1,    67,    14,    -1,
      16,    -1,    -1,    -1,    20,    21,    22,    55,    -1,    -1,
      -1,     7,    -1,     9,    -1,    11,     3,     4,    14,    67,
      16,    -1,    -1,    55,    20,    21,    22,     7,    -1,     9,
      -1,    11,    -1,    -1,    14,    67,    16,    -1,    -1,    55,
      20,    21,    22,    -1,    -1,    32,    33,    -1,    -1,    -1,
      37,    67,    -1,    -1,    41,    42,     4,    -1,    -1,    55,
      47,    48,    -1,    -1,    -1,    -1,    -1,    -1,    55,    -1,
      -1,    67,    -1,    -1,    -1,    55,    -1,    -1,    26,    27,
       4,    -1,    -1,    -1,    32,    33,    -1,    67,    -1,    37,
      -1,    -1,    -1,    41,    42,    43,    44,    45,    46,    47,
      48,     3,    26,    27,    -1,    -1,    -1,    55,    32,    33,
      -1,    -1,    -1,    37,    -1,    -1,    -1,    41,    42,    43,
      44,    45,    46,    47,    48,     3,    -1,    -1,    -1,    -1,
      -1,    55,    34,    35,    36,    37,    38,    39,    40,    34,
      35,    36,    37,    38,    39,    40,     3,    49,    50,    51,
      52,    53,    54,     3,    49,    50,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    34,    35,    36,
      37,    38,    39,    40,    34,    35,    36,    37,    38,    39,
      40,     3,    49,    50,    51,    52,    53,    54,    -1,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     4,    -1,     4,     5,    -1,
       9,    -1,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    21,    22,     4,    -1,     4,    49,    50,    51,
      52,    53,    54,    32,    33,    32,    33,    -1,    37,    -1,
      37,    -1,    41,    42,    41,    42,    -1,    -1,    47,    48,
      47,    48,    32,    33,    32,    33,    55,    37,    55,    37,
       5,    41,    42,    41,    42,    -1,    -1,    47,    48,    47,
      48,    -1,    -1,    -1,    -1,    55,    -1,    55,    -1,    -1,
      -1,     5,    -1,    -1,    -1,    -1,    -1,    -1,     5,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,    54,
      34,    35,    36,    37,    38,    39,    40,    34,    35,    36,
      37,    38,    39,    40,     5,    49,    50,    51,    52,    53,
      54,     5,    49,    50,    51,    52,    53,    54,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,    34,    35,    36,    37,    38,    39,    40,
      34,    35,    36,    37,    38,    39,    40,    -1,    49,    50,
      51,    52,    53,    54,     5,    49,    50,    51,    52,    53,
      54,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     5,    49,    50,    51,    52,
      53,    54,     5,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,
      51,    52,    53,    54,    34,    35,    36,    37,    38,    39,
      40,    34,    35,    36,    37,    38,    39,    40,     5,    49,
      50,    51,    52,    53,    54,     5,    49,    50,    51,    52,
      53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    34,    35,    36,    37,    38,    39,
      40,     6,    49,    50,    51,    52,    53,    54,     6,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    34,    35,    36,    37,
      38,    39,    40,    -1,    49,    50,    51,    52,    53,    54,
      24,    49,    50,    51,    52,    53,    54,    24,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    34,    35,    36,
      37,    38,    39,    40,    -1,    49,    50,    51,    52,    53,
      54,    24,    49,    50,    51,    52,    53,    54,    24,    -1,
      -1,    34,    35,    36,    37,    38,    39,    40,    34,    35,
      36,    37,    38,    39,    40,    -1,    49,    50,    51,    52,
      53,    54,    24,    49,    50,    51,    52,    53,    54,    24,
      -1,    -1,    34,    35,    36,    37,    38,    39,    40,    34,
      35,    36,    37,    38,    39,    40,    -1,    49,    50,    51,
      52,    53,    54,    -1,    49,    50,    51,    52,    53,    54,
      34,    35,    36,    37,    38,    39,    40,    34,    35,    36,
      37,    38,    39,    40,    -1,    49,    50,    51,    52,    53,
      54,    -1,    49,    50,    51,    52,    -1,    54,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     9,    11,    14,    16,    20,    21,    22,    55,
      67,    71,    72,    73,    74,    75,    77,    79,    82,    85,
      88,    91,    92,    93,    94,    97,   100,   104,   105,     4,
       3,     4,     4,     4,     4,     3,     3,     4,    32,    33,
      37,    41,    42,    47,    48,    55,   109,     4,    12,    13,
      23,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    90,    99,    23,    55,     0,    73,    56,    56,
      55,   109,    55,    91,   109,   109,    67,    75,    98,   109,
     109,   109,    31,    15,    15,     3,    34,    35,    36,    37,
      38,    39,    40,    49,    50,    51,    52,    53,    54,    30,
      67,   106,   107,   108,   109,   109,    55,    89,    92,    93,
     109,     3,    24,     3,     4,    23,    56,    86,   109,   109,
       5,     5,     5,     5,     5,    55,   109,     5,     5,     4,
       4,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,    55,     5,    25,    25,    24,     3,
      23,    55,   106,    24,     4,    26,    27,    43,    44,    45,
      46,    55,    76,    78,    92,    93,   109,    23,    56,     3,
       3,    17,    17,     3,     3,    17,     6,    56,     3,    17,
     109,   109,     3,    67,   109,    23,    24,    56,     5,    67,
       4,     4,     4,    28,     4,     3,     3,     3,     3,    24,
      68,     8,   101,    72,    72,    55,    55,    55,    72,     5,
       5,    55,   109,    55,    17,    55,    68,    80,    17,     5,
      42,    55,     5,   108,   109,    67,   109,   102,    18,    18,
       4,    99,    18,    24,    56,    81,   109,    29,    67,    72,
      55,    25,    25,     3,     5,     5,    23,    87,     6,     8,
      10,   103,    19,    95,    17,    68,    83,    18,    25,     4,
      23,    18,     3,    81,   109,     3,     3,   109,     3,    23,
      72,   109,     6,    18,    16,    17,    96,    17,    84,    67,
       3,   109,   109,    33,     5,     5,    24,   109,     9,     6,
      72,     4,    72,    19,    81,    18,    25,    23,     5,    24,
       3,    24,     3,    72,   109,    18,    16,    17,    18,     3,
      17,   109,     3,     3,     9,     5,     4,    72,    81,    24,
       3,    17,   109,    18,    18,    23,    72,     5,   109,    18,
      17,    24,    72,     3,    18
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    76,    76,
      76,    76,    77,    78,    78,    79,    80,    80,    80,    81,
      81,    82,    83,    83,    84,    84,    85,    86,    86,    87,
      87,    88,    88,    88,    88,    89,    89,    89,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    91,
      91,    91,    91,    91,    91,    92,    93,    94,    94,    94,
      95,    96,    96,    97,    98,    98,    99,    99,   100,   101,
     102,   102,   103,   103,   104,   105,   106,   106,   106,   106,
     107,   107,   108,   108,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     3,     5,     8,     1,
       1,     1,     5,     5,     8,     1,     5,     7,     1,     1,
       1,     1,    10,     6,     2,     6,     6,     4,     6,     3,
       1,     8,     9,     4,     5,     3,     8,     3,     2,     4,
       3,     4,     4,     4,     8,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     2,     3,     5,     4,     7,     7,    11,    13,
       8,     9,     0,     7,     5,     4,     1,     1,     9,     6,
       7,     0,     3,     0,     7,     8,     1,     1,     1,     0,
       4,     2,     3,     1,     3,     3,     3,     3,     3,     3,
       1,     2,     2,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     5,     5
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
#line 67 "parser.y"
                                                    { raiz = (yyvsp[0].nodo); yylineno = 1; }
#line 1551 "parser.tab.c"
    break;

  case 3: /* lista_instrucciones: lista_instrucciones instruccion  */
#line 71 "parser.y"
                                                    { (yyval.nodo) = ListaInstrucciones((yyvsp[-1].nodo), (yyvsp[0].nodo)); }
#line 1557 "parser.tab.c"
    break;

  case 4: /* lista_instrucciones: instruccion  */
#line 72 "parser.y"
                                                    { (yyval.nodo) = ListaInstrucciones((yyvsp[0].nodo), NULL); }
#line 1563 "parser.tab.c"
    break;

  case 5: /* instruccion: declaration  */
#line 76 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1569 "parser.tab.c"
    break;

  case 6: /* instruccion: asignation  */
#line 77 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1575 "parser.tab.c"
    break;

  case 7: /* instruccion: print  */
#line 78 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1581 "parser.tab.c"
    break;

  case 8: /* instruccion: if_sentence  */
#line 79 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1587 "parser.tab.c"
    break;

  case 9: /* instruccion: native_func  */
#line 80 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1593 "parser.tab.c"
    break;

  case 10: /* instruccion: switch_case  */
#line 81 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1599 "parser.tab.c"
    break;

  case 11: /* instruccion: while_sentence  */
#line 82 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1605 "parser.tab.c"
    break;

  case 12: /* instruccion: for_sentence  */
#line 83 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1611 "parser.tab.c"
    break;

  case 13: /* instruccion: function_sentence  */
#line 84 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1617 "parser.tab.c"
    break;

  case 14: /* print: PRINT_SENTENCE PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 90 "parser.y"
                                                                                    { (yyval.nodo) = Print((yyvsp[-2].nodo)); }
#line 1623 "parser.tab.c"
    break;

  case 15: /* print: PRINT_SENTENCE PARENTESIS_OPEN native_func PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 91 "parser.y"
                                                                                    { (yyval.nodo) = Print((yyvsp[-2].nodo)); }
#line 1629 "parser.tab.c"
    break;

  case 16: /* declaration: DATA_TYPE IDENTIFICADOR S_PUNTO_COMA  */
#line 96 "parser.y"
            {  (yyval.nodo) = Var_Declaration((yyvsp[-2].data_type), (yyvsp[-1].identificador), Terminal_Null("DEFAULT")); /* VARIABLE SIN VALOR*/ }
#line 1635 "parser.tab.c"
    break;

  case 17: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL expr S_PUNTO_COMA  */
#line 99 "parser.y"
            { (yyval.nodo) = Var_Declaration((yyvsp[-4].data_type), (yyvsp[-3].identificador), (yyvsp[-1].nodo)); }
#line 1641 "parser.tab.c"
    break;

  case 18: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL PARENTESIS_OPEN DATA_TYPE PARENTESIS_CLOSE IDENTIFICADOR S_PUNTO_COMA  */
#line 102 "parser.y"
            { (yyval.nodo) = Casteo_Narrowing((yyvsp[-7].data_type), (yyvsp[-6].identificador), (yyvsp[-3].data_type), (yyvsp[-1].identificador)); /* CASTEO NARROWING*/ }
#line 1647 "parser.tab.c"
    break;

  case 19: /* declaration: vector  */
#line 104 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); /* DECLARATION VECTOR */ }
#line 1653 "parser.tab.c"
    break;

  case 20: /* declaration: matriz  */
#line 106 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); /* MATRIZ */ }
#line 1659 "parser.tab.c"
    break;

  case 21: /* declaration: dynamic_array  */
#line 108 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("DYNAMIC_ARRAY NO IMPLEMENTADO AUN"); /* DYNAMIC_ARRAY */ }
#line 1665 "parser.tab.c"
    break;

  case 22: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL variable_access S_PUNTO_COMA  */
#line 111 "parser.y"
            { (yyval.nodo) = Vector_Asignation((yyvsp[-4].data_type), (yyvsp[-3].identificador), (yyvsp[-1].nodo)); /* ASIGNACION DE VARIABLE A VECTOR*/ }
#line 1671 "parser.tab.c"
    break;

  case 23: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL matrix_access S_PUNTO_COMA  */
#line 114 "parser.y"
            { (yyval.nodo) = Matriz_Asignation((yyvsp[-4].data_type), (yyvsp[-3].identificador), (yyvsp[-1].nodo)); /* ASIGNACION DE VARIABLE A MATRIZ*/ }
#line 1677 "parser.tab.c"
    break;

  case 24: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL parse_expretion PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 117 "parser.y"
            { (yyval.nodo) = Parse_Expression((yyvsp[-6].identificador), (yyvsp[-7].data_type), (yyvsp[-4].identificador), (yyvsp[-2].nodo)); /* PARSEO DE TIPOS */ }
#line 1683 "parser.tab.c"
    break;

  case 25: /* declaration: string_join  */
#line 119 "parser.y"
                           { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1689 "parser.tab.c"
    break;

  case 26: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL array_funcs S_PUNTO_COMA  */
#line 122 "parser.y"
            { (yyval.nodo) = Array_func_Declaration((yyvsp[-4].data_type), (yyvsp[-3].identificador), (yyvsp[-1].nodo)); /* FUNCIONES DE ARRAYS */ }
#line 1695 "parser.tab.c"
    break;

  case 27: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL IDENTIFICADOR PARENTESIS_OPEN PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 125 "parser.y"
            { (yyval.nodo) = Asignation_function_no_param((yyvsp[-6].data_type), (yyvsp[-5].identificador), (yyvsp[-3].identificador)); /* ASIGNACION DE VARIABLE A UNA FUNCION SIN PARAMETROS */ }
#line 1701 "parser.tab.c"
    break;

  case 28: /* parse_expretion: PARSE_INT  */
#line 129 "parser.y"
                                     { (yyval.identificador) = "int"; }
#line 1707 "parser.tab.c"
    break;

  case 29: /* parse_expretion: PARSE_DOUBLE  */
#line 130 "parser.y"
                                     { (yyval.identificador) = "double"; }
#line 1713 "parser.tab.c"
    break;

  case 30: /* parse_expretion: PARSE_FLOAT  */
#line 131 "parser.y"
                                     { (yyval.identificador) = "float"; }
#line 1719 "parser.tab.c"
    break;

  case 31: /* parse_expretion: PARSE_STRING  */
#line 132 "parser.y"
                                     { (yyval.identificador) = "String"; }
#line 1725 "parser.tab.c"
    break;

  case 32: /* string_join: DATA_TYPE IDENTIFICADOR S_IGUAL JOIN_STRING PARENTESIS_OPEN STRING_COMILLAS COMA vector_values PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 137 "parser.y"
            { 
                if ((yyvsp[-2].lista_nodos)[0]->tipo == NODO_IDENTIFICADOR) {
                    // Si es un identificador, retornarlo tal cual para evaluar luego
                    (yyval.nodo) = String_Join_Array((yyvsp[-9].data_type), (yyvsp[-8].identificador), (yyvsp[-4].string_comillas), (yyvsp[-2].lista_nodos));
                } else { 
                    (yyval.nodo) = Var_Declaration((yyvsp[-9].data_type), (yyvsp[-8].identificador), Make_StringJoin((yyvsp[-9].data_type), (yyvsp[-4].string_comillas), (yyvsp[-2].lista_nodos))); 
                }
                
            }
#line 1739 "parser.tab.c"
    break;

  case 33: /* array_funcs: ARRAY_INDEX PARENTESIS_OPEN IDENTIFICADOR COMA expr PARENTESIS_CLOSE  */
#line 151 "parser.y"
            { (yyval.nodo) = Array_Index_Of((yyvsp[-3].identificador), (yyvsp[-1].nodo)); /* FUNCION INDEX OF PARA VECTORES */ }
#line 1745 "parser.tab.c"
    break;

  case 34: /* array_funcs: IDENTIFICADOR FUNC_LENGTH  */
#line 154 "parser.y"
            { (yyval.nodo) = Array_Length((yyvsp[-1].identificador)); /* FUNCION LENGTH PARA VECTORES */ }
#line 1751 "parser.tab.c"
    break;

  case 35: /* vector: DATA_TYPE CORCHETE_OPEN CORCHETE_CLOSE IDENTIFICADOR S_IGUAL vector_type  */
#line 160 "parser.y"
        { (yyval.nodo) = Declaration_Vector((yyvsp[-5].data_type), (yyvsp[-2].identificador), (yyvsp[0].nodo)); /* REGRESAMOS EL NODO QUE GENERA */ }
#line 1757 "parser.tab.c"
    break;

  case 36: /* vector_type: NEW_WORD DATA_TYPE CORCHETE_OPEN INT_NUMBER CORCHETE_CLOSE S_PUNTO_COMA  */
#line 165 "parser.y"
            { (yyval.nodo) = Vector_Auto((yyvsp[-4].data_type), (yyvsp[-2].int_number)); }
#line 1763 "parser.tab.c"
    break;

  case 37: /* vector_type: LLAVE_OPEN vector_values LLAVE_CLOSE S_PUNTO_COMA  */
#line 168 "parser.y"
            { (yyval.nodo) = Valores_Vector((yyvsp[-2].lista_nodos)); /* VECTOR CON VALORES */ }
#line 1769 "parser.tab.c"
    break;

  case 38: /* vector_type: IDENTIFICADOR FUNC_ADD PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 171 "parser.y"
            { (yyval.nodo) = Array_Add_Ref((yyvsp[-5].identificador), (yyvsp[-2].nodo)); /* FUNCION ADD EN VECTORES*/}
#line 1775 "parser.tab.c"
    break;

  case 39: /* vector_values: vector_values COMA expr  */
#line 177 "parser.y"
            { (yyval.lista_nodos) = Add_Valor_Vector((yyvsp[-2].lista_nodos), (yyvsp[0].nodo)); }
#line 1781 "parser.tab.c"
    break;

  case 40: /* vector_values: expr  */
#line 179 "parser.y"
            { (yyval.lista_nodos) = Lista_Vector((yyvsp[0].nodo)); }
#line 1787 "parser.tab.c"
    break;

  case 41: /* matriz: DATA_TYPE CORCHETE_OPEN CORCHETE_CLOSE CORCHETE_OPEN CORCHETE_CLOSE IDENTIFICADOR S_IGUAL matriz_type  */
#line 185 "parser.y"
        { (yyval.nodo) = Declaration_Matriz((yyvsp[-7].data_type), (yyvsp[-2].identificador), (yyvsp[0].nodo)); /* REGRESAMOS EL NODO QUE GENERA */ }
#line 1793 "parser.tab.c"
    break;

  case 42: /* matriz_type: NEW_WORD DATA_TYPE CORCHETE_OPEN expr CORCHETE_CLOSE CORCHETE_OPEN expr CORCHETE_CLOSE S_PUNTO_COMA  */
#line 191 "parser.y"
            { (yyval.nodo) = Matriz_Auto((yyvsp[-7].data_type), (yyvsp[-5].nodo), (yyvsp[-2].nodo)); /* valores definidos en matriz*/ }
#line 1799 "parser.tab.c"
    break;

  case 43: /* matriz_type: LLAVE_OPEN matriz_values LLAVE_CLOSE S_PUNTO_COMA  */
#line 194 "parser.y"
            { (yyval.nodo) = Matriz_With_Values((yyvsp[-2].lista_nodos)); /* valores definidos en matriz*/ }
#line 1805 "parser.tab.c"
    break;

  case 44: /* matriz_values: matriz_values COMA LLAVE_OPEN vector_values LLAVE_CLOSE  */
#line 201 "parser.y"
            {
                // Get current size of list
                int size = 0;
                while ((yyvsp[-4].lista_nodos) && (yyvsp[-4].lista_nodos)[size] != NULL) size++;
                
                // Create new list with extra space
                (yyval.lista_nodos) = malloc(sizeof(Nodo*) * (size + 2));
                
                // Copy existing nodes
                for(int i = 0; i < size; i++) {
                    (yyval.lista_nodos)[i] = (yyvsp[-4].lista_nodos)[i];
                }
                
                // Add new vector_values node
                (yyval.lista_nodos)[size] = Valores_Vector((yyvsp[-1].lista_nodos));
                (yyval.lista_nodos)[size + 1] = NULL;
            }
#line 1827 "parser.tab.c"
    break;

  case 45: /* matriz_values: LLAVE_OPEN vector_values LLAVE_CLOSE  */
#line 220 "parser.y"
            {
                // Create list with single node
                (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 2);
                (yyval.lista_nodos)[0] = Valores_Vector((yyvsp[-1].lista_nodos));
                (yyval.lista_nodos)[1] = NULL;
            }
#line 1838 "parser.tab.c"
    break;

  case 51: /* asignation: IDENTIFICADOR op_expr expr_bridge S_PUNTO_COMA  */
#line 247 "parser.y"
            { (yyval.nodo) = Asignacion_Variable((yyvsp[-3].identificador), (yyvsp[-2].identificador), (yyvsp[-1].nodo)); /* 'OPERADOR ASIGNACION' PARA UNA VARIABLE Y ASIGNACION NORMAL*/ }
#line 1844 "parser.tab.c"
    break;

  case 52: /* asignation: variable_access S_IGUAL expr S_PUNTO_COMA  */
#line 250 "parser.y"
            { (yyval.nodo) = Vector_Asignation_Ref((yyvsp[-3].nodo), (yyvsp[-1].nodo)); }
#line 1850 "parser.tab.c"
    break;

  case 53: /* asignation: matrix_access S_IGUAL expr S_PUNTO_COMA  */
#line 253 "parser.y"
            { (yyval.nodo) = Matriz_Change_Value((yyvsp[-3].nodo), (yyvsp[-1].nodo)); }
#line 1856 "parser.tab.c"
    break;

  case 54: /* asignation: DATA_TYPE IDENTIFICADOR S_IGUAL IDENTIFICADOR PARENTESIS_OPEN function_parameters_access PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 256 "parser.y"
            {
                Nodo* temp = Function_Call_Parameters((yyvsp[-4].identificador), (yyvsp[-2].lista_nodos));
                (yyval.nodo) = Asignation_function((yyvsp[-7].data_type), (yyvsp[-6].identificador), temp); /* ASIGNACION DE VARIABLE A UNA FUNCION CON PARAMETROS */
            }
#line 1865 "parser.tab.c"
    break;

  case 55: /* expr_bridge: expr  */
#line 267 "parser.y"
                                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1871 "parser.tab.c"
    break;

  case 56: /* expr_bridge: variable_access  */
#line 268 "parser.y"
                                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1877 "parser.tab.c"
    break;

  case 57: /* expr_bridge: matrix_access  */
#line 269 "parser.y"
                                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1883 "parser.tab.c"
    break;

  case 58: /* op_expr: S_IGUAL  */
#line 274 "parser.y"
                                { (yyval.identificador) = "="; }
#line 1889 "parser.tab.c"
    break;

  case 59: /* op_expr: OP_MAS_IGUAL  */
#line 275 "parser.y"
                                { (yyval.identificador) = "+="; }
#line 1895 "parser.tab.c"
    break;

  case 60: /* op_expr: OP_MENOS_IGUAL  */
#line 276 "parser.y"
                                { (yyval.identificador) = "-="; }
#line 1901 "parser.tab.c"
    break;

  case 61: /* op_expr: OP_MULTI_IGUAL  */
#line 277 "parser.y"
                                { (yyval.identificador) = "*="; }
#line 1907 "parser.tab.c"
    break;

  case 62: /* op_expr: OP_DIV_IGUAL  */
#line 278 "parser.y"
                                { (yyval.identificador) = "/="; }
#line 1913 "parser.tab.c"
    break;

  case 63: /* op_expr: OP_MOD_IGUAL  */
#line 279 "parser.y"
                                { (yyval.identificador) = "%="; }
#line 1919 "parser.tab.c"
    break;

  case 64: /* op_expr: OP_AND_IGUAL  */
#line 280 "parser.y"
                                { (yyval.identificador) = "&="; }
#line 1925 "parser.tab.c"
    break;

  case 65: /* op_expr: OP_OR_IGUAL  */
#line 281 "parser.y"
                                { (yyval.identificador) = "|="; }
#line 1931 "parser.tab.c"
    break;

  case 66: /* op_expr: OP_POT_IGUAL  */
#line 282 "parser.y"
                                { (yyval.identificador) = "^="; }
#line 1937 "parser.tab.c"
    break;

  case 67: /* op_expr: OP_MAYOR_IGUAL  */
#line 283 "parser.y"
                                { (yyval.identificador) = ">>="; }
#line 1943 "parser.tab.c"
    break;

  case 68: /* op_expr: OP_MENOR_IGUAL  */
#line 284 "parser.y"
                                { (yyval.identificador) = "<<="; }
#line 1949 "parser.tab.c"
    break;

  case 69: /* native_func: IDENTIFICADOR for_option S_PUNTO_COMA  */
#line 291 "parser.y"
            {(yyval.nodo) = Plus_Minus_Var((yyvsp[-2].identificador), (yyvsp[-1].identificador));}
#line 1955 "parser.tab.c"
    break;

  case 70: /* native_func: CONTINUE_WORD S_PUNTO_COMA  */
#line 294 "parser.y"
            { (yyval.nodo) = Continue_Word(); /* CONTINUE PARA CICLOS */ }
#line 1961 "parser.tab.c"
    break;

  case 71: /* native_func: BREAK_WORD S_PUNTO_COMA  */
#line 297 "parser.y"
            { (yyval.nodo) = Break_Word(); /* BREAK PARA CICLOS */ }
#line 1967 "parser.tab.c"
    break;

  case 72: /* native_func: RETURN_WORD S_PUNTO_COMA  */
#line 300 "parser.y"
            { (yyval.nodo) = Return_Word(); /* RETURN PARA FUNCIONES */ }
#line 1973 "parser.tab.c"
    break;

  case 73: /* native_func: RETURN_WORD expr S_PUNTO_COMA  */
#line 303 "parser.y"
            { (yyval.nodo) = Return_Value((yyvsp[-1].nodo)); /* RETURN PARA FUNCIONES */ }
#line 1979 "parser.tab.c"
    break;

  case 74: /* native_func: IDENTIFICADOR PARENTESIS_OPEN parameters_bridge PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 306 "parser.y"
            { (yyval.nodo) = Function_Call_No_Param((yyvsp[-4].identificador)); }
#line 1985 "parser.tab.c"
    break;

  case 75: /* variable_access: IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE  */
#line 312 "parser.y"
                {(yyval.nodo) = Vector_Reference((yyvsp[-3].identificador), (yyvsp[-1].nodo));/* ACCESO A VALOR EN UN VECTOR*/}
#line 1991 "parser.tab.c"
    break;

  case 76: /* matrix_access: IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE CORCHETE_OPEN expr CORCHETE_CLOSE  */
#line 317 "parser.y"
                {(yyval.nodo) = Matriz_Reference((yyvsp[-6].identificador), (yyvsp[-4].nodo), (yyvsp[-1].nodo));/* ACCESO A VALOR EN UNA MATRIZ */}
#line 1997 "parser.tab.c"
    break;

  case 77: /* if_sentence: IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 323 "parser.y"
            { (yyval.nodo) = Sentencia_If_Simple((yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 2003 "parser.tab.c"
    break;

  case 78: /* if_sentence: IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE ELSE_WORD LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 326 "parser.y"
            { (yyval.nodo) = Sentencia_If_Else((yyvsp[-8].nodo), (yyvsp[-5].nodo), (yyvsp[-1].nodo)); }
#line 2009 "parser.tab.c"
    break;

  case 79: /* if_sentence: IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE if_else_one if_else_chain ELSE_WORD LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 329 "parser.y"
            { (yyval.nodo) = Sentencia_If_ElseIf_Else((yyvsp[-10].nodo), (yyvsp[-7].nodo), (yyvsp[-5].nodo), (yyvsp[-4].lista_nodos), (yyvsp[-1].nodo)); /* IF - ELSE IF - ELSE CON LISTA DE ELSE IF */ }
#line 2015 "parser.tab.c"
    break;

  case 80: /* if_else_one: ELSE_WORD IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 334 "parser.y"
            { (yyval.nodo) = If_Else_One((yyvsp[-4].nodo), (yyvsp[-1].nodo)); /* INSTRUCCIONES DEL ELSE IF SI SOLSO VIENE UNA VEZ */ }
#line 2021 "parser.tab.c"
    break;

  case 81: /* if_else_chain: if_else_chain ELSE_WORD IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 339 "parser.y"
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
#line 2043 "parser.tab.c"
    break;

  case 82: /* if_else_chain: %empty  */
#line 358 "parser.y"
                { 
                // Inicializar lista vacía
                    (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 1);
                    (yyval.lista_nodos)[0] = NULL;
                }
#line 2053 "parser.tab.c"
    break;

  case 83: /* for_sentence: FOR_WORD PARENTESIS_OPEN for_condition PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 368 "parser.y"
            { (yyval.nodo) = For_Sentence((yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 2059 "parser.tab.c"
    break;

  case 84: /* for_condition: declaration expr S_PUNTO_COMA IDENTIFICADOR for_option  */
#line 374 "parser.y"
            { (yyval.nodo) = For_Condition((yyvsp[-4].nodo), (yyvsp[-3].nodo), (yyvsp[-1].identificador), (yyvsp[0].identificador)); }
#line 2065 "parser.tab.c"
    break;

  case 85: /* for_condition: DATA_TYPE IDENTIFICADOR S_PUNTO_PUNTO IDENTIFICADOR  */
#line 376 "parser.y"
            { (yyval.nodo) = For_Each((yyvsp[-3].data_type), (yyvsp[-2].identificador), (yyvsp[0].identificador)); /* Implementacion con los vectores */ }
#line 2071 "parser.tab.c"
    break;

  case 86: /* for_option: OP_AUMENTO  */
#line 380 "parser.y"
                       { (yyval.identificador) = "++"; }
#line 2077 "parser.tab.c"
    break;

  case 87: /* for_option: OP_DECREMENTO  */
#line 381 "parser.y"
                            { (yyval.identificador) = "--"; }
#line 2083 "parser.tab.c"
    break;

  case 88: /* switch_case: SWITCH_WORD PARENTESIS_OPEN IDENTIFICADOR PARENTESIS_CLOSE LLAVE_OPEN switch_case_one switch_case_list switch_default LLAVE_CLOSE  */
#line 386 "parser.y"
            { (yyval.nodo) = Switch_Sentence((yyvsp[-6].identificador), (yyvsp[-3].nodo), (yyvsp[-2].lista_nodos), (yyvsp[-1].nodo)); }
#line 2089 "parser.tab.c"
    break;

  case 89: /* switch_case_one: CASE_WORD expr S_PUNTO_PUNTO lista_instrucciones BREAK_WORD S_PUNTO_COMA  */
#line 392 "parser.y"
                { (yyval.nodo) = Switch_Case_One((yyvsp[-4].nodo), (yyvsp[-2].nodo)); }
#line 2095 "parser.tab.c"
    break;

  case 90: /* switch_case_list: switch_case_list CASE_WORD expr S_PUNTO_PUNTO lista_instrucciones BREAK_WORD S_PUNTO_COMA  */
#line 398 "parser.y"
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
#line 2117 "parser.tab.c"
    break;

  case 91: /* switch_case_list: %empty  */
#line 418 "parser.y"
                { 
                // Inicializar lista vacía
                    (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 1);
                    (yyval.lista_nodos)[0] = NULL;
                }
#line 2127 "parser.tab.c"
    break;

  case 92: /* switch_default: DEFAULT_WORD S_PUNTO_PUNTO lista_instrucciones  */
#line 428 "parser.y"
                { (yyval.nodo) = Switch_Default((yyvsp[0].nodo)); }
#line 2133 "parser.tab.c"
    break;

  case 93: /* switch_default: %empty  */
#line 431 "parser.y"
                { (yyval.nodo) = Nodo_Vacio("NO DEFAULT"); }
#line 2139 "parser.tab.c"
    break;

  case 94: /* while_sentence: WHILE_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 437 "parser.y"
                { (yyval.nodo) = While_Sentence((yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 2145 "parser.tab.c"
    break;

  case 95: /* function_sentence: DATA_TYPE IDENTIFICADOR PARENTESIS_OPEN parameters_bridge PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 443 "parser.y"
                { (yyval.nodo) = Funtion_Declaration((yyvsp[-7].data_type), (yyvsp[-6].identificador), (yyvsp[-4].lista_nodos), (yyvsp[-1].nodo)); /* DECLARACION DE FUNCIONES */ }
#line 2151 "parser.tab.c"
    break;

  case 96: /* parameters_bridge: function_parameters_declaration  */
#line 449 "parser.y"
                { (yyval.lista_nodos) = (yyvsp[0].lista_nodos); }
#line 2157 "parser.tab.c"
    break;

  case 97: /* parameters_bridge: function_parameters_access  */
#line 452 "parser.y"
                { (yyval.lista_nodos) = (yyvsp[0].lista_nodos); }
#line 2163 "parser.tab.c"
    break;

  case 98: /* parameters_bridge: MAIN_STRING  */
#line 455 "parser.y"
                {
                    // Create empty list with single node
                    (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 2);
                    (yyval.lista_nodos)[0] = Nodo_Vacio("NO PARAMETROS");
                    (yyval.lista_nodos)[1] = NULL;
                }
#line 2174 "parser.tab.c"
    break;

  case 99: /* parameters_bridge: %empty  */
#line 463 "parser.y"
                {
                    // Create empty list
                    (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 1);
                    (yyval.lista_nodos)[0] = Nodo_Vacio("NO PARAMETROS");
                }
#line 2184 "parser.tab.c"
    break;

  case 100: /* function_parameters_declaration: function_parameters_declaration COMA DATA_TYPE IDENTIFICADOR  */
#line 473 "parser.y"
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
#line 2202 "parser.tab.c"
    break;

  case 101: /* function_parameters_declaration: DATA_TYPE IDENTIFICADOR  */
#line 487 "parser.y"
                    {
                        (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 2);
                        (yyval.lista_nodos)[0] = Var_Declaration((yyvsp[-1].data_type), (yyvsp[0].identificador), Terminal_Null("DEFAULT"));
                        (yyval.lista_nodos)[1] = NULL;
                    }
#line 2212 "parser.tab.c"
    break;

  case 102: /* function_parameters_access: function_parameters_access COMA expr  */
#line 496 "parser.y"
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
#line 2230 "parser.tab.c"
    break;

  case 103: /* function_parameters_access: expr  */
#line 510 "parser.y"
                    {
                        (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 2);
                        (yyval.lista_nodos)[0] = (yyvsp[0].nodo);
                        (yyval.lista_nodos)[1] = NULL;
                    }
#line 2240 "parser.tab.c"
    break;

  case 104: /* expr: expr '+' expr  */
#line 518 "parser.y"
                                                { (yyval.nodo) = Suma((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2246 "parser.tab.c"
    break;

  case 105: /* expr: expr '-' expr  */
#line 519 "parser.y"
                                                { (yyval.nodo) = Resta((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2252 "parser.tab.c"
    break;

  case 106: /* expr: expr '*' expr  */
#line 520 "parser.y"
                                                { (yyval.nodo) = Multiplicacion((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2258 "parser.tab.c"
    break;

  case 107: /* expr: expr '/' expr  */
#line 521 "parser.y"
                                                { (yyval.nodo) = Division((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2264 "parser.tab.c"
    break;

  case 108: /* expr: expr '%' expr  */
#line 522 "parser.y"
                                                { (yyval.nodo) = Modulo((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2270 "parser.tab.c"
    break;

  case 109: /* expr: PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 523 "parser.y"
                                                { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2276 "parser.tab.c"
    break;

  case 110: /* expr: INT_NUMBER  */
#line 524 "parser.y"
                                                { (yyval.nodo) = Terminal_Int((yyvsp[0].int_number)); }
#line 2282 "parser.tab.c"
    break;

  case 111: /* expr: '-' expr  */
#line 525 "parser.y"
                                                { (yyval.nodo) = Terminal_Negativo((yyvsp[0].nodo)); }
#line 2288 "parser.tab.c"
    break;

  case 112: /* expr: FLOAT_NUMBER FLOAT_SUFFIX  */
#line 526 "parser.y"
                                                { (yyval.nodo) = Terminal_Float((yyvsp[-1].float_number)); }
#line 2294 "parser.tab.c"
    break;

  case 113: /* expr: FLOAT_NUMBER  */
#line 527 "parser.y"
                                                { (yyval.nodo) = Terminal_Double((yyvsp[0].float_number)); }
#line 2300 "parser.tab.c"
    break;

  case 114: /* expr: STRING_COMILLAS  */
#line 528 "parser.y"
                                                { if (strlen((yyvsp[0].string_comillas)) == 3) { (yyval.nodo) = Terminal_Char((yyvsp[0].string_comillas)[1]); } else { (yyval.nodo) = Terminal_String((yyvsp[0].string_comillas)); }}
#line 2306 "parser.tab.c"
    break;

  case 115: /* expr: BOOL_VALUE  */
#line 529 "parser.y"
                                                { (yyval.nodo) = Terminal_Bool((yyvsp[0].bool_true)); }
#line 2312 "parser.tab.c"
    break;

  case 116: /* expr: NULL_VALUE  */
#line 530 "parser.y"
                                                { (yyval.nodo) = Terminal_Null((yyvsp[0].null_value)); }
#line 2318 "parser.tab.c"
    break;

  case 117: /* expr: IDENTIFICADOR  */
#line 531 "parser.y"
                                                { (yyval.nodo) = Identificador_Ref((yyvsp[0].identificador));}
#line 2324 "parser.tab.c"
    break;

  case 118: /* expr: expr OP_MENOR_A expr  */
#line 532 "parser.y"
                                                { (yyval.nodo) = Menor_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2330 "parser.tab.c"
    break;

  case 119: /* expr: expr OP_MAYOR_A expr  */
#line 533 "parser.y"
                                                { (yyval.nodo) = Mayor_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2336 "parser.tab.c"
    break;

  case 120: /* expr: expr OP_MENOR_IGUAL_A expr  */
#line 534 "parser.y"
                                                { (yyval.nodo) = Menor_Igual_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2342 "parser.tab.c"
    break;

  case 121: /* expr: expr OP_MAYOR_IGUAL_A expr  */
#line 535 "parser.y"
                                                { (yyval.nodo) = Mayor_Igual_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2348 "parser.tab.c"
    break;

  case 122: /* expr: expr OP_IGUAL_IGUAL expr  */
#line 536 "parser.y"
                                                { (yyval.nodo) = Igual_Igual((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2354 "parser.tab.c"
    break;

  case 123: /* expr: expr OP_DISTINTO_A expr  */
#line 537 "parser.y"
                                                { (yyval.nodo) = Diferente_Que((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2360 "parser.tab.c"
    break;

  case 124: /* expr: expr LOGIC_AND expr  */
#line 538 "parser.y"
                                                { (yyval.nodo) = And((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2366 "parser.tab.c"
    break;

  case 125: /* expr: expr LOGIC_OR expr  */
#line 539 "parser.y"
                                                { (yyval.nodo) = Or((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2372 "parser.tab.c"
    break;

  case 126: /* expr: LOGIC_NOT expr  */
#line 540 "parser.y"
                                                { (yyval.nodo) = Not((yyvsp[0].nodo)); }
#line 2378 "parser.tab.c"
    break;

  case 127: /* expr: IDENTIFICADOR FUNC_EQUALS PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 542 "parser.y"
    { (yyval.nodo) = Equals_Compare((yyvsp[-4].identificador), (yyvsp[-1].nodo)); /* PRINT FUNC .EQUALS PARA UNA VARIABLE */ }
#line 2384 "parser.tab.c"
    break;

  case 128: /* expr: STRING_COMILLAS FUNC_EQUALS PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 544 "parser.y"
    { (yyval.nodo) = Equals_Compare((yyvsp[-4].string_comillas), (yyvsp[-1].nodo)); /* PRINT FUNC .EQUALS PARA UNA VARIABLE */ }
#line 2390 "parser.tab.c"
    break;


#line 2394 "parser.tab.c"

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

#line 547 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error: sintáctico en linea: %d\n", yylineno);
}
