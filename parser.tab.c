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
  YYSYMBOL_if_sentence = 93,               /* if_sentence  */
  YYSYMBOL_if_else_one = 94,               /* if_else_one  */
  YYSYMBOL_if_else_chain = 95,             /* if_else_chain  */
  YYSYMBOL_for_sentence = 96,              /* for_sentence  */
  YYSYMBOL_for_condition = 97,             /* for_condition  */
  YYSYMBOL_for_option = 98,                /* for_option  */
  YYSYMBOL_switch_case = 99,               /* switch_case  */
  YYSYMBOL_switch_case_one = 100,          /* switch_case_one  */
  YYSYMBOL_switch_case_list = 101,         /* switch_case_list  */
  YYSYMBOL_switch_default = 102,           /* switch_default  */
  YYSYMBOL_while_sentence = 103,           /* while_sentence  */
  YYSYMBOL_function_sentence = 104,        /* function_sentence  */
  YYSYMBOL_parameters_bridge = 105,        /* parameters_bridge  */
  YYSYMBOL_function_parameters_declaration = 106, /* function_parameters_declaration  */
  YYSYMBOL_function_parameters_access = 107, /* function_parameters_access  */
  YYSYMBOL_expr = 108                      /* expr  */
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
#define YYFINAL  65
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1013

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  70
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  328

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
     106,   108,   110,   113,   116,   118,   121,   126,   127,   128,
     129,   133,   147,   150,   156,   161,   164,   167,   173,   175,
     181,   187,   190,   196,   198,   204,   208,   209,   213,   214,
     220,   223,   226,   238,   239,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   260,   263,   266,   269,
     272,   275,   281,   284,   290,   293,   296,   301,   306,   326,
     335,   341,   343,   348,   349,   353,   359,   365,   386,   395,
     399,   404,   410,   416,   419,   422,   431,   440,   454,   463,
     477,   486,   487,   488,   489,   490,   491,   492,   493,   494,
     495,   496,   497,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   511
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

#define YYPACT_NINF (-233)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-88)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,    12,    18,    39,    58,    65,    68,    96,   376,   148,
     -14,   117,     6,  -233,  -233,  -233,  -233,  -233,  -233,  -233,
    -233,  -233,    64,  -233,  -233,  -233,  -233,  -233,    79,  -233,
     578,   559,   578,    80,  -233,  -233,   578,   578,  -233,   578,
     136,   154,  -233,  -233,   160,   456,     3,  -233,  -233,   578,
    -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,
    -233,   580,   147,   164,    44,  -233,  -233,   578,   172,   613,
      99,   195,   634,   641,     8,   578,   196,   677,  -233,  -233,
    -233,   211,   212,  -233,   578,   578,   578,   578,   578,   578,
     578,   578,   578,   578,   578,   578,   578,  -233,   162,   213,
     194,   197,   536,   864,    -4,   218,  -233,   536,  -233,    11,
    -233,     3,   199,   410,   -19,   480,   207,   208,   223,   227,
     216,    53,   501,   222,  -233,   578,   578,   159,   159,   153,
     153,  -233,  -233,  -233,   159,   159,   463,   463,   961,   954,
    -233,   234,   176,   578,   224,  -233,   225,   190,   243,  -233,
      60,   246,   249,  -233,  -233,  -233,  -233,   101,   253,   255,
     257,   508,   238,   200,  -233,   256,     6,  -233,  -233,     6,
     214,   434,   215,     6,   684,   705,  -233,   217,   536,   578,
     219,    -3,   259,   273,   237,   226,   561,  -233,   578,  -233,
    -233,  -233,  -233,   221,   578,  -233,   119,   135,  -233,   150,
     110,   220,  -233,  -233,  -233,   871,   229,   578,   251,   228,
    -233,     6,   231,   264,   266,   279,    69,   727,   270,   833,
      88,  -233,   277,   301,  -233,  -233,  -233,   -11,   -13,   536,
     304,   286,   245,   312,   578,   578,  -233,   314,   316,   578,
      72,     6,   578,   318,   292,   142,  -233,   303,   268,  -233,
     319,   578,   578,   293,  -233,  -233,    85,   748,  -233,  -233,
     895,  -233,   578,   361,   840,     6,  -233,   327,     6,   317,
     578,   107,   310,  -233,   536,   755,   322,   337,  -233,  -233,
     902,   339,     6,     6,   578,   283,   166,   113,   344,   331,
     578,   346,   348,  -233,  -233,     0,   377,   791,  -233,   349,
       6,  -233,  -233,   578,   926,  -233,  -233,   352,   340,   578,
     307,   145,   335,   158,     6,   798,  -233,  -233,   578,   323,
     343,   933,  -233,     6,   366,   345,  -233,  -233
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     2,     4,     7,     5,    24,    19,    20,    21,
       6,     9,     0,     8,    12,    10,    11,    13,     0,    68,
       0,     0,     0,     0,    67,    69,     0,     0,   107,     0,
     110,   111,   112,   113,   114,     0,    96,    83,    84,     0,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,     0,     0,     0,     0,     1,     3,     0,     0,     0,
     114,     0,     0,     0,     0,     0,     0,     0,   123,   108,
     109,     0,     0,    70,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    95,     0,     0,
      93,    94,   100,     0,   114,     0,    54,    53,    66,     0,
      16,    96,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,     0,     0,   115,   116,   101,
     102,   104,   103,   105,   117,   118,   119,   120,   121,   122,
      98,     0,     0,     0,    72,    50,     0,     0,     0,    47,
       0,     0,     0,    27,    29,    28,    30,   114,     0,     0,
       0,     0,     0,     0,    51,     0,     0,    15,    14,     0,
       0,     0,     0,     0,     0,     0,    71,     0,    99,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,    25,
      22,    17,    46,     0,     0,    88,     0,     0,    82,   114,
       0,     0,   125,   124,    97,     0,     0,     0,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      90,    91,    74,     0,    81,    80,    73,     0,     0,    39,
       0,     0,     0,     0,     0,     0,    26,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    79,     0,     0,    40,
       0,     0,     0,     0,    92,    18,     0,     0,    52,    23,
       0,    45,     0,     0,     0,     0,    85,     0,     0,     0,
       0,     0,     0,    36,    38,     0,     0,     0,    32,    49,
       0,     0,     0,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    31,    48,    68,     0,     0,    75,     0,
       0,    44,    42,     0,     0,    37,    35,     0,     0,     0,
       0,     0,     0,    68,     0,     0,    76,    43,     0,     0,
       0,     0,    77,     0,     0,     0,    41,    78
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -233,  -233,  -120,   -12,  -233,   338,  -233,  -233,  -233,  -233,
    -233,  -232,  -233,  -233,  -233,  -233,  -233,  -233,  -233,  -233,
    -233,   333,   -58,  -233,  -233,  -233,  -233,  -233,   173,  -233,
    -233,  -233,  -233,  -233,  -233,   265,  -233,   201,    -7
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,    11,    12,    13,    14,    15,   158,    16,   159,    17,
     210,   228,    18,   249,   271,    19,   114,   240,    20,   105,
      61,    21,    22,    23,   246,   269,    24,    76,    62,    25,
     195,   220,   244,    26,    27,    99,   100,   101,   229
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    45,   256,   106,   162,   250,   247,    36,   -86,    63,
     -86,    82,   251,     1,   207,     2,    28,     3,   -86,    49,
       4,    29,     5,    69,    72,    73,     6,     7,     8,    77,
      78,    63,    79,    97,   146,    37,    38,   163,   287,   102,
      39,    64,   103,    30,    40,    41,   196,   110,   111,   197,
      42,    43,   208,   201,   107,   160,   110,   248,    44,   170,
     115,     9,    31,   121,    36,   209,   147,   112,   122,    32,
      98,   311,    33,    10,   237,   261,   112,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     277,   232,    37,    38,   143,   262,   242,    39,   243,    34,
     113,    40,    41,    46,   102,   186,   161,    42,    43,   171,
     251,    47,    48,   160,    82,    44,    82,    65,   174,   175,
      67,   263,    47,    48,    49,   288,     1,   183,     2,   187,
       3,   301,   289,     4,    68,     5,   178,   221,   251,     6,
       7,     8,     1,    77,     2,   283,     3,    74,   285,     4,
     108,     5,    46,   222,   223,     6,     7,     8,   267,   268,
      47,    48,   296,   317,   161,    82,   -87,    80,   -87,    81,
     251,    49,   205,    49,     9,    82,   -87,   116,   187,   102,
     310,   217,   299,   300,    66,    66,    10,   219,   109,    66,
       9,    88,    89,    90,   319,    86,    87,    88,    89,    90,
     118,   123,    10,   325,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,   125,   126,   140,   141,   142,
      66,   145,   143,   149,   165,   166,   167,     1,   257,     2,
     168,     3,   260,   169,     4,   264,     5,   176,   225,   173,
       6,     7,     8,   177,   274,   275,   181,   179,   182,   180,
     184,    66,     1,   185,     2,   280,     3,   188,   189,     4,
     190,     5,   192,   254,   194,     6,     7,     8,   193,   198,
     200,    66,   204,    66,   206,     9,   211,   297,   212,   213,
     230,   214,   236,   304,    66,   227,   233,    10,   218,   234,
       1,   235,     2,   239,     3,   231,   245,     4,    66,     5,
       9,   298,   315,     6,     7,     8,   215,    66,   252,   253,
     266,   321,    10,    66,     1,   255,     2,   258,     3,   259,
     270,     4,   273,     5,   265,   316,   276,     6,     7,     8,
       1,   284,     2,   290,     3,   272,   286,     4,     9,     5,
     293,   322,   295,     6,     7,     8,   292,   302,   303,   305,
      10,   306,     1,   309,     2,   313,     3,   314,   318,     4,
     323,     5,     9,   327,    71,     6,     7,     8,     1,   326,
     281,    75,     3,   224,    10,     4,   148,     5,     9,    35,
      36,     6,     7,     8,     1,     0,   307,   216,     3,     0,
      10,     4,     0,     5,     0,     0,     0,     6,     7,     8,
       9,     0,     0,     0,     0,     0,     0,     0,    37,    38,
       0,     0,    10,    39,   150,     0,     9,    40,    41,     0,
       0,     0,     0,    42,    43,     0,     0,     0,    10,     0,
       0,    44,     9,     0,     0,     0,   151,   152,   150,     0,
       0,     0,    37,    38,    10,     0,     0,    39,     0,     0,
       0,    40,    41,   153,   154,   155,   156,    42,    43,    83,
     151,   152,     0,     0,     0,   157,    37,    38,     0,     0,
       0,    39,     0,     0,     0,    40,    41,   153,   154,   155,
     156,    42,    43,   164,     0,     0,     0,     0,     0,   199,
      84,    85,    86,    87,    88,    89,    90,    84,    85,    86,
      87,    88,    89,    90,   172,    91,    92,    93,    94,    95,
      96,   191,    91,    92,    84,    85,    86,    87,    88,    89,
      90,     0,     0,     0,     0,     0,     0,     0,     0,    91,
      92,    93,    94,    95,    96,    84,    85,    86,    87,    88,
      89,    90,    84,    85,    86,    87,    88,    89,    90,     0,
      91,    92,    93,    94,    95,    96,     0,    91,    92,    93,
      94,    95,    96,    36,     0,    36,   215,     0,     2,     0,
      84,    85,    86,    87,    88,    89,    90,     0,     0,     0,
       7,     8,    36,     0,    36,    91,    92,    93,    94,    95,
      96,    37,    38,    37,    38,     0,    39,     0,    39,     0,
      40,    41,    40,    41,     0,     0,    42,    43,    42,    43,
      37,    38,    37,    38,    70,    39,    44,    39,   117,    40,
      41,    40,    41,     0,     0,    42,    43,    42,    43,     0,
       0,     0,     0,    44,     0,   104,     0,     0,     0,   119,
       0,     0,     0,     0,     0,     0,   120,    84,    85,    86,
      87,    88,    89,    90,     0,     0,     0,     0,     0,     0,
       0,     0,    91,    92,    93,    94,    95,    96,    84,    85,
      86,    87,    88,    89,    90,    84,    85,    86,    87,    88,
      89,    90,   124,    91,    92,    93,    94,    95,    96,   202,
      91,    92,    93,    94,    95,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     203,    84,    85,    86,    87,    88,    89,    90,    84,    85,
      86,    87,    88,    89,    90,     0,    91,    92,    93,    94,
      95,    96,   238,    91,    92,    93,    94,    95,    96,    84,
      85,    86,    87,    88,    89,    90,     0,     0,     0,     0,
       0,     0,     0,   278,    91,    92,    93,    94,    95,    96,
     291,    84,    85,    86,    87,    88,    89,    90,     0,     0,
       0,     0,     0,     0,     0,     0,    91,    92,    93,    94,
      95,    96,    84,    85,    86,    87,    88,    89,    90,    84,
      85,    86,    87,    88,    89,    90,   308,    91,    92,    93,
      94,    95,    96,   320,    91,    92,    93,    94,    95,    96,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    84,    85,    86,    87,    88,
      89,    90,    84,    85,    86,    87,    88,    89,    90,   241,
      91,    92,    93,    94,    95,    96,   282,    91,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    84,    85,    86,
      87,    88,    89,    90,    84,    85,    86,    87,    88,    89,
      90,     0,    91,    92,    93,    94,    95,    96,   144,    91,
      92,    93,    94,    95,    96,   226,     0,     0,    84,    85,
      86,    87,    88,    89,    90,    84,    85,    86,    87,    88,
      89,    90,     0,    91,    92,    93,    94,    95,    96,   279,
      91,    92,    93,    94,    95,    96,   294,     0,     0,    84,
      85,    86,    87,    88,    89,    90,    84,    85,    86,    87,
      88,    89,    90,     0,    91,    92,    93,    94,    95,    96,
     312,    91,    92,    93,    94,    95,    96,   324,     0,     0,
      84,    85,    86,    87,    88,    89,    90,    84,    85,    86,
      87,    88,    89,    90,     0,    91,    92,    93,    94,    95,
      96,     0,    91,    92,    93,    94,    95,    96,    84,    85,
      86,    87,    88,    89,    90,    84,    85,    86,    87,    88,
      89,    90,     0,    91,    92,    93,    94,    95,     0,     0,
      91,    92,    93,    94
};

static const yytype_int16 yycheck[] =
{
      12,     8,   234,    61,    23,    18,    17,     4,     8,    23,
      10,    15,    25,     7,    17,     9,     4,    11,    18,    23,
      14,     3,    16,    30,    31,    32,    20,    21,    22,    36,
      37,    23,    39,    30,    23,    32,    33,    56,   270,    46,
      37,    55,    49,     4,    41,    42,   166,     3,     4,   169,
      47,    48,    55,   173,    61,   113,     3,    68,    55,     6,
      67,    55,     4,    55,     4,    68,    55,    23,    75,     4,
      67,   303,     4,    67,     5,     3,    23,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
       5,   211,    32,    33,    25,    23,     8,    37,    10,     3,
      56,    41,    42,     4,   111,     4,   113,    47,    48,    56,
      25,    12,    13,   171,    15,    55,    15,     0,   125,   126,
      56,   241,    12,    13,    23,    18,     7,    67,     9,    28,
      11,    18,    25,    14,    55,    16,   143,    18,    25,    20,
      21,    22,     7,   150,     9,   265,    11,    67,   268,    14,
       3,    16,     4,    18,     4,    20,    21,    22,    16,    17,
      12,    13,   282,    18,   171,    15,     8,    31,    10,    15,
      25,    23,   179,    23,    55,    15,    18,     5,    28,   186,
     300,   188,    16,    17,   196,   197,    67,   194,    24,   201,
      55,    38,    39,    40,   314,    36,    37,    38,    39,    40,
       5,     5,    67,   323,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,     4,     4,    55,     5,    25,
     232,     3,    25,    24,    17,    17,     3,     7,   235,     9,
       3,    11,   239,    17,    14,   242,    16,     3,    18,    17,
      20,    21,    22,    67,   251,   252,    56,    23,     5,    24,
       4,   263,     7,     4,     9,   262,    11,     4,     3,    14,
       3,    16,    24,    18,     8,    20,    21,    22,    68,    55,
      55,   283,    55,   285,    55,    55,    17,   284,     5,    42,
      29,    55,     3,   290,   296,    56,    55,    67,    67,    25,
       7,    25,     9,    23,    11,    67,    19,    14,   310,    16,
      55,    18,   309,    20,    21,    22,     5,   319,     4,    23,
      18,   318,    67,   325,     7,     3,     9,     3,    11,     3,
      17,    14,     3,    16,     6,    18,    33,    20,    21,    22,
       7,     4,     9,    23,    11,    67,    19,    14,    55,    16,
       3,    18,     3,    20,    21,    22,    24,     3,    17,     3,
      67,     3,     7,     4,     9,     3,    11,    17,    23,    14,
      17,    16,    55,    18,    31,    20,    21,    22,     7,     3,
       9,    33,    11,   200,    67,    14,   111,    16,    55,     3,
       4,    20,    21,    22,     7,    -1,     9,   186,    11,    -1,
      67,    14,    -1,    16,    -1,    -1,    -1,    20,    21,    22,
      55,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    33,
      -1,    -1,    67,    37,     4,    -1,    55,    41,    42,    -1,
      -1,    -1,    -1,    47,    48,    -1,    -1,    -1,    67,    -1,
      -1,    55,    55,    -1,    -1,    -1,    26,    27,     4,    -1,
      -1,    -1,    32,    33,    67,    -1,    -1,    37,    -1,    -1,
      -1,    41,    42,    43,    44,    45,    46,    47,    48,     3,
      26,    27,    -1,    -1,    -1,    55,    32,    33,    -1,    -1,
      -1,    37,    -1,    -1,    -1,    41,    42,    43,    44,    45,
      46,    47,    48,     3,    -1,    -1,    -1,    -1,    -1,    55,
      34,    35,    36,    37,    38,    39,    40,    34,    35,    36,
      37,    38,    39,    40,     3,    49,    50,    51,    52,    53,
      54,     3,    49,    50,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,
      50,    51,    52,    53,    54,    34,    35,    36,    37,    38,
      39,    40,    34,    35,    36,    37,    38,    39,    40,    -1,
      49,    50,    51,    52,    53,    54,    -1,    49,    50,    51,
      52,    53,    54,     4,    -1,     4,     5,    -1,     9,    -1,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      21,    22,     4,    -1,     4,    49,    50,    51,    52,    53,
      54,    32,    33,    32,    33,    -1,    37,    -1,    37,    -1,
      41,    42,    41,    42,    -1,    -1,    47,    48,    47,    48,
      32,    33,    32,    33,    55,    37,    55,    37,     5,    41,
      42,    41,    42,    -1,    -1,    47,    48,    47,    48,    -1,
      -1,    -1,    -1,    55,    -1,    55,    -1,    -1,    -1,     5,
      -1,    -1,    -1,    -1,    -1,    -1,     5,    34,    35,    36,
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
      52,    53,    54,     5,    49,    50,    51,    52,    53,    54,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    34,    35,    36,    37,    38,    39,    40,     6,
      49,    50,    51,    52,    53,    54,     6,    49,    50,    51,
      52,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    34,    35,    36,    37,    38,    39,
      40,    -1,    49,    50,    51,    52,    53,    54,    24,    49,
      50,    51,    52,    53,    54,    24,    -1,    -1,    34,    35,
      36,    37,    38,    39,    40,    34,    35,    36,    37,    38,
      39,    40,    -1,    49,    50,    51,    52,    53,    54,    24,
      49,    50,    51,    52,    53,    54,    24,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    34,    35,    36,    37,
      38,    39,    40,    -1,    49,    50,    51,    52,    53,    54,
      24,    49,    50,    51,    52,    53,    54,    24,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    34,    35,    36,
      37,    38,    39,    40,    -1,    49,    50,    51,    52,    53,
      54,    -1,    49,    50,    51,    52,    53,    54,    34,    35,
      36,    37,    38,    39,    40,    34,    35,    36,    37,    38,
      39,    40,    -1,    49,    50,    51,    52,    53,    -1,    -1,
      49,    50,    51,    52
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     9,    11,    14,    16,    20,    21,    22,    55,
      67,    71,    72,    73,    74,    75,    77,    79,    82,    85,
      88,    91,    92,    93,    96,    99,   103,   104,     4,     3,
       4,     4,     4,     4,     3,     3,     4,    32,    33,    37,
      41,    42,    47,    48,    55,   108,     4,    12,    13,    23,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    90,    98,    23,    55,     0,    73,    56,    55,   108,
      55,    91,   108,   108,    67,    75,    97,   108,   108,   108,
      31,    15,    15,     3,    34,    35,    36,    37,    38,    39,
      40,    49,    50,    51,    52,    53,    54,    30,    67,   105,
     106,   107,   108,   108,    55,    89,    92,   108,     3,    24,
       3,     4,    23,    56,    86,   108,     5,     5,     5,     5,
       5,    55,   108,     5,     5,     4,     4,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
      55,     5,    25,    25,    24,     3,    23,    55,   105,    24,
       4,    26,    27,    43,    44,    45,    46,    55,    76,    78,
      92,   108,    23,    56,     3,    17,    17,     3,     3,    17,
       6,    56,     3,    17,   108,   108,     3,    67,   108,    23,
      24,    56,     5,    67,     4,     4,     4,    28,     4,     3,
       3,     3,    24,    68,     8,   100,    72,    72,    55,    55,
      55,    72,     5,     5,    55,   108,    55,    17,    55,    68,
      80,    17,     5,    42,    55,     5,   107,   108,    67,   108,
     101,    18,    18,     4,    98,    18,    24,    56,    81,   108,
      29,    67,    72,    55,    25,    25,     3,     5,     5,    23,
      87,     6,     8,    10,   102,    19,    94,    17,    68,    83,
      18,    25,     4,    23,    18,     3,    81,   108,     3,     3,
     108,     3,    23,    72,   108,     6,    18,    16,    17,    95,
      17,    84,    67,     3,   108,   108,    33,     5,     5,    24,
     108,     9,     6,    72,     4,    72,    19,    81,    18,    25,
      23,     5,    24,     3,    24,     3,    72,   108,    18,    16,
      17,    18,     3,    17,   108,     3,     3,     9,     5,     4,
      72,    81,    24,     3,    17,   108,    18,    18,    23,    72,
       5,   108,    18,    17,    24,    72,     3,    18
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    70,    71,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    76,    76,    76,
      76,    77,    78,    78,    79,    80,    80,    80,    81,    81,
      82,    83,    83,    84,    84,    85,    86,    86,    87,    87,
      88,    88,    88,    89,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    91,    91,    91,    91,
      91,    91,    92,    92,    93,    93,    93,    94,    95,    95,
      96,    97,    97,    98,    98,    99,   100,   101,   101,   102,
     102,   103,   104,   105,   105,   105,   105,   106,   106,   107,
     107,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     5,     5,     3,     5,     8,     1,
       1,     1,     5,     8,     1,     5,     7,     1,     1,     1,
       1,    10,     6,     2,     6,     6,     4,     6,     3,     1,
       8,     9,     4,     5,     3,     8,     3,     2,     4,     3,
       4,     4,     8,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     2,     2,
       3,     5,     4,     7,     7,    11,    13,     8,     9,     0,
       7,     5,     4,     1,     1,     9,     6,     7,     0,     3,
       0,     7,     8,     1,     1,     1,     0,     4,     2,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     2,     2,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     5,     5
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
#line 1533 "parser.tab.c"
    break;

  case 3: /* lista_instrucciones: lista_instrucciones instruccion  */
#line 71 "parser.y"
                                                    { (yyval.nodo) = ListaInstrucciones((yyvsp[-1].nodo), (yyvsp[0].nodo)); }
#line 1539 "parser.tab.c"
    break;

  case 4: /* lista_instrucciones: instruccion  */
#line 72 "parser.y"
                                                    { (yyval.nodo) = ListaInstrucciones((yyvsp[0].nodo), NULL); }
#line 1545 "parser.tab.c"
    break;

  case 5: /* instruccion: declaration  */
#line 76 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1551 "parser.tab.c"
    break;

  case 6: /* instruccion: asignation  */
#line 77 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1557 "parser.tab.c"
    break;

  case 7: /* instruccion: print  */
#line 78 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1563 "parser.tab.c"
    break;

  case 8: /* instruccion: if_sentence  */
#line 79 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1569 "parser.tab.c"
    break;

  case 9: /* instruccion: native_func  */
#line 80 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1575 "parser.tab.c"
    break;

  case 10: /* instruccion: switch_case  */
#line 81 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1581 "parser.tab.c"
    break;

  case 11: /* instruccion: while_sentence  */
#line 82 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1587 "parser.tab.c"
    break;

  case 12: /* instruccion: for_sentence  */
#line 83 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1593 "parser.tab.c"
    break;

  case 13: /* instruccion: function_sentence  */
#line 84 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1599 "parser.tab.c"
    break;

  case 14: /* print: PRINT_SENTENCE PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 90 "parser.y"
                                                                                    { (yyval.nodo) = Print((yyvsp[-2].nodo)); }
#line 1605 "parser.tab.c"
    break;

  case 15: /* print: PRINT_SENTENCE PARENTESIS_OPEN native_func PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 91 "parser.y"
                                                                                    { (yyval.nodo) = Print((yyvsp[-2].nodo)); }
#line 1611 "parser.tab.c"
    break;

  case 16: /* declaration: DATA_TYPE IDENTIFICADOR S_PUNTO_COMA  */
#line 96 "parser.y"
            {  (yyval.nodo) = Var_Declaration((yyvsp[-2].data_type), (yyvsp[-1].identificador), Terminal_Null("DEFAULT")); /* VARIABLE SIN VALOR*/ }
#line 1617 "parser.tab.c"
    break;

  case 17: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL expr S_PUNTO_COMA  */
#line 99 "parser.y"
            { (yyval.nodo) = Var_Declaration((yyvsp[-4].data_type), (yyvsp[-3].identificador), (yyvsp[-1].nodo)); }
#line 1623 "parser.tab.c"
    break;

  case 18: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL PARENTESIS_OPEN DATA_TYPE PARENTESIS_CLOSE IDENTIFICADOR S_PUNTO_COMA  */
#line 102 "parser.y"
            { (yyval.nodo) = Casteo_Narrowing((yyvsp[-7].data_type), (yyvsp[-6].identificador), (yyvsp[-3].data_type), (yyvsp[-1].identificador)); /* CASTEO NARROWING*/ }
#line 1629 "parser.tab.c"
    break;

  case 19: /* declaration: vector  */
#line 104 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); /* DECLARATION VECTOR */ }
#line 1635 "parser.tab.c"
    break;

  case 20: /* declaration: matriz  */
#line 106 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); /* MATRIZ */ }
#line 1641 "parser.tab.c"
    break;

  case 21: /* declaration: dynamic_array  */
#line 108 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("DYNAMIC_ARRAY NO IMPLEMENTADO AUN"); /* DYNAMIC_ARRAY */ }
#line 1647 "parser.tab.c"
    break;

  case 22: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL variable_access S_PUNTO_COMA  */
#line 111 "parser.y"
            { (yyval.nodo) = Vector_Asignation((yyvsp[-4].data_type), (yyvsp[-3].identificador), (yyvsp[-1].nodo)); /* ASIGNACION DE VARIABLE A VECTOR O MATRIZ */ }
#line 1653 "parser.tab.c"
    break;

  case 23: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL parse_expretion PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 114 "parser.y"
            { (yyval.nodo) = Parse_Expression((yyvsp[-6].identificador), (yyvsp[-7].data_type), (yyvsp[-4].identificador), (yyvsp[-2].nodo)); /* PARSEO DE TIPOS */ }
#line 1659 "parser.tab.c"
    break;

  case 24: /* declaration: string_join  */
#line 116 "parser.y"
                           { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1665 "parser.tab.c"
    break;

  case 25: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL array_funcs S_PUNTO_COMA  */
#line 119 "parser.y"
            { (yyval.nodo) = Array_func_Declaration((yyvsp[-4].data_type), (yyvsp[-3].identificador), (yyvsp[-1].nodo)); /* FUNCIONES DE ARRAYS */ }
#line 1671 "parser.tab.c"
    break;

  case 26: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL IDENTIFICADOR PARENTESIS_OPEN PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 122 "parser.y"
            { (yyval.nodo) = Asignation_function_no_param((yyvsp[-6].data_type), (yyvsp[-5].identificador), (yyvsp[-3].identificador)); /* ASIGNACION DE VARIABLE A UNA FUNCION SIN PARAMETROS */ }
#line 1677 "parser.tab.c"
    break;

  case 27: /* parse_expretion: PARSE_INT  */
#line 126 "parser.y"
                                     { (yyval.identificador) = "int"; }
#line 1683 "parser.tab.c"
    break;

  case 28: /* parse_expretion: PARSE_DOUBLE  */
#line 127 "parser.y"
                                     { (yyval.identificador) = "double"; }
#line 1689 "parser.tab.c"
    break;

  case 29: /* parse_expretion: PARSE_FLOAT  */
#line 128 "parser.y"
                                     { (yyval.identificador) = "float"; }
#line 1695 "parser.tab.c"
    break;

  case 30: /* parse_expretion: PARSE_STRING  */
#line 129 "parser.y"
                                     { (yyval.identificador) = "String"; }
#line 1701 "parser.tab.c"
    break;

  case 31: /* string_join: DATA_TYPE IDENTIFICADOR S_IGUAL JOIN_STRING PARENTESIS_OPEN STRING_COMILLAS COMA vector_values PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 134 "parser.y"
            { 
                if ((yyvsp[-2].lista_nodos)[0]->tipo == NODO_IDENTIFICADOR) {
                    // Si es un identificador, retornarlo tal cual para evaluar luego
                    (yyval.nodo) = String_Join_Array((yyvsp[-9].data_type), (yyvsp[-8].identificador), (yyvsp[-4].string_comillas), (yyvsp[-2].lista_nodos));
                } else { 
                    (yyval.nodo) = Var_Declaration((yyvsp[-9].data_type), (yyvsp[-8].identificador), Make_StringJoin((yyvsp[-9].data_type), (yyvsp[-4].string_comillas), (yyvsp[-2].lista_nodos))); 
                }
                
            }
#line 1715 "parser.tab.c"
    break;

  case 32: /* array_funcs: ARRAY_INDEX PARENTESIS_OPEN IDENTIFICADOR COMA expr PARENTESIS_CLOSE  */
#line 148 "parser.y"
            { (yyval.nodo) = Array_Index_Of((yyvsp[-3].identificador), (yyvsp[-1].nodo)); /* FUNCION INDEX OF PARA VECTORES */ }
#line 1721 "parser.tab.c"
    break;

  case 33: /* array_funcs: IDENTIFICADOR FUNC_LENGTH  */
#line 151 "parser.y"
            { (yyval.nodo) = Array_Length((yyvsp[-1].identificador)); /* FUNCION LENGTH PARA VECTORES */ }
#line 1727 "parser.tab.c"
    break;

  case 34: /* vector: DATA_TYPE CORCHETE_OPEN CORCHETE_CLOSE IDENTIFICADOR S_IGUAL vector_type  */
#line 157 "parser.y"
        { (yyval.nodo) = Declaration_Vector((yyvsp[-5].data_type), (yyvsp[-2].identificador), (yyvsp[0].nodo)); /* REGRESAMOS EL NODO QUE GENERA */ }
#line 1733 "parser.tab.c"
    break;

  case 35: /* vector_type: NEW_WORD DATA_TYPE CORCHETE_OPEN INT_NUMBER CORCHETE_CLOSE S_PUNTO_COMA  */
#line 162 "parser.y"
            { (yyval.nodo) = Vector_Auto((yyvsp[-4].data_type), (yyvsp[-2].int_number)); }
#line 1739 "parser.tab.c"
    break;

  case 36: /* vector_type: LLAVE_OPEN vector_values LLAVE_CLOSE S_PUNTO_COMA  */
#line 165 "parser.y"
            { (yyval.nodo) = Valores_Vector((yyvsp[-2].lista_nodos)); /* VECTOR CON VALORES */ }
#line 1745 "parser.tab.c"
    break;

  case 37: /* vector_type: IDENTIFICADOR FUNC_ADD PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 168 "parser.y"
            { (yyval.nodo) = Array_Add_Ref((yyvsp[-5].identificador), (yyvsp[-2].nodo)); /* FUNCION ADD EN VECTORES*/}
#line 1751 "parser.tab.c"
    break;

  case 38: /* vector_values: vector_values COMA expr  */
#line 174 "parser.y"
            { (yyval.lista_nodos) = Add_Valor_Vector((yyvsp[-2].lista_nodos), (yyvsp[0].nodo)); }
#line 1757 "parser.tab.c"
    break;

  case 39: /* vector_values: expr  */
#line 176 "parser.y"
            { (yyval.lista_nodos) = Lista_Vector((yyvsp[0].nodo)); }
#line 1763 "parser.tab.c"
    break;

  case 40: /* matriz: DATA_TYPE CORCHETE_OPEN CORCHETE_CLOSE CORCHETE_OPEN CORCHETE_CLOSE IDENTIFICADOR S_IGUAL matriz_type  */
#line 182 "parser.y"
        { (yyval.nodo) = Declaration_Matriz((yyvsp[-7].data_type), (yyvsp[-2].identificador), (yyvsp[0].nodo)); /* REGRESAMOS EL NODO QUE GENERA */ }
#line 1769 "parser.tab.c"
    break;

  case 41: /* matriz_type: NEW_WORD DATA_TYPE CORCHETE_OPEN expr CORCHETE_CLOSE CORCHETE_OPEN expr CORCHETE_CLOSE S_PUNTO_COMA  */
#line 188 "parser.y"
            { (yyval.nodo) = Matriz_Auto((yyvsp[-7].data_type), (yyvsp[-5].nodo), (yyvsp[-2].nodo)); /* valores definidos en matriz*/ }
#line 1775 "parser.tab.c"
    break;

  case 42: /* matriz_type: LLAVE_OPEN matriz_values LLAVE_CLOSE S_PUNTO_COMA  */
#line 191 "parser.y"
            { (yyval.nodo) = Nodo_Vacio("VALORES DE MATRIZ NO IMPLEMENTADO AUN"); /* valores definidos en matriz*/ }
#line 1781 "parser.tab.c"
    break;

  case 44: /* matriz_values: LLAVE_OPEN vector_values LLAVE_CLOSE  */
#line 199 "parser.y"
            { /* valores definidos en matriz*/}
#line 1787 "parser.tab.c"
    break;

  case 50: /* asignation: IDENTIFICADOR op_expr expr_bridge S_PUNTO_COMA  */
#line 221 "parser.y"
            { (yyval.nodo) = Asignacion_Variable((yyvsp[-3].identificador), (yyvsp[-2].identificador), (yyvsp[-1].nodo)); /* 'OPERADOR ASIGNACION' PARA UNA VARIABLE Y ASIGNACION NORMAL*/ }
#line 1793 "parser.tab.c"
    break;

  case 51: /* asignation: variable_access S_IGUAL expr S_PUNTO_COMA  */
#line 224 "parser.y"
            { (yyval.nodo) = Vector_Asignation_Ref((yyvsp[-3].nodo), (yyvsp[-1].nodo)); }
#line 1799 "parser.tab.c"
    break;

  case 52: /* asignation: DATA_TYPE IDENTIFICADOR S_IGUAL IDENTIFICADOR PARENTESIS_OPEN function_parameters_access PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 227 "parser.y"
            {
                Nodo* temp = Function_Call_Parameters((yyvsp[-4].identificador), (yyvsp[-2].lista_nodos));
                (yyval.nodo) = Asignation_function((yyvsp[-7].data_type), (yyvsp[-6].identificador), temp); /* ASIGNACION DE VARIABLE A UNA FUNCION CON PARAMETROS */
            }
#line 1808 "parser.tab.c"
    break;

  case 53: /* expr_bridge: expr  */
#line 238 "parser.y"
                                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1814 "parser.tab.c"
    break;

  case 54: /* expr_bridge: variable_access  */
#line 239 "parser.y"
                                { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1820 "parser.tab.c"
    break;

  case 55: /* op_expr: S_IGUAL  */
#line 244 "parser.y"
                                { (yyval.identificador) = "="; }
#line 1826 "parser.tab.c"
    break;

  case 56: /* op_expr: OP_MAS_IGUAL  */
#line 245 "parser.y"
                                { (yyval.identificador) = "+="; }
#line 1832 "parser.tab.c"
    break;

  case 57: /* op_expr: OP_MENOS_IGUAL  */
#line 246 "parser.y"
                                { (yyval.identificador) = "-="; }
#line 1838 "parser.tab.c"
    break;

  case 58: /* op_expr: OP_MULTI_IGUAL  */
#line 247 "parser.y"
                                { (yyval.identificador) = "*="; }
#line 1844 "parser.tab.c"
    break;

  case 59: /* op_expr: OP_DIV_IGUAL  */
#line 248 "parser.y"
                                { (yyval.identificador) = "/="; }
#line 1850 "parser.tab.c"
    break;

  case 60: /* op_expr: OP_MOD_IGUAL  */
#line 249 "parser.y"
                                { (yyval.identificador) = "%="; }
#line 1856 "parser.tab.c"
    break;

  case 61: /* op_expr: OP_AND_IGUAL  */
#line 250 "parser.y"
                                { (yyval.identificador) = "&="; }
#line 1862 "parser.tab.c"
    break;

  case 62: /* op_expr: OP_OR_IGUAL  */
#line 251 "parser.y"
                                { (yyval.identificador) = "|="; }
#line 1868 "parser.tab.c"
    break;

  case 63: /* op_expr: OP_POT_IGUAL  */
#line 252 "parser.y"
                                { (yyval.identificador) = "^="; }
#line 1874 "parser.tab.c"
    break;

  case 64: /* op_expr: OP_MAYOR_IGUAL  */
#line 253 "parser.y"
                                { (yyval.identificador) = ">>="; }
#line 1880 "parser.tab.c"
    break;

  case 65: /* op_expr: OP_MENOR_IGUAL  */
#line 254 "parser.y"
                                { (yyval.identificador) = "<<="; }
#line 1886 "parser.tab.c"
    break;

  case 66: /* native_func: IDENTIFICADOR for_option S_PUNTO_COMA  */
#line 261 "parser.y"
            {(yyval.nodo) = Plus_Minus_Var((yyvsp[-2].identificador), (yyvsp[-1].identificador));}
#line 1892 "parser.tab.c"
    break;

  case 67: /* native_func: CONTINUE_WORD S_PUNTO_COMA  */
#line 264 "parser.y"
            { (yyval.nodo) = Continue_Word(); /* CONTINUE PARA CICLOS */ }
#line 1898 "parser.tab.c"
    break;

  case 68: /* native_func: BREAK_WORD S_PUNTO_COMA  */
#line 267 "parser.y"
            { (yyval.nodo) = Break_Word(); /* BREAK PARA CICLOS */ }
#line 1904 "parser.tab.c"
    break;

  case 69: /* native_func: RETURN_WORD S_PUNTO_COMA  */
#line 270 "parser.y"
            { (yyval.nodo) = Return_Word(); /* RETURN PARA FUNCIONES */ }
#line 1910 "parser.tab.c"
    break;

  case 70: /* native_func: RETURN_WORD expr S_PUNTO_COMA  */
#line 273 "parser.y"
            { (yyval.nodo) = Return_Value((yyvsp[-1].nodo)); /* RETURN PARA FUNCIONES */ }
#line 1916 "parser.tab.c"
    break;

  case 71: /* native_func: IDENTIFICADOR PARENTESIS_OPEN parameters_bridge PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 276 "parser.y"
            { (yyval.nodo) = Function_Call_No_Param((yyvsp[-4].identificador)); }
#line 1922 "parser.tab.c"
    break;

  case 72: /* variable_access: IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE  */
#line 282 "parser.y"
                {(yyval.nodo) = Vector_Reference((yyvsp[-3].identificador), (yyvsp[-1].nodo));/* ACCESO A VALOR EN UN VECTOR*/}
#line 1928 "parser.tab.c"
    break;

  case 73: /* variable_access: IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE CORCHETE_OPEN expr CORCHETE_CLOSE  */
#line 285 "parser.y"
                {(yyval.nodo) = Nodo_Vacio("MATRIZ NO IMPLEMENTADO AUN");/* ACCESO A VALOR EN UNA MATRIZ */}
#line 1934 "parser.tab.c"
    break;

  case 74: /* if_sentence: IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 291 "parser.y"
            { (yyval.nodo) = Sentencia_If_Simple((yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 1940 "parser.tab.c"
    break;

  case 75: /* if_sentence: IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE ELSE_WORD LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 294 "parser.y"
            { (yyval.nodo) = Sentencia_If_Else((yyvsp[-8].nodo), (yyvsp[-5].nodo), (yyvsp[-1].nodo)); }
#line 1946 "parser.tab.c"
    break;

  case 76: /* if_sentence: IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE if_else_one if_else_chain ELSE_WORD LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 297 "parser.y"
            { (yyval.nodo) = Sentencia_If_ElseIf_Else((yyvsp[-10].nodo), (yyvsp[-7].nodo), (yyvsp[-5].nodo), (yyvsp[-4].lista_nodos), (yyvsp[-1].nodo)); /* IF - ELSE IF - ELSE CON LISTA DE ELSE IF */ }
#line 1952 "parser.tab.c"
    break;

  case 77: /* if_else_one: ELSE_WORD IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 302 "parser.y"
            { (yyval.nodo) = If_Else_One((yyvsp[-4].nodo), (yyvsp[-1].nodo)); /* INSTRUCCIONES DEL ELSE IF SI SOLSO VIENE UNA VEZ */ }
#line 1958 "parser.tab.c"
    break;

  case 78: /* if_else_chain: if_else_chain ELSE_WORD IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 307 "parser.y"
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
#line 1980 "parser.tab.c"
    break;

  case 79: /* if_else_chain: %empty  */
#line 326 "parser.y"
                { 
                // Inicializar lista vacía
                    (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 1);
                    (yyval.lista_nodos)[0] = NULL;
                }
#line 1990 "parser.tab.c"
    break;

  case 80: /* for_sentence: FOR_WORD PARENTESIS_OPEN for_condition PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 336 "parser.y"
            { (yyval.nodo) = For_Sentence((yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 1996 "parser.tab.c"
    break;

  case 81: /* for_condition: declaration expr S_PUNTO_COMA IDENTIFICADOR for_option  */
#line 342 "parser.y"
            { (yyval.nodo) = For_Condition((yyvsp[-4].nodo), (yyvsp[-3].nodo), (yyvsp[-1].identificador), (yyvsp[0].identificador)); }
#line 2002 "parser.tab.c"
    break;

  case 82: /* for_condition: DATA_TYPE IDENTIFICADOR S_PUNTO_PUNTO IDENTIFICADOR  */
#line 344 "parser.y"
            { (yyval.nodo) = For_Each((yyvsp[-3].data_type), (yyvsp[-2].identificador), (yyvsp[0].identificador)); /* Implementacion con los vectores */ }
#line 2008 "parser.tab.c"
    break;

  case 83: /* for_option: OP_AUMENTO  */
#line 348 "parser.y"
                       { (yyval.identificador) = "++"; }
#line 2014 "parser.tab.c"
    break;

  case 84: /* for_option: OP_DECREMENTO  */
#line 349 "parser.y"
                            { (yyval.identificador) = "--"; }
#line 2020 "parser.tab.c"
    break;

  case 85: /* switch_case: SWITCH_WORD PARENTESIS_OPEN IDENTIFICADOR PARENTESIS_CLOSE LLAVE_OPEN switch_case_one switch_case_list switch_default LLAVE_CLOSE  */
#line 354 "parser.y"
            { (yyval.nodo) = Switch_Sentence((yyvsp[-6].identificador), (yyvsp[-3].nodo), (yyvsp[-2].lista_nodos), (yyvsp[-1].nodo)); }
#line 2026 "parser.tab.c"
    break;

  case 86: /* switch_case_one: CASE_WORD expr S_PUNTO_PUNTO lista_instrucciones BREAK_WORD S_PUNTO_COMA  */
#line 360 "parser.y"
                { (yyval.nodo) = Switch_Case_One((yyvsp[-4].nodo), (yyvsp[-2].nodo)); }
#line 2032 "parser.tab.c"
    break;

  case 87: /* switch_case_list: switch_case_list CASE_WORD expr S_PUNTO_PUNTO lista_instrucciones BREAK_WORD S_PUNTO_COMA  */
#line 366 "parser.y"
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
#line 2054 "parser.tab.c"
    break;

  case 88: /* switch_case_list: %empty  */
#line 386 "parser.y"
                { 
                // Inicializar lista vacía
                    (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 1);
                    (yyval.lista_nodos)[0] = NULL;
                }
#line 2064 "parser.tab.c"
    break;

  case 89: /* switch_default: DEFAULT_WORD S_PUNTO_PUNTO lista_instrucciones  */
#line 396 "parser.y"
                { (yyval.nodo) = Switch_Default((yyvsp[0].nodo)); }
#line 2070 "parser.tab.c"
    break;

  case 90: /* switch_default: %empty  */
#line 399 "parser.y"
                { (yyval.nodo) = Nodo_Vacio("NO DEFAULT"); }
#line 2076 "parser.tab.c"
    break;

  case 91: /* while_sentence: WHILE_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 405 "parser.y"
                { (yyval.nodo) = While_Sentence((yyvsp[-4].nodo), (yyvsp[-1].nodo)); }
#line 2082 "parser.tab.c"
    break;

  case 92: /* function_sentence: DATA_TYPE IDENTIFICADOR PARENTESIS_OPEN parameters_bridge PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 411 "parser.y"
                { (yyval.nodo) = Funtion_Declaration((yyvsp[-7].data_type), (yyvsp[-6].identificador), (yyvsp[-4].lista_nodos), (yyvsp[-1].nodo)); /* DECLARACION DE FUNCIONES */ }
#line 2088 "parser.tab.c"
    break;

  case 93: /* parameters_bridge: function_parameters_declaration  */
#line 417 "parser.y"
                { (yyval.lista_nodos) = (yyvsp[0].lista_nodos); }
#line 2094 "parser.tab.c"
    break;

  case 94: /* parameters_bridge: function_parameters_access  */
#line 420 "parser.y"
                { (yyval.lista_nodos) = (yyvsp[0].lista_nodos); }
#line 2100 "parser.tab.c"
    break;

  case 95: /* parameters_bridge: MAIN_STRING  */
#line 423 "parser.y"
                {
                    // Create empty list with single node
                    (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 2);
                    (yyval.lista_nodos)[0] = Nodo_Vacio("NO PARAMETROS");
                    (yyval.lista_nodos)[1] = NULL;
                }
#line 2111 "parser.tab.c"
    break;

  case 96: /* parameters_bridge: %empty  */
#line 431 "parser.y"
                {
                    // Create empty list
                    (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 1);
                    (yyval.lista_nodos)[0] = Nodo_Vacio("NO PARAMETROS");
                }
#line 2121 "parser.tab.c"
    break;

  case 97: /* function_parameters_declaration: function_parameters_declaration COMA DATA_TYPE IDENTIFICADOR  */
#line 441 "parser.y"
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
#line 2139 "parser.tab.c"
    break;

  case 98: /* function_parameters_declaration: DATA_TYPE IDENTIFICADOR  */
#line 455 "parser.y"
                    {
                        (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 2);
                        (yyval.lista_nodos)[0] = Var_Declaration((yyvsp[-1].data_type), (yyvsp[0].identificador), Terminal_Null("DEFAULT"));
                        (yyval.lista_nodos)[1] = NULL;
                    }
#line 2149 "parser.tab.c"
    break;

  case 99: /* function_parameters_access: function_parameters_access COMA expr  */
#line 464 "parser.y"
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
#line 2167 "parser.tab.c"
    break;

  case 100: /* function_parameters_access: expr  */
#line 478 "parser.y"
                    {
                        (yyval.lista_nodos) = malloc(sizeof(Nodo*) * 2);
                        (yyval.lista_nodos)[0] = (yyvsp[0].nodo);
                        (yyval.lista_nodos)[1] = NULL;
                    }
#line 2177 "parser.tab.c"
    break;

  case 101: /* expr: expr '+' expr  */
#line 486 "parser.y"
                                                { (yyval.nodo) = Suma((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2183 "parser.tab.c"
    break;

  case 102: /* expr: expr '-' expr  */
#line 487 "parser.y"
                                                { (yyval.nodo) = Resta((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2189 "parser.tab.c"
    break;

  case 103: /* expr: expr '*' expr  */
#line 488 "parser.y"
                                                { (yyval.nodo) = Multiplicacion((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2195 "parser.tab.c"
    break;

  case 104: /* expr: expr '/' expr  */
#line 489 "parser.y"
                                                { (yyval.nodo) = Division((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2201 "parser.tab.c"
    break;

  case 105: /* expr: expr '%' expr  */
#line 490 "parser.y"
                                                { (yyval.nodo) = Modulo((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2207 "parser.tab.c"
    break;

  case 106: /* expr: PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 491 "parser.y"
                                                { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 2213 "parser.tab.c"
    break;

  case 107: /* expr: INT_NUMBER  */
#line 492 "parser.y"
                                                { (yyval.nodo) = Terminal_Int((yyvsp[0].int_number)); }
#line 2219 "parser.tab.c"
    break;

  case 108: /* expr: '-' expr  */
#line 493 "parser.y"
                                                { (yyval.nodo) = Terminal_Negativo((yyvsp[0].nodo)); }
#line 2225 "parser.tab.c"
    break;

  case 109: /* expr: FLOAT_NUMBER FLOAT_SUFFIX  */
#line 494 "parser.y"
                                                { (yyval.nodo) = Terminal_Float((yyvsp[-1].float_number)); }
#line 2231 "parser.tab.c"
    break;

  case 110: /* expr: FLOAT_NUMBER  */
#line 495 "parser.y"
                                                { (yyval.nodo) = Terminal_Double((yyvsp[0].float_number)); }
#line 2237 "parser.tab.c"
    break;

  case 111: /* expr: STRING_COMILLAS  */
#line 496 "parser.y"
                                                { if (strlen((yyvsp[0].string_comillas)) == 3) { (yyval.nodo) = Terminal_Char((yyvsp[0].string_comillas)[1]); } else { (yyval.nodo) = Terminal_String((yyvsp[0].string_comillas)); }}
#line 2243 "parser.tab.c"
    break;

  case 112: /* expr: BOOL_VALUE  */
#line 497 "parser.y"
                                                { (yyval.nodo) = Terminal_Bool((yyvsp[0].bool_true)); }
#line 2249 "parser.tab.c"
    break;

  case 113: /* expr: NULL_VALUE  */
#line 498 "parser.y"
                                                { (yyval.nodo) = Terminal_Null((yyvsp[0].null_value)); }
#line 2255 "parser.tab.c"
    break;

  case 114: /* expr: IDENTIFICADOR  */
#line 499 "parser.y"
                                                { (yyval.nodo) = Identificador_Ref((yyvsp[0].identificador));}
#line 2261 "parser.tab.c"
    break;

  case 115: /* expr: expr OP_MENOR_A expr  */
#line 500 "parser.y"
                                                { (yyval.nodo) = Menor_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2267 "parser.tab.c"
    break;

  case 116: /* expr: expr OP_MAYOR_A expr  */
#line 501 "parser.y"
                                                { (yyval.nodo) = Mayor_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2273 "parser.tab.c"
    break;

  case 117: /* expr: expr OP_MENOR_IGUAL_A expr  */
#line 502 "parser.y"
                                                { (yyval.nodo) = Menor_Igual_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2279 "parser.tab.c"
    break;

  case 118: /* expr: expr OP_MAYOR_IGUAL_A expr  */
#line 503 "parser.y"
                                                { (yyval.nodo) = Mayor_Igual_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2285 "parser.tab.c"
    break;

  case 119: /* expr: expr OP_IGUAL_IGUAL expr  */
#line 504 "parser.y"
                                                { (yyval.nodo) = Igual_Igual((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2291 "parser.tab.c"
    break;

  case 120: /* expr: expr OP_DISTINTO_A expr  */
#line 505 "parser.y"
                                                { (yyval.nodo) = Diferente_Que((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2297 "parser.tab.c"
    break;

  case 121: /* expr: expr LOGIC_AND expr  */
#line 506 "parser.y"
                                                { (yyval.nodo) = And((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2303 "parser.tab.c"
    break;

  case 122: /* expr: expr LOGIC_OR expr  */
#line 507 "parser.y"
                                                { (yyval.nodo) = Or((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 2309 "parser.tab.c"
    break;

  case 123: /* expr: LOGIC_NOT expr  */
#line 508 "parser.y"
                                                { (yyval.nodo) = Not((yyvsp[0].nodo)); }
#line 2315 "parser.tab.c"
    break;

  case 124: /* expr: IDENTIFICADOR FUNC_EQUALS PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 510 "parser.y"
    { (yyval.nodo) = Equals_Compare((yyvsp[-4].identificador), (yyvsp[-1].nodo)); /* PRINT FUNC .EQUALS PARA UNA VARIABLE */ }
#line 2321 "parser.tab.c"
    break;

  case 125: /* expr: STRING_COMILLAS FUNC_EQUALS PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 512 "parser.y"
    { (yyval.nodo) = Equals_Compare((yyvsp[-4].string_comillas), (yyvsp[-1].nodo)); /* PRINT FUNC .EQUALS PARA UNA VARIABLE */ }
#line 2327 "parser.tab.c"
    break;


#line 2331 "parser.tab.c"

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

#line 515 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error: sintáctico en linea: %d\n", yylineno);
}
