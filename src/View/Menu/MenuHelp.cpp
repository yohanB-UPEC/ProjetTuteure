#include "include/View/Menu/MenuPref.h"
#include "include/View/Fenetre.h"

MenuHelp::MenuHelp(Fenetre *fen) : QMenu("Aide"){
    this->fen = fen;

    doc = this->addAction("Documentation");
    about = this->addAction("A propos");
	
	this->fen->menuBar()->addMenu(this);

    connect(doc,SIGNAL(triggered()),this,SLOT(s_Doc()));
    connect(about,SIGNAL(triggered()),this,SLOT(s_About()));
	
}

void MenuHelp::s_Doc(){
    //redirect link to QDoc
}

void MenuHelp::s_About(){
    QDialog *dial = new QDialog();
    const QSize size(470, 170);
    dial->setFixedSize(size);
    dial->setWindowTitle("A propos");

    QVBoxLayout *lay = new QVBoxLayout();

    QHBoxLayout *h = new QHBoxLayout();
    QLabel *lab = new QLabel();
    const QSize size2(100, 100);
    DIcons::logo.pixmap(size2);
    lab->setPixmap(DIcons::logo.pixmap(size2));
    h->addWidget(lab);

    QLabel *content = new QLabel();
    content->setText("Javora est un IDE crée par Jérémy Varange, Yohan Bordes,\nNoah Lacaste et Alexandre Ventura\n\nBasé sur Qt 5.15.1 \n\nmars 2021");

    QHBoxLayout *h1 = new QHBoxLayout();
    h1->setAlignment(Qt::AlignRight);
    QPushButton *fermer = new QPushButton("Fermer");

    h->addWidget(content);
    h1->addWidget(fermer);

    lay->addLayout(h);
    lay->addLayout(h1);
    dial->setLayout(lay);

    connect(fermer,SIGNAL(clicked()),dial,SLOT(accept()));
    dial->exec();
}
