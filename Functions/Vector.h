#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

// Tipo de dato de vector
typedef enum { T_INT, T_STRING } VectorType;

// Vector genérico (ints o strings)
typedef struct {
    void **data;       // punteros a datos
    size_t size;       // cantidad de elementos
    size_t capacity;   // capacidad reservada
    VectorType type;   // tipo del vector
} Vector;

// Funciones para vectores
Vector* vector_create(VectorType type, size_t initial_capacity);
void vector_add_int(Vector *vec, int value);
void vector_add_string(Vector *vec, const char *str);
int vector_get_int(Vector *vec, size_t index);
char* vector_get_string(Vector *vec, size_t index);
void vector_free(Vector *vec);

// Entrada de tabla de símbolos
typedef struct {
    char *name;
    Vector *vec;
} SymbolEntry;

// Tabla de símbolos
typedef struct {
    SymbolEntry *entries;
    size_t size;
    size_t capacity;
} SymbolTable;

// Funciones de tabla de símbolos
SymbolTable* table_create(size_t initial_capacity);
void table_add(SymbolTable *table, const char *name, Vector *vec);
Vector* table_get(SymbolTable *table, const char *name);
void table_free(SymbolTable *table);

#endif // VECTOR_H
