#ifndef SNIPPET_H
#define SNIPPET_H

#include <QtWidgets>
#include <QListView>
#include "include/View/Widget/DSnippetItem.h"
#include "include/Controller/Widget/SnippetController.h"
#include "include/Model/SnippetModel.h"

class Snippet : public QListView{
    Q_OBJECT
    public:
        Snippet(SnippetModel *model);

    private:
        SnippetModel* m_model;
};



/*
class Fenetre;

class Snippet : public QWidget {
    Q_OBJECT

    friend class SnippetController;

    public:
        Snippet(Fenetre* fen, QWidget *parent=0);
        QStringList getSnippetsNames();


    private:
        QVBoxLayout *layout;
        QLineEdit *input;
        QPushButton *search;
        QPushButton *add;
        QListWidget *listWidget;
        QDialog *dial;
        QPushButton *valider;
        QLineEdit *nomSnippet;
        Fenetre *fen;
        SnippetController sni;
        void addToList(QString snippetname);
        void getList();
        void createDialog();
        bool caracteresSpeciaux(QString nomSnippet);
};
*/
#endif
