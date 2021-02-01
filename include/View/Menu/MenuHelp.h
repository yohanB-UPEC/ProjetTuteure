#ifndef MENUHELP
#define MENUHELP

#include <QMenu>

class Fenetre;

class MenuHelp : public QMenu {
	Q_OBJECT
	
	public:
		MenuHelp(Fenetre *fen);
		
	private:
		Fenetre *fen;
		
};

#endif