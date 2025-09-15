#include <stdio.h>
#include <string.h>
#include "Evaluate.h"
#include "AST.h"

#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H
#define MAX_VARS 500
#define MAX_ERRORS 100
#define MAX_VECTORES 100
#define  MAX_FUNCTIONS 100

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
        int i_val;
        float f_val;
        double d_val;    // Agregar campo específico para double
        char* s_val;
        char c_val;
        int b_val;      // valor booleano 0 false | 1 true
        char* null_val;
        char* varType;   // Tipo de dato de la variable (int, float, etc.)
    } valor;  // ? Tipos de valores que tomara
} Variable ;    // ? Nombre del struct de VARIABLE

typedef struct {
    char nombreVector[64];    // ? Nombre del vector
    TipoDato tipo_Vector;     // ? Tipo de la variable
    Nodo** valores;           // ? Lista de nodos que contiene los valores del vector
    int size;                 // ? Tamaño actual del vector
} Vectores ;    // ? Nombre del struct de VECTOR

typedef struct {
    int Num;
    char* Desc_Error;
    char* Tipo_Error;
} Error_Variable;

// ! Tabla de simbolos que almacena las variables
extern Variable tabla_Variables[MAX_VARS];
extern int num_vars;
// ! -----------------------------------------------
extern Vectores lista_Vectores[MAX_VECTORES];
extern int num_vectores;
// ! -----------------------------------------------
extern Error_Variable lista_Errores[MAX_ERRORS];
extern int num_errores;
// ! -----------------------------------------------
extern Nodo* tabla_Funciones[MAX_FUNCTIONS];
extern int num_funciones;
//! -----------------------------------------------

// ? Funciones que estaran publicas y en este paquete
void AsignarVariable_Int(char* Nombre, int valor);      // ? Widening{int -> float} ? NARROWING{int -> char}
void AsignarVariable_Float(char* Nombre, float valor);  // ? Widening{float -> double} ? NARROWING{float -> int}
void AsignarVariable_String(char* Nombre, char* valor);
void AsignarVariable_Boolean(char* Nombre, int valor);
void AsignarVariable_Char(char* Nombre, char valor);    // ? Widening{char -> int}
void AsignarVariable_Long(char* Nombre, int valor);
void AsignarVariable_Short(char* Nombre, int valor);
void AsignarVariable_Double(char* Nombre, float valor); // ? NARROWING{double -> float}
void AsignarVariable_Byte(char* Nombre, char valor);

void AsignarParseo_Variable(char* Nombre, char* Tipo, char* Parse_Type, Valor valor);

void Actualizar_Variable(char* Nombre, Valor nuevo_valor);
void Asignacion_Especial(char* Nombre, char* operador, Valor nuevo_valor);
void Asignacion_Default(char* Nombre, char* Tipo);
void Casteo_Narrow(char* Tipo1, char* Identificador, char* ParseType, char* Identificador2);

void Agregar_Funcion(Nodo* funcion);
Nodo* Acceso_Funcion(char* Nombre);
void Clear_All_Funciones();

Nodo* Compare_Equals(char* Identificador, Nodo* Izq);
Nodo* Acceso_Variable(char* Nombre);

//FUNCION QUE RETORNE UNA LISTA INICIALIZADA DE NODOS
Nodo** Lista_Vector(Nodo* valor);
Nodo** Add_Valor_Vector(Nodo** lista, Nodo* valor);

//FUNCION QUE COMPARA DOS VALORES
int CompararValores(Valor valor1, Valor valor2);

// ! DEBUG FUNCTIONS
void Print_Specific_Variable(char* Nombre);
void Print_All_Variables();
void Print_All_Errors();
void Clear_All_Errors();
void Clear_All_Variables();
#endif