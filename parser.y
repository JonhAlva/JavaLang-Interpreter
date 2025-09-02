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
%token OP_MAS_IGUAL OP_MENOS_IGUAL OP_MULTI_IGUAL OP_DIV_IGUAL OP_MOD_IGUAL OP_AND_IGUAL DEFAULT_WORD WHILE_WORD OP_AUMENTO OP_DECREMENTO
%token OP_OR_IGUAL OP_POT_IGUAL OP_MAYOR_IGUAL OP_MENOR_IGUAL OP_IGUAL_IGUAL OP_DISTINTO_A OP_MENOR_IGUAL_A OP_MAYOR_IGUAL_A LOGIC_OR
%token LOGIC_AND OP_MENOR_A OP_MAYOR_A LOGIC_NOT PRINT_SENTENCE FUNC_EQUALS IF_WORD LLAVE_OPEN LLAVE_CLOSE ELSE_WORD FOR_WORD
%token CONTINUE_WORD RETURN_WORD CORCHETE_OPEN CORCHETE_CLOSE NEW_WORD COMA PARSE_INT PARSE_FLOAT PARSE_DOUBLE PARSE_STRING

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
            | native_func
            | switch_case
            | while_sentence
            | for_sentence
            | function_sentence
;

// * FUNCION DE IMPRIMIR VALORES -------------------------------------------------------------------------------

print:
    PRINT_SENTENCE PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA
    | PRINT_SENTENCE PARENTESIS_OPEN native_func PARENTESIS_CLOSE S_PUNTO_COMA
;


// * DECLARACION DE VARIABLES Y ESTRUCTURAS DE DATOS -----------------------------------------------------------------------------------

declaration:
            DATA_TYPE IDENTIFICADOR S_PUNTO_COMA                                  { /* VARIABLE SIN VALOR*/ }
            | DATA_TYPE IDENTIFICADOR S_IGUAL expr S_PUNTO_COMA              { /* VARIABLE CON VALOR O SI EXPR ES IDENTIFICADOR ES EL CASTEO WIDENING */ }
            | DATA_TYPE IDENTIFICADOR S_IGUAL PARENTESIS_OPEN DATA_TYPE PARENTESIS_CLOSE IDENTIFICADOR S_PUNTO_COMA { /* CASTEO NARROWING*/ }
            | vector
            | matriz
            | dynamic_array
            | DATA_TYPE IDENTIFICADOR S_IGUAL variable_access S_PUNTO_COMA
            | DATA_TYPE IDENTIFICADOR S_IGUAL IDENTIFICADOR PARENTESIS_OPEN function_parameters PARENTESIS_CLOSE S_PUNTO_COMA
            | DATA_TYPE IDENTIFICADOR S_IGUAL parse_expretion PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA

;

parse_expretion:
                PARSE_INT
                | PARSE_DOUBLE
                | PARSE_FLOAT
                | PARSE_STRING
;

string_join:
            
;

// ! DECLARACION DE VECTOR
vector:
        DATA_TYPE CORCHETE_OPEN CORCHETE_CLOSE IDENTIFICADOR S_IGUAL vector_type 

// ! LAS DOS MANERAS DE QUE PUEDEN INGRESAR UN VECTOR
vector_type:
            NEW_WORD DATA_TYPE CORCHETE_OPEN expr CORCHETE_CLOSE S_PUNTO_COMA { /* VECTOR AUTO */ }
            | LLAVE_OPEN vector_values LLAVE_CLOSE S_PUNTO_COMA         { /* VECTOR CON VALORES */ }
;
;

// ! RECURSIVA PARA VECTOR, TOMAR VALORES INGRESADOS POR COMAS
vector_values:
            vector_values COMA expr
            | expr
;

// ! DECLARACION DE MATRIZ
matriz:
        DATA_TYPE CORCHETE_OPEN CORCHETE_CLOSE CORCHETE_OPEN CORCHETE_CLOSE IDENTIFICADOR S_IGUAL matriz_type
;

// ! LAS DOS MANERAS QUE PUEDEN INGRESAR UNA MATRIZ
matriz_type:
            NEW_WORD DATA_TYPE CORCHETE_OPEN expr CORCHETE_CLOSE CORCHETE_OPEN expr CORCHETE_CLOSE S_PUNTO_COMA
            | LLAVE_OPEN matriz_values LLAVE_CLOSE S_PUNTO_COMA
;

// ! RECURSIVA PARA MATRIZ, TOMAR VALORES INGRESADOS EN APARTADOS POR COMAS
matriz_values:
            matriz_values COMA LLAVE_OPEN vector_values LLAVE_CLOSE 
            | LLAVE_OPEN vector_values LLAVE_CLOSE 
;

// ! DECLARACION DE ARRAY MULTIDIMENSIONAL
dynamic_array:
            DATA_TYPE IDENTIFICADOR dynamic_corchete S_IGUAL NEW_WORD DATA_TYPE dynamic_data_declaration S_PUNTO_COMA
;

dynamic_corchete:
                dynamic_corchete CORCHETE_OPEN CORCHETE_CLOSE
                | CORCHETE_OPEN CORCHETE_CLOSE
;

dynamic_data_declaration:
                        dynamic_data_declaration CORCHETE_OPEN expr CORCHETE_CLOSE
                        | CORCHETE_OPEN expr CORCHETE_CLOSE
;

// * ASIGNACION DE VARIABLES ------------------------------------------------------------------------------------

asignation:
            IDENTIFICADOR op_expr expr_bridge S_PUNTO_COMA             { /* 'OPERADOR ASIGNACION' PARA UNA VARIABLE Y ASIGNACION NORMAL*/ }
            | variable_access S_IGUAL expr S_PUNTO_COMA                { /* ASIGNACION DE UN VALOR VECTOR, MATRIZ*/}
;

// ! PRODUCCION ENCARGADA DE DECIDIR SI SOLO VIENE UNA EXPRESION O ALGUN VALOR DE ASIGNACION DE VECTORES
expr_bridge:
        expr
        | variable_access
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
            IDENTIFICADOR FUNC_EQUALS PARENTESIS_OPEN expr PARENTESIS_CLOSE            {/* PRINT FUNC .EQUALS PARA UNA VARIABLE */}
            | IDENTIFICADOR OP_AUMENTO S_PUNTO_COMA                                             {/* AUMENTADOR DE VARIABLE PARA BUCLES*/}
            | IDENTIFICADOR OP_DECREMENTO S_PUNTO_COMA                                          {/* REDUCTOR DE VARIABLE PARA BUCLES*/}
            | CONTINUE_WORD S_PUNTO_COMA
            | BREAK_WORD S_PUNTO_COMA
            | RETURN_WORD S_PUNTO_COMA
            | RETURN_WORD expr S_PUNTO_COMA
            | IDENTIFICADOR PARENTESIS_OPEN PARENTESIS_CLOSE S_PUNTO_COMA
;

// ! PRODUCCION QUE MANEJA LA FORMA DE ESCRITURA DE LOS VECTORES Y LAS MATRICES
variable_access:
                IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE                 {/* ACCESO A VALOR EN UN VECTOR*/}
                | IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE CORCHETE_OPEN expr CORCHETE_CLOSE     {/* ACCESO A VALOR EN UNA MATRIZ */}
;

// * CONDICIONALES IF ELSE ---------------------------------------------------------------------------------------------
if_sentence:
            IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE
            | IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE ELSE_WORD LLAVE_OPEN lista_instrucciones LLAVE_CLOSE
;

// * CICLO FOR ----------------------------------------------------------------------------------------------------------
for_sentence:
            FOR_WORD PARENTESIS_OPEN for_condition PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE
; 

// ! CONDICIONES DEL FOR PARA DIFERENCIAR ENTRE FOR NORMAL O UN FOR EACH PARA LISTAS
for_condition:
            declaration expr S_PUNTO_COMA IDENTIFICADOR OP_AUMENTO                                {/* ESTRUCTURA FOR NORMAL */}
            | declaration expr S_PUNTO_COMA IDENTIFICADOR OP_DECREMENTO                           {/* ESTRUCTURA FOR NORMAL */}
            | DATA_TYPE IDENTIFICADOR S_PUNTO_PUNTO IDENTIFICADOR                                 {/* ESTRUCTURA FOR EACH */}
;

// * CONDICIONAL SWITCH CASE -----------------------------------------------------------------------------------------------
switch_case:
            SWITCH_WORD PARENTESIS_OPEN IDENTIFICADOR PARENTESIS_CLOSE LLAVE_OPEN switch_case_list switch_default LLAVE_CLOSE
;

// ! RECURSIVIDAD PARA INDEFINIDOS CASOS DE 'CASE'
switch_case_list:
                switch_case_list CASE_WORD expr S_PUNTO_PUNTO lista_instrucciones BREAK_WORD S_PUNTO_COMA
                | CASE_WORD expr S_PUNTO_PUNTO lista_instrucciones BREAK_WORD S_PUNTO_COMA
;

// ! CONDICIONAL DEL CASO 'DEFAULT' QUE PUEDE O NO VENIR
switch_default:
                DEFAULT_WORD S_PUNTO_PUNTO lista_instrucciones
                | /* vacío */
;

// * CONDICIONAL WHILE ----------------------------------------------------------------------------------------------------
while_sentence:
                WHILE_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE
;

// * DECLARACION DE FUNCIONES ----------------------------------------------------------------------------------------------------
function_sentence:
                    DATA_TYPE IDENTIFICADOR PARENTESIS_OPEN parameters_bridge PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE
;

// ! PUENTE PARA QUE EL PARSER DECIDA SI VIENEN O NO PARAMETROS
parameters_bridge:
                    function_parameters
                    | {/* vaćio */}
;

// ! RECURSIVA DE PARAMETROS 
function_parameters:
                    function_parameters COMA function_expr
                    | function_expr
;

function_expr:
            expr
            | DATA_TYPE IDENTIFICADOR
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