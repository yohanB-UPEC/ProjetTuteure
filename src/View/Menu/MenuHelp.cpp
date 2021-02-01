#include "include/View/Menu/MenuPref.h"
#include "include/View/Fenetre.h"

MenuHelp::MenuHelp(Fenetre *fen) : QMenu("Aide"){
	this->fen = fen;
	
	this->fen->menuBar()->addMenu(this);
	
}