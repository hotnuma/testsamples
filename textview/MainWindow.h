#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CWindow.h"

class MainWindow : public CWindow
{
public:

    MainWindow();
    virtual ~MainWindow();

private:

    SMAP1(MainWindow*, void, _actionOpen, GtkWidget*)
    SMAP1(MainWindow*, void, _actionQuit, GtkWidget*)
    SMAP1(MainWindow*, void, _onDestroy, GtkWidget*)

    void _createWindow();
    void _createMenu();
    void _createToolbar();
    void _createTextViex();

};

#endif // MAINWINDOW_H


