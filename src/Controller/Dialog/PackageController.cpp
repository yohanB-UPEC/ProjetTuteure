#include "include/Controller/Dialog/PackageController.h"
#include "include/View/Dialog/PackageDialog.h"

PackageController::PackageController(PackageDialog *pkd){
    this->m_pkd = pkd;
}

/* Bouton valider uniquement clickable quand le nom du package et le choix du package ont été choisis */

void PackageController::validate(){
    if(m_pkd->name->text().size() > 0 && m_pkd->loc.size() > 0 && caracteresSpeciaux() && !isExisted()){
        QFileInfo fi(m_pkd->loc);
        if(fi.isDir() && fi.isReadable() && fi.isWritable() && !fi.dir().exists(m_pkd->name->text()))
            m_pkd->valider->setEnabled(true);
    }else{
        m_pkd->valider->setEnabled(false);
    }
}

bool PackageController::caracteresSpeciaux(){
    for(int i = 0; i < m_pkd->name->text().size(); i++){
        if(!(m_pkd->name->text().at(i).isLetterOrNumber())){
            return false;
        }
    }
    return true;
}

bool PackageController::isExisted(){
    QString pathDoss = m_pkd->path->text() + "/" + m_pkd->name->text();
    QDir dossierCree(pathDoss);
    return dossierCree.exists();
}

/* permet d'obtenir la chemin d'accès du package */

void PackageController::selectedItem(const QItemSelection &selected, const QItemSelection &deselected){
    QModelIndexList items = selected.indexes();
    m_pkd->loc = m_pkd->filemodel->filePath(items[0]);
    m_pkd->path->setText(m_pkd->loc);
}
