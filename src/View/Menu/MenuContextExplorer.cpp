#include "include/View/Menu/MenuContextExplorer.h"
#include "include/View/Fenetre.h"

MenuContextExplorer::MenuContextExplorer(QModelIndex item, Model *model, Fenetre *fen): m_item(item), m_model(model), m_fen(fen){
    QAction* newf = this->addAction("New");
    newf->setMenu(fen->getMenuFile()->getMenuNew());
    this->addSeparator();
    this->addAction("Copier");
    this->addAction("Coller");
    this->addAction("Supprimer",this,SLOT(s_suppr()));
    this->addAction("Renommer",this,SLOT(s_rename()));
    this->addSeparator();
    this->addAction("Importer");
    this->addAction("Exporter");
    this->addSeparator();
    this->addAction("Lancer");
    this->addAction("Compiler");
    this->addAction("Générer Makefile",this,SLOT(s_makefile()));


}

void MenuContextExplorer::s_rename(){
    m_fen->getExplorer()->edit(m_item);
}
void MenuContextExplorer::s_suppr(){
    TreeItem *item = (TreeItem*)this->m_item.internalPointer();
    bool deleteFiles=true;
    if(typeid(*item) == typeid(DProject)){
        QuestionDialog dial("supression d'un projet", "Voulez-vous supprimer le projet " + item->label()+" ?","supprimer le contenu du projet sur le disque",m_fen);
        QPushButton *yes = new QPushButton("Oui");
        QPushButton *no = new QPushButton("Non");
        connect(yes,SIGNAL(clicked()),&dial,SLOT(accept()));
        connect(no,SIGNAL(clicked()),&dial,SLOT(reject()));
        dial.getButtonLayout()->addWidget(no);
        dial.getButtonLayout()->addWidget(yes);
        int res = dial.exec();
        if(res == 0){
            return;
        }
        deleteFiles = dial.isChecked();
    }
    m_model->removeRows(item->row(),1,m_item.parent(),deleteFiles);
}

void MenuContextExplorer::s_makefile(){
    TreeItem *item = (TreeItem*)m_item.internalPointer();
    while(typeid(*item) != typeid(DProject)){
        item = item->parent();
    }
    qDebug() << "début le la creation du makefile";
    ((DProject*)item)->createMakefile();
}
