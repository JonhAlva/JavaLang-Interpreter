#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tabla_Simbolos.h"

Variable tabla_Variables[MAX_VARS];
int num_vars = 0;

// ! Asignacion de variable INT
void AsignarVariable_Int(char* Nombre, int valor) {
    // ? for para recorrer el tamaño de la tabla
    for (int i = 0; i < num_vars; i++) {
        // ? Buscamos un espacio vacio para ingresar la nueva variable
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            tabla_Variables[i].tipo_Variable = TIPO_INT;
            tabla_Variables[i].valor.i_valor = valor;
            return;
        }
    }
    strcpy(tabla_Variables[num_vars].nombreVariable, Nombre);
    tabla_Variables[num_vars].tipo_Variable = TIPO_INT;
    tabla_Variables[num_vars].valor.i_valor = valor;
    num_vars++;
}

void AsignarVariable_Float(char* Nombre, float valor) {
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            tabla_Variables[i].tipo_Variable = TIPO_FLOAT;
            tabla_Variables[i].valor.f_valor = valor;
            return;
        }
    }
    strcpy(tabla_Variables[num_vars].nombreVariable, Nombre);
    tabla_Variables[num_vars].tipo_Variable = TIPO_FLOAT;
    tabla_Variables[num_vars].valor.f_valor = valor;
    num_vars++;
}

void AsignarVariable_String(char* Nombre, char* valor) {
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            tabla_Variables[i].tipo_Variable = TIPO_STRING;
            tabla_Variables[i].valor.c_valor = strdup(valor);
            return;
        }
    }
    strcpy(tabla_Variables[num_vars].nombreVariable, Nombre);
    tabla_Variables[num_vars].tipo_Variable = TIPO_STRING;
    tabla_Variables[num_vars].valor.c_valor = strdup(valor);
    num_vars++;
}