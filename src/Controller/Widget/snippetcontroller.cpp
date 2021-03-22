#include "include/Controller/Widget/SnippetController.h"
#include "include/View/Fenetre.h"

SnippetController::SnippetController(Snippet *sni){
    this->m_sni = sni;
}

void SnippetController::addSnippet(){
    SnippetModel *model=(SnippetModel*)m_sni->m_model->sourceModel();
    SnippetDialog sd(model);
    if(sd.exec() == QDialog::Accepted){
        qDebug() << "création du snippet";
        model->addSnippet(sd.getSnippetName());
    }
}

void SnippetController::modifyFile(const QModelIndex &index){
    m_sni->m_fen->getController()->openEditor(QCoreApplication::applicationDirPath()+"/Snippets/" + m_sni->m_model->data(index,Qt::DisplayRole).toString() + ".java");
}

void SnippetController::removeSnippet(const QModelIndex &index){
    int res = QMessageBox::question(m_sni,"Supprimer le snippet","Voulez-vous vraiment supprimer le Snippet "+m_sni->m_model->data(index,Qt::DisplayRole).toString()+" ?");
    if(res == QMessageBox::Yes){
        qDebug() << "supprimer le snippet";
        m_sni->m_model->removeRows(index.row(),1);
    }
}

void SnippetController::copySnippet(const QModelIndex &index){
    qDebug() << "copy du snippet";
    QApplication::clipboard()->setText(((SnippetModel*)m_sni->m_model->sourceModel())->getText(index));
}

void SnippetController::filtre(const QString& pattern){
    m_sni->m_model->setFilterFixedString(pattern);
}
