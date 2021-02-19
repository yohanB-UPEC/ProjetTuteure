#include "include/Controller/Dialog/ClassController.h"
#include "include/View/Dialog/ClassDialog.h"

ClassController::ClassController(Model *model, ClassDialog *clc){
	this->m_clc = clc;
    this->m_model = model;
}

void ClassController::validate(){
    if(name == true && m_clc->loc->text().size() > 0){
        m_clc->valider->setEnabled(true);
        return;
    }
    m_clc->valider->setEnabled(false);
}

void ClassController::selectLocation(const QItemSelection& selected, const QItemSelection& deselected){
    QModelIndex index = m_clc->fm->mapToSource(selected.indexes()[0]);
    if(!index.isValid()){
        m_clc->diaV->setEnabled(false);
        return;
    }
    TreeItem *next = (TreeItem*)index.internalPointer();
    if(typeid(*next) == typeid(DPackage)){
        m_clc->diaV->setEnabled(true);
    }else{
        m_clc->diaV->setEnabled(false);
    }
    m_chemintmp = index;
}

void ClassController::validateLocation(){
    TreeItem *next = (TreeItem*)m_chemintmp.internalPointer();
    QString path = m_model->getRelativePath(next);
    m_clc->loc->setText(path);
    m_chemin = m_chemintmp;
    validate();
    m_clc->locDia.accept();
}

void ClassController::validateName(const QString &text){
    QRegularExpression reg("^[A-Z][A-Za-z0-9]*$");
    if(reg.match(text).hasMatch()){
        name=true;
        m_clc->name->setStyleSheet("border: 1px solid black");
    }else{
        name=false;
        m_clc->name->setStyleSheet("border: 1px solid red");
    }
    validate();
}

void ClassController::createClass(){
    DJavaFile *file = new DJavaFile(m_clc->name->text()+".java");
    DClass *c = new DClass(m_clc->name->text());
    if(m_clc->radioMod->checkedId() == 0){
        c->setScope("public");
        file->setPublicClass(c);
    }else{
        file->addClass(c);
    }
    qDebug() << "etape 1";
    if(m_clc->m_type == Javora::Class){
        if(m_clc->abstract->isChecked()){
            c->setAbstract(true);
        }
        if(m_clc->final->isChecked()){
            c->setFinal(true);
        }
        c->setType("class");
        if(m_clc->main->isChecked()){
            DMethod *main = new DMethod("main","public","void");
            main->setStatic(true);
            main->addParametre("String[]","args");
            c->methods().push_back(main);
        }
    }else if(m_clc->m_type == Javora::Interface){
        c->setType("interface");
    }else{
        c->setType("enum");
    }

    if(!m_chemin.isValid()){
        m_chemin = m_model->getItem(m_clc->loc->text());
    }
    m_model->insertRow(9999,file,m_chemin);
    file->create();
    m_clc->accept();

}
