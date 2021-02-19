#include "include/View/Menu/MenuContextExplorer.h"
#include "include/View/Fenetre.h"

MenuContextExplorer::MenuContextExplorer(QModelIndex item, Model *model, Fenetre *fen): m_item(item), m_model(model), m_fen(fen){
    QAction* newf = this->addAction("New");
    newf->setMenu(fen->getMenuFile()->getMenuNew());
    this->addSeparator();
    this->addAction("Copier");
    this->addAction("Coller");
    this->addAction("Supprimer");
    this->addAction("Renommer",this,SLOT(s_rename()));
    this->addSeparator();
    this->addAction("Importer");
    this->addAction("Exporter");
    this->addSeparator();
    this->addAction("Lancer");
    this->addAction("Compiler");
    this->addAction("Générer Makefile");


}

void MenuContextExplorer::s_rename(){
    m_fen->getExplorer()->edit(m_item);
}
