%{
    #include <stdio.h>
    #include <stdlib.h>

    extern int yylex();
    extern int yylineno;
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
%token DATA_TYPE S_PUNTO_COMA S_IGUAL PARENTESIS_OPEN PARENTESIS_CLOSE S_PUNTO_PUNTO SWITCH_WORD CASE_WORD BREAK_WORD
%token OP_MAS_IGUAL OP_MENOS_IGUAL OP_MULTI_IGUAL OP_DIV_IGUAL OP_MOD_IGUAL OP_AND_IGUAL DEFAULT_WORD WHILE_WORD
%token OP_OR_IGUAL OP_POT_IGUAL OP_MAYOR_IGUAL OP_MENOR_IGUAL OP_IGUAL_IGUAL OP_DISTINTO_A OP_MENOR_IGUAL_A OP_MAYOR_IGUAL_A LOGIC_OR
%token LOGIC_AND OP_MENOR_A OP_MAYOR_A LOGIC_NOT PRINT_SENTENCE FUNC_EQUALS IF_WORD LLAVE_OPEN LLAVE_CLOSE ELSE_WORD

//Nombre de las producciones y su tipo de retorno {INT, FLOAT, BOOLEAN... etc}


// Precedencia de Operadores
%left LOGIC_OR
%left LOGIC_AND
%left OP_IGUAL_IGUAL OP_DISTINTO_A
%left OP_MENOR_A OP_MAYOR_A OP_MENOR_IGUAL_A OP_MAYOR_IGUAL_A
%left '+' '-'
%left '*' '/' '%'
%right LOGIC_NOT

// Nombre de la produccion donde empezara el analisis sintactico
%start input

%%

input:
        lista_instrucciones                         { yylineno = 1; }
;

lista_instrucciones:
            lista_instrucciones instruccion 
            | instruccion
;

instruccion:
            declaration
            | asignation
            | print
            | if_sentence
            | switch_case
            | while_sentence
;

// * FUNCION DE IMPRIMIR VALORES -------------------------------------------------------------------------------

print:
    PRINT_SENTENCE PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA
    | PRINT_SENTENCE PARENTESIS_OPEN native_func PARENTESIS_CLOSE S_PUNTO_COMA
;


// * DECLARACION DE VARIABLES -----------------------------------------------------------------------------------

declaration:
            DATA_TYPE IDENTIFICADOR S_PUNTO_COMA                                  { /* VARIABLE SIN VALOR*/ }
            | DATA_TYPE IDENTIFICADOR S_IGUAL expr S_PUNTO_COMA              { /* VARIABLE CON VALOR O SI EXPR ES IDENTIFICADOR ES EL CASTEO WIDENING */ }
            | DATA_TYPE IDENTIFICADOR S_IGUAL PARENTESIS_OPEN DATA_TYPE PARENTESIS_CLOSE IDENTIFICADOR S_PUNTO_COMA
            { /* CASTEO NARROWING*/ }
;


// * ASIGNACION DE VARIABLES ------------------------------------------------------------------------------------

asignation:
            IDENTIFICADOR op_expr expr S_PUNTO_COMA             { /* OPERADOR ASIGNACION PARA UNA VARIABLE*/ }
;

// ! OPERADORES DE ASIGNACION POSIBLES CASOS
op_expr:
        S_IGUAL
        | OP_MAS_IGUAL
        | OP_MENOS_IGUAL
        | OP_MULTI_IGUAL
        | OP_DIV_IGUAL
        | OP_MOD_IGUAL
        | OP_AND_IGUAL
        | OP_OR_IGUAL
        | OP_POT_IGUAL
        | OP_MAYOR_IGUAL
        | OP_MENOR_IGUAL
;

// * FUNCIONES ESPECIALES O NATIVAS -------------------------------------------------------------------------------------

native_func:
            IDENTIFICADOR FUNC_EQUALS PARENTESIS_OPEN IDENTIFICADOR PARENTESIS_CLOSE            {/* EQUALS PARA UNA VARIABLE */}
            | IDENTIFICADOR FUNC_EQUALS PARENTESIS_OPEN STRING_COMILLAS PARENTESIS_CLOSE        {/* EQUALS PARA UN TEXTO EN COMILLAS */}
            | IDENTIFICADOR '+' '+'                                                             {/* AUMENTADOR DE VARIABLE PARA BUCLES*/}
            | IDENTIFICADOR '-' '-'                                                             {/* REDUCTOR DE VARIABLE PARA BUCLES*/}
;

// * CONDICIONALES IF ELSE ---------------------------------------------------------------------------------------------
if_sentence:
            IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE
            | IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE ELSE_WORD LLAVE_OPEN lista_instrucciones LLAVE_CLOSE
;

// * CONDICIONAL SWITCH CASE -----------------------------------------------------------------------------------------------
switch_case:
            SWITCH_WORD PARENTESIS_OPEN IDENTIFICADOR PARENTESIS_CLOSE LLAVE_OPEN switch_case_list switch_default LLAVE_CLOSE
;

switch_case_list:
                switch_case_list CASE_WORD expr S_PUNTO_PUNTO lista_instrucciones BREAK_WORD S_PUNTO_COMA
                | CASE_WORD expr S_PUNTO_PUNTO lista_instrucciones BREAK_WORD S_PUNTO_COMA
;

switch_default:
                DEFAULT_WORD S_PUNTO_PUNTO lista_instrucciones
                | /* vacío */
;

// * CONDICIONAL WHILE ----------------------------------------------------------------------------------------------------
while_sentence:
                WHILE_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE
;

// * EXPRESIONES GLOBALES QUE INTERPRETAN ARITMETICA, OPERADORES LOGICOS Y ALGUNAS ASIGNACIONES ------------------
expr:
    expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | expr '%' expr
    | PARENTESIS_OPEN expr PARENTESIS_CLOSE
    | INT_NUMBER
    | FLOAT_NUMBER
    | STRING_COMILLAS
    | BOOL_VALUE
    | NULL_VALUE
    | IDENTIFICADOR
    | expr OP_MENOR_A expr
    | expr OP_MAYOR_A expr
    | expr OP_MENOR_IGUAL_A expr
    | expr OP_MAYOR_IGUAL_A expr
    | expr OP_IGUAL_IGUAL expr
    | expr OP_DISTINTO_A expr
    | expr LOGIC_AND expr
    | expr LOGIC_OR expr
    | LOGIC_NOT expr
;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: sintáctico en linea: %d\n", yylineno);
}