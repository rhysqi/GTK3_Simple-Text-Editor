
#include "../include/SAP.hh"

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *box;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Simple Text Editor");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 500);

    // Grid Box
    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    // Showing Widgets
    menubar(window, box);
    entry(window, box);
    gtk_widget_show_all(window);
}

// Main section
int main(int argc, char *argv[]) {

    GtkApplication *app;
    int		    status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}
