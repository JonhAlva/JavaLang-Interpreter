/* 
* CREACION DE TIPOS DE NODOS { ENUM }
* ATRIBUTOS O DISTINTOS VALORES QUE PUEDE TENER UN NODO { STRUCT }
* CONSTRUCCION DE FUNCIONES DISPONIBLES DENTRO DE "AST.C" { DEBEN COINCIDIR EN AMBOS ARCHIVOS }
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef AST_H
#define AST_H

typedef enum {
    NODO_INT,               // 0
    NODO_FLOAT,             // 1
    NODO_DOUBLE,            // 2
    NODO_STRING,            // 3
    NODO_IDENTIFICADOR,     // 4
    NODO_DECLARATION,       // 5
    NODO_ASIGNACION,        // 6
    NODO_EQUALS_COMPARE,    // 7
    NODO_BOOL,              // 8
    NODO_CHAR,              // 9
    NODO_PRINT,             // 10
    NODO_SUMA,              // 11
    NODO_RESTA,             // 12
    NODO_MULTIPLICACION,    // 13
    NODO_CASTEO_NARROWING,  // 14
    NODO_DIVISION,          // 15
    NODO_MODULO,            // 16
    NODO_NOT,               // 17
    NODO_NULL,              // 18
    NODO_AND,               // 19
    NODO_OR,                // 20
    NODO_LISTA,             // 21
    NODO_MENOR_A,           // 22
    NODO_MAYOR_A,           // 23
    NODO_MENOR_IGUAL_A,     // 24
    NODO_MAYOR_IGUAL_A,     // 25
    NODO_IGUAL_IGUAL,       // 26
    NODO_DIFERENTE_QUE,      // 27
    NODO_VALORES_VECTOR,     // 28
    NODO_PARSEO,              // 29
    NODO_IF_SIMPLE,        // 30
    NODO_IF_ELSE,            // 31
    NODO_IF_ELSE_ONE,       // 32
    NODO_ELSE_IF_LIST,    // 33
    NODO_IF_ELSE_IF,         // 34
    NODO_VECTOR_AUTO,    // 35
    NODO_VALORES_VECTOR_LIST, // 36
    NODO_DECLARATION_VECTOR,   // 37
    NODO_MATRIZ_AUTO,         // 38
    NODO_DECLARATION_MATRIX,  // 39
    NODO_FOR_CONDITION,      // 40
    NODO_FOR_SENTENCE,      // 41
    NODO_PLUS_MINUS_VAR,    // 42
    NODO_WHILE_SENTENCE,    // 43
    NODO_SWITCH_DEFAULT,    // 44
    NODO_SWITCH_CASE_ONE,   // 45
    NODO_SWITCH_CASE_LIST,  // 46
    NODO_SWITCH_SENTENCE,   // 47
    NODO_FUNCTION_DECLARATION, // 48
    NODO_FUNCTION_CALL_NO_PARAM, // 49
    NODO_FUNCTION_CALL_PARAMETERS, // 50
    NODO_CONTINUE,               // 51
    NODO_BREAK,                  // 52
    NODO_VACIO,                  // 53
    NODO_RETURN_SIMPLE,          // 54
    NODO_RETURN_FUNC,            // 55
    NODO_ASIGNATION_FUNC,     // 56
    NODO_VECTOR_REFERENCE,     // 57
    NODO_VECTOR_ASIGNATION ,   // 58
    NODO_ARRAYS_INDEXOF,      // 59
    NODO_ARRAYS_DECLARATION,   // 60
    NODO_ARRAY_LENGTH,           // 61
    NODO_ARRAY_ADD,             // 62
    NODO_STRING_JOIN_ARRAY,     // 63
    NODO_FOR_EACH,              // 64
} TipoNodo;

typedef struct Nodo {
    TipoNodo tipo;
    char* nombre;       //Identificadores
    int size_vector; // Tamaño del vector
    char* separador; // Separador para join
    union {
        int i_val;
        float f_val;
        double d_val;
        char* s_val;
        char c_val;
        int b_val;      // valor booleano 0 false | 1 true
        int op;
        char* op_bool;
        char* null_val;
        char* varType;   // Tipo de dato de la variable (int, float, etc.)
    } valor;
    struct Nodo* izq;
    struct Nodo* der;
    struct Nodo* nodo_else; // Para instrucciones else en if-else
    struct Nodo* siguiente;  // Para encadenar else-if
    struct Nodo** lista_nodos; // Para listas de nodos (como en vectores o listas de instrucciones)
} Nodo;

// ? Constructores de las funciones

Nodo* Terminal_Int(int valor);
Nodo* Terminal_Float(float valor);
Nodo* Terminal_Double(float valor);
Nodo* Terminal_String(char* valor);
Nodo* Terminal_Bool(int valor);
Nodo* Terminal_Char(char valor);
Nodo* Variable_Ref(char* nombre);
Nodo* Terminal_Null(char* valor);

Nodo* Suma(int Op, Nodo* Izq, Nodo* Der);
Nodo* Resta(int Op, Nodo* Izq, Nodo* Der);
Nodo* Multiplicacion(int Op, Nodo* Izq, Nodo* Der);
Nodo* Division(int Op, Nodo* Izq, Nodo* Der);
Nodo* Modulo(int Op, Nodo* Izq, Nodo* Der);

Nodo* Mayor_A(Nodo* Izq, Nodo* Der);
Nodo* Menor_A(Nodo* Izq, Nodo* Der);
Nodo* Mayor_Igual_A(Nodo* Izq, Nodo* Der);
Nodo* Menor_Igual_A(Nodo* Izq, Nodo* Der);
Nodo* Igual_Igual(Nodo* Izq, Nodo* Der);
Nodo* Diferente_Que(Nodo* Izq, Nodo* Der);
Nodo* Not(Nodo* Neg);
Nodo* And(Nodo* Izq, Nodo* Der);
Nodo* Or(Nodo* Izq, Nodo* Der);
Nodo* Identificador_Ref(char* nombre);

Nodo* Var_Declaration(char* Tipo, char* Nombre, Nodo* Izq);
Nodo* Asignacion_Variable(char* Nombre, char* Op, Nodo* Izq);
Nodo* Print(Nodo* expr);
Nodo* ListaInstrucciones(Nodo* instr, Nodo* resto);
Nodo* Vector_Auto(char* TipoDato, int LlenadoAuto);
Nodo* Declaration_Vector(char* DataType, char* Identificador, Nodo* TipoVector);
Nodo* Valores_Vector(Nodo** lista);
Nodo* Matriz_Auto(char* Tipo, Nodo* Val1, Nodo* Val2);
Nodo* Declaration_Matriz(char* DataType, char* Identificador, Nodo* TipoMatriz);
Nodo* Nodo_Vacio(const char* mensaje);

Nodo* Casteo_Narrowing(char* Tipo1, char* Identificador, char* ParseType, char* Identificador2);
Nodo* Equals_Compare(char* Identificador, Nodo* Izq);
Nodo* Parse_Expression(char* Identificador, char* TipoVar, char* ParseType, Nodo* expr);
Nodo* Continue_Word();
Nodo* Break_Word();
Nodo* Return_Word();
Nodo* Funtion_Declaration(char* Tipo, char* Identificador, Nodo** Parametros, Nodo* Instrucciones);
Nodo* Function_Call_No_Param(char* Identificador);
Nodo* Function_Call_Parameters(char* Identificador, Nodo** parametrosPorAsignar);
Nodo* Asignation_function(char* DataType, char* Identificador, Nodo* NodoFuncCallParameters);
Nodo* Return_Value(Nodo* expr);
Nodo* Vector_Reference(char* Identificador, Nodo* Index);
Nodo* Vector_Asignation(char* TipoDato, char* Identificador, Nodo* expr);

Nodo** Lista_Vector(Nodo* valor);
Nodo** Add_Valor_Vector(Nodo** lista, Nodo* valor);
Nodo* Make_StringJoin(char* tipo, char* Separador, Nodo** lista);

Nodo* Sentencia_If_Simple(Nodo* condicion, Nodo* instrucciones);
Nodo* Sentencia_If_Else(Nodo* condicion, Nodo* instrucciones_if, Nodo* instrucciones_else);

Nodo* Sentencia_ElseIf(Nodo* condicion, Nodo* instrucciones, Nodo* siguiente_else_if);
Nodo* If_Else_One(Nodo* condicion, Nodo* instrucciones_else);
Nodo* Sentencia_If_ElseIf_Else(Nodo* condicion, Nodo* instrucciones_if, 
                                Nodo* instrucciones_else_if, Nodo** lista_else_if, Nodo* instrucciones_else);

Nodo* For_Condition(Nodo* Declaration, Nodo* Condicion, char* Identificador, char* IncOrDec);
Nodo* For_Sentence(Nodo* ForCondition, Nodo* instrucciones);
Nodo* For_Each(char* Tipo, char* TempVar, char* VectorName);
Nodo* Plus_Minus_Var(char* Identificador, char* IncOrDec);
Nodo* While_Sentence(Nodo* condicion, Nodo* instrucciones);
Nodo* Switch_Default(Nodo* instrucciones);
Nodo* Switch_Case_One(Nodo* condicion, Nodo* instrucciones);
Nodo* Switch_Sentence(char* Identificador_Comparador, Nodo* Case_One, Nodo** List_Cases, Nodo* Default_Case);

Nodo* Array_Index_Of(char* VectorName, Nodo* Clave);
Nodo* Array_func_Declaration(char* DataType, char* Identificador, Nodo* TipoArray);
Nodo* Array_Length(char* Identificador);
Nodo* Array_Add_Ref(char* VectorName, Nodo* ValueToAdd);
Nodo* String_Join_Array(char* VarType, char* Identificador, char* Separador, Nodo** ArrayVal);

void Print_AST(Nodo* raiz, const char* filename);
const char* Get_Node_Type_Name(TipoNodo tipo);
static void Print_AST_DOT(Nodo* n, FILE* f);

// ? Funciones de limpieza
//void ImprimirNodo(Nodo* nodo, int nivel);
//void LiberarNodo(Nodo* nodo);

#endif