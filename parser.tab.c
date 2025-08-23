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

    extern int yylex();
    extern int yylineno;
    void yyerror(const char* s);

#line 80 "parser.tab.c"

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
  YYSYMBOL_INT_NUMBER = 3,                 /* INT_NUMBER  */
  YYSYMBOL_FLOAT_NUMBER = 4,               /* FLOAT_NUMBER  */
  YYSYMBOL_IDENTIFICADOR = 5,              /* IDENTIFICADOR  */
  YYSYMBOL_STRING_COMILLAS = 6,            /* STRING_COMILLAS  */
  YYSYMBOL_BOOL_VALUE = 7,                 /* BOOL_VALUE  */
  YYSYMBOL_NULL_VALUE = 8,                 /* NULL_VALUE  */
  YYSYMBOL_DATA_TYPE = 9,                  /* DATA_TYPE  */
  YYSYMBOL_S_PUNTO_COMA = 10,              /* S_PUNTO_COMA  */
  YYSYMBOL_S_IGUAL = 11,                   /* S_IGUAL  */
  YYSYMBOL_PARENTESIS_OPEN = 12,           /* PARENTESIS_OPEN  */
  YYSYMBOL_PARENTESIS_CLOSE = 13,          /* PARENTESIS_CLOSE  */
  YYSYMBOL_S_PUNTO_PUNTO = 14,             /* S_PUNTO_PUNTO  */
  YYSYMBOL_SWITCH_WORD = 15,               /* SWITCH_WORD  */
  YYSYMBOL_CASE_WORD = 16,                 /* CASE_WORD  */
  YYSYMBOL_BREAK_WORD = 17,                /* BREAK_WORD  */
  YYSYMBOL_OP_MAS_IGUAL = 18,              /* OP_MAS_IGUAL  */
  YYSYMBOL_OP_MENOS_IGUAL = 19,            /* OP_MENOS_IGUAL  */
  YYSYMBOL_OP_MULTI_IGUAL = 20,            /* OP_MULTI_IGUAL  */
  YYSYMBOL_OP_DIV_IGUAL = 21,              /* OP_DIV_IGUAL  */
  YYSYMBOL_OP_MOD_IGUAL = 22,              /* OP_MOD_IGUAL  */
  YYSYMBOL_OP_AND_IGUAL = 23,              /* OP_AND_IGUAL  */
  YYSYMBOL_DEFAULT_WORD = 24,              /* DEFAULT_WORD  */
  YYSYMBOL_WHILE_WORD = 25,                /* WHILE_WORD  */
  YYSYMBOL_OP_AUMENTO = 26,                /* OP_AUMENTO  */
  YYSYMBOL_OP_DECREMENTO = 27,             /* OP_DECREMENTO  */
  YYSYMBOL_OP_OR_IGUAL = 28,               /* OP_OR_IGUAL  */
  YYSYMBOL_OP_POT_IGUAL = 29,              /* OP_POT_IGUAL  */
  YYSYMBOL_OP_MAYOR_IGUAL = 30,            /* OP_MAYOR_IGUAL  */
  YYSYMBOL_OP_MENOR_IGUAL = 31,            /* OP_MENOR_IGUAL  */
  YYSYMBOL_OP_IGUAL_IGUAL = 32,            /* OP_IGUAL_IGUAL  */
  YYSYMBOL_OP_DISTINTO_A = 33,             /* OP_DISTINTO_A  */
  YYSYMBOL_OP_MENOR_IGUAL_A = 34,          /* OP_MENOR_IGUAL_A  */
  YYSYMBOL_OP_MAYOR_IGUAL_A = 35,          /* OP_MAYOR_IGUAL_A  */
  YYSYMBOL_LOGIC_OR = 36,                  /* LOGIC_OR  */
  YYSYMBOL_LOGIC_AND = 37,                 /* LOGIC_AND  */
  YYSYMBOL_OP_MENOR_A = 38,                /* OP_MENOR_A  */
  YYSYMBOL_OP_MAYOR_A = 39,                /* OP_MAYOR_A  */
  YYSYMBOL_LOGIC_NOT = 40,                 /* LOGIC_NOT  */
  YYSYMBOL_PRINT_SENTENCE = 41,            /* PRINT_SENTENCE  */
  YYSYMBOL_FUNC_EQUALS = 42,               /* FUNC_EQUALS  */
  YYSYMBOL_IF_WORD = 43,                   /* IF_WORD  */
  YYSYMBOL_LLAVE_OPEN = 44,                /* LLAVE_OPEN  */
  YYSYMBOL_LLAVE_CLOSE = 45,               /* LLAVE_CLOSE  */
  YYSYMBOL_ELSE_WORD = 46,                 /* ELSE_WORD  */
  YYSYMBOL_FOR_WORD = 47,                  /* FOR_WORD  */
  YYSYMBOL_CONTINUE_WORD = 48,             /* CONTINUE_WORD  */
  YYSYMBOL_RETURN_WORD = 49,               /* RETURN_WORD  */
  YYSYMBOL_CORCHETE_OPEN = 50,             /* CORCHETE_OPEN  */
  YYSYMBOL_CORCHETE_CLOSE = 51,            /* CORCHETE_CLOSE  */
  YYSYMBOL_NEW_WORD = 52,                  /* NEW_WORD  */
  YYSYMBOL_COMA = 53,                      /* COMA  */
  YYSYMBOL_54_ = 54,                       /* '+'  */
  YYSYMBOL_55_ = 55,                       /* '-'  */
  YYSYMBOL_56_ = 56,                       /* '*'  */
  YYSYMBOL_57_ = 57,                       /* '/'  */
  YYSYMBOL_58_ = 58,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_input = 60,                     /* input  */
  YYSYMBOL_lista_instrucciones = 61,       /* lista_instrucciones  */
  YYSYMBOL_instruccion = 62,               /* instruccion  */
  YYSYMBOL_print = 63,                     /* print  */
  YYSYMBOL_declaration = 64,               /* declaration  */
  YYSYMBOL_vector = 65,                    /* vector  */
  YYSYMBOL_vector_type = 66,               /* vector_type  */
  YYSYMBOL_vector_values = 67,             /* vector_values  */
  YYSYMBOL_matriz = 68,                    /* matriz  */
  YYSYMBOL_matriz_type = 69,               /* matriz_type  */
  YYSYMBOL_matriz_values = 70,             /* matriz_values  */
  YYSYMBOL_asignation = 71,                /* asignation  */
  YYSYMBOL_op_expr = 72,                   /* op_expr  */
  YYSYMBOL_native_func = 73,               /* native_func  */
  YYSYMBOL_if_sentence = 74,               /* if_sentence  */
  YYSYMBOL_for_sentence = 75,              /* for_sentence  */
  YYSYMBOL_for_condition = 76,             /* for_condition  */
  YYSYMBOL_switch_case = 77,               /* switch_case  */
  YYSYMBOL_switch_case_list = 78,          /* switch_case_list  */
  YYSYMBOL_switch_default = 79,            /* switch_default  */
  YYSYMBOL_while_sentence = 80,            /* while_sentence  */
  YYSYMBOL_expr = 81                       /* expr  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  43
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   548

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  78
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  199

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


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
       2,     2,     2,     2,     2,     2,     2,    58,     2,     2,
       2,     2,    56,    54,     2,    55,     2,    57,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    53,    53,    57,    58,    62,    63,    64,    65,    66,
      67,    68,    69,    75,    76,    83,    84,    85,    86,    87,
      92,    96,    97,   103,   104,   109,   114,   115,   120,   121,
     128,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   149,   150,   151,   152,   157,   158,   163,   168,
     169,   170,   175,   180,   181,   186,   187,   192,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217
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
  "\"end of file\"", "error", "\"invalid token\"", "INT_NUMBER",
  "FLOAT_NUMBER", "IDENTIFICADOR", "STRING_COMILLAS", "BOOL_VALUE",
  "NULL_VALUE", "DATA_TYPE", "S_PUNTO_COMA", "S_IGUAL", "PARENTESIS_OPEN",
  "PARENTESIS_CLOSE", "S_PUNTO_PUNTO", "SWITCH_WORD", "CASE_WORD",
  "BREAK_WORD", "OP_MAS_IGUAL", "OP_MENOS_IGUAL", "OP_MULTI_IGUAL",
  "OP_DIV_IGUAL", "OP_MOD_IGUAL", "OP_AND_IGUAL", "DEFAULT_WORD",
  "WHILE_WORD", "OP_AUMENTO", "OP_DECREMENTO", "OP_OR_IGUAL",
  "OP_POT_IGUAL", "OP_MAYOR_IGUAL", "OP_MENOR_IGUAL", "OP_IGUAL_IGUAL",
  "OP_DISTINTO_A", "OP_MENOR_IGUAL_A", "OP_MAYOR_IGUAL_A", "LOGIC_OR",
  "LOGIC_AND", "OP_MENOR_A", "OP_MAYOR_A", "LOGIC_NOT", "PRINT_SENTENCE",
  "FUNC_EQUALS", "IF_WORD", "LLAVE_OPEN", "LLAVE_CLOSE", "ELSE_WORD",
  "FOR_WORD", "CONTINUE_WORD", "RETURN_WORD", "CORCHETE_OPEN",
  "CORCHETE_CLOSE", "NEW_WORD", "COMA", "'+'", "'-'", "'*'", "'/'", "'%'",
  "$accept", "input", "lista_instrucciones", "instruccion", "print",
  "declaration", "vector", "vector_type", "vector_values", "matriz",
  "matriz_type", "matriz_values", "asignation", "op_expr", "native_func",
  "if_sentence", "for_sentence", "for_condition", "switch_case",
  "switch_case_list", "switch_default", "while_sentence", "expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-161)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     335,   395,     4,    -8,    -1,    17,    20,    22,    69,   335,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,  -161,  -161,  -161,  -161,  -161,  -161,    78,    79,
    -161,  -161,  -161,  -161,    87,   367,     3,    50,    97,   367,
     380,   367,    95,  -161,  -161,  -161,  -161,    74,  -161,  -161,
    -161,  -161,  -161,  -161,   367,   367,    27,  -161,   390,     5,
      93,   147,   -24,   107,   155,   182,     7,   367,   126,   129,
     130,   193,  -161,  -161,   367,   367,   367,   367,   367,   367,
     367,   367,   367,   367,   367,   367,   367,    88,    80,    99,
      57,   100,   102,   137,   138,   105,   113,   120,   106,  -161,
    -161,  -161,   490,   490,    18,    18,   476,   484,    18,    18,
      75,    75,  -161,  -161,  -161,   150,  -161,   -29,   146,   149,
     335,  -161,  -161,   335,   161,   162,   335,   164,   367,   187,
    -161,   159,   367,     1,    62,   264,  -161,   114,   283,   188,
     -18,   449,   121,   -16,   220,   367,   183,   154,  -161,   176,
    -161,  -161,  -161,  -161,   190,   367,   367,   163,   199,  -161,
     335,   228,   335,  -161,   179,  -161,   449,   406,   367,   -15,
     174,   295,   335,   335,   335,   223,   -14,   225,   197,   367,
     233,   308,   322,  -161,  -161,  -161,   367,   414,  -161,   234,
    -161,    33,   195,  -161,  -161,   367,   441,   236,  -161
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     2,
       4,     7,     5,    18,    19,     6,     9,     8,    12,    10,
      11,    31,    32,    33,    34,    35,    36,    37,     0,     0,
      38,    39,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     3,    44,    45,     0,    64,    65,
      69,    66,    67,    68,     0,     0,     0,    15,     0,     0,
       0,     0,    69,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    30,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    42,
      43,    63,    74,    75,    72,    73,    77,    76,    70,    71,
      58,    59,    60,    61,    62,     0,    16,     0,     0,     0,
       0,    14,    13,     0,     0,     0,     0,     0,     0,     0,
      20,     0,     0,    56,     0,     0,    51,     0,     0,     0,
       0,    24,     0,     0,     0,     0,     0,     0,    57,    46,
      49,    50,    48,    17,     0,     0,     0,     0,     0,    25,
       0,     0,     0,    52,     0,    22,    23,     0,     0,     0,
       0,     0,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    21,    29,    27,     0,     0,    54,     0,
      47,     0,     0,    53,    28,     0,     0,     0,    26
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -161,  -161,  -104,    -9,  -161,   226,  -161,  -161,  -160,  -161,
    -161,  -161,  -161,  -161,   230,  -161,  -161,  -161,  -161,  -161,
    -161,  -161,   -34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    12,    13,   130,   140,    14,
     159,   169,    15,    35,    16,    17,    18,    68,    19,   133,
     147,    20,   141
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    56,    28,    29,    38,    61,    64,    65,   176,    36,
      89,    39,    96,    57,    58,   128,   134,   145,    34,   135,
      71,    72,   138,   129,    88,   146,   191,   154,   157,    40,
     177,   184,    41,    97,    42,   155,   158,    73,   178,   155,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,    71,    37,    90,   171,    37,   173,    74,
      75,    76,    77,    78,    79,    80,    81,     1,   181,    43,
     182,     2,    82,    83,    84,    85,    86,     3,   194,    69,
      70,    82,    83,    84,    85,    86,   155,     4,    45,    46,
     116,    48,    49,    50,    51,    52,    53,   115,   144,    47,
      54,    59,    60,     5,    66,     6,    91,   148,   118,     7,
     117,   161,    74,    75,    76,    77,    78,    79,    80,    81,
      93,   166,   167,    57,    58,    44,    44,   124,    55,    44,
     125,    84,    85,    86,    82,    83,    84,    85,    86,    98,
     150,   151,    99,   100,   119,   187,   120,   121,   122,   123,
     126,   131,    74,    75,    76,    77,    78,    79,    80,    81,
      92,   196,    44,   127,    44,   132,   136,   137,    94,   139,
     143,   156,    44,    44,    82,    83,    84,    85,    86,    74,
      75,    76,    77,    78,    79,    80,    81,    74,    75,    76,
      77,    78,    79,    80,    81,    95,   142,   162,   153,   163,
     165,    82,    83,    84,    85,    86,   101,   168,   170,    82,
      83,    84,    85,    86,    74,    75,    76,    77,    78,    79,
      80,    81,   164,   174,   179,    74,    75,    76,    77,    78,
      79,    80,    81,   183,   160,   185,    82,    83,    84,    85,
      86,   186,   172,   188,   193,   195,   198,    82,    83,    84,
      85,    86,    74,    75,    76,    77,    78,    79,    80,    81,
      74,    75,    76,    77,    78,    79,    80,    81,    67,     1,
      63,     0,     0,     2,    82,    83,    84,    85,    86,     3,
       0,     0,    82,    83,    84,    85,    86,     0,     1,     4,
       0,     0,     2,     0,     0,     0,     0,     0,     3,     0,
       1,     0,     0,     0,     2,     5,     0,     6,     4,   149,
       3,     7,   180,     1,     0,     0,     0,     2,     0,     0,
       4,     0,     0,     3,     5,   189,     6,     1,   152,     0,
       7,     2,     0,     4,     0,     0,     5,     3,     6,     0,
       1,     0,     7,     0,     2,     0,     0,     4,     0,     5,
       3,     6,     0,     0,     0,     7,     0,     0,     0,     0,
       4,     0,     0,     5,     0,     6,     0,   190,     0,     7,
      48,    49,    50,    51,    52,    53,     5,     0,     6,    54,
       0,     0,     7,    48,    49,    62,    51,    52,    53,     0,
       0,     0,    54,    48,    49,    50,    51,    52,    53,     0,
       0,     0,    87,     0,     0,     0,    21,    55,     0,     0,
       0,     0,     0,    22,    23,    24,    25,    26,    27,     0,
      55,    28,    29,    30,    31,    32,    33,     0,     0,     0,
      55,     0,     0,     0,     0,     0,     0,    34,    74,    75,
      76,    77,    78,    79,    80,    81,    74,    75,    76,    77,
      78,    79,    80,    81,     0,     0,     0,   175,     0,     0,
      82,    83,    84,    85,    86,   192,     0,     0,    82,    83,
      84,    85,    86,    74,    75,    76,    77,    78,    79,    80,
      81,    74,    75,    76,    77,    78,    79,    80,    81,     0,
       0,     0,   197,     0,     0,    82,    83,    84,    85,    86,
       0,     0,     0,    82,    83,    84,    85,    86,    74,    75,
      76,    77,     0,    79,    80,    81,    74,    75,    76,    77,
       0,     0,    80,    81,    76,    77,     0,     0,    80,    81,
      82,    83,    84,    85,    86,     0,     0,     0,    82,    83,
      84,    85,    86,     0,    82,    83,    84,    85,    86
};

static const yytype_int16 yycheck[] =
{
       9,    35,    26,    27,    12,    39,    40,    41,   168,     5,
       5,    12,     5,    10,    11,    44,   120,    16,    42,   123,
      54,    55,   126,    52,    58,    24,   186,    45,    44,    12,
      45,    45,    12,    67,    12,    53,    52,    10,    53,    53,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    50,    50,   160,    50,   162,    32,
      33,    34,    35,    36,    37,    38,    39,     5,   172,     0,
     174,     9,    54,    55,    56,    57,    58,    15,    45,     5,
       6,    54,    55,    56,    57,    58,    53,    25,    10,    10,
      10,     3,     4,     5,     6,     7,     8,     9,   132,    12,
      12,    51,     5,    41,     9,    43,    13,    45,    51,    47,
      11,   145,    32,    33,    34,    35,    36,    37,    38,    39,
      13,   155,   156,    10,    11,   134,   135,    14,    40,   138,
      10,    56,    57,    58,    54,    55,    56,    57,    58,    13,
      26,    27,    13,    13,    44,   179,    44,    10,    10,    44,
      44,     5,    32,    33,    34,    35,    36,    37,    38,    39,
      13,   195,   171,    13,   173,    16,     5,     5,    13,     5,
      11,    50,   181,   182,    54,    55,    56,    57,    58,    32,
      33,    34,    35,    36,    37,    38,    39,    32,    33,    34,
      35,    36,    37,    38,    39,    13,     9,    14,    10,    45,
      10,    54,    55,    56,    57,    58,    13,    44,     9,    54,
      55,    56,    57,    58,    32,    33,    34,    35,    36,    37,
      38,    39,    46,    44,    50,    32,    33,    34,    35,    36,
      37,    38,    39,    10,    14,    10,    54,    55,    56,    57,
      58,    44,    14,    10,    10,    50,    10,    54,    55,    56,
      57,    58,    32,    33,    34,    35,    36,    37,    38,    39,
      32,    33,    34,    35,    36,    37,    38,    39,    42,     5,
      40,    -1,    -1,     9,    54,    55,    56,    57,    58,    15,
      -1,    -1,    54,    55,    56,    57,    58,    -1,     5,    25,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,    15,    -1,
       5,    -1,    -1,    -1,     9,    41,    -1,    43,    25,    45,
      15,    47,    17,     5,    -1,    -1,    -1,     9,    -1,    -1,
      25,    -1,    -1,    15,    41,    17,    43,     5,    45,    -1,
      47,     9,    -1,    25,    -1,    -1,    41,    15,    43,    -1,
       5,    -1,    47,    -1,     9,    -1,    -1,    25,    -1,    41,
      15,    43,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      25,    -1,    -1,    41,    -1,    43,    -1,    45,    -1,    47,
       3,     4,     5,     6,     7,     8,    41,    -1,    43,    12,
      -1,    -1,    47,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    11,    40,    -1,    -1,
      -1,    -1,    -1,    18,    19,    20,    21,    22,    23,    -1,
      40,    26,    27,    28,    29,    30,    31,    -1,    -1,    -1,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    42,    32,    33,
      34,    35,    36,    37,    38,    39,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    51,    -1,    -1,
      54,    55,    56,    57,    58,    51,    -1,    -1,    54,    55,
      56,    57,    58,    32,    33,    34,    35,    36,    37,    38,
      39,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    51,    -1,    -1,    54,    55,    56,    57,    58,
      -1,    -1,    -1,    54,    55,    56,    57,    58,    32,    33,
      34,    35,    -1,    37,    38,    39,    32,    33,    34,    35,
      -1,    -1,    38,    39,    34,    35,    -1,    -1,    38,    39,
      54,    55,    56,    57,    58,    -1,    -1,    -1,    54,    55,
      56,    57,    58,    -1,    54,    55,    56,    57,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     9,    15,    25,    41,    43,    47,    60,    61,
      62,    63,    64,    65,    68,    71,    73,    74,    75,    77,
      80,    11,    18,    19,    20,    21,    22,    23,    26,    27,
      28,    29,    30,    31,    42,    72,     5,    50,    12,    12,
      12,    12,    12,     0,    62,    10,    10,    12,     3,     4,
       5,     6,     7,     8,    12,    40,    81,    10,    11,    51,
       5,    81,     5,    73,    81,    81,     9,    64,    76,     5,
       6,    81,    81,    10,    32,    33,    34,    35,    36,    37,
      38,    39,    54,    55,    56,    57,    58,    12,    81,     5,
      50,    13,    13,    13,    13,    13,     5,    81,    13,    13,
      13,    13,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,     9,    10,    11,    51,    44,
      44,    10,    10,    44,    14,    10,    44,    13,    44,    52,
      66,     5,    16,    78,    61,    61,     5,     5,    61,     5,
      67,    81,     9,    11,    81,    16,    24,    79,    45,    45,
      26,    27,    45,    10,    45,    53,    50,    44,    52,    69,
      14,    81,    14,    45,    46,    10,    81,    81,    44,    70,
       9,    61,    14,    61,    44,    51,    67,    45,    53,    50,
      17,    61,    61,    10,    45,    10,    44,    81,    10,    17,
      45,    67,    51,    10,    45,    50,    81,    51,    10
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    60,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    64,    64,    64,    64,    64,
      65,    66,    66,    67,    67,    68,    69,    69,    70,    70,
      71,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    73,    73,    73,    73,    74,    74,    75,    76,
      76,    76,    77,    78,    78,    79,    79,    80,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    81,    81,    81,    81,    81,    81,    81
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     5,     3,     5,     8,     1,     1,
       6,     6,     4,     3,     1,     8,     9,     4,     5,     3,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     5,     3,     3,     7,    11,     7,     5,
       5,     4,     8,     7,     6,     3,     0,     7,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     2
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
#line 53 "parser.y"
                                                    { yylineno = 1; }
#line 1345 "parser.tab.c"
    break;

  case 15: /* declaration: DATA_TYPE IDENTIFICADOR S_PUNTO_COMA  */
#line 83 "parser.y"
                                                                                  { /* VARIABLE SIN VALOR*/ }
#line 1351 "parser.tab.c"
    break;

  case 16: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL expr S_PUNTO_COMA  */
#line 84 "parser.y"
                                                                             { /* VARIABLE CON VALOR O SI EXPR ES IDENTIFICADOR ES EL CASTEO WIDENING */ }
#line 1357 "parser.tab.c"
    break;

  case 17: /* declaration: DATA_TYPE IDENTIFICADOR S_IGUAL PARENTESIS_OPEN DATA_TYPE PARENTESIS_CLOSE IDENTIFICADOR S_PUNTO_COMA  */
#line 85 "parser.y"
                                                                                                                    { /* CASTEO NARROWING*/ }
#line 1363 "parser.tab.c"
    break;

  case 21: /* vector_type: NEW_WORD DATA_TYPE CORCHETE_OPEN expr CORCHETE_CLOSE S_PUNTO_COMA  */
#line 96 "parser.y"
                                                                              { /* VECTOR AUTO */ }
#line 1369 "parser.tab.c"
    break;

  case 22: /* vector_type: LLAVE_OPEN vector_values LLAVE_CLOSE S_PUNTO_COMA  */
#line 97 "parser.y"
                                                                        { /* VECTOR CON VALORES */ }
#line 1375 "parser.tab.c"
    break;

  case 30: /* asignation: IDENTIFICADOR op_expr expr S_PUNTO_COMA  */
#line 128 "parser.y"
                                                                { /* OPERADOR ASIGNACION PARA UNA VARIABLE*/ }
#line 1381 "parser.tab.c"
    break;

  case 42: /* native_func: IDENTIFICADOR FUNC_EQUALS PARENTESIS_OPEN IDENTIFICADOR PARENTESIS_CLOSE  */
#line 149 "parser.y"
                                                                                                {/* EQUALS PARA UNA VARIABLE */}
#line 1387 "parser.tab.c"
    break;

  case 43: /* native_func: IDENTIFICADOR FUNC_EQUALS PARENTESIS_OPEN STRING_COMILLAS PARENTESIS_CLOSE  */
#line 150 "parser.y"
                                                                                                {/* EQUALS PARA UN TEXTO EN COMILLAS */}
#line 1393 "parser.tab.c"
    break;

  case 44: /* native_func: IDENTIFICADOR OP_AUMENTO S_PUNTO_COMA  */
#line 151 "parser.y"
                                                                                                {/* AUMENTADOR DE VARIABLE PARA BUCLES*/}
#line 1399 "parser.tab.c"
    break;

  case 45: /* native_func: IDENTIFICADOR OP_DECREMENTO S_PUNTO_COMA  */
#line 152 "parser.y"
                                                                                                {/* REDUCTOR DE VARIABLE PARA BUCLES*/}
#line 1405 "parser.tab.c"
    break;

  case 49: /* for_condition: declaration expr S_PUNTO_COMA IDENTIFICADOR OP_AUMENTO  */
#line 168 "parser.y"
                                                                                                  {/* ESTRUCTURA FOR NORMAL */}
#line 1411 "parser.tab.c"
    break;

  case 50: /* for_condition: declaration expr S_PUNTO_COMA IDENTIFICADOR OP_DECREMENTO  */
#line 169 "parser.y"
                                                                                                  {/* ESTRUCTURA FOR NORMAL */}
#line 1417 "parser.tab.c"
    break;

  case 51: /* for_condition: DATA_TYPE IDENTIFICADOR S_PUNTO_PUNTO IDENTIFICADOR  */
#line 170 "parser.y"
                                                                                                  {/* ESTRUCTURA FOR EACH */}
#line 1423 "parser.tab.c"
    break;


#line 1427 "parser.tab.c"

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

#line 220 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Error: sintáctico en linea: %d\n", yylineno);
}
