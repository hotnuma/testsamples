TEMPLATE = app
TARGET = testgtk
CONFIG = c++11 link_pkgconfig
PKGCONFIG = gtk+-3.0
DEFINES = GTK
INCLUDEPATH = /usr/local/include/scintilla

HEADERS += \
#    MainWindow.h \

SOURCES = \
    0Temp.cpp \
#    MainWindow.cpp \
    main.cpp \

DISTFILES = \
    License.txt \
    Readme.txt \
    install.sh \
    meson.build \

