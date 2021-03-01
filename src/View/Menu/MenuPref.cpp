#include "include/View/Menu/MenuPref.h"
#include "include/View/Fenetre.h"
#include "include/View/Widget/Console.h"

MenuPref::MenuPref(Fenetre *fen) : QMenu("Préférences"), mp(this){
	this->fen = fen;

    theme = this->addAction("Thème");
    term = this->addAction("Terminal");
	
	this->fen->menuBar()->addMenu(this);

    connect(theme,SIGNAL(triggered()),&mp,SLOT(s_Theme()));
    connect(term,SIGNAL(triggered()),&mp,SLOT(s_Term()));
	
}





