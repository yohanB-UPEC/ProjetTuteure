#ifndef SRCFOLDERDIALOG_H
#define SRCFOLDERDIALOG_H

#include <QtWidgets>
#include "include/Controller/Dialog/SrcFolderController.h"

class SrcFolderDialog : public QDialog {
    Q_OBJECT

    friend class SrcFolderController;

    public:
        SrcFolderDialog(QWidget *parent);

    private:
        QPushButton *valider;
        QLineEdit *name;
        QLineEdit *loc;
        QItemSelectionModel* selectionModel;
        QFileSystemModel *filemodel;
        SrcFolderController sfd;
};


#endif
