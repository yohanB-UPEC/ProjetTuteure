#ifndef INTERFACEDIALOG_H
#define INTERFACEDIALOG_H

#include <QtWidgets>
#include "include/Controller/Dialog/InterfaceController.h"

class InterfaceDialog : public QDialog {
    Q_OBJECT

    friend class InterfaceController;

    public:
        InterfaceDialog(QWidget *parent=0);

    private:
        QPushButton *valider;
        QLineEdit *name;
        QLineEdit *loc, *loc2;
        QItemSelectionModel* selectionModel;
        QFileSystemModel *filemodel, *filemodel2;
        InterfaceController ifd;
};

#endif
