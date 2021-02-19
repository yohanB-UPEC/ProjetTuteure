#include "include/View/Dialog/ProjectDialog.h"

ProjectDialog::ProjectDialog(QWidget *parent, Model *model): QDialog(parent), pc(model,this){

	this->resize(600,250);
	this->setMinimumWidth(500);
	this->setWindowTitle("Création de Projet");
	
	QVBoxLayout *layout = new QVBoxLayout(); 
	
	QHBoxLayout *h1 = new QHBoxLayout();
	QLabel *lab1 = new QLabel("Nom de projet: ");
	name = new QLineEdit();
	h1->addWidget(lab1);
	h1->addWidget(name);
	
	QHBoxLayout *h2 = new QHBoxLayout();
	QLabel *lab2 = new QLabel("Emplacement: ");
	loc = new QLineEdit();
	QPushButton *browse = new QPushButton("Parcourir");
	h2->addWidget(lab2);
	h2->addWidget(loc);
	h2->addWidget(browse);
	
	QHBoxLayout *h3 = new QHBoxLayout();
	QLabel *lab3 = new QLabel("JDK spécifique au projet: ");
	jdk = new QComboBox();
	jdk->addItem("Default JDK");
	h3->addWidget(lab3);
	h3->addWidget(jdk);
	

	QHBoxLayout *h4 = new QHBoxLayout();
	h4->setAlignment(Qt::AlignRight);
	valider = new QPushButton("Valider");
	QPushButton *annuler = new QPushButton("Annuler");
	valider->setEnabled(false);
	h4->addWidget(annuler);
	h4->addWidget(valider);
	
	QSpacerItem *si = new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding);
	
	layout->addLayout(h1);
	layout->addLayout(h2);
	layout->addLayout(h3);
	layout->addItem(si);
	layout->addLayout(h4);
	this->setLayout(layout);
	
	
	connect(browse,SIGNAL(clicked()),&pc,SLOT(parcourir()));
	connect(annuler,SIGNAL(clicked()),this,SLOT(reject()));
	connect(valider,SIGNAL(clicked()),&pc,SLOT(createProject()));
	connect(name,SIGNAL(textChanged(QString)),&pc,SLOT(validate()));
	connect(loc,SIGNAL(textChanged(QString)),&pc,SLOT(validate()));
}




const QString ProjectDialog::getName(){
	return this->name->text();
}
const QString ProjectDialog::getLocation(){
	return this->loc->text();
}
const QString ProjectDialog::getJDK(){
	return this->jdk->currentText();
}
