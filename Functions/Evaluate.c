#include "AST.h"
#include "Evaluate.h"
#include "Tabla_Simbolos.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

// * Este indice servira para hacer las acciones correspondientes
// * a la aritmetica permitiendo que el programa decida y vea
// * que tipo de dato es el que viene, mandamos un objeto valor para
// * almacenar el tipo y poder usarlo para ejecutar las operaciones

// * Evalua nodos
Valor Evaluar(Nodo* n) {
    Valor v;

    if (n == NULL) {
        v.tipo = VAL_NULL;
        v.null_val = "-Null Err"; // Error de nodo nulo
        return v;
    }

    // * if (!n) return v;

    switch (n->tipo) {

        case NODO_INT: // * ----------------------------------------------------------------------------------------
            v.tipo = VAL_INT;
            v.i_val = n->valor.i_val;
            return v;

        case NODO_FLOAT: // * ----------------------------------------------------------------------------------------
            v.tipo = VAL_FLOAT;
            v.f_val = n->valor.f_val;
            return v;

        case NODO_DOUBLE: // * ----------------------------------------------------------------------------------------
            v.tipo = VAL_DOUBLE;
            v.d_val = n->valor.d_val;
            return v;

        case NODO_STRING: {// * ----------------------------------------------------------------------------------------
            v.tipo = VAL_STRING;
            // Obtener longitud del string
            size_t len = strlen(n->valor.s_val);
            
            // Verificar si tiene comillas al inicio y al final
            if (len >= 2 && n->valor.s_val[0] == '"' && n->valor.s_val[len-1] == '"') {
                // Crear nuevo string sin comillas
                char* contenido = malloc(len - 1); // -2 por las comillas +1 por el null terminator
                strncpy(contenido, n->valor.s_val + 1, len - 2); // Copiar sin primera y última comilla
                contenido[len - 2] = '\0'; // Agregar null terminator
                v.s_val = contenido;
            } else {
                // Si no tiene comillas, copiar tal cual
                v.s_val = strdup(n->valor.s_val);
            }
            return v;
        }

        case NODO_BOOL: // * ----------------------------------------------------------------------------------------
            v.tipo = VAL_BOOL;
            v.b_val = n->valor.b_val;
            return v;

        case NODO_CHAR: // * ----------------------------------------------------------------------------------------
            v.tipo = VAL_CHAR;
            v.c_val = n->valor.c_val;
            return v;

        case NODO_NULL: // * ----------------------------------------------------------------------------------------
            v.tipo = VAL_NULL;
            v.null_val = n->valor.null_val;
            return v;

        case NODO_NOT: { // * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);

            if (izq.tipo == VAL_BOOL) {
            v.tipo = VAL_BOOL;
            v.b_val = !izq.b_val;
            return v;
            }
        }

        case NODO_MODULO: {
            Valor izq = Evaluar(n->izq);
            Valor der = Evaluar(n->der);

            // * Comprobar si son enteros
            if (izq.tipo == VAL_INT && der.tipo == VAL_INT) {
            v.tipo = VAL_INT;
            v.i_val = izq.i_val % der.i_val;
            return v;
            }

            // * Si ambos son char, usar su valor ASCII
            if (izq.tipo == VAL_CHAR && der.tipo == VAL_CHAR) {
            v.tipo = VAL_INT;
            v.i_val = ((int)izq.c_val) % ((int)der.c_val);
            return v;
            }

            // * Si uno es char y otro es int
            if (izq.tipo == VAL_CHAR && der.tipo == VAL_INT) {
            v.tipo = VAL_INT;
            v.i_val = ((int)izq.c_val) % der.i_val;
            return v;
            }
            if (izq.tipo == VAL_INT && der.tipo == VAL_CHAR) {
            v.tipo = VAL_INT;
            v.i_val = izq.i_val % ((int)der.c_val);
            return v;
            }
        }

        case NODO_SUMA: { // * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            Valor der = Evaluar(n->der);

            // * Concatenacion de valores en + si son strings o valores variables
            if (izq.tipo == VAL_STRING || der.tipo == VAL_STRING) {
                v.tipo = VAL_STRING;
                char temp[100];  // ! Buffer temporal para conversiones
                char* str_izq;
                char* str_der;

                // Convertir valor izquierdo a string
                switch(izq.tipo) {
                    case VAL_STRING:
                        str_izq = strdup(izq.s_val);
                        break;
                    case VAL_INT:
                        sprintf(temp, "%d", izq.i_val);
                        str_izq = strdup(temp);
                        break;
                    case VAL_FLOAT:
                        sprintf(temp, "%f", izq.f_val);
                        str_izq = strdup(temp);
                        break;
                    case VAL_DOUBLE:
                        sprintf(temp, "%lf", izq.d_val);
                        str_izq = strdup(temp);
                        break;
                    case VAL_BOOL:
                        str_izq = strdup(izq.b_val ? "true" : "false");
                        break;
                    case VAL_CHAR:
                        sprintf(temp, "%c", izq.c_val);
                        str_izq = strdup(temp);
                        break;
                    case VAL_NULL:
                        str_izq = strdup("null");
                        break;
                }

                // Convertir valor derecho a string
                switch(der.tipo) {
                    case VAL_STRING:
                        str_der = strdup(der.s_val);
                        break;
                    case VAL_INT:
                        sprintf(temp, "%d", der.i_val);
                        str_der = strdup(temp);
                        break;
                    case VAL_FLOAT:
                        sprintf(temp, "%f", der.f_val);
                        str_der = strdup(temp);
                        break;
                    case VAL_DOUBLE:
                        sprintf(temp, "%lf", der.d_val);
                        str_der = strdup(temp);
                        break;
                    case VAL_BOOL:
                        str_der = strdup(der.b_val ? "true" : "false");
                        break;
                    case VAL_CHAR:
                        sprintf(temp, "%c", der.c_val);
                        str_der = strdup(temp);
                        break;
                    case VAL_NULL:
                        str_der = strdup("null");
                        break;
                }
                // Concatenar strings
            v.s_val = malloc(strlen(str_izq) + strlen(str_der) + 1);
            strcpy(v.s_val, str_izq);
            strcat(v.s_val, str_der);
            // Liberar memoria temporal
            free(str_izq);
            free(str_der);
            return v;
        }

            // * Comprobar si son enteros
            if (izq.tipo == VAL_INT && der.tipo == VAL_INT) {
                v.tipo = VAL_INT;
                v.i_val = izq.i_val + der.i_val;
                return v;
            }

            // * Si viene un float, entonces tirar float
            if (izq.tipo == VAL_FLOAT || der.tipo == VAL_FLOAT) {
                v.tipo = VAL_FLOAT;
                float izq_val = (izq.tipo == VAL_INT) ? (float)izq.i_val : izq.f_val;
                float der_val = (der.tipo == VAL_INT) ? (float)der.i_val : der.f_val;
                v.f_val = izq_val + der_val;
                return v;
            }

        }

        case NODO_RESTA: { // * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            Valor der = Evaluar(n->der);

            // * Comprobar si son enteros
            if (izq.tipo == VAL_INT && der.tipo == VAL_INT) {
                v.tipo = VAL_INT;
                v.i_val = izq.i_val - der.i_val;
                return v;
            }

            // * Si viene un float, entonces tirar float
            if (izq.tipo == VAL_FLOAT || der.tipo == VAL_FLOAT) {
                v.tipo = VAL_FLOAT;
                float izq_val = (izq.tipo == VAL_INT) ? (float)izq.i_val : izq.f_val;
                float der_val = (der.tipo == VAL_INT) ? (float)der.i_val : der.f_val;
                v.f_val = izq_val - der_val;
                return v;
            }
        }

        case NODO_MULTIPLICACION: {// * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            Valor der = Evaluar(n->der);

            // * Comprobar si son enteros
            if (izq.tipo == VAL_INT && der.tipo == VAL_INT) {
                v.tipo = VAL_INT;
                v.i_val = izq.i_val * der.i_val;
                return v;
            }

            // * Si viene un float, entonces tirar float
            if (izq.tipo == VAL_FLOAT || der.tipo == VAL_FLOAT) {
                v.tipo = VAL_FLOAT;
                float izq_val = (izq.tipo == VAL_INT) ? (float)izq.i_val : izq.f_val;
                float der_val = (der.tipo == VAL_INT) ? (float)der.i_val : der.f_val;
                v.f_val = izq_val * der_val;
                return v;
            }
        }

        case NODO_DIVISION: {// * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            Valor der = Evaluar(n->der);

            // * Comprobar si son enteros
            if (izq.tipo == VAL_INT && der.tipo == VAL_INT) {

                if (der.i_val == 0) {
                    v.tipo = VAL_NULL;
                    v.null_val = "-Div/0 Err"; // Error de dividir en 0
                    return v;
                }

                v.tipo = VAL_INT;
                v.i_val = izq.i_val / der.i_val;
                return v;
            }

            // * Si viene un float, entonces tirar float
            if (izq.tipo == VAL_FLOAT || der.tipo == VAL_FLOAT) {

                if (der.f_val == 0) {
                    v.tipo = VAL_NULL;
                    v.null_val = "-Div/0 Err"; // Error de dividir en 0
                    return v;
                }

                v.tipo = VAL_FLOAT;
                float izq_val = (izq.tipo == VAL_INT) ? (float)izq.i_val : izq.f_val;
                float der_val = (der.tipo == VAL_INT) ? (float)der.i_val : der.f_val;
                v.f_val = izq_val / der_val;
                return v;
            }
            }
        case NODO_MAYOR_A:{// * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            Valor der = Evaluar(n->der);

            if (izq.tipo == VAL_INT && der.tipo == VAL_INT) {
            v.tipo = VAL_BOOL;
            v.b_val = (izq.i_val > der.i_val) ? 1 : 0;
            return v;
            }

            if (izq.tipo == VAL_FLOAT || der.tipo == VAL_FLOAT) {
            v.tipo = VAL_BOOL;
            float izq_val = (izq.tipo == VAL_INT) ? (float)izq.i_val : izq.f_val;
            float der_val = (der.tipo == VAL_INT) ? (float)der.i_val : der.f_val;
            v.b_val = (izq_val > der_val) ? 1 : 0;
            return v;
            }

            // Comparación de caracteres
            if (izq.tipo == VAL_CHAR && der.tipo == VAL_CHAR) {
            v.tipo = VAL_BOOL;
            v.b_val = (izq.c_val > der.c_val) ? 1 : 0;
            return v;
            }
        }

        case NODO_MENOR_A:{// * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            Valor der = Evaluar(n->der);

            if (izq.tipo == VAL_INT && der.tipo == VAL_INT) {
            v.tipo = VAL_BOOL;
            v.b_val = (izq.i_val < der.i_val) ? 1 : 0;
            return v;
            }

            if (izq.tipo == VAL_FLOAT || der.tipo == VAL_FLOAT) {
            v.tipo = VAL_BOOL;
            float izq_val = (izq.tipo == VAL_INT) ? (float)izq.i_val : izq.f_val;
            float der_val = (der.tipo == VAL_INT) ? (float)der.i_val : der.f_val;
            v.b_val = (izq_val < der_val) ? 1 : 0;
            return v;
            }

            // Comparación de caracteres
            if (izq.tipo == VAL_CHAR && der.tipo == VAL_CHAR) {
            v.tipo = VAL_BOOL;
            v.b_val = (izq.c_val < der.c_val) ? 1 : 0;
            return v;
            }
        }

        case NODO_MAYOR_IGUAL_A:{// * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            Valor der = Evaluar(n->der);

            if (izq.tipo == VAL_INT && der.tipo == VAL_INT) {
            v.tipo = VAL_BOOL;
            v.b_val = (izq.i_val >= der.i_val) ? 1 : 0;
            return v;
            }

            if (izq.tipo == VAL_FLOAT || der.tipo == VAL_FLOAT) {
            v.tipo = VAL_BOOL;
            float izq_val = (izq.tipo == VAL_INT) ? (float)izq.i_val : izq.f_val;
            float der_val = (der.tipo == VAL_INT) ? (float)der.i_val : der.f_val;
            v.b_val = (izq_val >= der_val) ? 1 : 0;
            return v;
            }

            // Comparación de caracteres
            if (izq.tipo == VAL_CHAR && der.tipo == VAL_CHAR) {
            v.tipo = VAL_BOOL;
            v.b_val = (izq.c_val >= der.c_val) ? 1 : 0;
            return v;
            }
        }

        case NODO_MENOR_IGUAL_A:{// * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            Valor der = Evaluar(n->der);

            if (izq.tipo == VAL_INT && der.tipo == VAL_INT) {
            v.tipo = VAL_BOOL;
            v.b_val = (izq.i_val <= der.i_val) ? 1 : 0;
            return v;
            }

            if (izq.tipo == VAL_FLOAT || der.tipo == VAL_FLOAT) {
            v.tipo = VAL_BOOL;
            float izq_val = (izq.tipo == VAL_INT) ? (float)izq.i_val : izq.f_val;
            float der_val = (der.tipo == VAL_INT) ? (float)der.i_val : der.f_val;
            v.b_val = (izq_val <= der_val) ? 1 : 0;
            return v;
            }

            // Comparación de caracteres
            if (izq.tipo == VAL_CHAR && der.tipo == VAL_CHAR) {
            v.tipo = VAL_BOOL;
            v.b_val = (izq.c_val <= der.c_val) ? 1 : 0;
            return v;
            }
        }

        case NODO_IGUAL_IGUAL:{// * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            Valor der = Evaluar(n->der);

            if (izq.tipo == VAL_INT && der.tipo == VAL_INT) {
            v.tipo = VAL_BOOL;
            v.b_val = (izq.i_val == der.i_val) ? 1 : 0;
            return v;
            }

            if (izq.tipo == VAL_FLOAT || der.tipo == VAL_FLOAT) {
            v.tipo = VAL_BOOL;
            float izq_val = (izq.tipo == VAL_INT) ? (float)izq.i_val : izq.f_val;
            float der_val = (der.tipo == VAL_INT) ? (float)der.i_val : der.f_val;
            v.b_val = (izq_val == der_val) ? 1 : 0;
            return v;
            }

            // Comparación de caracteres
            if (izq.tipo == VAL_CHAR && der.tipo == VAL_CHAR) {
            v.tipo = VAL_BOOL;
            v.b_val = (izq.c_val == der.c_val) ? 1 : 0;
            return v;
            }

            // Comparación de strings
            if (izq.tipo == VAL_STRING && der.tipo == VAL_STRING) {
            v.tipo = VAL_BOOL;
            v.b_val = (strcmp(izq.s_val, der.s_val) == 0) ? 1 : 0;
            return v;
            }

            //Comparacion de booleanos
            if (izq.tipo == VAL_BOOL && der.tipo == VAL_BOOL) {
            v.tipo = VAL_BOOL;
            v.b_val = (izq.b_val == der.b_val) ? 1 : 0;
            return v;
            }
        }

        case NODO_DIFERENTE_QUE:{// * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            Valor der = Evaluar(n->der);

            if (izq.tipo == VAL_INT && der.tipo == VAL_INT) {
            v.tipo = VAL_BOOL;
            v.b_val = (izq.i_val != der.i_val) ? 1 : 0;
            return v;
            }

            if (izq.tipo == VAL_FLOAT || der.tipo == VAL_FLOAT) {
            v.tipo = VAL_BOOL;
            float izq_val = (izq.tipo == VAL_INT) ? (float)izq.i_val : izq.f_val;
            float der_val = (der.tipo == VAL_INT) ? (float)der.i_val : der.f_val;
            v.b_val = (izq_val != der_val) ? 1 : 0;
            return v;
            }

            // Comparación de caracteres
            if (izq.tipo == VAL_CHAR && der.tipo == VAL_CHAR) {
            v.tipo = VAL_BOOL;
            v.b_val = (izq.c_val != der.c_val) ? 1 : 0;
            return v;
            }

            // Comparación de strings
            if (izq.tipo == VAL_STRING && der.tipo == VAL_STRING) {
            v.tipo = VAL_BOOL;
            v.b_val = (strcmp(izq.s_val, der.s_val) != 0) ? 1 : 0;
            return v;
            }
        }

        case NODO_AND: { // * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            Valor der = Evaluar(n->der);

            // ! printf("LOs valores que vienen en AND son: %d y %d \n", izq.b_val, der.b_val);

            if (izq.tipo == VAL_BOOL && der.tipo == VAL_BOOL) {
                v.tipo = VAL_BOOL;
                v.b_val = (izq.b_val == 1 && der.b_val == 1) ? 1 : 0;
                return v;
            }
        }

        case NODO_OR: { // * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            Valor der = Evaluar(n->der);

            // ! printf("Los valores que vienen en OR son: %d y %d \n", izq.b_val, der.b_val);

            if (izq.tipo == VAL_BOOL && der.tipo == VAL_BOOL) {
                v.tipo = VAL_BOOL;
                v.b_val = (izq.b_val == 1 || der.b_val == 1) ? 1 : 0;
                return v;
            }
        }

        case NODO_DECLARATION: { // * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            // * Nombre de variable en "n->nombre"
            // * Tipo de variable en "n->valor.varType"
            // * Valor asignado en "izq.[Atributo segun tipo]"
            // Validar si el tipo declarado en varType es igual al tipo del valor evaluado

            if (izq.tipo == VAL_NULL) {
                Asignacion_Default(n->nombre, n->valor.varType);
                printf(" » 💾 Variable Registrada: '%s' asignada con valor por defecto\n", n->nombre);
                break;
            }


            if (strcmp(n->valor.varType, "int") == 0) {
                if (izq.tipo == VAL_INT) {
                    AsignarVariable_Int(n->nombre, izq.i_val);
                    printf(" » 💾 Variable Registrada: '%s' asignada con valor: %d \n", n->nombre, izq.i_val);
                } else if (izq.tipo == VAL_FLOAT) {
                    // Permitir asignar un float eliminando la parte fraccionaria
                    AsignarVariable_Int(n->nombre, (int)izq.f_val);
                    printf(" » 💾 Variable Registrada (int -> float): '%s' asignada con valor: %d \n", n->nombre, (int)izq.f_val);
                } else {
                    printf(" »   Int Error: Tipo de dato no coincide \n");
                }

            } else if (strcmp(n->valor.varType, "float") == 0) {
                if (izq.tipo == VAL_FLOAT) {
                    AsignarVariable_Float(n->nombre, izq.f_val);
                    printf(" » 💾 Variable Registrada: '%s' asignada con valor: %f \n", n->nombre, izq.f_val);
                } else if (izq.tipo == VAL_DOUBLE) {
                    // perimitir asignar un double eliminando la parte fraccionaria extra
                    AsignarVariable_Float(n->nombre, (float)izq.d_val);
                    printf(" » 💾 Variable Registrada (float -> double): '%s' asignada con valor: %f \n", n->nombre, (float)izq.d_val);
                } else {
                    printf(" »   Float Error: Tipo de dato no coincide \n");
                }

            } else if (strcmp(n->valor.varType, "String") == 0) {
                if (izq.tipo == VAL_STRING) {
                    AsignarVariable_String(n->nombre, izq.s_val);
                    printf(" » 💾 Variable Registrada: '%s' asignada con valor: %s \n", n->nombre, izq.s_val);
                } else {
                    printf(" »   String Error: Tipo de dato no coincide \n");
                }

            } else if (strcmp(n->valor.varType, "boolean") == 0) {
                if (izq.tipo == VAL_BOOL) {
                    AsignarVariable_Boolean(n->nombre, izq.b_val);
                    printf(" » 💾 Variable Registrada: '%s' asignada con valor: %d \n", n->nombre, izq.b_val ? 1 : 0);
                } else {
                    printf(" »   Boolean Error: Tipo de dato no coincide \n");
                }

            } else if (strcmp(n->valor.varType, "char") == 0) {
                if (izq.tipo == VAL_CHAR) {
                    AsignarVariable_Char(n->nombre, izq.c_val);
                    printf(" » 💾 Variable Registrada: '%s' asignada con valor: %c \n", n->nombre, izq.c_val);
                } else if (izq.tipo == VAL_INT) {
                    // Permitir asignar un int a un char si el int está en el rango ASCII
                    if (izq.i_val >= 0 && izq.i_val <= 255) {
                        AsignarVariable_Char(n->nombre, (char)izq.i_val);
                        printf(" » 💾 Variable Registrada (char -> int): '%s' asignada con valor: %c \n", n->nombre, (char)izq.i_val);
                    } else {
                        printf(" »   Char Error: Valor entero fuera del rango ASCII \n");
                    }
                } else {
                    printf(" »   Char Error: Tipo de dato no coincide \n");
                }

            } else if (strcmp(n->valor.varType, "long") == 0) {
                if (izq.tipo == VAL_INT) {
                    AsignarVariable_Long(n->nombre, izq.i_val);
                    printf(" » 💾 Variable Registrada: '%s' asignada con valor: %d \n", n->nombre, izq.i_val);
                } else {
                    printf(" »   Long Error: Tipo de dato no coincide \n");
                }

            } else if (strcmp(n->valor.varType, "short") == 0) {
                if (izq.tipo == VAL_INT) {
                    AsignarVariable_Short(n->nombre, izq.i_val);
                    printf(" » 💾 Variable Registrada: '%s' asignada con valor: %d \n", n->nombre, izq.i_val);
                } else {
                    printf(" »   Short Error: Tipo de dato no coincide \n");
                }

            } else if (strcmp(n->valor.varType, "double") == 0) {
                if (izq.tipo == VAL_DOUBLE) {
                    AsignarVariable_Double(n->nombre, izq.d_val);
                    printf(" » 💾 Variable Registrada: '%s' asignada con valor: %f \n", n->nombre, izq.d_val);
                } else {
                    printf(" »   Double Error: Tipo de dato no coincide \n");
                }

            } else if (strcmp(n->valor.varType, "byte") == 0) {
                if (izq.tipo == VAL_CHAR) {
                    AsignarVariable_Byte(n->nombre, izq.c_val);
                    printf(" » 💾 Variable Registrada: '%s' asignada con valor: %c \n", n->nombre, izq.c_val);
                } else {
                    printf(" »   Byte Error: Tipo de dato no coincide \n");
                }
            } else {
                printf(" »   Tipo de dato desconocido en declaracion * \n");
            }
            break;
        }

        case NODO_IDENTIFICADOR: { // * ----------------------------------------------------------------------------------------
            // * Buscar variable en tabla de simbolos y retornar su valor
            Nodo* varNodo = Acceso_Variable(n->nombre);
            if (varNodo != NULL) {
                Valor result = Evaluar(varNodo);
                //! Print_Specific_Variable(n->nombre);
                return result;
            } else {
                v.tipo = VAL_NULL;
                v.null_val = "-Var Not Found Err"; // Error de variable no encontrada
                return v;
            }
        }
        
        case NODO_ASIGNACION: { // * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            Nodo* varNodo = Acceso_Variable(n->nombre);
            // * Nombre de variable en "n->nombre"
            // * Valor asignado en "izq.[Atributo segun tipo]"
            // * Buscar si la variable ya existe
            
            if (varNodo != NULL) {
                if (strcmp(n->valor.op_bool, "=") == 0) {
                    Actualizar_Variable(n->nombre, izq);
                    break;
                } else {
                    Asignacion_Especial(n->nombre, n->valor.op_bool, izq);
                    break;
                }
            }

            break;
        }

        case NODO_CASTEO_NARROWING: {
            Valor izq = Evaluar(n->izq);
            Valor der = Evaluar(n->der);

            char* identificador = izq.s_val;
            char* identificador2 = der.s_val;
            char* tipo1 = n->valor.varType;
            char* parseType = n->nombre;

            Casteo_Narrow(tipo1, identificador, parseType, identificador2);
            break;
        }

        case NODO_EQUALS_COMPARE: { // * ----------------------------------------------------------------------------------------

            Nodo* Verificacion = Compare_Equals(n->nombre, n->izq);

            Valor izq = Evaluar(Verificacion);

            v.tipo = VAL_BOOL;
            v.b_val = izq.b_val;
            return v;

        }

        case NODO_PARSEO: { // * ----------------------------------------------------------------------------------------

            Valor izq = Evaluar(n->izq);
            char* tipoVariable = n->valor.varType;
            char* Identificador = n->nombre;
            char* ParseType = n->valor.op_bool;

            AsignarParseo_Variable(Identificador, tipoVariable, ParseType, izq);
            break;
        }

        case NODO_IF_SIMPLE: { // * -----------------------------------------------------------------------------------------

            Valor condicion = Evaluar(n->izq);

            if (condicion.tipo == VAL_BOOL) {
                if (condicion.b_val == 1) {
                    printf(" » 🆗 Ejecutando If Simple >_______________________________________________________________\n");
                    Evaluar(n->der); // Ejecutar el bloque si la condición es verdadera
                    printf("____________________________________________________________________________________________\n\n");
                }
            } else {
                printf(" » ❌  Error If: La condición no es booleana \n");
            }
            break;
        }

        case NODO_IF_ELSE: { // * -----------------------------------------------------------------------------------------

            Valor condicion = Evaluar(n->izq);

            if (condicion.tipo == VAL_BOOL) {
                if (condicion.b_val == 1) {
                    printf(" » 🆗 Ejecutando If >_________________________________________________________________________\n");
                    Evaluar(n->der); // Ejecutar el bloque if si la condición es verdadera
                    printf("____________________________________________________________________________________________\n\n");
                } else {
                    printf(" » 🆗 Ejecutando Else >_______________________________________________________________________\n");
                    Evaluar(n->nodo_else); // Ejecutar el bloque else si la condición es falsa
                    printf("____________________________________________________________________________________________\n\n");
                }
            } else {
                printf(" » ❌  Error If-Else: La condición no es booleana \n");
            }
            break;
        }

        case NODO_IF_ELSE_IF: {
            Valor condicionIf = Evaluar(n->izq);

            if (condicionIf.tipo == VAL_BOOL && condicionIf.b_val == 1) {
            printf(" » 🆗 Ejecutando If >_________________________________________________________________________\n");
            Evaluar(n->der); // Ejecutar el bloque if si la condición es verdadera
            printf("____________________________________________________________________________________________\n\n");
            } else {
                // Verificar el siguiente else if
                Valor condicionElseIf = Evaluar(n->siguiente->izq);
                if (condicionElseIf.tipo == VAL_BOOL && condicionElseIf.b_val == 1) {
                    printf(" » 🆗 Ejecutando Else If >____________________________________________________________________\n");
                    Evaluar(n->siguiente->der); // Ejecutar el bloque else if si la condición es verdadera
                    printf("____________________________________________________________________________________________\n\n");
                } else {
                    // Verificar lista de nodos else if adicionales
                    int ejecutado = 0;
                    if (n->lista_nodos != NULL) {
                        for (int i = 0; n->lista_nodos[i] != NULL; i++) {
                            Valor cond = Evaluar(n->lista_nodos[i]->izq);
                            if (cond.tipo == VAL_BOOL && cond.b_val == 1) {
                                printf(" » 🆗 Ejecutando Else If (Lista) >___________________________________________________________\n");
                                Evaluar(n->lista_nodos[i]->der); // Ejecutar instrucciones de este else if
                                printf("____________________________________________________________________________________________\n\n");
                                ejecutado = 1;
                                break; // Se encontró una condición verdadera, salir del ciclo
                            }
                        }
                    }
                    // Si ninguna condición se cumple, ejecutar el else
                    if (!ejecutado) {
                    printf(" » 🆗 Ejecutando Else >_______________________________________________________________________\n");
                    Evaluar(n->nodo_else); // Ejecutar el bloque else si la condición es falsa
                    printf("____________________________________________________________________________________________\n\n");
                    }
                }
            }
            break;
        }

        case NODO_PRINT: { // * ----------------------------------------------------------------------------------------
            // ! TODO LO QUE SALGA EN PRINT ES LO QUE SE RETORNA AL FRONTEND
            Valor resultado = Evaluar(n->izq);

            switch (resultado.tipo) {

            case VAL_INT:
                printf(" » 🖨️  » %d\n", resultado.i_val);
                break;

            case VAL_FLOAT:
                printf(" » 🖨️  »  %f\n", resultado.f_val);
                break;

            case VAL_DOUBLE:
                printf(" » 🖨️  »  %lf\n", resultado.d_val);
                break;
            
            case VAL_STRING:
                printf(" » 🖨️  »  %s\n", resultado.s_val);
                break;

            case VAL_BOOL:
                if (resultado.b_val == 1) {
                    printf(" » 🖨️  »  True \n");
                } else {
                    printf(" » 🖨️  »  False \n");
                }
                break;

            case VAL_CHAR:
                printf(" » 🖨️ »  %c\n", resultado.c_val);
                break;

            case VAL_NULL:
                printf(" » 🖨️ »  %s\n", resultado.null_val);
                break;

            default:
                printf("Tipo de dato desconocido * \n");
                break;
            }

        }

        // ? Nodo recursivo que lee cada instruccion
        case NODO_LISTA:  // * ----------------------------------------------------------------------------------------
            Evaluar(n->izq);
            Evaluar(n->der);
            break;
        
        // ! DEclaraciones y esas weas de las variables en tabla de simbolos se trabaja
        // ! Aqui solo desglozamos valores y los mandamos
        // ! AQUI SE AÑADEN MAS CASES PARA LOS DISTINTOS NODOS Y LO QUE QUIERO QUE SALGA
    }
    //v.tipo = VAL_NULL;
    //v.null_val = "NODO DESCONOCIDO"; // Error de tipo
    //return v;
}
