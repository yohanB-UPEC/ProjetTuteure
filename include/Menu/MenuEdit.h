#ifndef MENUEDIT
#define MENUEDIT

#include <QMenu>

class Fenetre;

class MenuEdit : public QMenu {
	Q_OBJECT
	
	public:
		MenuEdit(Fenetre *fen);
		
	private:
		Fenetre *fen;
		QAction *cancel;
		QAction *restore;
		QAction *cut;
		QAction *copy;
		QAction *paste;
		QAction *suppr;
		QAction *selectAll;
		QAction *search;
		QAction *search_next;
		QAction *search_previous;
};

#endif