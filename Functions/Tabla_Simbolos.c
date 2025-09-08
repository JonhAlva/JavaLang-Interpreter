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

Nodo* Acceso_Variable(char* Nombre) {
    Nodo* n = malloc(sizeof(Nodo));
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            switch (tabla_Variables[i].tipo_Variable) {
                case TIPO_INT:
                    n->tipo = NODO_INT;
                    n->valor.i_val = tabla_Variables[i].valor.i_val;
                    break;
                case TIPO_FLOAT:
                    n->tipo = NODO_FLOAT;
                    n->valor.f_val = tabla_Variables[i].valor.f_val;
                    break;
                case TIPO_STRING:
                    n->tipo = NODO_STRING;
                    n->valor.s_val = strdup(tabla_Variables[i].valor.s_val);
                    break;
                case TIPO_BOOLEAN:
                    n->tipo = NODO_BOOL;
                    n->valor.b_val = tabla_Variables[i].valor.b_val;
                    break;
                case TIPO_CHAR:
                    n->tipo = NODO_CHAR;
                    n->valor.c_val = tabla_Variables[i].valor.c_val;
                    break;
                case TIPO_LONG:
                    n->tipo = NODO_INT; // Usamos NODO_INT para representar long
                    n->valor.i_val = tabla_Variables[i].valor.i_val;
                    break;
                case TIPO_SHORT:
                    n->tipo = NODO_INT; // Usamos NODO_INT para representar short
                    n->valor.i_val = tabla_Variables[i].valor.i_val;
                    break;
                case TIPO_DOUBLE:
                    n->tipo = NODO_DOUBLE; // Usamos NODO_DOUBLE para representar double
                    n->valor.d_val = tabla_Variables[i].valor.d_val;
                    break;
                case TIPO_BYTE:
                    n->tipo = NODO_CHAR; // Usamos NODO_CHAR para representar byte
                    n->valor.c_val = tabla_Variables[i].valor.c_val;
                    break;
                }
            n->izq = n->der = NULL;
            return n;
        }
    }
    n->tipo = NODO_NULL;
    n->valor.null_val = "-Var Not Found Err"; // Error de variable no encontrada
    n->izq = n->der = NULL;
    return n;
}