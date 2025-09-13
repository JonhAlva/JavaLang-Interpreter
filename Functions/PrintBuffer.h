#ifndef PRINT_BUFFER_H
#define PRINT_BUFFER_H

#define MAX_PRINT_LENGTH 1024
#define MAX_OUTPUTS 1000

typedef struct {
    char** mensajes;
    int count;
}PrintBuffer;

extern PrintBuffer print_buffer;

void init_print_buffer(void);
void add_to_print_buffer(const char* message);
void clear_print_buffer(void);
char** get_print_buffer(int* count);

#endif
