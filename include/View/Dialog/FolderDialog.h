#ifndef FOLDERDIALOG_H
#define FOLDERDIALOG_H

#include <QtWidgets>
#include "include/Controller/Dialog/FolderController.h"

class FolderDialog : public QDialog {
    Q_OBJECT

    friend class FolderController;

    public:
        FolderDialog(QWidget *parent);

    private:
        QPushButton *valider;
        QLineEdit *name;
        QLineEdit *loc;
        QItemSelectionModel* selectionModel;
        QFileSystemModel *filemodel;
        FolderController fd;
        //void selectedItem(const QItemSelection &selected, const QItemSelection &deselected);

};

#endif
