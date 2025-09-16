#include "AST.h"
#include "Evaluate.h"
#include "Tabla_Simbolos.h"
#include "PrintBuffer.h"
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
    char* nombresParametros[20]; // Array para almacenar los nombres de los parámetros

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
            
            // Procesar caracteres especiales de escape
            char* result = malloc(2*len); // Buffer temporal más grande para posibles expansiones
            int j = 0;
            
            for(int i = 0; contenido[i] != '\0'; i++) {
                if(contenido[i] == '\\' && contenido[i+1] == 'n') {
                result[j++] = '\n';  // Insertar salto de línea real
                i++; // Saltar el siguiente carácter 'n'
                } else {
                result[j++] = contenido[i];
                }
            }
            result[j] = '\0';
            
            free(contenido);
            v.s_val = result;
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

            // * Si viene un double, entonces tirar double
            if (izq.tipo == VAL_DOUBLE || der.tipo == VAL_DOUBLE) {
                v.tipo = VAL_DOUBLE;
                double izq_val = (izq.tipo == VAL_INT) ? (double)izq.i_val : 
                        (izq.tipo == VAL_FLOAT) ? (double)izq.f_val : izq.d_val;
                double der_val = (der.tipo == VAL_INT) ? (double)der.i_val :
                        (der.tipo == VAL_FLOAT) ? (double)der.f_val : der.d_val;
                v.d_val = izq_val + der_val;
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

            // * Si viene un double, entonces tirar double
            if (izq.tipo == VAL_DOUBLE || der.tipo == VAL_DOUBLE) {
            v.tipo = VAL_DOUBLE;
            double izq_val = (izq.tipo == VAL_INT) ? (double)izq.i_val : 
                (izq.tipo == VAL_FLOAT) ? (double)izq.f_val : izq.d_val;
            double der_val = (der.tipo == VAL_INT) ? (double)der.i_val :
                (der.tipo == VAL_FLOAT) ? (double)der.f_val : der.d_val;
            v.d_val = izq_val - der_val;
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

            // * Si viene un double, entonces tirar double
            if (izq.tipo == VAL_DOUBLE || der.tipo == VAL_DOUBLE) {
            v.tipo = VAL_DOUBLE;
            double izq_val = (izq.tipo == VAL_INT) ? (double)izq.i_val : 
                (izq.tipo == VAL_FLOAT) ? (double)izq.f_val : izq.d_val;
            double der_val = (der.tipo == VAL_INT) ? (double)der.i_val :
                (der.tipo == VAL_FLOAT) ? (double)der.f_val : der.d_val;
            v.d_val = izq_val * der_val;
            return v;
            }
        }

        case NODO_DIVISION: {// * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            Valor der = Evaluar(n->der);

            // Check for division by zero first
            if ((der.tipo == VAL_INT && der.i_val == 0) || 
                (der.tipo == VAL_FLOAT && der.f_val == 0.0) ||
                (der.tipo == VAL_DOUBLE && der.d_val == 0.0)) {
                v.tipo = VAL_NULL;
                v.null_val = "-Div/0 Err";
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "No es posible dividir entre 0";
                lista_Errores[num_errores].Tipo_Error = "Division";
                num_errores++;
                return v;
            }

            if (izq.tipo == VAL_INT && der.tipo == VAL_INT) {

                if (izq.i_val % der.i_val != 0) {
                    v.tipo = VAL_FLOAT;
                    v.f_val = (float)izq.i_val / (float)der.i_val;
                } else {
                    v.tipo = VAL_INT;
                    v.i_val = izq.i_val / der.i_val;
                }
                return v;
            }


            v.tipo = VAL_FLOAT;
            float izq_val = (izq.tipo == VAL_INT) ? (float)izq.i_val : 
                            (izq.tipo == VAL_FLOAT) ? izq.f_val : (float)izq.d_val;
            float der_val = (der.tipo == VAL_INT) ? (float)der.i_val :
                            (der.tipo == VAL_FLOAT) ? der.f_val : (float)der.d_val;
            v.f_val = izq_val / der_val;
            return v;
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

            if (izq.tipo == VAL_DOUBLE || der.tipo == VAL_DOUBLE) {
            v.tipo = VAL_BOOL;
            double izq_val = (izq.tipo == VAL_INT) ? (double)izq.i_val :
                (izq.tipo == VAL_FLOAT) ? (double)izq.f_val : izq.d_val;
            double der_val = (der.tipo == VAL_INT) ? (double)der.i_val :
                (der.tipo == VAL_FLOAT) ? (double)der.f_val : der.d_val;
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

            if (izq.tipo == VAL_DOUBLE || der.tipo == VAL_DOUBLE) {
            v.tipo = VAL_BOOL;
            double izq_val = (izq.tipo == VAL_INT) ? (double)izq.i_val :
                (izq.tipo == VAL_FLOAT) ? (double)izq.f_val : izq.d_val;
            double der_val = (der.tipo == VAL_INT) ? (double)der.i_val :
                (der.tipo == VAL_FLOAT) ? (double)der.f_val : der.d_val;
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

            if (izq.tipo == VAL_DOUBLE || der.tipo == VAL_DOUBLE) {
            v.tipo = VAL_BOOL;
            double izq_val = (izq.tipo == VAL_INT) ? (double)izq.i_val : 
                    (izq.tipo == VAL_FLOAT) ? (double)izq.f_val : izq.d_val;
            double der_val = (der.tipo == VAL_INT) ? (double)der.i_val :
                    (der.tipo == VAL_FLOAT) ? (double)der.f_val : der.d_val;
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

            if (izq.tipo == VAL_DOUBLE || der.tipo == VAL_DOUBLE) {
            v.tipo = VAL_BOOL;
            double izq_val = (izq.tipo == VAL_INT) ? (double)izq.i_val :
                (izq.tipo == VAL_FLOAT) ? (double)izq.f_val : izq.d_val;
            double der_val = (der.tipo == VAL_INT) ? (double)der.i_val :
                (der.tipo == VAL_FLOAT) ? (double)der.f_val : der.d_val;
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

            if (izq.tipo == VAL_DOUBLE || der.tipo == VAL_DOUBLE) {
            v.tipo = VAL_BOOL;
            double izq_val = (izq.tipo == VAL_INT) ? (double)izq.i_val : 
                   (izq.tipo == VAL_FLOAT) ? (double)izq.f_val : izq.d_val;
            double der_val = (der.tipo == VAL_INT) ? (double)der.i_val :
                   (der.tipo == VAL_FLOAT) ? (double)der.f_val : der.d_val;
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

            if (izq.tipo == VAL_DOUBLE || der.tipo == VAL_DOUBLE) {
            v.tipo = VAL_BOOL;
            double izq_val = (izq.tipo == VAL_INT) ? (double)izq.i_val : 
               (izq.tipo == VAL_FLOAT) ? (double)izq.f_val : izq.d_val;
            double der_val = (der.tipo == VAL_INT) ? (double)der.i_val :
               (der.tipo == VAL_FLOAT) ? (double)der.f_val : der.d_val;
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
            
            // Si el primer operando es falso, no evaluamos el segundo
            if (izq.tipo == VAL_BOOL && izq.b_val == 0) {
                v.tipo = VAL_BOOL;
                v.b_val = 0;
                return v;
            }
            
            Valor der = Evaluar(n->der);

            if (izq.tipo == VAL_BOOL && der.tipo == VAL_BOOL) {
                v.tipo = VAL_BOOL;
                v.b_val = (izq.b_val && der.b_val);
                return v;
            } else {
                printf(" » ❌ Error AND: Los operandos deben ser booleanos\n");
                v.tipo = VAL_BOOL;
                v.b_val = 0;
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "Los operandos deben ser booleanos";
                lista_Errores[num_errores].Tipo_Error = "Comparacion AND";
                num_errores++;
                return v;
            }
        }

        case NODO_OR: { // * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            
            // Si el primer operando es verdadero, no evaluamos el segundo
            if (izq.tipo == VAL_BOOL && izq.b_val == 1) {
                v.tipo = VAL_BOOL;
                v.b_val = 1;
                return v;
            }
            
            Valor der = Evaluar(n->der);

            if (izq.tipo == VAL_BOOL && der.tipo == VAL_BOOL) {
                v.tipo = VAL_BOOL;
                v.b_val = (izq.b_val || der.b_val);
                return v;
            } else {
                printf(" » ❌ Error OR: Los operandos deben ser booleanos\n");
                v.tipo = VAL_BOOL;
                v.b_val = 0;
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "Los operandos deben ser booleanos";
                lista_Errores[num_errores].Tipo_Error = "Comparacion OR";
                num_errores++;
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
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible";
                    lista_Errores[num_errores].Tipo_Error = "Declaracion Int";
                    num_errores++;
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
                    printf(" »   Int Error: Tipo de dato no coincide \n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible";
                    lista_Errores[num_errores].Tipo_Error = "Declaracion Float";
                    num_errores++;
                }

            } else if (strcmp(n->valor.varType, "String") == 0) {
                if (izq.tipo == VAL_STRING) {
                    AsignarVariable_String(n->nombre, izq.s_val);
                    printf(" » 💾 Variable Registrada: '%s' asignada con valor: %s \n", n->nombre, izq.s_val);
                } else {
                    printf(" »   String Error: Tipo de dato no coincide \n");
                    printf(" »   Int Error: Tipo de dato no coincide \n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible";
                    lista_Errores[num_errores].Tipo_Error = "Declaracion String";
                    num_errores++;
                }

            } else if (strcmp(n->valor.varType, "boolean") == 0) {
                if (izq.tipo == VAL_BOOL) {
                    AsignarVariable_Boolean(n->nombre, izq.b_val);
                    printf(" » 💾 Variable Registrada: '%s' asignada con valor: %d \n", n->nombre, izq.b_val ? 1 : 0);
                } else {
                    printf(" »   Boolean Error: Tipo de dato no coincide \n");
                    printf(" »   Int Error: Tipo de dato no coincide \n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible";
                    lista_Errores[num_errores].Tipo_Error = "Declaracion Boolean";
                    num_errores++;
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
                    printf(" »   Int Error: Tipo de dato no coincide \n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible";
                    lista_Errores[num_errores].Tipo_Error = "Declaracion Char";
                    num_errores++;
                }

            } else if (strcmp(n->valor.varType, "long") == 0) {
                if (izq.tipo == VAL_INT) {
                    AsignarVariable_Long(n->nombre, izq.i_val);
                    printf(" » 💾 Variable Registrada: '%s' asignada con valor: %d \n", n->nombre, izq.i_val);
                } else {
                    printf(" »   Long Error: Tipo de dato no coincide \n");
                    printf(" »   Int Error: Tipo de dato no coincide \n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible";
                    lista_Errores[num_errores].Tipo_Error = "Declaracion Long";
                    num_errores++;
                }

            } else if (strcmp(n->valor.varType, "short") == 0) {
                if (izq.tipo == VAL_INT) {
                    AsignarVariable_Short(n->nombre, izq.i_val);
                    printf(" » 💾 Variable Registrada: '%s' asignada con valor: %d \n", n->nombre, izq.i_val);
                } else {
                    printf(" »   Short Error: Tipo de dato no coincide \n");
                    printf(" »   Int Error: Tipo de dato no coincide \n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible";
                    lista_Errores[num_errores].Tipo_Error = "Declaracion Short";
                    num_errores++;
                }

            } else if (strcmp(n->valor.varType, "double") == 0) {
                if (izq.tipo == VAL_DOUBLE) {
                    AsignarVariable_Double(n->nombre, izq.d_val);
                    printf(" » 💾 Variable Registrada: '%s' asignada con valor: %f \n", n->nombre, izq.d_val);
                } else {
                    printf(" »   Double Error: Tipo de dato no coincide \n");
                    printf(" »   Int Error: Tipo de dato no coincide \n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible";
                    lista_Errores[num_errores].Tipo_Error = "Declaracion Double";
                    num_errores++;
                }

            } else if (strcmp(n->valor.varType, "byte") == 0) {
                if (izq.tipo == VAL_CHAR) {
                    AsignarVariable_Byte(n->nombre, izq.c_val);
                    printf(" » 💾 Variable Registrada: '%s' asignada con valor: %c \n", n->nombre, izq.c_val);
                } else {
                    printf(" »   Byte Error: Tipo de dato no coincide \n");
                    printf(" »   Int Error: Tipo de dato no coincide \n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible";
                    lista_Errores[num_errores].Tipo_Error = "Declaracion Byte";
                    num_errores++;
                }
            } else {
                printf(" » ERROR: Tipo de dato desconocido en declaracion * \n");
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "Tipo de Dato Desconocido";
                lista_Errores[num_errores].Tipo_Error = "Declaracion";
                num_errores++;
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
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "La variable no fue encontrada";
                lista_Errores[num_errores].Tipo_Error = "Variable";
                num_errores++;
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

            // agregar condicion cuando el nodo sea un tipo val_string
            if (n->nombre[0] == '"' && n->nombre[strlen(n->nombre)-1] == '"') {
                Valor izq = Evaluar(n->izq);

                // quitar comillas del texto
                char* str_without_quotes = malloc(strlen(n->nombre) - 1);
                strncpy(str_without_quotes, n->nombre + 1, strlen(n->nombre) - 2);
                str_without_quotes[strlen(n->nombre) - 2] = '\0';

                v.tipo = VAL_BOOL;
                v.b_val = (strcmp(izq.s_val, str_without_quotes) == 0) ? 1 : 0;
                
                free(str_without_quotes);
                return v;
            }

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
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "LA condicion no es booleana";
                lista_Errores[num_errores].Tipo_Error = "Sentencia If";
                num_errores++;
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
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "LA condicion no es booleana";
                lista_Errores[num_errores].Tipo_Error = "Sentencia If-Else";
                num_errores++;
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

        case NODO_DECLARATION_VECTOR: { // * ----------------------------------------------------------------------------------------
            // * Nombre de variable en "n->nombre"
            // * Tipo de variable en "n->valor.varType"
            // * Tipo del vector en "n->izq"

            // del nodo izq ver que tipo de vector viene
            if (n->izq != NULL) {
                if (n->izq->tipo == NODO_VECTOR_AUTO) {
                    printf(" * * *  Vector Registrado: '%s' de tipo Auto \n", n->nombre);
                } else if (n->izq->tipo == NODO_VALORES_VECTOR_LIST) {
                    printf(" * * *  Vector Registrado: '%s' de tipo Explicito con valores definidos \n", n->nombre);
                } else {
                    printf(" »   Tipo de dato desconocido en declaracion de vector * \n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Dato desconocido en declaracion de vector";
                    lista_Errores[num_errores].Tipo_Error = "Vector";
                num_errores++;
                }
            }
            break;
        }

        case NODO_DECLARATION_MATRIX: { // * ----------------------------------------------------------------------------------------
            // * Nombre de variable en "n->nombre"
            // * Tipo de variable en "n->valor.varType"
            // * Tipo del vector en "n->izq"

            // del nodo izq ver que tipo de vector viene
            if (n->izq != NULL) {
                if (n->izq->tipo == NODO_MATRIZ_AUTO) {
                    printf(" * * *  Matriz Registrada: '%s' de tipo Auto \n", n->nombre);

                    //AÑADIR UN ELSE IF PARA EL OTRO TIPO DE MATRIZ CON LOS VALORES DEFINIDOS
                } else {
                    printf(" »   Tipo de dato desconocido en declaracion de matriz * \n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Dato desconocido en declaracion de matriz";
                    lista_Errores[num_errores].Tipo_Error = "Matriz";
                num_errores++;
                }
            }
            break;
        }

        case NODO_FOR_SENTENCE: { // * ----------------------------------------------------------------------------------------
            // Evaluar la declaración inicial
            Evaluar(n->izq->izq);

            // Obtener nombre de variable y tipo de operación
            char* nombreVar = n->izq->nombre;
            char* tipoOp = n->izq->valor.op_bool;

            // Validar operador
            if(strcmp(tipoOp, "++") != 0 && strcmp(tipoOp, "--") != 0) {
                printf(" » ❌ Error For: Operacion no valida, solo se permite ++ o -- \n");
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "Operacion no valida, solo se permite ++ o --";
                lista_Errores[num_errores].Tipo_Error = "Sentencia For";
                num_errores++;
                break;
            }

            // Ciclo principal del for
            while(1) {
                // Evaluar condición
                printf(" » 🔄 Evaluando condicion For\n");
                Valor condicion = Evaluar(n->izq->der);

                if(condicion.tipo != VAL_BOOL) {
                    printf(" » ❌ Error For: La condicion debe ser booleana\n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "La condicion debe ser booleana";
                    lista_Errores[num_errores].Tipo_Error = "Sentencia For";
                    num_errores++;
                    break;
                }

                // Si la condición es falsa, salir del ciclo
                if(!condicion.b_val) {
                    break;
                }

                // Ejecutar el bloque de instrucciones
                printf(" » ⏩ Ejecutando iteracion For\n");
                Evaluar(n->der);

                // Obtener valor actual de la variable
                Nodo* varNodo = Acceso_Variable(nombreVar);
                if(varNodo == NULL) {
                    printf(" » ❌ Error For: Variable de control no encontrada\n");
                    break;
                }
                Valor valorActual = Evaluar(varNodo);

                // Incrementar o decrementar según corresponda
                if(strcmp(tipoOp, "++") == 0) {
                    Actualizar_Variable(nombreVar, (Valor){.tipo = VAL_INT, .i_val = valorActual.i_val + 1});
                } else {
                    printf(" ---------------------------------------------el operador es --\n");
                    Actualizar_Variable(nombreVar, (Valor){.tipo = VAL_INT, .i_val = valorActual.i_val - 1});
                }
            }
            
            break;
        }

        case NODO_PLUS_MINUS_VAR: {
            Valor izq = Evaluar(n->izq);

            // Obtener nombre de variable y tipo de operación
            char* nombreVar = n->nombre;
            char* tipoOp = n->valor.op_bool;

            // Validar operador
            if(strcmp(tipoOp, "++") != 0 && strcmp(tipoOp, "--") != 0) {
                printf(" » ❌ Error: Operacion no valida, solo se permite ++ o -- \n");
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "Operacion no valida, solo se permite ++ o --";
                lista_Errores[num_errores].Tipo_Error = "Incremento/Decremento";
                num_errores++;
                break;
            }

            // Validar que la variable exista
            Nodo* varNodo = Acceso_Variable(nombreVar);
            if(varNodo == NULL) {
                printf(" » ❌ Error: Variable no encontrada\n");
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "Variable no encontrada";
                lista_Errores[num_errores].Tipo_Error = "Incremento/Decremento";
                num_errores++;
                break;
            }

            // Validar que la variable sea de tipo int
            Valor valorActual = Evaluar(varNodo);
            if(valorActual.tipo != VAL_INT) {
                printf(" » ❌ Error: La variable debe ser de tipo int para esta operacion\n");
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "La variable debe ser de tipo int para esta operacion";
                lista_Errores[num_errores].Tipo_Error = "Incremento/Decremento";
                num_errores++;
                break;
            }

            // Realizar la operación
            if(strcmp(tipoOp, "++") == 0) {
                Actualizar_Variable(nombreVar, (Valor){.tipo = VAL_INT, .i_val = valorActual.i_val + 1});
            } else {
                Actualizar_Variable(nombreVar, (Valor){.tipo = VAL_INT, .i_val = valorActual.i_val - 1});
            }
            break;
        }

        case NODO_WHILE_SENTENCE: { // * ----------------------------------------------------------------------------------------
            while(1) {
                // Evaluar condición al inicio de cada iteración
                Valor condicion = Evaluar(n->izq);
                
                // Validar que la condición sea booleana
                if(condicion.tipo != VAL_BOOL) {
                    printf(" » ❌ Error While: La condicion debe ser booleana\n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "La condicion debe ser booleana";
                    lista_Errores[num_errores].Tipo_Error = "Sentencia While";
                    num_errores++;
                    break;
                }

                // Si la condición es falsa, salir del ciclo
                if(!condicion.b_val) {
                    break;
                }

                // Ejecutar el bloque de instrucciones
                printf(" » 🔄 Ejecutando iteracion While\n");
                
                // Ejecutar instrucciones y verificar si hay break o continue
                Valor resultado = Evaluar(n->der);
                
                // Verificar si se encontró un break
                if(resultado.tipo == VAL_NULL && strcmp(resultado.null_val, "BREAK") == 0) {
                    printf(" » ⏹️ Break encontrado, saliendo del ciclo\n");
                    break;
                }
                
                // Verificar si se encontró un continue
                if(resultado.tipo == VAL_INT && resultado.i_val == 1) {
                    printf(" » ⏭️ Continue encontrado, saltando a siguiente iteracion\n");
                    continue;
                }
            }
        break;
        }

        case NODO_SWITCH_SENTENCE: { // * ----------------------------------------------------------------------------------------
            // ? Nombre de la variable a comparar
            char* nombreVar = n->nombre;

            // ? Nodo de la varible a comparar
            Nodo* Valor_NombreVar = Acceso_Variable(nombreVar);
            if (Valor_NombreVar == NULL) {
                printf(" » ❌ Error Switch: Variable '%s' no encontrada\n", nombreVar);
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "Variable no encontrada";
                lista_Errores[num_errores].Tipo_Error = "Sentencia Switch";
                num_errores++;
                break;
            }

            // ? Capturar el valor de VValor_NombreVar dependiendo del tipo
            Valor valorSwitch;
            switch(Valor_NombreVar->tipo) {
                case NODO_INT:
                    valorSwitch = (Valor){.tipo = VAL_INT, .i_val = Valor_NombreVar->valor.i_val};
                    break;
                case NODO_STRING:
                    valorSwitch = (Valor){.tipo = VAL_STRING, .s_val = strdup(Valor_NombreVar->valor.s_val)};
                    break;
                case NODO_CHAR:
                    valorSwitch = (Valor){.tipo = VAL_CHAR, .c_val = Valor_NombreVar->valor.c_val};
                    break;
                default:
                    printf(" » ❌ Error Switch: Tipo de dato no soportado en switch\n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Tipo de dato no soportado en switch";
                    lista_Errores[num_errores].Tipo_Error = "Sentencia Switch";
                    num_errores++;
                    break;
                }

            // Evaluar primer caso si existe
            int casoEncontrado = 0;
            if (n->izq != NULL) {
                Valor valorCaso = Evaluar(n->izq->izq);
                if (CompararValores(valorSwitch, valorCaso)) {
                    printf(" » 🔀 Ejecutando primer caso del Switch\n");
                    Evaluar(n->izq->der);
                    casoEncontrado = 1;
                }
            }

            // Evaluar casos adicionales si existen y no se encontró coincidencia
            if (!casoEncontrado && n->lista_nodos != NULL) {
                for (int i = 0; n->lista_nodos[i] != NULL; i++) {
                    Valor valorCaso = Evaluar(n->lista_nodos[i]->izq);
                    if (CompararValores(valorSwitch, valorCaso)) {
                    printf(" » 🔀 Ejecutando caso %d del Switch\n", i + 2);
                    Evaluar(n->lista_nodos[i]->der);
                    casoEncontrado = 1;
                    break;
                    }
                }
            }

            // Ejecutar caso default si existe y no se encontró coincidencia
            if (!casoEncontrado && n->nodo_else != NULL) {
                printf(" » 🔀 Ejecutando caso default del Switch\n");
                Evaluar(n->nodo_else);
                printf("El tipo de nodo_else es: %d\n", n->nodo_else->tipo);
            }

            // Liberar memoria si se usó un string
            if (valorSwitch.tipo == VAL_STRING) {
                free(valorSwitch.s_val);
            }
            break;
        }

        case NODO_SWITCH_DEFAULT: { // * ----------------------------------------------------------------------------------------
            Evaluar(n->izq);
            break;
        }

        case NODO_FUNCTION_DECLARATION: { // * ----------------------------------------------------------------------------------------
            // * Nombre de la funcion en "n->nombre"
            // * Tipo de retorno en "n->valor.varType"
            // * Parametros en "n->izq" (lista enlazada de nodos PARAMETRO)
            // * Cuerpo de la funcion en "n->der" (nodo LISTA)
            // Guardar la funcion en la tabla de simbolos
            Agregar_Funcion(n->nombre, n->valor.varType, n->lista_nodos, n->izq);

            printf(" » 📚 Funcion Registrada: '%s'\n", n->nombre);
            break;
        }

        case NODO_FUNCTION_CALL_NO_PARAM: { // * ----------------------------------------------------------------------------------------
            // * Nombre de la funcion en "n->nombre"
            // Buscar la funcion en la tabla de simbolos
            Funcion* funcionStruct = Acceso_Funcion(n->nombre);
            if (funcionStruct == NULL) {
                printf(" » ❌ Error Funcion: Funcion '%s' no encontrada\n", n->nombre);
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "Funcion no encontrada";
                lista_Errores[num_errores].Tipo_Error = "Llamado de Funcion";
                num_errores++;
                v.tipo = VAL_NULL;
                v.null_val = "-Func Not Found Err"; // Error de funcion no encontrada
                return v;
            }

            // Verificar si la funcion viene sin parametros ejecutarla funcion directamente
            if (strcmp(funcionStruct->parametros[0]->valor.s_val, "NO PARAMETROS") == 0) {
                // Ejecutar el cuerpo de la funcion
                printf(" » ▶️ Ejecutando Funcion: '%s' sin parametros\n", n->nombre);
                Evaluar(funcionStruct->instrucciones);
                break;
            }
            break;
        }

        case NODO_RETURN_FUNC: { // * ----------------------------------------------------------------------------------------
            // * Valor a retornar en "n->izq"
            Valor retorno = Evaluar(n->izq);
            printf(" » 🔙 Retornando valor de funcion\n");
            return retorno;
        }

        case NODO_ASIGNATION_FUNC: { // * ----------------------------------------------------------------------------------------
            // Obtener la función de la tabla de símbolos
            Funcion* funcionStruct = Acceso_Funcion(n->izq->nombre);
            if (funcionStruct == NULL) {
            printf(" » ❌ Error Funcion: Funcion '%s' no encontrada\n", n->izq->nombre);
            lista_Errores[num_errores].Num = num_errores;
            lista_Errores[num_errores].Desc_Error = "Funcion no encontrada";
            lista_Errores[num_errores].Tipo_Error = "Llamado de Funcion";
            num_errores++;
            break;
            }

            // Verificar que el tipo de retorno coincida con el tipo declarado
            if (strcmp(funcionStruct->tipoRetorno, n->valor.varType) != 0) {
            printf(" » ❌ Error: Tipo de retorno de función no coincide con tipo declarado\n");
            lista_Errores[num_errores].Num = num_errores;
            lista_Errores[num_errores].Desc_Error = "Tipo de retorno no coincide";
            lista_Errores[num_errores].Tipo_Error = "Asignacion Funcion";
            num_errores++;
            break;
            }

            // Evaluar los parámetros y almacenarlos directamente
            if (n->izq->lista_nodos != NULL) {
                int i = 0;
                while (n->izq->lista_nodos[i] != NULL && funcionStruct->parametros[i] != NULL) {
                    // Evaluar el valor del parámetro
                    Valor val = Evaluar(n->izq->lista_nodos[i]);
                    // Asignar el parámetro según su tipo
                    switch (val.tipo) {
                        case VAL_INT:
                            AsignarVariable_Int(funcionStruct->parametros[i]->nombre, val.i_val);
                            break;
                        case VAL_FLOAT:  
                            AsignarVariable_Float(funcionStruct->parametros[i]->nombre, val.f_val);
                            break;
                        case VAL_DOUBLE:
                            AsignarVariable_Double(funcionStruct->parametros[i]->nombre, val.d_val); 
                            break;
                        case VAL_STRING:
                            AsignarVariable_String(funcionStruct->parametros[i]->nombre, val.s_val);
                            break;
                        case VAL_BOOL:
                            AsignarVariable_Boolean(funcionStruct->parametros[i]->nombre, val.b_val);
                            break;
                        case VAL_CHAR:
                            AsignarVariable_Char(funcionStruct->parametros[i]->nombre, val.c_val);
                            break;
                        default:
                            printf("Error: Tipo de parámetro no soportado\n");
                            break;
                    }
                    i++;
                }
            }

            // Ejecutar la función y obtener el valor de retorno
            Valor resultado = Evaluar(funcionStruct->instrucciones);  // ! ------------------
            // printf("el retorno fue de tipo: %d\n", resultado.tipo);
            // printf("y su valor nuimerico es: %d\n", resultado.i_val);
            // Asignar el resultado a la variable dependiendo del tipo
            switch (resultado.tipo) {
                case VAL_INT:
                    AsignarVariable_Int(n->nombre, resultado.i_val);
                    break;
                case VAL_FLOAT:
                    AsignarVariable_Float(n->nombre, resultado.f_val);
                    break;
                case VAL_DOUBLE:
                    AsignarVariable_Double(n->nombre, resultado.d_val);
                    break;
                case VAL_STRING:
                    AsignarVariable_String(n->nombre, resultado.s_val);
                    break;
                case VAL_BOOL:
                    AsignarVariable_Boolean(n->nombre, resultado.b_val);
                    break;
                case VAL_CHAR:
                    AsignarVariable_Char(n->nombre, resultado.c_val);
                    break;
                default:
                    printf(" » ❌ Error: Tipo de retorno no soportado\n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Tipo de retorno no soportado";
                    lista_Errores[num_errores].Tipo_Error = "Asignacion Funcion";
                    num_errores++;
                    break;
            }
            printf(" » 💾 Variable '%s' asignada con resultado de función '%s'\n", 
                n->nombre, n->izq->nombre);

            // Eliminar los parámetros de la tabla de símbolos
            if (funcionStruct->parametros[0] != NULL) {
            int i = 0;
            while (funcionStruct->parametros[i] != NULL) {
                EliminarVariable(funcionStruct->parametros[i]->nombre);
                i++;
            }
            }
            break;
        }

        case NODO_PRINT: { // * ----------------------------------------------------------------------------------------
            // ! TODO LO QUE SALGA EN PRINT ES LO QUE SE RETORNA AL FRONTEND
            Valor resultado = Evaluar(n->izq);
            char buffer[MAX_PRINT_LENGTH];

            switch (resultado.tipo) {

                case VAL_INT:
                    snprintf(buffer, MAX_PRINT_LENGTH, "%d\n", resultado.i_val);
                    //printf(" » 🖨️  » %d\n", resultado.i_val);
                    break;

                case VAL_FLOAT:
                    snprintf(buffer, MAX_PRINT_LENGTH, "%f\n", resultado.f_val);
                    //printf(" » 🖨️  »  %f\n", resultado.f_val);
                    break;

                case VAL_DOUBLE:
                    snprintf(buffer, MAX_PRINT_LENGTH, "%lf\n", resultado.d_val);
                    //printf(" » 🖨️  »  %lf\n", resultado.d_val);
                    break;
                
                case VAL_STRING:
                    snprintf(buffer, MAX_PRINT_LENGTH, "%s\n", resultado.s_val);
                    //printf(" » 🖨️  »  %s\n", resultado.s_val);
                    break;

                case VAL_BOOL:
                    if (resultado.b_val == 1) {
                        snprintf(buffer, MAX_PRINT_LENGTH, "True\n");
                        //printf(" » 🖨️  »  True \n");
                    } else {
                        snprintf(buffer, MAX_PRINT_LENGTH, "False\n");
                        //printf(" » 🖨️  »  False \n");
                    }
                    break;

                case VAL_CHAR:
                    snprintf(buffer, MAX_PRINT_LENGTH, "%c\n", resultado.c_val);
                    //printf(" » 🖨️ »  %c\n", resultado.c_val);
                    break;

                case VAL_NULL:
                    snprintf(buffer, MAX_PRINT_LENGTH, "%s\n", resultado.null_val);
                    //printf(" » 🖨️ »  %s\n", resultado.null_val);
                    break;

                default:
                snprintf(buffer, MAX_PRINT_LENGTH, "❓ Tipo de dato desconocido para Imprimir\n");
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "Tipo de dato desconocido para Imprimir";
                lista_Errores[num_errores].Tipo_Error = "Print";
                num_errores++;
                    //printf(" ❓ Tipo de dato desconocido para Imprimir \n");
                    break;
                }

            add_to_print_buffer(buffer);
            break;
        }

        // ? Nodo recursivo que lee cada instruccion
        case NODO_LISTA: { // * ----------------------------------------------------------------------------------------
            if (n->izq != NULL) {
                Valor resultado_izq = Evaluar(n->izq);
                // Si encontramos un return, propagarlo inmediatamente
                if (n->izq->tipo == NODO_RETURN_FUNC) {
                    return resultado_izq;
                }
            }
            
            if (n->der != NULL) {
                Valor resultado_der = Evaluar(n->der);
                // Si encontramos un return, propagarlo inmediatamente
                if (n->der->tipo == NODO_RETURN_FUNC) {
                    return resultado_der;
                }
            }
            break;
        }
        
        // ! DEclaraciones y esas weas de las variables en tabla de simbolos se trabaja
        // ! Aqui solo desglozamos valores y los mandamos
        // ! AQUI SE AÑADEN MAS CASES PARA LOS DISTINTOS NODOS Y LO QUE QUIERO QUE SALGA
    }
    //v.tipo = VAL_NULL;
    //v.null_val = "NODO DESCONOCIDO"; // Error de tipo
    //return v;
}
