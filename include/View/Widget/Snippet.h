#ifndef SNIPPET_H
#define SNIPPET_H

#include <QtWidgets>
#include <QListView>
#include "include/View/Widget/DSnippetItem.h"

class Fenetre;

class Snippet : public QWidget {
    Q_OBJECT

    public:
        Snippet(Fenetre* fen, QWidget *parent=0);

    private:
        QVBoxLayout *layout;
        QLineEdit *input;
        QPushButton *search;
        QPushButton *add;
        QListWidget *listWidget;
        QListWidgetItem* listItems;
        QDialog *dial;
        QPushButton *valider;
        QLineEdit *nomSnippet;
        QString filename;
        Fenetre *fen;
        void addToList(QString snippetname);
        void getList();
        void createDialog();
        bool caracteresSpeciaux(QString nomSnippet);

    public slots:
        void isDeleted();
        void addSnippet();
        void validate(QString nomSnippet);
        void copyFile(QString name);
        void modifyFile(QString name);
        void deleteFile(QString name);
};

#endif
