#include "include/View/Menu/MenuEdit.h"
#include "include/View/Fenetre.h"

MenuEdit::MenuEdit(Fenetre *fen) : QMenu("Edition"), me(this){
	this->fen = fen;
	
	cancel = this->addAction("Annuler");
    cancel->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
	restore = this->addAction("Rétablir");
    restore->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y));
	
	this->addSeparator();
	cut = this->addAction("Couper");
    cut->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));
	copy = this->addAction("Copier");
    copy->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
	paste = this->addAction("Coller");
    paste->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_V));
	
	this->addSeparator();
	suppr = this->addAction("supprimer");
    suppr->setShortcut(Qt::Key_Delete);
	selectAll = this->addAction("Tout Selectionner");
    selectAll->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_A));
	
	this->addSeparator();
    search = this->addAction("Rechercher");
    search->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F));
	search_next = this->addAction("Recherche Suivante");
    search_next->setShortcut(QKeySequence(Qt::Key_F3));
	search_previous = this->addAction("Recherche Précédente");
    search_previous->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_F3));
    replace = this->addAction("Remplacer");
    replace->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_H));
	
    this->fen->menuBar()->addMenu(this);
    connect(cancel,SIGNAL(triggered()),&me,SLOT(s_Undo()));
    connect(restore,SIGNAL(triggered()),&me,SLOT(s_Redo()));
    connect(cut,SIGNAL(triggered()),&me,SLOT(s_Cut()));
    connect(copy,SIGNAL(triggered()),&me,SLOT(s_Copy()));
    connect(paste,SIGNAL(triggered()),&me,SLOT(s_Paste()));
    connect(suppr,SIGNAL(triggered()),&me,SLOT(s_Suppr()));
    connect(selectAll,SIGNAL(triggered()),&me,SLOT(s_SelectAll()));
    connect(search,SIGNAL(triggered()),&me,SLOT(s_Search()));
    connect(search_next,SIGNAL(triggered()),&me,SLOT(s_SearchNext()));
    connect(search_previous,SIGNAL(triggered()),&me,SLOT(s_SearchPrev()));
    connect(replace,SIGNAL(triggered()),&me,SLOT(s_Replace()));
}
