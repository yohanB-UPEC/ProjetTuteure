#ifndef SNIPPETCONTROLLER_H
#define SNIPPETCONTROLLER_H

#include <QtWidgets>
#include "include/View/Dialog/SnippetDialog.h"

class Snippet;

class SnippetController : public QObject {
    Q_OBJECT

    public:
        SnippetController(Snippet *sni);

    private:
        Snippet *m_sni;

    public slots:
        void addSnippet();
        void modifyFile(const QModelIndex &index);
        void removeSnippet(const QModelIndex &index);
        void copySnippet(const QModelIndex &index);
        void filtre(const QString& pattern);

};

#endif
