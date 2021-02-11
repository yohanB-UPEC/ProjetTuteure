#include "include/Controller/Dialog/SrcFolderController.h"
#include "include/View/Dialog/SrcFolderDialog.h"

SrcFolderController::SrcFolderController(SrcFolderDialog *sfd){
    this->m_sfd = sfd;
}

void SrcFolderController::validate(){
    if(m_sfd->name->text().size() > 0 && m_sfd->name->text().size() > 0){
        QFileInfo fi(m_sfd->loc->text());
        if(fi.isDir() && fi.isReadable() && fi.isWritable() && !fi.dir().exists(m_sfd->name->text()) && caracteresSpeciaux() && !isExisted()){
            m_sfd->valider->setEnabled(true);
            return;
        }
    }
    m_sfd->valider->setEnabled(false);
}

bool SrcFolderController::caracteresSpeciaux(){
    for(int i = 0; i < m_sfd->name->text().size(); i++){
        if(!(m_sfd->name->text().at(i).isLetterOrNumber())){
            return false;
        }
    }
    return true;
}

bool SrcFolderController::isExisted(){
    QDir dossier(m_sfd->loc->text());
    return dossier.exists(((QString)m_sfd->name->text()));
}

void SrcFolderController::parcourir(){
    QString dir = QFileDialog::getExistingDirectory(m_sfd, tr("Selectionne un dossier"),"./",QFileDialog::ShowDirsOnly);
    if(dir.size() > 0){
        m_sfd->loc->setText(dir);
    }
}
