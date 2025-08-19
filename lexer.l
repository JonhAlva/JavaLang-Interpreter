%{
    #include "parser.tab.h"
%}

/*Reconocimiento de Tokes o patrones*/
%%

"int"                   { return DATA_TYPE; }                           /* Reconocimiento de  palabras reservadas */
"float"                 { return DATA_TYPE; }
"boolean"               { return DATA_TYPE; }
"char"                  { return DATA_TYPE; }
"String"                { return DATA_TYPE; }
"true"                  { return BOOL_TRUE; }
"false"                 { return BOOL_FALSE; }

"+"                     { return S_MAS; }                               /* Reconocimiento de simbolos */
"-"                     { return S_MENOS; }
"*"                     { return S_MULTI; }
"/"                     { return S_DIVIDIR; }
";"                     { return S_PUNTO_COMA; }
"="                     { return S_IGUAL; }

"//".*                  {/* Ignora comentarios de una linea*/}
"/*"([^*]|\n)*"*/"      { /* Ignora comentario multilinea */ }

[0-9]+"."[0-9]+         { yylval = atoi(yytext); return FLOAT_NUMBER; } /* Reconocimiento de identificadores */
[0-9]+                  { yylval = atoi(yytext); return INT_NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval = atoi(yytext); return IDENTIFICADOR; }
\"[^\"]*\"              { yylval = atoi(yytext); return STRING_COMILLAS; }

\n                      { return SALTO_LINEA; }    
[ \t]+                  { /*Ignora tabulaciones y espacios*/ }
.                       { printf("Error: caracter inesperado %s\n", yytext); }

%%

int yywrap() {
    return 1;
}