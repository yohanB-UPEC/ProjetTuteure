#include "include/Menu/MenuPref.h"
#include "include/Widget/Fenetre.h"

MenuHelp::MenuHelp(Fenetre *fen) : QMenu("Aide"){
	this->fen = fen;
	
	this->fen->menuBar()->addMenu(this);
	
}