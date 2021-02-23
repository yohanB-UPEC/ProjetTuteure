#ifndef DSNIPPETITEM_H
#define DSNIPPETITEM_H

#include <QtWidgets>
#include "include/Model/DIcons.h"

class DSnippetItem : public QWidget {
    Q_OBJECT

    public:
        DSnippetItem(QString nomLab, QListWidgetItem *item, QWidget *parent=nullptr);
        QPushButton *getCopy();
        QPushButton *getModifier();
        QPushButton *getDel();
        QLabel *getNomSnippet();
        QWidget *getWidget();

    private:
        QPushButton *modifier;
        QPushButton *copy;
        QPushButton *del;
        QLabel *nomSnippet;
        QWidget *widget;
    public slots:
        void copy_snippet();
        void modify_snippet();
        void delete_snippet();
    signals:
        void sig(QString nom);
        void sig_modify(QString nom);
        void sig_delete(QString nom);
};

#endif
