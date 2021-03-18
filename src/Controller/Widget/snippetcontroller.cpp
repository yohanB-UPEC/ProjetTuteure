#include "include/Controller/Widget/SnippetController.h"
#include "include/View/Fenetre.h"
/*
SnippetController::SnippetController(Snippet *sni){
    this->m_sni = sni;
}

void SnippetController::addSnippet(){
    m_sni->createDialog();
    if(m_sni->nomSnippet->text().size() == 0) return;
    QFile file(QCoreApplication::applicationDirPath()+"/Snippets/" + m_sni->nomSnippet->text() + ".java");
    if(!file.open(QIODevice::ReadWrite | QIODevice::Truncate)){
        qDebug() << "file failed" << file.errorString();
    }
    m_sni->addToList(m_sni->nomSnippet->text());
}

void SnippetController::copyFile(QString name){
    QFile file(QCoreApplication::applicationDirPath()+"/Snippets/" + name + ".java");
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        for(int i = 0; i < m_sni->listWidget->count(); i++){
            QListWidgetItem *item = m_sni->listWidget->item(i);
            QString nom = ((DSnippetItem*) m_sni->listWidget->itemWidget(item))->getNomSnippet()->text();
            if(name == nom){
                item->setHidden(true);
            }
        }
        QMessageBox msgBox(QMessageBox::Critical, "Fichier inexistant", "Le fichier est introuvable");
        msgBox.setText("Le fichier n'existe pas");
        msgBox.exec();
        return;
    }
    QTextStream flux(&file);
    QString content = flux.readAll();
    DCodeEditor *editor = new DCodeEditor();
    editor->appendPlainText(content);
    editor->selectAll();
    editor->copy();
}

void SnippetController::modifyFile(QString name){
    m_sni->fen->getController()->openEditor(QCoreApplication::applicationDirPath()+"/Snippets/" + name + ".java");
}

void SnippetController::deleteFile(QString name){
    QDirIterator it(QCoreApplication::applicationDirPath()+"/Snippets");
    while(it.hasNext()){
        QFile file(it.next());
        QFileInfo info(file);
        QString filename = info.baseName();
        if(filename == name){
            file.remove();
            for(int i = 0; i < m_sni->listWidget->count(); i++)
                m_sni->listWidget->item(i)->setHidden(true);
            m_sni->getList();
            return;
        }
    }
}

void SnippetController::validate(QString nomSnippet){
    if(nomSnippet.size() > 0 && m_sni->caracteresSpeciaux(nomSnippet))
        m_sni->valider->setEnabled(true);
    else
        m_sni->valider->setEnabled(false);
}

void SnippetController::isDeleted(){
    for(int i = 0; i < m_sni->listWidget->count(); i++){
        QListWidgetItem *item = m_sni->listWidget->item(i);
        QString nom = ((DSnippetItem*) m_sni->listWidget->itemWidget(item))->getNomSnippet()->text();
        if(!(nom.contains(m_sni->input->text(), Qt::CaseInsensitive)))
            item->setHidden(true);
        else
            item->setHidden(false);
    }
}
*/