#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PrintBuffer.h"

PrintBuffer print_buffer = {NULL, 0};

void init_print_buffer(void) {
    print_buffer.mensajes = malloc(sizeof(char*) * MAX_OUTPUTS);
    print_buffer.count = 0;
}

void add_to_print_buffer(const char* message) {
    if (print_buffer.count < MAX_OUTPUTS) {
        print_buffer.mensajes[print_buffer.count] = strdup(message);
        print_buffer.count++;
    }
}

void clear_print_buffer(void) {
    for (int i = 0; i < print_buffer.count; i++) {
        free(print_buffer.mensajes[i]);
    }
    print_buffer.count = 0;
}

char** get_print_buffer(int* count) {
    *count = print_buffer.count;
    return print_buffer.mensajes;
}