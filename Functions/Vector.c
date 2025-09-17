#include "Vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------------------- VECTORES -------------------

Vector* vector_create(VectorType type, size_t initial_capacity) {
    Vector *vec = malloc(sizeof(Vector));
    vec->data = malloc(initial_capacity * sizeof(void*));
    vec->size = 0;
    vec->capacity = initial_capacity;
    vec->type = type;
    return vec;
}

void vector_add_int(Vector *vec, int value) {
    if (vec->type != T_INT) {
        fprintf(stderr, "Error: intentando agregar int a un vector de strings\n");
        exit(1);
    }
    if (vec->size == vec->capacity) {
        vec->capacity *= 2;
        vec->data = realloc(vec->data, vec->capacity * sizeof(void*));
    }
    int *p = malloc(sizeof(int));
    *p = value;
    vec->data[vec->size++] = p;
}

void vector_add_string(Vector *vec, const char *str) {
    if (vec->type != T_STRING) {
        fprintf(stderr, "Error: intentando agregar string a un vector de ints\n");
        exit(1);
    }
    if (vec->size == vec->capacity) {
        vec->capacity *= 2;
        vec->data = realloc(vec->data, vec->capacity * sizeof(void*));
    }
    vec->data[vec->size++] = strdup(str);
}

int vector_get_int(Vector *vec, size_t index) {
    if (vec->type != T_INT || index >= vec->size) {
        fprintf(stderr, "Error: tipo incorrecto o índice fuera de rango\n");
        exit(1);
    }
    return *(int*)vec->data[index];
}

char* vector_get_string(Vector *vec, size_t index) {
    if (vec->type != T_STRING || index >= vec->size) {
        fprintf(stderr, "Error: tipo incorrecto o índice fuera de rango\n");
        exit(1);
    }
    return (char*)vec->data[index];
}

void vector_free(Vector *vec) {
    for (size_t i = 0; i < vec->size; i++) {
        free(vec->data[i]);
    }
    free(vec->data);
    free(vec);
}

// Busca un entero en el vector y devuelve el índice, o -1 si no se encuentra
int vector_find_int(Vector *vec, int value) {
    if (vec->type != T_INT) {
        fprintf(stderr, "Error: vector no es de tipo int\n");
        return -1;
    }
    for (size_t i = 0; i < vec->size; i++) {
        int *p = (int *)vec->data[i];
        if (*p == value) {
            return (int)i;  // encontrado
        }
    }
    return -1; // no encontrado
}

// Busca una cadena en el vector y devuelve el índice, o -1 si no se encuentra
int vector_find_string(Vector *vec, const char *str) {
    if (vec->type != T_STRING) {
        fprintf(stderr, "Error: vector no es de tipo string\n");
        return -1;
    }
    for (size_t i = 0; i < vec->size; i++) {
        char *s = (char *)vec->data[i];
        if (strcmp(s, str) == 0) {
            return (int)i;  // encontrado
        }
    }
    return -1; // no encontrado
}

// Reemplazar un entero en un índice específico
void vector_set_int(Vector *vec, size_t index, int value) {
    if (vec->type != T_INT || index >= vec->size) {
        fprintf(stderr, "Error: tipo incorrecto o índice fuera de rango\n");
        exit(1);
    }
    int *p = malloc(sizeof(int));
    *p = value;
    free(vec->data[index]);      // liberar el valor anterior
    vec->data[index] = p;        // asignar el nuevo valor
}

// Reemplazar una cadena en un índice específico
void vector_set_string(Vector *vec, size_t index, const char *str) {
    if (vec->type != T_STRING || index >= vec->size) {
        fprintf(stderr, "Error: tipo incorrecto o índice fuera de rango\n");
        exit(1);
    }
    free(vec->data[index]);      // liberar la cadena anterior
    vec->data[index] = strdup(str);  // duplicar la nueva cadena
}

// Retorna el número de elementos actuales en el vector
size_t vector_size(Vector *vec) {
    return vec->size;
}


// ------------------- TABLA DE SÍMBOLOS -------------------

SymbolTable* table_create(size_t initial_capacity) {
    SymbolTable *table = malloc(sizeof(SymbolTable));
    table->entries = malloc(initial_capacity * sizeof(SymbolEntry));
    table->size = 0;
    table->capacity = initial_capacity;
    return table;
}

void table_add(SymbolTable *table, const char *name, Vector *vec) {
    if (table->size == table->capacity) {
        table->capacity *= 2;
        table->entries = realloc(table->entries, table->capacity * sizeof(SymbolEntry));
    }
    table->entries[table->size].name = strdup(name);
    table->entries[table->size].vec = vec;
    table->size++;
}

Vector* table_get(SymbolTable *table, const char *name) {
    for (size_t i = 0; i < table->size; i++) {
        if (strcmp(table->entries[i].name, name) == 0)
            return table->entries[i].vec;
    }
    return NULL;
}

void table_free(SymbolTable *table) {
    for (size_t i = 0; i < table->size; i++) {
        free(table->entries[i].name);
        vector_free(table->entries[i].vec);
    }
    free(table->entries);
    free(table);
}
