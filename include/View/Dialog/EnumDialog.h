#ifndef ENUMDIALOG_H
#define ENUMDIALOG_H

#include <QtWidgets>

class EnumDialog : public QDialog {
    Q_OBJECT

    public:
        EnumDialog(QWidget *parent);

    private:
        QPushButton *valider;
        QLineEdit *name;
        QLineEdit *loc, *loc2;
        QItemSelectionModel* selectionModel;
        QFileSystemModel *filemodel, *filemodel2;

    public slots:
        void validate();
        void parcourir();
        void parcourir2();
        //void selectedItem(const QItemSelection &selected, const QItemSelection &deselected);

};

#endif
