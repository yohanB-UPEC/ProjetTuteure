#include "include/View/Menu/MenuEdit.h"
#include "include/View/Fenetre.h"

MenuEdit::MenuEdit(Fenetre *fen) : QMenu("Edition"){
	this->fen = fen;
	
	cancel = this->addAction("Annuler");
	restore = this->addAction("Rétablir");
	
	this->addSeparator();
	cut = this->addAction("Couper");
	copy = this->addAction("Copier");
	paste = this->addAction("Coller");
	
	this->addSeparator();
	suppr = this->addAction("supprimer");
	selectAll = this->addAction("Tout Selectionner");
	
	this->addSeparator();
	search = this->addAction("Rechercher/Remplacer");
	search_next = this->addAction("Recherche Suivante");
	search_previous = this->addAction("Recherche Précédente");
	
	this->fen->menuBar()->addMenu(this);
	
}