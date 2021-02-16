#ifndef FOLDERDIALOG_H
#define FOLDERDIALOG_H

#include <QtWidgets>
#include "include/Controller/Dialog/FolderController.h"
#include "include/Model/FilteredModel.h"
#include "include/Model/Javora.h"

class FolderDialog : public QDialog {
    Q_OBJECT

    friend class FolderController;

    public:
        FolderDialog(QWidget *parent, Model *model, QFlags<Javora::ModelType> type = Javora::Folder);

    private:
        QPushButton *valider;
        QLineEdit *name;
        QLineEdit *loc;
        QTreeView *tree;
        FolderController fd;
        FilteredModel *fm;
        QFlags<Javora::ModelType> m_type;
        //void selectedItem(const QItemSelection &selected, const QItemSelection &deselected);

};

#endif
