#ifndef DCLASSTEST
#define DCLASSTEST

#include <QtTest/QtTest>
#include "include/Hierarchy/DClass.h"
#include "include/Hierarchy/NaiveAnalyzer.h"
#include "include/Hierarchy/JavaFileReader.h"

class DClassTest: public QObject
{
	Q_OBJECT
	
	private slots:
		void classes1();
		void classes2();
		void classes3();
		void findMethods();
		void getMethod();
		void naiveAnalyzer1();
};

#endif