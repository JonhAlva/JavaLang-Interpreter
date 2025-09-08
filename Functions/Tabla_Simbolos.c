#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tabla_Simbolos.h"
#include "Evaluate.h"

Variable tabla_Variables[MAX_VARS];
int num_vars = 0;

// ! Asignacion de variable INT
void AsignarVariable_Int(char* Nombre, int valor) {
    // ? for para recorrer el tamaño de la tabla
    for (int i = 0; i < num_vars; i++) {
        // ? Buscamos un espacio vacio para ingresar la nueva variable
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            tabla_Variables[i].tipo_Variable = TIPO_INT;
            tabla_Variables[i].valor.i_val = valor;
            return;
        }
    }
    strcpy(tabla_Variables[num_vars].nombreVariable, Nombre);
    tabla_Variables[num_vars].tipo_Variable = TIPO_INT;
    tabla_Variables[num_vars].valor.i_val = valor;
    num_vars++;
}

void AsignarVariable_Float(char* Nombre, float valor) {
     // ? for para recorrer el tamaño de la tabla
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            tabla_Variables[i].tipo_Variable = TIPO_FLOAT;
            tabla_Variables[i].valor.f_val = valor;
            return;
        }
    }
    strcpy(tabla_Variables[num_vars].nombreVariable, Nombre);
    tabla_Variables[num_vars].tipo_Variable = TIPO_FLOAT;
    tabla_Variables[num_vars].valor.f_val = valor;
    num_vars++;
}

void AsignarVariable_String(char* Nombre, char* valor) {
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            tabla_Variables[i].tipo_Variable = TIPO_STRING;
            tabla_Variables[i].valor.s_val = strdup(valor);
            return;
        }
    }
    strcpy(tabla_Variables[num_vars].nombreVariable, Nombre);
    tabla_Variables[num_vars].tipo_Variable = TIPO_STRING;
    tabla_Variables[num_vars].valor.s_val = strdup(valor);
    num_vars++;
}

void AsignarVariable_Boolean(char* Nombre, int valor) {
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            tabla_Variables[i].tipo_Variable = TIPO_BOOLEAN;
            tabla_Variables[i].valor.f_val = valor;
            return;
        }
    }
    strcpy(tabla_Variables[num_vars].nombreVariable, Nombre);
    tabla_Variables[num_vars].tipo_Variable = TIPO_BOOLEAN;
    tabla_Variables[num_vars].valor.f_val = valor;
    num_vars++;
}

void AsignarVariable_Char(char* Nombre, char valor) { // ? ---------------------------
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            tabla_Variables[i].tipo_Variable = TIPO_CHAR;
            tabla_Variables[i].valor.c_val = valor;
            return;
        }
    }
    strcpy(tabla_Variables[num_vars].nombreVariable, Nombre);
    tabla_Variables[num_vars].tipo_Variable = TIPO_CHAR;
    tabla_Variables[num_vars].valor.c_val = valor;
    num_vars++;
}

void AsignarVariable_Long(char* Nombre, int valor) {

    valor = (long)valor; // Convertir int a long
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            tabla_Variables[i].tipo_Variable = TIPO_LONG;
            tabla_Variables[i].valor.i_val = valor;
            return;
        }
    }
    strcpy(tabla_Variables[num_vars].nombreVariable, Nombre);
    tabla_Variables[num_vars].tipo_Variable = TIPO_LONG;
    tabla_Variables[num_vars].valor.i_val = valor;
    num_vars++;
}

void AsignarVariable_Short(char* Nombre, int valor) {

    valor = (short)valor; // Convertir int a short
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            tabla_Variables[i].tipo_Variable = TIPO_SHORT;
            tabla_Variables[i].valor.i_val = valor;
            return;
        }
    }
    strcpy(tabla_Variables[num_vars].nombreVariable, Nombre);
    tabla_Variables[num_vars].tipo_Variable = TIPO_SHORT;
    tabla_Variables[num_vars].valor.i_val = valor;
    num_vars++;
}

void AsignarVariable_Double(char* Nombre, float valor) {

    double d_valor = (double)valor; // Convertir float a double
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            tabla_Variables[i].tipo_Variable = TIPO_DOUBLE;
            tabla_Variables[i].valor.d_val = d_valor;
            return;
        }
    }
    strcpy(tabla_Variables[num_vars].nombreVariable, Nombre);
    tabla_Variables[num_vars].tipo_Variable = TIPO_DOUBLE;
    tabla_Variables[num_vars].valor.d_val = d_valor;
    num_vars++;
}

void AsignarVariable_Byte(char* Nombre, char valor) {
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            tabla_Variables[i].tipo_Variable = TIPO_BYTE;
            tabla_Variables[i].valor.c_val = valor;
            return;
        }
    }
    strcpy(tabla_Variables[num_vars].nombreVariable, Nombre);
    tabla_Variables[num_vars].tipo_Variable = TIPO_BYTE;
    tabla_Variables[num_vars].valor.c_val = valor;
    num_vars++;
}

Valor Acceso_Variable(char* Nombre) {
    Valor v;
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            switch (tabla_Variables[i].tipo_Variable) {
                case TIPO_INT:
                    v.tipo = VAL_INT;
                    v.i_val = tabla_Variables[i].valor.i_val;
                    return v;
                case TIPO_FLOAT:
                    v.tipo = VAL_FLOAT;
                    v.f_val = tabla_Variables[i].valor.f_val;
                    return v;
                case TIPO_STRING:
                    v.tipo = VAL_STRING;
                    v.s_val = tabla_Variables[i].valor.s_val;
                    return v;
                case TIPO_BOOLEAN:
                    v.tipo = VAL_BOOL;
                    v.b_val = tabla_Variables[i].valor.b_val;
                    return v;
                case TIPO_CHAR:
                    v.tipo = VAL_CHAR;
                    v.c_val = tabla_Variables[i].valor.c_val;
                    printf(" »   Accediendo a variable CHAR: '%s' con valor: %c \n", Nombre, v.c_val);
                    return v;
                case TIPO_LONG:
                    v.tipo = VAL_INT; // Usamos VAL_INT para representar long
                    v.i_val = (int)tabla_Variables[i].valor.i_val; // Convertir long a int
                    return v;
                case TIPO_SHORT:
                    v.tipo = VAL_INT; // Usamos VAL_INT para representar short
                    v.i_val = (int)tabla_Variables[i].valor.i_val; // Convertir short a int
                    return v;
                case TIPO_DOUBLE:
                    v.tipo = VAL_FLOAT; // Usamos VAL_FLOAT para representar double
                    v.f_val = (float)tabla_Variables[i].valor.d_val; // Convertir double a float
                    printf(" »   Accediendo a variable DOUBLE: '%s' con valor: %f \n", Nombre, v.f_val);
                    return v;
                case TIPO_BYTE:
                    v.tipo = VAL_CHAR; // Usamos VAL_CHAR para representar byte
                    v.c_val = tabla_Variables[i].valor.c_val; // Asumimos que es un solo byte
                    return v;
                default:
                    break;
            }
        }
    }
    // Si no se encuentra la variable, retornar un valor nulo
    v.tipo = VAL_NULL;
    v.null_val = "null";
    return v;
}