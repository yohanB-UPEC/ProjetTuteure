#ifndef FENETRE
#define FENETRE

#include <QtWidgets>
#include "../Model/Model.h"
#include "../Controller/Controller.h"
#include "Widget/DCodeEditor.h"
#include "Menu/MenuFile.h"
#include "Menu/MenuEdit.h"
#include "Menu/MenuPref.h"
#include "Menu/MenuHelp.h"
#include "Widget/Console.h"



class Fenetre : public QMainWindow {
	Q_OBJECT
	
	public:
		Fenetre(Model *model);
		QTabWidget* getCentral(){return central;}
		Model* getModel(){return this->model;}
	private:
		MenuFile *menuFile;
		MenuEdit *menuEdit;
		MenuPref *menuPref;
		MenuHelp *menuHelp;
        Console *console;
		
		QTabWidget *central;
		
		Model *model;
		Controller *controller;
		
};

#endif
