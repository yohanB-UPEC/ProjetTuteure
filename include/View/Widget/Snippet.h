#ifndef SNIPPET_H
#define SNIPPET_H

#include <QtWidgets>
#include <QListView>
#include "include/View/Widget/DSnippetItem.h"
#include "include/Controller/Widget/SnippetController.h"

class Fenetre;

class Snippet : public QWidget {
    Q_OBJECT

    friend class SnippetController;

    public:
        Snippet(Fenetre* fen, QWidget *parent=0);
        DSnippetItem* getDSnippetItem() {return this->dlistItem;}

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
        DSnippetItem *dlistItem;
        SnippetController sni;
        void addToList(QString snippetname);
        void getList();
        void createDialog();
        bool caracteresSpeciaux(QString nomSnippet);
};

#endif
