%{
    #include <stdio.h>
    #include <stdlib.h>

    void yyerror(const char* s);
    int yylex();
%}

//Aqui tiene que ir el nombre del return del lexer para cada token
%token FLOAT_NUMBER INT_NUMBER IDENTIFICADOR BOOL_TRUE BOOL_FALSE DATA_TYPE
%token S_MAS S_MENOS S_MULTI S_DIVIDIR SALTO_LINEA S_PUNTO_COMA S_IGUAL STRING_COMILLAS

// Precedencia de Operadores
%left '+' '-'
%left '*' '/'

// Nombre de la produccion donde empezara el analisis sintactico
%start input

%%

input:
        instrucciones SALTO_LINEA            { printf("cadena obteninda: %s\n", $1); }
;

instrucciones:
            instrucciones instruccion
            | instruccion
;

instruccion:
            declaration
;

// * DECLARACION DE VARIABLES -----------------------------------------------------------------------------------

declaration:
            DATA_TYPE IDENTIFICADOR S_IGUAL operation S_PUNTO_COMA 
; 

operation:
            INT_NUMBER
            | FLOAT_NUMBER
            | BOOL_FALSE
            | BOOL_TRUE
            | IDENTIFICADOR
            | STRING_COMILLAS
;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: %s\n", s);
}