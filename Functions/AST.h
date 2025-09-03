#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#ifndef AST_H
#define AST_H

typedef enum {
    NODO_INT,
    NODO_FLOAT,
    NODO_STRING,
    NODO_IDENTIFICADOR,
    NODO_DECLARATION,
    NODO_BOOL,
    NODO_CHAR,
    NODO_PRINT,
    NODO_OPERACION
} TipoNodo;

typedef struct Nodo {
    TipoNodo tipo;
    char* nombre;       //Identificadores
    union {
        int i_val;
        float f_val;
        char* s_val;
        char c_val;
        bool b_val;
        int op;
    } valor;
    struct Nodo* izq;
    struct Nodo* der;
} Nodo;

// ? Constructores de las funciones

Nodo* Terminal_Int(int valor);
Nodo* Terminal_Float(float valor);
Nodo* Terminal_String(char* valor);
Nodo* Declaration_Var(char* nombre, Nodo* valor);
Nodo* Terminal_Bool(bool valor);
Nodo* Terminal_Char(char valor);
Nodo* Variable_Ref(char* nombre);

Nodo* Print(Nodo* expr);
Nodo* Operacion(int op, Nodo* izq, Nodo* der);

// ? Funciones de limpieza
//void ImprimirNodo(Nodo* nodo, int nivel);
//void LiberarNodo(Nodo* nodo);

#endif