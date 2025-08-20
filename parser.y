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
    char* null_value;
}

//Tokens con tipo de dato
%token <int_number>         INT_NUMBER
%token <float_number>       FLOAT_NUMBER
%token <identificador>      IDENTIFICADOR
%token <string_comillas>    STRING_COMILLAS
%token <bool_true>          BOOL_VALUE
%token <null_value>         NULL_VALUE

//Aqui tiene que ir el nombre del return del lexer para cada token
%token DATA_TYPE S_PUNTO_COMA S_IGUAL PARENTESIS_OPEN PARENTESIS_CLOSE

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
            DATA_TYPE IDENTIFICADOR S_PUNTO_COMA                                  { /* VARIABLE SIN VALOR*/ }
            | DATA_TYPE IDENTIFICADOR S_IGUAL data_type S_PUNTO_COMA              { /* VARIABLE CON VALOR*/ }
            | DATA_TYPE IDENTIFICADOR S_IGUAL IDENTIFICADOR S_PUNTO_COMA          { /* CASTEO WIDENING*/ }
            | DATA_TYPE IDENTIFICADOR S_IGUAL PARENTESIS_OPEN DATA_TYPE PARENTESIS_CLOSE IDENTIFICADOR S_PUNTO_COMA
            { /* CASTEO NARROWING*/ }
;

data_type:
        INT_NUMBER
        | FLOAT_NUMBER
        | STRING_COMILLAS
        | BOOL_VALUE
        | NULL_VALUE
;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: sintáctico: %s\n", s);
}