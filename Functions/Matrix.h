#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>

// Definición de Matriz
typedef enum {
    M_INT,
    M_STRING
} MatrixType;

typedef struct {
    MatrixType type;   // Tipo de dato
    size_t rows;       // Filas
    size_t cols;       // Columnas
    void **data;       // Puntero a punteros simulando arreglo 2D
} Matrix;

// Funciones para trabajar matriz
Matrix *matrix_create(MatrixType type, size_t rows, size_t cols);
void matrix_free(Matrix *m);
void matrix_set_int(Matrix *m, size_t row, size_t col, int value);
void matrix_set_string(Matrix *m, size_t row, size_t col, const char *value);
int matrix_get_int(Matrix *m, size_t row, size_t col);
const char *matrix_get_string(Matrix *m, size_t row, size_t col);

// Tabla de símbolos de matrices
typedef struct {
    char *name;
    Matrix *matrix;
} MatrixSymbol;

typedef struct {
    MatrixSymbol *symbols;
    size_t size;
    size_t capacity;
} MatrixTable;

MatrixTable *matrix_table_create(size_t initial_capacity);
void matrix_table_free(MatrixTable *table);
void matrix_table_add(MatrixTable *table, const char *name, Matrix *matrix);
Matrix *matrix_table_get(MatrixTable *table, const char *name);

#endif
