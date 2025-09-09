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
  YYSYMBOL_NEW_WORD = 25,                  /* NEW_WORD  */
  YYSYMBOL_COMA = 26,                      /* COMA  */
  YYSYMBOL_PARSE_INT = 27,                 /* PARSE_INT  */
  YYSYMBOL_PARSE_FLOAT = 28,               /* PARSE_FLOAT  */
  YYSYMBOL_PARSE_DOUBLE = 29,              /* PARSE_DOUBLE  */
  YYSYMBOL_PARSE_STRING = 30,              /* PARSE_STRING  */
  YYSYMBOL_JOIN_STRING = 31,               /* JOIN_STRING  */
  YYSYMBOL_ARRAY_INDEX = 32,               /* ARRAY_INDEX  */
  YYSYMBOL_FUNC_LENGTH = 33,               /* FUNC_LENGTH  */
  YYSYMBOL_FUNC_ADD = 34,                  /* FUNC_ADD  */
  YYSYMBOL_MAIN_STRING = 35,               /* MAIN_STRING  */
  YYSYMBOL_FLOAT_SUFFIX = 36,              /* FLOAT_SUFFIX  */
  YYSYMBOL_LOGIC_NOT = 37,                 /* LOGIC_NOT  */
  YYSYMBOL_INT_NUMBER = 38,                /* INT_NUMBER  */
  YYSYMBOL_OP_MENOR_A = 39,                /* OP_MENOR_A  */
  YYSYMBOL_OP_MAYOR_A = 40,                /* OP_MAYOR_A  */
  YYSYMBOL_41_ = 41,                       /* '+'  */
  YYSYMBOL_42_ = 42,                       /* '-'  */
  YYSYMBOL_43_ = 43,                       /* '/'  */
  YYSYMBOL_44_ = 44,                       /* '*'  */
  YYSYMBOL_45_ = 45,                       /* '%'  */
  YYSYMBOL_FLOAT_NUMBER = 46,              /* FLOAT_NUMBER  */
  YYSYMBOL_STRING_COMILLAS = 47,           /* STRING_COMILLAS  */
  YYSYMBOL_BOOL_VALUE = 48,                /* BOOL_VALUE  */
  YYSYMBOL_NULL_VALUE = 49,                /* NULL_VALUE  */
  YYSYMBOL_OP_MENOR_IGUAL_A = 50,          /* OP_MENOR_IGUAL_A  */
  YYSYMBOL_OP_MAYOR_IGUAL_A = 51,          /* OP_MAYOR_IGUAL_A  */
  YYSYMBOL_OP_IGUAL_IGUAL = 52,            /* OP_IGUAL_IGUAL  */
  YYSYMBOL_OP_DISTINTO_A = 53,             /* OP_DISTINTO_A  */
  YYSYMBOL_LOGIC_AND = 54,                 /* LOGIC_AND  */
  YYSYMBOL_LOGIC_OR = 55,                  /* LOGIC_OR  */
  YYSYMBOL_IDENTIFICADOR = 56,             /* IDENTIFICADOR  */
  YYSYMBOL_S_IGUAL = 57,                   /* S_IGUAL  */
  YYSYMBOL_OP_MAS_IGUAL = 58,              /* OP_MAS_IGUAL  */
  YYSYMBOL_OP_MENOS_IGUAL = 59,            /* OP_MENOS_IGUAL  */
  YYSYMBOL_OP_MULTI_IGUAL = 60,            /* OP_MULTI_IGUAL  */
  YYSYMBOL_OP_DIV_IGUAL = 61,              /* OP_DIV_IGUAL  */
  YYSYMBOL_OP_MOD_IGUAL = 62,              /* OP_MOD_IGUAL  */
  YYSYMBOL_OP_AND_IGUAL = 63,              /* OP_AND_IGUAL  */
  YYSYMBOL_OP_OR_IGUAL = 64,               /* OP_OR_IGUAL  */
  YYSYMBOL_OP_POT_IGUAL = 65,              /* OP_POT_IGUAL  */
  YYSYMBOL_OP_MAYOR_IGUAL = 66,            /* OP_MAYOR_IGUAL  */
  YYSYMBOL_OP_MENOR_IGUAL = 67,            /* OP_MENOR_IGUAL  */
  YYSYMBOL_DATA_TYPE = 68,                 /* DATA_TYPE  */
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
  YYSYMBOL_for_sentence = 93,              /* for_sentence  */
  YYSYMBOL_for_condition = 94,             /* for_condition  */
  YYSYMBOL_switch_case = 95,               /* switch_case  */
  YYSYMBOL_switch_case_list = 96,          /* switch_case_list  */
  YYSYMBOL_switch_default = 97,            /* switch_default  */
  YYSYMBOL_while_sentence = 98,            /* while_sentence  */
  YYSYMBOL_function_sentence = 99,         /* function_sentence  */
  YYSYMBOL_parameters_bridge = 100,        /* parameters_bridge  */
  YYSYMBOL_function_parameters = 101,      /* function_parameters  */
  YYSYMBOL_function_expr = 102,            /* function_expr  */
  YYSYMBOL_expr = 103                      /* expr  */
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
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   964

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  293

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
       2,     2,     2,     2,     2,     2,     2,    45,     2,     2,
       2,     2,    44,    41,     2,    42,     2,    43,     2,     2,
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
      35,    36,    37,    38,    39,    40,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    70,    71,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    89,    90,    96,    99,   102,   105,
     106,   107,   108,   109,   110,   111,   112,   116,   117,   118,
     119,   123,   127,   128,   133,   137,   138,   139,   144,   145,
     150,   155,   156,   161,   162,   167,   171,   172,   176,   177,
     183,   184,   189,   190,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   211,   214,   215,   216,   217,
     218,   219,   220,   225,   226,   231,   232,   237,   242,   243,
     244,   249,   254,   255,   260,   261,   266,   271,   276,   277,
     282,   283,   284,   288,   289,   293,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   309,   310,   311,   312,   313,   314
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
  "RETURN_WORD", "CORCHETE_OPEN", "CORCHETE_CLOSE", "NEW_WORD", "COMA",
  "PARSE_INT", "PARSE_FLOAT", "PARSE_DOUBLE", "PARSE_STRING",
  "JOIN_STRING", "ARRAY_INDEX", "FUNC_LENGTH", "FUNC_ADD", "MAIN_STRING",
  "FLOAT_SUFFIX", "LOGIC_NOT", "INT_NUMBER", "OP_MENOR_A", "OP_MAYOR_A",
  "'+'", "'-'", "'/'", "'*'", "'%'", "FLOAT_NUMBER", "STRING_COMILLAS",
  "BOOL_VALUE", "NULL_VALUE", "OP_MENOR_IGUAL_A", "OP_MAYOR_IGUAL_A",
  "OP_IGUAL_IGUAL", "OP_DISTINTO_A", "LOGIC_AND", "LOGIC_OR",
  "IDENTIFICADOR", "S_IGUAL", "OP_MAS_IGUAL", "OP_MENOS_IGUAL",
  "OP_MULTI_IGUAL", "OP_DIV_IGUAL", "OP_MOD_IGUAL", "OP_AND_IGUAL",
  "OP_OR_IGUAL", "OP_POT_IGUAL", "OP_MAYOR_IGUAL", "OP_MENOR_IGUAL",
  "DATA_TYPE", "$accept", "input", "lista_instrucciones", "instruccion",
  "print", "declaration", "parse_expretion", "string_join", "array_funcs",
  "vector", "vector_type", "vector_values", "matriz", "matriz_type",
  "matriz_values", "dynamic_array", "dynamic_corchete",
  "dynamic_data_declaration", "asignation", "expr_bridge", "op_expr",
  "native_func", "variable_access", "if_sentence", "for_sentence",
  "for_condition", "switch_case", "switch_case_list", "switch_default",
  "while_sentence", "function_sentence", "parameters_bridge",
  "function_parameters", "function_expr", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-222)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     311,    -3,     9,    20,    21,    28,    39,    52,   108,   129,
      -5,    67,   311,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
    -222,    33,  -222,  -222,  -222,  -222,  -222,    43,  -222,   334,
     497,   334,    45,  -222,  -222,   334,   334,  -222,    84,  -222,
    -222,  -222,  -222,   358,   120,   123,   133,   130,   334,  -222,
    -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
     339,   115,     6,  -222,  -222,   334,   138,   470,    92,   142,
     487,   528,     8,   334,   143,   545,  -222,  -222,  -222,   334,
     334,   334,   334,   334,   334,   334,   334,   334,   334,   334,
     334,   334,   135,  -222,  -222,   334,   689,   127,   148,  -222,
     878,    14,  -222,    -2,   134,   390,   -16,   411,   136,   149,
     156,   167,   160,    36,   428,   163,  -222,   131,   131,   118,
     118,  -222,  -222,  -222,   131,   131,   162,   162,   911,   895,
    -222,   569,   161,  -222,   155,   126,  -222,   141,   193,   173,
    -222,   878,  -222,    54,  -222,  -222,  -222,  -222,   204,   205,
      65,   206,   208,   216,   219,   445,   200,   201,  -222,   222,
     311,  -222,  -222,   311,   179,   181,   311,  -222,   334,   183,
      -6,  -222,   223,    81,   245,   334,   334,    -2,  -222,   334,
    -222,  -222,  -222,  -222,  -222,   184,   334,     5,   207,   227,
    -222,    49,   258,   711,   194,   334,   185,   220,  -222,   311,
    -222,   199,   841,   861,    63,   586,   233,   650,   334,   251,
     240,  -222,   243,  -222,  -222,  -222,  -222,    -9,    12,   878,
     236,   262,   278,   265,   334,   334,   267,   268,   334,     3,
     311,   667,   311,  -222,   256,   260,   214,  -222,   281,   334,
     334,   334,  -222,  -222,    89,   610,  -222,  -222,   733,  -222,
     334,   328,   311,   311,   311,   334,    30,   263,  -222,   878,
     755,   627,  -222,  -222,  -222,   777,   285,   348,   295,    91,
     287,   274,   334,   290,   294,  -222,   106,   298,  -222,  -222,
    -222,   334,   799,  -222,  -222,   113,   114,   280,  -222,   334,
     821,   302,  -222
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     4,     7,     5,    19,    20,    21,     6,
       9,     0,     8,    12,    10,    11,    13,     0,    69,     0,
       0,     0,     0,    68,    70,     0,     0,   101,   103,   104,
     105,   106,   107,     0,     0,     0,     0,     0,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     1,     3,     0,     0,     0,   107,     0,
       0,     0,     0,     0,     0,     0,   116,   102,    71,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    67,     0,     0,   107,     0,    53,
      52,     0,    16,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   100,   108,   109,    95,
      96,    98,    97,    99,   110,   111,   112,   113,   114,   115,
      72,     0,    73,    50,     0,     0,    92,     0,     0,    88,
      91,    93,    47,     0,    27,    29,    28,    30,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,    51,     0,
       0,    15,    14,     0,     0,     0,     0,    65,     0,     0,
       0,    94,     0,     0,     0,     0,     0,     0,    33,     0,
      25,    26,    22,    17,    46,     0,     0,    85,     0,     0,
      80,     0,     0,     0,     0,     0,     0,     0,    34,     0,
      90,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    75,    78,    79,    77,    74,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    81,     0,     0,     0,    40,     0,     0,
       0,     0,    87,    18,     0,     0,    23,    24,     0,    45,
       0,     0,     0,    84,     0,     0,     0,     0,    36,    38,
       0,     0,    31,    32,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    48,    69,     0,    76,    44,
      42,     0,     0,    35,    37,    69,     0,     0,    43,     0,
       0,     0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -222,  -222,  -146,    -7,  -222,   275,  -222,  -222,  -222,  -222,
    -222,  -221,  -222,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
    -222,   282,   -56,  -222,  -222,  -222,  -222,  -222,  -222,  -222,
    -222,  -222,   144,   137,    -8
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,   151,   152,   153,    16,
     198,   218,    17,   237,   256,    18,   106,   229,    19,    98,
      60,    20,    21,    22,    23,    74,    24,   187,   210,    25,
      26,   138,   139,   140,   219
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    27,    35,   244,    99,    64,   249,   156,   235,   102,
     103,   195,    28,   208,   188,   209,   236,   189,    61,   196,
     192,    67,    70,    71,    29,    30,   250,    75,    76,   104,
     238,    61,    31,   136,   269,    36,    37,   134,   239,   102,
      96,   157,   164,    32,    38,    39,    40,    41,   270,   154,
     197,    62,   100,   222,    42,    33,   271,   107,    35,   104,
     286,   213,   214,   105,   113,   114,   137,    63,   226,   177,
     135,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   251,    35,   253,   131,    48,   173,
      65,    36,    37,   105,   262,   141,    44,   155,   178,    66,
      38,    39,    40,    41,    45,    46,   267,    47,   268,   279,
      42,    34,    35,    72,   -83,   239,   -83,   239,    36,    37,
      77,   -82,   174,   -82,   -83,    92,    93,    38,    39,    40,
      41,   -82,   288,    44,    95,    75,    94,    42,   130,   101,
     239,    45,    46,   108,    47,    36,    37,   110,   115,   137,
      48,   133,    48,   159,    38,    39,    40,    41,   142,   161,
     193,    83,    84,    85,    42,   141,   160,   202,   203,   141,
     162,   205,    81,    82,    83,    84,    85,   163,   207,   169,
     166,    64,    64,   170,   168,    64,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,   171,   172,   173,
     231,    79,    80,    81,    82,    83,    84,    85,   175,   176,
     179,   180,    86,    87,     1,    64,     2,   245,     3,   181,
     248,     4,   182,     5,   184,   211,   185,     6,     7,     8,
     186,   259,   260,   261,     1,   190,     2,   191,     3,   194,
     199,     4,   265,     5,    64,   212,    64,     6,     7,     8,
     201,   217,   206,   220,   221,   223,   228,   232,   233,   240,
      64,    64,   234,     9,   282,     1,   241,     2,   243,     3,
     246,   247,     4,   254,     5,    10,   215,   255,     6,     7,
       8,   290,   257,     9,   258,     1,   272,     2,   276,     3,
     280,   281,     4,   283,     5,    10,   242,   284,     6,     7,
       8,   285,     1,   289,     2,   292,     3,    73,     0,     4,
     200,     5,    69,   278,     9,     6,     7,     8,     1,     0,
       2,   204,     3,     0,     0,     4,    10,     5,     0,     0,
       0,     6,     7,     8,     9,     1,     0,   266,    35,     3,
       0,     0,     4,    35,     5,     0,    10,     0,     6,     7,
       8,     9,     0,     0,     0,     1,     0,   277,     0,     3,
       0,    78,     4,    10,     5,     0,     0,     9,     6,     7,
       8,    36,    37,     0,     0,     0,    36,    37,     0,    10,
      38,    39,    40,    41,     9,    38,    39,    40,    41,     0,
      42,     0,     0,     0,   143,    97,    10,    79,    80,    81,
      82,    83,    84,    85,     9,     0,     0,     0,    86,    87,
      88,    89,    90,    91,   158,     0,    10,   144,   145,   146,
     147,   148,   149,     0,     0,     0,     0,    36,    37,     0,
       0,   165,     0,     0,     0,     0,    38,    39,    40,    41,
       0,     0,     0,     0,     0,     0,   150,     0,   183,     0,
      79,    80,    81,    82,    83,    84,    85,     0,     0,     0,
       0,    86,    87,    88,    89,    90,    91,    79,    80,    81,
      82,    83,    84,    85,     0,   109,     0,     0,    86,    87,
      88,    89,    90,    91,    79,    80,    81,    82,    83,    84,
      85,     0,   111,     0,     0,    86,    87,    88,    89,    90,
      91,    35,     0,     0,     0,     0,     2,     0,     0,    79,
      80,    81,    82,    83,    84,    85,     0,     0,     7,     8,
      86,    87,    88,    89,    90,    91,    79,    80,    81,    82,
      83,    84,    85,   112,    36,    37,     0,    86,    87,    88,
      89,    90,    91,    38,    39,    40,    41,     0,     0,     0,
     116,     0,     0,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    79,    80,    81,
      82,    83,    84,    85,   167,     0,     0,     0,    86,    87,
      88,    89,    90,    91,    79,    80,    81,    82,    83,    84,
      85,   227,     0,     0,     0,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,   263,     0,     0,     0,    86,
      87,    88,    89,    90,    91,    79,    80,    81,    82,    83,
      84,    85,   274,     0,     0,     0,    86,    87,    88,    89,
      90,    91,     0,     0,     0,     0,     0,     0,     0,    79,
      80,    81,    82,    83,    84,    85,   230,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    79,    80,    81,    82,
      83,    84,    85,   252,     0,     0,     0,    86,    87,    88,
      89,    90,    91,     0,     0,     0,     0,     0,     0,    79,
      80,    81,    82,    83,    84,    85,     0,     0,     0,     0,
      86,    87,    88,    89,    90,    91,    79,    80,    81,    82,
      83,    84,    85,   132,     0,     0,     0,    86,    87,    88,
      89,    90,    91,     0,     0,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,   216,     0,     0,     0,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,   264,     0,     0,
       0,    86,    87,    88,    89,    90,    91,     0,     0,     0,
       0,     0,    79,    80,    81,    82,    83,    84,    85,   273,
       0,     0,     0,    86,    87,    88,    89,    90,    91,     0,
       0,     0,     0,     0,    79,    80,    81,    82,    83,    84,
      85,   275,     0,     0,     0,    86,    87,    88,    89,    90,
      91,     0,     0,     0,     0,     0,    79,    80,    81,    82,
      83,    84,    85,   287,     0,     0,     0,    86,    87,    88,
      89,    90,    91,     0,     0,     0,     0,     0,    79,    80,
      81,    82,    83,    84,    85,   291,     0,     0,     0,    86,
      87,    88,    89,    90,    91,     0,     0,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,   224,     0,     0,
       0,    86,    87,    88,    89,    90,    91,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,   225,     0,     0,
       0,    86,    87,    88,    89,    90,    91,     0,     0,     0,
      79,    80,    81,    82,    83,    84,    85,     0,     0,     0,
       0,    86,    87,    88,    89,    90,    91,    79,    80,    81,
      82,    83,    84,    85,     0,     0,     0,     0,    86,    87,
      88,    89,    90,    91,    79,    80,    81,    82,    83,    84,
      85,     0,     0,     0,     0,    86,    87,    88,    89,    90,
      79,    80,    81,    82,    83,    84,    85,     0,     0,     0,
       0,    86,    87,    88,    89
};

static const yytype_int16 yycheck[] =
{
       8,     4,     4,   224,    60,    12,     3,    23,    17,     3,
       4,    17,     3,     8,   160,    10,    25,   163,    23,    25,
     166,    29,    30,    31,     4,     4,    23,    35,    36,    23,
      18,    23,     4,    35,   255,    37,    38,    23,    26,     3,
      48,    57,     6,     4,    46,    47,    48,    49,    18,   105,
      56,    56,    60,   199,    56,     3,    26,    65,     4,    23,
     281,    12,    13,    57,    56,    73,    68,     0,     5,     4,
      56,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,   230,     4,   232,    95,    23,    26,
      57,    37,    38,    57,     5,   103,     4,   105,    33,    56,
      46,    47,    48,    49,    12,    13,   252,    15,   254,    18,
      56,     3,     4,    68,     8,    26,    10,    26,    37,    38,
      36,     8,    68,    10,    18,     5,     3,    46,    47,    48,
      49,    18,    18,     4,     4,   143,     3,    56,     3,    24,
      26,    12,    13,     5,    15,    37,    38,     5,     5,    68,
      23,     3,    23,    17,    46,    47,    48,    49,    24,     3,
     168,    43,    44,    45,    56,   173,    17,   175,   176,   177,
       3,   179,    41,    42,    43,    44,    45,    17,   186,    24,
      17,   188,   189,    57,    23,   192,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    56,     5,    26,
     208,    39,    40,    41,    42,    43,    44,    45,     4,     4,
       4,     3,    50,    51,     7,   222,     9,   225,    11,     3,
     228,    14,     3,    16,    24,    18,    25,    20,    21,    22,
       8,   239,   240,   241,     7,    56,     9,    56,    11,    56,
      17,    14,   250,    16,   251,    18,   253,    20,    21,    22,
       5,    57,    68,    68,    34,    56,    23,     6,    18,    23,
     267,   268,    19,    56,   272,     7,     4,     9,     3,    11,
       3,     3,    14,    17,    16,    68,    18,    17,    20,    21,
      22,   289,    68,    56,     3,     7,    23,     9,     3,    11,
       3,    17,    14,     3,    16,    68,    18,     3,    20,    21,
      22,     3,     7,    23,     9,     3,    11,    32,    -1,    14,
     173,    16,    30,    18,    56,    20,    21,    22,     7,    -1,
       9,   177,    11,    -1,    -1,    14,    68,    16,    -1,    -1,
      -1,    20,    21,    22,    56,     7,    -1,     9,     4,    11,
      -1,    -1,    14,     4,    16,    -1,    68,    -1,    20,    21,
      22,    56,    -1,    -1,    -1,     7,    -1,     9,    -1,    11,
      -1,     3,    14,    68,    16,    -1,    -1,    56,    20,    21,
      22,    37,    38,    -1,    -1,    -1,    37,    38,    -1,    68,
      46,    47,    48,    49,    56,    46,    47,    48,    49,    -1,
      56,    -1,    -1,    -1,     4,    56,    68,    39,    40,    41,
      42,    43,    44,    45,    56,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,     3,    -1,    68,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    37,    38,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    46,    47,    48,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    -1,     3,    -1,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    39,    40,    41,
      42,    43,    44,    45,    -1,     5,    -1,    -1,    50,    51,
      52,    53,    54,    55,    39,    40,    41,    42,    43,    44,
      45,    -1,     5,    -1,    -1,    50,    51,    52,    53,    54,
      55,     4,    -1,    -1,    -1,    -1,     9,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    21,    22,
      50,    51,    52,    53,    54,    55,    39,    40,    41,    42,
      43,    44,    45,     5,    37,    38,    -1,    50,    51,    52,
      53,    54,    55,    46,    47,    48,    49,    -1,    -1,    -1,
       5,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      42,    43,    44,    45,     5,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    39,    40,    41,    42,    43,    44,
      45,     5,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,     5,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    39,    40,    41,    42,    43,
      44,    45,     5,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,     6,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    39,    40,    41,    42,
      43,    44,    45,     6,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    39,
      40,    41,    42,    43,    44,    45,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    39,    40,    41,    42,
      43,    44,    45,    24,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    24,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    24,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    24,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    24,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,    42,
      43,    44,    45,    24,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    -1,    -1,    -1,    -1,    -1,    39,    40,
      41,    42,    43,    44,    45,    24,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    -1,    -1,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    26,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    26,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    -1,    -1,    -1,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    39,    40,    41,
      42,    43,    44,    45,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    39,    40,    41,    42,    43,    44,
      45,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      39,    40,    41,    42,    43,    44,    45,    -1,    -1,    -1,
      -1,    50,    51,    52,    53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     9,    11,    14,    16,    20,    21,    22,    56,
      68,    70,    71,    72,    73,    74,    78,    81,    84,    87,
      90,    91,    92,    93,    95,    98,    99,     4,     3,     4,
       4,     4,     4,     3,     3,     4,    37,    38,    46,    47,
      48,    49,    56,   103,     4,    12,    13,    15,    23,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      89,    23,    56,     0,    72,    57,    56,   103,    56,    90,
     103,   103,    68,    74,    94,   103,   103,    36,     3,    39,
      40,    41,    42,    43,    44,    45,    50,    51,    52,    53,
      54,    55,     5,     3,     3,     4,   103,    56,    88,    91,
     103,    24,     3,     4,    23,    57,    85,   103,     5,     5,
       5,     5,     5,    56,   103,     5,     5,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
       3,   103,    24,     3,    23,    56,    35,    68,   100,   101,
     102,   103,    24,     4,    27,    28,    29,    30,    31,    32,
      56,    75,    76,    77,    91,   103,    23,    57,     3,    17,
      17,     3,     3,    17,     6,     3,    17,     5,    23,    24,
      57,    56,     5,    26,    68,     4,     4,     4,    33,     4,
       3,     3,     3,     3,    24,    25,     8,    96,    71,    71,
      56,    56,    71,   103,    56,    17,    25,    56,    79,    17,
     102,     5,   103,   103,   101,   103,    68,   103,     8,    10,
      97,    18,    18,    12,    13,    18,    24,    57,    80,   103,
      68,    34,    71,    56,    26,    26,     5,     5,    23,    86,
       6,   103,     6,    18,    19,    17,    25,    82,    18,    26,
      23,     4,    18,     3,    80,   103,     3,     3,   103,     3,
      23,    71,     6,    71,    17,    17,    83,    68,     3,   103,
     103,   103,     5,     5,    24,   103,     9,    71,    71,    80,
      18,    26,    23,    24,     5,    24,     3,     9,    18,    18,
       3,    17,   103,     3,     3,     3,    80,    24,    18,    23,
     103,    24,     3
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    69,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    73,    73,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    75,    75,    75,
      75,    76,    77,    77,    78,    79,    79,    79,    80,    80,
      81,    82,    82,    83,    83,    84,    85,    85,    86,    86,
      87,    87,    88,    88,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    91,    91,    92,    92,    93,    94,    94,
      94,    95,    96,    96,    97,    97,    98,    99,   100,   100,
     101,   101,   101,   102,   102,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
     103,   103,   103,   103,   103,   103,   103
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     3,     5,     8,     1,
       1,     1,     5,     8,     8,     5,     5,     1,     1,     1,
       1,     6,     6,     2,     6,     6,     4,     6,     3,     1,
       8,     9,     4,     5,     3,     8,     3,     2,     4,     3,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     5,     3,     3,     2,     2,
       2,     3,     4,     4,     7,     7,    11,     7,     5,     5,
       4,     8,     7,     6,     3,     0,     7,     8,     1,     0,
       3,     1,     1,     1,     2,     3,     3,     3,     3,     3,
       3,     1,     2,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     2
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
#line 1505 "parser.tab.c"
    break;

  case 3: /* lista_instrucciones: lista_instrucciones instruccion  */
#line 70 "parser.y"
                                                    { (yyval.nodo) = ListaInstrucciones((yyvsp[-1].nodo), (yyvsp[0].nodo)); }
#line 1511 "parser.tab.c"
    break;

  case 4: /* lista_instrucciones: instruccion  */
#line 71 "parser.y"
                                                    { (yyval.nodo) = ListaInstrucciones((yyvsp[0].nodo), NULL); }
#line 1517 "parser.tab.c"
    break;

  case 5: /* instruccion: declaration  */
#line 75 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1523 "parser.tab.c"
    break;

  case 6: /* instruccion: asignation  */
#line 76 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1529 "parser.tab.c"
    break;

  case 7: /* instruccion: print  */
#line 77 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1535 "parser.tab.c"
    break;

  case 8: /* instruccion: if_sentence  */
#line 78 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("IF NO IMPLEMENTADO AUN"); /*$$ = $1;*/ }
#line 1541 "parser.tab.c"
    break;

  case 9: /* instruccion: native_func  */
#line 79 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1547 "parser.tab.c"
    break;

  case 10: /* instruccion: switch_case  */
#line 80 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("SWITCH CASE NO IMPLEMENTADA AUN"); /*$$ = $1;*/ }
#line 1553 "parser.tab.c"
    break;

  case 11: /* instruccion: while_sentence  */
#line 81 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("WHILE NO IMPLEMENTADO AUN"); /*$$ = $1;*/ }
#line 1559 "parser.tab.c"
    break;

  case 12: /* instruccion: for_sentence  */
#line 82 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("FOR NO IMPLEMENTADO AUN"); /*$$ = $1;*/ }
#line 1565 "parser.tab.c"
    break;

  case 13: /* instruccion: function_sentence  */
#line 83 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("FUNCION NO IMPLEMENTADA AUN"); /*$$ = $1;*/ }
#line 1571 "parser.tab.c"
    break;

  case 14: /* print: PRINT_SENTENCE PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 89 "parser.y"
                                                                                    { (yyval.nodo) = Print((yyvsp[-2].nodo)); }
#line 1577 "parser.tab.c"
    break;

  case 15: /* print: PRINT_SENTENCE PARENTESIS_OPEN native_func PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 90 "parser.y"
                                                                                    { (yyval.nodo) = Print((yyvsp[-2].nodo)); }
#line 1583 "parser.tab.c"
    break;

  case 16: /* declaration: DATA_TYPE IDENTIFICADOR S_PUNTO_COMA  */
#line 97 "parser.y"
            {  (yyval.nodo) = Var_Declaration((yyvsp[-2].data_type), (yyvsp[-1].identificador), Terminal_Null("DEFAULT")); /* VARIABLE SIN VALOR*/ }
#line 1589 "parser.tab.c"
    break;

  case 17: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL expr S_PUNTO_COMA  */
#line 100 "parser.y"
            { (yyval.nodo) = Var_Declaration((yyvsp[-4].data_type), (yyvsp[-3].identificador), (yyvsp[-1].nodo)); }
#line 1595 "parser.tab.c"
    break;

  case 18: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL PARENTESIS_OPEN DATA_TYPE PARENTESIS_CLOSE IDENTIFICADOR S_PUNTO_COMA  */
#line 103 "parser.y"
            { (yyval.nodo) = Casteo_Narrowing((yyvsp[-7].data_type), (yyvsp[-6].identificador), (yyvsp[-3].data_type), (yyvsp[-1].identificador)); /* CASTEO NARROWING*/ }
#line 1601 "parser.tab.c"
    break;

  case 19: /* declaration: vector  */
#line 105 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("VECTOR NO IMPLEMENTADO AUN"); /* VECTOR */ }
#line 1607 "parser.tab.c"
    break;

  case 20: /* declaration: matriz  */
#line 106 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("MATRIZ NO IMPLEMENTADO AUN"); /* MATRIZ */ }
#line 1613 "parser.tab.c"
    break;

  case 21: /* declaration: dynamic_array  */
#line 107 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("DYNAMIC_ARRAY NO IMPLEMENTADO AUN"); /* DYNAMIC_ARRAY */ }
#line 1619 "parser.tab.c"
    break;

  case 22: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL variable_access S_PUNTO_COMA  */
#line 108 "parser.y"
                                                                                { (yyval.nodo) = Nodo_Vacio("Variable acceso NO IMPLEMENTADO AUN"); /* ASIGNACION DE VARIABLE A VECTOR O MATRIZ */ }
#line 1625 "parser.tab.c"
    break;

  case 23: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL IDENTIFICADOR PARENTESIS_OPEN function_parameters PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 109 "parser.y"
                                                                                                                               { (yyval.nodo) = Nodo_Vacio("DECLARACION DE FUNCION NO IMPLEMENTADO AUN"); /* DECLARACION DE FUNCIONES */ }
#line 1631 "parser.tab.c"
    break;

  case 24: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL parse_expretion PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 110 "parser.y"
                                                                                                                 { (yyval.nodo) = Nodo_Vacio("PARSEO DE TIPOS NO IMPLEMENTADO AUN"); /* PARSEO DE TIPOS */ }
#line 1637 "parser.tab.c"
    break;

  case 25: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL string_join S_PUNTO_COMA  */
#line 111 "parser.y"
                                                                        { (yyval.nodo) = Nodo_Vacio("JOIN DE STRINGS NO IMPLEMENTADO AUN"); /* JOIN DE STRINGS */ }
#line 1643 "parser.tab.c"
    break;

  case 26: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL array_funcs S_PUNTO_COMA  */
#line 112 "parser.y"
                                                                        { (yyval.nodo) = Nodo_Vacio("ARRAY FUNCS NO IMPLEMENTADO AUN"); /* FUNCIONES DE ARRAYS */ }
#line 1649 "parser.tab.c"
    break;

  case 35: /* vector_type: NEW_WORD DATA_TYPE CORCHETE_OPEN expr CORCHETE_CLOSE S_PUNTO_COMA  */
#line 137 "parser.y"
                                                                              { /* VECTOR AUTO */ }
#line 1655 "parser.tab.c"
    break;

  case 36: /* vector_type: LLAVE_OPEN vector_values LLAVE_CLOSE S_PUNTO_COMA  */
#line 138 "parser.y"
                                                                        { /* VECTOR CON VALORES */ }
#line 1661 "parser.tab.c"
    break;

  case 37: /* vector_type: IDENTIFICADOR FUNC_ADD PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 139 "parser.y"
                                                                                        { /* FUNCION ADD EN VECTORES*/}
#line 1667 "parser.tab.c"
    break;

  case 50: /* asignation: IDENTIFICADOR op_expr expr_bridge S_PUNTO_COMA  */
#line 183 "parser.y"
                                                                       { (yyval.nodo) = Asignacion_Variable((yyvsp[-3].identificador), (yyvsp[-2].identificador), (yyvsp[-1].nodo)); /* 'OPERADOR ASIGNACION' PARA UNA VARIABLE Y ASIGNACION NORMAL*/ }
#line 1673 "parser.tab.c"
    break;

  case 51: /* asignation: variable_access S_IGUAL expr S_PUNTO_COMA  */
#line 184 "parser.y"
                                                                       { (yyval.nodo) = Nodo_Vacio("VAR ACCEESS NO IMPLEMENTADO AUN");}
#line 1679 "parser.tab.c"
    break;

  case 52: /* expr_bridge: expr  */
#line 189 "parser.y"
                                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1685 "parser.tab.c"
    break;

  case 53: /* expr_bridge: variable_access  */
#line 190 "parser.y"
                                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1691 "parser.tab.c"
    break;

  case 54: /* op_expr: S_IGUAL  */
#line 195 "parser.y"
                                { (yyval.identificador) = "="; }
#line 1697 "parser.tab.c"
    break;

  case 55: /* op_expr: OP_MAS_IGUAL  */
#line 196 "parser.y"
                                { (yyval.identificador) = "+="; }
#line 1703 "parser.tab.c"
    break;

  case 56: /* op_expr: OP_MENOS_IGUAL  */
#line 197 "parser.y"
                                { (yyval.identificador) = "-="; }
#line 1709 "parser.tab.c"
    break;

  case 57: /* op_expr: OP_MULTI_IGUAL  */
#line 198 "parser.y"
                                { (yyval.identificador) = "*="; }
#line 1715 "parser.tab.c"
    break;

  case 58: /* op_expr: OP_DIV_IGUAL  */
#line 199 "parser.y"
                                { (yyval.identificador) = "/="; }
#line 1721 "parser.tab.c"
    break;

  case 59: /* op_expr: OP_MOD_IGUAL  */
#line 200 "parser.y"
                                { (yyval.identificador) = "%="; }
#line 1727 "parser.tab.c"
    break;

  case 60: /* op_expr: OP_AND_IGUAL  */
#line 201 "parser.y"
                                { (yyval.identificador) = "&="; }
#line 1733 "parser.tab.c"
    break;

  case 61: /* op_expr: OP_OR_IGUAL  */
#line 202 "parser.y"
                                { (yyval.identificador) = "|="; }
#line 1739 "parser.tab.c"
    break;

  case 62: /* op_expr: OP_POT_IGUAL  */
#line 203 "parser.y"
                                { (yyval.identificador) = "^="; }
#line 1745 "parser.tab.c"
    break;

  case 63: /* op_expr: OP_MAYOR_IGUAL  */
#line 204 "parser.y"
                                { (yyval.identificador) = ">>="; }
#line 1751 "parser.tab.c"
    break;

  case 64: /* op_expr: OP_MENOR_IGUAL  */
#line 205 "parser.y"
                                { (yyval.identificador) = "<<="; }
#line 1757 "parser.tab.c"
    break;

  case 65: /* native_func: IDENTIFICADOR FUNC_EQUALS PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 212 "parser.y"
            { (yyval.nodo) = Equals_Compare((yyvsp[-4].identificador), (yyvsp[-1].nodo)); /* PRINT FUNC .EQUALS PARA UNA VARIABLE */ }
#line 1763 "parser.tab.c"
    break;

  case 66: /* native_func: IDENTIFICADOR OP_AUMENTO S_PUNTO_COMA  */
#line 214 "parser.y"
                                                                                                {/* AUMENTADOR DE VARIABLE PARA BUCLES*/}
#line 1769 "parser.tab.c"
    break;

  case 67: /* native_func: IDENTIFICADOR OP_DECREMENTO S_PUNTO_COMA  */
#line 215 "parser.y"
                                                                                                {/* REDUCTOR DE VARIABLE PARA BUCLES*/}
#line 1775 "parser.tab.c"
    break;

  case 68: /* native_func: CONTINUE_WORD S_PUNTO_COMA  */
#line 216 "parser.y"
                                                                       { (yyval.nodo) = Nodo_Vacio("NO IMPLEMENTADO AUN"); /* CONTINUE PARA CICLOS */ }
#line 1781 "parser.tab.c"
    break;

  case 69: /* native_func: BREAK_WORD S_PUNTO_COMA  */
#line 217 "parser.y"
                                                                        { (yyval.nodo) = Nodo_Vacio("NO IMPLEMENTADO AUN"); /* BREAK PARA CICLOS */ }
#line 1787 "parser.tab.c"
    break;

  case 70: /* native_func: RETURN_WORD S_PUNTO_COMA  */
#line 218 "parser.y"
                                                                        { (yyval.nodo) = Nodo_Vacio("NO IMPLEMENTADO AUN"); /* RETURN PARA FUNCIONES */ }
#line 1793 "parser.tab.c"
    break;

  case 71: /* native_func: RETURN_WORD expr S_PUNTO_COMA  */
#line 219 "parser.y"
                                                                        { (yyval.nodo) = Nodo_Vacio("NO IMPLEMENTADO AUN"); /* RETURN PARA FUNCIONES */ }
#line 1799 "parser.tab.c"
    break;

  case 72: /* native_func: IDENTIFICADOR PARENTESIS_OPEN PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 220 "parser.y"
                                                                                        { /** LLAMADA A FUNCION SIN PARAMETROS */ }
#line 1805 "parser.tab.c"
    break;

  case 73: /* variable_access: IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE  */
#line 225 "parser.y"
                                                                                {(yyval.nodo) = Nodo_Vacio("VECTOR NO IMPLEMENTADO AUN");/* ACCESO A VALOR EN UN VECTOR*/}
#line 1811 "parser.tab.c"
    break;

  case 74: /* variable_access: IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE CORCHETE_OPEN expr CORCHETE_CLOSE  */
#line 226 "parser.y"
                                                                                                        {(yyval.nodo) = Nodo_Vacio("MATRIZ NO IMPLEMENTADO AUN");/* ACCESO A VALOR EN UNA MATRIZ */}
#line 1817 "parser.tab.c"
    break;

  case 75: /* if_sentence: IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 231 "parser.y"
                                                                                                        { (yyval.nodo) = Nodo_Vacio("IF SIMPLE NO IMPLEMENTADO AUN"); }
#line 1823 "parser.tab.c"
    break;

  case 76: /* if_sentence: IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE ELSE_WORD LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 232 "parser.y"
                                                                                                                                                            { (yyval.nodo) = Nodo_Vacio("IF ELSE NO IMPLEMENTADO AUN"); }
#line 1829 "parser.tab.c"
    break;

  case 78: /* for_condition: declaration expr S_PUNTO_COMA IDENTIFICADOR OP_AUMENTO  */
#line 242 "parser.y"
                                                                                                  {/* ESTRUCTURA FOR NORMAL */}
#line 1835 "parser.tab.c"
    break;

  case 79: /* for_condition: declaration expr S_PUNTO_COMA IDENTIFICADOR OP_DECREMENTO  */
#line 243 "parser.y"
                                                                                                  {/* ESTRUCTURA FOR NORMAL */}
#line 1841 "parser.tab.c"
    break;

  case 80: /* for_condition: DATA_TYPE IDENTIFICADOR S_PUNTO_PUNTO IDENTIFICADOR  */
#line 244 "parser.y"
                                                                                                  {/* ESTRUCTURA FOR EACH */}
#line 1847 "parser.tab.c"
    break;

  case 86: /* while_sentence: WHILE_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 266 "parser.y"
                                                                                                            { (yyval.nodo) = Nodo_Vacio("WHILE NO IMPLEMENTADO AUN"); }
#line 1853 "parser.tab.c"
    break;

  case 89: /* parameters_bridge: %empty  */
#line 277 "parser.y"
                      {/* vaćio */}
#line 1859 "parser.tab.c"
    break;

  case 95: /* expr: expr '+' expr  */
#line 293 "parser.y"
                                                { (yyval.nodo) = Suma((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1865 "parser.tab.c"
    break;

  case 96: /* expr: expr '-' expr  */
#line 294 "parser.y"
                                                { (yyval.nodo) = Resta((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1871 "parser.tab.c"
    break;

  case 97: /* expr: expr '*' expr  */
#line 295 "parser.y"
                                                { (yyval.nodo) = Multiplicacion((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1877 "parser.tab.c"
    break;

  case 98: /* expr: expr '/' expr  */
#line 296 "parser.y"
                                                { (yyval.nodo) = Division((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1883 "parser.tab.c"
    break;

  case 99: /* expr: expr '%' expr  */
#line 297 "parser.y"
                                                { (yyval.nodo) = Modulo((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1889 "parser.tab.c"
    break;

  case 100: /* expr: PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 298 "parser.y"
                                                { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1895 "parser.tab.c"
    break;

  case 101: /* expr: INT_NUMBER  */
#line 299 "parser.y"
                                                { (yyval.nodo) = Terminal_Int((yyvsp[0].int_number)); }
#line 1901 "parser.tab.c"
    break;

  case 102: /* expr: FLOAT_NUMBER FLOAT_SUFFIX  */
#line 300 "parser.y"
                                                { (yyval.nodo) = Terminal_Float((yyvsp[-1].float_number)); }
#line 1907 "parser.tab.c"
    break;

  case 103: /* expr: FLOAT_NUMBER  */
#line 301 "parser.y"
                                                { (yyval.nodo) = Terminal_Double((yyvsp[0].float_number)); }
#line 1913 "parser.tab.c"
    break;

  case 104: /* expr: STRING_COMILLAS  */
#line 302 "parser.y"
                                                { if (strlen((yyvsp[0].string_comillas)) == 3) { (yyval.nodo) = Terminal_Char((yyvsp[0].string_comillas)[1]); } else { (yyval.nodo) = Terminal_String((yyvsp[0].string_comillas)); }}
#line 1919 "parser.tab.c"
    break;

  case 105: /* expr: BOOL_VALUE  */
#line 303 "parser.y"
                                                { (yyval.nodo) = Terminal_Bool((yyvsp[0].bool_true)); }
#line 1925 "parser.tab.c"
    break;

  case 106: /* expr: NULL_VALUE  */
#line 304 "parser.y"
                                                { (yyval.nodo) = Terminal_Null((yyvsp[0].null_value)); }
#line 1931 "parser.tab.c"
    break;

  case 107: /* expr: IDENTIFICADOR  */
#line 305 "parser.y"
                                                { (yyval.nodo) = Identificador_Ref((yyvsp[0].identificador));}
#line 1937 "parser.tab.c"
    break;

  case 108: /* expr: expr OP_MENOR_A expr  */
#line 306 "parser.y"
                                                { (yyval.nodo) = Menor_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1943 "parser.tab.c"
    break;

  case 109: /* expr: expr OP_MAYOR_A expr  */
#line 307 "parser.y"
                                                { (yyval.nodo) = Mayor_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1949 "parser.tab.c"
    break;

  case 110: /* expr: expr OP_MENOR_IGUAL_A expr  */
#line 308 "parser.y"
                                                { (yyval.nodo) = Menor_Igual_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1955 "parser.tab.c"
    break;

  case 111: /* expr: expr OP_MAYOR_IGUAL_A expr  */
#line 309 "parser.y"
                                                { (yyval.nodo) = Mayor_Igual_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1961 "parser.tab.c"
    break;

  case 112: /* expr: expr OP_IGUAL_IGUAL expr  */
#line 310 "parser.y"
                                                { (yyval.nodo) = Igual_Igual((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1967 "parser.tab.c"
    break;

  case 113: /* expr: expr OP_DISTINTO_A expr  */
#line 311 "parser.y"
                                                { (yyval.nodo) = Diferente_Que((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1973 "parser.tab.c"
    break;

  case 114: /* expr: expr LOGIC_AND expr  */
#line 312 "parser.y"
                                                { (yyval.nodo) = And((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1979 "parser.tab.c"
    break;

  case 115: /* expr: expr LOGIC_OR expr  */
#line 313 "parser.y"
                                                { (yyval.nodo) = Or((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1985 "parser.tab.c"
    break;

  case 116: /* expr: LOGIC_NOT expr  */
#line 314 "parser.y"
                                                { (yyval.nodo) = Not((yyvsp[0].nodo)); }
#line 1991 "parser.tab.c"
    break;


#line 1995 "parser.tab.c"

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

#line 317 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error: sintáctico en linea: %d\n", yylineno);
}
