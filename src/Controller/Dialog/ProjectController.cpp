#include "include/Controller/Dialog/ProjectController.h"
#include "include/View/Dialog/ProjectDialog.h"

ProjectController::ProjectController(Model *model, ProjectDialog *dial){
	this->m_model = model;
	this->m_dial = dial;
}

void ProjectController::parcourir(){	
	QString dir = QFileDialog::getExistingDirectory(m_dial, tr("Selectionne un dossier"),"./",QFileDialog::ShowDirsOnly);
	if(dir.size() > 0){
		m_dial->loc->setText(dir);
	}
}
void ProjectController::validate(){
	if(m_dial->getName().size() > 0 && m_dial->getLocation().size() > 0){
		QFileInfo fi(m_dial->getLocation());
		if(fi.isDir() && fi.isReadable() && fi.isWritable() && !fi.dir().exists(m_dial->getName())){
			m_dial->valider->setEnabled(true);
			return;
		}
	}
	m_dial->valider->setEnabled(false);
}

void ProjectController::createProject(){
	DProject *projet = new DProject(m_dial->getName());
	DSourceFolder *sf = new DSourceFolder("src");
	DFolder *f = new DFolder("res");
	TreeItem *makefile = new TreeItem("Makefile");
	projet->appendChild(sf);
	projet->appendChild(f);
	projet->appendChild(makefile);
	m_model->insertRow(9999,projet);
	m_dial->accept();
}