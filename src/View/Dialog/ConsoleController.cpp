#include "include/Controller/Dialog/ConsoleController.h"
#include "include/View/Dialog/ConsoleDialog.h"

ConsoleController::ConsoleController(ConsoleDialog *view): m_view(view){
    selectedRow=-1;
}


void ConsoleController::modifyButton(){
    if(m_view->m_table->selectionModel()->hasSelection()){
        QModelIndex index = m_view->m_table->selectionModel()->selectedRows(0)[0];
        if(index.isValid()){
            selectedRow = index.row();
            m_view->addDialog(*(QString*)index.internalPointer(), *(QString*)m_view->m_table->selectionModel()->selectedRows(1)[0].internalPointer());
        }
    }
}

void ConsoleController::supprimer(){
    QModelIndex index = m_view->m_table->selectionModel()->selectedRows(0)[0];
    if(index.isValid()){
        m_view->m_model->removeConsole(index.row());
    }
}

void ConsoleController::modify(){
    if(m_view->m_name->text().size() > 0 && m_view->m_cmd->text().size()>0){
        if(m_view->m_model->modify(selectedRow,m_view->m_name->text(),m_view->m_cmd->text())){
            m_view->m_dial->accept();
        }else{
            QMessageBox::information(nullptr,"nom incorrect","Une autre commande de lancement porte déjà ce nom");
        }
    }else{
        QMessageBox::information(nullptr,"formulaire incorrect","les 2 champs de texte doivent être remplis.");
    }
}

void ConsoleController::addConsole(){
    if(m_view->m_name->text().size() > 0 && m_view->m_cmd->text().size()>0){
        if(m_view->m_model->addConsole(m_view->m_name->text(),m_view->m_cmd->text())){
            m_view->m_dial->accept();
        }else{
            QMessageBox::information(nullptr,"nom incorrect","Une autre commande de lancement porte déjà ce nom");
        }
    }else{
        QMessageBox::information(nullptr,"formulaire incorrect","les 2 champs de texte doivent être remplis.");
    }
}

void ConsoleController::deleted(){
    qDebug() << "destruction de la broite de dialogue";
}

void ConsoleController::cancelAll(){
    m_view->m_model->reload();
    m_view->reject();
}
void ConsoleController::validateAll(){
    m_view->m_model->valider();
    m_view->accept();
}
