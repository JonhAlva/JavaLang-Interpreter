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
    DATA_TYPE = 258,               /* DATA_TYPE  */
    S_PUNTO_COMA = 259,            /* S_PUNTO_COMA  */
    S_IGUAL = 260,                 /* S_IGUAL  */
    PARENTESIS_OPEN = 261,         /* PARENTESIS_OPEN  */
    PARENTESIS_CLOSE = 262,        /* PARENTESIS_CLOSE  */
    S_PUNTO_PUNTO = 263,           /* S_PUNTO_PUNTO  */
    SWITCH_WORD = 264,             /* SWITCH_WORD  */
    CASE_WORD = 265,               /* CASE_WORD  */
    BREAK_WORD = 266,              /* BREAK_WORD  */
    OP_MAS_IGUAL = 267,            /* OP_MAS_IGUAL  */
    OP_MENOS_IGUAL = 268,          /* OP_MENOS_IGUAL  */
    OP_MULTI_IGUAL = 269,          /* OP_MULTI_IGUAL  */
    OP_DIV_IGUAL = 270,            /* OP_DIV_IGUAL  */
    OP_MOD_IGUAL = 271,            /* OP_MOD_IGUAL  */
    OP_AND_IGUAL = 272,            /* OP_AND_IGUAL  */
    DEFAULT_WORD = 273,            /* DEFAULT_WORD  */
    WHILE_WORD = 274,              /* WHILE_WORD  */
    OP_AUMENTO = 275,              /* OP_AUMENTO  */
    OP_DECREMENTO = 276,           /* OP_DECREMENTO  */
    OP_OR_IGUAL = 277,             /* OP_OR_IGUAL  */
    OP_POT_IGUAL = 278,            /* OP_POT_IGUAL  */
    OP_MAYOR_IGUAL = 279,          /* OP_MAYOR_IGUAL  */
    OP_MENOR_IGUAL = 280,          /* OP_MENOR_IGUAL  */
    PRINT_SENTENCE = 281,          /* PRINT_SENTENCE  */
    FUNC_EQUALS = 282,             /* FUNC_EQUALS  */
    IF_WORD = 283,                 /* IF_WORD  */
    LLAVE_OPEN = 284,              /* LLAVE_OPEN  */
    LLAVE_CLOSE = 285,             /* LLAVE_CLOSE  */
    ELSE_WORD = 286,               /* ELSE_WORD  */
    FOR_WORD = 287,                /* FOR_WORD  */
    CONTINUE_WORD = 288,           /* CONTINUE_WORD  */
    RETURN_WORD = 289,             /* RETURN_WORD  */
    CORCHETE_OPEN = 290,           /* CORCHETE_OPEN  */
    CORCHETE_CLOSE = 291,          /* CORCHETE_CLOSE  */
    NEW_WORD = 292,                /* NEW_WORD  */
    COMA = 293,                    /* COMA  */
    PARSE_INT = 294,               /* PARSE_INT  */
    PARSE_FLOAT = 295,             /* PARSE_FLOAT  */
    PARSE_DOUBLE = 296,            /* PARSE_DOUBLE  */
    PARSE_STRING = 297,            /* PARSE_STRING  */
    JOIN_STRING = 298,             /* JOIN_STRING  */
    ARRAY_INDEX = 299,             /* ARRAY_INDEX  */
    FUNC_LENGTH = 300,             /* FUNC_LENGTH  */
    FUNC_ADD = 301,                /* FUNC_ADD  */
    MAIN_STRING = 302,             /* MAIN_STRING  */
    LOGIC_NOT = 303,               /* LOGIC_NOT  */
    INT_NUMBER = 304,              /* INT_NUMBER  */
    OP_MENOR_A = 305,              /* OP_MENOR_A  */
    OP_MAYOR_A = 306,              /* OP_MAYOR_A  */
    FLOAT_NUMBER = 307,            /* FLOAT_NUMBER  */
    IDENTIFICADOR = 308,           /* IDENTIFICADOR  */
    STRING_COMILLAS = 309,         /* STRING_COMILLAS  */
    BOOL_VALUE = 310,              /* BOOL_VALUE  */
    NULL_VALUE = 311,              /* NULL_VALUE  */
    OP_MENOR_IGUAL_A = 312,        /* OP_MENOR_IGUAL_A  */
    OP_MAYOR_IGUAL_A = 313,        /* OP_MAYOR_IGUAL_A  */
    OP_IGUAL_IGUAL = 314,          /* OP_IGUAL_IGUAL  */
    OP_DISTINTO_A = 315,           /* OP_DISTINTO_A  */
    LOGIC_AND = 316,               /* LOGIC_AND  */
    LOGIC_OR = 317                 /* LOGIC_OR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 15 "parser.y"

    struct Nodo* nodo;
    int int_number;
    float float_number;
    char* identificador;
    char* string_comillas;
    char* operador;
    int bool_true;  /* 0 = false, 1 = true */
    char* null_value;

#line 137 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
