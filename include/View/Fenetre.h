#ifndef FENETRE
#define FENETRE

#include <QtWidgets>
#include "../Model/Model.h"
#include "../Model/DSnippet.h"
#include "../Controller/Controller.h"
#include "Widget/DCodeEditor.h"
#include "Menu/MenuFile.h"
#include "Menu/MenuEdit.h"
#include "Menu/MenuPref.h"
#include "Menu/MenuHelp.h"
#include "Widget/Console.h"
#include "include/Controller/Widget/ExplorerDelegate.h"

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
        Console* getConsole(){return this->console;}
        MenuPref* getMenuPref(){return this->menuPref;}
	private:
		MenuFile *menuFile;
		MenuEdit *menuEdit;
		MenuPref *menuPref;
		MenuHelp *menuHelp;
        Console *console;
        QTreeView *tree;
        QPushButton *newCmd;
        QDockWidget *consoles;
		QTabWidget *central;
        QTabWidget *central2;	
		Model *model;
		Controller *controller;

    public slots:
        void s_newCmd();
		
};

#endif
