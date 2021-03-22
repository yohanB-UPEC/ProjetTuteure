#ifndef SNIPPET_H
#define SNIPPET_H

#include <QtWidgets>
#include <QListView>
#include "include/View/Widget/DSnippetItem.h"
#include "include/Controller/Widget/SnippetController.h"
#include "include/Model/SnippetModel.h"
#include "include/Controller/Widget/SnippetDelegate.h"

class Fenetre;

class Snippet : public QWidget{
    Q_OBJECT

    friend class SnippetController;

    public:
        Snippet(Fenetre *fen, SnippetModel *model);
    private:
        Fenetre *m_fen;
        QSortFilterProxyModel* m_model;
        QListView listView;
        SnippetController *sc;

};

#endif
