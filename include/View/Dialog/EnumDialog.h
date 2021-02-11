#ifndef ENUMDIALOG_H
#define ENUMDIALOG_H

#include <QtWidgets>
#include "include/Controller/Dialog/EnumController.h"

class EnumDialog : public QDialog {
    Q_OBJECT

    friend class EnumController;

    public:
        EnumDialog(QWidget *parent);

    private:
        QPushButton *valider;
        QLineEdit *name;
        QLineEdit *loc, *loc2;
        QItemSelectionModel* selectionModel;
        QFileSystemModel *filemodel, *filemodel2;
        EnumController ed;
};

#endif
