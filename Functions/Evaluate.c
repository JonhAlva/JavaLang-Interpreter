#include "AST.h"
#include <string.h>
#include <stdlib.h>
#include "Evaluate.h"
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

        case NODO_STRING: // * ----------------------------------------------------------------------------------------
            v.tipo = VAL_STRING;
            v.s_val = n->valor.s_val;
            return v;

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

            // * Concatenacion de valores en + si son strings o valores variables
            if (izq.tipo == VAL_STRING || der.tipo == VAL_STRING) {
                v.tipo = VAL_STRING;
                char temp[100];  // ! Buffer temporal para conversiones
                char* str_izq;
                char* str_der;

                // ! Convertir izquierda a string si no lo es
                if (izq.tipo == VAL_STRING) {
                    str_izq = izq.s_val;
                } else {
                    switch(izq.tipo) {
                        case VAL_INT:
                            sprintf(temp, "%d", izq.i_val);
                            break;
                        case VAL_FLOAT:
                            sprintf(temp, "%f", izq.f_val);
                            break;
                        case VAL_BOOL:
                            sprintf(temp, "%s", izq.b_val ? "true" : "false");
                            break;
                        default:
                            sprintf(temp, " ");
                    }
                    str_izq = strdup(temp);
                }

                // ! Convertir derecha a string si no lo es
                if (der.tipo == VAL_STRING) {
                    str_der = der.s_val;
                } else {
                    switch(der.tipo) {
                        case VAL_INT:
                            sprintf(temp, "%d", der.i_val);
                            break;
                        case VAL_FLOAT:
                            sprintf(temp, "%f", der.f_val);
                            break;
                        case VAL_BOOL:
                            sprintf(temp, "%s", der.b_val ? "true" : "false");
                            break;
                        default:
                            sprintf(temp, " ");
                    }
                    str_der = strdup(temp);
                }

                // ! Concatenar los strings
                v.s_val = malloc(strlen(str_izq) + strlen(str_der) + 1);
                strcpy(v.s_val, str_izq);
                strcat(v.s_val, str_der);

                // ! Liberar memoria si fue asignada dinámicamente
                if (izq.tipo != VAL_STRING) free(str_izq);
                if (der.tipo != VAL_STRING) free(str_der);
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

            if (izq.tipo == VAL_BOOL && der.tipo == VAL_BOOL) {
                v.tipo = VAL_BOOL;
                v.b_val = (izq.b_val == 1 && der.b_val == 1) ? 1 : 0;
                return v;
            }
        }

        case NODO_OR: { // * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            Valor der = Evaluar(n->der);

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
            if (strcmp(n->valor.varType, "int") == 0) {
                printf(" »   Tipo de dato declarado es INT \n");
            } else if (strcmp(n->valor.varType, "float") == 0) {
                printf(" »   Tipo de dato declarado es FLOAT \n");
            } else if (strcmp(n->valor.varType, "String") == 0) {
                printf(" »   Tipo de dato declarado es STRING \n");
            } else if (strcmp(n->valor.varType, "boolean") == 0) {
                printf(" »   Tipo de dato declarado es BOOL \n");
            } else if (strcmp(n->valor.varType, "char") == 0) {
                printf(" »   Tipo de dato declarado es CHAR \n");
            } else if (strcmp(n->valor.varType, "long") == 0) {
                printf(" »   Tipo de dato declarado es LONG \n");
            } else if (strcmp(n->valor.varType, "short") == 0) {
                printf(" »   Tipo de dato declarado es SHORT \n");
            } else if (strcmp(n->valor.varType, "double") == 0) {
                printf(" »   Tipo de dato declarado es DOUBLE \n");
            } else if (strcmp(n->valor.varType, "byte") == 0) {
                printf(" »   Tipo de dato declarado es BYTE \n");
            } else {
                printf(" »   Tipo de dato desconocido en declaracion * \n");
            }
            // ! Manejo de declaraciones se hace en otro lado
            break;
        }

        case NODO_PRINT: { // * ----------------------------------------------------------------------------------------
            Valor resultado = Evaluar(n->izq);

            switch (resultado.tipo) {

            case VAL_INT:
                printf(" »   %d\n", resultado.i_val);
                break;

            case VAL_FLOAT:
                printf(" »   %f\n", resultado.f_val);
                break;

            case VAL_STRING:
                printf(" »   %s\n", resultado.s_val);
                break;

            case VAL_BOOL:
                if (resultado.b_val == 1) {
                    printf(" »   True \n");
                } else {
                    printf(" »   False \n");
                }
                break;

            case VAL_CHAR:
                printf(" »   %c\n", resultado.c_val);
                break;

            case VAL_NULL:
                printf(" »   %s\n", resultado.null_val);
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
