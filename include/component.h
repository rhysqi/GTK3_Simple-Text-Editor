
#include <gtk-3.0/gdk/gdk.h>
#include <gtk-3.0/gtk/gtk.h>
#include <stdio.h>

// Declare global variable
GtkTextBuffer *text_buffer = NULL;
GtkWidget *window = NULL;

// Fungsi untuk membaca isi file dan menampilkannya di buffer teks
void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file) {
        char buffer[1024];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            gtk_text_buffer_insert_at_cursor(text_buffer, buffer, -1);
        }
        fclose(file);
    } else {
        g_print("Failed to open file for reading: %s\n", filename);
    }
}

// Fungsi untuk menulis isi buffer teks ke dalam file
void write_file(const char *filename) {
    GtkTextIter start;
    GtkTextIter end;
    char *text;
    
    gtk_text_buffer_get_start_iter(text_buffer, &start);
    gtk_text_buffer_get_end_iter(text_buffer, &end);
    
    text = gtk_text_buffer_get_text(text_buffer, &start, &end, FALSE);
    
    FILE *file = fopen(filename, "w");
    if (file) {
        fputs(text, file);
        fclose(file);
    } else {
        g_print("Failed to open file for writing: %s\n", filename);
    }
    
    g_free(text);
}

// Menu bar Function
inline void on_new_clicked(GtkWidget *widget) {
    // new files function
    if (text_buffer != NULL) {
        gtk_text_buffer_set_text(text_buffer, "", -1);
    }
}

inline void on_open_clicked(GtkWidget *widget) {
    // Open file function
    GtkWidget *file_chooser;
    file_chooser = gtk_file_chooser_dialog_new("Open File",
                                               GTK_WINDOW(window),
                                               GTK_FILE_CHOOSER_ACTION_OPEN,
                                               "Cancel", GTK_RESPONSE_CANCEL,
                                               "Open", GTK_RESPONSE_ACCEPT,
                                               NULL);

    if (gtk_dialog_run(GTK_DIALOG(file_chooser)) == GTK_RESPONSE_ACCEPT) {
        char *filename;
        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_chooser));
        read_file(filename);
        g_free(filename);
    }

    gtk_widget_destroy(file_chooser);
}

inline void on_save_clicked(GtkWidget *widget) {
    // save file function
    GtkWidget *file_chooser;
    file_chooser = gtk_file_chooser_dialog_new("Save File",
                                               GTK_WINDOW(window),
                                               GTK_FILE_CHOOSER_ACTION_SAVE,
                                               "Cancel", GTK_RESPONSE_CANCEL,
                                               "Save", GTK_RESPONSE_ACCEPT,
                                               NULL);

    if (gtk_dialog_run(GTK_DIALOG(file_chooser)) == GTK_RESPONSE_ACCEPT) {
        char *filename;
        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(file_chooser));
        write_file(filename);
        g_free(filename);
    }

    gtk_widget_destroy(file_chooser);

}
inline void menubar(GtkWidget *window, GtkWidget *box) {

    GtkWidget *menu;
    menu = gtk_menu_bar_new();

    GtkWidget *menu_item_new;
    menu_item_new = gtk_menu_item_new_with_label("New");

    GtkWidget *menu_item_open;
    menu_item_open = gtk_menu_item_new_with_label("Open");

    GtkWidget *menu_item_save;
    menu_item_save = gtk_menu_item_new_with_label("Save");

    // Menu bar show
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item_new);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item_open);
    gtk_menu_shell_append(GTK_MENU_SHELL(menu), menu_item_save);
    gtk_container_add(GTK_CONTAINER(window), box);
    gtk_box_pack_start(GTK_BOX(box), menu, FALSE, FALSE, 0);

    // signal connect
    g_signal_connect(menu_item_new, "activate", G_CALLBACK(on_new_clicked), NULL);
    g_signal_connect(menu_item_open, "activate", G_CALLBACK(on_open_clicked), NULL);
    g_signal_connect(menu_item_save, "activate", G_CALLBACK(on_save_clicked), NULL);
}

// Entry Function
inline void entry_activated(GtkEntry *entry) {
    const gchar *text = gtk_entry_get_text(entry);
    g_print("Teks Masuk: %s\n", text);
}

inline void entry(GtkWidget *window, GtkWidget *box) {
    // Membuat GtkScrolledWindow
    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_box_pack_start(GTK_BOX(box), scrolled_window, TRUE, TRUE, 0);

    // Membuat GtkTextView
    GtkWidget *entry = gtk_text_view_new();
    g_signal_connect(entry, "activated", G_CALLBACK(entry_activated), entry);

    // Mengatur scroll untuk GtkScrolledWindow
    gtk_container_add(GTK_CONTAINER(scrolled_window), entry);

    // Menginisialisasi buffer teks
    text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(entry));
}