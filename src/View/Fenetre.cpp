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

    central2 = new QTabWidget(this);
    central2->setTabsClosable(true);
    central2->setMovable(true);

	
	
	QDockWidget *snippet = new QDockWidget("Snippets",this);
    snippet->setWidget(new Snippet(this));
    consoles = new QDockWidget("Consoles",this);

    newCmd = new QPushButton("+");
    const QSize size = QSize(20, 20);
    newCmd->setFixedSize(size);
    newCmd->setStyleSheet("background: blue; border-style: outset; border-radius: 10px; color: white; font: bold 20px;");

    QLabel *lab = new QLabel("Consoles");
    lab->setStyleSheet("font-size: 12px;");

    QWidget *title_bar = new QWidget();
    title_bar->setStyleSheet("background: rgb(218,218,218); padding: 0; margin: 0; border-style: outset; border-width: 1px; border-color: grey;");
    title_bar->setMaximumHeight(25);
    QHBoxLayout *layout = new QHBoxLayout();
    layout->setContentsMargins(5,0,50,0);

    title_bar->setLayout(layout);

    layout->addWidget(lab);
    layout->addWidget(newCmd, Qt::AlignVCenter);
    consoles->setTitleBarWidget(title_bar);
	QDockWidget *explorer = new QDockWidget("Explorateur",this);
	
	snippet->setFeatures(QDockWidget::DockWidgetMovable);
	consoles->setFeatures(QDockWidget::DockWidgetMovable);
	explorer->setFeatures(QDockWidget::DockWidgetMovable);
	
    QTreeView *tree = new QTreeView;
    tree->setHeaderHidden(true);
	explorer->setWidget(tree);
    tree->setModel(model);
	
    consoles->setWidget(central2);
	this->addDockWidget(Qt::RightDockWidgetArea,snippet);
	this->addDockWidget(Qt::BottomDockWidgetArea,consoles);
	this->addDockWidget(Qt::LeftDockWidgetArea,explorer);

    connect(newCmd,SIGNAL(clicked()),this,SLOT(s_newCmd()));
	
}

void Fenetre::s_newCmd(){
    central2->addTab(new Console(consoles),"nouveau");
}
