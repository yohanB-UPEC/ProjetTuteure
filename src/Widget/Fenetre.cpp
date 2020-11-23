
#include "include/Widget/Fenetre.h"

Fenetre::Fenetre() : QMainWindow(){
	this->resize(1000,600);
	this->setWindowTitle("Projet Dyst Editor");
	
	loadFileMenu();
	loadEditionMenu();
	loadPrefMenu();
	loadAideMenu();
	
	tw1 = new QTabWidget(this);
	tw1->setTabsClosable(true);
	tw1->setMovable(true);
	this->setCentralWidget(tw1);
	
	
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

void Fenetre::loadFileMenu(){
	fileMenu = menuBar()->addMenu("Fichier");
	(f_newProject = fileMenu->addAction("New"))->setShortcut(QKeySequence("Ctrl+N"));
	(f_openFile = fileMenu->addAction("Open File"))->setShortcut(QKeySequence("Ctrl+O"));
	f_recentFiles = fileMenu->addAction("Recent Files");
	fileMenu->addSeparator();
	(f_closeEditor = fileMenu->addAction("Close Editor"))->setShortcut(QKeySequence("Ctrl+W"));
	(f_closeAllEditor = fileMenu->addAction("Close All Editors"))->setShortcut(QKeySequence("Ctrl+Shift+W"));
	fileMenu->addSeparator();
	(f_save = fileMenu->addAction("Save"))->setShortcut(QKeySequence("Ctrl+S"));
	f_saveAs = fileMenu->addAction("Save As");
	(f_saveAll = fileMenu->addAction("Save All"))->setShortcut(QKeySequence("Ctrl+Shift+S"));
	fileMenu->addSeparator();
	(f_properties = fileMenu->addAction("Propriétés"))->setShortcut(QKeySequence("Alt+Enter"));
	fileMenu->addSeparator();
	f_quitter = fileMenu->addAction("Quitter");
	
	newf = new QMenu();
	newf->addAction("Java Project");
	newf->addSeparator();
	newf->addAction("Package");
	newf->addAction("Class");
	newf->addAction("Interface");
	newf->addAction("Enum");
	newf->addAction("Folder");
	f_newFile = newf->addAction("File");
	f_newProject->setMenu(newf);
	
	connect(f_newFile,SIGNAL(triggered()),this,SLOT(addTab()));
	connect(f_quitter,SIGNAL(triggered()),qApp,SLOT(closeAllWindows()));
	
}

void Fenetre::loadEditionMenu(){
	editMenu = menuBar()->addMenu("Edition");
	editMenu->addAction("Annuler");
	editMenu->addAction("Rétablir");
	editMenu->addSeparator();
	editMenu->addAction("Couper");
	QAction *copy = editMenu->addAction("Copier");
	QAction *paste = editMenu->addAction("Coller");
	editMenu->addSeparator();
	editMenu->addAction("supprimer");
	editMenu->addAction("Tout Selectionner");
	editMenu->addSeparator();
	editMenu->addAction("Rechercher/Remplacer");
	editMenu->addAction("Recherche Suivante");
	editMenu->addAction("Recherche Précédente");
}

void Fenetre::loadPrefMenu(){
	prefMenu = menuBar()->addMenu("Préférences");
}

void Fenetre::loadAideMenu(){
	aideMenu = menuBar()->addMenu("Aide");
}

void Fenetre::addTab(){
	tw1->addTab(new DCodeEditor(),"nouveau");
}