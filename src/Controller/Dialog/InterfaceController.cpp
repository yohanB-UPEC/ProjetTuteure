#include "include/Controller/Dialog/InterfaceController.h"
#include "include/View/Dialog/InterfaceDialog.h"

InterfaceController::InterfaceController(InterfaceDialog *ifd){
    this->m_ifd = ifd;
}

void InterfaceController::validate(){
    if(m_ifd->name->text().size() > 0 && m_ifd->loc->text().size() > 0 && m_ifd->loc2->text().size() > 0 && caracteresSpeciaux() && !isExisted()){
        QFileInfo fiIf(m_ifd->loc->text());
        QFileInfo fiDoss(m_ifd->loc2->text());
        if(fiDoss.isDir() && fiDoss.isReadable() && fiDoss.isWritable() && !fiDoss.dir().exists(m_ifd->name->text()) && fiIf.isDir() && fiIf.isReadable() && fiIf.isWritable()){
            m_ifd->valider->setEnabled(true);
        }
    }else{
        m_ifd->valider->setEnabled(false);
    }
}

bool InterfaceController::caracteresSpeciaux(){
    for(int i = 0; i < m_ifd->name->text().size(); i++){
        if(!(m_ifd->name->text().at(i).isLetterOrNumber())){
            return false;
        }
    }
    return true;
}

bool InterfaceController::isExisted(){
    QDir dossierPkg(m_ifd->loc->text());
    QDir dossier(m_ifd->loc2->text());
    if(!dossier.exists() || !dossierPkg.exists()) return true;
    return dossier.exists(m_ifd->name->text().append(".java"));
}

void InterfaceController::parcourir(){
    QString dir = QFileDialog::getExistingDirectory(m_ifd, tr("Selectionne un dossier"),"./",QFileDialog::ShowDirsOnly);
    if(dir.size() > 0){
        m_ifd->loc->setText(dir);
    }
}

void InterfaceController::parcourir2(){
    QString dir = QFileDialog::getExistingDirectory(m_ifd, tr("Selectionne un dossier"),"./",QFileDialog::ShowDirsOnly);
    if(dir.size() > 0){
        m_ifd->loc2->setText(dir);
    }
}
