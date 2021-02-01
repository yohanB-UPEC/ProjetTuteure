#include "include/View/Menu/MenuPref.h"
#include "include/View/Fenetre.h"

MenuPref::MenuPref(Fenetre *fen) : QMenu("Préférences"){
	this->fen = fen;
	
	this->fen->menuBar()->addMenu(this);
	
}