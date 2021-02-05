#ifndef SRCFOLDERDIALOG_H
#define SRCFOLDERDIALOG_H

#include <QtWidgets>

class SrcFolderDialog : public QDialog {
    Q_OBJECT

    public:
        SrcFolderDialog(QWidget *parent);

    private:
        QPushButton *valider;
        QLineEdit *name;
        QLineEdit *loc;
        QItemSelectionModel* selectionModel;
        QFileSystemModel *filemodel;

    public slots:
        void validate();
        void parcourir();
        //void selectedItem(const QItemSelection &selected, const QItemSelection &deselected);

};


#endif
