#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CWindow.h"

class MainWindow : public CWindow
{
public:

    MainWindow();
    virtual ~MainWindow();

private:

    SIGNAL_MAP1(MainWindow*, void, _actionOpen, GtkWidget*)
    SIGNAL_MAP1(MainWindow*, void, _actionQuit, GtkWidget*)

    SIGNAL_MAP1(MainWindow*, void, _onDestroy, GtkWidget*)

    void _createWindow();
    GtkWidget* _createMenu();
    GtkWidget* _createToolbar();
    GtkWidget* _createTextViex();



};

#endif // MAINWINDOW_H


