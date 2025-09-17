#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Functions/AST.h"
#include "Functions/Evaluate.h"
#include "Functions/PrintBuffer.h"
#include "Functions/Tabla_Simbolos.h"
#include "Functions/Vector.h"
#include <gtk/gtk.h>
#include <locale.h>

// Prototipo de parser
int yyparse(void);

//Leer archivo como argumento
extern FILE *yyin;

extern void yyrestart(FILE *input_file);

extern Nodo* raiz;

SymbolTable *symtab;

typedef struct {
    GtkWidget *input;
    GtkWidget *output;
} CompileData;

//Funcion de compilacion
int Analizar_Codigo(char* codigo, GtkWidget *textview2) {
    //Escribir Exit para salir del bucle

        Clear_All_Variables();
        Clear_All_Errors();
        Clear_All_Funciones();
        if (strncmp(codigo, "exit", 4) == 0) {
            return 1;
        }

        setlocale(LC_NUMERIC, "C"); // Solo punto como decimal

        init_print_buffer(); // Inicializar el buffer de impresión

        // Crear un archivo temporal en memoria con la entrada
        FILE *f = fmemopen(codigo, strlen(codigo), "rb");

        yyrestart(f);
        yyin = f;
        printf(" 🚀 Iniciando análisis sintáctico... \n");
        if (yyparse() == 0) {
            printf(" ✅ Análisis sintáctico terminado con éxito \n");
            if (raiz != NULL ) {
                Evaluar(raiz);

                int count;
                char** mensajes = get_print_buffer(&count);

                GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview2));
                gtk_text_buffer_set_text(buffer, "", 0); // Limpiar el buffer

                for (int i = 0; i < count; i++) {
                    gtk_text_buffer_insert_at_cursor(buffer, mensajes[i], -1);
                    free(mensajes[i]);
                }


                free(mensajes);
            }
        } else {
            printf(" ❌ Se encontraron errores durante el análisis \n");
            return 1;
        }

        fclose(f);
        return 0;
}

//limpiador
static void destroy_compile_data(gpointer data, GClosure *closure) {
    g_free(data);
}

// Abrir archivo
static void Open_File_clicked(GtkWidget *widget, gpointer user_data) {
    CompileData *data = (CompileData*)user_data;
    GtkWidget *dialog;
    GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
    gint res;

    dialog = gtk_file_chooser_dialog_new("Open File",
                                        GTK_WINDOW(gtk_widget_get_toplevel(widget)),
                                        action,
                                        "_Cancel",
                                        GTK_RESPONSE_CANCEL,
                                        "_Open",
                                        GTK_RESPONSE_ACCEPT,
                                        NULL);

    res = gtk_dialog_run(GTK_DIALOG(dialog));
    if (res == GTK_RESPONSE_ACCEPT) {
        char *filename;
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        filename = gtk_file_chooser_get_filename(chooser);
        
        // Read file contents
        FILE *file = fopen(filename, "r");
        if (file) {
            // Get file size
            fseek(file, 0, SEEK_END);
            long fsize = ftell(file);
            fseek(file, 0, SEEK_SET);

            // Read file content
            char *content = malloc(fsize + 1);
            fread(content, fsize, 1, file);
            fclose(file);
            content[fsize] = 0;  // Null terminate

            // Set content to text view
            GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(data->input));
            gtk_text_buffer_set_text(buffer, content, -1);

            free(content);
        } else {
            GtkWidget *error_dialog = gtk_message_dialog_new(GTK_WINDOW(gtk_widget_get_toplevel(widget)),
                                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                                        GTK_MESSAGE_ERROR,
                                                        GTK_BUTTONS_CLOSE,
                                                        "Error al abrir el archivo: %s",
                                                        filename);
            gtk_dialog_run(GTK_DIALOG(error_dialog));
            gtk_widget_destroy(error_dialog);
        }
        g_free(filename);
    }

    gtk_widget_destroy(dialog);
}

// * Funcion para generar el reporte de simbolos
void Generate_Symbols_Report(){
    if (num_vars == 0) {
        printf("✅ No se encontraron variables declaradas\n");
        return;
    } else {
        Print_All_Variables();
    }
}

// * Funcion para generar el reporte de errores
void Generate_Errors_Report(){

    if (num_errores == 0) {
        printf("✅ No se encontraron errores\n");
        return;
    } else {
        Print_All_Errors();
    }
    
}

void Generate_AST_Report(){
    if (raiz == NULL) {
        printf("❌ No se ha generado el AST, no hay código para analizar\n");
        return;
    } else {
        Print_AST(raiz, "ast_report");
    }
}

// funcion de accion del boton {COMPILAR} de la ventana de gtk3
void Compile_clicked(GtkWidget *widget, gpointer user_data) {
    CompileData *data = (CompileData*)user_data;
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(data->input));
    GtkTextIter start, end;
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    gchar *texto = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

    // entrada que se esta mandando a Analizar_Codigo
    // ! printf("Input code to analyze:\n%s\n", texto);

    int r = Analizar_Codigo(texto, data->output);

    if (r == 0) {
        g_print(" 🌐 Ejecución de código exitosa!\n");
    } else if (r == 5) {
        g_print(" 🟥 Error en la ejecucion del código!\n");
    }

    g_free(texto);
}

// COnfiguracion de la ventana de gtk3
static void on_activate(GtkApplication *app, gpointer user_data) {
    // Crear la ventana principal
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Simply Java Lang Compiler");
    gtk_window_set_default_size(GTK_WINDOW(window), 1485, 850);

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
    GtkWidget *label3 = gtk_label_new("Copyright © 2025 ClasterJack");
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
    gtk_widget_set_name(label3, "CopyLabel");
    gtk_widget_set_name(button, "CompileButton");
    gtk_widget_set_name(button2, "ArchivoButton");
    gtk_widget_set_name(button3, "ArchivoButton");
    gtk_widget_set_name(button4, "ReportesButton");
    gtk_widget_set_name(button5, "ReportesButton");
    gtk_widget_set_name(button6, "ReportesButton");
    gtk_widget_set_name(window, "MainWindow");
    gtk_widget_set_name(textview, "Entrada");
    gtk_widget_set_name(textview2, "Salida");

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

    //buffer para colocar texto en la salida
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(textview2));

    // Colocacion de los objetos en la ventana
    //                                      x   y
    gtk_fixed_put(GTK_FIXED(fixed), label, 45, 80);
    gtk_fixed_put(GTK_FIXED(fixed), label2, 760, 80);
    gtk_fixed_put(GTK_FIXED(fixed), label3, 1250, 800);
    gtk_fixed_put(GTK_FIXED(fixed), button, 180, 790);  // COmpile button
    gtk_fixed_put(GTK_FIXED(fixed), button2, 45, 25);   // Abrir archivo
    gtk_fixed_put(GTK_FIXED(fixed), button3, 230, 25); // Guardar archivo
    gtk_fixed_put(GTK_FIXED(fixed), button4, 880, 30); // Reporte AST
    gtk_fixed_put(GTK_FIXED(fixed), button5, 1060, 30); // Reporte Symbols
    gtk_fixed_put(GTK_FIXED(fixed), button6, 1270, 30); // Reporte Errs
    gtk_fixed_put(GTK_FIXED(fixed), scrolled, 35, 120);
    gtk_fixed_put(GTK_FIXED(fixed), scrolled2, 750, 120);
    
    //Acciones de los botones
    // Crear la estructura con los datos
    CompileData *data = g_new(CompileData, 1);
    data->input = textview;
    data->output = textview2;

    // Conectar la señal una sola vez
    g_signal_connect_data(button, "clicked", 
                        G_CALLBACK(Compile_clicked), 
                        data, 
                        destroy_compile_data, 
                        G_CONNECT_AFTER);

    g_signal_connect_data(button2, "clicked",
                G_CALLBACK(Open_File_clicked),
                data,
                NULL,
                G_CONNECT_AFTER);

    g_signal_connect_data(button5, "clicked",
                G_CALLBACK(Generate_Symbols_Report),
                data,
                NULL,
                G_CONNECT_AFTER);

    g_signal_connect_data(button6, "clicked",
                G_CALLBACK(Generate_Errors_Report),
                data,
                NULL,
                G_CONNECT_AFTER);

    g_signal_connect_data(button4, "clicked",
                G_CALLBACK(Generate_AST_Report),
                data,
                NULL,
                G_CONNECT_AFTER);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {

    symtab = table_create(2);
    setlocale(LC_NUMERIC, "C"); // Solo punto como decimal
    gtk_init(&argc, &argv);
    
    GtkApplication *app = gtk_application_new("org.ejemplo.compilador", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
    

    /*
    init_print_buffer(); // Inicializar el buffer de impresión

    char input[1024];
    printf("    $ Ingresar una entrada \n");
    if (argc > 1 ) {

        char *filename = argv[1];
        yyin = fopen(filename, "r");
        if (!yyin) {
            perror("El archivo no se pudo leer!");
            return 1;
        }

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

    return 0; 
    */
}