/* 
* CONSTRUCCION DE LOS TIPOS DE NODOS, QUE TIPO DE VALOR ES, ESTABLECER SU HIJO IZQ Y DER
* SU VALOR POR DEFECTO Y LOS PARAMETROS QUE NECESITA PAR CONSTRUIRSE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AST.h"
#include "Evaluate.h"

// ? NODOS DE OPERACIONES ARITMETICAS -----------------------------------------------------------------

Nodo* Suma(int Op, Nodo* Izq, Nodo* Der) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_SUMA;
    n->valor.op = Op;
    n->izq = Izq;
    n->der = Der;
    return n;
}

Nodo* Resta(int Op, Nodo* Izq, Nodo* Der) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_RESTA;
    n->valor.op = Op;
    n->izq = Izq;
    n->der = Der;
    return n;
}

Nodo* Multiplicacion(int Op, Nodo* Izq, Nodo* Der) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_MULTIPLICACION;
    n->valor.op = Op;
    n->izq = Izq;
    n->der = Der;
    return n;
}

Nodo* Division(int Op, Nodo* Izq, Nodo* Der) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_DIVISION;
    n->valor.op = Op;
    n->izq = Izq;
    n->der = Der;
    return n;
}

Nodo* Modulo(int Op, Nodo* Izq, Nodo* Der) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_MODULO;
    n->valor.op = Op;
    n->izq = Izq;
    n->der = Der;
    return n;
}

// ? ------------------------------------------------------------------------------------------------------------

// ? NODOS DE MANEJO DE VARIABLES E IDENTIFICADORES --------------------------------------------------------------

// ! Nodo para comparar string con equals
Nodo* Equals_Compare(char* Identificador, Nodo* Izq) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_EQUALS_COMPARE;
    n->nombre = strdup(Identificador);
    n->izq = Izq;
    n->der = NULL;
    return n;
}

// ! declaracion de casteo narrowing
Nodo* Casteo_Narrowing(char* Tipo1, char* Identificador, char* ParseType, char* Identificador2) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_CASTEO_NARROWING;
    n->nombre = strdup(ParseType);
    n->valor.varType = strdup(Tipo1);
    n->izq = Variable_Ref(Identificador);
    n->der = Variable_Ref(Identificador2);
    return n;
}

// ! Declaracion de variable con valor
Nodo* Var_Declaration(char* Tipo, char* Nombre, Nodo* Izq) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_DECLARATION;
    n->nombre = strdup(Nombre);
    n->valor.varType = strdup(Tipo);
    n->izq = Izq;
    n->der = NULL;
    return n;
}

// ! Nodo para identificador de variable { Nombre de variable }
Nodo* Identificador_Ref(char* nombre) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_IDENTIFICADOR;
    n->nombre = strdup(nombre);
    n->izq = n->der = NULL;
    return n;
}

Nodo* Asignacion_Variable(char* Nombre, char* Op, Nodo* Izq) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_ASIGNACION; 
    n->nombre = strdup(Nombre);
    n->valor.op_bool = strdup(Op);
    n->izq = Izq;
    n->der = NULL;
    return n;
}

// ? ------------------------------------------------------------------------------------------------------------

// ! Nodo Booleano, hace la logica de las operaciones booleanas
Nodo* And(Nodo* Izq, Nodo* Der) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_AND;
    n->izq = Izq;
    n->der = Der;
    return n;
}

Nodo* Or(Nodo* Izq, Nodo* Der) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_OR;
    n->izq = Izq;
    n->der = Der;
    return n;
}

Nodo* Not(Nodo* Neg) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_NOT;
    n->izq = Neg;
    n->der = NULL;
    return n;
}

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

// ! Numero double normal * * * *
Nodo* Terminal_Double(float valor) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_DOUBLE;  
    n->valor.d_val = (double)valor;
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

// ! Booleano normal * * * * 
Nodo* Terminal_Bool(int valor) {
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

// ! Valor null por defecto
Nodo* Terminal_Null(char* valor) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_NULL;
    n->valor.null_val = valor;
    n->izq = n->der = NULL;
    return n;
}

Nodo* Mayor_A(Nodo* Izq, Nodo* Der) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_MAYOR_A;
    n->izq = Izq;
    n->der = Der;
    return n;
}

Nodo* Menor_A(Nodo* Izq, Nodo* Der) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_MENOR_A;
    n->izq = Izq;
    n->der = Der;
    return n;
}

Nodo* Mayor_Igual_A(Nodo* Izq, Nodo* Der) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_MAYOR_IGUAL_A;
    n->izq = Izq;
    n->der = Der;
    return n;
}

Nodo* Menor_Igual_A(Nodo* Izq, Nodo* Der) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_MENOR_IGUAL_A;
    n->izq = Izq;
    n->der = Der;
    return n;
}

Nodo* Igual_Igual(Nodo* Izq, Nodo* Der) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_IGUAL_IGUAL;
    n->izq = Izq;
    n->der = Der;
    return n;
}

Nodo* Diferente_Que(Nodo* Izq, Nodo* Der) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_DIFERENTE_QUE;
    n->izq = Izq;
    n->der = Der;
    return n;
}

Nodo* Nodo_Vacio(const char* mensaje) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_NULL;
    n->valor.s_val = strdup(mensaje);
    n->izq = n->der = NULL;
    return n;
}

Nodo* ListaInstrucciones(Nodo* instr, Nodo* resto) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_LISTA;
    n->izq = instr;
    n->der = resto;
    return n;
}

Nodo** Lista_Vector(Nodo* valor) {
    Nodo** lista = malloc(2 * sizeof(Nodo*)); // Espacio para 1 elemento + NULL
    lista[0] = valor;
    lista[1] = NULL; // Marcador de fin de lista
    return lista;
}

Nodo** Add_Valor_Vector(Nodo** lista, Nodo* valor) {
    // Reasignar memoria para la nueva lista
    int i = 0;
    while (lista[i] != NULL) i++; // Contar elementos actuales
    lista = realloc(lista, (i + 2) * sizeof(Nodo*)); // +1 para el nuevo elemento +1 para NULL
    lista[i] = valor; // Agregar nuevo valor
    lista[i + 1] = NULL; // Mantener el marcador de fin de lista
    return lista;
}

Nodo* Make_StringJoin(char* tipo, char* Separador, Nodo** lista) {
    // Quitar las comillas del separador si existen
    char separador_str[256];
    size_t len = strlen(Separador);
    if (len >= 2 && Separador[0] == '"' && Separador[len - 1] == '"') {
        strncpy(separador_str, Separador + 1, len - 2);
        separador_str[len - 2] = '\0';
    } else {
        strncpy(separador_str, Separador, sizeof(separador_str) - 1);
        separador_str[sizeof(separador_str) - 1] = '\0';
    }

    printf("el separador es: '%s'\n", separador_str);

    //evaluar la lista de nodos y concatenar sus valores en una sola cadena
    char resultado[1000] = ""; // Cadena para almacenar el resultado final
    for (int i = 0; lista[i] != NULL; i++) {
        Valor val = Evaluar(lista[i]);
        if (val.tipo == VAL_STRING) {
            strcat(resultado, val.s_val);
            if (lista[i + 1] != NULL) {
                strcat(resultado, separador_str); // Agregar el separador entre elementos
            }
        }
    }

    // Asignar el resultado final al nodo y retornarlo
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_STRING;
    n->valor.s_val = strdup(resultado);
    n->izq = n->der = NULL;
    return n;
}

Nodo* Parse_Expression(char* Identificador, char* TipoVar, char* ParseType, Nodo* expr) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_PARSEO;
    n->nombre = strdup(Identificador);
    n->valor.varType = strdup(TipoVar);
    n->valor.op_bool = strdup(ParseType);
    n->izq = expr;
    n->der = NULL;
    return n;
}