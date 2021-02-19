#include "include/View/Fenetre.h"

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
	
	
	QDockWidget *snippet = new QDockWidget("Snippets",this);
	QDockWidget *consoles = new QDockWidget("Consoles",this);
	QDockWidget *explorer = new QDockWidget("Explorateur",this);
	
	snippet->setFeatures(QDockWidget::DockWidgetMovable);
	consoles->setFeatures(QDockWidget::DockWidgetMovable);
	explorer->setFeatures(QDockWidget::DockWidgetMovable);
	
    tree = new QTreeView;
    tree->setDragDropMode(QAbstractItemView::DragOnly);
    tree->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tree->setContextMenuPolicy(Qt::CustomContextMenu);
    tree->setItemDelegate(new ExplorerDelegate());
    tree->setHeaderHidden(true);
	explorer->setWidget(tree);
    tree->setModel(model);
	
    console = new Console(consoles);
    consoles->setWidget(console);
	this->addDockWidget(Qt::RightDockWidgetArea,snippet);
	this->addDockWidget(Qt::BottomDockWidgetArea,consoles);
	this->addDockWidget(Qt::LeftDockWidgetArea,explorer);


    connect(tree,SIGNAL(doubleClicked(const QModelIndex)),controller,SLOT(doubleClickOpen(const QModelIndex)));
    connect(central,SIGNAL(tabCloseRequested(int)),controller,SLOT(closeEditor(int)));
    connect(tree,SIGNAL(customContextMenuRequested(const QPoint&)),controller,SLOT(explorerContextMenu(const QPoint&)));
}
