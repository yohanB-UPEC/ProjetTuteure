#ifndef MENUFILE
#define MENUFILE

#include <QMenu>
#include "MenuNew.h"
class Fenetre;
class MenuNew;

class MenuFile : public QMenu {
	Q_OBJECT
	
	public:
		MenuFile(Fenetre *fen);
        MenuNew* getMenuNew(){return this->newf;}
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

    public slots:
        void s_open();
};

#endif
