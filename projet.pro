
QT += core gui widgets
CONFIG += console

HEADERS += include/View/Fenetre.h \
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
		include/Model/Model.h \
		include/Model/TreeItem.h \
		include/Compiler/NaiveAnalyzer.h \
		include/Compiler/JavaFileReader.h \
		include/Controller/Controller.h 
				
SOURCES += src/View/Fenetre.cpp \
		src/View/Widget/DCodeEditor.cpp \
		src/View/Widget/JavaHighLighter.cpp \
		src/View/Menu/MenuFile.cpp \
		src/View/Menu/MenuNew.cpp \
		src/View/Menu/MenuEdit.cpp \
		src/View/Menu/MenuPref.cpp \
		src/View/Menu/MenuHelp.cpp \
		src/View/Dialog/ProjectDialog.cpp \
		src/Model/DClass.cpp \
		src/Model/Model.cpp \
		src/Model/TreeItem.cpp \
		src/Compiler/NaiveAnalyzer.cpp \
		src/Compiler/JavaFileReader.cpp \
		src/Controller/Controller.cpp
		
test_conf {
	TARGET = my_app_test
	QT += testlib
	HEADERS += include/UnitTest/DClassTest.h			
	SOURCES += src/UnitTest/DClassTest.cpp
} else {
	SOURCES += src/main.cpp
}



