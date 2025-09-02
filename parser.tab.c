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
    #include "./Functions/Tabla_Simbolos.h"

    extern int yylex();
    extern int yylineno;
    void yyerror(const char* s);

#line 81 "parser.tab.c"

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
  YYSYMBOL_DATA_TYPE = 3,                  /* DATA_TYPE  */
  YYSYMBOL_S_PUNTO_COMA = 4,               /* S_PUNTO_COMA  */
  YYSYMBOL_S_IGUAL = 5,                    /* S_IGUAL  */
  YYSYMBOL_PARENTESIS_OPEN = 6,            /* PARENTESIS_OPEN  */
  YYSYMBOL_PARENTESIS_CLOSE = 7,           /* PARENTESIS_CLOSE  */
  YYSYMBOL_S_PUNTO_PUNTO = 8,              /* S_PUNTO_PUNTO  */
  YYSYMBOL_SWITCH_WORD = 9,                /* SWITCH_WORD  */
  YYSYMBOL_CASE_WORD = 10,                 /* CASE_WORD  */
  YYSYMBOL_BREAK_WORD = 11,                /* BREAK_WORD  */
  YYSYMBOL_OP_MAS_IGUAL = 12,              /* OP_MAS_IGUAL  */
  YYSYMBOL_OP_MENOS_IGUAL = 13,            /* OP_MENOS_IGUAL  */
  YYSYMBOL_OP_MULTI_IGUAL = 14,            /* OP_MULTI_IGUAL  */
  YYSYMBOL_OP_DIV_IGUAL = 15,              /* OP_DIV_IGUAL  */
  YYSYMBOL_OP_MOD_IGUAL = 16,              /* OP_MOD_IGUAL  */
  YYSYMBOL_OP_AND_IGUAL = 17,              /* OP_AND_IGUAL  */
  YYSYMBOL_DEFAULT_WORD = 18,              /* DEFAULT_WORD  */
  YYSYMBOL_WHILE_WORD = 19,                /* WHILE_WORD  */
  YYSYMBOL_OP_AUMENTO = 20,                /* OP_AUMENTO  */
  YYSYMBOL_OP_DECREMENTO = 21,             /* OP_DECREMENTO  */
  YYSYMBOL_OP_OR_IGUAL = 22,               /* OP_OR_IGUAL  */
  YYSYMBOL_OP_POT_IGUAL = 23,              /* OP_POT_IGUAL  */
  YYSYMBOL_OP_MAYOR_IGUAL = 24,            /* OP_MAYOR_IGUAL  */
  YYSYMBOL_OP_MENOR_IGUAL = 25,            /* OP_MENOR_IGUAL  */
  YYSYMBOL_OP_IGUAL_IGUAL = 26,            /* OP_IGUAL_IGUAL  */
  YYSYMBOL_OP_DISTINTO_A = 27,             /* OP_DISTINTO_A  */
  YYSYMBOL_OP_MENOR_IGUAL_A = 28,          /* OP_MENOR_IGUAL_A  */
  YYSYMBOL_OP_MAYOR_IGUAL_A = 29,          /* OP_MAYOR_IGUAL_A  */
  YYSYMBOL_LOGIC_OR = 30,                  /* LOGIC_OR  */
  YYSYMBOL_LOGIC_AND = 31,                 /* LOGIC_AND  */
  YYSYMBOL_OP_MENOR_A = 32,                /* OP_MENOR_A  */
  YYSYMBOL_OP_MAYOR_A = 33,                /* OP_MAYOR_A  */
  YYSYMBOL_LOGIC_NOT = 34,                 /* LOGIC_NOT  */
  YYSYMBOL_PRINT_SENTENCE = 35,            /* PRINT_SENTENCE  */
  YYSYMBOL_FUNC_EQUALS = 36,               /* FUNC_EQUALS  */
  YYSYMBOL_IF_WORD = 37,                   /* IF_WORD  */
  YYSYMBOL_LLAVE_OPEN = 38,                /* LLAVE_OPEN  */
  YYSYMBOL_LLAVE_CLOSE = 39,               /* LLAVE_CLOSE  */
  YYSYMBOL_ELSE_WORD = 40,                 /* ELSE_WORD  */
  YYSYMBOL_FOR_WORD = 41,                  /* FOR_WORD  */
  YYSYMBOL_CONTINUE_WORD = 42,             /* CONTINUE_WORD  */
  YYSYMBOL_RETURN_WORD = 43,               /* RETURN_WORD  */
  YYSYMBOL_CORCHETE_OPEN = 44,             /* CORCHETE_OPEN  */
  YYSYMBOL_CORCHETE_CLOSE = 45,            /* CORCHETE_CLOSE  */
  YYSYMBOL_NEW_WORD = 46,                  /* NEW_WORD  */
  YYSYMBOL_COMA = 47,                      /* COMA  */
  YYSYMBOL_PARSE_INT = 48,                 /* PARSE_INT  */
  YYSYMBOL_PARSE_FLOAT = 49,               /* PARSE_FLOAT  */
  YYSYMBOL_PARSE_DOUBLE = 50,              /* PARSE_DOUBLE  */
  YYSYMBOL_PARSE_STRING = 51,              /* PARSE_STRING  */
  YYSYMBOL_JOIN_STRING = 52,               /* JOIN_STRING  */
  YYSYMBOL_ARRAY_INDEX = 53,               /* ARRAY_INDEX  */
  YYSYMBOL_FUNC_LENGTH = 54,               /* FUNC_LENGTH  */
  YYSYMBOL_FUNC_ADD = 55,                  /* FUNC_ADD  */
  YYSYMBOL_MAIN_STRING = 56,               /* MAIN_STRING  */
  YYSYMBOL_INT_NUMBER = 57,                /* INT_NUMBER  */
  YYSYMBOL_FLOAT_NUMBER = 58,              /* FLOAT_NUMBER  */
  YYSYMBOL_IDENTIFICADOR = 59,             /* IDENTIFICADOR  */
  YYSYMBOL_STRING_COMILLAS = 60,           /* STRING_COMILLAS  */
  YYSYMBOL_BOOL_VALUE = 61,                /* BOOL_VALUE  */
  YYSYMBOL_NULL_VALUE = 62,                /* NULL_VALUE  */
  YYSYMBOL_63_ = 63,                       /* '+'  */
  YYSYMBOL_64_ = 64,                       /* '-'  */
  YYSYMBOL_65_ = 65,                       /* '*'  */
  YYSYMBOL_66_ = 66,                       /* '/'  */
  YYSYMBOL_67_ = 67,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 68,                  /* $accept  */
  YYSYMBOL_input = 69,                     /* input  */
  YYSYMBOL_lista_instrucciones = 70,       /* lista_instrucciones  */
  YYSYMBOL_instruccion = 71,               /* instruccion  */
  YYSYMBOL_print = 72,                     /* print  */
  YYSYMBOL_declaration = 73,               /* declaration  */
  YYSYMBOL_parse_expretion = 74,           /* parse_expretion  */
  YYSYMBOL_string_join = 75,               /* string_join  */
  YYSYMBOL_array_funcs = 76,               /* array_funcs  */
  YYSYMBOL_vector = 77,                    /* vector  */
  YYSYMBOL_vector_type = 78,               /* vector_type  */
  YYSYMBOL_vector_values = 79,             /* vector_values  */
  YYSYMBOL_matriz = 80,                    /* matriz  */
  YYSYMBOL_matriz_type = 81,               /* matriz_type  */
  YYSYMBOL_matriz_values = 82,             /* matriz_values  */
  YYSYMBOL_dynamic_array = 83,             /* dynamic_array  */
  YYSYMBOL_dynamic_corchete = 84,          /* dynamic_corchete  */
  YYSYMBOL_dynamic_data_declaration = 85,  /* dynamic_data_declaration  */
  YYSYMBOL_asignation = 86,                /* asignation  */
  YYSYMBOL_expr_bridge = 87,               /* expr_bridge  */
  YYSYMBOL_op_expr = 88,                   /* op_expr  */
  YYSYMBOL_native_func = 89,               /* native_func  */
  YYSYMBOL_variable_access = 90,           /* variable_access  */
  YYSYMBOL_if_sentence = 91,               /* if_sentence  */
  YYSYMBOL_for_sentence = 92,              /* for_sentence  */
  YYSYMBOL_for_condition = 93,             /* for_condition  */
  YYSYMBOL_switch_case = 94,               /* switch_case  */
  YYSYMBOL_switch_case_list = 95,          /* switch_case_list  */
  YYSYMBOL_switch_default = 96,            /* switch_default  */
  YYSYMBOL_while_sentence = 97,            /* while_sentence  */
  YYSYMBOL_function_sentence = 98,         /* function_sentence  */
  YYSYMBOL_parameters_bridge = 99,         /* parameters_bridge  */
  YYSYMBOL_function_parameters = 100,      /* function_parameters  */
  YYSYMBOL_function_expr = 101,            /* function_expr  */
  YYSYMBOL_expr = 102                      /* expr  */
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
#define YYLAST   1009

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  68
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  292

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   317


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
       2,     2,     2,     2,     2,     2,     2,    67,     2,     2,
       2,     2,    65,    63,     2,    64,     2,    66,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    55,    55,    59,    60,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    78,    79,    86,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,   101,   102,   103,
     104,   108,   112,   113,   118,   122,   123,   124,   129,   130,
     135,   140,   141,   146,   147,   152,   156,   157,   161,   162,
     168,   169,   174,   175,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   196,   197,   198,   199,   200,
     201,   202,   203,   208,   209,   214,   215,   220,   225,   226,
     227,   232,   237,   238,   243,   244,   249,   254,   259,   260,
     265,   266,   267,   271,   272,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   293,   294,   295,   296
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
  "\"end of file\"", "error", "\"invalid token\"", "DATA_TYPE",
  "S_PUNTO_COMA", "S_IGUAL", "PARENTESIS_OPEN", "PARENTESIS_CLOSE",
  "S_PUNTO_PUNTO", "SWITCH_WORD", "CASE_WORD", "BREAK_WORD",
  "OP_MAS_IGUAL", "OP_MENOS_IGUAL", "OP_MULTI_IGUAL", "OP_DIV_IGUAL",
  "OP_MOD_IGUAL", "OP_AND_IGUAL", "DEFAULT_WORD", "WHILE_WORD",
  "OP_AUMENTO", "OP_DECREMENTO", "OP_OR_IGUAL", "OP_POT_IGUAL",
  "OP_MAYOR_IGUAL", "OP_MENOR_IGUAL", "OP_IGUAL_IGUAL", "OP_DISTINTO_A",
  "OP_MENOR_IGUAL_A", "OP_MAYOR_IGUAL_A", "LOGIC_OR", "LOGIC_AND",
  "OP_MENOR_A", "OP_MAYOR_A", "LOGIC_NOT", "PRINT_SENTENCE", "FUNC_EQUALS",
  "IF_WORD", "LLAVE_OPEN", "LLAVE_CLOSE", "ELSE_WORD", "FOR_WORD",
  "CONTINUE_WORD", "RETURN_WORD", "CORCHETE_OPEN", "CORCHETE_CLOSE",
  "NEW_WORD", "COMA", "PARSE_INT", "PARSE_FLOAT", "PARSE_DOUBLE",
  "PARSE_STRING", "JOIN_STRING", "ARRAY_INDEX", "FUNC_LENGTH", "FUNC_ADD",
  "MAIN_STRING", "INT_NUMBER", "FLOAT_NUMBER", "IDENTIFICADOR",
  "STRING_COMILLAS", "BOOL_VALUE", "NULL_VALUE", "'+'", "'-'", "'*'",
  "'/'", "'%'", "$accept", "input", "lista_instrucciones", "instruccion",
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

#define YYPACT_NINF (-212)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     621,   -40,     1,    10,    34,    56,    61,    86,    69,   474,
     965,   108,   621,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,    63,  -212,  -212,  -212,  -212,  -212,    65,     7,    53,
    -212,   158,   546,   158,   116,  -212,  -212,   158,   158,  -212,
    -212,  -212,  -212,  -212,  -212,    95,  -212,   109,  -212,  -212,
    -212,  -212,  -212,  -212,   133,   134,  -212,  -212,  -212,  -212,
     114,   158,   363,  -212,  -212,   158,   -39,  -212,   489,   453,
     110,    -2,   150,   239,    68,   174,   254,   281,   -23,   158,
     175,   308,  -212,  -212,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   161,  -212,  -212,
     158,   696,   130,   179,  -212,   887,   103,   139,   180,   459,
    -212,  -212,  -212,  -212,   181,   182,     0,   187,   193,   194,
     197,   113,   127,  -212,   195,   156,  -212,   887,  -212,   159,
     162,   171,   172,   208,   209,   183,    27,   210,   184,  -212,
     167,   167,    84,    84,   909,   929,    84,    84,   106,   106,
    -212,  -212,  -212,  -212,   323,   185,  -212,  -212,   164,    59,
     220,   158,   158,   453,  -212,   158,  -212,  -212,  -212,  -212,
    -212,   190,   468,   241,  -212,   235,   621,  -212,  -212,   621,
     188,   189,   621,  -212,   158,   244,   158,   247,   199,  -212,
     196,   707,   717,     3,   335,   621,  -212,   212,   158,    16,
       6,   555,  -212,    17,   574,   759,   -30,    55,   887,   213,
     246,   256,   158,   158,   258,   274,   609,   158,    14,   403,
     158,   250,   251,  -212,   249,  -212,  -212,  -212,  -212,   253,
     289,  -212,   290,   158,   158,   158,  -212,    48,   350,  -212,
    -212,  -212,   767,  -212,   158,   621,   419,   621,  -212,   255,
     158,    62,   252,  -212,   887,   809,   377,  -212,  -212,  -212,
     817,   662,   621,   621,   621,    64,   291,   259,   158,   294,
     295,  -212,   296,   673,   618,  -212,  -212,   158,   859,  -212,
    -212,    51,   297,  -212,    67,   272,    54,  -212,   158,   867,
     318,  -212
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     4,     7,     5,    19,    20,    21,     6,
       9,     0,     8,    12,    10,    11,    13,     0,     0,     0,
      69,     0,     0,     0,     0,    68,    70,     0,     0,   101,
     102,   106,   103,   104,   105,     0,    54,     0,    55,    56,
      57,    58,    59,    60,     0,     0,    61,    62,    63,    64,
       0,     0,     0,     1,     3,     0,     0,    16,     0,    89,
       0,     0,     0,     0,   106,     0,     0,     0,     0,     0,
       0,     0,   115,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,    67,
       0,     0,   106,     0,    53,    52,     0,     0,     0,     0,
      27,    29,    28,    30,     0,     0,   106,     0,     0,     0,
       0,     0,     0,    92,     0,    88,    91,    93,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     111,   112,   109,   110,   114,   113,   107,   108,    95,    96,
      97,    98,    99,    72,     0,    73,    50,    51,     0,     0,
       0,     0,     0,     0,    33,     0,    25,    26,    22,    17,
      94,     0,     0,     0,    46,     0,     0,    15,    14,     0,
       0,     0,     0,    65,     0,     0,     0,     0,     0,    34,
       0,     0,     0,     0,     0,     0,    90,     0,     0,    85,
       0,     0,    80,     0,     0,     0,     0,     0,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    75,    78,    79,    77,    74,     0,
       0,    40,     0,     0,     0,     0,    18,     0,     0,    23,
      24,    87,     0,    45,     0,     0,     0,     0,    81,     0,
       0,     0,     0,    36,    38,     0,     0,    31,    32,    49,
       0,     0,     0,    84,     0,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,    44,    42,     0,     0,    35,
      37,    69,     0,    76,     0,     0,    69,    43,     0,     0,
       0,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -212,  -212,  -149,   -10,  -212,   292,  -212,  -212,  -212,  -212,
    -212,  -211,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,   293,    -5,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,   160,   152,    -9
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,   117,   118,   119,    16,
     189,   207,    17,   231,   251,    18,    71,   218,    19,   103,
      62,    20,    21,    22,    23,    80,    24,   199,   222,    25,
      26,   124,   125,   126,   208
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,   237,    64,   129,    27,   107,   163,    29,   229,     1,
     214,    67,    68,    69,    30,     2,   230,     3,   243,    28,
     108,    27,    73,    76,    77,     4,   220,   200,    81,    82,
     201,    67,    68,   204,   221,   180,   136,   225,   226,   265,
      31,     5,   130,     6,    61,   223,   216,     7,     8,     9,
     172,    70,   101,   105,   164,   257,   106,   104,   244,   121,
     127,   -83,    32,   120,   -82,    10,   284,    33,    65,   -83,
     137,    70,   -82,    35,    47,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    54,    55,
     -83,   154,    34,   -82,   232,   233,   261,   186,   263,    83,
      81,   266,   233,   275,    60,   187,   287,   157,    63,   267,
      66,   233,    72,   273,   233,   274,    97,   169,   188,    78,
     100,    84,    85,    86,    87,    88,    89,    90,    91,    84,
      85,    86,    87,    88,    89,    90,    91,    98,    99,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,   191,   192,   127,   128,   194,   131,    92,    93,
      94,    95,    96,   127,    37,   153,    92,    93,    94,    95,
      96,    94,    95,    96,    61,   205,    92,    93,    94,    95,
      96,   133,   138,   156,   158,   159,   170,   161,   162,   219,
      64,    64,    38,   165,    64,    86,    87,   166,   167,    90,
      91,   168,   171,   172,   238,   173,    64,   174,   242,   175,
     176,   246,   177,   178,   181,    39,    40,    41,    42,    43,
      44,   179,   182,   185,   254,   255,   256,   190,   195,   184,
      92,    93,    94,    95,    96,   260,    84,    85,    86,    87,
      88,    89,    90,    91,   197,   198,   132,   202,   203,   206,
     209,    64,   235,    64,   210,   211,   217,   234,   247,   278,
     236,   134,   239,    64,    64,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,   240,   289,
      84,    85,    86,    87,    88,    89,    90,    91,   135,   249,
     248,   250,   252,   264,   253,   276,   268,   277,   279,   280,
     281,   286,    92,    93,    94,    95,    96,    84,    85,    86,
      87,    88,    89,    90,    91,   139,   288,    92,    93,    94,
      95,    96,   291,   193,   196,    75,    79,     0,     0,     0,
     183,     0,     0,     0,    84,    85,    86,    87,    88,    89,
      90,    91,   215,     0,    92,    93,    94,    95,    96,    84,
      85,    86,    87,    88,    89,    90,    91,   258,     0,     0,
       0,    84,    85,    86,    87,    88,    89,    90,    91,    37,
       0,    92,    93,    94,    95,    96,    84,    85,    86,    87,
      88,    89,    90,    91,   270,     0,    92,    93,    94,    95,
      96,     0,     0,     0,     0,     0,     0,    38,    92,    93,
      94,    95,    96,    84,    85,    86,    87,    88,    89,    90,
      91,   245,     0,    92,    93,    94,    95,    96,     0,     0,
      39,    40,   102,    42,    43,    44,     0,   262,     0,    84,
      85,    86,    87,    88,    89,    90,    91,     0,     0,     0,
      92,    93,    94,    95,    96,    84,    85,    86,    87,    88,
      89,    90,    91,     0,     0,     0,   122,     0,     0,    37,
       0,     0,   160,     0,     0,    37,    92,    93,    94,    95,
      96,   122,     0,     0,    37,     0,     0,     0,    36,     0,
      37,     0,    92,    93,    94,    95,    96,    38,     0,     0,
       0,     0,     0,    38,     0,   109,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,    38,   123,
      39,    40,    41,    42,    43,    44,    39,    40,    41,    42,
      43,    44,     0,    38,     0,    39,    40,    41,    42,    43,
      44,    39,    40,    41,    42,    43,    44,   110,   111,   112,
     113,   114,   115,     0,     0,     0,    39,    40,   116,    42,
      43,    44,    37,     0,     0,     0,     0,     3,     1,     0,
       0,     0,     0,     0,     2,     0,     3,     0,     0,     0,
       0,     0,     0,     0,     4,     0,     0,     1,     0,     0,
      38,     0,     0,     2,     0,     3,     0,     0,     8,     9,
       5,     0,     6,     4,   224,     0,     7,     8,     9,     0,
       0,     0,     0,    39,    40,    74,    42,    43,    44,     5,
       0,     6,     1,   227,    10,     7,     8,     9,     2,     0,
       3,     1,     0,     0,     1,     0,     0,     2,     4,     3,
       2,     0,     3,    10,     0,     0,     0,     4,     0,     0,
       4,     0,     0,     0,     5,     0,     6,     0,   241,     0,
       7,     8,     9,     5,     0,     6,     5,   283,     6,     7,
       8,     9,     7,     8,     9,     1,     0,     0,    10,     0,
       0,     2,     0,   272,     0,     0,     1,    10,     0,     0,
      10,     4,     2,     0,   282,     0,     0,     0,     0,     0,
       0,     0,     4,     0,     0,     0,     0,     5,     0,     6,
       0,     0,     0,     7,     8,     9,     0,     0,     5,     0,
       6,     0,     0,     0,     7,     8,     9,     0,     0,     0,
       0,    10,    84,    85,    86,    87,    88,    89,    90,    91,
       0,     0,    10,    84,    85,    86,    87,    88,    89,    90,
      91,   155,     0,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,   212,     0,     0,     0,     0,    92,
      93,    94,    95,    96,   213,     0,     0,     0,     0,     0,
      92,    93,    94,    95,    96,     0,     0,     0,     0,     0,
      92,    93,    94,    95,    96,    84,    85,    86,    87,    88,
      89,    90,    91,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,   228,     0,     0,     0,     0,     0,
       0,     0,   259,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    94,    95,    96,     0,     0,     0,
      92,    93,    94,    95,    96,    84,    85,    86,    87,    88,
      89,    90,    91,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,   269,     0,     0,     0,     0,     0,
       0,     0,   271,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    92,    93,    94,    95,    96,     0,     0,     0,
      92,    93,    94,    95,    96,    84,    85,    86,    87,    88,
      89,    90,    91,    84,    85,    86,    87,    88,    89,    90,
      91,     0,     0,     0,   285,     0,     0,     0,     0,     0,
       0,     0,   290,    84,    85,    86,    87,    88,    89,    90,
      91,     0,    92,    93,    94,    95,    96,     0,     0,     0,
      92,    93,    94,    95,    96,    84,    85,    86,    87,     0,
      89,    90,    91,     0,     0,     0,     0,     0,     0,     0,
      92,    93,    94,    95,    96,    84,    85,    86,    87,     0,
       0,    90,    91,     0,     0,     0,     0,     0,     0,     0,
      46,    47,    92,    93,    94,    95,    96,    48,    49,    50,
      51,    52,    53,     0,     0,    54,    55,    56,    57,    58,
      59,     0,    92,    93,    94,    95,    96,     0,     0,     0,
       0,    60,     0,     0,     0,     0,     0,     0,     0,    61
};

static const yytype_int16 yycheck[] =
{
       9,   212,    12,     5,    44,    44,     6,     6,    38,     3,
       7,     4,     5,     6,     4,     9,    46,    11,     4,    59,
      59,    44,    31,    32,    33,    19,    10,   176,    37,    38,
     179,     4,     5,   182,    18,     8,    59,    20,    21,   250,
       6,    35,    44,    37,    44,    39,   195,    41,    42,    43,
      47,    44,    61,    62,    54,     7,    65,    62,    44,    68,
      69,    10,     6,    68,    10,    59,   277,     6,     5,    18,
      79,    44,    18,     4,     6,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    20,    21,
      39,   100,     6,    39,    39,    47,   245,    38,   247,     4,
     109,    39,    47,    39,    36,    46,    39,     4,     0,    47,
      45,    47,    59,   262,    47,   264,     7,     4,    59,     3,
       6,    26,    27,    28,    29,    30,    31,    32,    33,    26,
      27,    28,    29,    30,    31,    32,    33,     4,     4,    26,
      27,    28,    29,    30,    31,    32,    33,    63,    64,    65,
      66,    67,   161,   162,   163,    45,   165,     7,    63,    64,
      65,    66,    67,   172,     6,     4,    63,    64,    65,    66,
      67,    65,    66,    67,    44,   184,    63,    64,    65,    66,
      67,     7,     7,     4,    45,     5,    59,     6,     6,   198,
     200,   201,    34,     6,   204,    28,    29,     4,     4,    32,
      33,     4,     7,    47,   213,    46,   216,    45,   217,    38,
      38,   220,     4,     4,     4,    57,    58,    59,    60,    61,
      62,    38,    38,    59,   233,   234,   235,     7,    38,    44,
      63,    64,    65,    66,    67,   244,    26,    27,    28,    29,
      30,    31,    32,    33,     3,    10,     7,    59,    59,     5,
       3,   261,     6,   263,    55,    59,    44,    44,     8,   268,
       4,     7,     4,   273,   274,    26,    27,    28,    29,    30,
      31,    32,    33,    63,    64,    65,    66,    67,     4,   288,
      26,    27,    28,    29,    30,    31,    32,    33,     7,    40,
      39,    38,     3,    38,     4,     4,    44,    38,     4,     4,
       4,     4,    63,    64,    65,    66,    67,    26,    27,    28,
      29,    30,    31,    32,    33,     7,    44,    63,    64,    65,
      66,    67,     4,   163,   172,    32,    34,    -1,    -1,    -1,
       7,    -1,    -1,    -1,    26,    27,    28,    29,    30,    31,
      32,    33,     7,    -1,    63,    64,    65,    66,    67,    26,
      27,    28,    29,    30,    31,    32,    33,     7,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,     6,
      -1,    63,    64,    65,    66,    67,    26,    27,    28,    29,
      30,    31,    32,    33,     7,    -1,    63,    64,    65,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    34,    63,    64,
      65,    66,    67,    26,    27,    28,    29,    30,    31,    32,
      33,     8,    -1,    63,    64,    65,    66,    67,    -1,    -1,
      57,    58,    59,    60,    61,    62,    -1,     8,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    26,    27,    28,    29,    30,
      31,    32,    33,    -1,    -1,    -1,     3,    -1,    -1,     6,
      -1,    -1,     3,    -1,    -1,     6,    63,    64,    65,    66,
      67,     3,    -1,    -1,     6,    -1,    -1,    -1,     4,    -1,
       6,    -1,    63,    64,    65,    66,    67,    34,    -1,    -1,
      -1,    -1,    -1,    34,    -1,     6,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    -1,    -1,    -1,    -1,    34,    56,
      57,    58,    59,    60,    61,    62,    57,    58,    59,    60,
      61,    62,    -1,    34,    -1,    57,    58,    59,    60,    61,
      62,    57,    58,    59,    60,    61,    62,    48,    49,    50,
      51,    52,    53,    -1,    -1,    -1,    57,    58,    59,    60,
      61,    62,     6,    -1,    -1,    -1,    -1,    11,     3,    -1,
      -1,    -1,    -1,    -1,     9,    -1,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    -1,     3,    -1,    -1,
      34,    -1,    -1,     9,    -1,    11,    -1,    -1,    42,    43,
      35,    -1,    37,    19,    39,    -1,    41,    42,    43,    -1,
      -1,    -1,    -1,    57,    58,    59,    60,    61,    62,    35,
      -1,    37,     3,    39,    59,    41,    42,    43,     9,    -1,
      11,     3,    -1,    -1,     3,    -1,    -1,     9,    19,    11,
       9,    -1,    11,    59,    -1,    -1,    -1,    19,    -1,    -1,
      19,    -1,    -1,    -1,    35,    -1,    37,    -1,    39,    -1,
      41,    42,    43,    35,    -1,    37,    35,    39,    37,    41,
      42,    43,    41,    42,    43,     3,    -1,    -1,    59,    -1,
      -1,     9,    -1,    11,    -1,    -1,     3,    59,    -1,    -1,
      59,    19,     9,    -1,    11,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    35,    -1,    37,
      -1,    -1,    -1,    41,    42,    43,    -1,    -1,    35,    -1,
      37,    -1,    -1,    -1,    41,    42,    43,    -1,    -1,    -1,
      -1,    59,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    59,    26,    27,    28,    29,    30,    31,    32,
      33,    45,    -1,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    47,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    26,    27,    28,    29,    30,
      31,    32,    33,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    26,    27,    28,    29,    30,
      31,    32,    33,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    26,    27,    28,    29,    30,
      31,    32,    33,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    45,    26,    27,    28,    29,    30,    31,    32,
      33,    -1,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    26,    27,    28,    29,    -1,
      31,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      63,    64,    65,    66,    67,    26,    27,    28,    29,    -1,
      -1,    32,    33,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       5,     6,    63,    64,    65,    66,    67,    12,    13,    14,
      15,    16,    17,    -1,    -1,    20,    21,    22,    23,    24,
      25,    -1,    63,    64,    65,    66,    67,    -1,    -1,    -1,
      -1,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     9,    11,    19,    35,    37,    41,    42,    43,
      59,    69,    70,    71,    72,    73,    77,    80,    83,    86,
      89,    90,    91,    92,    94,    97,    98,    44,    59,     6,
       4,     6,     6,     6,     6,     4,     4,     6,    34,    57,
      58,    59,    60,    61,    62,   102,     5,     6,    12,    13,
      14,    15,    16,    17,    20,    21,    22,    23,    24,    25,
      36,    44,    88,     0,    71,     5,    45,     4,     5,     6,
      44,    84,    59,   102,    59,    89,   102,   102,     3,    73,
      93,   102,   102,     4,    26,    27,    28,    29,    30,    31,
      32,    33,    63,    64,    65,    66,    67,     7,     4,     4,
       6,   102,    59,    87,    90,   102,   102,    44,    59,     6,
      48,    49,    50,    51,    52,    53,    59,    74,    75,    76,
      90,   102,     3,    56,    99,   100,   101,   102,    45,     5,
      44,     7,     7,     7,     7,     7,    59,   102,     7,     7,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,     4,   102,    45,     4,     4,    45,     5,
       3,     6,     6,     6,    54,     6,     4,     4,     4,     4,
      59,     7,    47,    46,    45,    38,    38,     4,     4,    38,
       8,     4,    38,     7,    44,    59,    38,    46,    59,    78,
       7,   102,   102,   100,   102,    38,   101,     3,    10,    95,
      70,    70,    59,    59,    70,   102,     5,    79,   102,     3,
      55,    59,    47,    47,     7,     7,    70,    44,    85,   102,
      10,    18,    96,    39,    39,    20,    21,    39,    45,    38,
      46,    81,    39,    47,    44,     6,     4,    79,   102,     4,
       4,    39,   102,     4,    44,     8,   102,     8,    39,    40,
      38,    82,     3,     4,   102,   102,   102,     7,     7,    45,
     102,    70,     8,    70,    38,    79,    39,    47,    44,    45,
       7,    45,    11,    70,    70,    39,     4,    38,   102,     4,
       4,     4,    11,    39,    79,    45,     4,    39,    44,   102,
      45,     4
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    68,    69,    70,    70,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    72,    72,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    74,    74,    74,
      74,    75,    76,    76,    77,    78,    78,    78,    79,    79,
      80,    81,    81,    82,    82,    83,    84,    84,    85,    85,
      86,    86,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    89,    89,    89,    89,
      89,    89,    89,    90,    90,    91,    91,    92,    93,    93,
      93,    94,    95,    95,    96,    96,    97,    98,    99,    99,
     100,   100,   100,   101,   101,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102
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
       3,     1,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     2
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
#line 55 "parser.y"
                                                    { yylineno = 1; }
#line 1510 "parser.tab.c"
    break;

  case 16: /* declaration: DATA_TYPE IDENTIFICADOR S_PUNTO_COMA  */
#line 87 "parser.y"
            { /* VARIABLE SIN VALOR*/ }
#line 1516 "parser.tab.c"
    break;

  case 17: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL expr S_PUNTO_COMA  */
#line 88 "parser.y"
                                                                             { /* VARIABLE CON VALOR O SI EXPR ES IDENTIFICADOR ES EL CASTEO WIDENING */ }
#line 1522 "parser.tab.c"
    break;

  case 18: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL PARENTESIS_OPEN DATA_TYPE PARENTESIS_CLOSE IDENTIFICADOR S_PUNTO_COMA  */
#line 89 "parser.y"
                                                                                                                    { /* CASTEO NARROWING*/ }
#line 1528 "parser.tab.c"
    break;

  case 35: /* vector_type: NEW_WORD DATA_TYPE CORCHETE_OPEN expr CORCHETE_CLOSE S_PUNTO_COMA  */
#line 122 "parser.y"
                                                                              { /* VECTOR AUTO */ }
#line 1534 "parser.tab.c"
    break;

  case 36: /* vector_type: LLAVE_OPEN vector_values LLAVE_CLOSE S_PUNTO_COMA  */
#line 123 "parser.y"
                                                                        { /* VECTOR CON VALORES */ }
#line 1540 "parser.tab.c"
    break;

  case 37: /* vector_type: IDENTIFICADOR FUNC_ADD PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 124 "parser.y"
                                                                                        { /* FUNCION ADD EN VECTORES*/}
#line 1546 "parser.tab.c"
    break;

  case 50: /* asignation: IDENTIFICADOR op_expr expr_bridge S_PUNTO_COMA  */
#line 168 "parser.y"
                                                                       { /* 'OPERADOR ASIGNACION' PARA UNA VARIABLE Y ASIGNACION NORMAL*/ }
#line 1552 "parser.tab.c"
    break;

  case 51: /* asignation: variable_access S_IGUAL expr S_PUNTO_COMA  */
#line 169 "parser.y"
                                                                       { /* ASIGNACION DE UN VALOR VECTOR, MATRIZ*/}
#line 1558 "parser.tab.c"
    break;

  case 65: /* native_func: IDENTIFICADOR FUNC_EQUALS PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 196 "parser.y"
                                                                                       {/* PRINT FUNC .EQUALS PARA UNA VARIABLE */}
#line 1564 "parser.tab.c"
    break;

  case 66: /* native_func: IDENTIFICADOR OP_AUMENTO S_PUNTO_COMA  */
#line 197 "parser.y"
                                                                                                {/* AUMENTADOR DE VARIABLE PARA BUCLES*/}
#line 1570 "parser.tab.c"
    break;

  case 67: /* native_func: IDENTIFICADOR OP_DECREMENTO S_PUNTO_COMA  */
#line 198 "parser.y"
                                                                                                {/* REDUCTOR DE VARIABLE PARA BUCLES*/}
#line 1576 "parser.tab.c"
    break;

  case 73: /* variable_access: IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE  */
#line 208 "parser.y"
                                                                                {/* ACCESO A VALOR EN UN VECTOR*/}
#line 1582 "parser.tab.c"
    break;

  case 74: /* variable_access: IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE CORCHETE_OPEN expr CORCHETE_CLOSE  */
#line 209 "parser.y"
                                                                                                        {/* ACCESO A VALOR EN UNA MATRIZ */}
#line 1588 "parser.tab.c"
    break;

  case 78: /* for_condition: declaration expr S_PUNTO_COMA IDENTIFICADOR OP_AUMENTO  */
#line 225 "parser.y"
                                                                                                  {/* ESTRUCTURA FOR NORMAL */}
#line 1594 "parser.tab.c"
    break;

  case 79: /* for_condition: declaration expr S_PUNTO_COMA IDENTIFICADOR OP_DECREMENTO  */
#line 226 "parser.y"
                                                                                                  {/* ESTRUCTURA FOR NORMAL */}
#line 1600 "parser.tab.c"
    break;

  case 80: /* for_condition: DATA_TYPE IDENTIFICADOR S_PUNTO_PUNTO IDENTIFICADOR  */
#line 227 "parser.y"
                                                                                                  {/* ESTRUCTURA FOR EACH */}
#line 1606 "parser.tab.c"
    break;

  case 89: /* parameters_bridge: %empty  */
#line 260 "parser.y"
                      {/* vaćio */}
#line 1612 "parser.tab.c"
    break;


#line 1616 "parser.tab.c"

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

#line 299 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error: sintáctico en linea: %d\n", yylineno);
}
