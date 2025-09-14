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
  YYSYMBOL_switch_case_list = 99,          /* switch_case_list  */
  YYSYMBOL_switch_default = 100,           /* switch_default  */
  YYSYMBOL_while_sentence = 101,           /* while_sentence  */
  YYSYMBOL_function_sentence = 102,        /* function_sentence  */
  YYSYMBOL_parameters_bridge = 103,        /* parameters_bridge  */
  YYSYMBOL_function_parameters = 104,      /* function_parameters  */
  YYSYMBOL_function_expr = 105,            /* function_expr  */
  YYSYMBOL_expr = 106                      /* expr  */
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
#define YYLAST   1054

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  69
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  316

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
       0,    68,    68,    72,    73,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    91,    92,    98,   101,   104,   107,
     109,   111,   113,   116,   119,   122,   124,   128,   129,   130,
     131,   135,   140,   141,   146,   151,   154,   157,   162,   164,
     170,   176,   179,   185,   187,   193,   197,   198,   202,   203,
     209,   210,   215,   216,   221,   222,   223,   224,   225,   226,
     227,   228,   229,   230,   231,   237,   240,   241,   242,   243,
     244,   249,   250,   255,   258,   261,   266,   271,   291,   300,
     306,   308,   313,   314,   318,   323,   324,   329,   330,   335,
     341,   346,   347,   352,   353,   354,   358,   359,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   387
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
  "for_condition", "for_option", "switch_case", "switch_case_list",
  "switch_default", "while_sentence", "function_sentence",
  "parameters_bridge", "function_parameters", "function_expr", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-225)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-87)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     382,    27,    31,    39,    41,    52,    56,    68,   166,   131,
      -3,    88,   382,  -225,  -225,  -225,  -225,  -225,  -225,  -225,
    -225,  -225,    38,  -225,  -225,  -225,  -225,  -225,    45,  -225,
     434,   109,   434,    37,  -225,  -225,   434,   434,  -225,    79,
     105,  -225,  -225,   117,   408,   144,  -225,  -225,   434,  -225,
    -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,
     511,   155,   112,     5,  -225,  -225,   434,   156,   540,   133,
     161,   562,   583,     3,   434,   171,   590,  -225,  -225,   175,
     182,  -225,   434,   434,   434,   434,   434,   434,   434,   434,
     434,   434,   434,   434,   434,   197,   803,    94,   199,  -225,
     957,  -225,    10,  -225,     7,   185,   206,   -10,   460,   201,
     210,   213,   222,   214,    66,   467,   217,  -225,   434,   434,
     219,   219,   145,   145,  -225,  -225,  -225,   219,   219,  1004,
    1004,   985,   978,  -225,   220,  -225,   221,   209,  -225,   215,
     259,   243,  -225,   957,  -225,    60,   269,   273,  -225,  -225,
    -225,  -225,    91,   275,   280,   281,   488,   261,   218,  -225,
     282,   382,  -225,  -225,   382,   233,   234,   382,   626,   633,
     434,   237,   -11,  -225,   276,    92,   292,   252,   434,     7,
    -225,   434,  -225,  -225,  -225,  -225,   235,   434,    11,    -4,
     208,  -225,   140,   260,  -225,  -225,   824,   248,   434,   277,
     241,  -225,   382,  -225,   257,   288,   950,    17,   654,   291,
     761,   434,   312,   298,  -225,   301,  -225,  -225,  -225,    -2,
      73,   957,   318,   300,   289,   322,   434,   434,   326,   330,
     434,    24,   382,   782,   382,  -225,   189,  -225,   320,   268,
    -225,   336,   434,   434,   434,  -225,  -225,    65,   676,  -225,
    -225,   845,  -225,   434,   401,   382,   382,   338,   382,   321,
     434,    98,   323,  -225,   957,   697,   866,   347,  -225,  -225,
     887,   348,   419,   434,   310,   224,   103,   349,   337,   434,
     355,   356,  -225,  -225,   157,   358,   704,  -225,   359,   382,
    -225,  -225,   434,   908,  -225,  -225,   193,   352,   434,   327,
     137,   350,   382,   740,  -225,  -225,   434,   346,   353,   929,
    -225,   382,   368,   365,  -225,  -225
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     4,     7,     5,    25,    19,    20,    21,
       6,     9,     0,     8,    12,    10,    11,    13,     0,    67,
       0,     0,     0,     0,    66,    68,     0,     0,   104,   106,
     107,   108,   109,   110,     0,     0,    82,    83,     0,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,     0,     0,     0,     1,     3,     0,     0,     0,   110,
       0,     0,     0,     0,     0,     0,     0,   119,   105,     0,
       0,    69,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   110,     0,    53,
      52,    65,     0,    16,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,     0,     0,
     111,   112,    98,    99,   101,   100,   102,   113,   114,   115,
     116,   117,   118,    70,    71,    50,     0,     0,    95,     0,
       0,    91,    94,    96,    47,     0,     0,     0,    27,    29,
      28,    30,   110,     0,     0,     0,     0,     0,     0,    51,
       0,     0,    15,    14,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    97,     0,     0,     0,     0,     0,     0,
      33,     0,    26,    22,    17,    46,     0,     0,    88,     0,
       0,    81,     0,     0,   121,   120,     0,     0,     0,     0,
       0,    34,     0,    93,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    89,    73,    80,    79,    72,     0,
       0,    39,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,     0,    78,     0,     0,
      40,     0,     0,     0,     0,    90,    18,     0,     0,    23,
      24,     0,    45,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,    36,    38,     0,     0,     0,    32,    49,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    48,    67,     0,     0,    74,     0,     0,
      44,    42,     0,     0,    37,    35,    67,     0,     0,     0,
       0,     0,     0,     0,    75,    43,     0,     0,     0,     0,
      76,     0,     0,     0,    41,    77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -225,  -225,  -129,   -12,  -225,   342,  -225,  -225,  -225,  -225,
    -225,  -224,  -225,  -225,  -225,  -225,  -225,  -225,  -225,  -225,
    -225,   357,   -56,  -225,  -225,  -225,  -225,  -225,   186,  -225,
    -225,  -225,  -225,  -225,  -225,   205,   225,    -7
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,   153,    16,   154,    17,
     201,   220,    18,   240,   261,    19,   107,   231,    20,    98,
      60,    21,    22,    23,   237,   259,    24,    75,    61,    25,
     188,   213,    26,    27,   140,   141,   142,   221
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      65,    44,   247,     1,    99,     2,   198,     3,   103,   104,
       4,    36,     5,   157,   214,   238,     6,     7,     8,   211,
      62,   212,   228,    68,    71,    72,    62,   252,   105,    76,
      77,    28,   189,   136,    29,   190,   276,   138,   193,    37,
      38,    96,   175,    30,   199,    31,   158,   253,    39,    40,
     155,     9,    63,   100,    41,    42,    32,   200,   114,   108,
      33,   106,    43,    10,    36,   137,   239,   115,   300,   103,
     267,    34,   165,   224,   139,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,    64,   105,
     242,   241,    37,    38,    66,   179,    36,   143,   242,   156,
      67,    39,    40,   254,    73,   256,    80,    41,    42,    80,
      78,   168,   169,    36,    48,    43,   277,    48,     2,   180,
      79,   290,   106,   278,    37,    38,   272,   176,   242,   274,
       7,     8,    80,    39,    40,    45,   102,    45,    76,    41,
      42,    37,    38,    46,    47,    46,    47,    43,    80,    95,
      39,    40,    46,    47,    48,   305,    41,    42,   101,   139,
     299,   109,   242,   196,    69,   -86,   111,   -86,   143,    35,
      36,   206,   143,   307,   208,   -86,   116,    65,    65,   118,
     210,    65,   313,    86,    87,    88,   119,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    37,    38,
     133,   -85,   135,   -85,   233,   257,   258,    39,    40,   144,
     145,   -85,    65,    41,    42,     1,   162,     2,   160,     3,
     248,    43,     4,   251,     5,   163,   215,   161,     6,     7,
       8,   164,   146,   147,   167,   264,   265,   266,    37,    38,
     288,   289,    65,   170,    65,   171,   270,    39,    40,   148,
     149,   150,   151,    41,    42,    84,    85,    86,    87,    88,
      65,   152,    65,     9,   174,   172,   286,     1,   175,     2,
     173,     3,   293,   177,     4,    10,     5,   178,   217,   181,
       6,     7,     8,   182,   183,   185,   186,    65,   191,   192,
     187,   303,   197,   202,   205,    65,     1,   204,     2,   309,
       3,    65,   209,     4,   219,     5,   222,   245,   223,     6,
       7,     8,   225,   226,   230,     9,   235,     1,   234,     2,
     236,     3,   243,   244,     4,   246,     5,    10,   287,   249,
       6,     7,     8,   250,     1,   262,     2,   260,     3,   263,
     275,     4,   273,     5,     9,   304,   279,     6,     7,     8,
     282,   284,   291,     1,   292,     2,    10,     3,   294,   295,
       4,   296,     5,   298,   310,     9,     6,     7,     8,   302,
     311,   314,     1,   306,     2,    74,     3,    10,   216,     4,
       0,     5,     9,   315,   207,     6,     7,     8,    70,     1,
       0,     2,     0,     3,    10,     0,     4,     0,     5,     0,
     203,     9,     6,     7,     8,     0,     0,     0,     1,     0,
     271,    81,     3,    10,     0,     4,     0,     5,     0,     0,
       9,     6,     7,     8,     0,     0,     1,     0,   285,     0,
       3,     0,    10,     4,     0,     5,     0,     9,    36,     6,
       7,     8,    82,    83,    84,    85,    86,    87,    88,    10,
       0,     0,     0,     0,     0,     0,     9,    89,    90,    91,
      92,    93,    94,   159,     0,     0,    37,    38,    10,     0,
     166,     0,     0,     0,     9,    39,    40,     0,     0,     0,
       0,    41,    42,     0,     0,     0,    10,     0,     0,    43,
       0,   184,     0,     0,    82,    83,    84,    85,    86,    87,
      88,    82,    83,    84,    85,    86,    87,    88,     0,    89,
      90,    91,    92,    93,    94,    36,    89,    90,    91,    92,
      93,    94,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,     0,     0,     0,     0,    89,    90,    91,
      92,    93,    94,    37,    38,   110,     0,     0,     0,     0,
       0,     0,    39,    40,     0,     0,     0,     0,    41,    42,
       0,     0,     0,     0,     0,     0,    97,   112,     0,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,     0,     0,     0,     0,   113,    89,
      90,    91,    92,    93,    94,   117,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,     0,     0,     0,     0,
       0,    89,    90,    91,    92,    93,    94,    82,    83,    84,
      85,    86,    87,    88,    82,    83,    84,    85,    86,    87,
      88,   194,    89,    90,    91,    92,    93,    94,   195,    89,
      90,    91,    92,    93,    94,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   229,
      82,    83,    84,    85,    86,    87,    88,    82,    83,    84,
      85,    86,    87,    88,     0,    89,    90,    91,    92,    93,
      94,   268,    89,    90,    91,    92,    93,    94,    82,    83,
      84,    85,    86,    87,    88,     0,     0,     0,     0,     0,
       0,     0,   280,    89,    90,    91,    92,    93,    94,   297,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
       0,     0,     0,     0,     0,    89,    90,    91,    92,    93,
      94,    82,    83,    84,    85,    86,    87,    88,    82,    83,
      84,    85,    86,    87,    88,   308,    89,    90,    91,    92,
      93,    94,     0,    89,    90,    91,    92,    93,    94,     0,
       0,     0,     0,     0,     0,     0,     0,   232,     0,     0,
       0,     0,     0,     0,    82,    83,    84,    85,    86,    87,
      88,     0,     0,     0,     0,     0,     0,     0,   255,    89,
      90,    91,    92,    93,    94,    82,    83,    84,    85,    86,
      87,    88,     0,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,    93,    94,    82,    83,    84,    85,
      86,    87,    88,     0,     0,     0,     0,   134,     0,     0,
       0,    89,    90,    91,    92,    93,    94,    82,    83,    84,
      85,    86,    87,    88,     0,     0,     0,     0,   218,     0,
       0,     0,    89,    90,    91,    92,    93,    94,    82,    83,
      84,    85,    86,    87,    88,     0,     0,     0,     0,   269,
       0,     0,     0,    89,    90,    91,    92,    93,    94,    82,
      83,    84,    85,    86,    87,    88,     0,     0,     0,     0,
     281,     0,     0,     0,    89,    90,    91,    92,    93,    94,
      82,    83,    84,    85,    86,    87,    88,     0,     0,     0,
       0,   283,     0,     0,     0,    89,    90,    91,    92,    93,
      94,    82,    83,    84,    85,    86,    87,    88,     0,     0,
       0,     0,   301,     0,     0,     0,    89,    90,    91,    92,
      93,    94,    82,    83,    84,    85,    86,    87,    88,     0,
       0,     0,     0,   312,     0,     0,     0,    89,    90,    91,
      92,    93,    94,    82,    83,    84,    85,    86,    87,    88,
       0,     0,     0,     0,     0,   227,     0,     0,    89,    90,
      91,    92,    93,    94,    82,    83,    84,    85,    86,    87,
      88,    82,    83,    84,    85,    86,    87,    88,     0,    89,
      90,    91,    92,    93,    94,     0,    89,    90,    91,    92,
      93,    94,    82,    83,    84,    85,    86,    87,    88,    82,
      83,    84,    85,    86,    87,    88,     0,    89,    90,    91,
      92,    93,     0,     0,    89,    90,    91,    92,    82,    83,
      84,    85,    86,    87,    88,     0,     0,     0,     0,     0,
       0,     0,     0,    89,    90
};

static const yytype_int16 yycheck[] =
{
      12,     8,   226,     7,    60,     9,    17,    11,     3,     4,
      14,     4,    16,    23,    18,    17,    20,    21,    22,     8,
      23,    10,     5,    30,    31,    32,    23,     3,    23,    36,
      37,     4,   161,    23,     3,   164,   260,    30,   167,    32,
      33,    48,    25,     4,    55,     4,    56,    23,    41,    42,
     106,    55,    55,    60,    47,    48,     4,    68,    55,    66,
       4,    56,    55,    67,     4,    55,    68,    74,   292,     3,
       5,     3,     6,   202,    67,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,     0,    23,
      25,    18,    32,    33,    56,     4,     4,   104,    25,   106,
      55,    41,    42,   232,    67,   234,    15,    47,    48,    15,
      31,   118,   119,     4,    23,    55,    18,    23,     9,    28,
      15,    18,    56,    25,    32,    33,   255,    67,    25,   258,
      21,    22,    15,    41,    42,     4,    24,     4,   145,    47,
      48,    32,    33,    12,    13,    12,    13,    55,    15,     5,
      41,    42,    12,    13,    23,    18,    47,    48,     3,    67,
     289,     5,    25,   170,    55,     8,     5,    10,   175,     3,
       4,   178,   179,   302,   181,    18,     5,   189,   190,     4,
     187,   193,   311,    38,    39,    40,     4,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    32,    33,
       3,     8,     3,    10,   211,    16,    17,    41,    42,    24,
       4,    18,   224,    47,    48,     7,     3,     9,    17,    11,
     227,    55,    14,   230,    16,     3,    18,    17,    20,    21,
      22,    17,    26,    27,    17,   242,   243,   244,    32,    33,
      16,    17,   254,    23,   256,    24,   253,    41,    42,    43,
      44,    45,    46,    47,    48,    36,    37,    38,    39,    40,
     272,    55,   274,    55,     5,    56,   273,     7,    25,     9,
      55,    11,   279,     4,    14,    67,    16,     4,    18,     4,
      20,    21,    22,     3,     3,    24,    68,   299,    55,    55,
       8,   298,    55,    17,    42,   307,     7,     5,     9,   306,
      11,   313,    67,    14,    56,    16,    29,    18,    67,    20,
      21,    22,    55,    25,    23,    55,    18,     7,     6,     9,
      19,    11,     4,    23,    14,     3,    16,    67,    18,     3,
      20,    21,    22,     3,     7,    67,     9,    17,    11,     3,
      19,    14,     4,    16,    55,    18,    23,    20,    21,    22,
       3,     3,     3,     7,    17,     9,    67,    11,     3,     3,
      14,     3,    16,     4,    18,    55,    20,    21,    22,    17,
      17,     3,     7,    23,     9,    33,    11,    67,   192,    14,
      -1,    16,    55,    18,   179,    20,    21,    22,    31,     7,
      -1,     9,    -1,    11,    67,    -1,    14,    -1,    16,    -1,
     175,    55,    20,    21,    22,    -1,    -1,    -1,     7,    -1,
       9,     3,    11,    67,    -1,    14,    -1,    16,    -1,    -1,
      55,    20,    21,    22,    -1,    -1,     7,    -1,     9,    -1,
      11,    -1,    67,    14,    -1,    16,    -1,    55,     4,    20,
      21,    22,    34,    35,    36,    37,    38,    39,    40,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    49,    50,    51,
      52,    53,    54,     3,    -1,    -1,    32,    33,    67,    -1,
       3,    -1,    -1,    -1,    55,    41,    42,    -1,    -1,    -1,
      -1,    47,    48,    -1,    -1,    -1,    67,    -1,    -1,    55,
      -1,     3,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    34,    35,    36,    37,    38,    39,    40,    -1,    49,
      50,    51,    52,    53,    54,     4,    49,    50,    51,    52,
      53,    54,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    50,    51,
      52,    53,    54,    32,    33,     5,    -1,    -1,    -1,    -1,
      -1,    -1,    41,    42,    -1,    -1,    -1,    -1,    47,    48,
      -1,    -1,    -1,    -1,    -1,    -1,    55,     5,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,    49,
      50,    51,    52,    53,    54,     5,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    49,    50,    51,    52,    53,    54,    34,    35,    36,
      37,    38,    39,    40,    34,    35,    36,    37,    38,    39,
      40,     5,    49,    50,    51,    52,    53,    54,     5,    49,
      50,    51,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     5,
      34,    35,    36,    37,    38,    39,    40,    34,    35,    36,
      37,    38,    39,    40,    -1,    49,    50,    51,    52,    53,
      54,     5,    49,    50,    51,    52,    53,    54,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     5,    49,    50,    51,    52,    53,    54,     5,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    49,    50,    51,    52,    53,
      54,    34,    35,    36,    37,    38,    39,    40,    34,    35,
      36,    37,    38,    39,    40,     5,    49,    50,    51,    52,
      53,    54,    -1,    49,    50,    51,    52,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,    49,
      50,    51,    52,    53,    54,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    50,    51,    52,    53,    54,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    24,    -1,    -1,
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
      -1,    -1,    -1,    -1,    -1,    25,    -1,    -1,    49,    50,
      51,    52,    53,    54,    34,    35,    36,    37,    38,    39,
      40,    34,    35,    36,    37,    38,    39,    40,    -1,    49,
      50,    51,    52,    53,    54,    -1,    49,    50,    51,    52,
      53,    54,    34,    35,    36,    37,    38,    39,    40,    34,
      35,    36,    37,    38,    39,    40,    -1,    49,    50,    51,
      52,    53,    -1,    -1,    49,    50,    51,    52,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    49,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     9,    11,    14,    16,    20,    21,    22,    55,
      67,    70,    71,    72,    73,    74,    76,    78,    81,    84,
      87,    90,    91,    92,    95,    98,   101,   102,     4,     3,
       4,     4,     4,     4,     3,     3,     4,    32,    33,    41,
      42,    47,    48,    55,   106,     4,    12,    13,    23,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      89,    97,    23,    55,     0,    72,    56,    55,   106,    55,
      90,   106,   106,    67,    74,    96,   106,   106,    31,    15,
      15,     3,    34,    35,    36,    37,    38,    39,    40,    49,
      50,    51,    52,    53,    54,     5,   106,    55,    88,    91,
     106,     3,    24,     3,     4,    23,    56,    85,   106,     5,
       5,     5,     5,     5,    55,   106,     5,     5,     4,     4,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,     3,    24,     3,    23,    55,    30,    67,
     103,   104,   105,   106,    24,     4,    26,    27,    43,    44,
      45,    46,    55,    75,    77,    91,   106,    23,    56,     3,
      17,    17,     3,     3,    17,     6,     3,    17,   106,   106,
      23,    24,    56,    55,     5,    25,    67,     4,     4,     4,
      28,     4,     3,     3,     3,    24,    68,     8,    99,    71,
      71,    55,    55,    71,     5,     5,   106,    55,    17,    55,
      68,    79,    17,   105,     5,    42,   106,   104,   106,    67,
     106,     8,    10,   100,    18,    18,    97,    18,    24,    56,
      80,   106,    29,    67,    71,    55,    25,    25,     5,     5,
      23,    86,     6,   106,     6,    18,    19,    93,    17,    68,
      82,    18,    25,     4,    23,    18,     3,    80,   106,     3,
       3,   106,     3,    23,    71,     6,    71,    16,    17,    94,
      17,    83,    67,     3,   106,   106,   106,     5,     5,    24,
     106,     9,    71,     4,    71,    19,    80,    18,    25,    23,
       5,    24,     3,    24,     3,     9,   106,    18,    16,    17,
      18,     3,    17,   106,     3,     3,     3,     5,     4,    71,
      80,    24,    17,   106,    18,    18,    23,    71,     5,   106,
      18,    17,    24,    71,     3,    18
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
      90,    91,    91,    92,    92,    92,    93,    94,    94,    95,
      96,    96,    97,    97,    98,    99,    99,   100,   100,   101,
     102,   103,   103,   104,   104,   104,   105,   105,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     3,     5,     8,     1,
       1,     1,     5,     8,     8,     1,     5,     1,     1,     1,
       1,    10,     6,     2,     6,     6,     4,     6,     3,     1,
       8,     9,     4,     5,     3,     8,     3,     2,     4,     3,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     2,     2,     3,
       4,     4,     7,     7,    11,    13,     8,     9,     0,     7,
       5,     4,     1,     1,     8,     7,     6,     3,     0,     7,
       8,     1,     0,     3,     1,     1,     1,     2,     3,     3,
       3,     3,     3,     3,     1,     2,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       5,     5
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
#line 68 "parser.y"
                                                    { raiz = (yyvsp[0].nodo); yylineno = 1; }
#line 1535 "parser.tab.c"
    break;

  case 3: /* lista_instrucciones: lista_instrucciones instruccion  */
#line 72 "parser.y"
                                                    { (yyval.nodo) = ListaInstrucciones((yyvsp[-1].nodo), (yyvsp[0].nodo)); }
#line 1541 "parser.tab.c"
    break;

  case 4: /* lista_instrucciones: instruccion  */
#line 73 "parser.y"
                                                    { (yyval.nodo) = ListaInstrucciones((yyvsp[0].nodo), NULL); }
#line 1547 "parser.tab.c"
    break;

  case 5: /* instruccion: declaration  */
#line 77 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1553 "parser.tab.c"
    break;

  case 6: /* instruccion: asignation  */
#line 78 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1559 "parser.tab.c"
    break;

  case 7: /* instruccion: print  */
#line 79 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1565 "parser.tab.c"
    break;

  case 8: /* instruccion: if_sentence  */
#line 80 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1571 "parser.tab.c"
    break;

  case 9: /* instruccion: native_func  */
#line 81 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1577 "parser.tab.c"
    break;

  case 10: /* instruccion: switch_case  */
#line 82 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("SWITCH CASE NO IMPLEMENTADA AUN"); /*$$ = $1;*/ }
#line 1583 "parser.tab.c"
    break;

  case 11: /* instruccion: while_sentence  */
#line 83 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1589 "parser.tab.c"
    break;

  case 12: /* instruccion: for_sentence  */
#line 84 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1595 "parser.tab.c"
    break;

  case 13: /* instruccion: function_sentence  */
#line 85 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("FUNCION NO IMPLEMENTADA AUN"); /*$$ = $1;*/ }
#line 1601 "parser.tab.c"
    break;

  case 14: /* print: PRINT_SENTENCE PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 91 "parser.y"
                                                                                    { (yyval.nodo) = Print((yyvsp[-2].nodo)); }
#line 1607 "parser.tab.c"
    break;

  case 15: /* print: PRINT_SENTENCE PARENTESIS_OPEN native_func PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 92 "parser.y"
                                                                                    { (yyval.nodo) = Print((yyvsp[-2].nodo)); }
#line 1613 "parser.tab.c"
    break;

  case 16: /* declaration: DATA_TYPE IDENTIFICADOR S_PUNTO_COMA  */
#line 99 "parser.y"
            {  (yyval.nodo) = Var_Declaration((yyvsp[-2].data_type), (yyvsp[-1].identificador), Terminal_Null("DEFAULT")); /* VARIABLE SIN VALOR*/ }
#line 1619 "parser.tab.c"
    break;

  case 17: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL expr S_PUNTO_COMA  */
#line 102 "parser.y"
            { (yyval.nodo) = Var_Declaration((yyvsp[-4].data_type), (yyvsp[-3].identificador), (yyvsp[-1].nodo)); }
#line 1625 "parser.tab.c"
    break;

  case 18: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL PARENTESIS_OPEN DATA_TYPE PARENTESIS_CLOSE IDENTIFICADOR S_PUNTO_COMA  */
#line 105 "parser.y"
            { (yyval.nodo) = Casteo_Narrowing((yyvsp[-7].data_type), (yyvsp[-6].identificador), (yyvsp[-3].data_type), (yyvsp[-1].identificador)); /* CASTEO NARROWING*/ }
#line 1631 "parser.tab.c"
    break;

  case 19: /* declaration: vector  */
#line 107 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); /* DECLARATION VECTOR */ }
#line 1637 "parser.tab.c"
    break;

  case 20: /* declaration: matriz  */
#line 109 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); /* MATRIZ */ }
#line 1643 "parser.tab.c"
    break;

  case 21: /* declaration: dynamic_array  */
#line 111 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("DYNAMIC_ARRAY NO IMPLEMENTADO AUN"); /* DYNAMIC_ARRAY */ }
#line 1649 "parser.tab.c"
    break;

  case 22: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL variable_access S_PUNTO_COMA  */
#line 114 "parser.y"
            { (yyval.nodo) = Nodo_Vacio("Variable acceso NO IMPLEMENTADO AUN"); /* ASIGNACION DE VARIABLE A VECTOR O MATRIZ */ }
#line 1655 "parser.tab.c"
    break;

  case 23: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL IDENTIFICADOR PARENTESIS_OPEN function_parameters PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 117 "parser.y"
            { (yyval.nodo) = Nodo_Vacio("DECLARACION DE FUNCION NO IMPLEMENTADO AUN"); /* DECLARACION DE FUNCIONES */ }
#line 1661 "parser.tab.c"
    break;

  case 24: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL parse_expretion PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 120 "parser.y"
            { (yyval.nodo) = Parse_Expression((yyvsp[-6].identificador), (yyvsp[-7].data_type), (yyvsp[-4].identificador), (yyvsp[-2].nodo)); /* PARSEO DE TIPOS */ }
#line 1667 "parser.tab.c"
    break;

  case 25: /* declaration: string_join  */
#line 122 "parser.y"
                           { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1673 "parser.tab.c"
    break;

  case 26: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL array_funcs S_PUNTO_COMA  */
#line 124 "parser.y"
                                                                        { (yyval.nodo) = Nodo_Vacio("ARRAY FUNCS NO IMPLEMENTADO AUN"); /* FUNCIONES DE ARRAYS */ }
#line 1679 "parser.tab.c"
    break;

  case 27: /* parse_expretion: PARSE_INT  */
#line 128 "parser.y"
                                     { (yyval.identificador) = "int"; }
#line 1685 "parser.tab.c"
    break;

  case 28: /* parse_expretion: PARSE_DOUBLE  */
#line 129 "parser.y"
                                     { (yyval.identificador) = "double"; }
#line 1691 "parser.tab.c"
    break;

  case 29: /* parse_expretion: PARSE_FLOAT  */
#line 130 "parser.y"
                                     { (yyval.identificador) = "float"; }
#line 1697 "parser.tab.c"
    break;

  case 30: /* parse_expretion: PARSE_STRING  */
#line 131 "parser.y"
                                     { (yyval.identificador) = "String"; }
#line 1703 "parser.tab.c"
    break;

  case 31: /* string_join: DATA_TYPE IDENTIFICADOR S_IGUAL JOIN_STRING PARENTESIS_OPEN STRING_COMILLAS COMA vector_values PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 136 "parser.y"
            { (yyval.nodo) = Var_Declaration((yyvsp[-9].data_type), (yyvsp[-8].identificador), Make_StringJoin((yyvsp[-9].data_type), (yyvsp[-4].string_comillas), (yyvsp[-2].lista_nodos))); }
#line 1709 "parser.tab.c"
    break;

  case 34: /* vector: DATA_TYPE CORCHETE_OPEN CORCHETE_CLOSE IDENTIFICADOR S_IGUAL vector_type  */
#line 147 "parser.y"
        { (yyval.nodo) = Declaration_Vector((yyvsp[-5].data_type), (yyvsp[-2].identificador), (yyvsp[0].nodo)); /* REGRESAMOS EL NODO QUE GENERA */ }
#line 1715 "parser.tab.c"
    break;

  case 35: /* vector_type: NEW_WORD DATA_TYPE CORCHETE_OPEN expr CORCHETE_CLOSE S_PUNTO_COMA  */
#line 152 "parser.y"
            { (yyval.nodo) = Vector_Auto((yyvsp[-5].data_type), (yyvsp[-4].data_type), (yyvsp[-2].nodo)); }
#line 1721 "parser.tab.c"
    break;

  case 36: /* vector_type: LLAVE_OPEN vector_values LLAVE_CLOSE S_PUNTO_COMA  */
#line 155 "parser.y"
            { (yyval.nodo) = Valores_Vector((yyvsp[-2].lista_nodos)); /* VECTOR CON VALORES */ }
#line 1727 "parser.tab.c"
    break;

  case 37: /* vector_type: IDENTIFICADOR FUNC_ADD PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 157 "parser.y"
                                                                                        { /* FUNCION ADD EN VECTORES*/}
#line 1733 "parser.tab.c"
    break;

  case 38: /* vector_values: vector_values COMA expr  */
#line 163 "parser.y"
            { (yyval.lista_nodos) = Add_Valor_Vector((yyvsp[-2].lista_nodos), (yyvsp[0].nodo)); }
#line 1739 "parser.tab.c"
    break;

  case 39: /* vector_values: expr  */
#line 165 "parser.y"
            { (yyval.lista_nodos) = Lista_Vector((yyvsp[0].nodo)); }
#line 1745 "parser.tab.c"
    break;

  case 40: /* matriz: DATA_TYPE CORCHETE_OPEN CORCHETE_CLOSE CORCHETE_OPEN CORCHETE_CLOSE IDENTIFICADOR S_IGUAL matriz_type  */
#line 171 "parser.y"
        { (yyval.nodo) = Declaration_Matriz((yyvsp[-7].data_type), (yyvsp[-2].identificador), (yyvsp[0].nodo)); /* REGRESAMOS EL NODO QUE GENERA */ }
#line 1751 "parser.tab.c"
    break;

  case 41: /* matriz_type: NEW_WORD DATA_TYPE CORCHETE_OPEN expr CORCHETE_CLOSE CORCHETE_OPEN expr CORCHETE_CLOSE S_PUNTO_COMA  */
#line 177 "parser.y"
            { (yyval.nodo) = Matriz_Auto((yyvsp[-7].data_type), (yyvsp[-5].nodo), (yyvsp[-2].nodo)); /* valores definidos en matriz*/ }
#line 1757 "parser.tab.c"
    break;

  case 42: /* matriz_type: LLAVE_OPEN matriz_values LLAVE_CLOSE S_PUNTO_COMA  */
#line 180 "parser.y"
            { (yyval.nodo) = Nodo_Vacio("VALORES DE MATRIZ NO IMPLEMENTADO AUN"); /* valores definidos en matriz*/ }
#line 1763 "parser.tab.c"
    break;

  case 44: /* matriz_values: LLAVE_OPEN vector_values LLAVE_CLOSE  */
#line 188 "parser.y"
            { /* valores definidos en matriz*/}
#line 1769 "parser.tab.c"
    break;

  case 50: /* asignation: IDENTIFICADOR op_expr expr_bridge S_PUNTO_COMA  */
#line 209 "parser.y"
                                                                       { (yyval.nodo) = Asignacion_Variable((yyvsp[-3].identificador), (yyvsp[-2].identificador), (yyvsp[-1].nodo)); /* 'OPERADOR ASIGNACION' PARA UNA VARIABLE Y ASIGNACION NORMAL*/ }
#line 1775 "parser.tab.c"
    break;

  case 51: /* asignation: variable_access S_IGUAL expr S_PUNTO_COMA  */
#line 210 "parser.y"
                                                                       { (yyval.nodo) = Nodo_Vacio("VAR ACCEESS NO IMPLEMENTADO AUN");}
#line 1781 "parser.tab.c"
    break;

  case 52: /* expr_bridge: expr  */
#line 215 "parser.y"
                                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1787 "parser.tab.c"
    break;

  case 53: /* expr_bridge: variable_access  */
#line 216 "parser.y"
                                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1793 "parser.tab.c"
    break;

  case 54: /* op_expr: S_IGUAL  */
#line 221 "parser.y"
                                { (yyval.identificador) = "="; }
#line 1799 "parser.tab.c"
    break;

  case 55: /* op_expr: OP_MAS_IGUAL  */
#line 222 "parser.y"
                                { (yyval.identificador) = "+="; }
#line 1805 "parser.tab.c"
    break;

  case 56: /* op_expr: OP_MENOS_IGUAL  */
#line 223 "parser.y"
                                { (yyval.identificador) = "-="; }
#line 1811 "parser.tab.c"
    break;

  case 57: /* op_expr: OP_MULTI_IGUAL  */
#line 224 "parser.y"
                                { (yyval.identificador) = "*="; }
#line 1817 "parser.tab.c"
    break;

  case 58: /* op_expr: OP_DIV_IGUAL  */
#line 225 "parser.y"
                                { (yyval.identificador) = "/="; }
#line 1823 "parser.tab.c"
    break;

  case 59: /* op_expr: OP_MOD_IGUAL  */
#line 226 "parser.y"
                                { (yyval.identificador) = "%="; }
#line 1829 "parser.tab.c"
    break;

  case 60: /* op_expr: OP_AND_IGUAL  */
#line 227 "parser.y"
                                { (yyval.identificador) = "&="; }
#line 1835 "parser.tab.c"
    break;

  case 61: /* op_expr: OP_OR_IGUAL  */
#line 228 "parser.y"
                                { (yyval.identificador) = "|="; }
#line 1841 "parser.tab.c"
    break;

  case 62: /* op_expr: OP_POT_IGUAL  */
#line 229 "parser.y"
                                { (yyval.identificador) = "^="; }
#line 1847 "parser.tab.c"
    break;

  case 63: /* op_expr: OP_MAYOR_IGUAL  */
#line 230 "parser.y"
                                { (yyval.identificador) = ">>="; }
#line 1853 "parser.tab.c"
    break;

  case 64: /* op_expr: OP_MENOR_IGUAL  */
#line 231 "parser.y"
                                { (yyval.identificador) = "<<="; }
#line 1859 "parser.tab.c"
    break;

  case 65: /* native_func: IDENTIFICADOR for_option S_PUNTO_COMA  */
#line 238 "parser.y"
            {(yyval.nodo) = Plus_Minus_Var((yyvsp[-2].identificador), (yyvsp[-1].identificador));}
#line 1865 "parser.tab.c"
    break;

  case 66: /* native_func: CONTINUE_WORD S_PUNTO_COMA  */
#line 240 "parser.y"
                                                                       { (yyval.nodo) = Nodo_Vacio("NO IMPLEMENTADO AUN"); /* CONTINUE PARA CICLOS */ }
#line 1871 "parser.tab.c"
    break;

  case 67: /* native_func: BREAK_WORD S_PUNTO_COMA  */
#line 241 "parser.y"
                                                                        { (yyval.nodo) = Nodo_Vacio("NO IMPLEMENTADO AUN"); /* BREAK PARA CICLOS */ }
#line 1877 "parser.tab.c"
    break;

  case 68: /* native_func: RETURN_WORD S_PUNTO_COMA  */
#line 242 "parser.y"
                                                                        { (yyval.nodo) = Nodo_Vacio("NO IMPLEMENTADO AUN"); /* RETURN PARA FUNCIONES */ }
#line 1883 "parser.tab.c"
    break;

  case 69: /* native_func: RETURN_WORD expr S_PUNTO_COMA  */
#line 243 "parser.y"
                                                                        { (yyval.nodo) = Nodo_Vacio("NO IMPLEMENTADO AUN"); /* RETURN PARA FUNCIONES */ }
#line 1889 "parser.tab.c"
    break;

  case 70: /* native_func: IDENTIFICADOR PARENTESIS_OPEN PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 244 "parser.y"
                                                                                        { /** LLAMADA A FUNCION SIN PARAMETROS */ }
#line 1895 "parser.tab.c"
    break;

  case 71: /* variable_access: IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE  */
#line 249 "parser.y"
                                                                                {(yyval.nodo) = Nodo_Vacio("VECTOR NO IMPLEMENTADO AUN");/* ACCESO A VALOR EN UN VECTOR*/}
#line 1901 "parser.tab.c"
    break;

  case 72: /* variable_access: IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE CORCHETE_OPEN expr CORCHETE_CLOSE  */
#line 250 "parser.y"
                                                                                                        {(yyval.nodo) = Nodo_Vacio("MATRIZ NO IMPLEMENTADO AUN");/* ACCESO A VALOR EN UNA MATRIZ */}
#line 1907 "parser.tab.c"
    break;

  case 73: /* if_sentence: IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 256 "parser.y"
            { (yyval.nodo) = Sentencia_If_Simple((yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 1913 "parser.tab.c"
    break;

  case 74: /* if_sentence: IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE ELSE_WORD LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 259 "parser.y"
            { (yyval.nodo) = Sentencia_If_Else((yyvsp[-8].nodo), (yyvsp[-5].nodo), (yyvsp[-1].nodo)); }
#line 1919 "parser.tab.c"
    break;

  case 75: /* if_sentence: IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE if_else_one if_else_chain ELSE_WORD LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 262 "parser.y"
            { (yyval.nodo) = Sentencia_If_ElseIf_Else((yyvsp[-10].nodo), (yyvsp[-7].nodo), (yyvsp[-5].nodo), (yyvsp[-4].lista_nodos), (yyvsp[-1].nodo)); /* IF - ELSE IF - ELSE CON LISTA DE ELSE IF */ }
#line 1925 "parser.tab.c"
    break;

  case 76: /* if_else_one: ELSE_WORD IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 267 "parser.y"
            { (yyval.nodo) = If_Else_One((yyvsp[-4].nodo), (yyvsp[-1].nodo)); /* INSTRUCCIONES DEL ELSE IF SI SOLSO VIENE UNA VEZ */ }
#line 1931 "parser.tab.c"
    break;

  case 77: /* if_else_chain: if_else_chain ELSE_WORD IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 272 "parser.y"
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
#line 1953 "parser.tab.c"
    break;

  case 78: /* if_else_chain: %empty  */
#line 291 "parser.y"
                { 
                // Inicializar lista vacía
                    (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 1);
                    (yyval.lista_nodos)[0] = NULL;
                }
#line 1963 "parser.tab.c"
    break;

  case 79: /* for_sentence: FOR_WORD PARENTESIS_OPEN for_condition PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 301 "parser.y"
            { (yyval.nodo) = For_Sentence((yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 1969 "parser.tab.c"
    break;

  case 80: /* for_condition: declaration expr S_PUNTO_COMA IDENTIFICADOR for_option  */
#line 307 "parser.y"
            { (yyval.nodo) = For_Condition((yyvsp[-4].nodo), (yyvsp[-3].nodo), (yyvsp[-1].identificador), (yyvsp[0].identificador)); }
#line 1975 "parser.tab.c"
    break;

  case 81: /* for_condition: DATA_TYPE IDENTIFICADOR S_PUNTO_PUNTO IDENTIFICADOR  */
#line 309 "parser.y"
            {  Nodo_Vacio("ESTRUCTURA FOR EACH"); /* Implementacion con los vectores */}
#line 1981 "parser.tab.c"
    break;

  case 82: /* for_option: OP_AUMENTO  */
#line 313 "parser.y"
                       { (yyval.identificador) = "++"; }
#line 1987 "parser.tab.c"
    break;

  case 83: /* for_option: OP_DECREMENTO  */
#line 314 "parser.y"
                            { (yyval.identificador) = "--"; }
#line 1993 "parser.tab.c"
    break;

  case 89: /* while_sentence: WHILE_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 336 "parser.y"
                { (yyval.nodo) = While_Sentence((yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 1999 "parser.tab.c"
    break;

  case 92: /* parameters_bridge: %empty  */
#line 347 "parser.y"
                      {/* vaćio */}
#line 2005 "parser.tab.c"
    break;

  case 98: /* expr: expr '+' expr  */
#line 363 "parser.y"
                                                { (yyval.nodo) = Suma((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2011 "parser.tab.c"
    break;

  case 99: /* expr: expr '-' expr  */
#line 364 "parser.y"
                                                { (yyval.nodo) = Resta((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2017 "parser.tab.c"
    break;

  case 100: /* expr: expr '*' expr  */
#line 365 "parser.y"
                                                { (yyval.nodo) = Multiplicacion((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2023 "parser.tab.c"
    break;

  case 101: /* expr: expr '/' expr  */
#line 366 "parser.y"
                                                { (yyval.nodo) = Division((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2029 "parser.tab.c"
    break;

  case 102: /* expr: expr '%' expr  */
#line 367 "parser.y"
                                                { (yyval.nodo) = Modulo((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2035 "parser.tab.c"
    break;

  case 103: /* expr: PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 368 "parser.y"
                                                { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2041 "parser.tab.c"
    break;

  case 104: /* expr: INT_NUMBER  */
#line 369 "parser.y"
                                                { (yyval.nodo) = Terminal_Int((yyvsp[0].int_number)); }
#line 2047 "parser.tab.c"
    break;

  case 105: /* expr: FLOAT_NUMBER FLOAT_SUFFIX  */
#line 370 "parser.y"
                                                { (yyval.nodo) = Terminal_Float((yyvsp[-1].float_number)); }
#line 2053 "parser.tab.c"
    break;

  case 106: /* expr: FLOAT_NUMBER  */
#line 371 "parser.y"
                                                { (yyval.nodo) = Terminal_Double((yyvsp[0].float_number)); }
#line 2059 "parser.tab.c"
    break;

  case 107: /* expr: STRING_COMILLAS  */
#line 372 "parser.y"
                                                { if (strlen((yyvsp[0].string_comillas)) == 3) { (yyval.nodo) = Terminal_Char((yyvsp[0].string_comillas)[1]); } else { (yyval.nodo) = Terminal_String((yyvsp[0].string_comillas)); }}
#line 2065 "parser.tab.c"
    break;

  case 108: /* expr: BOOL_VALUE  */
#line 373 "parser.y"
                                                { (yyval.nodo) = Terminal_Bool((yyvsp[0].bool_true)); }
#line 2071 "parser.tab.c"
    break;

  case 109: /* expr: NULL_VALUE  */
#line 374 "parser.y"
                                                { (yyval.nodo) = Terminal_Null((yyvsp[0].null_value)); }
#line 2077 "parser.tab.c"
    break;

  case 110: /* expr: IDENTIFICADOR  */
#line 375 "parser.y"
                                                { (yyval.nodo) = Identificador_Ref((yyvsp[0].identificador));}
#line 2083 "parser.tab.c"
    break;

  case 111: /* expr: expr OP_MENOR_A expr  */
#line 376 "parser.y"
                                                { (yyval.nodo) = Menor_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2089 "parser.tab.c"
    break;

  case 112: /* expr: expr OP_MAYOR_A expr  */
#line 377 "parser.y"
                                                { (yyval.nodo) = Mayor_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2095 "parser.tab.c"
    break;

  case 113: /* expr: expr OP_MENOR_IGUAL_A expr  */
#line 378 "parser.y"
                                                { (yyval.nodo) = Menor_Igual_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2101 "parser.tab.c"
    break;

  case 114: /* expr: expr OP_MAYOR_IGUAL_A expr  */
#line 379 "parser.y"
                                                { (yyval.nodo) = Mayor_Igual_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2107 "parser.tab.c"
    break;

  case 115: /* expr: expr OP_IGUAL_IGUAL expr  */
#line 380 "parser.y"
                                                { (yyval.nodo) = Igual_Igual((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2113 "parser.tab.c"
    break;

  case 116: /* expr: expr OP_DISTINTO_A expr  */
#line 381 "parser.y"
                                                { (yyval.nodo) = Diferente_Que((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2119 "parser.tab.c"
    break;

  case 117: /* expr: expr LOGIC_AND expr  */
#line 382 "parser.y"
                                                { (yyval.nodo) = And((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2125 "parser.tab.c"
    break;

  case 118: /* expr: expr LOGIC_OR expr  */
#line 383 "parser.y"
                                                { (yyval.nodo) = Or((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2131 "parser.tab.c"
    break;

  case 119: /* expr: LOGIC_NOT expr  */
#line 384 "parser.y"
                                                { (yyval.nodo) = Not((yyvsp[0].nodo)); }
#line 2137 "parser.tab.c"
    break;

  case 120: /* expr: IDENTIFICADOR FUNC_EQUALS PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 386 "parser.y"
    { (yyval.nodo) = Equals_Compare((yyvsp[-4].identificador), (yyvsp[-1].nodo)); /* PRINT FUNC .EQUALS PARA UNA VARIABLE */ }
#line 2143 "parser.tab.c"
    break;

  case 121: /* expr: STRING_COMILLAS FUNC_EQUALS PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 388 "parser.y"
    { (yyval.nodo) = Equals_Compare((yyvsp[-4].string_comillas), (yyvsp[-1].nodo)); /* PRINT FUNC .EQUALS PARA UNA VARIABLE */ }
#line 2149 "parser.tab.c"
    break;


#line 2153 "parser.tab.c"

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

#line 391 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error: sintáctico en linea: %d\n", yylineno);
}
