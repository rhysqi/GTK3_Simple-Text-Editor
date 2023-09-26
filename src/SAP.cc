
#include "../include/SAP.hh"

// static void button_clicked(GtkWidget *widget, gpointer data) {
//     g_print("Tombol Ditekan!\n");
// }

// static void activate(GtkApplication *app, gpointer user_data) {
//     GtkWidget *window;
//     GtkWidget *button;
//     GtkWidget *box;

//     window = gtk_application_window_new(GTK_APPLICATION(app));
//     gtk_window_set_title(GTK_WINDOW(window), "Simple Calculator");
//     gtk_window_set_default_size(GTK_WINDOW(window), 400, 500);
//     gtk_window_set_resizable(GTK_WINDOW(window), FALSE);

//     // Membuat kotak (box) untuk tombol
//     box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 10);
//     gtk_container_add(GTK_CONTAINER(window), box);

//     // Membuat tombol
//     button = gtk_button_new_with_label("Tombol GTK");
//     g_signal_connect(button, "clicked", G_CALLBACK(button_clicked), NULL);

//     // Menambahkan tombol ke dalam kotak
//     gtk_box_pack_start(GTK_BOX(box), button, TRUE, TRUE, 0);

//     // Menampilkan semua elemen
//     gtk_widget_show_all(window);
// }

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Grid Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    // Membuat grid
    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Membuat beberapa tombol dan menempatkannya dalam grid
    GtkWidget *button1 = gtk_button_new_with_label("Button 1");
    GtkWidget *button2 = gtk_button_new_with_label("Button 2");
    GtkWidget *button3 = gtk_button_new_with_label("Button 3");

    // Menempatkan tombol-tombol dalam grid pada baris dan kolom tertentu
    gtk_grid_attach(GTK_GRID(grid), button1, 0, 0, 1, 1);  // Baris 0, Kolom 0
    gtk_grid_attach(GTK_GRID(grid), button2, 1, 0, 1, 1);  // Baris 0, Kolom 1
    gtk_grid_attach(GTK_GRID(grid), button3, 0, 1, 2, 1);  // Baris 1, Kolom 0-1 (menggunakan 2 kolom)

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}