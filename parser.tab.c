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
    #include "./Functions/AST.h"

    extern int yylex();
    extern int yylineno;
    void yyerror(const char* s);  

    Nodo* raiz = NULL;

#line 84 "parser.tab.c"

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
  YYSYMBOL_PRINT_SENTENCE = 26,            /* PRINT_SENTENCE  */
  YYSYMBOL_FUNC_EQUALS = 27,               /* FUNC_EQUALS  */
  YYSYMBOL_IF_WORD = 28,                   /* IF_WORD  */
  YYSYMBOL_LLAVE_OPEN = 29,                /* LLAVE_OPEN  */
  YYSYMBOL_LLAVE_CLOSE = 30,               /* LLAVE_CLOSE  */
  YYSYMBOL_ELSE_WORD = 31,                 /* ELSE_WORD  */
  YYSYMBOL_FOR_WORD = 32,                  /* FOR_WORD  */
  YYSYMBOL_CONTINUE_WORD = 33,             /* CONTINUE_WORD  */
  YYSYMBOL_RETURN_WORD = 34,               /* RETURN_WORD  */
  YYSYMBOL_CORCHETE_OPEN = 35,             /* CORCHETE_OPEN  */
  YYSYMBOL_CORCHETE_CLOSE = 36,            /* CORCHETE_CLOSE  */
  YYSYMBOL_NEW_WORD = 37,                  /* NEW_WORD  */
  YYSYMBOL_COMA = 38,                      /* COMA  */
  YYSYMBOL_PARSE_INT = 39,                 /* PARSE_INT  */
  YYSYMBOL_PARSE_FLOAT = 40,               /* PARSE_FLOAT  */
  YYSYMBOL_PARSE_DOUBLE = 41,              /* PARSE_DOUBLE  */
  YYSYMBOL_PARSE_STRING = 42,              /* PARSE_STRING  */
  YYSYMBOL_JOIN_STRING = 43,               /* JOIN_STRING  */
  YYSYMBOL_ARRAY_INDEX = 44,               /* ARRAY_INDEX  */
  YYSYMBOL_FUNC_LENGTH = 45,               /* FUNC_LENGTH  */
  YYSYMBOL_FUNC_ADD = 46,                  /* FUNC_ADD  */
  YYSYMBOL_MAIN_STRING = 47,               /* MAIN_STRING  */
  YYSYMBOL_LOGIC_NOT = 48,                 /* LOGIC_NOT  */
  YYSYMBOL_INT_NUMBER = 49,                /* INT_NUMBER  */
  YYSYMBOL_OP_MENOR_A = 50,                /* OP_MENOR_A  */
  YYSYMBOL_OP_MAYOR_A = 51,                /* OP_MAYOR_A  */
  YYSYMBOL_52_ = 52,                       /* '+'  */
  YYSYMBOL_53_ = 53,                       /* '-'  */
  YYSYMBOL_54_ = 54,                       /* '/'  */
  YYSYMBOL_55_ = 55,                       /* '*'  */
  YYSYMBOL_56_ = 56,                       /* '%'  */
  YYSYMBOL_FLOAT_NUMBER = 57,              /* FLOAT_NUMBER  */
  YYSYMBOL_STRING_COMILLAS = 58,           /* STRING_COMILLAS  */
  YYSYMBOL_BOOL_VALUE = 59,                /* BOOL_VALUE  */
  YYSYMBOL_NULL_VALUE = 60,                /* NULL_VALUE  */
  YYSYMBOL_OP_MENOR_IGUAL_A = 61,          /* OP_MENOR_IGUAL_A  */
  YYSYMBOL_OP_MAYOR_IGUAL_A = 62,          /* OP_MAYOR_IGUAL_A  */
  YYSYMBOL_OP_IGUAL_IGUAL = 63,            /* OP_IGUAL_IGUAL  */
  YYSYMBOL_OP_DISTINTO_A = 64,             /* OP_DISTINTO_A  */
  YYSYMBOL_LOGIC_AND = 65,                 /* LOGIC_AND  */
  YYSYMBOL_LOGIC_OR = 66,                  /* LOGIC_OR  */
  YYSYMBOL_IDENTIFICADOR = 67,             /* IDENTIFICADOR  */
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
#define YYLAST   972

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
       2,     2,     2,     2,     2,     2,     2,    56,     2,     2,
       2,     2,    55,    52,     2,    53,     2,    54,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    68,    69,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    87,    88,    94,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   109,   110,   111,
     112,   116,   120,   121,   126,   130,   131,   132,   137,   138,
     143,   148,   149,   154,   155,   160,   164,   165,   169,   170,
     176,   177,   182,   183,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   204,   205,   206,   207,   208,
     209,   210,   211,   216,   217,   222,   223,   228,   233,   234,
     235,   240,   245,   246,   251,   252,   257,   262,   267,   268,
     273,   274,   275,   279,   280,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304
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
  "OP_MAYOR_IGUAL", "OP_MENOR_IGUAL", "PRINT_SENTENCE", "FUNC_EQUALS",
  "IF_WORD", "LLAVE_OPEN", "LLAVE_CLOSE", "ELSE_WORD", "FOR_WORD",
  "CONTINUE_WORD", "RETURN_WORD", "CORCHETE_OPEN", "CORCHETE_CLOSE",
  "NEW_WORD", "COMA", "PARSE_INT", "PARSE_FLOAT", "PARSE_DOUBLE",
  "PARSE_STRING", "JOIN_STRING", "ARRAY_INDEX", "FUNC_LENGTH", "FUNC_ADD",
  "MAIN_STRING", "LOGIC_NOT", "INT_NUMBER", "OP_MENOR_A", "OP_MAYOR_A",
  "'+'", "'-'", "'/'", "'*'", "'%'", "FLOAT_NUMBER", "STRING_COMILLAS",
  "BOOL_VALUE", "NULL_VALUE", "OP_MENOR_IGUAL_A", "OP_MAYOR_IGUAL_A",
  "OP_IGUAL_IGUAL", "OP_DISTINTO_A", "LOGIC_AND", "LOGIC_OR",
  "IDENTIFICADOR", "$accept", "input", "lista_instrucciones",
  "instruccion", "print", "declaration", "parse_expretion", "string_join",
  "array_funcs", "vector", "vector_type", "vector_values", "matriz",
  "matriz_type", "matriz_values", "dynamic_array", "dynamic_corchete",
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
     241,   -31,     4,    15,    19,    26,    29,    48,    17,   161,
     707,    51,   241,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,    40,  -212,  -212,  -212,  -212,  -212,    25,     8,    -3,
    -212,   420,   442,   420,    65,  -212,  -212,   420,   420,  -212,
    -212,  -212,  -212,  -212,  -212,   314,  -212,    83,  -212,  -212,
    -212,  -212,  -212,  -212,    88,   103,  -212,  -212,  -212,  -212,
     106,   420,   448,  -212,  -212,   420,   -29,  -212,   403,   236,
      72,     2,    97,   466,    68,   119,   485,   503,   -27,   420,
     130,   526,  -212,  -212,   420,   420,   420,   420,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   129,  -212,  -212,
     420,   697,    75,   137,  -212,   878,   331,   107,   146,   128,
    -212,  -212,  -212,  -212,   155,   167,    -1,   168,   180,   188,
     189,   352,   131,  -212,   190,   158,  -212,   878,  -212,   162,
     164,   172,   173,   201,   208,   185,    12,   369,   187,  -212,
     126,   126,   104,   104,  -212,  -212,  -212,   126,   126,   910,
     910,   895,   286,  -212,   545,   182,  -212,  -212,   160,   -26,
     215,   420,   420,   236,  -212,   420,  -212,  -212,  -212,  -212,
    -212,   200,   295,   228,  -212,   223,   241,  -212,  -212,   241,
     174,   176,   241,  -212,   420,   235,   420,   242,   202,  -212,
     179,   842,   861,    11,   563,   241,  -212,   212,   420,    45,
      39,    90,  -212,   151,   116,   718,    74,    91,   878,   214,
     248,   251,   420,   420,   252,   253,   136,   420,    22,   622,
     420,   250,   231,  -212,   234,  -212,  -212,  -212,  -212,   233,
     263,  -212,   264,   420,   420,   420,  -212,    24,   586,  -212,
    -212,  -212,   739,  -212,   420,   241,   645,   241,  -212,   243,
     420,    98,   245,  -212,   878,   760,   605,  -212,  -212,  -212,
     781,   278,   241,   241,   241,   100,   266,   247,   420,   273,
     274,  -212,   282,   296,   204,  -212,  -212,   420,   802,  -212,
    -212,    84,   284,  -212,   102,   255,    87,  -212,   420,   823,
     287,  -212
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
     102,   103,   104,   105,   106,     0,    54,     0,    55,    56,
      57,    58,    59,    60,     0,     0,    61,    62,    63,    64,
       0,     0,     0,     1,     3,     0,     0,    16,     0,    89,
       0,     0,     0,     0,   106,     0,     0,     0,     0,     0,
       0,     0,   115,    71,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    66,    67,
       0,     0,   106,     0,    53,    52,     0,     0,     0,     0,
      27,    29,    28,    30,     0,     0,   106,     0,     0,     0,
       0,     0,     0,    92,     0,    88,    91,    93,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   100,
     107,   108,    95,    96,    98,    97,    99,   109,   110,   111,
     112,   113,   114,    72,     0,    73,    50,    51,     0,     0,
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
    -212,  -212,  -149,   -10,  -212,   258,  -212,  -212,  -212,  -212,
    -212,  -211,  -212,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,   268,   -53,  -212,  -212,  -212,  -212,  -212,  -212,  -212,
    -212,  -212,   139,   110,    -9
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
      45,   237,    64,   186,    27,   163,   107,   129,    27,   104,
      29,   187,    67,    68,    69,   120,    67,    68,   214,    30,
     180,    35,    73,    76,    77,    31,   243,   200,    81,    82,
     201,   257,    32,   204,    61,    33,    28,   130,   108,   265,
     136,   188,     1,    70,   164,    65,   216,    70,     2,   172,
       3,    63,   101,   105,    34,   220,   106,   244,     4,   121,
     127,    66,   233,   221,    72,     5,   284,     6,    78,   223,
     137,     7,     8,     9,    47,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,    54,    55,
      97,   154,    98,     1,   -83,    60,   261,   -82,   263,     2,
      81,     3,   -83,   229,   131,   -82,    10,    99,   128,     4,
      61,   230,   100,   273,   -83,   274,     5,   -82,     6,     1,
     224,   232,     7,     8,     9,     2,   133,     3,   266,   233,
     275,   160,   287,   153,    37,     4,   267,   138,   233,     1,
     233,   156,     5,   158,     6,     2,   227,     3,     7,     8,
       9,   159,   191,   192,   127,     4,   194,    10,    88,    89,
      90,   161,     5,   127,     6,    36,   241,    37,     7,     8,
       9,   225,   226,   162,   165,   205,    38,    39,    86,    87,
      88,    89,    90,    10,   166,    40,    41,    42,    43,   219,
      64,    64,   167,   168,    64,    44,   172,   171,   170,   173,
     174,   175,   176,    10,   238,   177,    64,     1,   242,    38,
      39,   246,   178,     2,   179,     3,   182,   184,    40,    41,
      42,    43,   190,     4,   254,   255,   256,   185,    44,   195,
       5,   197,     6,   198,   283,   260,     7,     8,     9,   122,
     206,   202,    37,   203,     1,   209,   211,   217,   210,   234,
       2,    64,     3,    64,   235,   236,   239,   240,   247,   278,
       4,   248,   250,    64,    64,   249,   252,     5,   253,     6,
     276,    10,   264,     7,     8,     9,   277,   279,   280,   289,
     268,     1,   196,   123,    38,    39,   281,     2,   286,   272,
     288,   291,    79,    40,    41,    42,    43,     4,   122,     1,
      75,    37,   193,    44,     5,     2,     6,   282,    10,     0,
       7,     8,     9,     0,     0,     4,     0,     0,    83,     0,
       0,     0,     5,     0,     6,     0,     0,     0,     7,     8,
       9,     0,     0,     0,     0,   157,    84,    85,    86,    87,
      88,    89,    90,    38,    39,    10,     0,    91,    92,    93,
      94,    95,    40,    41,    42,    43,   169,     0,     0,     0,
       0,     0,    44,    10,    84,    85,    86,    87,    88,    89,
      90,     0,     0,   181,     0,    91,    92,    93,    94,    95,
      96,    84,    85,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,    92,    93,    94,    95,    96,     0,     0,
       0,     0,    84,    85,    86,    87,    88,    89,    90,   109,
       0,     0,     0,    91,    92,    93,    94,    95,    96,    84,
      85,    86,    87,    88,    89,    90,    37,     0,     0,     0,
      91,    92,    93,    94,    95,    96,     0,     0,     0,     0,
       0,     0,   110,   111,   112,   113,   114,   115,    37,     0,
       0,    38,    39,     3,    37,     0,     0,     0,     0,     0,
      40,    41,    42,    43,     0,     0,     0,     0,    38,    39,
     116,     0,     0,   132,     0,     8,     9,    40,    41,    42,
      43,     0,     0,     0,     0,     0,     0,    44,     0,     0,
      38,    39,   134,     0,     0,     0,    38,    39,     0,    40,
      41,    42,    43,     0,     0,    40,    41,    42,    43,    74,
     135,     0,     0,     0,     0,   102,    84,    85,    86,    87,
      88,    89,    90,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,   139,     0,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,    92,    93,    94,
      95,    96,   183,    84,    85,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,    92,    93,    94,    95,    96,
     215,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,    89,    90,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,   258,     0,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,    92,    93,    94,
      95,    96,   270,    84,    85,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    91,    92,    93,    94,    95,    96,
     245,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,    89,    90,     0,     0,     0,     0,    91,    92,    93,
      94,    95,    96,   262,     0,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,    92,    93,    94,
      95,    96,    84,    85,    86,    87,    88,    89,    90,     0,
       0,     0,     0,    91,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,    92,    93,    94,
      95,    96,    46,    47,     0,     0,     0,     0,     0,    48,
      49,    50,    51,    52,    53,     0,     0,    54,    55,    56,
      57,    58,    59,   155,    60,     0,     0,     0,     0,     0,
       0,     0,    61,     0,     0,     0,     0,    84,    85,    86,
      87,    88,    89,    90,   228,     0,     0,     0,    91,    92,
      93,    94,    95,    96,     0,     0,     0,     0,    84,    85,
      86,    87,    88,    89,    90,   259,     0,     0,     0,    91,
      92,    93,    94,    95,    96,     0,     0,     0,     0,    84,
      85,    86,    87,    88,    89,    90,   269,     0,     0,     0,
      91,    92,    93,    94,    95,    96,     0,     0,     0,     0,
      84,    85,    86,    87,    88,    89,    90,   271,     0,     0,
       0,    91,    92,    93,    94,    95,    96,     0,     0,     0,
       0,    84,    85,    86,    87,    88,    89,    90,   285,     0,
       0,     0,    91,    92,    93,    94,    95,    96,     0,     0,
       0,     0,    84,    85,    86,    87,    88,    89,    90,   290,
       0,     0,     0,    91,    92,    93,    94,    95,    96,     0,
       0,     0,     0,    84,    85,    86,    87,    88,    89,    90,
     212,     0,     0,     0,    91,    92,    93,    94,    95,    96,
       0,     0,    84,    85,    86,    87,    88,    89,    90,   213,
       0,     0,     0,    91,    92,    93,    94,    95,    96,     0,
       0,    84,    85,    86,    87,    88,    89,    90,     0,     0,
       0,     0,    91,    92,    93,    94,    95,    96,    84,    85,
      86,    87,    88,    89,    90,     0,     0,     0,     0,    91,
      92,    93,    94,    95,    96,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,    92,    93,    94,
      84,    85,    86,    87,    88,    89,    90,     0,     0,     0,
       0,    91,    92
};

static const yytype_int16 yycheck[] =
{
       9,   212,    12,    29,    35,     6,    35,     5,    35,    62,
       6,    37,     4,     5,     6,    68,     4,     5,     7,     4,
       8,     4,    31,    32,    33,     6,     4,   176,    37,    38,
     179,     7,     6,   182,    35,     6,    67,    35,    67,   250,
      67,    67,     3,    35,    45,     5,   195,    35,     9,    38,
      11,     0,    61,    62,     6,    10,    65,    35,    19,    68,
      69,    36,    38,    18,    67,    26,   277,    28,     3,    30,
      79,    32,    33,    34,     6,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    20,    21,
       7,   100,     4,     3,    10,    27,   245,    10,   247,     9,
     109,    11,    18,    29,     7,    18,    67,     4,    36,    19,
      35,    37,     6,   262,    30,   264,    26,    30,    28,     3,
      30,    30,    32,    33,    34,     9,     7,    11,    30,    38,
      30,     3,    30,     4,     6,    19,    38,     7,    38,     3,
      38,     4,    26,    36,    28,     9,    30,    11,    32,    33,
      34,     5,   161,   162,   163,    19,   165,    67,    54,    55,
      56,     6,    26,   172,    28,     4,    30,     6,    32,    33,
      34,    20,    21,     6,     6,   184,    48,    49,    52,    53,
      54,    55,    56,    67,     4,    57,    58,    59,    60,   198,
     200,   201,     4,     4,   204,    67,    38,     7,    67,    37,
      36,    29,    29,    67,   213,     4,   216,     3,   217,    48,
      49,   220,     4,     9,    29,    11,    29,    35,    57,    58,
      59,    60,     7,    19,   233,   234,   235,    67,    67,    29,
      26,     3,    28,    10,    30,   244,    32,    33,    34,     3,
       5,    67,     6,    67,     3,     3,    67,    35,    46,    35,
       9,   261,    11,   263,     6,     4,     4,     4,     8,   268,
      19,    30,    29,   273,   274,    31,     3,    26,     4,    28,
       4,    67,    29,    32,    33,    34,    29,     4,     4,   288,
      35,     3,   172,    47,    48,    49,     4,     9,     4,    11,
      35,     4,    34,    57,    58,    59,    60,    19,     3,     3,
      32,     6,   163,    67,    26,     9,    28,    11,    67,    -1,
      32,    33,    34,    -1,    -1,    19,    -1,    -1,     4,    -1,
      -1,    -1,    26,    -1,    28,    -1,    -1,    -1,    32,    33,
      34,    -1,    -1,    -1,    -1,     4,    50,    51,    52,    53,
      54,    55,    56,    48,    49,    67,    -1,    61,    62,    63,
      64,    65,    57,    58,    59,    60,     4,    -1,    -1,    -1,
      -1,    -1,    67,    67,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,     4,    -1,    61,    62,    63,    64,    65,
      66,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,     6,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    50,
      51,    52,    53,    54,    55,    56,     6,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,     6,    -1,
      -1,    48,    49,    11,     6,    -1,    -1,    -1,    -1,    -1,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    48,    49,
      67,    -1,    -1,     7,    -1,    33,    34,    57,    58,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      48,    49,     7,    -1,    -1,    -1,    48,    49,    -1,    57,
      58,    59,    60,    -1,    -1,    57,    58,    59,    60,    67,
       7,    -1,    -1,    -1,    -1,    67,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    66,     7,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    66,     7,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,    66,
       7,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    66,     7,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    66,     7,    50,    51,    52,    53,    54,    55,    56,
      -1,    -1,    -1,    -1,    61,    62,    63,    64,    65,    66,
       8,    -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,
      54,    55,    56,    -1,    -1,    -1,    -1,    61,    62,    63,
      64,    65,    66,     8,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    66,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    -1,
      -1,    -1,    -1,    -1,    -1,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      65,    66,     5,     6,    -1,    -1,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    17,    -1,    -1,    20,    21,    22,
      23,    24,    25,    36,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    -1,    -1,    -1,    -1,    50,    51,    52,
      53,    54,    55,    56,    36,    -1,    -1,    -1,    61,    62,
      63,    64,    65,    66,    -1,    -1,    -1,    -1,    50,    51,
      52,    53,    54,    55,    56,    36,    -1,    -1,    -1,    61,
      62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,    50,
      51,    52,    53,    54,    55,    56,    36,    -1,    -1,    -1,
      61,    62,    63,    64,    65,    66,    -1,    -1,    -1,    -1,
      50,    51,    52,    53,    54,    55,    56,    36,    -1,    -1,
      -1,    61,    62,    63,    64,    65,    66,    -1,    -1,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    36,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    66,    -1,    -1,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    36,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    -1,
      -1,    -1,    -1,    50,    51,    52,    53,    54,    55,    56,
      38,    -1,    -1,    -1,    61,    62,    63,    64,    65,    66,
      -1,    -1,    50,    51,    52,    53,    54,    55,    56,    38,
      -1,    -1,    -1,    61,    62,    63,    64,    65,    66,    -1,
      -1,    50,    51,    52,    53,    54,    55,    56,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65,    66,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    -1,    -1,    61,
      62,    63,    64,    65,    66,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    -1,    -1,    61,    62,    63,    64,
      50,    51,    52,    53,    54,    55,    56,    -1,    -1,    -1,
      -1,    61,    62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     9,    11,    19,    26,    28,    32,    33,    34,
      67,    69,    70,    71,    72,    73,    77,    80,    83,    86,
      89,    90,    91,    92,    94,    97,    98,    35,    67,     6,
       4,     6,     6,     6,     6,     4,     4,     6,    48,    49,
      57,    58,    59,    60,    67,   102,     5,     6,    12,    13,
      14,    15,    16,    17,    20,    21,    22,    23,    24,    25,
      27,    35,    88,     0,    71,     5,    36,     4,     5,     6,
      35,    84,    67,   102,    67,    89,   102,   102,     3,    73,
      93,   102,   102,     4,    50,    51,    52,    53,    54,    55,
      56,    61,    62,    63,    64,    65,    66,     7,     4,     4,
       6,   102,    67,    87,    90,   102,   102,    35,    67,     6,
      39,    40,    41,    42,    43,    44,    67,    74,    75,    76,
      90,   102,     3,    47,    99,   100,   101,   102,    36,     5,
      35,     7,     7,     7,     7,     7,    67,   102,     7,     7,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,     4,   102,    36,     4,     4,    36,     5,
       3,     6,     6,     6,    45,     6,     4,     4,     4,     4,
      67,     7,    38,    37,    36,    29,    29,     4,     4,    29,
       8,     4,    29,     7,    35,    67,    29,    37,    67,    78,
       7,   102,   102,   100,   102,    29,   101,     3,    10,    95,
      70,    70,    67,    67,    70,   102,     5,    79,   102,     3,
      46,    67,    38,    38,     7,     7,    70,    35,    85,   102,
      10,    18,    96,    30,    30,    20,    21,    30,    36,    29,
      37,    81,    30,    38,    35,     6,     4,    79,   102,     4,
       4,    30,   102,     4,    35,     8,   102,     8,    30,    31,
      29,    82,     3,     4,   102,   102,   102,     7,     7,    36,
     102,    70,     8,    70,    29,    79,    30,    38,    35,    36,
       7,    36,    11,    70,    70,    30,     4,    29,   102,     4,
       4,     4,    11,    30,    79,    36,     4,    30,    35,   102,
      36,     4
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
#line 64 "parser.y"
                                                    { raiz = (yyvsp[0].nodo); yylineno = 1; }
#line 1507 "parser.tab.c"
    break;

  case 3: /* lista_instrucciones: lista_instrucciones instruccion  */
#line 68 "parser.y"
                                                    { (yyval.nodo) = ListaInstrucciones((yyvsp[-1].nodo), (yyvsp[0].nodo)); }
#line 1513 "parser.tab.c"
    break;

  case 4: /* lista_instrucciones: instruccion  */
#line 69 "parser.y"
                                                    { (yyval.nodo) = ListaInstrucciones((yyvsp[0].nodo), NULL); }
#line 1519 "parser.tab.c"
    break;

  case 5: /* instruccion: declaration  */
#line 73 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("DECLARACION NO IMPLEMENTADA AUN"); /*$$ = $1;*/ }
#line 1525 "parser.tab.c"
    break;

  case 6: /* instruccion: asignation  */
#line 74 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("ASIGNACION NO IMPLEMENTADA AUN"); /*$$ = $1;*/ }
#line 1531 "parser.tab.c"
    break;

  case 7: /* instruccion: print  */
#line 75 "parser.y"
                                    { (yyval.nodo) = (yyvsp[0].nodo); }
#line 1537 "parser.tab.c"
    break;

  case 8: /* instruccion: if_sentence  */
#line 76 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("IF NO IMPLEMENTADO AUN"); /*$$ = $1;*/ }
#line 1543 "parser.tab.c"
    break;

  case 9: /* instruccion: native_func  */
#line 77 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("FUNCION NATIVA NO IMPLEMENTADA AUN"); /*$$ = $1;*/ }
#line 1549 "parser.tab.c"
    break;

  case 10: /* instruccion: switch_case  */
#line 78 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("SWITCH CASE NO IMPLEMENTADA AUN"); /*$$ = $1;*/ }
#line 1555 "parser.tab.c"
    break;

  case 11: /* instruccion: while_sentence  */
#line 79 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("WHILE NO IMPLEMENTADO AUN"); /*$$ = $1;*/ }
#line 1561 "parser.tab.c"
    break;

  case 12: /* instruccion: for_sentence  */
#line 80 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("FOR NO IMPLEMENTADO AUN"); /*$$ = $1;*/ }
#line 1567 "parser.tab.c"
    break;

  case 13: /* instruccion: function_sentence  */
#line 81 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("FUNCION NO IMPLEMENTADA AUN"); /*$$ = $1;*/ }
#line 1573 "parser.tab.c"
    break;

  case 14: /* print: PRINT_SENTENCE PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 87 "parser.y"
                                                                                    { (yyval.nodo) = Print((yyvsp[-2].nodo)); }
#line 1579 "parser.tab.c"
    break;

  case 15: /* print: PRINT_SENTENCE PARENTESIS_OPEN native_func PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 88 "parser.y"
                                                                                    { /* PRINT FUNCION NATIVA */ }
#line 1585 "parser.tab.c"
    break;

  case 16: /* declaration: DATA_TYPE IDENTIFICADOR S_PUNTO_COMA  */
#line 95 "parser.y"
            { /* VARIABLE SIN VALOR*/ }
#line 1591 "parser.tab.c"
    break;

  case 17: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL expr S_PUNTO_COMA  */
#line 96 "parser.y"
                                                                             { (yyval.nodo) = Nodo_Vacio("DECLARACION SIN ASIGNACION NO IMPLEMENTADA AUN"); /* DECLARACION CON ASIGNACION NORMAL*/ }
#line 1597 "parser.tab.c"
    break;

  case 18: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL PARENTESIS_OPEN DATA_TYPE PARENTESIS_CLOSE IDENTIFICADOR S_PUNTO_COMA  */
#line 97 "parser.y"
                                                                                                                    { /* CASTEO NARROWING*/ }
#line 1603 "parser.tab.c"
    break;

  case 19: /* declaration: vector  */
#line 98 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("VECTOR NO IMPLEMENTADO AUN"); /* VECTOR */ }
#line 1609 "parser.tab.c"
    break;

  case 20: /* declaration: matriz  */
#line 99 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("MATRIZ NO IMPLEMENTADO AUN"); /* MATRIZ */ }
#line 1615 "parser.tab.c"
    break;

  case 21: /* declaration: dynamic_array  */
#line 100 "parser.y"
                                    { (yyval.nodo) = Nodo_Vacio("DYNAMIC_ARRAY NO IMPLEMENTADO AUN"); /* DYNAMIC_ARRAY */ }
#line 1621 "parser.tab.c"
    break;

  case 22: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL variable_access S_PUNTO_COMA  */
#line 101 "parser.y"
                                                                                { (yyval.nodo) = Nodo_Vacio("Variable acceso NO IMPLEMENTADO AUN"); /* ASIGNACION DE VARIABLE A VECTOR O MATRIZ */ }
#line 1627 "parser.tab.c"
    break;

  case 23: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL IDENTIFICADOR PARENTESIS_OPEN function_parameters PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 102 "parser.y"
                                                                                                                               { (yyval.nodo) = Nodo_Vacio("DECLARACION DE FUNCION NO IMPLEMENTADO AUN"); /* DECLARACION DE FUNCIONES */ }
#line 1633 "parser.tab.c"
    break;

  case 24: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL parse_expretion PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 103 "parser.y"
                                                                                                                 { (yyval.nodo) = Nodo_Vacio("PARSEO DE TIPOS NO IMPLEMENTADO AUN"); /* PARSEO DE TIPOS */ }
#line 1639 "parser.tab.c"
    break;

  case 25: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL string_join S_PUNTO_COMA  */
#line 104 "parser.y"
                                                                        { (yyval.nodo) = Nodo_Vacio("JOIN DE STRINGS NO IMPLEMENTADO AUN"); /* JOIN DE STRINGS */ }
#line 1645 "parser.tab.c"
    break;

  case 26: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL array_funcs S_PUNTO_COMA  */
#line 105 "parser.y"
                                                                        { (yyval.nodo) = Nodo_Vacio("ARRAY FUNCS NO IMPLEMENTADO AUN"); /* FUNCIONES DE ARRAYS */ }
#line 1651 "parser.tab.c"
    break;

  case 35: /* vector_type: NEW_WORD DATA_TYPE CORCHETE_OPEN expr CORCHETE_CLOSE S_PUNTO_COMA  */
#line 130 "parser.y"
                                                                              { /* VECTOR AUTO */ }
#line 1657 "parser.tab.c"
    break;

  case 36: /* vector_type: LLAVE_OPEN vector_values LLAVE_CLOSE S_PUNTO_COMA  */
#line 131 "parser.y"
                                                                        { /* VECTOR CON VALORES */ }
#line 1663 "parser.tab.c"
    break;

  case 37: /* vector_type: IDENTIFICADOR FUNC_ADD PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA  */
#line 132 "parser.y"
                                                                                        { /* FUNCION ADD EN VECTORES*/}
#line 1669 "parser.tab.c"
    break;

  case 50: /* asignation: IDENTIFICADOR op_expr expr_bridge S_PUNTO_COMA  */
#line 176 "parser.y"
                                                                       { /* 'OPERADOR ASIGNACION' PARA UNA VARIABLE Y ASIGNACION NORMAL*/ }
#line 1675 "parser.tab.c"
    break;

  case 51: /* asignation: variable_access S_IGUAL expr S_PUNTO_COMA  */
#line 177 "parser.y"
                                                                       { /* ASIGNACION DE UN VALOR VECTOR, MATRIZ*/}
#line 1681 "parser.tab.c"
    break;

  case 65: /* native_func: IDENTIFICADOR FUNC_EQUALS PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 204 "parser.y"
                                                                                       {/* PRINT FUNC .EQUALS PARA UNA VARIABLE */}
#line 1687 "parser.tab.c"
    break;

  case 66: /* native_func: IDENTIFICADOR OP_AUMENTO S_PUNTO_COMA  */
#line 205 "parser.y"
                                                                                                {/* AUMENTADOR DE VARIABLE PARA BUCLES*/}
#line 1693 "parser.tab.c"
    break;

  case 67: /* native_func: IDENTIFICADOR OP_DECREMENTO S_PUNTO_COMA  */
#line 206 "parser.y"
                                                                                                {/* REDUCTOR DE VARIABLE PARA BUCLES*/}
#line 1699 "parser.tab.c"
    break;

  case 73: /* variable_access: IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE  */
#line 216 "parser.y"
                                                                                {/* ACCESO A VALOR EN UN VECTOR*/}
#line 1705 "parser.tab.c"
    break;

  case 74: /* variable_access: IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE CORCHETE_OPEN expr CORCHETE_CLOSE  */
#line 217 "parser.y"
                                                                                                        {/* ACCESO A VALOR EN UNA MATRIZ */}
#line 1711 "parser.tab.c"
    break;

  case 75: /* if_sentence: IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 222 "parser.y"
                                                                                                        { (yyval.nodo) = Nodo_Vacio("IF SIMPLE NO IMPLEMENTADO AUN"); }
#line 1717 "parser.tab.c"
    break;

  case 76: /* if_sentence: IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE ELSE_WORD LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 223 "parser.y"
                                                                                                                                                            { (yyval.nodo) = Nodo_Vacio("IF ELSE NO IMPLEMENTADO AUN"); }
#line 1723 "parser.tab.c"
    break;

  case 78: /* for_condition: declaration expr S_PUNTO_COMA IDENTIFICADOR OP_AUMENTO  */
#line 233 "parser.y"
                                                                                                  {/* ESTRUCTURA FOR NORMAL */}
#line 1729 "parser.tab.c"
    break;

  case 79: /* for_condition: declaration expr S_PUNTO_COMA IDENTIFICADOR OP_DECREMENTO  */
#line 234 "parser.y"
                                                                                                  {/* ESTRUCTURA FOR NORMAL */}
#line 1735 "parser.tab.c"
    break;

  case 80: /* for_condition: DATA_TYPE IDENTIFICADOR S_PUNTO_PUNTO IDENTIFICADOR  */
#line 235 "parser.y"
                                                                                                  {/* ESTRUCTURA FOR EACH */}
#line 1741 "parser.tab.c"
    break;

  case 86: /* while_sentence: WHILE_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE  */
#line 257 "parser.y"
                                                                                                            { (yyval.nodo) = Nodo_Vacio("WHILE NO IMPLEMENTADO AUN"); }
#line 1747 "parser.tab.c"
    break;

  case 89: /* parameters_bridge: %empty  */
#line 268 "parser.y"
                      {/* vaćio */}
#line 1753 "parser.tab.c"
    break;

  case 95: /* expr: expr '+' expr  */
#line 284 "parser.y"
                                                { (yyval.nodo) = Suma((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1759 "parser.tab.c"
    break;

  case 96: /* expr: expr '-' expr  */
#line 285 "parser.y"
                                                { (yyval.nodo) = Resta((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1765 "parser.tab.c"
    break;

  case 97: /* expr: expr '*' expr  */
#line 286 "parser.y"
                                                { (yyval.nodo) = Multiplicacion((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1771 "parser.tab.c"
    break;

  case 98: /* expr: expr '/' expr  */
#line 287 "parser.y"
                                                { (yyval.nodo) = Division((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1777 "parser.tab.c"
    break;

  case 99: /* expr: expr '%' expr  */
#line 288 "parser.y"
                                                { (yyval.nodo) = Modulo((yyvsp[-1].int_number), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1783 "parser.tab.c"
    break;

  case 100: /* expr: PARENTESIS_OPEN expr PARENTESIS_CLOSE  */
#line 289 "parser.y"
                                                { (yyval.nodo) = (yyvsp[-1].nodo); }
#line 1789 "parser.tab.c"
    break;

  case 101: /* expr: INT_NUMBER  */
#line 290 "parser.y"
                                                { (yyval.nodo) = Terminal_Int((yyvsp[0].int_number)); }
#line 1795 "parser.tab.c"
    break;

  case 102: /* expr: FLOAT_NUMBER  */
#line 291 "parser.y"
                                                { (yyval.nodo) = Terminal_Float((yyvsp[0].float_number)); }
#line 1801 "parser.tab.c"
    break;

  case 103: /* expr: STRING_COMILLAS  */
#line 292 "parser.y"
                                                { if (strlen((yyvsp[0].string_comillas)) == 3) { (yyval.nodo) = Terminal_Char((yyvsp[0].string_comillas)[1]); } else { (yyval.nodo) = Terminal_String((yyvsp[0].string_comillas)); }}
#line 1807 "parser.tab.c"
    break;

  case 104: /* expr: BOOL_VALUE  */
#line 293 "parser.y"
                                                { (yyval.nodo) = Terminal_Bool((yyvsp[0].bool_true)); }
#line 1813 "parser.tab.c"
    break;

  case 105: /* expr: NULL_VALUE  */
#line 294 "parser.y"
                                                { (yyval.nodo) = Terminal_Null((yyvsp[0].null_value)); }
#line 1819 "parser.tab.c"
    break;

  case 106: /* expr: IDENTIFICADOR  */
#line 295 "parser.y"
                                                { (yyval.nodo) = Identificador_Ref((yyvsp[0].identificador));}
#line 1825 "parser.tab.c"
    break;

  case 107: /* expr: expr OP_MENOR_A expr  */
#line 296 "parser.y"
                                                { (yyval.nodo) = Menor_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1831 "parser.tab.c"
    break;

  case 108: /* expr: expr OP_MAYOR_A expr  */
#line 297 "parser.y"
                                                { (yyval.nodo) = Mayor_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1837 "parser.tab.c"
    break;

  case 109: /* expr: expr OP_MENOR_IGUAL_A expr  */
#line 298 "parser.y"
                                                { (yyval.nodo) = Menor_Igual_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1843 "parser.tab.c"
    break;

  case 110: /* expr: expr OP_MAYOR_IGUAL_A expr  */
#line 299 "parser.y"
                                                { (yyval.nodo) = Mayor_Igual_A((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1849 "parser.tab.c"
    break;

  case 111: /* expr: expr OP_IGUAL_IGUAL expr  */
#line 300 "parser.y"
                                                { (yyval.nodo) = Igual_Igual((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1855 "parser.tab.c"
    break;

  case 112: /* expr: expr OP_DISTINTO_A expr  */
#line 301 "parser.y"
                                                { (yyval.nodo) = Diferente_Que((yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1861 "parser.tab.c"
    break;

  case 113: /* expr: expr LOGIC_AND expr  */
#line 302 "parser.y"
                                                { (yyval.nodo) = Operacion_Bool((yyvsp[-1].operador), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1867 "parser.tab.c"
    break;

  case 114: /* expr: expr LOGIC_OR expr  */
#line 303 "parser.y"
                                                { (yyval.nodo) = Operacion_Bool((yyvsp[-1].operador), (yyvsp[-2].nodo), (yyvsp[0].nodo)); }
#line 1873 "parser.tab.c"
    break;

  case 115: /* expr: LOGIC_NOT expr  */
#line 304 "parser.y"
                                                { (yyval.nodo) = Not((yyvsp[-1].int_number), (yyvsp[0].nodo)); }
#line 1879 "parser.tab.c"
    break;


#line 1883 "parser.tab.c"

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

#line 307 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error: sintáctico en linea: %d\n", yylineno);
}
