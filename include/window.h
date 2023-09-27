
#include <gtk-3.0/gdk/gdk.h>
#include <gtk-3.0/gtk/gtk.h>

inline void Window(GtkWidget *window) {
    gtk_window_set_title(GTK_WINDOW(window), "Simple Text Editor");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 500);
}