#include "include/View/Widget/DSnippetItem.h"

DSnippetItem::DSnippetItem(QString nomLab, QListWidgetItem *item, QWidget *parent): QWidget(parent){

    copy = new QPushButton(DIcons::copy, "");
    const QSize size = QSize(40, 40);
    copy->setFixedSize(size);
    copy->setToolTip("Copie le contenu du fichier");

    modifier = new QPushButton(DIcons::modify, "");
    modifier->setFixedSize(size);
    modifier->setToolTip("Modifie le contenu du fichier");

    del = new QPushButton(DIcons::remove, "");
    del->setFixedSize(size);
    del->setToolTip("Supprime le snippet");

    nomSnippet = new QLabel(nomLab);
    nomSnippet->setStyleSheet("font-size: 15px;");
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(nomSnippet);
    layout->addWidget(copy);
    layout->addWidget(modifier);
    layout->addWidget(del);
    this->setLayout(layout);
    connect(copy, SIGNAL(clicked()), this, SLOT(copy_snippet()));
    connect(modifier, SIGNAL(clicked()), this, SLOT(modify_snippet()));
    connect(del, SIGNAL(clicked()), this, SLOT(delete_snippet()));
}

QPushButton *DSnippetItem::getCopy(){
    return copy;
}

QPushButton *DSnippetItem::getModifier(){
    return modifier;
}

QPushButton *DSnippetItem::getDel(){
    return del;
}

QLabel *DSnippetItem::getNomSnippet(){
    return nomSnippet;
}

void DSnippetItem::copy_snippet(){
    emit sig(nomSnippet->text());
}

void DSnippetItem::modify_snippet(){
    emit sig_modify(nomSnippet->text());
}

void DSnippetItem::delete_snippet(){
    emit sig_delete(nomSnippet->text());
}
