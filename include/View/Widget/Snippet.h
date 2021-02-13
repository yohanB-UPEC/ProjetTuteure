#ifndef SNIPPET_H
#define SNIPPET_H

#include <QtWidgets>
#include <QListView>

class Fenetre;

class Snippet : public QWidget {
    Q_OBJECT

    public:
        Snippet(QWidget *parent=0);

    private:
        QVBoxLayout *layout;
        QLineEdit *input;
        QPushButton *search;
        QPushButton *modifier;
        QPushButton *copy;
        QPushButton *add;
        QListWidget *listWidget;
        QListWidgetItem* listItems;
        QDialog *dial;
        QPushButton *valider;
        QLineEdit *nomSnippet;
        void addToList(QString snippetname);
        void getList();
        void createDialog();
        bool caracteresSpeciaux(QString nomSnippet);

    public slots:
        void searchSnippet();
        void addSnippet();
        void validate(QString nomSnippet);
};

#endif
