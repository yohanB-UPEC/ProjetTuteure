#include "include/UnitTest/DClassTest.h"

void DClassTest::classes1(){
	DClass dc("Player","public","class");	
	{
		std::list<DClass*>& classes = dc.classes();
		classes.push_back(new DClass("Model","private","class")); 
		classes.push_back(new DClass("Inventaire","public","class")); 
		classes.push_back(new DClass("Location","public","class"));
	}
	QVERIFY(dc.classes().size() == 3);
}

void DClassTest::classes2(){
	DClass dc("Player","public","class");	
	{
		dc.classes().push_back(new DClass("Model","private","class"));
	}
	DClass& tmp = *(dc.classes().front());
	QVERIFY(tmp.label() == "Model" && tmp.scope() == "private" && tmp.type() == "class");
}

void DClassTest::classes3(){
	DClass dc("Player","public","class");
	
	DClass *c1 = new DClass("Classe1","public","class");
	DClass *c2 = new DClass("Classe2","public","class");
	DClass *c3 = new DClass("Classe3","public","class");
	
	std::list<DClass*>& classes = dc.classes();
	classes.push_back(c1);
	classes.push_back(c2);
	classes.push_back(c3);
	
	DClass* c2b = dc.findClasses("Classe2").front();
	c2b->setType("Enum");
	
	QVERIFY(dc.findClasses("Classe2").front()->type() == c2b->type());
}


void DClassTest::findMethods(){
	DClass dc("Player","public","class");	
	{
		DMethod* m1 = new DMethod("getPath","public","String");
		m1->addParametre("File","f");
		dc.methods().push_back(m1);
		dc.methods().push_back(new DMethod("close","public","void"));
		dc.methods().push_back(new DMethod("getPath","public","String"));
	}
	QVERIFY(dc.findMethods("getPath").size() == 2);
}

void DClassTest::getMethod(){
	DClass dc("Player","public","class");
	{

		DMethod* m2 = new DMethod("fonction1","public","String");
		m2->addParametre("Param1","1");
		m2->addParametre("Param1","2");
		
		DMethod *m3 = new DMethod("fonction1","public","String");
		m3->addParametre("Param1","1");
		m3->addParametre("Param2","2");
		m3->addParametre("Param3","3");
		
		DMethod *m1 = new DMethod("fonction1","public","String");
		m1->addParametre("Param1","1");
		m1->addParametre("Param2","2");
		
		auto& methods = dc.methods();
		methods.push_back(m2);
		methods.push_back(m3);
		methods.push_back(m1);
		methods.push_back(new DMethod("close","public","void")); 
		methods.push_back(new DMethod("getPath","public","String"));
	}
	DMethod*  tmp = dc.getMethod("fonction1",2,"Param1","Param2");
	QVERIFY(tmp != nullptr && tmp->label() == "fonction1" && tmp->parametres()[0]->type() == "Param1" && tmp->parametres()[1]->type() == "Param2" && tmp->parametres().size() == 2);
}


void DClassTest::naiveAnalyzer1(){
	QFile dc("./debug/test/test1.java");
	if(!dc.open(QIODevice::ReadOnly | QIODevice::Text)){
		COUT << "--> impossible d'ouvrir le fichier <-- \n";
		QVERIFY(0);
	}
	JavaFileReader jfr(dc);
	QChar res;
	while((res = jfr.readChar()) != -1){
		if(res == 0)
			COUT << '|';
		else
			COUT << res;
	}
	QVERIFY(1);
}

QTEST_MAIN(DClassTest)