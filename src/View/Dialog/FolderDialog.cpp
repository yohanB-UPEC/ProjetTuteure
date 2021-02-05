#include "include/View/Dialog/FolderDialog.h"

FolderDialog::FolderDialog(QWidget *parent): QDialog(parent){
    this->resize(600,100);
    this->setMinimumWidth(500);
    this->setWindowTitle("Création de dossier");

    QVBoxLayout *layout = new QVBoxLayout();

    QHBoxLayout *h1 = new QHBoxLayout();
    QLabel *lab1 = new QLabel("Nom du dossier: ");
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
    layout->addItem(si);
    layout->addLayout(h4);
    this->setLayout(layout);


    connect(browse,SIGNAL(clicked()),this,SLOT(parcourir()));
    connect(annuler,SIGNAL(clicked()),this,SLOT(reject()));
    connect(valider,SIGNAL(clicked()),this,SLOT(accept()));
    connect(name,SIGNAL(textChanged(QString)),this,SLOT(validate()));
    connect(loc,SIGNAL(textChanged(QString)),this,SLOT(validate()));
}

void FolderDialog::parcourir(){
    QString dir = QFileDialog::getExistingDirectory(this, tr("Selectionne un dossier"),"./",QFileDialog::ShowDirsOnly);
    if(dir.size() > 0){
        this->loc->setText(dir);
    }
}
void FolderDialog::validate(){
    if(name->text().size() > 0 && loc->text().size() > 0){
        this->valider->setEnabled(true);
    }else{
        this->valider->setEnabled(false);
    }
}
