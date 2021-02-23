#include "include/View/Widget/Snippet.h"
#include "include/View/Fenetre.h"

Snippet::Snippet(Fenetre* fen, QWidget *parent): QWidget(parent), sni(this){
    this->fen = fen;
    layout = new QVBoxLayout();

    QHBoxLayout *h1 = new QHBoxLayout();
    input = new QLineEdit();
    input->setPlaceholderText("Recherchez...");
    input->setStyleSheet("border-style: outset; border-width: 2px; border-color: darkgrey; border-radius: 10px; color: black; background-color: white;");
    add = new QPushButton(DIcons::add, "");
    const QSize size = QSize(40, 40);
    add->setFixedSize(size);
    add->setStyleSheet("border: none;");

    QVBoxLayout *h2 = new QVBoxLayout();

    listWidget = new QListWidget();
    listWidget->setMouseTracking(true);
    listItems = new QListWidgetItem;

    h1->addWidget(input);
    h1->addWidget(add);
    h2->addWidget(listWidget);
    layout->addLayout(h1);
    layout->addLayout(h2);
    this->setLayout(layout);

    /* Création du dossier Snippet */

    QString path = "Snippets";
    QDir dir;
    if(dir.mkpath(path) == false){
        qDebug() << "Failed dir";
    }

    getList();
    connect(input,SIGNAL(textChanged(QString)),&sni,SLOT(isDeleted()));
    connect(add,SIGNAL(clicked()),&sni,SLOT(addSnippet()));
}

void Snippet::createDialog(){
    dial = new QDialog();
    dial->resize(400,100);
    dial->setMinimumWidth(500);
    dial->setWindowTitle("Nouveau snippet");

    QVBoxLayout *lay = new QVBoxLayout();

    QHBoxLayout *h = new QHBoxLayout();
    QLabel *lab = new QLabel("Nom ");
    nomSnippet = new QLineEdit();
    h->addWidget(lab);
    h->addWidget(nomSnippet);

    QHBoxLayout *h1 = new QHBoxLayout();
    h1->setAlignment(Qt::AlignRight);
    valider = new QPushButton("Valider");
    QPushButton *annuler = new QPushButton("Annuler");
    valider->setEnabled(false);

    h1->addWidget(annuler);
    h1->addWidget(valider);

    lay->addLayout(h);
    lay->addLayout(h1);
    dial->setLayout(lay);

    connect(annuler,SIGNAL(clicked()),dial,SLOT(reject()));
    connect(valider,SIGNAL(clicked()),dial,SLOT(accept()));
    connect(nomSnippet,SIGNAL(textChanged(QString)),&sni,SLOT(validate(QString)));
    dial->exec();
}

void Snippet::getList(){
    QDirIterator it("Snippets");
    while(it.hasNext()){
        QFile file(it.next());
        QFileInfo info(file);
        QString filename = info.baseName();
        if(filename != ""){
            addToList(filename);
        }
    }
}

bool Snippet::caracteresSpeciaux(QString nomSnippet){
    for(int i = 0; i < nomSnippet.size(); i++){
        if(!(nomSnippet.at(i).isLetterOrNumber())){
            return false;
        }
    }
    return true;
}

void Snippet::addToList(QString snippetname){
    QListWidgetItem *listWItems = new QListWidgetItem;
    dlistItem = new DSnippetItem(snippetname, listWItems);
    listWItems->setSizeHint(dlistItem->sizeHint());
    listWidget->addItem(listWItems);
    listWidget->setItemWidget(listWItems, dlistItem);

    connect(dlistItem,SIGNAL(sig(QString)),&sni,SLOT(copyFile(QString)));
    connect(dlistItem,SIGNAL(sig_modify(QString)),&sni,SLOT(modifyFile(QString)));
    connect(dlistItem,SIGNAL(sig_delete(QString)),&sni,SLOT(deleteFile(QString)));
}
