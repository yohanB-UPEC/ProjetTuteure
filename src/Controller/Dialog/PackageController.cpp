#include "include/Controller/Dialog/PackageController.h"
#include "include/View/Dialog/PackageDialog.h"

PackageController::PackageController(Model *model, PackageDialog *pkd){
    this->m_pkd = pkd;
	this->m_model = model;
}

/* Bouton valider uniquement clickable quand le nom du package et le choix du package ont été choisis */

void PackageController::validate(){
    if(m_pkd->name->text().size() > 0 && m_pkd->path->text().size() > 0){
            TreeItem * tmp = (TreeItem*)m_chemin.internalPointer();
            if(typeid(*tmp) == typeid(DSourceFolder)){
                m_pkd->valider->setEnabled(true);
                return;
            }
    }
    m_pkd->valider->setEnabled(false);
}


/* permet d'obtenir la chemin d'accès du package */

void PackageController::selectedItem(const QItemSelection& selected, const QItemSelection& deselected){
    QModelIndex index = m_pkd->fm->mapToSource(selected.indexes()[0]);
    if(!index.isValid()){
        return;
    }
    TreeItem *next = (TreeItem*)index.internalPointer();
    QString path = m_model->getRelativePath(next);
    m_pkd->path->setText(path);
    m_chemin = index;
    validate();
}

void PackageController::createPackage(){
    DPackage *p = new DPackage(m_pkd->name->text());
    m_model->insertRow(9999,p,m_chemin);
    p->create();
    m_pkd->accept();
}
