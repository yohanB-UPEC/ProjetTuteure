#include "include/Controller/Widget/ExplorerDelegate.h"

ExplorerDelegate::ExplorerDelegate(): QStyledItemDelegate(){

}


void ExplorerDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const{
    TreeItem *item = (TreeItem*)index.internalPointer();
    QLineEdit* edit = (QLineEdit*)editor;
    if(edit->text().size() <= 0 || edit->text() == item->label()){
        return;
    }
    if(typeid(*item) == typeid(DProject)){
       QDir dir(item->getPath());
       dir.cd("..");
        if(dir.exists(edit->text())){
            QMessageBox::information(nullptr,"erreur de renommage", "Un dossier portant ce nom existe déjà à cet emplacement");
            return;
        }
        QStyledItemDelegate::setModelData(editor,model,index);
        return;
    }

    if(item->parent()->exist(edit->text())){
        QMessageBox::information(nullptr,"erreur de renommage", "Un autre élément du même dossier porte déjà ce nom.");
        return;
    }

    // futurs test de renommage
    if(typeid(*item) == typeid(TreeItem)){

    }else if(typeid(*item) == typeid(DProject)){

    }

    QStyledItemDelegate::setModelData(editor,model,index);
}
