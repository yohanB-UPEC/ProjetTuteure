#include "include/View/Fenetre.h"

Fenetre::Fenetre(Model *model) : QMainWindow(){
	this->model = model;
	this->controller = new Controller(this,this->model);
	this->resize(1000,600);
	this->setWindowTitle("Projet Dyst Editor");
	this->setWindowIcon(DIcons::logo);

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
	
	//QFileSystemModel *filemodel = new QFileSystemModel;
    //filemodel->setRootPath(QDir::currentPath());
    QTreeView *tree = new QTreeView;
    tree->setHeaderHidden(true);
	explorer->setWidget(tree);
    tree->setModel(model);
	
    console = new Console(consoles);
    consoles->setWidget(console);
	this->addDockWidget(Qt::RightDockWidgetArea,snippet);
	this->addDockWidget(Qt::BottomDockWidgetArea,consoles);
	this->addDockWidget(Qt::LeftDockWidgetArea,explorer);
	
}
