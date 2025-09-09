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
    NODO_DIFERENTE_QUE      // *
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
Nodo* Nodo_Vacio(const char* mensaje);

Nodo* Casteo_Narrowing(char* Tipo1, char* Identificador, char* ParseType, char* Identificador2);
Nodo* Equals_Compare(char* Identificador, Nodo* Izq);

// ? Funciones de limpieza
//void ImprimirNodo(Nodo* nodo, int nivel);
//void LiberarNodo(Nodo* nodo);

#endif