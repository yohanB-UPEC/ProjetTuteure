#include "include/Controller/Dialog/ClassController.h"
#include "include/View/Dialog/ClassDialog.h"

ClassController::ClassController(ClassDialog *clc){
	this->m_clc = clc;
}

void ClassController::validate(){
    if(m_clc->name->text().size() > 0 && m_clc->loc->text().size() > 0 && m_clc->loc2->text().size() > 0 && caracteresSpeciaux() && !isExisted()){
        QFileInfo fiPkg(m_clc->loc->text());
        QFileInfo fiDoss(m_clc->loc2->text());
        if(fiDoss.isDir() && fiDoss.isReadable() && fiDoss.isWritable() && !fiDoss.dir().exists(m_clc->name->text()) && fiPkg.isDir() && fiPkg.isReadable() && fiPkg.isWritable()){
            m_clc->valider->setEnabled(true);
        }
    }else{
        m_clc->valider->setEnabled(false);
    }
}

bool ClassController::caracteresSpeciaux(){
	for(int i = 0; i < m_clc->name->text().size(); i++){
		if(!(m_clc->name->text().at(i).isLetterOrNumber())){
			return false;
		}
	}
	return true;
}

bool ClassController::isExisted(){
    QDir dossierPkg(m_clc->loc->text());
	QDir dossier(m_clc->loc2->text());
    if(!dossier.exists() || !dossierPkg.exists()) return true;
	return dossier.exists(m_clc->name->text().append(".java"));
}

void ClassController::parcourir(){
    QString dir = QFileDialog::getExistingDirectory(m_clc, tr("Selectionne un dossier"),"./",QFileDialog::ShowDirsOnly);
    if(dir.size() > 0){
        m_clc->loc->setText(dir);
    }
}

void ClassController::parcourir2(){
    QString dir = QFileDialog::getExistingDirectory(m_clc, tr("Selectionne un dossier"),"./",QFileDialog::ShowDirsOnly);
    if(dir.size() > 0){
        m_clc->loc2->setText(dir);
    }
}
