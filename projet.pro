
QT += core gui widgets
CONFIG += console

HEADERS += include/Widget/Fenetre.h \
		include/Widget/DCodeEditor.h \
		include/Widget/JavaHighLighter.h \
		include/Menu/MenuFile.h \
		include/Menu/MenuNew.h \
		include/Menu/MenuEdit.h \
		include/Menu/MenuPref.h \
		include/Menu/MenuHelp.h \
		include/Hierarchy/ClassElement.h \
		include/Hierarchy/ClassSubElement.h \
		include/Hierarchy/DAttribut.h \
		include/Hierarchy/DMethod.h \
		include/Hierarchy/DClass.h \
		include/Hierarchy/NaiveAnalyzer.h 
				
SOURCES += src/Widget/Fenetre.cpp \
		src/Widget/DCodeEditor.cpp \
		src/Widget/JavaHighLighter.cpp \
		src/Menu/MenuFile.cpp \
		src/Menu/MenuNew.cpp \
		src/Menu/MenuEdit.cpp \
		src/Menu/MenuPref.cpp \
		src/Menu/MenuHelp.cpp \
		src/Hierarchy/DClass.cpp \
		src/Hierarchy/NaiveAnalyzer.cpp
		
test_conf {
	TARGET = my_app_test
	QT += testlib
	HEADERS += include/UnitTest/DClassTest.h			
	SOURCES += src/UnitTest/DClassTest.cpp
} else {
	SOURCES += src/main.cpp
}



