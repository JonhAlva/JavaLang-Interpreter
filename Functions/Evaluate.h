#include <string.h>
#include <stdlib.h>
#include "AST.h"

#ifndef EVALUATE_H
#define EVALUATE_H

typedef enum {
    // ! AGREGAR EL OTRO TIPO DE DATOS QUE SE ACEPTAN
    VAL_INT, 
    VAL_FLOAT, 
    VAL_BOOL, 
    VAL_STRING, 
    VAL_CHAR, 
    VAL_NULL,
    VAL_DOUBLE
} TipoValor;

typedef struct {
    TipoValor tipo;
    union {
        int i_val;
        float f_val;
        double d_val;
        char* s_val; //string
        char c_val;     //char
        int b_val;      // valor booleano 0 false | 1 true
        int op;         //operador
        char* null_val; //valor nulo
        char* varType;   // Tipo de dato de la variable (int, float, etc.)
    };
} Valor;

Valor Evaluar(struct Nodo* n);

#endif