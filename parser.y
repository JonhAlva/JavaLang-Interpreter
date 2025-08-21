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
%token DATA_TYPE S_PUNTO_COMA S_IGUAL PARENTESIS_OPEN PARENTESIS_CLOSE
%token OP_MAS_IGUAL OP_MENOS_IGUAL OP_MULTI_IGUAL OP_DIV_IGUAL OP_MOD_IGUAL OP_AND_IGUAL 
%token OP_OR_IGUAL OP_POT_IGUAL OP_MAYOR_IGUAL OP_MENOR_IGUAL OP_IGUAL_IGUAL OP_DISTINTO_A OP_MENOR_IGUAL_A OP_MAYOR_IGUAL_A LOGIC_OR
%token LOGIC_AND OP_MENOR_A OP_MAYOR_A LOGIC_NOT PRINT_SENTENCE

//Nombre de las producciones y su tipo de retorno {INT, FLOAT, BOOLEAN... etc}


// Precedencia de Operadores
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
;

// * FUNCION DE IMPRIMIR VALORES -------------------------------------------------------------------------------

print:
    PRINT_SENTENCE print_values
;

// ! POSIBLES CASOS QUE PUEDE LLEGAR A IMPRIMIR
print_values:
        expr
;

// * DECLARACION DE VARIABLES -----------------------------------------------------------------------------------

declaration:
            DATA_TYPE IDENTIFICADOR S_PUNTO_COMA                                  { /* VARIABLE SIN VALOR*/ }
            | DATA_TYPE IDENTIFICADOR S_IGUAL expr S_PUNTO_COMA              { /* VARIABLE CON VALOR*/ }
;


// * ASIGNACION DE VARIABLES ------------------------------------------------------------------------------------

asignation:
            IDENTIFICADOR op_expr expr S_PUNTO_COMA             { /* OPERADOR ASIGNACION */ }
            | DATA_TYPE IDENTIFICADOR S_IGUAL IDENTIFICADOR S_PUNTO_COMA          { /* CASTEO WIDENING*/ }
            | DATA_TYPE IDENTIFICADOR S_IGUAL PARENTESIS_OPEN DATA_TYPE PARENTESIS_CLOSE IDENTIFICADOR S_PUNTO_COMA
            { /* CASTEO NARROWING*/ }
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