#ifndef MENUPREF
#define MENUPREF

#include <QMenu>

class Fenetre;

class MenuPref : public QMenu {
	Q_OBJECT
	
	public:
		MenuPref(Fenetre *fen);
		
	private:
		Fenetre *fen;
		
};

#endif