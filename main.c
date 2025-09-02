#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipo de parser
int yyparse(void);

//Leer archivo como argumento
extern FILE *yyin;

extern void yyrestart(FILE *input_file);

int main(int argc, char **argv) {
    char input[1024];
    printf("    $ Ingresar una entrada \n");
    if (argc > 1 ) {

        char *filename = argv[1];
        yyin = fopen(filename, "r");
        if (!yyin) {
            perror("El archivo no se pudo leer!");
            return 1;
        }

        // Mostrar contenido del archivo
        /*printf("\n=== Contenido del archivo '%s' ===\n", filename);
        int c;
        FILE *temp = fopen(filename, "r");
        while ((c = fgetc(temp)) != EOF) {
            putchar(c);
        }
        fclose(temp);
        printf("\n=================================\n\n"); */

        // Iniciar análisis
        if (yyparse() == 0) {
            printf(" ✅ Análisis sintáctico terminado con éxito \n");
        } else {
            printf(" ❌ Se encontraron errores durante el análisis \n");
        }

        fclose(yyin);
        return 0;
    }
    while(1) {
        printf("        \n>> ");
        if (!fgets(input, sizeof(input), stdin)) {
            break; // EOF
        }

        //Escribir Exit para salir del bucle
        if (strncmp(input, "exit", 4) == 0)
            break;

        // Crear un archivo temporal en memoria con la entrada
        FILE *f = fmemopen(input, strlen(input), "r");
        yyrestart(f);
        yyin = f;

        if (yyparse() == 0) {
            printf(" ✅ Análisis sintáctico terminado con éxito \n");
        } else {
            printf(" ❌ Se encontraron errores durante el análisis \n");
        }

        fclose(f);
    }

    return 0;
}