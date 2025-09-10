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
        return;
    }

    //Verificar si la variable es de tipo int solamente
    for (int i = 0; i < num_vars; i++) {
        if (strcmp(tabla_Variables[i].nombreVariable, Nombre) == 0) {
            if (tabla_Variables[i].tipo_Variable != TIPO_INT) {
                printf(" ❌ Error: La variable '%s' no es de tipo int, no se puede usar operador especial\n", Nombre);
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
}












