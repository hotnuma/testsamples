#include "MainWindow.h"

#include <print.h>

void MainWindow::_actionOpen(GtkWidget*)
{
    print("clicked");

    GtkWidget *dialog;

    dialog = gtk_file_chooser_dialog_new(
        "Open File",
        GTK_WINDOW(_wnd),
        GTK_FILE_CHOOSER_ACTION_OPEN,
        "gtk-cancel",
        GTK_RESPONSE_CANCEL,
        "gtk-open",
        GTK_RESPONSE_ACCEPT,
        nullptr);

    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT)
    {
        char *filename;

        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));

        print(filename);

        g_free(filename);
    }

    gtk_widget_destroy(dialog);
}

void MainWindow::_actionQuit(GtkWidget*)
{
    gtk_window_close(GTK_WINDOW(_wnd));
}


