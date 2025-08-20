%{
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();
    void yyerror(const char* s);
%}

//Declaracion de Union para diferenciar el tipo de dato yyval.{NOMBRE}  <-
%union{
    int int_number;
    float float_number;
    char* identificador;
    char* string_comillas;
    int bool_true;  /* 0 = false, 1 = true */
}

//Tokens con tipo de dato
%token <int_number>         INT_NUMBER
%token <float_number>       FLOAT_NUMBER
%token <identificador>      IDENTIFICADOR
%token <string_comillas>    STRING_COMILLAS
%token <bool_true>          BOOL_VALUE

//Aqui tiene que ir el nombre del return del lexer para cada token
%token DATA_TYPE S_PUNTO_COMA S_IGUAL

//Nombre de las producciones y su tipo de retorno {INT, FLOAT, BOOLEAN... etc}


// Precedencia de Operadores
%left '+' '-'
%left '*' '/'

// Nombre de la produccion donde empezara el analisis sintactico
%start input

%%

input:
        lista_instrucciones
;

lista_instrucciones:
            lista_instrucciones instruccion 
            | instruccion
;

instruccion:
            declaration
;

// * DECLARACION DE VARIABLES -----------------------------------------------------------------------------------

declaration:
            DATA_TYPE IDENTIFICADOR S_PUNTO_COMA
            | DATA_TYPE IDENTIFICADOR S_IGUAL INT_NUMBER S_PUNTO_COMA
            | DATA_TYPE IDENTIFICADOR S_IGUAL FLOAT_NUMBER S_PUNTO_COMA
            | DATA_TYPE IDENTIFICADOR S_IGUAL STRING_COMILLAS S_PUNTO_COMA
            | DATA_TYPE IDENTIFICADOR S_IGUAL BOOL_VALUE S_PUNTO_COMA
;           

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: sintáctico: %s\n", s);
}