#include "qsizepolicy.h"
#include "include/View/Fenetre.h"
#include "include/View/Widget/Console.h"
#include "include/View/Widget/Snippet.h"

Fenetre::Fenetre(Model *model) : QMainWindow(){
	this->model = model;
	this->controller = new Controller(this,this->model);
	this->resize(1000,600);
	this->setWindowTitle("Projet Dyst Editor");
	this->setWindowIcon(DIcons::logo);

	menuFile = new MenuFile(this);
	menuEdit = new MenuEdit(this);
	menuPref = new MenuPref(this);
	menuHelp = new MenuHelp(this);

	
	central = new QTabWidget(this);
	central->setTabsClosable(true);
    central->setMovable(true);
	this->setCentralWidget(central);


    tree = new QTreeView;
    tree->setDragDropMode(QAbstractItemView::DragOnly);
    tree->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tree->setContextMenuPolicy(Qt::CustomContextMenu);
    tree->setItemDelegate(new ExplorerDelegate());
    tree->setHeaderHidden(true);
    tree->setModel(model);

	
    QDockWidget *snippet = new QDockWidget("Snippets",this);
    QDockWidget *explorer = new QDockWidget("Explorateur",this);
    QDockWidget *consoles = new QDockWidget("Terminale de commande:  ",this);

    snippet->setFeatures(QDockWidget::DockWidgetMovable);
    consoles->setFeatures(QDockWidget::DockWidgetMovable);
    explorer->setFeatures(QDockWidget::DockWidgetMovable);

    this->addDockWidget(Qt::RightDockWidgetArea,snippet);
    this->addDockWidget(Qt::BottomDockWidgetArea,consoles);
    this->addDockWidget(Qt::LeftDockWidgetArea,explorer);

    TitleBar *consoleBar = new TitleBar();
    consoles->setTitleBarWidget(consoleBar);
    ConsoleTabWidget *consoleTabs = new ConsoleTabWidget(consoleBar,model->getConsole());
    consoles->setWidget(consoleTabs);

    snippet->setTitleBarWidget(new TitleBar());

    snippet->setWidget(new Snippet(this));
    explorer->setWidget(tree);




    connect(tree,SIGNAL(doubleClicked(const QModelIndex)),controller,SLOT(openEditor(const QModelIndex)));
    connect(tree,SIGNAL(doubleClicked(const QModelIndex)),controller,SLOT(doubleClickOpen(const QModelIndex)));
    connect(central,SIGNAL(tabCloseRequested(int)),controller,SLOT(closeEditor(int)));
    connect(tree,SIGNAL(customContextMenuRequested(const QPoint&)),controller,SLOT(explorerContextMenu(const QPoint&)));

}


