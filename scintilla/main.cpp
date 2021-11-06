#include <gtk/gtk.h>

#include <Scintilla.h>
#include <SciLexer.h>
#include <ScintillaWidget.h>

#define SendMessage(m, w, l) scintilla_send_message(sci, m, w, l)

int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);

    GtkWidget *wnd = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *editor = scintilla_new();
    ScintillaObject *sci = SCINTILLA(editor);

    gtk_container_add(GTK_CONTAINER(wnd), editor);

    g_signal_connect(wnd, "destroy",
    G_CALLBACK(gtk_main_quit), NULL);

    scintilla_set_id(sci, 0);
    gtk_window_set_default_size(GTK_WINDOW(wnd), 500, 300);

    SendMessage(SCI_STYLECLEARALL, 0, 0);
    SendMessage(SCI_SETLEXER, SCLEX_CPP, 0);
    SendMessage(SCI_SETKEYWORDS, 0, (sptr_t)"int char");
    SendMessage(SCI_STYLESETFORE, SCE_C_COMMENT, 0x008000);
    SendMessage(SCI_STYLESETFORE, SCE_C_COMMENTLINE, 0x008000);
    SendMessage(SCI_STYLESETFORE, SCE_C_NUMBER, 0x808000);
    SendMessage(SCI_STYLESETFORE, SCE_C_WORD, 0x800000);
    SendMessage(SCI_STYLESETFORE, SCE_C_STRING, 0x800080);
    SendMessage(SCI_STYLESETBOLD, SCE_C_OPERATOR, 1);
    SendMessage(SCI_INSERTTEXT, 0, (sptr_t)
    "int main(int argc, char **argv) {\n"
    "    // Start up the gnome\n"
    "    gnome_init(\"stest\", \"1.0\", argc, argv);\n}"
    );

    gtk_widget_show_all(wnd);
    gtk_widget_grab_focus(GTK_WIDGET(editor));
    gtk_main();

    return 0;
}


