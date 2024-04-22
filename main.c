#include <gtk/gtk.h>
#include <stdio.h>

GtkWidget *buttons[3][3];

// Function to handle button clicks
void button_clicked(GtkWidget *widget, gpointer data) {
    // Get the row and column of the clicked button
    int row = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(widget), "row"));
    int col = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(widget), "col"));

    // Add your logic to handle the button click (e.g., update the game board)
}

// Function to create the Tic Tac Toe GUI
void create_gui(GtkWidget *grid) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            buttons[i][j] = gtk_button_new();
            gtk_grid_attach(GTK_GRID(grid), buttons[i][j], i, j, 1, 1);

            // Set the row and column data for each button
            g_object_set_data(G_OBJECT(buttons[i][j]), "row", GINT_TO_POINTER(i));
            g_object_set_data(G_OBJECT(buttons[i][j]), "col", GINT_TO_POINTER(j));

            // Connect the button click signal to the button_clicked function
            g_signal_connect(buttons[i][j], "clicked", G_CALLBACK(button_clicked), NULL);
        }
    }
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *grid;

    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create the main window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Tic Tac Toe");
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Create a grid layout for the buttons
    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Create the Tic Tac Toe GUI
    create_gui(grid);

    // Show all widgets
    gtk_widget_show_all(window);

    // Start the GTK main loop
    gtk_main();

    return 0;
}
