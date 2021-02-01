#include "include/View/Menu/MenuNew.h"
#include "include/View/Fenetre.h"

MenuNew::MenuNew(Fenetre* fen) : QMenu(){
	this->fen = fen;
	javaProject = this->addAction("Java Project");
	this->addSeparator();
	package = this->addAction("Package");
	aClass = this->addAction("Class");
	aInterface = this->addAction("Interface");
	aEnum = this->addAction("Enum");
	folder = this->addAction("Folder");
	file = this->addAction("File");
	
	connect(javaProject,SIGNAL(triggered()),this,SLOT(s_Project()));
	connect(file,SIGNAL(triggered()),this,SLOT(s_File()));
	
}

void MenuNew::s_File(){
	this->fen->getCentral()->addTab(new DCodeEditor(),"nouveau");
}
void MenuNew::s_Project(){
	ProjectDialog proDia(this->fen);
	int res = proDia.exec();
	printf("ProDia= %d\n",res);
}