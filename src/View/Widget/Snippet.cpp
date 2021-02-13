#include "include/View/Widget/Snippet.h"

Snippet::Snippet(QWidget *parent): QWidget(parent){

    layout = new QVBoxLayout();

    QHBoxLayout *h1 = new QHBoxLayout();
    input = new QLineEdit();
    input->setPlaceholderText("Recherchez...");
    input->setStyleSheet("border-style: outset; border-width: 2px; border-color: darkgrey; border-radius: 10px;");
    add = new QPushButton("+");
    const QSize size = QSize(20, 20);
    add->setFixedSize(size);
    add->setStyleSheet("background: blue; border-style: outset; border-radius: 10px; color: white; font: bold 20px;");

    QVBoxLayout *h2 = new QVBoxLayout();

    listWidget = new QListWidget();
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

    //connect(input,SIGNAL(textChanged(QString)),this,SLOT(searchSnippet()));
    connect(add,SIGNAL(clicked()),this,SLOT(addSnippet()));
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
    connect(nomSnippet,SIGNAL(textChanged(QString)),this,SLOT(validate(QString)));
    dial->exec();
}

void Snippet::getList(){
    QDirIterator it("Snippets");
    while(it.hasNext()){
        QFile file(it.next());
        QFileInfo info(file);
        QString filename = info.baseName();
        if(filename != "")
            addToList(filename);
    }
}

void Snippet::addSnippet(){
    createDialog();
    QFile file("Snippets/" + nomSnippet->text() + ".java");
    if(!file.open(QIODevice::ReadWrite | QIODevice::Truncate)){
        qDebug() << "file failed" << file.errorString();
    }
    addToList(nomSnippet->text());
}

void Snippet::addToList(QString snippetname){
    QWidget* widget = new QWidget();
    QHBoxLayout* h3 = new QHBoxLayout(widget);
    QLabel* lab = new QLabel(snippetname);
    QPushButton* copy = new QPushButton("Copier");
    QPushButton* modif = new QPushButton("Modifier");

    h3->addWidget(lab);
    h3->addWidget(copy);
    h3->addWidget(modif);

    widget->setLayout(h3);

    listItems = new QListWidgetItem;
    listItems->setSizeHint(widget->sizeHint());
    listWidget->addItem(listItems);
    listWidget->setItemWidget(listItems, widget);
}

void Snippet::validate(QString nomSnippet){
    if(nomSnippet.size() > 0 && caracteresSpeciaux(nomSnippet))
        valider->setEnabled(true);
    else
        valider->setEnabled(false);
}

bool Snippet::caracteresSpeciaux(QString nomSnippet){
    for(int i = 0; i < nomSnippet.size(); i++){
        if(!(nomSnippet.at(i).isLetterOrNumber())){
            return false;
        }
    }
    return true;
}

void Snippet::searchSnippet(){
    qDebug() << "input = " << input->text();
    qDebug() << "nbSnippets = " << listWidget->count();
    QListWidgetItem *item = listWidget->currentItem();
    if(item)
        qDebug() << "snippet = " << item->text();
    else qDebug() << "FDP";
}
