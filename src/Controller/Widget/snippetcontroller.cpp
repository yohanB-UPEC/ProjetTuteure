#include "include/Controller/Widget/SnippetController.h"
#include "include/View/Fenetre.h"

SnippetController::SnippetController(Snippet *sni){
    this->m_sni = sni;
}

void SnippetController::addSnippet(){
    SnippetDialog sd(m_sni->m_model);
    if(sd.exec() == QDialog::Accepted){
        qDebug() << "création du snippet";
        m_sni->m_model->addSnippet(sd.getSnippetName());
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
    QApplication::clipboard()->setText(m_sni->m_model->getText(index));
}

