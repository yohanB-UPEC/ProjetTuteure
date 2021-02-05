#ifndef FOLDERDIALOG_H
#define FOLDERDIALOG_H

#include <QtWidgets>

class FolderDialog : public QDialog {
    Q_OBJECT

    public:
        FolderDialog(QWidget *parent);

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
