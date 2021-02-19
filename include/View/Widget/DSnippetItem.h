#ifndef DSNIPPETITEM_H
#define DSNIPPETITEM_H

#include <QtWidgets>

class DSnippetItem : public QWidget {
    Q_OBJECT

    public:
        DSnippetItem(QString nomLab, QListWidgetItem *item, QWidget *parent=nullptr);
        QPushButton *getCopy();
        QPushButton *getModifier();
        QLabel *getNomSnippet();
        QWidget *getWidget();

    private:
        QPushButton *modifier;
        QPushButton *copy;
        QLabel *nomSnippet;
        QWidget *widget;
    public slots:
        void copy_snippet();
        void modify_snippet();
    signals:
        void sig(QString nom);
        void sig_modify(QString nom);
};

#endif
