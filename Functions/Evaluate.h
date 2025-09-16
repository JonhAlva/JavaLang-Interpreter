#include <string.h>
#include <stdlib.h>
#include "AST.h"

#ifndef EVALUATE_H
#define EVALUATE_H

typedef enum {
    // ! AGREGAR EL OTRO TIPO DE DATOS QUE SE ACEPTAN
    VAL_INT,        //0
    VAL_FLOAT,     //1
    VAL_BOOL,      //2
    VAL_STRING,   //3
    VAL_CHAR,     //4
    VAL_NULL,     //5
    VAL_DOUBLE,   //6
    VAL_CONTINUE, //7
    VAL_BREAK     //8
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