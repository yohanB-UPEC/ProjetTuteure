#ifndef SNIPPETCONTROLLER_H
#define SNIPPETCONTROLLER_H

#include <QtWidgets>

class Snippet;

class SnippetController : public QObject {
    Q_OBJECT

    public:
        SnippetController(Snippet *sni);

    private:
        Snippet *m_sni;

    public slots:
        void isDeleted();
        void addSnippet();
        void validate(QString nomSnippet);
        void copyFile(QString name);
        void modifyFile(QString name);
        void deleteFile(QString name);
};

#endif
