#include "include/View/Dialog/FolderDialog.h"

FolderDialog::FolderDialog(QWidget *parent, Model *model,QFlags<Javora::ModelType> type): QDialog(parent), fd(model,this), m_type(type){
    this->resize(600,300);
    this->setMinimumWidth(500);
    if(m_type.testFlag(Javora::Folder)){
        this->setWindowTitle("Création d'un dossier");
    }else if(m_type.testFlag(Javora::SourceFolder)){
        this->setWindowTitle("Création d'un dossier de code source");
    }else{
        this->setWindowTitle("Error, type inconnue");
        return;
    }

    QVBoxLayout *layout = new QVBoxLayout();


    tree = new QTreeView;
    tree->setHeaderHidden(true);
    if(m_type.testFlag(Javora::Folder)){
        fm = new FilteredModel(Javora::Project | Javora::Folder);
    }else{
        fm = new FilteredModel(Javora::Project);
    }
    fm->setSourceModel(model);
    tree->setModel(fm);
    layout->addWidget(tree);

    QHBoxLayout *h1 = new QHBoxLayout();
    QLabel *lab1 = new QLabel("Emplacement: ");
    loc = new QLineEdit();
    loc->setEnabled(false);
    h1->addWidget(lab1);
    h1->addWidget(loc);
    layout->addLayout(h1);


    QHBoxLayout *h2 = new QHBoxLayout();
    QLabel *lab2 = new QLabel("Nom du dossier: ");
    name = new QLineEdit();
    h2->addWidget(lab2);
    h2->addWidget(name);
    layout->addLayout(h2);




    QHBoxLayout *h4 = new QHBoxLayout();
    h4->setAlignment(Qt::AlignRight);
    valider = new QPushButton("Valider");
    QPushButton *annuler = new QPushButton("Annuler");
    valider->setEnabled(false);
    h4->addWidget(annuler);
    h4->addWidget(valider);

    layout->addLayout(h4);
    this->setLayout(layout);


    connect(annuler,SIGNAL(clicked()),this,SLOT(reject()));
    connect(valider,SIGNAL(clicked()),&fd,SLOT(createFolder()));
    connect(name,SIGNAL(textChanged(QString)),&fd,SLOT(validate()));
    connect(tree->selectionModel(), SIGNAL(selectionChanged(const QItemSelection&, const QItemSelection&)), &fd, SLOT(selectedItem(const QItemSelection&, const QItemSelection&)));
}
