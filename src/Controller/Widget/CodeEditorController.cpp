#include "include/Controller/Widget/CodeEditorController.h"
#include "include/View/Widget/DCodeEditor.h"

CodeEditorController::CodeEditorController(TreeItem *item, DCodeEditor *view){
    this->m_item = item;
    this->m_view = view;
    if(item != nullptr){
        m_path = item->getPath();
        open();

    }
    qDebug() << "connect";
}

void CodeEditorController::open(){
    QFile file(m_path);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(m_view,"impossible d'ouvrir le fichier","Impossible d'ouvrir le fichier "+m_path);
        return;
    }
    m_view->setUndoRedoEnabled(false);
    QTextStream in(&file);
    while(!in.atEnd()){
        m_view->appendPlainText(in.readLine());
    }
    file.close();
    m_view->setUndoRedoEnabled(true);
    m_view->document()->setModified(false);
    connect(m_item,SIGNAL(rename(QString)),this,SLOT(rename(QString)));
    qDebug() << "open";
}

void CodeEditorController::save(){
    if(m_item == nullptr && m_path == ""){
        m_path = QFileDialog::getSaveFileName(m_view,tr("Enregistrer le fichier"),"~/",tr("all file (*.*)"));
    }
    if(m_path == "")
        return;
    QFile file(m_path);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(m_view,"impossible d'ouvrir le fichier","Impossible d'ouvrir le fichier "+m_path);
        return;
    }
    QTextStream out(&file);
    QTextBlock next = m_view->document()->begin();
    while(next !=  m_view->document()->end() ){
        out << next.text()+"\n";
        next = next.next();
    }
    file.close();
    m_view->document()->setModified(false);
}

bool CodeEditorController::close(){
    if(!m_view->document()->isModified())
        return true;
    QMessageBox::StandardButton res = QMessageBox::question(m_view,"Fermeture du fichier","Voulez-vous sauvegarder ce fichier",QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel,QMessageBox::Cancel);
    if(res == QMessageBox::Save){
        save();
    }else if(res == QMessageBox::Cancel){
        return false;
    }
    return true;
}

bool CodeEditorController::isItem(TreeItem *test){
    if(test == m_item){
        return true;
    }
    return false;
}

void CodeEditorController::rename(QString path){
    qDebug() << "CodeEditorController::rename  " << path;
    m_path = path;
    if(typeid(*(m_view->parentWidget()->parentWidget())) == typeid(QTabWidget)){
        QTabWidget* tab = (QTabWidget*)m_view->parentWidget()->parentWidget();
        tab->setTabText(tab->indexOf(m_view),m_item->label());
    }
}
