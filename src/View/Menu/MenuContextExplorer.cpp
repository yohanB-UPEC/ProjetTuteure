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
        QMessageBox msg(m_fen);
        msg.setWindowTitle("suppression d'un projet");
        msg.setText("Voulez-vous supprimer le projet " + item->label()+" ?");
        msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msg.setDefaultButton(QMessageBox::No);
        QCheckBox box("supprimer le contenu du projet sur le disque",&msg);
        int res = msg.exec();
        if(res == QMessageBox::No){
            return;
        }
        deleteFiles = box.isChecked();
    }
    qDebug() << "MenuContextExplorer::s_suppr  item a supprimer: " << item->label() << " num=" << item->row() << "  path: "<< item->getPath() ;
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
