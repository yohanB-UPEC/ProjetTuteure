#include "include/Controller/Dialog/EnumController.h"
#include "include/View/Dialog/EnumDialog.h"

EnumController::EnumController(EnumDialog *ed){
    this->m_ed = ed;
}

void EnumController::validate(){
    if(m_ed->name->text().size() > 0 && m_ed->loc->text().size() > 0 && m_ed->loc2->text().size() > 0 && caracteresSpeciaux() && !isExisted()){
        QFileInfo fiIf(m_ed->loc->text());
        QFileInfo fiDoss(m_ed->loc2->text());
        if(fiDoss.isDir() && fiDoss.isReadable() && fiDoss.isWritable() && !fiDoss.dir().exists(m_ed->name->text()) && fiIf.isDir() && fiIf.isReadable() && fiIf.isWritable()){
            m_ed->valider->setEnabled(true);
        }
    }else{
        m_ed->valider->setEnabled(false);
    }
}

bool EnumController::caracteresSpeciaux(){
    for(int i = 0; i < m_ed->name->text().size(); i++){
        if(!(m_ed->name->text().at(i).isLetterOrNumber())){
            return false;
        }
    }
    return true;
}

bool EnumController::isExisted(){
    QDir dossierPkg(m_ed->loc->text());
    QDir dossier(m_ed->loc2->text());
    if(!dossier.exists() || !dossierPkg.exists()) return true;
    return dossier.exists(m_ed->name->text().append(".java"));
}

void EnumController::parcourir(){
    QString dir = QFileDialog::getExistingDirectory(m_ed, tr("Selectionne un dossier"),"./",QFileDialog::ShowDirsOnly);
    if(dir.size() > 0){
        m_ed->loc->setText(dir);
    }
}

void EnumController::parcourir2(){
    QString dir = QFileDialog::getExistingDirectory(m_ed, tr("Selectionne un dossier"),"./",QFileDialog::ShowDirsOnly);
    if(dir.size() > 0){
        m_ed->loc2->setText(dir);
    }
}
