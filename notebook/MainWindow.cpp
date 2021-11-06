#include "MainWindow.h"
#include <CString.h>

void notebookAppend(CWindow *wnd, GtkWidget *notebook,
                    const char *title, GtkWidget *page)
{
    // label.
    GtkWidget *label=gtk_label_new(title);

    // button.
    GtkWidget *cross=gtk_label_new(nullptr);
    gtk_label_set_markup(GTK_LABEL(cross), "<span foreground='black'>x</span>");
    GtkWidget *button=gtk_button_new();
    gtk_container_add(GTK_CONTAINER(button), cross);

    GtkWidget *box=gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);
    gtk_box_pack_start(GTK_BOX(box), label, true, true, 0);
    gtk_box_pack_start(GTK_BOX(box), button, false, false, 0);
    gtk_widget_show_all(box);

    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page, box);

    g_signal_connect(button, "clicked", G_CALLBACK(MainWindow::onClickedCB), wnd);
}

MainWindow::MainWindow()
{
    _createWindow();
}

MainWindow::~MainWindow()
{
}

void MainWindow::_createWindow()
{
    _wnd = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(_wnd), "App Title");
    gtk_window_set_default_size(GTK_WINDOW(_wnd), 400, 300);
    gtk_window_set_position(GTK_WINDOW(_wnd), GTK_WIN_POS_CENTER);
    setWindowObject(_wnd, this);
    g_signal_connect(_wnd, "destroy", G_CALLBACK(_onDestroyCB), this);

    GtkWidget *notebook=gtk_notebook_new();
    gtk_container_add(GTK_CONTAINER(_wnd), notebook);

    GtkWidget *page=gtk_label_new("page1");
    notebookAppend(this, notebook, "title1", page);

}

void MainWindow::_onDestroy(GtkWidget*)
{
    bool quit = true;

    GList *list = gtk_window_list_toplevels();

    for (GList *i = list; i; i = i->next)
    {
        CWindow *window = (CWindow*) getWindowObject(GTK_WIDGET(i->data));

        if (window && window != this)
        {
            quit = false;
            break;
        }
    }

    setWindowObject(_wnd, nullptr);
    delete this;

    if (quit)
        gtk_main_quit();
}


