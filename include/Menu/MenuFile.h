#ifndef MENUFILE
#define MENUFILE

#include <QMenu>
#include "MenuNew.h"

class Fenetre;

class MenuFile : public QMenu {
	Q_OBJECT
	
	public:
		MenuFile(Fenetre *fen);
		
	private:
		QAction *nouveau;
		QAction *openFile;
		QAction *recentFiles;
		QAction *closeEditor;
		QAction *closeAllEditor;
		QAction *save;
		QAction *saveAs;
		QAction *saveAll;
		QAction *properties;
		QAction *quitter;
		MenuNew *newf;
		Fenetre *fen;
};

#endif