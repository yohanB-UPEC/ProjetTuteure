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
#include "include/Controller/Widget/ExplorerDelegate.h"
#include "include/View/Widget/Snippet.h"
#include "Widget/TitleBar.h"
#include "Widget/ConsoleTabWidget.h"

class MenuFile;

class Fenetre : public QMainWindow {
	Q_OBJECT
    friend class Controller;
	public:
		Fenetre(Model *model);
		QTabWidget* getCentral(){return central;}
		Model* getModel(){return this->model;}
        Controller* getController(){return this->controller;}
        MenuFile* getMenuFile(){return this->menuFile;}
        QTreeView* getExplorer(){return this->tree;}
        MenuPref* getMenuPref(){return this->menuPref;}
	private:
		MenuFile *menuFile;
		MenuEdit *menuEdit;
		MenuPref *menuPref;
		MenuHelp *menuHelp;

        QTreeView *tree;
		QTabWidget *central;
		Model *model;
		Controller *controller;
		
};

#endif
