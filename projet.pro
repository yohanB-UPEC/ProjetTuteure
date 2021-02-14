
QT += core gui widgets xml
CONFIG += console
RESOURCES = resources.qrc

HEADERS += include/View/Fenetre.h \
    include/Controller/Dialog/EnumController.h \
    include/Controller/Dialog/FolderController.h \
    include/Controller/Dialog/InterfaceController.h \
    include/Controller/Dialog/PackageController.h \
    include/Controller/Dialog/SrcFolderController.h \
	include/View/Dialog/EnumDialog.h \
	include/View/Dialog/FolderDialog.h \
	include/View/Dialog/InterfaceDialog.h \
	include/View/Dialog/SrcFolderDialog.h \
	include/View/Widget/Console.h \
	include/View/Widget/DCodeEditor.h \
	include/View/Widget/JavaHighLighter.h \
	include/View/Widget/DFilteredTreeView.h \
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
	include/Compiler/NaiveAnalyzer.h \
	include/Compiler/JavaFileReader.h \
	include/Controller/Controller.h \
	include/View/Dialog/PackageDialog.h \
	include/View/Dialog/ClassDialog.h \
	include/Controller/Dialog/ProjectController.h \
	include/Controller/Dialog/ClassController.h
				
SOURCES += src/View/Fenetre.cpp \
    src/Controller/Dialog/EnumController.cpp \
    src/Controller/Dialog/FolderController.cpp \
    src/Controller/Dialog/InterfaceController.cpp \
    src/Controller/Dialog/PackageController.cpp \
    src/Controller/Dialog/SrcFolderController.cpp \
	src/View/Dialog/EnumDialog.cpp \
	src/View/Dialog/FolderDialog.cpp \
	src/View/Dialog/InterfaceDialog.cpp \
	src/View/Dialog/SrcFolderDialog.cpp \
	src/View/Widget/Console.cpp \
	src/View/Widget/DCodeEditor.cpp \
	src/View/Widget/JavaHighLighter.cpp \
	src/View/Widget/DFilteredTreeView.cpp \
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
	src/Controller/Dialog/ClassController.cpp
		
test_conf {
	TARGET = my_app_test
	QT += testlib
	HEADERS += include/UnitTest/DClassTest.h			
	SOURCES += src/UnitTest/DClassTest.cpp
} else {
	SOURCES += src/main.cpp
}



