#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "AST.h"

// ! Nodo SYSTEM OUT PRINT
Nodo* Print(Nodo* expr) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_PRINT;
    n->izq = expr;
    n->der = NULL;
    n->nombre = NULL;
    return n;
}

// ! Nmero int normal * * * *
Nodo* Terminal_Int(int valor) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_INT;
    n->valor.i_val = valor;
    n->izq = n->der = NULL;
    return n;
};

// ! Numero float normal * * * *
Nodo* Terminal_Float(float valor) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_FLOAT;
    n->valor.f_val = valor;
    n->izq = n->der = NULL;
    return n;
}

// ! Cadena string normal * * * *
Nodo* Terminal_String(char* valor) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_STRING;
    n->valor.s_val = strdup(valor);
    n->izq = n->der = NULL;
    return n;
}

// ! Identificador
Nodo* Variable_Ref(char* nombre) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_STRING;
    n->valor.s_val = strdup(nombre);
    n->izq = n->der = NULL;
    return n;
}

// ! Declaracion de variable
Nodo* Declaration_Var(char* nombre, Nodo* valor) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_DECLARATION;
    n->nombre = strdup(nombre);
    n->izq = valor;
    n->der = NULL;
    return n;
}

// ! Booleano normal * * * * 
Nodo* Terminal_Bool(bool valor) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_BOOL;
    n->valor.b_val = valor;
    n->izq = n->der = NULL;
    return n;
}

// ! Char normal de un solo byte * * *
Nodo* Terminal_Char(char valor) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_CHAR;
    n->valor.c_val = valor;
    n->izq = n->der = NULL;
    return n;
}

// ! Operaciones combinadas
Nodo * Operacion(int op, Nodo* izq, Nodo* der) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_OPERACION;
    n->valor.op = op;
    n->izq = izq;
    n->der = der;
    return n;
}
