#include "include/View/Widget/Snippet.h"
#include "include/View/Fenetre.h"

Snippet::Snippet(Fenetre* fen, QWidget *parent): QWidget(parent){
    this->fen = fen;
    layout = new QVBoxLayout();

    QHBoxLayout *h1 = new QHBoxLayout();
    input = new QLineEdit();
    input->setPlaceholderText("Recherchez...");
    input->setStyleSheet("border-style: outset; border-width: 2px; border-color: darkgrey; border-radius: 10px; color: black;");
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
    connect(input,SIGNAL(textChanged(QString)),this,SLOT(isDeleted()));
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
        if(filename != ""){
            addToList(filename);
        }
    }
}

void Snippet::addSnippet(){
    createDialog();
    if(nomSnippet->text().size() == 0) return;
    QFile file("Snippets/" + nomSnippet->text() + ".java");
    if(!file.open(QIODevice::ReadWrite | QIODevice::Truncate)){
        qDebug() << "file failed" << file.errorString();
    }
    addToList(nomSnippet->text());
}

void Snippet::addToList(QString snippetname){
    QListWidgetItem *listWItems = new QListWidgetItem;
    DSnippetItem *dlistItem = new DSnippetItem(snippetname, listWItems);
    listWItems->setSizeHint(dlistItem->sizeHint());
    listWidget->addItem(listWItems);
    listWidget->setItemWidget(listWItems, dlistItem);

    connect(dlistItem,SIGNAL(sig(QString)),this,SLOT(copyFile(QString)));
    connect(dlistItem,SIGNAL(sig_modify(QString)),this,SLOT(modifyFile(QString)));
    connect(dlistItem,SIGNAL(sig_delete(QString)),this,SLOT(deleteFile(QString)));
}

void Snippet::copyFile(QString name){
    QFile file("Snippets/" + name + ".java");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        for(int i = 0; i < listWidget->count(); i++){
            QListWidgetItem *item = listWidget->item(i);
            QString nom = ((DSnippetItem*) listWidget->itemWidget(item))->getNomSnippet()->text();
            if(name == nom){
                item->setHidden(true);
            }
        }
        QMessageBox msgBox(QMessageBox::Critical, "Fichier inexistant", "Le fichier est introuvable");
        msgBox.setText("Le fichier n'existe pas");
        msgBox.exec();
        return;
    }
    QTextStream flux(&file);
    QString content = flux.readAll();
    DCodeEditor *editor = new DCodeEditor();
    editor->appendPlainText(content);
    editor->selectAll();
    editor->copy();
    QMessageBox msgBox(QMessageBox::Information, "fichier copié", "fichier copié");
    msgBox.exec();
}

void Snippet::modifyFile(QString name){
    DCodeEditor *editor = new DCodeEditor();
    int i = 0;
    for(; i < this->fen->getCentral()->count(); i++){
        if(this->fen->getCentral()->tabText(i) == (name + ".java")){
            this->fen->getCentral()->setCurrentWidget(this->fen->getCentral()->widget(i));
            return;
        }
    }
    this->fen->getCentral()->addTab(editor, name + ".java");
    this->fen->getCentral()->setCurrentWidget(this->fen->getCentral()->widget(i));
    QFile file("Snippets/" + name + ".java");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        for(int i = 0; i < listWidget->count(); i++){
            QListWidgetItem *item = listWidget->item(i);
            QString nom = ((DSnippetItem*) listWidget->itemWidget(item))->getNomSnippet()->text();
            if(name == nom){
                item->setHidden(true);
            }
        }
        QMessageBox msgBox(QMessageBox::Critical, "Fichier inexistant", "Le fichier est introuvable");
        msgBox.setText("Le fichier n'existe pas");
        msgBox.exec();
        return;
    }
    QTextStream flux(&file);
    editor->appendPlainText(flux.readAll());
}

void Snippet::deleteFile(QString name){
    QDirIterator it("Snippets");
    while(it.hasNext()){
        QFile file(it.next());
        QFileInfo info(file);
        QString filename = info.baseName();
        if(filename == name){
            qDebug() << name;
            file.remove();
            for(int i = 0; i < listWidget->count(); i++){
                QListWidgetItem *item = listWidget->item(i);
                item->setHidden(true);
            }
            getList();
            return;
        }
    }
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

void Snippet::isDeleted(){
    for(int i = 0; i < listWidget->count(); i++){
        QListWidgetItem *item = listWidget->item(i);
        QString nom = ((DSnippetItem*) listWidget->itemWidget(item))->getNomSnippet()->text();
        if(!(nom.contains(input->text(), Qt::CaseInsensitive)))
            item->setHidden(true);
        else
            item->setHidden(false);
    }
}
