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
    NODO_INT,               // *
    NODO_FLOAT,             // *
    NODO_DOUBLE,            // *
    NODO_STRING,            // *
    NODO_IDENTIFICADOR,     // *
    NODO_DECLARATION,       // *
    NODO_ASIGNACION,        // *
    NODO_EQUALS_COMPARE,    // *
    NODO_BOOL,              // *
    NODO_CHAR,              // *
    NODO_PRINT,             // *
    NODO_SUMA,              // *
    NODO_RESTA,             // *
    NODO_MULTIPLICACION,    // *
    NODO_CASTEO_NARROWING,  // *
    NODO_DIVISION,          // *
    NODO_MODULO,            // *
    NODO_NOT,               // *
    NODO_NULL,              // *
    NODO_AND,               // *
    NODO_OR,                // *
    NODO_LISTA,             // *
    NODO_MENOR_A,           // *
    NODO_MAYOR_A,           // *
    NODO_MENOR_IGUAL_A,     // *
    NODO_MAYOR_IGUAL_A,     // *
    NODO_IGUAL_IGUAL,       // *
    NODO_DIFERENTE_QUE,      // *
    NODO_VALORES_VECTOR,     // *
    NODO_PARSEO,              // *
    NODO_IF_SIMPLE,        // *
    NODO_IF_ELSE,            // *
    NODO_IF_ELSE_ONE,       // *
    NODO_ELSE_IF_LIST,    // *
    NODO_IF_ELSE_IF,         // * 
    NODO_VECTOR_AUTO,
    NODO_VALORES_VECTOR_LIST, // *
    NODO_DECLARATION_VECTOR,   // *
    NODO_MATRIZ_AUTO,
    NODO_DECLARATION_MATRIX,
    NODO_FOR_CONDITION,
    NODO_FOR_SENTENCE
} TipoNodo;

typedef struct Nodo {
    TipoNodo tipo;
    char* nombre;       //Identificadores
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
Nodo* Vector_Auto(char* Instruccion, char* TipoDato, Nodo* LlenadoAuto);
Nodo* Declaration_Vector(char* DataType, char* Identificador, Nodo* TipoVector);
Nodo* Valores_Vector(Nodo** lista);
Nodo* Matriz_Auto(char* Tipo, Nodo* Val1, Nodo* Val2);
Nodo* Declaration_Matriz(char* DataType, char* Identificador, Nodo* TipoMatriz);
Nodo* Nodo_Vacio(const char* mensaje);

Nodo* Casteo_Narrowing(char* Tipo1, char* Identificador, char* ParseType, char* Identificador2);
Nodo* Equals_Compare(char* Identificador, Nodo* Izq);
Nodo* Parse_Expression(char* Identificador, char* TipoVar, char* ParseType, Nodo* expr);

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
// ? Funciones de limpieza
//void ImprimirNodo(Nodo* nodo, int nivel);
//void LiberarNodo(Nodo* nodo);

#endif