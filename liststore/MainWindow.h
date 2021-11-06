#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CWindow.h"

enum
{
    LIST_ITEM = 0,
    N_COLUMNS
};

class MainWindow : public CWindow
{
public:

    MainWindow();
    virtual ~MainWindow();

private:

    void _createWindow();
    GtkWidget* _createListView();

    SIGNAL_MAP1(MainWindow*, void, _onDestroy, GtkWidget*)
    SIGNAL_MAP1(MainWindow*, void, _onChanged, GtkWidget*)

};

#endif // MAINWINDOW_H


