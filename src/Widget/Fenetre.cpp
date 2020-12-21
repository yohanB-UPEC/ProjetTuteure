#include "include/Widget/Fenetre.h"

Fenetre::Fenetre() : QMainWindow(){
	this->resize(1000,600);
	this->setWindowTitle("Projet Dyst Editor");
	
	menuFile = new MenuFile(this);
	menuEdit = new MenuEdit(this);
	menuPref = new MenuPref(this);
	menuHelp = new MenuHelp(this);
	
	central = new QTabWidget(this);
	central->setTabsClosable(true);
	central->setMovable(true);
	this->setCentralWidget(central);
	
	
	QDockWidget *snippet = new QDockWidget("Snippets",this);
	QDockWidget *consoles = new QDockWidget("Consoles",this);
	QDockWidget *explorer = new QDockWidget("Explorateur",this);
	
	snippet->setFeatures(QDockWidget::DockWidgetMovable);
	consoles->setFeatures(QDockWidget::DockWidgetMovable);
	explorer->setFeatures(QDockWidget::DockWidgetMovable);
	
	
	
	
	this->addDockWidget(Qt::RightDockWidgetArea,snippet);
	this->addDockWidget(Qt::BottomDockWidgetArea,consoles);
	this->addDockWidget(Qt::LeftDockWidgetArea,explorer);
	
}
