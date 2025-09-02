#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Tabla_Simbolos.h"

void imprimirVariable(char* Nombre) {
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            switch (tabla_Variables[i].tipo_Variable) {
            case TIPO_INT:
                printf("💾 Variable Registrada: %s = %d \n", Nombre, tabla_Variables[i].valor.i_valor);
                break;
            case TIPO_STRING:
                printf("💾 Variable Registrada: %s = %f \n", Nombre, tabla_Variables[i].valor.c_valor);
                break;
            case TIPO_FLOAT:
                printf("💾 Variable Registrada: %s = %f \n", Nombre, tabla_Variables[i].valor.f_valor);
                break;
            }
            return;    
        }
    }
    // ! Variable no declarada
    printf("Error: variable %s no ha sido declarada!\n", Nombre);
}

void Imprimir_System_out(char* Texto) {
    printf("🖥️ System Print: %s \n", Texto);
}

