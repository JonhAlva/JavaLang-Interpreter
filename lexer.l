%{
    #include "parser.tab.h"
    #include <string.h>
    #include <stdlib.h>
%}

%option yylineno
/*Reconocimiento de Tokes o patrones*/
%%

[ \t\r\n]+              { /*Ignora espacios en blanco*/ }
"//".*                  {/* Ignora comentarios de una linea*/}
"/*"([^*]|\n)*"*/"      { /* Ignora comentario multilinea */ }

"int"                   { return DATA_TYPE; }                           /* Reconocimiento de  palabras reservadas */
"float"                 { return DATA_TYPE; }
"boolean"               { return DATA_TYPE; }
"char"                  { return DATA_TYPE; }
"String"                { return DATA_TYPE; }
"System.out.println"    { return PRINT_SENTENCE; }
".equals"               { return FUNC_EQUALS; }
"if"                    { return IF_WORD; }
"else"                  { return ELSE_WORD; }
"switch"                { return SWITCH_WORD; }
"case"                  { return CASE_WORD; }
"break"                 { return BREAK_WORD; }
"continue"              { return CONTINUE_WORD; }
"return"                { return RETURN_WORD; }
"new"                   { return NEW_WORD;}
"default"               { return DEFAULT_WORD; }
"while"                 { return WHILE_WORD; }
"for"                   { return FOR_WORD; }
"true"                  { yylval.bool_true = 1; return BOOL_VALUE; }
"false"                 { yylval.bool_true = 0; return BOOL_VALUE; }
"null"                  { yylval.null_value = "-null"; return NULL_VALUE; }

";"                     { return S_PUNTO_COMA; }
":"                     { return S_PUNTO_PUNTO; }
"="                     { return S_IGUAL; }
"("                     { return PARENTESIS_OPEN; }
")"                     { return PARENTESIS_CLOSE; }
"{"                     { return LLAVE_OPEN; }
"}"                     { return LLAVE_CLOSE; }
"["                     { return CORCHETE_OPEN; }
"]"                     { return CORCHETE_CLOSE; }
","                     { return COMA; }

"=="                    { return OP_IGUAL_IGUAL; }
"!="                    { return OP_DISTINTO_A; }
"+="                    { return OP_MAS_IGUAL; }
"-="                    { return OP_MENOS_IGUAL; }
"*="                    { return OP_MULTI_IGUAL; }
"/="                    { return OP_DIV_IGUAL; }
"%="                    { return OP_MOD_IGUAL; }
"&="                    { return OP_AND_IGUAL; }
"|="                    { return OP_OR_IGUAL; }
"^="                    { return OP_POT_IGUAL; }
">>="                   { return OP_MAYOR_IGUAL; }
"<<="                   { return OP_MENOR_IGUAL; }

"++"                    { return OP_AUMENTO; }
"--"                    { return OP_DECREMENTO; }

"<="                    { return OP_MENOR_IGUAL_A; }
">="                    { return OP_MAYOR_IGUAL_A; }
"<"                     { return OP_MENOR_A; }
">"                     { return OP_MAYOR_A; }
"+"                     { return '+'; }                               /* Reconocimiento de simbolos */
"-"                     { return '-'; }
"*"                     { return '*'; }
"/"                     { return '/'; }
"%"                     { return '%'; }
"||"                    { return LOGIC_OR; }
"&&"                    { return LOGIC_AND; }
"!"                     { return LOGIC_NOT; }

[0-9]+"."[0-9]+         { yylval.float_number = atof(yytext); return FLOAT_NUMBER; } /* Reconocimiento de identificadores */
[0-9]+                  { yylval.int_number = atoi(yytext); return INT_NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.identificador = strdup(yytext); return IDENTIFICADOR; }
\"([^\"\r\n]|\"\")*\"   { yylval.string_comillas = strdup(yytext); return STRING_COMILLAS; }

.                       { printf("Error: caracter inesperado %s\n", yytext); return yytext[0]; }

%%

int yywrap() {
    return 1;
}