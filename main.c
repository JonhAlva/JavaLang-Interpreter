#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Functions/AST.h"
#include "Functions/Evaluate.h"
#include <gtk/gtk.h>

// Prototipo de parser
int yyparse(void);

//Leer archivo como argumento
extern FILE *yyin;

extern void yyrestart(FILE *input_file);

extern Nodo* raiz;

//Funcion de compilacion
int Analizar_Codigo(char* codigo) {
    //Escribir Exit para salir del bucle
        if (strncmp(codigo, "exit", 4) == 0) {
            return 1;
        }

        // Crear un archivo temporal en memoria con la entrada
        FILE *f = fmemopen(codigo, strlen(codigo), "r");
        yyrestart(f);
        yyin = f;

        if (yyparse() == 0) {
            printf(" ✅ Análisis sintáctico terminado con éxito \n");
            if (raiz != NULL ) {
                Evaluar(raiz);
            }
        } else {
            printf(" ❌ Se encontraron errores durante el análisis \n");
        }

        fclose(f);
        return 0;
}

// funcion de accion del boton {COMPILAR} de la ventana de gtk3
void Compile_clicked(GtkWidget *widget, gpointer textview) {
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview));
    GtkTextIter start, end;
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    gchar *texto = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

    int r = Analizar_Codigo(texto);

    if (r == 0) {
        g_print("Compilación exitosa!\n");
    } else {
        g_print("Error en el código!\n");
    }

    g_free(texto);
}

// COnfiguracion de la ventana de gtk3
static void on_activate(GtkApplication *app, gpointer user_data) {
    // Crear la ventana principal
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Java Lang Compiler - ClasterJack");
    gtk_window_set_default_size(GTK_WINDOW(window), 1500, 850);

    GtkWidget *fixed = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(window), fixed);

    // Importacion del css
    GtkCssProvider *cssProvider = gtk_css_provider_new();
    gtk_css_provider_load_from_path(cssProvider, "Styles/MainStyle.css", NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                            GTK_STYLE_PROVIDER(cssProvider),
                                            GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(cssProvider);

    // Creacion de los objetos que se veran en la ventana
    GtkWidget *label = gtk_label_new("Entrada de codigo JavaLang:");
    GtkWidget *label2 = gtk_label_new("Salida: ");
    GtkWidget *button = gtk_button_new_with_label("Compilar");
    GtkWidget *button2 = gtk_button_new_with_label("Abrir");
    GtkWidget *button3 = gtk_button_new_with_label("Guardar");
    GtkWidget *button4 = gtk_button_new_with_label("Reporte AST");
    GtkWidget *button5 = gtk_button_new_with_label("Reporte Symbols");
    GtkWidget *button6 = gtk_button_new_with_label("Reporte Errs");
    GtkWidget *textview = gtk_text_view_new();
    GtkWidget *textview2 = gtk_text_view_new();

    //Nombres de los objetos para el css y configuracion
    gtk_widget_set_name(label, "EntradaLabel");
    gtk_widget_set_name(label2, "EntradaLabel");
    gtk_widget_set_name(button, "CompileButton");
    gtk_widget_set_name(button2, "ArchivoButton");
    gtk_widget_set_name(button3, "ArchivoButton");
    gtk_widget_set_name(button4, "ReportesButton");
    gtk_widget_set_name(button5, "ReportesButton");
    gtk_widget_set_name(button6, "ReportesButton");

    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(textview), GTK_WRAP_NONE);
    gtk_text_view_set_monospace(GTK_TEXT_VIEW(textview), TRUE);
    gtk_widget_set_size_request(textview, 700, 650);
    GtkWidget *scrolled = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(scrolled, 700, 650);
    gtk_container_add(GTK_CONTAINER(scrolled), textview);

    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(textview2), GTK_WRAP_NONE);
    gtk_text_view_set_monospace(GTK_TEXT_VIEW(textview2), TRUE);
    gtk_widget_set_size_request(textview2, 700, 650);
    GtkWidget *scrolled2 = gtk_scrolled_window_new(NULL, NULL);
    gtk_widget_set_size_request(scrolled2, 700, 650);
    gtk_container_add(GTK_CONTAINER(scrolled2), textview2);

    // Colocacion de los objetos en la ventana
    gtk_fixed_put(GTK_FIXED(fixed), label, 45, 75);
    gtk_fixed_put(GTK_FIXED(fixed), label2, 760, 75);
    gtk_fixed_put(GTK_FIXED(fixed), button, 45, 790);
    gtk_fixed_put(GTK_FIXED(fixed), button2, 45, 30);
    gtk_fixed_put(GTK_FIXED(fixed), button3, 150, 30);
    gtk_fixed_put(GTK_FIXED(fixed), button4, 950, 30);
    gtk_fixed_put(GTK_FIXED(fixed), button5, 1120, 30);
    gtk_fixed_put(GTK_FIXED(fixed), button6, 1330, 30);
    gtk_fixed_put(GTK_FIXED(fixed), scrolled, 35, 120);
    gtk_fixed_put(GTK_FIXED(fixed), scrolled2, 750, 120);
    

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    char input[1024];
    
    GtkApplication *app = gtk_application_new("org.ejemplo.compilador", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;

    
/*
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
        printf("\n=================================\n\n"); ***********

        // Iniciar análisis
        if (yyparse() == 0) {
            printf("        ✅ Análisis sintáctico terminado con éxito \n");
            printf(" ⚒️ : \n");
            if (raiz != NULL ) {
                Evaluar(raiz);
            }
        } else {
            printf("        ❌ Se encontraron errores durante el análisis \n");
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
            if (raiz != NULL ) {
                Evaluar(raiz);
            }
        } else {
            printf(" ❌ Se encontraron errores durante el análisis \n");
        }

        fclose(f);
    }

    return 0;  */
}