#include "include/View/Dialog/SnippetDialog.h"

SnippetDialog::SnippetDialog(SnippetModel *model): m_model(model){
    this->resize(400,100);
    this->setMinimumWidth(500);
    this->setWindowTitle("Nouveau snippet");

    QVBoxLayout *lay = new QVBoxLayout();

    QHBoxLayout *h = new QHBoxLayout();
    QLabel *lab = new QLabel("Nom ");
    m_name = new QLineEdit();
    h->addWidget(lab);
    h->addWidget(m_name);

    QHBoxLayout *h1 = new QHBoxLayout();
    h1->setAlignment(Qt::AlignRight);
    valider = new QPushButton("Valider");
    QPushButton *annuler = new QPushButton("Annuler");
    valider->setEnabled(false);

    h1->addWidget(annuler);
    h1->addWidget(valider);

    lay->addLayout(h);
    lay->addLayout(h1);
    this->setLayout(lay);

    connect(annuler,SIGNAL(clicked()),this,SLOT(reject()));
    connect(valider,SIGNAL(clicked()),this,SLOT(accept()));
    connect(m_name,SIGNAL(textChanged(QString)),this,SLOT(validate(QString)));
}

void SnippetDialog::validate(QString name){
    if(name.size() > 0 && !this->m_model->exist(name)){
        this->valider->setEnabled(true);
    }else{
        this->valider->setEnabled(false);
    }
}

const QString SnippetDialog::getSnippetName(){
    return this->m_name->text();
}
