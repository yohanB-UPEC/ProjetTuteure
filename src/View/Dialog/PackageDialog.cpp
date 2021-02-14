#include "include/View/Dialog/PackageDialog.h"

PackageDialog::PackageDialog(QWidget *parent): QDialog(parent), pkd(this){

	/* paramètrage de la boîte de dialogue */

	this->resize(600,500);
	this->setMinimumWidth(500);
	this->setWindowTitle("Nouveau package");

	QVBoxLayout *layout = new QVBoxLayout();

	/* explorateur de fichier */

	filemodel = new QFileSystemModel;
	filemodel->setRootPath(QDir::currentPath());
	QTreeView *pkgTree = new QTreeView;
    pkgTree->setModel(filemodel);

    /* chemin du package */

    QHBoxLayout *h3 = new QHBoxLayout();
    QLabel *lab2 = new QLabel("Chemin du projet: ");
    path = new QLineEdit();
    h3->addWidget(lab2);
    h3->addWidget(path);

    /* choix du nom du projet */
	
	QHBoxLayout *h1 = new QHBoxLayout();
	QLabel *lab1 = new QLabel("Nom de projet: ");
	name = new QLineEdit();
	h1->addWidget(lab1);
	h1->addWidget(name);

	/* Bouton annuler et valider */

    QHBoxLayout *h2 = new QHBoxLayout();
	h2->setAlignment(Qt::AlignRight);
	valider = new QPushButton("Valider");
	QPushButton *annuler = new QPushButton("Annuler");
	valider->setEnabled(false);
	h2->addWidget(annuler);
	h2->addWidget(valider);

	/* ajout des différents widgets dans la boîte de dialogue */

	layout->addWidget(pkgTree);
    layout->addLayout(h3);
    layout->addLayout(h1);
    layout->addLayout(h2);
    
    this->setLayout(layout);

    /* écouteurs d'évenement */

    connect(annuler,SIGNAL(clicked()),this,SLOT(reject()));
	connect(valider,SIGNAL(clicked()),this,SLOT(accept()));
    connect(name,SIGNAL(textChanged(QString)),&pkd,SLOT(validate()));
    connect(pkgTree->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&,const QItemSelection&)), &pkd, SLOT(validate()));
    connect(pkgTree->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&,const QItemSelection&)), &pkd, SLOT(selectedItem(const QItemSelection&,const QItemSelection&)));
}
