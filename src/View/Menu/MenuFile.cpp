#include "include/View/Menu/MenuFile.h"
#include "include/View/Fenetre.h"

MenuFile::MenuFile(Fenetre *fen) : QMenu("Fichier"){
	this->fen = fen;
	nouveau = this->addAction("New");
    openFile = this->addAction("Open File",this,SLOT(s_open()),QKeySequence(Qt::CTRL + Qt::Key_O));
	recentFiles = this->addAction("Recent Files");
	this->addSeparator();
    closeEditor = this->addAction("Close Editor",fen->getController(),SLOT(closeEditor()),QKeySequence(Qt::CTRL + Qt::Key_W));
    closeAllEditor = this->addAction("Close All Editors",fen->getController(),SLOT(closeAllEditor()),QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_W));
	this->addSeparator();
    save = this->addAction("Save",fen->getController(), SLOT(saveEditor()), QKeySequence(Qt::CTRL + Qt::Key_S) );
	saveAs = this->addAction("Save As");
    saveAll = this->addAction("Save All",fen->getController(), SLOT(saveAllEditor()), QKeySequence(Qt::CTRL + Qt::SHIFT + Qt::Key_S));
	this->addSeparator();
	properties = this->addAction("Propriétés");
	this->addSeparator();
    quitter = this->addAction("Quitter",qApp,SLOT(closeAllWindows()));
	
	newf = new MenuNew(fen);
	nouveau->setMenu(newf);
	
	this->fen->menuBar()->addMenu(this);
}

void MenuFile::s_open(){
    QString path = QFileDialog::getOpenFileName(fen);
    fen->getController()->openEditor(path);
}
