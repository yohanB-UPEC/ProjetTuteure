#include "include/View/Dialog/ClassDialog.h"

ClassDialog::ClassDialog(QWidget *parent): QDialog(parent){

	/* Paramètrage de la boîte de dialogue */

	this->resize(600,250);
	this->setMinimumWidth(500);
	this->setWindowTitle("Nouvelle classe");

	QVBoxLayout *layout = new QVBoxLayout();

	/* Choix du nom de la classe */
	
	QHBoxLayout *h1 = new QHBoxLayout();
	QLabel *lab1 = new QLabel("Classe* ");
	name = new QLineEdit();
	h1->addWidget(lab1);
	h1->addWidget(name);

    /* Choix du (des) noms des super-classes */

	QHBoxLayout *h2 = new QHBoxLayout();
	QLabel *lab2 = new QLabel("Super-classe ");
	superClass = new QLineEdit();
	h2->addWidget(lab2);
	h2->addWidget(superClass);

    /* Choix du des nom(s) des interface(s) */

	QHBoxLayout *h3 = new QHBoxLayout();
	QLabel *lab3 = new QLabel("Interface ");
    interFace = new QLineEdit();
	h3->addWidget(lab3);
    h3->addWidget(interFace);

    /* Choix de la visibilité de la classe */


	QLabel *lab4 = new QLabel("Visibilité ");
	QHBoxLayout *h4 = new QHBoxLayout();

    QRadioButton *radio1 = new QRadioButton(tr("public"));
    QRadioButton *radio2 = new QRadioButton(tr("private"));
    QRadioButton *radio3 = new QRadioButton(tr("protected"));

    radio1->setChecked(true);

    h4->addWidget(lab4);
    h4->addWidget(radio1);
    h4->addWidget(radio2);
    h4->addWidget(radio3);

    /* main */

    QVBoxLayout *h6 = new QVBoxLayout();
    QCheckBox *main = new QCheckBox("public static void main(String[] args)", this);
    h6->addWidget(main);

    /* constructeur par défaut */

    QCheckBox *constructor = new QCheckBox("constructeur par défaut", this);
    h6->addWidget(constructor);


    QHBoxLayout *h5 = new QHBoxLayout();
	h5->setAlignment(Qt::AlignRight);
	valider = new QPushButton("Valider");
	QPushButton *annuler = new QPushButton("Annuler");
	valider->setEnabled(false);
	h5->addWidget(annuler);
	h5->addWidget(valider);

    layout->addLayout(h1);
    layout->addLayout(h2);
    layout->addLayout(h3);
    layout->addLayout(h4);
    layout->addLayout(h6);
    layout->addLayout(h5);
    this->setLayout(layout);

    connect(annuler,SIGNAL(clicked()),this,SLOT(reject()));
	connect(valider,SIGNAL(clicked()),this,SLOT(accept()));
	connect(name,SIGNAL(textChanged(QString)),this,SLOT(validate()));
}

void ClassDialog::validate(){
	if(name->text().size() > 0){
		this->valider->setEnabled(true);
	}else{
		this->valider->setEnabled(false);
	}
}
