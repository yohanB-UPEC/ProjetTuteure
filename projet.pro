
QT += core gui widgets
CONFIG += console

HEADERS += include/Widget/Fenetre.h
HEADERS += include/Widget/DCodeEditor.h
HEADERS += include/Widget/JavaHighLighter.h
HEADERS += include/Menu/MenuFile.h
HEADERS += include/Menu/MenuNew.h
HEADERS += include/Menu/MenuEdit.h
HEADERS += include/Menu/MenuPref.h
HEADERS += include/Menu/MenuHelp.h


SOURCES += src/main.cpp
SOURCES += src/Widget/Fenetre.cpp
SOURCES += src/Widget/DCodeEditor.cpp
SOURCES += src/Widget/JavaHighLighter.cpp
SOURCES += src/Menu/MenuFile.cpp
SOURCES += src/Menu/MenuNew.cpp
SOURCES += src/Menu/MenuEdit.cpp
SOURCES += src/Menu/MenuPref.cpp
SOURCES += src/Menu/MenuHelp.cpp