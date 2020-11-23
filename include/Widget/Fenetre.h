#ifndef FENETRE
#define FENETRE

#include <QtWidgets>
#include "DCodeEditor.h"

class Fenetre : public QMainWindow {
	Q_OBJECT
	
	public:
		Fenetre();
	
	public slots:
		void addTab();
	
	private:
		void loadFileMenu();
		QMenu *fileMenu;		
		QAction *f_newProject;
		QAction *f_newFile;
		QAction *f_openFile;
		QAction *f_recentFiles;
		QAction *f_closeEditor;
		QAction *f_closeAllEditor;
		QAction *f_save;
		QAction *f_saveAs;
		QAction *f_saveAll;
		QAction *f_properties;
		QAction *f_quitter;	
		QMenu *newf;		
		QMenu *editMenu;
		QMenu *prefMenu;
		QMenu *aideMenu;
		
		void loadEditionMenu();
		void loadPrefMenu();
		void loadAideMenu();
		
		QTabWidget *tw1;
		
};

#endif