
QT += core gui widgets xml
CONFIG += console
RESOURCES = resources.qrc

HEADERS += include/View/Fenetre.h \
    include/Controller/Dialog/ConsoleController.h \
    include/Controller/Dialog/FolderController.h \
    include/Controller/Dialog/PackageController.h \
    include/Controller/Menu/MenuPrefController.h \
    include/Controller/Widget/CodeEditorController.h \
    include/Controller/Widget/ExplorerDelegate.h \
    include/Model/ConsoleModel.h \
    include/Model/FilteredModel.h \
    include/Model/Javora.h \
    include/Model/MakefileFactory.h \
    include/View/Dialog/ConsoleDialog.h \
    include/View/Dialog/FolderDialog.h \
    include/View/Menu/MenuContextExplorer.h \
    include/View/Widget/Console.h \
    include/View/Widget/ConsoleTabWidget.h \
    include/View/Widget/DCodeEditor.h \
    include/View/Widget/JavaHighLighter.h \
    include/View/Menu/MenuFile.h \
    include/View/Menu/MenuNew.h \
    include/View/Menu/MenuEdit.h \
    include/View/Menu/MenuPref.h \
    include/View/Menu/MenuHelp.h \
    include/View/Dialog/ProjectDialog.h \
    include/Model/ClassElement.h \
    include/Model/ClassSubElement.h \
    include/Model/DAttribut.h \
    include/Model/DMethod.h \
    include/Model/DClass.h \
    include/Model/DJavaFile.h \
    include/Model/Model.h \
    include/Model/TreeItem.h \
    include/Model/DIcons.h \
    include/Model/DProject.h \
    include/Model/DSourceFolder.h \
    include/Model/DFolder.h \
    include/Model/DPackage.h \
    include/Controller/Controller.h \
    include/View/Dialog/PackageDialog.h \
    include/View/Dialog/ClassDialog.h \
    include/Controller/Dialog/ProjectController.h \
    include/Controller/Dialog/ClassController.h \
    include/Controller/Widget/SnippetController.h \
    include/Controller/Menu/MenuEditController.h \
    include/View/Widget/DSnippetItem.h \
    include/View/Widget/Snippet.h \
    include/View/Widget/TitleBar.h

SOURCES += src/View/Fenetre.cpp \
    src/Controller/Dialog/FolderController.cpp \
    src/Controller/Dialog/PackageController.cpp \
    src/Controller/Menu/MenuPrefController.cpp \
    src/Controller/Widget/CodeEditorController.cpp \
    src/Controller/Widget/ExplorerDelegate.cpp \
    src/Controller/Widget/SnippetController.cpp \
    src/Model/ClassSubElement.cpp \
    src/Model/ConsoleModel.cpp \
    src/Model/DAttribut.cpp \
    src/Model/DMethod.cpp \
    src/Model/FilteredModel.cpp \
    src/Model/MakefileFactory.cpp \
    src/View/Dialog/ConsoleController.cpp \
    src/View/Dialog/ConsoleDialog.cpp \
    src/View/Dialog/FolderDialog.cpp \
    src/View/Menu/MenuContextExplorer.cpp \
    src/View/Widget/Console.cpp \
    src/View/Widget/ConsoleTabWidget.cpp \
    src/View/Widget/DCodeEditor.cpp \
    src/View/Widget/JavaHighLighter.cpp \
    src/View/Menu/MenuFile.cpp \
    src/View/Menu/MenuNew.cpp \
    src/View/Menu/MenuEdit.cpp \
    src/View/Menu/MenuPref.cpp \
    src/View/Menu/MenuHelp.cpp \
    src/View/Dialog/ProjectDialog.cpp \
    src/Model/DClass.cpp \
    src/Model/DJavaFile.cpp \
    src/Model/Model.cpp \
    src/Model/TreeItem.cpp \
    src/Model/DIcons.cpp \
    src/Model/DProject.cpp \
    src/Model/DSourceFolder.cpp \
    src/Model/DFolder.cpp \
    src/Model/DPackage.cpp \
    src/Compiler/NaiveAnalyzer.cpp \
    src/Compiler/JavaFileReader.cpp \
    src/Controller/Controller.cpp \
    src/View/Dialog/PackageDialog.cpp \
    src/View/Dialog/ClassDialog.cpp \
    src/Controller/Dialog/ProjectController.cpp \
    src/Controller/Dialog/ClassController.cpp \
    src/Controller/Menu/MenuEditController.cpp \
    src/View/Widget/DSnippetItem.cpp \
    src/View/Widget/Snippet.cpp \
    src/View/Widget/TitleBar.cpp

test_conf {
	TARGET = my_app_test
	QT += testlib
	HEADERS += include/UnitTest/DClassTest.h			
	SOURCES += src/UnitTest/DClassTest.cpp
} else {
	SOURCES += src/main.cpp
}



