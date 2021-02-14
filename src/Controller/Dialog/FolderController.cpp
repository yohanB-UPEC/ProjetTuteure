#include "include/Controller/Dialog/FolderController.h"
#include "include/View/Dialog/FolderDialog.h"

FolderController::FolderController(FolderDialog *fd){
    this->m_fd = fd;
}

void FolderController::validate(){
    if(m_fd->name->text().size() > 0 && m_fd->name->text().size() > 0){
        QFileInfo fi(m_fd->loc->text());
        if(fi.isDir() && fi.isReadable() && fi.isWritable() && !fi.dir().exists(m_fd->name->text()) && caracteresSpeciaux() && !isExisted()){
            m_fd->valider->setEnabled(true);
            return;
        }
    }
    m_fd->valider->setEnabled(false);
}

bool FolderController::caracteresSpeciaux(){
    for(int i = 0; i < m_fd->name->text().size(); i++){
        if(!(m_fd->name->text().at(i).isLetterOrNumber())){
            return false;
        }
    }
    return true;
}

bool FolderController::isExisted(){
    QDir dossier(m_fd->loc->text());
    return dossier.exists(((QString)m_fd->name->text()));
}

void FolderController::parcourir(){
    QString dir = QFileDialog::getExistingDirectory(m_fd, tr("Selectionne un dossier"),"./",QFileDialog::ShowDirsOnly);
    if(dir.size() > 0){
        m_fd->loc->setText(dir);
    }
}
