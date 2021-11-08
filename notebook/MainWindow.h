#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CWindow.h"

class MainWindow : public CWindow
{
public:

    MainWindow();
    virtual ~MainWindow();

private:

    SMAP1(MainWindow*, void, _onClicked, GtkWidget*)
    SMAP1(MainWindow*, void, _onDestroy, GtkWidget*)

    void _createWindow();

    GtkWidget *_notebook = nullptr;
};

#endif // MAINWINDOW_H


