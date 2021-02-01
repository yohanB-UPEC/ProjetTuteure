#ifndef MENUNEW
#define MENUNEW

#include <QMenu>
#include "../Dialog/ProjectDialog.h"

class Fenetre; 

class MenuNew : public QMenu {
	Q_OBJECT
	
	public:
		MenuNew(Fenetre* fen);
	
	public slots:
		void s_File();
		void s_Project();
		
	private:
		QAction *javaProject;
		QAction *package;
		QAction *aClass;
		QAction *aInterface;
		QAction *aEnum;
		QAction *folder;
		QAction *file;
		Fenetre *fen;
};

#endif