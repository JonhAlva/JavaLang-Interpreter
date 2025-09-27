#include "Matrix.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Funciones de Matriz
Matrix *matrix_create(MatrixType type, size_t rows, size_t cols) {
    Matrix *m = malloc(sizeof(Matrix));
    m->type = type;
    m->rows = rows;
    m->cols = cols;
    m->data = malloc(rows * sizeof(void*));

    for (size_t i = 0; i < rows; i++) {
        m->data[i] = calloc(cols, sizeof(void*));
    }

    return m;
}

void matrix_free(Matrix *m) {
    if (!m) return;

    if (m->type == M_STRING) {
        for (size_t i = 0; i < m->rows; i++) {
            for (size_t j = 0; j < m->cols; j++) {
                free(((char**)m->data[i])[j]);
            }
        }
    }

    for (size_t i = 0; i < m->rows; i++) {
        free(m->data[i]);
    }
    free(m->data);
    free(m);
}

void matrix_set_int(Matrix *m, size_t row, size_t col, int value) {
    if (m->type != M_INT) return;
    ((int*)m->data[row])[col] = value;
}

void matrix_set_string(Matrix *m, size_t row, size_t col, const char *value) {
    if (m->type != M_STRING) return;
    ((char**)m->data[row])[col] = strdup(value);
}

int matrix_get_int(Matrix *m, size_t row, size_t col) {
    if (m->type != M_INT) return 0;
    return ((int*)m->data[row])[col];
}

const char *matrix_get_string(Matrix *m, size_t row, size_t col) {
    if (m->type != M_STRING) return NULL;
    return ((char**)m->data[row])[col];
}

// Funciones de MatrixTable
MatrixTable *matrix_table_create(size_t initial_capacity) {
    MatrixTable *table = malloc(sizeof(MatrixTable));
    table->symbols = malloc(initial_capacity * sizeof(MatrixSymbol));
    table->size = 0;
    table->capacity = initial_capacity;
    return table;
}

void matrix_table_free(MatrixTable *table) {
    if (!table) return;
    for (size_t i = 0; i < table->size; i++) {
        free(table->symbols[i].name);
        matrix_free(table->symbols[i].matrix);
    }
    free(table->symbols);
    free(table);
}

void matrix_table_add(MatrixTable *table, const char *name, Matrix *matrix) {
    if (table->size == table->capacity) {
        table->capacity *= 2;
        table->symbols = realloc(table->symbols, table->capacity * sizeof(MatrixSymbol));
    }

    table->symbols[table->size].name = strdup(name);
    table->symbols[table->size].matrix = matrix;
    table->size++;
}

Matrix *matrix_table_get(MatrixTable *table, const char *name) {
    for (size_t i = 0; i < table->size; i++) {
        if (strcmp(table->symbols[i].name, name) == 0) {
            return table->symbols[i].matrix;
        }
    }
    return NULL;
}
