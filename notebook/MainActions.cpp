#include "MainWindow.h"

#include <print.h>

void MainWindow::_onClicked(GtkWidget*)
{
    print("clicked");

    gtk_notebook_remove_page(
        GTK_NOTEBOOK(_notebook),
        gtk_notebook_get_current_page(GTK_NOTEBOOK(_notebook)));

}


