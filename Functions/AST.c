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

    // ! printf("el separador es: '%s'\n", separador_str);

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

Nodo* Sentencia_If_Simple(Nodo* condicion, Nodo* instrucciones) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_IF_SIMPLE;
    n->izq = condicion;
    n->der = instrucciones;
    n->nombre = NULL;
    return n;
}

Nodo* Sentencia_If_Else(Nodo* condicion, Nodo* instrucciones_if, Nodo* instrucciones_else) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_IF_ELSE;
    n->izq = condicion;
    n->der = instrucciones_if;
    n->nodo_else = instrucciones_else; // Usamos valor.nodo_else para almacenar las instrucciones else
    n->nombre = NULL;
    return n;
}

// * Lista de nodos que representan las sentencias else-if
Nodo* Sentencia_ElseIf(Nodo* condicion, Nodo* instrucciones, Nodo* siguiente_else_if) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_ELSE_IF_LIST;
    n->izq = condicion;
    n->der = instrucciones;
    n->siguiente = siguiente_else_if; // Enlaza al siguiente else-if
    n->nombre = NULL;
    return n;
}

Nodo* If_Else_One(Nodo* condicion, Nodo* instrucciones_else) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_IF_SIMPLE; // Reutilizamos el nodo IF_SIMPLE para el else
    n->izq = condicion;
    n->der = instrucciones_else;
    n->nombre = NULL;
    return n;
}

Nodo* Sentencia_If_ElseIf_Else(Nodo* condicion, Nodo* instrucciones_if, 
                                Nodo* instrucciones_else_if, Nodo** lista_else_if, Nodo* instrucciones_else) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_IF_ELSE_IF;
    n->izq = condicion;
    n->der = instrucciones_if;
    n->nodo_else = instrucciones_else; // Usamos valor.nodo_else para almacenar las instrucciones else
    n->siguiente = instrucciones_else_if; // Enlaza al primer else-if
    n->lista_nodos = lista_else_if; // Almacena la lista de else-if
    n->nombre = NULL;
    return n;
}

Nodo* Vector_Auto(char* Instruccion, char* TipoDato, Nodo* LlenadoAuto) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_VECTOR_AUTO;
    n->nombre = strdup(Instruccion);
    n->izq = LlenadoAuto;
    n->der = NULL;
    n->valor.varType = strdup(TipoDato);
    return n;
}

Nodo* Declaration_Vector(char* DataType, char* Identificador, Nodo* TipoVector) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_DECLARATION_VECTOR;
    n->nombre = strdup(Identificador);
    n->valor.varType = strdup(DataType);
    n->izq = TipoVector;
    n->der = NULL;
    return n;
}

Nodo* Valores_Vector(Nodo** lista) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_VALORES_VECTOR_LIST;
    n->lista_nodos = lista;
    n->izq = n->der = NULL;
    n->nombre = NULL;
    return n;
}

Nodo* Matriz_Auto(char* Tipo, Nodo* Val1, Nodo* Val2) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_MATRIZ_AUTO;
    n->nombre = strdup(Tipo);
    n->izq = Val1;
    n->der = Val2;
    return n;
}

Nodo* Declaration_Matriz(char* DataType, char* Identificador, Nodo* TipoMatriz) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_DECLARATION_MATRIX;
    n->nombre = strdup(Identificador);
    n->valor.varType = strdup(DataType);
    n->izq = TipoMatriz;
    n->der = NULL;
    return n;
}

Nodo* For_Condition(Nodo* Declaration, Nodo* Condicion, char* Identificador, char* IncOrDec) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_FOR_CONDITION;
    n->izq = Declaration;
    n->der = Condicion;
    n->nombre = strdup(Identificador);
    n->valor.op_bool = strdup(IncOrDec); // "++" o "--"
    return n;
}

Nodo* For_Sentence(Nodo* ForCondition, Nodo* instrucciones) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_FOR_SENTENCE;
    n->izq = ForCondition;
    n->der = instrucciones;
    n->nombre = NULL;
    return n;
}

Nodo* Plus_Minus_Var(char* Identificador, char* IncOrDec) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_PLUS_MINUS_VAR; 
    n->nombre = strdup(Identificador);
    n->valor.op_bool = strdup(IncOrDec); // "++" o "--"
    n->izq = NULL;
    n->der = NULL;
    return n;
}

Nodo* While_Sentence(Nodo* condicion, Nodo* instrucciones) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_WHILE_SENTENCE;
    n->izq = condicion;
    n->der = instrucciones;
    n->nombre = NULL;
    return n;
}

Nodo* Switch_Default(Nodo* instrucciones) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_SWITCH_DEFAULT; // Reutilizamos el nodo SWITCH_DEFAULT para el default
    n->izq = instrucciones;
    n->der = NULL;
    n->nombre = NULL;
    return n;
}

Nodo* Switch_Case_One(Nodo* condicion, Nodo* instrucciones) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_SWITCH_CASE_ONE;
    n->izq = condicion;
    n->der = instrucciones;
    n->nombre = NULL;
    return n;
}

Nodo* Switch_Sentence(char* Identificador_Comparador, Nodo* Case_One, Nodo** List_Cases, Nodo* Default_Case) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_SWITCH_SENTENCE;
    n->nombre = strdup(Identificador_Comparador);
    n->izq = Case_One; // Primer caso obligatorio
    n->der = NULL;
    n->lista_nodos = List_Cases; // Lista de casos adicionales (puede ser NULL)
    n->nodo_else = Default_Case; // Caso default (puede ser NULL)
    return n;
}

Nodo* Continue_Word() {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_CONTINUE;
    n->izq = n->der = NULL;
    n->nombre = NULL;
    return n;
}

Nodo* Break_Word() {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_BREAK;
    n->izq = n->der = NULL;
    n->nombre = NULL;
    return n;
}

Nodo* Funtion_Declaration(char* Tipo, char* Identificador, Nodo** Parametros, Nodo* Instrucciones) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_FUNCTION_DECLARATION;
    n->nombre = strdup(Identificador);
    n->valor.varType = strdup(Tipo);
    n->lista_nodos = Parametros; // Lista de parámetros (puede ser NULL)
    n->izq = Instrucciones; // Instrucciones de la función
    n->der = NULL;
    return n;
}

Nodo* Function_Call(char* Identificador) {
    Nodo* n = malloc(sizeof(Nodo));
    n->tipo = NODO_FUNCTION_CALL;
    n->nombre = strdup(Identificador);
    n->izq = n->der = NULL;
    n->lista_nodos = NULL; // No hay parámetros
    return n;
}
