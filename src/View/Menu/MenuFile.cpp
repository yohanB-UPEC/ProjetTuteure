#include "include/View/Menu/MenuFile.h"
#include "include/View/Fenetre.h"

MenuFile::MenuFile(Fenetre *fen) : QMenu("Fichier"){
	this->fen = fen;
	nouveau = this->addAction("New");
	openFile = this->addAction("Open File");
	recentFiles = this->addAction("Recent Files");
	this->addSeparator();
	closeEditor = this->addAction("Close Editor");
	closeAllEditor = this->addAction("Close All Editors");
	this->addSeparator();
	save = this->addAction("Save");
	saveAs = this->addAction("Save As");
	saveAll = this->addAction("Save All");
	this->addSeparator();
	properties = this->addAction("Propriétés");
	this->addSeparator();
	quitter = this->addAction("Quitter");
	
	newf = new MenuNew(fen);
	nouveau->setMenu(newf);
	
	connect(quitter,SIGNAL(triggered()),qApp,SLOT(closeAllWindows()));
	
	this->fen->menuBar()->addMenu(this);
}