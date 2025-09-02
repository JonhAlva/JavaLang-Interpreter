#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

// ? Struct de tipo de variables --------------------------------------------
typedef enum {
    TIPO_INT,
    TIPO_FLOAT,
    TIPO_BOOLEAN,
    TIPO_CHAR,
    TIPO_STRING,
    TIPO_LONG,
    TIPO_BYTE,
    TIPO_SHORT,
    TIPO_DOUBLE
} TipoDato ;        // ? Nombre del strcut

// ? Struct de variable --------------------------------------------------------
typedef struct {
    char nombreVariable[64];    // ? Nombre de la variable
    TipoDato tipo_Variable;     // ? Tipo de la variable
    union {
        int i_valor;
        float f_valor;
        bool b_valor;
        char* c_valor; // ? string y byte incluido aqui
        long l_valor;
        short sh_valor;
        double d_valor;
    } valor;  // ? Tipos de valores que tomara
} Variable ;    // ? Nombre del struct de VARIABLE

// ! Tabla de simbolos que almacena las variables
Variable tabla_Variables[150];
int num_vars = 0;
// ! -----------------------------------------------

// ? Funciones que estaran publicas y en este paquete
void AsignarVariable_Int(char* Nombre, int valor);
void AsignarVariable_Float(char* Nombre, float valor);
void AsignarVariable_String(char* Nombre, char* valor);
void imprimirVariable(char* Nombre);
void Imprimir_System_out(char* Texto);

#endif