/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    S_PUNTO_COMA = 258,            /* S_PUNTO_COMA  */
    PARENTESIS_OPEN = 259,         /* PARENTESIS_OPEN  */
    PARENTESIS_CLOSE = 260,        /* PARENTESIS_CLOSE  */
    S_PUNTO_PUNTO = 261,           /* S_PUNTO_PUNTO  */
    SWITCH_WORD = 262,             /* SWITCH_WORD  */
    CASE_WORD = 263,               /* CASE_WORD  */
    BREAK_WORD = 264,              /* BREAK_WORD  */
    DEFAULT_WORD = 265,            /* DEFAULT_WORD  */
    WHILE_WORD = 266,              /* WHILE_WORD  */
    OP_AUMENTO = 267,              /* OP_AUMENTO  */
    OP_DECREMENTO = 268,           /* OP_DECREMENTO  */
    PRINT_SENTENCE = 269,          /* PRINT_SENTENCE  */
    FUNC_EQUALS = 270,             /* FUNC_EQUALS  */
    IF_WORD = 271,                 /* IF_WORD  */
    LLAVE_OPEN = 272,              /* LLAVE_OPEN  */
    LLAVE_CLOSE = 273,             /* LLAVE_CLOSE  */
    ELSE_WORD = 274,               /* ELSE_WORD  */
    FOR_WORD = 275,                /* FOR_WORD  */
    CONTINUE_WORD = 276,           /* CONTINUE_WORD  */
    RETURN_WORD = 277,             /* RETURN_WORD  */
    CORCHETE_OPEN = 278,           /* CORCHETE_OPEN  */
    CORCHETE_CLOSE = 279,          /* CORCHETE_CLOSE  */
    NEW_WORD = 280,                /* NEW_WORD  */
    COMA = 281,                    /* COMA  */
    PARSE_INT = 282,               /* PARSE_INT  */
    PARSE_FLOAT = 283,             /* PARSE_FLOAT  */
    PARSE_DOUBLE = 284,            /* PARSE_DOUBLE  */
    PARSE_STRING = 285,            /* PARSE_STRING  */
    JOIN_STRING = 286,             /* JOIN_STRING  */
    ARRAY_INDEX = 287,             /* ARRAY_INDEX  */
    FUNC_LENGTH = 288,             /* FUNC_LENGTH  */
    FUNC_ADD = 289,                /* FUNC_ADD  */
    MAIN_STRING = 290,             /* MAIN_STRING  */
    FLOAT_SUFFIX = 291,            /* FLOAT_SUFFIX  */
    LOGIC_NOT = 292,               /* LOGIC_NOT  */
    INT_NUMBER = 293,              /* INT_NUMBER  */
    OP_MENOR_A = 294,              /* OP_MENOR_A  */
    OP_MAYOR_A = 295,              /* OP_MAYOR_A  */
    FLOAT_NUMBER = 296,            /* FLOAT_NUMBER  */
    STRING_COMILLAS = 297,         /* STRING_COMILLAS  */
    BOOL_VALUE = 298,              /* BOOL_VALUE  */
    NULL_VALUE = 299,              /* NULL_VALUE  */
    OP_MENOR_IGUAL_A = 300,        /* OP_MENOR_IGUAL_A  */
    OP_MAYOR_IGUAL_A = 301,        /* OP_MAYOR_IGUAL_A  */
    OP_IGUAL_IGUAL = 302,          /* OP_IGUAL_IGUAL  */
    OP_DISTINTO_A = 303,           /* OP_DISTINTO_A  */
    LOGIC_AND = 304,               /* LOGIC_AND  */
    LOGIC_OR = 305,                /* LOGIC_OR  */
    IDENTIFICADOR = 306,           /* IDENTIFICADOR  */
    S_IGUAL = 307,                 /* S_IGUAL  */
    OP_MAS_IGUAL = 308,            /* OP_MAS_IGUAL  */
    OP_MENOS_IGUAL = 309,          /* OP_MENOS_IGUAL  */
    OP_MULTI_IGUAL = 310,          /* OP_MULTI_IGUAL  */
    OP_DIV_IGUAL = 311,            /* OP_DIV_IGUAL  */
    OP_MOD_IGUAL = 312,            /* OP_MOD_IGUAL  */
    OP_AND_IGUAL = 313,            /* OP_AND_IGUAL  */
    OP_OR_IGUAL = 314,             /* OP_OR_IGUAL  */
    OP_POT_IGUAL = 315,            /* OP_POT_IGUAL  */
    OP_MAYOR_IGUAL = 316,          /* OP_MAYOR_IGUAL  */
    OP_MENOR_IGUAL = 317,          /* OP_MENOR_IGUAL  */
    DATA_TYPE = 318                /* DATA_TYPE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser.y"

    struct Nodo* nodo;
    int int_number;
    float float_number;
    char* identificador;
    char* string_comillas;
    char* operador;
    int bool_true;  /* 0 = false, 1 = true */
    char* null_value;
    char* data_type;
    struct Nodo** lista_nodos;

#line 140 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
