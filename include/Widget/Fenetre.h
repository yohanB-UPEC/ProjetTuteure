#ifndef FENETRE
#define FENETRE

#include <QtWidgets>
#include "DCodeEditor.h"
#include "include/Menu/MenuFile.h"
#include "include/Menu/MenuEdit.h"
#include "include/Menu/MenuPref.h"
#include "include/Menu/MenuHelp.h"

class Fenetre : public QMainWindow {
	Q_OBJECT
	
	public:
		Fenetre();
		QTabWidget* getCentral(){return central;}
		
	private:
		MenuFile *menuFile;
		MenuEdit *menuEdit;
		MenuPref *menuPref;
		MenuHelp *menuHelp;
		
		QTabWidget *central;
		
};

#endif