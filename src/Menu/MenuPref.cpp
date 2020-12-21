#include "include/Menu/MenuPref.h"
#include "include/Widget/Fenetre.h"

MenuPref::MenuPref(Fenetre *fen) : QMenu("Préférences"){
	this->fen = fen;
	
	this->fen->menuBar()->addMenu(this);
	
}