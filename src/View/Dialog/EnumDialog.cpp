#include "include/View/Dialog/EnumDialog.h"

EnumDialog::EnumDialog(QWidget *parent): QDialog(parent), ed(this){

    /* Paramètrage de la boîte de dialogue */

    this->resize(600,250);
    this->setMinimumWidth(500);
    this->setWindowTitle("Nouvelle interface");

    QVBoxLayout *layout = new QVBoxLayout();

    /* Choix du nom de l'énumération */

    QHBoxLayout *h1 = new QHBoxLayout();
    QLabel *lab1 = new QLabel("Nom* ");
    name = new QLineEdit();
    h1->addWidget(lab1);
    h1->addWidget(name);

    /* dossier source */

    QHBoxLayout *h2 = new QHBoxLayout();
    QLabel *lab2 = new QLabel("Emplacement du package: ");
    loc = new QLineEdit();
    QPushButton *browse = new QPushButton("Parcourir");
    h2->addWidget(lab2);
    h2->addWidget(loc);
    h2->addWidget(browse);

    /* package */

    QHBoxLayout *h3 = new QHBoxLayout();
    QLabel *lab3 = new QLabel("Emplacement du dossier: ");
    loc2 = new QLineEdit();
    QPushButton *browse2 = new QPushButton("Parcourir");
    h3->addWidget(lab3);
    h3->addWidget(loc2);
    h3->addWidget(browse2);

    /* Choix de la visibilité de l'énumération */


    QLabel *lab4 = new QLabel("Visibilité ");
    QHBoxLayout *h5 = new QHBoxLayout();

    QRadioButton *radio1 = new QRadioButton(tr("public"));
    QRadioButton *radio2 = new QRadioButton(tr("private"));
    QRadioButton *radio3 = new QRadioButton(tr("protected"));

    radio1->setChecked(true);

    h5->addWidget(lab4);
    h5->addWidget(radio1);
    h5->addWidget(radio2);
    h5->addWidget(radio3);

    /* Bouton annuler et valider */

    QHBoxLayout *h4 = new QHBoxLayout();
    h2->setAlignment(Qt::AlignRight);
    valider = new QPushButton("Valider");
    QPushButton *annuler = new QPushButton("Annuler");
    valider->setEnabled(false);
    h4->addWidget(annuler);
    h4->addWidget(valider);

    layout->addLayout(h1);
    layout->addLayout(h2);
    layout->addLayout(h3);
    layout->addLayout(h5);
    layout->addLayout(h4);
    this->setLayout(layout);

    connect(browse,SIGNAL(clicked()),&ed,SLOT(parcourir()));
    connect(browse2,SIGNAL(clicked()),&ed,SLOT(parcourir2()));
    connect(annuler,SIGNAL(clicked()),this,SLOT(reject()));
    connect(valider,SIGNAL(clicked()),this,SLOT(accept()));
    connect(name,SIGNAL(textChanged(QString)),&ed,SLOT(validate()));
    connect(loc,SIGNAL(textChanged(QString)),&ed,SLOT(validate()));
    connect(loc2,SIGNAL(textChanged(QString)),&ed,SLOT(validate()));
}
