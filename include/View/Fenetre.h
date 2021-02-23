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
        Snippet* getSnippet(){return this->snippet;}
        QLabel* getLabel(){return this->lab;}
	private:
		MenuFile *menuFile;
		MenuEdit *menuEdit;
		MenuPref *menuPref;
		MenuHelp *menuHelp;
        Console *console;
        Snippet *snippet;
        QTreeView *tree;
        QPushButton *newCmd;
        QPushButton *stopProc;
        QDockWidget *consoles;
		QTabWidget *central;
        QTabWidget *central2;
        QLabel *lab;
		Model *model;
		Controller *controller;

    public slots:
        void s_newCmd();
        void s_stopProc();
		
};

#endif
