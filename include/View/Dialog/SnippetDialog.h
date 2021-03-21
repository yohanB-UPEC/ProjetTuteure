#ifndef SNIPPETDIALOG_H
#define SNIPPETDIALOG_H

#include <QtWidgets>
#include "include/Model/SnippetModel.h"

class SnippetDialog: public QDialog{
    Q_OBJECT
    public:
        SnippetDialog(SnippetModel *model);
        const QString getSnippetName();
    public slots:
        void validate(QString name);

    private:
        QPushButton *valider;
        QLineEdit *m_name;
        SnippetModel *m_model;
};

#endif // SNIPPETDIALOG_H
