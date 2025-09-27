%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "./Functions/AST.h"

    extern int yylex();
    extern int yylineno;
    void yyerror(const char* s);  

    Nodo* raiz = NULL;
%}

//Declaracion de Union para diferenciar el tipo de dato yyval.{NOMBRE}  <-
%union{
    struct Nodo* nodo;
    int int_number;
    float float_number;
    char* identificador;
    char* string_comillas;
    char* operador;
    int bool_true;  /* 0 = false, 1 = true */
    char* null_value;
    char* data_type;
    struct Nodo** lista_nodos;
}

//Aqui tiene que ir el nombre del return del lexer para cada token
%token S_PUNTO_COMA PARENTESIS_OPEN PARENTESIS_CLOSE S_PUNTO_PUNTO SWITCH_WORD CASE_WORD BREAK_WORD
%token DEFAULT_WORD WHILE_WORD OP_AUMENTO OP_DECREMENTO
%token PRINT_SENTENCE FUNC_EQUALS IF_WORD LLAVE_OPEN LLAVE_CLOSE ELSE_WORD FOR_WORD
%token CONTINUE_WORD RETURN_WORD CORCHETE_OPEN CORCHETE_CLOSE COMA JOIN_STRING
%token ARRAY_INDEX FUNC_LENGTH FUNC_ADD MAIN_STRING FLOAT_SUFFIX

//Tokens con tipo de dato
%token <int_number>         LOGIC_NOT INT_NUMBER OP_MENOR_A OP_MAYOR_A '+' '-' '/' '*' '%'
%token <float_number>       FLOAT_NUMBER
%token <string_comillas>    STRING_COMILLAS PARSE_INT PARSE_FLOAT PARSE_DOUBLE PARSE_STRING
%token <bool_true>          BOOL_VALUE
%token <null_value>         NULL_VALUE
%token <operador>           OP_MENOR_IGUAL_A OP_MAYOR_IGUAL_A OP_IGUAL_IGUAL OP_DISTINTO_A LOGIC_AND LOGIC_OR
%token <identificador>      IDENTIFICADOR S_IGUAL OP_MAS_IGUAL OP_MENOS_IGUAL OP_MULTI_IGUAL OP_DIV_IGUAL OP_MOD_IGUAL OP_AND_IGUAL OP_OR_IGUAL OP_POT_IGUAL OP_MAYOR_IGUAL OP_MENOR_IGUAL
%token <data_type>          DATA_TYPE NEW_WORD

//Nombre de las producciones y su tipo de retorno {INT, FLOAT, BOOLEAN... etc}
%type <nodo> input lista_instrucciones instruccion declaration asignation print expr if_sentence while_sentence expr_bridge variable_access
%type <nodo> native_func vector_type string_join if_else_one vector matriz_type matriz for_condition for_sentence switch_default
%type <nodo> switch_case_one switch_case function_sentence array_funcs matrix_access
%type <identificador> op_expr parse_expretion for_option
%type <lista_nodos> vector_values if_else_chain matriz_values switch_case_list function_parameters_access function_parameters_declaration parameters_bridge

// Precedencia de Operadores
%left LOGIC_AND
%left LOGIC_OR
%left OP_IGUAL_IGUAL OP_DISTINTO_A
%left OP_MENOR_A OP_MAYOR_A OP_MENOR_IGUAL_A OP_MAYOR_IGUAL_A
%left '*' '/'
%left '+' '-' '%'
%right LOGIC_NOT
%precedence UMINUS

// Nombre de la produccion donde empezara el analisis sintactico
%start input

%%

input:
        lista_instrucciones                         { raiz = $1; yylineno = 1; }
;

lista_instrucciones:
            lista_instrucciones instruccion         { $$ = ListaInstrucciones($1, $2); }
            | instruccion                           { $$ = ListaInstrucciones($1, NULL); }  
;

instruccion:
            declaration             { $$ = $1; }
            | asignation            { $$ = $1; }
            | print                 { $$ = $1; }
            | if_sentence           { $$ = $1; }
            | native_func           { $$ = $1; }
            | switch_case           { $$ = $1; }
            | while_sentence        { $$ = $1; }
            | for_sentence          { $$ = $1; }
            | function_sentence     { $$ = $1; }
;

// * FUNCION DE IMPRIMIR VALORES -------------------------------------------------------------------------------

print:
    PRINT_SENTENCE PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA               { $$ = Print($3); }
    | PRINT_SENTENCE PARENTESIS_OPEN native_func PARENTESIS_CLOSE S_PUNTO_COMA      { $$ = Print($3); }
// * DECLARACION DE VARIABLES Y ESTRUCTURAS DE DATOS -----------------------------------------------------------------------------------

declaration:
            DATA_TYPE IDENTIFICADOR S_PUNTO_COMA 
            {  $$ = Var_Declaration($1, $2, Terminal_Null("DEFAULT")); /* VARIABLE SIN VALOR*/ }

            | DATA_TYPE IDENTIFICADOR S_IGUAL expr S_PUNTO_COMA                  
            { $$ = Var_Declaration($1, $2, $4); }  

            | DATA_TYPE IDENTIFICADOR S_IGUAL PARENTESIS_OPEN DATA_TYPE PARENTESIS_CLOSE IDENTIFICADOR S_PUNTO_COMA 
            { $$ = Casteo_Narrowing($1, $2, $5, $7); /* CASTEO NARROWING*/ }

            | vector                { $$ = $1; /* DECLARATION VECTOR */ }

            | matriz                { $$ = $1; /* MATRIZ */ }

            | dynamic_array         { $$ = Nodo_Vacio("DYNAMIC_ARRAY NO IMPLEMENTADO AUN"); /* DYNAMIC_ARRAY */ }

            | DATA_TYPE IDENTIFICADOR S_IGUAL variable_access S_PUNTO_COMA      
            { $$ = Vector_Asignation($1, $2, $4); /* ASIGNACION DE VARIABLE A VECTOR*/ }

            | DATA_TYPE IDENTIFICADOR S_IGUAL matrix_access S_PUNTO_COMA      
            { $$ = Matriz_Asignation($1, $2, $4); /* ASIGNACION DE VARIABLE A MATRIZ*/ }

            | DATA_TYPE IDENTIFICADOR S_IGUAL parse_expretion PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA 
            { $$ = Parse_Expression($2, $1, $4, $6); /* PARSEO DE TIPOS */ }

            | string_join  { $$ = $1; }

            | DATA_TYPE IDENTIFICADOR S_IGUAL array_funcs S_PUNTO_COMA  
            { $$ = Array_func_Declaration($1, $2, $4); /* FUNCIONES DE ARRAYS */ }

            | DATA_TYPE IDENTIFICADOR S_IGUAL IDENTIFICADOR PARENTESIS_OPEN PARENTESIS_CLOSE S_PUNTO_COMA  
            { $$ = Asignation_function_no_param($1, $2, $4); /* ASIGNACION DE VARIABLE A UNA FUNCION SIN PARAMETROS */ }
;

parse_expretion:
                PARSE_INT            { $$ = "int"; }
                | PARSE_DOUBLE       { $$ = "double"; }
                | PARSE_FLOAT        { $$ = "float"; }
                | PARSE_STRING       { $$ = "String"; }
;

string_join:
            DATA_TYPE IDENTIFICADOR S_IGUAL JOIN_STRING PARENTESIS_OPEN STRING_COMILLAS COMA vector_values PARENTESIS_CLOSE S_PUNTO_COMA
            { 
                if ($8[0]->tipo == NODO_IDENTIFICADOR) {
                    // Si es un identificador, retornarlo tal cual para evaluar luego
                    $$ = String_Join_Array($1, $2, $6, $8);
                } else { 
                    $$ = Var_Declaration($1, $2, Make_StringJoin($1, $6, $8)); 
                }
                
            }

;

array_funcs:
            ARRAY_INDEX PARENTESIS_OPEN IDENTIFICADOR COMA expr PARENTESIS_CLOSE
            { $$ = Array_Index_Of($3, $5); /* FUNCION INDEX OF PARA VECTORES */ }

            | IDENTIFICADOR FUNC_LENGTH
            { $$ = Array_Length($1); /* FUNCION LENGTH PARA VECTORES */ }
;

// ! DECLARACION DE VECTOR
vector:
        DATA_TYPE CORCHETE_OPEN CORCHETE_CLOSE IDENTIFICADOR S_IGUAL vector_type 
        { $$ = Declaration_Vector($1, $4, $6); /* REGRESAMOS EL NODO QUE GENERA */ }

// ! LAS DOS MANERAS DE QUE PUEDEN INGRESAR UN VECTOR
vector_type:
            NEW_WORD DATA_TYPE CORCHETE_OPEN INT_NUMBER CORCHETE_CLOSE S_PUNTO_COMA 
            { $$ = Vector_Auto($2, $4); }

            | LLAVE_OPEN vector_values LLAVE_CLOSE S_PUNTO_COMA         
            { $$ = Valores_Vector($2); /* VECTOR CON VALORES */ }

            | IDENTIFICADOR FUNC_ADD PARENTESIS_OPEN expr PARENTESIS_CLOSE S_PUNTO_COMA 
            { $$ = Array_Add_Ref($1, $4); /* FUNCION ADD EN VECTORES*/}
;

// ! RECURSIVA PARA VECTOR, TOMAR VALORES INGRESADOS POR COMAS
vector_values:
            vector_values COMA expr
            { $$ = Add_Valor_Vector($1, $3); }
            | expr
            { $$ = Lista_Vector($1); }
;

// ! DECLARACION DE MATRIZ
matriz:
        DATA_TYPE CORCHETE_OPEN CORCHETE_CLOSE CORCHETE_OPEN CORCHETE_CLOSE IDENTIFICADOR S_IGUAL matriz_type
        { $$ = Declaration_Matriz($1, $6, $8); /* REGRESAMOS EL NODO QUE GENERA */ }
;

// ! LAS DOS MANERAS QUE PUEDEN INGRESAR UNA MATRIZ
matriz_type:
            NEW_WORD DATA_TYPE CORCHETE_OPEN expr CORCHETE_CLOSE CORCHETE_OPEN expr CORCHETE_CLOSE S_PUNTO_COMA
            { $$ = Matriz_Auto($2, $4, $7); /* valores definidos en matriz*/ }

            | LLAVE_OPEN matriz_values LLAVE_CLOSE S_PUNTO_COMA
            { $$ = Matriz_With_Values($2); /* valores definidos en matriz*/ }
;

// ! RECURSIVA PARA MATRIZ, TOMAR VALORES INGRESADOS EN APARTADOS POR COMAS
// Retorna una lista de nodos tipo Vector_Values
matriz_values:
            matriz_values COMA LLAVE_OPEN vector_values LLAVE_CLOSE 
            {
                // Get current size of list
                int size = 0;
                while ($1 && $1[size] != NULL) size++;
                
                // Create new list with extra space
                $$ = malloc(sizeof(Nodo*) * (size + 2));
                
                // Copy existing nodes
                for(int i = 0; i < size; i++) {
                    $$[i] = $1[i];
                }
                
                // Add new vector_values node
                $$[size] = Valores_Vector($4);
                $$[size + 1] = NULL;
            }

            | LLAVE_OPEN vector_values LLAVE_CLOSE 
            {
                // Create list with single node
                $$ = malloc(sizeof(Nodo*) * 2);
                $$[0] = Valores_Vector($2);
                $$[1] = NULL;
            }
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
            IDENTIFICADOR op_expr expr_bridge S_PUNTO_COMA             
            { $$ = Asignacion_Variable($1, $2, $3); /* 'OPERADOR ASIGNACION' PARA UNA VARIABLE Y ASIGNACION NORMAL*/ }

            | variable_access S_IGUAL expr S_PUNTO_COMA                
            { $$ = Vector_Asignation_Ref($1, $3); }

            | matrix_access S_IGUAL expr S_PUNTO_COMA                
            { $$ = Matriz_Change_Value($1, $3); }

            | DATA_TYPE IDENTIFICADOR S_IGUAL IDENTIFICADOR PARENTESIS_OPEN function_parameters_access PARENTESIS_CLOSE S_PUNTO_COMA  
            {
                Nodo* temp = Function_Call_Parameters($4, $6);
                $$ = Asignation_function($1, $2, temp); /* ASIGNACION DE VARIABLE A UNA FUNCION CON PARAMETROS */
            }
;




// ! PRODUCCION ENCARGADA DE DECIDIR SI SOLO VIENE UNA EXPRESION O ALGUN VALOR DE ASIGNACION DE VECTORES
expr_bridge:
        expr                    { $$ = $1; }
        | variable_access       { $$ = $1; }
        | matrix_access         { $$ = $1; }
;

// ! OPERADORES DE ASIGNACION POSIBLES CASOS
op_expr:
        S_IGUAL                 { $$ = "="; }
        | OP_MAS_IGUAL          { $$ = "+="; }
        | OP_MENOS_IGUAL        { $$ = "-="; }
        | OP_MULTI_IGUAL        { $$ = "*="; }
        | OP_DIV_IGUAL          { $$ = "/="; }
        | OP_MOD_IGUAL          { $$ = "%="; }
        | OP_AND_IGUAL          { $$ = "&="; }
        | OP_OR_IGUAL           { $$ = "|="; }
        | OP_POT_IGUAL          { $$ = "^="; }
        | OP_MAYOR_IGUAL        { $$ = ">>="; }
        | OP_MENOR_IGUAL        { $$ = "<<="; }
;

// * FUNCIONES ESPECIALES O NATIVAS -------------------------------------------------------------------------------------

native_func:
            IDENTIFICADOR for_option S_PUNTO_COMA          
            {$$ = Plus_Minus_Var($1, $2);}

            | CONTINUE_WORD S_PUNTO_COMA 
            { $$ = Continue_Word(); /* CONTINUE PARA CICLOS */ }

            | BREAK_WORD S_PUNTO_COMA 
            { $$ = Break_Word(); /* BREAK PARA CICLOS */ }
            
            | RETURN_WORD S_PUNTO_COMA 
            { $$ = Return_Word(); /* RETURN PARA FUNCIONES */ }

            | RETURN_WORD expr S_PUNTO_COMA 
            { $$ = Return_Value($2); /* RETURN PARA FUNCIONES */ }

            | IDENTIFICADOR PARENTESIS_OPEN parameters_bridge PARENTESIS_CLOSE S_PUNTO_COMA
            { $$ = Function_Call_No_Param($1); }
;

// ! PRODUCCION QUE MANEJA LA FORMA DE ESCRITURA DE LOS VECTORES Y LAS MATRICES
variable_access:
                IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE
                {$$ = Vector_Reference($1, $3);/* ACCESO A VALOR EN UN VECTOR*/}
;

matrix_access:
                IDENTIFICADOR CORCHETE_OPEN expr CORCHETE_CLOSE CORCHETE_OPEN expr CORCHETE_CLOSE     
                {$$ = Matriz_Reference($1, $3, $6);/* ACCESO A VALOR EN UNA MATRIZ */}
;

// * CONDICIONALES IF ELSE ---------------------------------------------------------------------------------------------
if_sentence:
            IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE    
            { $$ = Sentencia_If_Simple($3, $6); }

            | IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE ELSE_WORD LLAVE_OPEN lista_instrucciones LLAVE_CLOSE 
            { $$ = Sentencia_If_Else($3, $6, $10); }
            
            | IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE if_else_one if_else_chain ELSE_WORD LLAVE_OPEN lista_instrucciones LLAVE_CLOSE
            { $$ = Sentencia_If_ElseIf_Else($3, $6, $8, $9, $12); /* IF - ELSE IF - ELSE CON LISTA DE ELSE IF */ }
;

if_else_one:
            ELSE_WORD IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE
            { $$ = If_Else_One($4, $7); /* INSTRUCCIONES DEL ELSE IF SI SOLSO VIENE UNA VEZ */ }
;

if_else_chain:
                if_else_chain ELSE_WORD IF_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE
                {  
                    // Obtener el tamaño actual de la lista
                    int size = 0;
                    while ($1 && $1[size] != NULL) size++;
                    
                    // Crear nueva lista con un espacio adicional
                    $$ = malloc(sizeof(Nodo*) * (size + 2));  // +1 para el nuevo nodo, +1 para NULL
                    
                    // Copiar nodos existentes
                    for(int i = 0; i < size; i++) {
                        $$[i] = $1[i];
                    }
                    
                    // Agregar nuevo nodo else-if
                    $$[size] = Sentencia_ElseIf($5, $8, NULL);
                    $$[size + 1] = NULL;  // Terminar lista con NULL
                }

                | /* vacío */
                { 
                // Inicializar lista vacía
                    $$ = malloc(sizeof(Nodo*) * 1);
                    $$[0] = NULL;
                }
;

// * CICLO FOR ----------------------------------------------------------------------------------------------------------
for_sentence:
            FOR_WORD PARENTESIS_OPEN for_condition PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE
            { $$ = For_Sentence($3, $6); }
; 

// ! CONDICIONES DEL FOR PARA DIFERENCIAR ENTRE FOR NORMAL O UN FOR EACH PARA LISTAS
for_condition:
            declaration expr S_PUNTO_COMA IDENTIFICADOR for_option
            { $$ = For_Condition($1, $2, $4, $5); }
            | DATA_TYPE IDENTIFICADOR S_PUNTO_PUNTO IDENTIFICADOR
            { $$ = For_Each($1, $2, $4); /* Implementacion con los vectores */ }
;

for_option:
            OP_AUMENTO { $$ = "++"; }
            | OP_DECREMENTO { $$ = "--"; }

// * CONDICIONAL SWITCH CASE -----------------------------------------------------------------------------------------------
switch_case:
            SWITCH_WORD PARENTESIS_OPEN IDENTIFICADOR PARENTESIS_CLOSE LLAVE_OPEN switch_case_one switch_case_list switch_default LLAVE_CLOSE
            { $$ = Switch_Sentence($3, $6, $7, $8); }
;

// ! ASEGURAMOS QUE ALMENOS UN CASE DEBE EXISTIR
switch_case_one:
                CASE_WORD expr S_PUNTO_PUNTO lista_instrucciones BREAK_WORD S_PUNTO_COMA
                { $$ = Switch_Case_One($2, $4); }
;

// ! RECURSIVIDAD PARA INDEFINIDOS CASOS DE 'CASE'
switch_case_list:
                switch_case_list CASE_WORD expr S_PUNTO_PUNTO lista_instrucciones BREAK_WORD S_PUNTO_COMA
                {
                    // Obtener el tamaño actual de la lista
                    int size = 0;
                    while ($1 && $1[size] != NULL) size++;
                    
                    // Crear nueva lista con un espacio adicional
                    $$ = malloc(sizeof(Nodo*) * (size + 2));  // +1 para el nuevo nodo, +1 para NULL
                    
                    // Copiar nodos existentes
                    for(int i = 0; i < size; i++) {
                        $$[i] = $1[i];
                    }
                    
                    // Agregar nuevo nodo case
                    $$[size] = Switch_Case_One($3, $5);
                    $$[size + 1] = NULL;  // Terminar lista con NULL
                }


                | /* vacío */
                { 
                // Inicializar lista vacía
                    $$ = malloc(sizeof(Nodo*) * 1);
                    $$[0] = NULL;
                }
;

// ! CONDICIONAL DEL CASO 'DEFAULT' QUE PUEDE O NO VENIR
switch_default:
                DEFAULT_WORD S_PUNTO_PUNTO lista_instrucciones
                { $$ = Switch_Default($3); }

                | /* vacío */
                { $$ = Nodo_Vacio("NO DEFAULT"); }
;

// * CONDICIONAL WHILE ----------------------------------------------------------------------------------------------------
while_sentence:
                WHILE_WORD PARENTESIS_OPEN expr PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE
                { $$ = While_Sentence($3, $6); }
;

// * DECLARACION DE FUNCIONES ----------------------------------------------------------------------------------------------------
function_sentence:
                DATA_TYPE IDENTIFICADOR PARENTESIS_OPEN parameters_bridge PARENTESIS_CLOSE LLAVE_OPEN lista_instrucciones LLAVE_CLOSE
                { $$ = Funtion_Declaration($1, $2, $4, $7); /* DECLARACION DE FUNCIONES */ }
;

// ! PUENTE PARA QUE EL PARSER DECIDA SI VIENEN O NO PARAMETROS
parameters_bridge:
                function_parameters_declaration
                { $$ = $1; }

                | function_parameters_access
                { $$ = $1; }

                | MAIN_STRING
                {
                    // Create empty list with single node
                    $$ = malloc(sizeof(Nodo*) * 2);
                    $$[0] = Nodo_Vacio("NO PARAMETROS");
                    $$[1] = NULL;
                }

                | /* vacío */ 
                {
                    // Create empty list
                    $$ = malloc(sizeof(Nodo*) * 1);
                    $$[0] = Nodo_Vacio("NO PARAMETROS");
                }
;

// ! RECURSIVA DE PARAMETROS 
function_parameters_declaration:
                    function_parameters_declaration COMA DATA_TYPE IDENTIFICADOR
                    {
                        int size = 0;
                        while ($1 && $1[size] != NULL) size++;
                        
                        $$ = malloc(sizeof(Nodo*) * (size + 2));
                        
                        for(int i = 0; i < size; i++) {
                            $$[i] = $1[i];
                        }
                        
                        $$[size] = Var_Declaration($3, $4, Terminal_Null("DEFAULT"));
                        $$[size + 1] = NULL;
                    }
                    | DATA_TYPE IDENTIFICADOR
                    {
                        $$ = malloc(sizeof(Nodo*) * 2);
                        $$[0] = Var_Declaration($1, $2, Terminal_Null("DEFAULT"));
                        $$[1] = NULL;
                    }
;

function_parameters_access:
                    function_parameters_access COMA expr
                    {
                        int size = 0;
                        while ($1 && $1[size] != NULL) size++;
                        
                        $$ = malloc(sizeof(Nodo*) * (size + 2));
                        
                        for(int i = 0; i < size; i++) {
                            $$[i] = $1[i];
                        }
                        
                        $$[size] = $3;
                        $$[size + 1] = NULL;
                    }
                    | expr
                    {
                        $$ = malloc(sizeof(Nodo*) * 2);
                        $$[0] = $1;
                        $$[1] = NULL;
                    }
;
// * EXPRESIONES GLOBALES QUE INTERPRETAN ARITMETICA, OPERADORES LOGICOS Y ALGUNAS ASIGNACIONES ------------------
expr:
    expr '+' expr                               { $$ = Suma($2, $1, $3); }
    | expr '-' expr                             { $$ = Resta($2, $1, $3); }
    | expr '*' expr                             { $$ = Multiplicacion($2, $1, $3); }
    | expr '/' expr                             { $$ = Division($2, $1, $3); }
    | expr '%' expr                             { $$ = Modulo($2, $1, $3); }
    | PARENTESIS_OPEN expr PARENTESIS_CLOSE     { $$ = $2; }
    | INT_NUMBER                                { $$ = Terminal_Int($1); }
    | '-' expr %prec UMINUS                     { $$ = Terminal_Negativo($2); }
    | FLOAT_NUMBER FLOAT_SUFFIX                 { $$ = Terminal_Float($1); }
    | FLOAT_NUMBER                              { $$ = Terminal_Double($1); }
    | STRING_COMILLAS                           { if (strlen($1) == 3) { $$ = Terminal_Char($1[1]); } else { $$ = Terminal_String($1); }} // ! Agregar verificacion si es un char o no
    | BOOL_VALUE                                { $$ = Terminal_Bool($1); }
    | NULL_VALUE                                { $$ = Terminal_Null($1); } // ! Cambiar a "-null" si no lo procesa bien
    | IDENTIFICADOR                             { $$ = Identificador_Ref($1);}
    | expr OP_MENOR_A expr                      { $$ = Menor_A($1, $3); }
    | expr OP_MAYOR_A expr                      { $$ = Mayor_A($1, $3); }
    | expr OP_MENOR_IGUAL_A expr                { $$ = Menor_Igual_A($1, $3); }
    | expr OP_MAYOR_IGUAL_A expr                { $$ = Mayor_Igual_A($1, $3); }
    | expr OP_IGUAL_IGUAL expr                  { $$ = Igual_Igual($1, $3); }
    | expr OP_DISTINTO_A expr                   { $$ = Diferente_Que($1, $3); }
    | expr LOGIC_AND expr                       { $$ = And($1, $3); }
    | expr LOGIC_OR expr                        { $$ = Or($1, $3); }
    | LOGIC_NOT expr                            { $$ = Not($2); }
    | IDENTIFICADOR FUNC_EQUALS PARENTESIS_OPEN expr PARENTESIS_CLOSE 
    { $$ = Equals_Compare($1, $4); /* PRINT FUNC .EQUALS PARA UNA VARIABLE */ }
    | STRING_COMILLAS FUNC_EQUALS PARENTESIS_OPEN expr PARENTESIS_CLOSE 
    { $$ = Equals_Compare($1, $4); /* PRINT FUNC .EQUALS PARA UNA VARIABLE */ }
;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error: sintáctico en linea: %d\n", yylineno);
}