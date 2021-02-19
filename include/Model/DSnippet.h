#ifndef DSNIPPET_H
#define DSNIPPET_H

#include <QPushButton>
#include <QListView>
#include <QtWidgets>

class Fenetre;

class DSnippet : public QListView {
    Q_OBJECT

    public:
        DSnippet(QWidget *parent=0);

    private:
        QLineEdit *input;
        QPushButton *search;
        QPushButton *modifier;
        QPushButton *copy;
        QPushButton *add;
        QListView list;
};

#endif
