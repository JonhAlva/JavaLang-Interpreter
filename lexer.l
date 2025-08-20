%{
    #include "parser.tab.h"
    #include <string.h>
    #include <stdlib.h>
%}

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
"true"                  { yylval.bool_true = 1; return BOOL_VALUE; }
"false"                 { yylval.bool_true = 0; return BOOL_VALUE; }

";"                     { return S_PUNTO_COMA; }
"="                     { return S_IGUAL; }

"+"                     { return '+'; }                               /* Reconocimiento de simbolos */
"-"                     { return '-'; }
"*"                     { return '*'; }
"/"                     { return '/'; }

[0-9]+"."[0-9]+         { yylval.float_number = atof(yytext); return FLOAT_NUMBER; } /* Reconocimiento de identificadores */
[0-9]+                  { yylval.int_number = atoi(yytext); return INT_NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.identificador = strdup(yytext); return IDENTIFICADOR; }
\"([^\"\r\n]|\"\")*\"   { yylval.string_comillas = strdup(yytext); return STRING_COMILLAS; }

.                       { printf("Error: caracter inesperado %s\n", yytext); return yytext[0]; }

%%

int yywrap() {
    return 1;
}