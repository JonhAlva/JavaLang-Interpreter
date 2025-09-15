#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tabla_Simbolos.h"
#include "Evaluate.h"

Variable tabla_Variables[MAX_VARS];
int num_vars = 0;

Error_Variable lista_Errores[MAX_ERRORS];
int num_errores = 0;

Vectores lista_Vectores[MAX_VECTORES];
int num_vectores = 0;

Nodo* tabla_Funciones[MAX_FUNCTIONS];
int num_funciones = 0;

//! implementar una condicion para saber si hay una variable repetida

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

void AsignarVariable_Char(char* Nombre, char valor) {
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
                    n->valor.b_val = tabla_Variables[i].valor.b_val ? 1 : 0; // Condicion añadida para saber si es true o false
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
    lista_Errores[num_errores].Num = num_errores;
    lista_Errores[num_errores].Desc_Error = "Variable no Encontrada";
    lista_Errores[num_errores].Tipo_Error = Nombre;
    num_errores++;
    return n;
}

void Actualizar_Variable(char* Nombre, Valor nuevo_valor) {
    // Verificar si la variable existe
    int variable_encontrada = 0;
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            variable_encontrada = 1;
            break;
        }
    }

    // Si la variable no fue encontrada
    if (!variable_encontrada) {
        printf(" ❌ Error: La variable '%s' no ha sido declarada\n", Nombre);
        lista_Errores[num_errores].Num = num_errores;
        lista_Errores[num_errores].Desc_Error = "Variable no Encontrada";
        lista_Errores[num_errores].Tipo_Error = Nombre;
        num_errores++;
        return;
    }
    // Actualizar el valor de la variable según su tipo
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            switch (tabla_Variables[i].tipo_Variable) {
                case TIPO_INT:
                    if (nuevo_valor.tipo == VAL_INT) {
                        tabla_Variables[i].valor.i_val = nuevo_valor.i_val;
                        printf(" » ✅ Variable '%s' Actualizada! \n", Nombre);
                    }
                    break;
                case TIPO_FLOAT:
                    if (nuevo_valor.tipo == VAL_FLOAT) {
                        tabla_Variables[i].valor.f_val = nuevo_valor.f_val;
                        printf(" » ✅ Variable '%s' Actualizada! \n", Nombre);
                    }
                    break;
                case TIPO_STRING:
                    if (nuevo_valor.tipo == VAL_STRING) {
                        free(tabla_Variables[i].valor.s_val); // Liberar memoria anterior
                        tabla_Variables[i].valor.s_val = strdup(nuevo_valor.s_val);
                        printf(" » ✅ Variable '%s' Actualizada! \n", Nombre);
                    }
                    break;
                case TIPO_BOOLEAN:
                    if (nuevo_valor.tipo == VAL_BOOL) {
                        tabla_Variables[i].valor.b_val = nuevo_valor.b_val;
                        printf(" » ✅ Variable '%s' Actualizada! \n", Nombre);
                    }
                    break;
                case TIPO_CHAR:
                    if (nuevo_valor.tipo == VAL_CHAR) {
                        tabla_Variables[i].valor.c_val = nuevo_valor.c_val;
                        printf(" » ✅ Variable '%s' Actualizada! \n", Nombre);
                    }
                    break;
                case TIPO_LONG:
                    if (nuevo_valor.tipo == VAL_INT) {
                        tabla_Variables[i].valor.i_val = nuevo_valor.i_val;
                        printf(" » ✅ Variable '%s' Actualizada! \n", Nombre);
                    }
                    break;
                case TIPO_SHORT:
                    if (nuevo_valor.tipo == VAL_INT) {
                        tabla_Variables[i].valor.i_val = nuevo_valor.i_val;
                        printf(" » ✅ Variable '%s' Actualizada! \n", Nombre);
                    }
                    break;
                case TIPO_DOUBLE:
                    if (nuevo_valor.tipo == VAL_DOUBLE) {
                        tabla_Variables[i].valor.d_val = nuevo_valor.d_val;
                        printf(" » ✅ Variable '%s' Actualizada! \n", Nombre);
                    }
                    break;
                case TIPO_BYTE:
                    if (nuevo_valor.tipo == VAL_CHAR) {
                        tabla_Variables[i].valor.c_val = nuevo_valor.c_val;
                        printf(" » ✅ Variable '%s' Actualizada! \n", Nombre);
                    }
                    break;
            }
            return;
        }
    }
}

void Asignacion_Especial(char* Nombre, char* operador, Valor nuevo_valor) {
    // Verificar si la variable existe
    int variable_encontrada = 0;
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            variable_encontrada = 1;
            break;
        }
    }

    // Si la variable no fue encontrada
    if (!variable_encontrada) {
        printf(" ❌ Error: La variable '%s' no ha sido declarada\n", Nombre);
        lista_Errores[num_errores].Num = num_errores;
        lista_Errores[num_errores].Desc_Error = "Variable no Declarada";
        lista_Errores[num_errores].Tipo_Error = Nombre;
        num_errores++;
        return;
    }

    //Verificar si la variable es de tipo int solamente
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            if (tabla_Variables[i].tipo_Variable != TIPO_INT) {
                printf(" ❌ Error: La variable '%s' no es de tipo int, no se puede usar operador especial\n", Nombre);
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "Variable no es tipo Int";
                lista_Errores[num_errores].Tipo_Error = Nombre;
                num_errores++;
                return;
            }
            break;
        }
    }

    //Variable que hace una copia del valor actual de la variable
    int valor_actual;
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            valor_actual = tabla_Variables[i].valor.i_val;
            break;
        }
    }

    // Dependiendo el operador se hara la operacion correspondiente
    if (strcmp(operador, "+=") == 0) {
        valor_actual += nuevo_valor.i_val;
        Actualizar_Variable(Nombre, (Valor){.tipo = VAL_INT, .i_val = valor_actual});
    } else if (strcmp(operador, "-=") == 0) {
        valor_actual -= nuevo_valor.i_val;
        Actualizar_Variable(Nombre, (Valor){.tipo = VAL_INT, .i_val = valor_actual});
    } else if (strcmp(operador, "*=") == 0) {
        valor_actual *= nuevo_valor.i_val;
        Actualizar_Variable(Nombre, (Valor){.tipo = VAL_INT, .i_val = valor_actual});
    } else if (strcmp(operador, "/=") == 0) {
        valor_actual /= nuevo_valor.i_val;
        Actualizar_Variable(Nombre, (Valor){.tipo = VAL_INT, .i_val = valor_actual});
    } else if (strcmp(operador, "%=") == 0) {
        valor_actual %= nuevo_valor.i_val;
        Actualizar_Variable(Nombre, (Valor){.tipo = VAL_INT, .i_val = valor_actual});
    } else if (strcmp(operador, "^=") == 0) {
        valor_actual ^= nuevo_valor.i_val;
        Actualizar_Variable(Nombre, (Valor){.tipo = VAL_INT, .i_val = valor_actual});
    } else if (strcmp(operador, "&=") == 0) {
        valor_actual &= nuevo_valor.i_val;
        Actualizar_Variable(Nombre, (Valor){.tipo = VAL_INT, .i_val = valor_actual});
    } else if (strcmp(operador, "|=") == 0) {
        valor_actual |= nuevo_valor.i_val;
        Actualizar_Variable(Nombre, (Valor){.tipo = VAL_INT, .i_val = valor_actual});
    } else if (strcmp(operador, "<<=") == 0) {
        valor_actual <<= nuevo_valor.i_val;
        Actualizar_Variable(Nombre, (Valor){.tipo = VAL_INT, .i_val = valor_actual});
    } else if (strcmp(operador, ">>=") == 0) {
        valor_actual >>= nuevo_valor.i_val;
        Actualizar_Variable(Nombre, (Valor){.tipo = VAL_INT, .i_val = valor_actual});
    } else {
        printf(" ❌ Error: Operador '%s' no reconocido para asignacion\n", operador);
        lista_Errores[num_errores].Num = num_errores;
        lista_Errores[num_errores].Desc_Error = "Operador no reconocido para asignacion";
        lista_Errores[num_errores].Tipo_Error = "Asignacion Especial";
        num_errores++;
    }
}

void Casteo_Narrow(char* Tipo1, char* Identificador, char* ParseType, char* Identificador2) {
    // Verificar si la variable existe
    int variable_encontrada = 0;
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Identificador2) == 0) {
            variable_encontrada = 1;
            break;
        }
    }

    // Si la variable no fue encontrada
    if (!variable_encontrada) {
        printf(" ❌ Error: La variable '%s' no ha sido declarada\n", Identificador2);
        lista_Errores[num_errores].Num = num_errores;
        lista_Errores[num_errores].Desc_Error = "Variable no Declarada";
        lista_Errores[num_errores].Tipo_Error = Identificador2;
        num_errores++;
        return;
    }

    // Verificar si el tipo de dato es compatible para casteo narrowing
    int tipo_compatible = 0;
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Identificador2) == 0) {
            if ((strcmp(Tipo1, "int") == 0 && tabla_Variables[i].tipo_Variable == TIPO_FLOAT) ||    // 1 EN INT
                (strcmp(Tipo1, "char") == 0 && tabla_Variables[i].tipo_Variable == TIPO_INT) ||     // 0 EN INT
                (strcmp(Tipo1, "float") == 0 && tabla_Variables[i].tipo_Variable == TIPO_DOUBLE)) {  // 8 EN INT
                // * printf(" » Variable '%s' encontrada con tipo compatible: %d\n", Identificador2, tabla_Variables[i].tipo_Variable);
                tipo_compatible = 1;
            }
            break;
        }
    }

    if (!tipo_compatible) {
        printf(" ❌ Error: No se puede realizar casteo narrowing de '%s' a '%s'\n", ParseType, Tipo1);
        lista_Errores[num_errores].Num = num_errores;
        lista_Errores[num_errores].Desc_Error = "No se puede realizar casteo narrowing";
        lista_Errores[num_errores].Tipo_Error = "Casteo";
        num_errores++;
        return;
    }

    // ! Realizar el casteo narrowing y asignar como nueva variable

    // float -> int
    if (strcmp(Tipo1, "int") == 0) {
        // Buscar Identificador2 y castear su valor
        for (int i = 0; i < num_vars; i++) {
            if (strcmp(tabla_Variables[i].nombreVariable, Identificador2) == 0 && tabla_Variables[i].tipo_Variable == TIPO_FLOAT) {
                int valor_casteado = (int)tabla_Variables[i].valor.f_val;
                AsignarVariable_Int(Identificador, valor_casteado);
                printf(" » 🉑  Casteo Narrowing realizado: float -> int para variable '%s'\n", Identificador);
                return;
            }
        }
    }
    // int -> char
    else if (strcmp(Tipo1, "char") == 0) {
        for (int i = 0; i < num_vars; i++) {
            if (strcmp(tabla_Variables[i].nombreVariable, Identificador2) == 0 && tabla_Variables[i].tipo_Variable == TIPO_INT) {
                char valor_casteado = (char)tabla_Variables[i].valor.i_val;
                AsignarVariable_Char(Identificador, valor_casteado);
                printf(" » 🉑  Casteo Narrowing realizado: int -> char para variable '%s'\n", Identificador);
                return;
            }
        }
    }
    // double -> float
    else if (strcmp(Tipo1, "float") == 0) {
        for (int i = 0; i < num_vars; i++) {
            if (strcmp(tabla_Variables[i].nombreVariable, Identificador2) == 0 && tabla_Variables[i].tipo_Variable == TIPO_DOUBLE) {
                float valor_casteado = (float)tabla_Variables[i].valor.d_val;
                AsignarVariable_Float(Identificador, valor_casteado);
                printf(" » 🉑  Casteo Narrowing realizado: double -> float para variable '%s'\n", Identificador);
                return;
            }
        }
    }
}

Nodo* Compare_Equals(char* Identificador, Nodo* Izq) {
    
    // Verificar si la variable existe
    int variable_encontrada = 0;
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Identificador) == 0) {
            variable_encontrada = 1;
            break;
        }
    }

    // Si la variable no fue encontrada
    if (!variable_encontrada) {
        printf(" ❌ Error: La variable '%s' no ha sido declarada\n", Identificador);
        lista_Errores[num_errores].Num = num_errores;
        lista_Errores[num_errores].Desc_Error = "Variable no Declarada";
        lista_Errores[num_errores].Tipo_Error = Identificador;
        num_errores++;
        Nodo* n = malloc(sizeof(Nodo));
        n->tipo = NODO_NULL;
        n->valor.null_val = "-Var Not Found Err"; // Error de variable no encontrada
        n->izq = n->der = NULL;
        return n;
    }

    // Verificar si el tipo de dato es String
    int es_string = 0;
    if (Izq->tipo != NODO_STRING) {
        es_string = 1;
    } 

    if (!es_string) {
        printf(" ❌ Error: La funcion .equals solo es compatible con tipo String\n");
        lista_Errores[num_errores].Num = num_errores;
        lista_Errores[num_errores].Desc_Error = "Solo se permite tipo String";
        lista_Errores[num_errores].Tipo_Error = "Funcion .equals";
        num_errores++;
        Nodo* n = malloc(sizeof(Nodo));
        n->tipo = NODO_NULL;
        n->valor.null_val = "-Var Not String Err"; // Error de variable no encontrada
        n->izq = n->der = NULL;
        return n;
    }

    //Evaluar el contenido del nodo y compararlo con s_val del identificador
    Valor valor_izq = Evaluar(Izq);

    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Identificador) == 0) {
            if (tabla_Variables[i].tipo_Variable == TIPO_STRING) {
                // ! printf(" » Comparando '%s' con '%s'\n", tabla_Variables[i].valor.s_val, valor_izq.s_val);
                if (strcmp(tabla_Variables[i].valor.s_val, valor_izq.s_val) == 0) {
                    Nodo* n = malloc(sizeof(Nodo));
                    n->tipo = NODO_BOOL;
                    n->valor.b_val = 1;
                    n->izq = n->der = NULL;
                    return n;
                } else {
                    Nodo* n = malloc(sizeof(Nodo));
                    n->tipo = NODO_BOOL;
                    n->valor.b_val = 0;
                    n->izq = n->der = NULL;
                    return n;
                }
            }
            break;
        }
    }

}

void Asignacion_Default(char* Nombre, char* Tipo) {
    // Asignar valor por defecto según el tipo de dato
    if (strcmp(Tipo, "int") == 0) {
        AsignarVariable_Int(Nombre, 0);
    } else if (strcmp(Tipo, "float") == 0) {
        AsignarVariable_Float(Nombre, 0.0f);
    } else if (strcmp(Tipo, "boolean") == 0) {
        AsignarVariable_Boolean(Nombre, 0); // false
    } else if (strcmp(Tipo, "char") == 0) {
        AsignarVariable_Char(Nombre, 78); // Carácter nulo "N"
    } else if (strcmp(Tipo, "String") == 0) {
        AsignarVariable_String(Nombre, "-null");
    } else if (strcmp(Tipo, "long") == 0) {
        AsignarVariable_Long(Nombre, 0L);
    } else if (strcmp(Tipo, "byte") == 0) {
        AsignarVariable_Byte(Nombre, 0);
    } else if (strcmp(Tipo, "short") == 0) {
        AsignarVariable_Short(Nombre, 0);
    } else if (strcmp(Tipo, "double") == 0) {
        AsignarVariable_Double(Nombre, 0.0);
    } else {
        printf(" »   Tipo de dato desconocido en declaracion * \n");
        lista_Errores[num_errores].Num = num_errores;
        lista_Errores[num_errores].Desc_Error = "Tipo de dato desconocido en declaracion";
        lista_Errores[num_errores].Tipo_Error = "Asignacion Default";
        num_errores++;
    }
    
}

void AsignarParseo_Variable(char* Nombre, char* Tipo, char* Parse_Type, Valor valor) {

    //verificar si valor es tipo string
    int es_string = 0;
    if (valor.tipo == VAL_STRING) {
        es_string = 1;
    }

    //convertir el string en un numero
    if (es_string) {
        // Intentar convertir a entero
        char* endptr;
        long int_val = strtol(valor.s_val, &endptr, 10);

        if (*endptr == '\0' && strcmp(Parse_Type, "int") == 0) {
            // Si la conversión fue exitosa
            AsignarVariable_Int(Nombre, int_val);
            printf(" » 🔀  Parseo realizado a Int para variable '%s'\n", Nombre);
            return;
        }

        // Intentar convertir a float
        float float_val = strtof(valor.s_val, &endptr);
        if (*endptr == '\0' && strcmp(Parse_Type, "float") == 0) {
            AsignarVariable_Float(Nombre, float_val);
            printf(" » 🔀  Parseo realizado a Float para variable '%s'\n", Nombre);
            return;
        }

        // Intentar convertir a double
        double double_val = strtod(valor.s_val, &endptr);
        if (*endptr == '\0' && strcmp(Parse_Type, "double") == 0) {
            AsignarVariable_Double(Nombre, double_val);
            printf(" » 🔀  Parseo realizado a Double para variable '%s'\n", Nombre);
            return;
        }

        // Si no se pudo convertir, asignar null
        printf(" » ❌ Error: Parseo fallido para variable '%s' el valor ingresado no es un numero \n", Nombre);
        lista_Errores[num_errores].Num = num_errores;
        lista_Errores[num_errores].Desc_Error = "El valor ingresado no es un numero";
        lista_Errores[num_errores].Tipo_Error = "Parseo Numerico";
        num_errores++;
    } else {
        // Convertir el valor que venga a cadena
        char buffer[64];
        switch (valor.tipo) {
            case VAL_INT:
                snprintf(buffer, sizeof(buffer), "%d", valor.i_val);
                break;
            case VAL_FLOAT:
                snprintf(buffer, sizeof(buffer), "%f", valor.f_val);
                break;
            case VAL_DOUBLE:
                snprintf(buffer, sizeof(buffer), "%lf", valor.d_val);
                break;
            case VAL_BOOL:
                snprintf(buffer, sizeof(buffer), "%s", valor.b_val ? "true" : "false");
                break;
            case VAL_CHAR:
                snprintf(buffer, sizeof(buffer), "%c", valor.c_val);
                break;
            default:
                snprintf(buffer, sizeof(buffer), "unknown");
                break;
        }
        // Usar buffer como cadena resultante
        AsignarVariable_String(Nombre, buffer);
        printf(" » 🔀  Valor convertido a String para variable '%s'\n", Nombre);
    }
}

void Agregar_Funcion(Nodo* funcion) {
    if (num_funciones < MAX_FUNCTIONS) {
        tabla_Funciones[num_funciones] = funcion;
        num_funciones++;
    } else {
        printf(" ❌ Error: Límite de funciones alcanzado\n");
        lista_Errores[num_errores].Num = num_errores;
        lista_Errores[num_errores].Desc_Error = "Limite de funciones alcanzado";
        lista_Errores[num_errores].Tipo_Error = "Funcion";
        num_errores++;
    }
}

Nodo* Acceso_Funcion(char* Nombre) {
    for (int i = 0; i < num_funciones; i++) {
        if (strcmp(tabla_Funciones[i]->nombre, Nombre) == 0) {
            return tabla_Funciones[i];
        }
    }
    printf(" ❌ Error: La función '%s' no ha sido declarada\n", Nombre);
    lista_Errores[num_errores].Num = num_errores;
    lista_Errores[num_errores].Desc_Error = "Funcion no Encontrada";
    lista_Errores[num_errores].Tipo_Error = Nombre;
    num_errores++;
    return NULL;
}

// ! FUNCIONES DE APOYO PARA LA TABLA DE SIMBOLOS --------------------
void Print_Specific_Variable(char* Nombre) {
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            printf(" » Variable: %s | Tipo: %d | Valor: ", tabla_Variables[i].nombreVariable, tabla_Variables[i].tipo_Variable);
            switch (tabla_Variables[i].tipo_Variable) {
                case TIPO_INT:
                    printf("%d\n", tabla_Variables[i].valor.i_val);
                    break;
                case TIPO_FLOAT:
                    printf("%f\n", tabla_Variables[i].valor.f_val);
                    break;
                case TIPO_STRING:
                    printf("%s\n", tabla_Variables[i].valor.s_val);
                    break;
                case TIPO_BOOLEAN:
                    printf("%s\n", tabla_Variables[i].valor.b_val ? "true" : "false");
                    break;
                case TIPO_CHAR:
                    printf("%c\n", tabla_Variables[i].valor.c_val);
                    break;
                case TIPO_LONG:
                    printf("%ld\n", (long)tabla_Variables[i].valor.i_val);
                    break;
                case TIPO_SHORT:
                    printf("%d\n", (short)tabla_Variables[i].valor.i_val);
                    break;
                case TIPO_DOUBLE:
                    printf("%lf\n", tabla_Variables[i].valor.d_val);
                    break;
                case TIPO_BYTE:
                    printf("%d\n", (unsigned char)tabla_Variables[i].valor.c_val);
                    break;
                default:
                    printf("Tipo desconocido\n");
            }
            return;
        }
    }
    printf(" ❌ Error: La variable '%s' no ha sido declarada\n", Nombre);
    lista_Errores[num_errores].Num = num_errores;
    lista_Errores[num_errores].Desc_Error = "Variable no Encontrada";
    lista_Errores[num_errores].Tipo_Error = "Variable";
    num_errores++;
}

void Print_All_Variables() {
    FILE *f = fopen("tabla_simbolos.dot", "w");
    if (f == NULL) {
        printf("Error creating DOT file\n");
        return;
    }

    // Write DOT header
    fprintf(f, "digraph tabla_simbolos {\n");
    fprintf(f, "    rankdir=LR;\n");
    fprintf(f, "    node [shape=record];\n\n");
    
    // Create a single node with all variables
    fprintf(f, "    tabla [label=\"{Tabla de Símbolos");

    // Add each variable as a separate field
    for (int i = 0; i < num_vars; i++) {
        fprintf(f, "|{%s|", tabla_Variables[i].nombreVariable);
        
        // Print type
        switch (tabla_Variables[i].tipo_Variable) {
            case TIPO_INT: fprintf(f, "int|"); break;
            case TIPO_FLOAT: fprintf(f, "float|"); break;
            case TIPO_STRING: fprintf(f, "String|"); break;
            case TIPO_BOOLEAN: fprintf(f, "boolean|"); break;
            case TIPO_CHAR: fprintf(f, "char|"); break;
            case TIPO_LONG: fprintf(f, "long|"); break;
            case TIPO_SHORT: fprintf(f, "short|"); break;
            case TIPO_DOUBLE: fprintf(f, "double|"); break;
            case TIPO_BYTE: fprintf(f, "byte|"); break;
            default: fprintf(f, "unknown|"); break;
        }

        // Print value with proper escaping
        switch (tabla_Variables[i].tipo_Variable) {
            case TIPO_INT:
                fprintf(f, "%d}", tabla_Variables[i].valor.i_val);
                break;
            case TIPO_FLOAT:
                fprintf(f, "%.2f}", tabla_Variables[i].valor.f_val);
                break;
            case TIPO_STRING:
                // Escape special characters in strings
                fprintf(f, "\\\"%s\\\"}", tabla_Variables[i].valor.s_val);
                break;
            case TIPO_BOOLEAN:
                fprintf(f, "%s}", tabla_Variables[i].valor.b_val ? "true" : "false");
                break;
            case TIPO_CHAR:
                // Escape special characters for chars
                if (tabla_Variables[i].valor.c_val == '"') 
                    fprintf(f, "\\\"\\\"}");
                else if (tabla_Variables[i].valor.c_val == '\\')
                    fprintf(f, "\\\\}");
                else
                    fprintf(f, "%c}", tabla_Variables[i].valor.c_val);
                break;
            case TIPO_LONG:
                fprintf(f, "%ld}", (long)tabla_Variables[i].valor.i_val);
                break;
            case TIPO_SHORT:
                fprintf(f, "%d}", (short)tabla_Variables[i].valor.i_val);
                break;
            case TIPO_DOUBLE:
                fprintf(f, "%.2lf}", tabla_Variables[i].valor.d_val);
                break;
            case TIPO_BYTE:
                fprintf(f, "%d}", (unsigned char)tabla_Variables[i].valor.c_val);
                break;
            default:
                fprintf(f, "unknown}");
        }
    }

    // Close the label and graph
    fprintf(f, "}\"];\n}\n");
    fclose(f);

    //printf(" » Archivo DOT generado como 'tabla_simbolos.dot'\n");
    // Generate PNG using system call
    system("dot -Tpng tabla_simbolos.dot -o tabla_simbolos.png");
    printf(" ✅ Imagen PNG generada como 'tabla_simbolos.png'\n");
}

void Print_All_Errors() {

    FILE *f = fopen("lista_errores.dot", "w");
    if (f == NULL) {
        printf("Error creating DOT file\n");
        return;
    }

    // Write DOT header
    fprintf(f, "digraph lista_errores {\n");
    fprintf(f, "    rankdir=LR;\n");
    fprintf(f, "    node [shape=record];\n\n");
    
    // Create a single node with all errors
    fprintf(f, "    errores [label=\"{Lista de Errores");

    // Add each error as a separate field
    for (int i = 0; i < num_errores; i++) {
        fprintf(f, "|{#%d|", lista_Errores[i].Num+1);
        fprintf(f, "%s|", lista_Errores[i].Tipo_Error);
        // Escape special characters in error descriptions
        char* desc = lista_Errores[i].Desc_Error;
        for (char* p = desc; *p; p++) {
            if (*p == '"' || *p == '\\') {
                fputc('\\', f); // Escape character
            }
            fputc(*p, f);
        }
        fprintf(f, "}");
    }

    // Close the label and graph
    fprintf(f, "}\"];\n}\n");
    fclose(f);

    //printf(" Archivo DOT generado como 'lista_errores.dot'\n");
    // Generate PNG using system call
    system("dot -Tpng lista_errores.dot -o lista_errores.png");
    printf(" ✅ Imagen PNG generada como 'lista_errores.png'\n");
}

void Clear_All_Errors() {
    num_errores = 0;
    printf(" ✅ Lista de errores limpiada\n");
}

void Clear_All_Variables() {
    num_vars = 0;
    printf(" ✅ Tabla de simbolos limpiada\n");
}

void Clear_All_Funciones() {
    num_funciones = 0;
    printf(" ✅ Tabla de funciones limpiada\n");
}

int CompararValores(Valor valor1, Valor valor2) {
    if (valor1.tipo != valor2.tipo) {
        return 0; // Tipos diferentes no son iguales
    }

    switch (valor1.tipo) {
        case VAL_INT:
            return valor1.i_val == valor2.i_val;
        case VAL_FLOAT:
            return valor1.f_val == valor2.f_val;
        case VAL_STRING:
            return strcmp(valor1.s_val, valor2.s_val) == 0;
        case VAL_BOOL:
            return valor1.b_val == valor2.b_val;
        case VAL_CHAR:
            return valor1.c_val == valor2.c_val;
        case VAL_DOUBLE:
            return valor1.d_val == valor2.d_val;
        default:
            return 0; // Tipo desconocido
    }
}