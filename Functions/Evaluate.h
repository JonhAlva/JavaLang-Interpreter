#include <string.h>
#include <stdlib.h>

#ifndef EVALUATE_H
#define EVALUATE_H

typedef enum {
    VAL_INT, 
    VAL_FLOAT, 
    VAL_BOOL, 
    VAL_STRING, 
    VAL_CHAR, 
    VAL_NULL
} TipoValor;

typedef struct {
    TipoValor tipo;
    union {
        int i_val;
        float f_val;
        char* s_val; //string
        char c_val;     //char
        int b_val;      // valor booleano 0 false | 1 true
        int op;         //operador
        char* null_val; //valor nulo
    };
} Valor;

Valor Evaluar(struct Nodo* n);

#endif