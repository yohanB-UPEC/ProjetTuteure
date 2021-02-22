#include "include/Controller/Controller.h"
#include "include/View/Fenetre.h"

Controller::Controller(Fenetre *fen, Model *model){
	this-> fen = fen;
	this->model = model;
	
}

void Controller::openEditor(const QModelIndex &index){
    TreeItem *item = (TreeItem*)index.internalPointer();
    if(typeid(*item) == typeid(TreeItem) || typeid(*item) == typeid(DJavaFile) ){
        QTabWidget *tab = this->fen->getCentral();
        for(int i = 0; i < tab->count();i++){
            if(((DCodeEditor*)tab->widget(i))->getController().isItem(item)){
                tab->setCurrentWidget(tab->widget(i));
                return;
            }
        }
        DCodeEditor *edit = new DCodeEditor(item,tab);
        tab->addTab(edit,item->label());
        tab->setCurrentWidget(edit);
    }
}

void Controller::openEditor(QString path){
    QTabWidget *tab = this->fen->getCentral();
    for(int i = 0; i < tab->count();i++){
        if(((DCodeEditor*)tab->widget(i))->getController().isFile(path)){
            tab->setCurrentWidget(tab->widget(i));
            return;
        }
    }
    DCodeEditor *edit = new DCodeEditor(path);
    QString name;
    if(path.isNull() || path.isEmpty()){
        name = "nouveau";
    }else{
        name = QFileInfo(path).fileName();
    }
    tab->addTab(edit,name);
    tab->setCurrentWidget(edit);
}

void  Controller::closeEditor(int index){
    DCodeEditor *edit;
    if(index<0){
        edit = (DCodeEditor*)this->fen->getCentral()->currentWidget();
    }else{
        edit = (DCodeEditor*)this->fen->getCentral()->widget(index);
    }
    if(edit==nullptr)
        return;
    if(edit->getController().close()){
        if(index < 0){
            this->fen->getCentral()->removeTab(this->fen->getCentral()->currentIndex());
        }else{
            this->fen->getCentral()->removeTab(index);
        }
        delete edit;
    }
}

void Controller::closeAllEditor(){
    QTabWidget *tab = this->fen->getCentral();
    while(tab->count() > 0){
        tab->setCurrentIndex(0);
        closeEditor();
    }
}

void Controller::saveEditor(){
    DCodeEditor *edit = (DCodeEditor*)this->fen->getCentral()->currentWidget();
    if(edit==nullptr)
        return;
    edit->getController().save();
}

void Controller::saveAllEditor(){
    QTabWidget *tab = this->fen->getCentral();
    for(int i = 0; i < tab->count();i++){
        ((DCodeEditor*)tab->widget(i))->getController().save();
    }
}

void Controller::explorerContextMenu(const QPoint& pos){
    QModelIndex item = fen->tree->indexAt(pos);
    MenuContextExplorer menu(item,model,fen);
    menu.exec(fen->tree->mapToGlobal(pos));
}
