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


    /*central2 = new QTabWidget(this);
    central2->setTabsClosable(true);
    central2->setMovable(true);*/

	
    QDockWidget *snippet = new QDockWidget("Snippets",this);
    QDockWidget *explorer = new QDockWidget("Explorateur",this);
    QDockWidget *consoles = new QDockWidget("Consoles",this);

    snippet->setFeatures(QDockWidget::DockWidgetMovable);
    consoles->setFeatures(QDockWidget::DockWidgetMovable);
    explorer->setFeatures(QDockWidget::DockWidgetMovable);

    this->addDockWidget(Qt::RightDockWidgetArea,snippet);
    this->addDockWidget(Qt::BottomDockWidgetArea,consoles);
    this->addDockWidget(Qt::LeftDockWidgetArea,explorer);


    consoles->setTitleBarWidget(new TitleBar());
    snippet->setTitleBarWidget(new TitleBar());

    snippet->setWidget(new Snippet(this));
    explorer->setWidget(tree);









/*
    QIcon addI("res/icons/add.png");
    newCmd = new QPushButton(addI, "");
    const QSize size = QSize(20, 20);
    newCmd->setFixedSize(size);
    newCmd->setStyleSheet("border: none;");

    QLabel *lab = new QLabel("Consoles");
    lab->setStyleSheet("font-size: 12px;");

    QWidget *title_bar = new QWidget();
    title_bar->setMaximumHeight(25);
    QHBoxLayout *layout = new QHBoxLayout();
    layout->setContentsMargins(5,0,50,0);

    title_bar->setLayout(layout);

    layout->addWidget(lab);
    layout->addWidget(newCmd, Qt::AlignVCenter);

    consoles->setTitleBarWidget(title_bar);*/

	
	
    //consoles->setWidget(central2);



    connect(tree,SIGNAL(doubleClicked(const QModelIndex)),controller,SLOT(openEditor(const QModelIndex)));
    connect(central,SIGNAL(tabCloseRequested(int)),controller,SLOT(closeEditor(int)));
    connect(tree,SIGNAL(customContextMenuRequested(const QPoint&)),controller,SLOT(explorerContextMenu(const QPoint&)));
    //connect(newCmd,SIGNAL(clicked()),this,SLOT(s_newCmd()));

}
/*
void Fenetre::s_newCmd(){
    console = new Console(this, consoles);
    central2->addTab(console,"nouveau");
}*/
