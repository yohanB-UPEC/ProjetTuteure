#include "include/Controller/Dialog/FolderController.h"
#include "include/View/Dialog/FolderDialog.h"

FolderController::FolderController(Model *model, FolderDialog *fd){
    this->m_fd = fd;
    this->m_model = model;
}

void FolderController::validate(){
    if(m_fd->name->text().size() > 0 && m_fd->name->text().size() > 0){
        TreeItem * tmp = (TreeItem*)m_chemin.internalPointer();
        if((typeid(*tmp) == typeid(DProject) && m_fd->m_type.testFlag(Javora::SourceFolder)) || ((typeid(*tmp) == typeid(DProject) || typeid(*tmp) == typeid(DFolder)) && m_fd->m_type.testFlag(Javora::Folder))){
            m_fd->valider->setEnabled(true);
            return;
        }
    }
    m_fd->valider->setEnabled(false);
}

void FolderController::selectedItem(const QItemSelection& selected, const QItemSelection& deselected){
    QModelIndex index = m_fd->fm->mapToSource(selected.indexes()[0]);
    if(!index.isValid()){
        return;
    }
    TreeItem *next = (TreeItem*)index.internalPointer();
    QString path = m_model->getRelativePath(next);
    m_fd->loc->setText(path);
    m_chemin = index;
    validate();
}

void FolderController::createFolder(){
    DFolder *f;
    if(m_fd->m_type.testFlag(Javora::SourceFolder)){
        f = new DSourceFolder(m_fd->name->text());
    }else{
        f = new DFolder(m_fd->name->text());
    }
    m_model->insertRow(9999,f,m_chemin);
    f->create();
    m_fd->accept();
}
