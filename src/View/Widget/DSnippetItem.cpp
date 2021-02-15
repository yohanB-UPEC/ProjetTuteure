#include "include/View/Widget/DSnippetItem.h"

DSnippetItem::DSnippetItem(QString nomLab, QListWidgetItem *item, QWidget *parent): QWidget(parent){

    copy = new QPushButton("Copier");
    modifier = new QPushButton("Modifier");
    nomSnippet = new QLabel(nomLab);
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(nomSnippet);
    layout->addWidget(copy);
    layout->addWidget(modifier);
    this->setLayout(layout);
    connect(copy, SIGNAL(clicked()), this, SLOT(copy_snippet()));
    connect(modifier, SIGNAL(clicked()), this, SLOT(modify_snippet()));
}

QPushButton *DSnippetItem::getCopy(){
    return copy;
}

QPushButton *DSnippetItem::getModifier(){
    return modifier;
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
