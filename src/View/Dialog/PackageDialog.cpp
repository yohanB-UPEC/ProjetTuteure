#include "include/View/Dialog/PackageDialog.h"

PackageDialog::PackageDialog(QWidget *parent): QDialog(parent){

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
    layout->addLayout(h1);
    layout->addLayout(h2);
    
    this->setLayout(layout);

    /* écouteurs d'évenement */

    connect(annuler,SIGNAL(clicked()),this,SLOT(reject()));
	connect(valider,SIGNAL(clicked()),this,SLOT(accept()));
	connect(name,SIGNAL(textChanged(QString)),this,SLOT(validate()));
	connect(pkgTree->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&,const QItemSelection&)), this, SLOT(validate()));
	connect(pkgTree->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&,const QItemSelection&)), this, SLOT(selectedItem(const QItemSelection&,const QItemSelection&)));
}

/* Bouton valider uniquement clickable quand le nom du package et le choix du package ont été choisis */

void PackageDialog::validate(){
	if(loc.size() > 0 && name->text().size() > 0){
		this->valider->setEnabled(true);
	}else{
		this->valider->setEnabled(false);
	}
}

/* permet d'obtenir la chemin d'accès du package */

void PackageDialog::selectedItem(const QItemSelection &selected, const QItemSelection &deselected){
	QModelIndexList items = selected.indexes();
    loc = filemodel->filePath(items[0]);
    printf("%s\n", loc.toStdString().c_str());
}
