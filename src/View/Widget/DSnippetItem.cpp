#include "include/View/Widget/DSnippetItem.h"

DSnippetItem::DSnippetItem(QString nomLab, QListWidgetItem *item, QWidget *parent): QWidget(parent){

    QIcon addI("res/icons/copy.png");
    copy = new QPushButton(addI, "");
    const QSize size = QSize(40, 40);
    copy->setFixedSize(size);
    copy->setToolTip("Copie le contenu du fichier");

    QIcon addIc("res/icons/modify.png");
    modifier = new QPushButton(addIc, "");
    const QSize size2 = QSize(40, 40);
    modifier->setFixedSize(size2);
    modifier->setToolTip("Modifie le contenu du fichier");

    nomSnippet = new QLabel(nomLab);
    nomSnippet->setStyleSheet("font-size: 15px;");
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
