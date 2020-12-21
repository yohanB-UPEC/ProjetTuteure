#ifndef MENUNEW
#define MENUNEW

#include <QMenu>

class Fenetre; 

class MenuNew : public QMenu {
	Q_OBJECT
	
	public:
		MenuNew(Fenetre* fen);
	
	public slots:
		void s_File();
		
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