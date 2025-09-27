#include "AST.h"
#include "Evaluate.h"
#include "Tabla_Simbolos.h"
#include "PrintBuffer.h"
#include "Vector.h"
#include "Matrix.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

// * Este indice servira para hacer las acciones correspondientes
// * a la aritmetica permitiendo que el programa decida y vea
// * que tipo de dato es el que viene, mandamos un objeto valor para
// * almacenar el tipo y poder usarlo para ejecutar las operaciones

    int continue_ = 0;
    int break_ = 0;
    extern SymbolTable *symtab;
    extern MatrixTable *mtab;

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

        case NODO_NEGATIVO: { // * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);
            if (izq.tipo == VAL_INT) {
                v.tipo = VAL_INT;
                v.i_val = -izq.i_val;
                return v;
            }
            if (izq.tipo == VAL_FLOAT) {
                v.tipo = VAL_FLOAT;
                v.f_val = -izq.f_val;
                return v;
            }
            if (izq.tipo == VAL_DOUBLE) {
                v.tipo = VAL_DOUBLE;
                v.d_val = -izq.d_val;
                return v;
            }
            // Manejar error de tipo
            v.tipo = VAL_NULL;
            v.null_val = "Error: tipo no soportado para negacion";
            return v;
        }

        case NODO_NOT: { // * ----------------------------------------------------------------------------------------
            Valor izq = Evaluar(n->izq);

            if (izq.tipo == VAL_BOOL) {
            v.tipo = VAL_BOOL;
            v.b_val = !izq.b_val;
            return v;
            }
        }

        case NODO_MODULO: {
            
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
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
            
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }

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
            
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
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
            
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
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
            
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
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
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
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

            //Verificar si la variable ya fue declarada
            if (BuscarVariable(n->nombre) == 1) {
                printf(" »   Error: La variable '%s' ya ha sido declarada.\n", n->nombre);
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "Variable ya declarada";
                lista_Errores[num_errores].Tipo_Error = "Declaracion Variable";
                num_errores++;
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
                } else if (izq.tipo == VAL_CHAR) {
                    // Permitir asignar un char usando su valor ASCII
                    AsignarVariable_Int(n->nombre, (int)izq.c_val);
                    printf(" » 💾 Variable Registrada (int -> char): '%s' asignada con valor ASCII: %d \n", n->nombre, (int)izq.c_val);
                } else {
                    printf(" »   Int Error: Tipo de dato no coincide para %s \n", n->nombre);
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
                } else if (izq.tipo == VAL_INT) {
                    // permitir asignar un int convirtiéndolo a float
                    AsignarVariable_Float(n->nombre, (float)izq.i_val);
                    printf(" » 💾 Variable Registrada (float -> int): '%s' asignada con valor: %f \n", n->nombre, (float)izq.i_val);
                } else {
                    printf(" »   Float Error: Tipo de dato no coincide \n");
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
                    printf(" »   String Error: Tipo de dato no coincide para %s \n", n->nombre);
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
                    printf(" »   Char Error: Tipo de dato no coincide para %s \n", n->nombre);
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
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible";
                    lista_Errores[num_errores].Tipo_Error = "Declaracion Short";
                    num_errores++;
                }

            } else if (strcmp(n->valor.varType, "double") == 0) {
                if (izq.tipo == VAL_DOUBLE) {
                    AsignarVariable_Double(n->nombre, izq.d_val);
                    printf(" » 💾 Variable Registrada: '%s' asignada con valor: %f \n", n->nombre, izq.d_val);
                } else if (izq.tipo == VAL_FLOAT) {
                    // Permitir asignar un float convirtiéndolo a double
                    AsignarVariable_Double(n->nombre, (double)izq.f_val);
                    printf(" » 💾 Variable Registrada (double -> float): '%s' asignada con valor: %f \n", n->nombre, (double)izq.f_val);
                } else {
                    printf(" »   Double Error: Tipo de dato no coincide \n");
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
            
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
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
            
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
            Valor izq = Evaluar(n->izq);
            Nodo* varNodo = Acceso_Variable(n->nombre);
            // * Nombre de variable en "n->nombre"
            // * Valor asignado en "izq.[Atributo segun tipo]"
            // * Buscar si la variable ya existe
            
            if (varNodo != NULL) {

                if (n->izq->tipo == NODO_MATRIZ_REFERENCE) {
                    // Si es una referencia a matriz verificar si existe la variable
                    // extraer el nombre de la matriz
                    char* nombreMatriz = n->izq->nombre;
                    //buscar la matriz en la tabla de simbolos
                    Matrix *matriz = matrix_table_get(mtab, strdup(nombreMatriz));
                    if (matriz == NULL) {
                        printf(" »   Error: La matriz '%s' no ha sido declarada.\n", nombreMatriz);
                        lista_Errores[num_errores].Num = num_errores;
                        lista_Errores[num_errores].Desc_Error = "Matriz no declarada";
                        lista_Errores[num_errores].Tipo_Error = "Asignacion Matriz";
                        num_errores++;
                        break;
                    }

                    // extraer los indices
                    Valor index1 = Evaluar(n->izq->izq);
                    Valor index2 = Evaluar(n->izq->der);

                    if (index1.tipo != VAL_INT || index2.tipo != VAL_INT) {
                        printf(" »   Error: Los indices de la matriz deben ser enteros.\n");
                        lista_Errores[num_errores].Num = num_errores;
                        lista_Errores[num_errores].Desc_Error = "Indices no enteros";
                        lista_Errores[num_errores].Tipo_Error = "Asignacion Matriz";
                        num_errores++;
                        break;
                    }

                    //buscar la vairble en n->nombre para saber su tipo de dato
                    Nodo* varTipoNodo = Acceso_Variable(n->nombre);
                    Valor varTipo = Evaluar(varTipoNodo);

                    if (varTipo.tipo == VAL_INT) {
                        // OBTENER EL VALOR DE LA MATRIZ EN LOS INDICES CON MATRIX GET INT
                        int valorINT= matrix_get_int(matriz, index1.i_val, index2.i_val);
                        Valor nx;
                        nx.tipo = VAL_INT;
                        nx.i_val = valorINT;
                        // ASIGNAR EL VALOR A LA VARIABLE
                        Actualizar_Variable(n->nombre, nx);
                        break;
                    } else if (varTipo.tipo == VAL_STRING) {
                        // OBTENER EL VALOR DE LA MATRIZ EN LOS INDICES CON MATRIX GET STRING
                        char* valorSTR = strdup(matrix_get_string(matriz, index1.i_val, index2.i_val));
                        Valor nx;
                        nx.tipo = VAL_STRING;
                        nx.s_val = valorSTR;
                        // ASIGNAR EL VALOR A LA VARIABLE
                        Actualizar_Variable(n->nombre, nx);
                        break;
                    } else {
                        printf(" »   Error: Tipo de dato no soportado en asignacion desde matriz.\n");
                        lista_Errores[num_errores].Num = num_errores;
                        lista_Errores[num_errores].Desc_Error = "Tipo de dato no soportado";
                        lista_Errores[num_errores].Tipo_Error = "Asignacion Matriz";
                        num_errores++;
                        break;
                    }
                }


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
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
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

            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
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
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
            // * Nombre de variable en "n->nombre"
            // * Tipo de variable en "n->valor.varType"
            // * Tipo del vector en "n->izq"

            // ! ENTRA NODO_DECLARATION DE VECTOR = n

            // del nodo izq ver que tipo de vector viene
            if (n->izq != NULL) {
                if (n->izq->tipo == NODO_VECTOR_AUTO) {
                    if(strcmp(n->valor.varType, n->izq->valor.varType) != 0) {
                        printf(" » ❌ Error Vector: El Tipo del vector no coincide con el tipo declarado \n");
                        lista_Errores[num_errores].Num = num_errores;
                        lista_Errores[num_errores].Desc_Error = "El nombre del vector no coincide con el tipo Declarado";
                        lista_Errores[num_errores].Tipo_Error = "Vector";
                        num_errores++;
                        break;
                    }

                    int vectorSize = n->izq->size_vector;

                    if (strcmp(n->valor.varType, "int") == 0) {
                        // ? CREAR VECTOR DE ENTEROS
                        Vector *vInt = vector_create(T_INT, vectorSize);

                        //agregar los valores al vector
                        for (int i = 0; i < vectorSize; i++) {
                            vector_add_int(vInt, 0); // valor por defecto   
                        }

                        table_add(symtab, n->nombre, vInt);
                        printf(" » 🆗 Vector de Int creado: '%s' con tamaño %d \n", n->nombre, vectorSize);
                        break;

                    } else if (strcmp(n->valor.varType, "float") == 0) {
                        // ? CREAR VECTOR DE FLOATS

                    } else if (strcmp(n->valor.varType, "String") == 0) {
                        Vector *vString = vector_create(T_STRING, vectorSize);

                        //agregar los valores al vector
                        for (int i = 0; i < vectorSize; i++) {
                            vector_add_string(vString, "Vacio"); // valor por defecto
                        }

                        table_add(symtab, n->nombre, vString);
                        printf(" » 🆗 Vector de String creado: '%s' con tamaño %d \n", n->nombre, vectorSize);
                        break;

                    } else if (strcmp(n->valor.varType, "boolean") == 0) {
                        // ? CREAR VECTOR DE BOOLEANOS

                    } else if (strcmp(n->valor.varType, "char") == 0) {
                        // ? CREAR VECTOR DE CHARS

                    } else if (strcmp(n->valor.varType, "long") == 0) {
                        // ? CREAR VECTOR DE LONGS

                    } else if (strcmp(n->valor.varType, "short") == 0) {
                        // ? CREAR VECTOR DE SHORTS

                    } else if (strcmp(n->valor.varType, "double") == 0) {
                        // ? CREAR VECTOR DE DOUBLES

                    } else if (strcmp(n->valor.varType, "byte") == 0) {
                        // ? CREAR VECTOR DE BYTES

                    } else {
                        printf(" » ❌ Error Vector: Tipo de dato no soportado para vector \n");
                        lista_Errores[num_errores].Num = num_errores;
                        lista_Errores[num_errores].Desc_Error = "Tipo de Dato no soportado para vector";
                        lista_Errores[num_errores].Tipo_Error = "Vector";
                        num_errores++;
                        break;
                    }
                    printf(" 🗃️ Vector Registrado: '%s' de tipo Auto con tamaño %d \n", n->nombre, n->izq->size_vector);
                    break;

                } else if (n->izq->tipo == NODO_VALORES_VECTOR_LIST) {

                    char* Name_vector_declaration = n->nombre;
                    char* Type_vector_declaration = n->valor.varType;

                    if (strcmp(Type_vector_declaration, "int") == 0 ) { // * ----------------------------------------------------------------------------------------
                        // ? CREAR VECTOR DE ENTEROS
                        Vector *vInt = vector_create(T_INT, 2);

                        // Agregar los valores al vector usando lista_nodos
                        for(int i = 0; n->izq->lista_nodos[i] != NULL; i++) {
                            Valor val = Evaluar(n->izq->lista_nodos[i]);
                            if (val.tipo == VAL_INT) {
                                vector_add_int(vInt, val.i_val);
                            } else {
                                printf(" » ❌ Error Vector: Tipo de dato no coincide en los valores del vector \n");
                                lista_Errores[num_errores].Num = num_errores;
                                lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible en los valores del vector";
                                lista_Errores[num_errores].Tipo_Error = "Vector";
                                num_errores++;
                                break;
                            }
                        }

                        table_add(symtab, Name_vector_declaration, vInt);
                        printf(" 🗃️ Vector Registrado: '%s' de tipo Explicito \n", n->nombre);
                        break;

                    } else if (strcmp(Type_vector_declaration, "String") == 0 ) { // * ------------------------------------------------------------------
                        // ? CREAR VECTOR DE STRINGS
                        Vector *vString = vector_create(T_STRING, 2);

                        // Agregar los valores al vector usando lista_nodos
                        for(int i = 0; n->izq->lista_nodos[i] != NULL; i++) {
                            Valor val = Evaluar(n->izq->lista_nodos[i]); // ! si retorna string
                            if (val.tipo == VAL_STRING) {
                                vector_add_string(vString, val.s_val);
                            } else {
                                printf(" » ❌ Error Vector: Tipo de dato no coincide en los valores del vector \n");
                                lista_Errores[num_errores].Num = num_errores;
                                lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible en los valores del vector";
                                lista_Errores[num_errores].Tipo_Error = "Vector";
                                num_errores++;
                                break;
                            }
                        }
                        table_add(symtab, Name_vector_declaration, vString);
                        printf(" 🗃️ Vector Registrado: '%s' de tipo Explicito \n", n->nombre);
                        break;
                    }

                    break;
                } else if (n->izq->tipo == NODO_ARRAY_ADD) {
                    // ? CREAR VECTOR CON VALORES AGREGADOS DINAMICAMENTE
                    char* Name_vector_declaration = n->nombre;
                    char* Name_Vector_exist = n->izq->nombre; // nombre del vector al que se le agregaran los valores
                    char* Type_vector_declaration = n->valor.varType;

                    // verificar que el vaector exista
                    Vector* vec = table_get(symtab, Name_Vector_exist);
                    if (vec == NULL) {
                        printf(" » ❌ Error Vector: El vector '%s' no existe para agregar valores \n", Name_Vector_exist);
                        lista_Errores[num_errores].Num = num_errores;
                        lista_Errores[num_errores].Desc_Error = "El vector no existe para agregar valores";
                        lista_Errores[num_errores].Tipo_Error = "Vector";
                        num_errores++;
                        break;
                    }   

                    //agreagar el valor al vector
                    Valor val = Evaluar(n->izq->izq); // valor a agregar al vector
                    if (strcmp(Type_vector_declaration, "int") == 0 ) { // * ----------------------------------------------------------------------------------------
                        if (val.tipo == VAL_INT) {
                            // declaramos el nuevo vector
                            Vector *vInt = vector_create(T_INT, 2);
                            size_t vectorSize = vec->size;
                            int currentSize = (int)vectorSize;

                            //agregar los valores al vector
                            for (int i = 0; i < currentSize; i++) {
                                int value = vector_get_int(vec, i);
                                vector_add_int(vInt, value);
                            }

                            //añadir el ultimo valor
                            vector_add_int(vInt, val.i_val);

                            table_add(symtab, Name_vector_declaration, vInt);
                            printf(" » 🆗 Vector con Func add Int creado: '%s' \n", n->nombre);
                            break;

                        } else {
                            printf(" » ❌ Error Vector: Tipo de dato no coincide en los valores del vector \n");
                            lista_Errores[num_errores].Num = num_errores;
                            lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible en los valores del vector";
                            lista_Errores[num_errores].Tipo_Error = "Vector";
                            num_errores++;
                            break;
                        }
                    }


                    if (strcmp(Type_vector_declaration, "String") == 0 ) { // * ------------------------------------------------------------------
                        if (val.tipo == VAL_STRING) {
                            // declaramos el nuevo vector
                            printf("--- se esta creando un nuevo vector de string con add\n");
                            Vector *vString = vector_create(T_STRING, 2);
                            size_t vectorSize = vec->size;
                            int currentSize = (int)vectorSize;

                            //agregar los valores al vector
                            for (int i = 0; i < currentSize; i++) {
                                char* value = vector_get_string(vec, i);
                                vector_add_string(vString, value);
                            }

                            //añadir el ultimo valor
                            vector_add_string(vString, val.s_val);

                            table_add(symtab, Name_vector_declaration, vString);
                            printf(" » 🆗 Vector con Func add String creado: '%s' \n", n->nombre);
                            break;

                        } else {
                            printf(" » ❌ Error Vector: Tipo de dato no coincide en los valores del vector \n");
                            lista_Errores[num_errores].Num = num_errores;
                            lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible en los valores del vector";
                            lista_Errores[num_errores].Tipo_Error = "Vector";
                            num_errores++;
                            break;
                            }
                        }

                    break;

                } else {
                    printf(" »   Tipo de dato desconocido en declaracion de vector * \n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Dato desconocido en declaracion de vector";
                    lista_Errores[num_errores].Tipo_Error = "Vector";
                    num_errores++;
                    break;
                }
            }
            break;
        }

        case NODO_VECTOR_ASIGNATION: { // * ----------------------------------------------------------------------------------------
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
            // ! AQUI ENTRA EL NODO_VECTOR_ASIGNATION = n
            char* Asignation_Name = n->nombre; // nombre del vector
            char* Asignation_Type = n->valor.varType; // tipo del vector
            char* Name_of_vector = n->izq->nombre; // nombre del vector al que se le asignara el valor
            Valor Index_of_vector = Evaluar(n->izq->izq); // indice del vector al que se le asignara el valor
            
            if (Index_of_vector.tipo != VAL_INT) {
                printf(" » ❌ Error Vector Asignation: El indice del vector debe ser un entero \n");
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "El indice del vector debe ser un entero";
                lista_Errores[num_errores].Tipo_Error = "Asignacion Vector";
                num_errores++;
                break;
            }

            // verificar si el vector existe
            Vector* vec = table_get(symtab, Name_of_vector);
            if (vec == NULL) {
                printf(" » ❌ Error Vector Asignation: El vector '%s' no existe \n", Name_of_vector);
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "El vector no existe";
                lista_Errores[num_errores].Tipo_Error = "Asignacion Vector";
                num_errores++;
            }

            //Obtener el valor del indice del vector para asignarlo
            if (vec->type == T_INT) { // * ASIGNACION DE VARIABLE INT
                int value_to_assign = vector_get_int(vec, Index_of_vector.i_val);

                //declarar variable
                AsignarVariable_Int(Asignation_Name, value_to_assign);
                printf(" » 🆗 Vector Asignado: '%s' del vector '%s' con valor %d \n", Asignation_Name, Name_of_vector, value_to_assign);
                break;
            } else if (vec->type == T_STRING) {
                char* value_to_assign = vector_get_string(vec, Index_of_vector.i_val);

                //declarar variable
                AsignarVariable_String(Asignation_Name, value_to_assign);
                printf(" » 🆗 Vector Asignado: '%s' del vector '%s' con valor %s \n", Asignation_Name, Name_of_vector, value_to_assign);
                break;
            }


            break;
        }

        case NODO_DECLARATION_MATRIX: { // * ----------------------------------------------------------------------------------------
            
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
            // * Nombre de variable en "n->nombre"
            // * Tipo de variable en "n->valor.varType"
            // * Tipo del vector en "n->izq"
            // del nodo izq ver que tipo de vector viene
            if (n->izq != NULL) {
                if (n->izq->tipo == NODO_MATRIZ_AUTO) {
                    if(strcmp(n->valor.varType, n->izq->nombre) != 0) {
                        printf(" » ❌ Error Vector: El Tipo de matriz no coincide con el tipo declarado \n");
                        lista_Errores[num_errores].Num = num_errores;
                        lista_Errores[num_errores].Desc_Error = "El nombre de la matriz no coincide con el tipo Declarado";
                        lista_Errores[num_errores].Tipo_Error = "Matriz";
                        num_errores++;
                        break;
                    }

                    //Evaluar para ver los valores de las columnas y filas
                    Valor filas = Evaluar(n->izq->izq);
                    Valor columnas = Evaluar(n->izq->der);

                    if (strcmp(n->valor.varType, "int") == 0) {
                        // ? CREAR MATRIZ DE ENTEROS
                        int rows = filas.i_val;
                        int cols = columnas.i_val;

                        Matrix *mInt = matrix_create(T_INT, rows, cols);

                        //agregar los valores a la matriz
                        for (int i = 0; i < rows; i++) {
                            for (int j = 0; j < cols; j++) {
                                matrix_set_int(mInt, i, j, 0); // valor por defecto   
                            }
                        }

                        matrix_table_add(mtab, n->nombre, mInt);
                        printf(" » 🗃️ Matriz de Int creada: '%s' con tamaño %dx%d \n", n->nombre, rows, cols);
                        break;

                    } else if (strcmp(n->valor.varType, "String") == 0) {
                        // ? CREAR MATRIZ DE STRINGS
                        int rows = filas.i_val;
                        int cols = columnas.i_val;

                        Matrix *mString = matrix_create(T_STRING, rows, cols);

                        //agregar los valores a la matriz
                        for (int i = 0; i < rows; i++) {
                            for (int j = 0; j < cols; j++) {
                                matrix_set_string(mString, i, j, "Vacio"); // valor por defecto   
                            }
                        }

                        matrix_table_add(mtab, n->nombre, mString);
                        printf(" » 🗃️ Matriz de String creada: '%s' con tamaño %dx%d \n", n->nombre, rows, cols);
                        break;

                    }
                    break;

                    //AÑADIR UN ELSE IF PARA EL OTRO TIPO DE MATRIZ CON LOS VALORES DEFINIDOS
                } else if (n->izq->tipo == NODO_MATRIZ_WITH_VALUES) {
                    char* Name_matrix_declaration = n->nombre;
                    char* Type_matrix_declaration = n->valor.varType;
                    printf(" » 🔄 Creando matriz con valores explícitos...\n");
                    int max_iterations = 100; // Limitar a 100 iteraciones para evitar bucles infinitos

                    // Primero contar filas y columnas para crear la matriz
                    int filas = 0;
                    int columnas = 0;
                    
                    // Contar filas
                    for (int i = 0; n->izq->lista_nodos[i] != NULL; i++) {
                        filas++;
                        // Contar columnas usando la primera fila
                        if (i == 0) {
                            for (int j = 0; n->izq->lista_nodos[i]->lista_nodos[j] != NULL; j++) {
                                columnas++;
                            }
                        }
                        if (i >= max_iterations) {
                            printf(" » ❌ Error: Demasiadas filas en la declaración de matriz\n");
                            break;
                        }
                    }

                    // Crear la matriz con el tamaño correcto
                    Matrix* mInt = NULL;
                    Matrix* mString = NULL;
                    
                    if (strcmp(Type_matrix_declaration, "int") == 0) {
                        mInt = matrix_create(T_INT, filas, columnas);
                    } else if (strcmp(Type_matrix_declaration, "String") == 0) {
                        mString = matrix_create(T_STRING, filas, columnas);
                    }

                    // Recorrer y asignar valores
                    for (int i = 0; n->izq->lista_nodos[i] != NULL; i++) {
                        for (int j = 0; n->izq->lista_nodos[i]->lista_nodos[j] != NULL; j++) {
                            Valor val = Evaluar(n->izq->lista_nodos[i]->lista_nodos[j]);
                            
                            if (strcmp(Type_matrix_declaration, "int") == 0) {
                                if (val.tipo == VAL_INT) {
                                    matrix_set_int(mInt, i, j, val.i_val);
                                } else {
                                    printf(" » ❌ Error: Tipo de dato incompatible en matriz\n");
                                    break;
                                }
                            } else if (strcmp(Type_matrix_declaration, "String") == 0) {
                                if (val.tipo == VAL_STRING) {
                                    matrix_set_string(mString, i, j, val.s_val);
                                } else {
                                    printf(" » ❌ Error: Tipo de dato incompatible en matriz\n");
                                    break;
                                }
                            }
                            if (j >= max_iterations) {
                                printf(" » ❌ Error: Demasiadas columnas en la declaración de matriz\n");
                                break;
                            }
                        }
                        if (i >= max_iterations) {
                            printf(" » ❌ Error: Demasiadas filas en la declaración de matriz\n");
                            break;
                        }
                    }

                    // Agregar la matriz a la tabla
                    if (strcmp(Type_matrix_declaration, "int") == 0) {
                        matrix_table_add(mtab, Name_matrix_declaration, mInt);
                        printf(" » 🗃️ Matriz de Int '%s' creada con tamaño %dx%d\n", Name_matrix_declaration, filas, columnas);
                    } else if (strcmp(Type_matrix_declaration, "String") == 0) {
                        matrix_table_add(mtab, Name_matrix_declaration, mString);
                        printf(" » 🗃️ Matriz de String '%s' creada con tamaño %dx%d\n", Name_matrix_declaration, filas, columnas);
                    }
                    break;
                    
                } else {
                    printf(" » ❌ Tipo de dato desconocido en declaracion de matriz\n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Dato desconocido en declaracion de matriz";
                    lista_Errores[num_errores].Tipo_Error = "Matriz";
                    num_errores++;
                    break;
                }
            }
            break;
        }     

        case NODO_MATRIZ_ASIGNATION: { // * ----------------------------------------------------------------------------------------
            
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
            // ! AQUI ENTRA EL NODO_MATRIZ_REFERENCE = n
            char* Asignation_Name = n->nombre; // nombre de la variable que recibira el valor de la matriz
            char* Asignation_Type = n->valor.varType; // tipo de la variable que recibira el valor de la matriz

            Valor Row_Index = Evaluar(n->izq->izq); // indice de la fila
            Valor Col_Index = Evaluar(n->izq->der); // indice de la columna
            char* Name_of_matrix = n->izq->nombre; // nombre de la matriz

            //varificar que la matriz exista
            Matrix* mat = matrix_table_get(mtab, Name_of_matrix);
            if (mat == NULL) {
                printf(" » ❌ Error Matriz Asignation: La matriz '%s' no existe \n", Name_of_matrix);
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "La matriz no existe";
                lista_Errores[num_errores].Tipo_Error = "Asignacion Matriz";
                num_errores++;
                break;
            }

            //Obtener el valor del indice de la matriz para asignarlo
            if (mat->type == T_INT) { // * ASIGNACION DE VARIABLE INT
                int value_to_assign = matrix_get_int(mat, Row_Index.i_val, Col_Index.i_val);

                //declarar variable
                AsignarVariable_Int(Asignation_Name, value_to_assign);
                printf(" » 🆗 Valor de Matriz Asignada: '%s' de la matriz '%s' con valor %d \n", Asignation_Name, Name_of_matrix, value_to_assign);
                break;
            } else if (mat->type == T_STRING) {
                char* value_to_assign = strdup(matrix_get_string(mat, Row_Index.i_val, Col_Index.i_val));

                //declarar variable
                AsignarVariable_String(Asignation_Name, value_to_assign);
                printf(" » 🆗 Valor de Matriz Asignada: '%s' de la matriz '%s' con valor %s \n", Asignation_Name, Name_of_matrix, value_to_assign);
                free(value_to_assign);
                break;
            } else {
                printf(" » ❌ Error Matriz Asignation: Tipo de dato no soportado en matriz \n");
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "Tipo de Dato no soportado en matriz";
                lista_Errores[num_errores].Tipo_Error = "Asignacion Matriz";
                num_errores++;
                break;
            }
        }

        case NODO_MATRIZ_CHANGE_VALUE: { // * ----------------------------------------------------------------------------------------
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
            
            // ! AQUI ENTRA EL NODO_MATRIZ_CHANGE_VALUE = n
            char* Name_of_matrix = n->izq->nombre; // nombre de la matriz a modificar

            Valor Row_Index = Evaluar(n->izq->izq); // indice de la fila
            Valor Col_Index = Evaluar(n->izq->der); // indice de la columna
            Valor New_Value = Evaluar(n->der); // nuevo valor a asignar
            //varificar que la matriz exista
            Matrix* mat = matrix_table_get(mtab, strdup(Name_of_matrix));
            if (mat == NULL) {
                printf(" » ❌ Error Matriz Change Value: La matriz '%s' no existe \n", Name_of_matrix);
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "La matriz no existe";
                lista_Errores[num_errores].Tipo_Error = "Cambio de valor Matriz";
                num_errores++;
                break;
            }

            //Cambiar el valor del indice de la matriz
            if (mat->type == T_INT) { // * ASIGNACION DE VARIABLE INT
                if (New_Value.tipo != VAL_INT) {
                    printf(" » ❌ Error Matriz Change Value: El nuevo valor debe ser un entero \n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "El nuevo valor debe ser un entero";
                    lista_Errores[num_errores].Tipo_Error = "Cambio de valor Matriz";
                    num_errores++;
                    break;
                }
                matrix_set_int(mat, Row_Index.i_val, Col_Index.i_val, New_Value.i_val);
                printf(" » 🆗 Valor de Matriz Modificado: de la matriz '%s' en posicion [%d][%d] con valor %d \n", Name_of_matrix, Row_Index.i_val, Col_Index.i_val, New_Value.i_val);
                break;

            } else if (mat->type == T_STRING) {
                if (New_Value.tipo != VAL_STRING) {
                    printf(" » ❌ Error Matriz Change Value: El nuevo valor debe ser un String \n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "El nuevo valor debe ser un String";
                    lista_Errores[num_errores].Tipo_Error = "Cambio de valor Matriz";
                    num_errores++;
                    break;
                }
            }

        }

        case NODO_FOR_SENTENCE: { // * ----------------------------------------------------------------------------------------
            // Instrucciones del for each
            if (n->izq->tipo == NODO_FOR_EACH) {
                char* Vector_Name = n->izq->separador; // nombre del vector a recorrer
                char* Var_Name = n->izq->nombre; // nombre de la variable que tomara el valor del vector
                char* Type_Var = n->izq->valor.varType; // tipo de la variable que tomara el valor del vector
                int IsVector = 0;
                int IsMatrix = 0;

                // verificar que el vector exista
                Vector* vec = table_get(symtab, Vector_Name);
                if (vec != NULL) {
                    IsVector = 1;
                }

                Matrix* mat = matrix_table_get(mtab, Vector_Name);
                if (mat != NULL) {
                    IsMatrix = 1;
                }

                //
                if (!IsVector && !IsMatrix) {
                    printf(" » ❌ Error For Each: El vector o Matriz '%s' no existe \n", Vector_Name);
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "El vector o Matriz no existe";
                    lista_Errores[num_errores].Tipo_Error = "Sentencia For Each";
                    num_errores++;
                    break;
                }

                if(IsMatrix) {
                    // recorrer la matriz segun su tipo
                    if (mat->type == T_INT) {
                        int rowSize = mat->rows;
                        int colSize = mat->cols;
                        for (int i = 0; i < rowSize; i++) {
                            for (int j = 0; j < colSize; j++) {
                                // Obtener el valor actual de la matriz
                                int value = matrix_get_int(mat, i, j);
                                
                                // Asignar el valor a la variable temporal
                                AsignarVariable_Int(Var_Name, value);
                                
                                //printf(" » 🔄 For Each: Iterando valor %d en matriz '%s' [%d][%d]\n", 
                                //        value, Name_of_matrix, i, j);
                                
                                // Ejecutar el bloque de código
                                Evaluar(n->der);
                                
                                // Verificar si se encontró un break
                                if(break_) {
                                    printf(" » ⏹️ Break encontrado, saliendo del ciclo\n");
                                    break_ = 0;
                                    goto end_matrix_loop;
                                }
                                
                                // Verificar si se encontró un continue
                                if(continue_) {
                                    printf(" » ⏭️ Continue encontrado, saltando a siguiente iteracion\n");
                                    continue_ = 0;
                                    continue;
                                }
                            }
                        }
                        end_matrix_loop:
                        EliminarVariable(Var_Name);
                    } else if (mat->type == T_STRING) {
                        int rowSize = mat->rows;
                        int colSize = mat->cols;
                        for (int i = 0; i < rowSize; i++) {
                            for (int j = 0; j < colSize; j++) {
                                // Obtener el valor actual de la matriz
                                char* value = strdup(matrix_get_string(mat, i, j));
                                
                                // Asignar el valor a la variable temporal
                                AsignarVariable_String(Var_Name, value);
                                
                                //printf(" » 🔄 For Each: Iterando valor %s en matriz '%s' [%d][%d]\n", 
                                //      value, Name_of_matrix, i, j);
                                
                                // Ejecutar el bloque de código
                                Evaluar(n->der);
                                
                                // Verificar si se encontró un break
                                if(break_) {
                                    printf(" » ⏹️ Break encontrado, saliendo del ciclo\n");
                                    break_ = 0;
                                    goto end_matrix_loop_string;
                                }
                                
                                // Verificar si se encontró un continue
                                if(continue_) {
                                    printf(" » ⏭️ Continue encontrado, saltando a siguiente iteracion\n");
                                    continue_ = 0;
                                    continue;
                                }
                            }
                        }
                        end_matrix_loop_string:
                        EliminarVariable(Var_Name);
                    } else {
                        printf(" » ❌ Error For: Tipo de matriz no soportado en For Each\n");
                        lista_Errores[num_errores].Num = num_errores;
                        lista_Errores[num_errores].Desc_Error = "Tipo de matriz no soportado";
                        lista_Errores[num_errores].Tipo_Error = "Sentencia For Each";
                        num_errores++;
                        break;
                    }
                    break;
                }

                if (IsVector) {
                    // recorrer el vector segun su tipo
                    if (vec->type == T_INT) {
                        int vectorSize = (int)vec->size;
                        for (int i = 0; i < vectorSize; i++) {
                            // Obtener el valor actual del vector
                            int value = vector_get_int(vec, i);
                            
                            // Asignar el valor a la variable temporal
                            AsignarVariable_Int(Var_Name, value);
                            
                            printf(" » 🔄 For Each: Iterando valor %d en vector '%s'\n", value, Vector_Name);
                            
                            // Ejecutar el bloque de código
                            Evaluar(n->der);
                            
                            // Verificar si se encontró un break
                            if(break_) {
                                printf(" » ⏹️ Break encontrado, saliendo del ciclo\n");
                                break_ = 0;
                                break;
                            }
                            
                            // Verificar si se encontró un continue 
                            if(continue_) {
                                printf(" » ⏭️ Continue encontrado, saltando a siguiente iteracion\n");
                                continue_ = 0;
                                continue;
                            }
                        }
                        EliminarVariable (Var_Name);
                    } else if (vec->type == T_STRING) {
                        int vectorSize = (int)vec->size;
                        for (int i = 0; i < vectorSize; i++) {
                            // Obtener el valor actual del vector
                            char* value = vector_get_string(vec, i);
                            
                            // Asignar el valor a la variable temporal
                            AsignarVariable_String(Var_Name, value);
                            
                            printf(" » 🔄 For Each: Iterando valor %s en vector '%s'\n", value, Vector_Name);
                            
                            // Ejecutar el bloque de código
                            Evaluar(n->der);
                            
                            // Verificar si se encontró un break
                            if(break_) {
                                printf(" » ⏹️ Break encontrado, saliendo del ciclo\n"); 
                                break_ = 0;
                                break;
                            }
                            
                            // Verificar si se encontró un continue
                            if(continue_) {
                                printf(" » ⏭️ Continue encontrado, saltando a siguiente iteracion\n");
                                continue_ = 0;
                                continue;
                            }
                        }
                        EliminarVariable (Var_Name);
                    } else {
                        printf(" » ❌ Error For: Tipo de vector no soportado en For Each\n");
                        lista_Errores[num_errores].Num = num_errores;
                        lista_Errores[num_errores].Desc_Error = "Tipo de vector no soportado";
                        lista_Errores[num_errores].Tipo_Error = "Sentencia For Each";
                        num_errores++;
                        break;
                    }
                    break;
                }
            }

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

            // Ciclo principal del for clasico
            while(1) {
                // Evaluar condición
                printf(" » 🔄 Evaluando condicion For Simple \n");
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

                if(continue_) {
                    printf(" » ⏭️⏭️ Continue encontrado, saltando a siguiente iteracion\n");
                    continue_ = 0; // Reiniciar el estado de continue
                    
                    // Actualizar variable de control antes de continuar
                    Nodo* varNodo = Acceso_Variable(nombreVar);
                    if(varNodo == NULL) {
                        printf(" » ❌ Error For: Variable de control no encontrada\n");
                        break;
                    }
                    Valor valorActual = Evaluar(varNodo);
                    
                    Actualizar_Variable(nombreVar, (Valor){.tipo = VAL_INT, .i_val = valorActual.i_val + 1});
                    
                    continue;
                }

                // Ejecutar el bloque de instrucciones
                printf(" » ⏩ Ejecutando iteracion For\n");
                Evaluar(n->der);

                // Verificar si se encontró un break
                if(break_) {
                    printf(" » ⏹️ Break encontrado, saliendo del ciclo\n");
                    break_ = 0; // Reiniciar el estado de break
                    break;
                }

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
                    Actualizar_Variable(nombreVar, (Valor){.tipo = VAL_INT, .i_val = valorActual.i_val - 1});
                }
            }
            EliminarVariable (nombreVar);
            break;
        }

        case NODO_PLUS_MINUS_VAR: {
            
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
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

        case NODO_CONTINUE:  // * ----------------------------------------------------------------------------------------
            // Retornar un valor especial para indicar un continue
            continue_ = 1;
            break;
        

        case NODO_BREAK:  // * ----------------------------------------------------------------------------------------
            // Retornar un valor especial para indicar un break
            break_ = 1;
            break;
        

        case NODO_WHILE_SENTENCE: {
            // Save parent flags
            int outer_break = break_;
            int outer_continue = continue_;
            
            // Reset flags for this loop
            break_ = 0;
            continue_ = 0;

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
                
                // Ejecutar instrucciones
                Valor resultado = Evaluar(n->der);
                printf(" » 🔄 Ejecutada iteracion While\n");
                
                // Verificar break/continue después de la ejecución
                if(continue_) {
                    printf(" » ⏭️ Continue encontrado, saltando a siguiente iteracion\n");
                    continue_ = 0;  // Reset continue flag
                    continue;  // Skip to next iteration
                }
                
                if(break_) {
                    printf(" » ⏹️ Break encontrado, saliendo del ciclo\n");
                    break_ = 0;  // Reset break flag
                    break;  // Exit the loop
                }
            }

            // Restore parent flags
            break_ = outer_break;
            continue_ = outer_continue;
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
            
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
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
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
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
            
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            // * Valor a retornar en "n->izq"
            Valor retorno = Evaluar(n->izq);
            // esta llegando un nodo suma
            printf(" » 🔙 Retornando valor de funcion\n");
            return retorno;
        }

        case NODO_ASIGNATION_FUNC: { // * ----------------------------------------------------------------------------------------
            
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
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

        case NODO_ARRAYS_DECLARATION: {
           
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
            // ! AQUI ENTRA EL NODO: NODO_ARRAYS_DECLARATION = n
            if (n->izq->tipo == NODO_ARRAYS_INDEXOF) {  
                // nombre del vector a buscar el indice
                char* Name_array_to_find = n->izq->nombre;
                Valor Array_Key = Evaluar(n->izq->izq); // valor a buscar en el array
                // verificar si el vector existe
                Vector* vec = table_get(symtab, Name_array_to_find);
                if (vec == NULL) {
                    printf(" » ❌ Error Array: El array '%s' no existe \n", Name_array_to_find);
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "El array no existe";
                    lista_Errores[num_errores].Tipo_Error = "Array";
                    num_errores++;
                    break;
                }

                if (Array_Key.tipo == VAL_INT && vec->type == T_INT) {
                    int index_found = vector_find_int(vec, Array_Key.i_val);
                    //declarar variable
                    AsignarVariable_Int(n->nombre, index_found);
                    printf(" » 🆗 Array.IndexOf Asignado a '%s' del array el valor del indice \n", n->nombre);
                    break;

                } else if (Array_Key.tipo == VAL_STRING && vec->type == T_STRING) {
                    int index_found = vector_find_string(vec, Array_Key.s_val);
                    //declarar variable
                    AsignarVariable_Int(n->nombre, index_found);
                    printf(" » 🆗 Array.IndexOf Asignado a '%s' el valor del indice \n", n->nombre);
                    break;

                } else {
                    printf(" » ❌ Error Array IndexOf: Tipo de dato no coincide con el tipo del array \n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible en el IndexOf del array";
                    lista_Errores[num_errores].Tipo_Error = "Array";
                    num_errores++;
                    break;

                }

            } else if (n->izq->tipo == NODO_ARRAY_LENGTH) {
                // nombre del vector a buscar el indice
                char* Name_array_to_find = n->izq->nombre;
                int IsVector = 0;
                int IsMatrix = 0;

                // verificar si el vector existe
                Vector* vec = table_get(symtab, Name_array_to_find);
                if (vec != NULL) {
                    IsVector = 1;  
                }

                //Verificar si la matriz existe
                Matrix* mat = matrix_table_get(mtab, Name_array_to_find);
                if (mat != NULL) {
                    IsMatrix = 1;
                }

                if (IsVector == 0 && IsMatrix == 0) {
                    printf(" » ❌ Error Array Length: El array o matriz '%s' no existe \n", Name_array_to_find);
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "El array o matriz no existe";
                    lista_Errores[num_errores].Tipo_Error = "Array/Matrix";
                    num_errores++;
                    break;
                }

                if (IsMatrix == 1) {
                    //declarar variable
                    AsignarVariable_Int(n->nombre, mat->rows);
                    printf(" » 🆗 Array.Length Asignado a '%s'\n", n->nombre);
                    break;
                }

                if(IsVector == 1) {
                // obtener el length del vector
                size_t length_of_array = vector_size(vec);
                int count = (int)length_of_array;

                //declarar variable
                AsignarVariable_Int(n->nombre, count);
                printf(" » 🆗 Array.Length Asignado a '%s'\n", n->nombre);
                break;
                }
            }
        }

        case NODO_STRING_JOIN_ARRAY: {
            
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
            char* Nombre_Variable_Asignar = n->nombre;
            char* Separador = n->separador;
            char separador_str[256];
            char* Tipo_de_Variable = n->valor.varType;
            char* Identificador = n->lista_nodos[0]->nombre;

            // verificar que el vaector exista
            Vector* vec = table_get(symtab,Identificador);
            if (vec == NULL) {
                printf(" » ❌ Error Vector: El vector '%s' no existe para agregar valores \n",  Identificador);
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "El vector no existe para agregar valores";
                lista_Errores[num_errores].Tipo_Error = "Vector";
                num_errores++;
                break;
            } 

            // Quitar las comillas del separador si existen
            size_t len = strlen(Separador);
            if (len >= 2 && Separador[0] == '"' && Separador[len - 1] == '"') {
                strncpy(separador_str, Separador + 1, len - 2);
                separador_str[len - 2] = '\0';
            } else {
                strncpy(separador_str, Separador, sizeof(separador_str) - 1);
                separador_str[sizeof(separador_str) - 1] = '\0';
            }

            char resultado[1000] = ""; // Cadena para almacenar el resultado final
            if (vec->type == T_STRING) {
                size_t vectorSize = vec->size;
                int currentSize = (int)vectorSize;

                for (int i = 0; i < currentSize; i++) {
                    char* value = vector_get_string(vec, i);
                    strcat(resultado, value);
                    if (i < currentSize - 1) {
                        strcat(resultado, separador_str);
                    }
                }

                // Asignar el resultado a la variable dependiendo del tipo
                if (strcmp(Tipo_de_Variable, "String") == 0) {
                    AsignarVariable_String(Nombre_Variable_Asignar, resultado);
                    printf(" » 🆗 Variable '%s' asignada con resultado de Join del array '%s'\n", 
                        Nombre_Variable_Asignar, Identificador);
                } else {
                    printf(" » ❌ Error: Tipo de retorno no soportado en Join\n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Tipo de retorno no soportado en Join";
                    lista_Errores[num_errores].Tipo_Error = "Join Array";
                    num_errores++;
                }

            } else {
                printf(" » ❌ Error Vector Join: Tipo de dato no coincide en los valores del vector \n");
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible en los valores del vector";
                lista_Errores[num_errores].Tipo_Error = "Vector";
                num_errores++;
            }

            break;
        }

        case NODO_VECTOR_ASIGNATION_REF: {
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
            char* Name_of_vector = n->izq->nombre; // nombre del vector a asignar
            Valor number = Evaluar(n->izq->izq); // valor del índice
            int index = number.i_val; // indice donde se asignara el valor
            Valor assignValue = Evaluar(n->der); // valor a asignar al vector

            //verificar si el vector existe
            Vector* vec = table_get(symtab, Name_of_vector);
            if (vec == NULL) {
                printf(" » ❌ Error Vector: El vector '%s' no existe para asignar valores \n", Name_of_vector);
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "El vector no existe para asignar valores";
                lista_Errores[num_errores].Tipo_Error = "Vector";
                num_errores++;
                break;
            }

            //verificar si el tipo de dato coincide
            if (vec->type == T_INT && assignValue.tipo == VAL_INT) {
                vector_set_int(vec, index, assignValue.i_val);
                printf(" » 🆗 Valor %d agregado al vector '%s'\n", assignValue.i_val, Name_of_vector);

            } else if (vec->type == T_STRING && assignValue.tipo == VAL_STRING) {
                vector_set_string(vec, index, assignValue.s_val);
                printf(" » 🆗 Valor %s agregado al vector '%s'\n", assignValue.s_val, Name_of_vector);

            } else {
                printf(" » ❌ Error Vector: Tipo de dato no coincide en los valores del vector \n");
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "Tipo de Dato Incompatible en los valores del vector";
                lista_Errores[num_errores].Tipo_Error = "Vector";
                num_errores++;
            }
            break;
        }

        case NODO_ASIGNACION_FUNCION_NO_PARAM:{ 
            
            if (continue_) {
                // Si estamos en un estado de continue o break, no evaluamos más
                continue_ = 0; // Reiniciar el estado de continue
                break;
            }
            
            // * Nombre de la funcion en "n->nombre"
            // Buscar la funcion en la tabla de simbolos
            char* Nombre_variable_a_declarar = n->nombre;
            char* Tipo_de_variable = n->valor.varType;

            Funcion* funcionStruct = Acceso_Funcion(n->separador);
            if (funcionStruct == NULL) {
                printf(" » ❌ Error Funcion: Funcion '%s' no encontrada\n", n->separador);
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "Funcion no encontrada";
                lista_Errores[num_errores].Tipo_Error = "Llamado de Funcion";
                num_errores++;
                break;
            }

            // verificar el tipo de funcion y el tipo de variable
            if (strcmp(funcionStruct->tipoRetorno, Tipo_de_variable) != 0) {
                printf(" » ❌ Error: Tipo de retorno de función no coincide con tipo declarado\n");
                lista_Errores[num_errores].Num = num_errores;
                lista_Errores[num_errores].Desc_Error = "Tipo de retorno no coincide";
                lista_Errores[num_errores].Tipo_Error = "Asignacion Funcion";
                num_errores++;
                break;
            }

            // ejecutar la funcion y asignar su valor a una nueva declaracion de variable segun el tipo
            Valor resultado = Evaluar(funcionStruct->instrucciones);  // ! ------------------
            // printf("el retorno fue de tipo: %d\n", resultado.tipo);
            // printf("y su valor nuimerico es: %d\n", resultado.i_val);
            // Asignar el resultado a la variable dependiendo del tipo
            switch (resultado.tipo) {
                case VAL_INT:
                    AsignarVariable_Int(Nombre_variable_a_declarar, resultado.i_val);
                    break;

                case VAL_FLOAT:
                    AsignarVariable_Float(Nombre_variable_a_declarar, resultado.f_val);
                    break;

                case VAL_DOUBLE:
                    AsignarVariable_Double(Nombre_variable_a_declarar, resultado.d_val);
                    break;

                case VAL_STRING:
                    AsignarVariable_String(Nombre_variable_a_declarar, resultado.s_val);
                    break;

                case VAL_BOOL:
                    AsignarVariable_Boolean(Nombre_variable_a_declarar, resultado.b_val);
                    break;

                case VAL_CHAR:
                    AsignarVariable_Char(Nombre_variable_a_declarar, resultado.c_val);
                    break;

                default:
                    printf(" » ❌ Error: Tipo de dato desconocido para asignar a la variable\n");
                    lista_Errores[num_errores].Num = num_errores;
                    lista_Errores[num_errores].Desc_Error = "Tipo de dato desconocido para asignar a la variable";
                    lista_Errores[num_errores].Tipo_Error = "Asignacion Funcion";
                    num_errores++;
                    break;
            }
            break;
        }

        case NODO_PRINT: { // * ----------------------------------------------------------------------------------------
            // ! TODO LO QUE SALGA EN PRINT ES LO QUE SE RETORNA AL FRONTEND

            if (continue_ == 1) {
                //continue_ = 0; // Reiniciar el estado de continue
                break;
            }

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
                    if (strchr(resultado.s_val, '~') != NULL) {
                        char *temp = strdup(resultado.s_val);
                        char *p = strchr(temp, '~');
                        if (p != NULL) {
                            *p = '\0'; // Reemplaza el '~' con un terminador de cadena
                        }
                        snprintf(buffer, MAX_PRINT_LENGTH, "%s", temp);
                        free(temp);
                    } else {
                        // Normal case with newline 
                        snprintf(buffer, MAX_PRINT_LENGTH, "%s\n", resultado.s_val);
                    }
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
