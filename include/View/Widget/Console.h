#ifndef CONSOLE_H
#define CONSOLE_H

#include <QtWidgets>

class Fenetre;

class Console : public QWidget {
    Q_OBJECT

    public:
        Console(QWidget *parent);
        ~Console();
        QPlainTextEdit *getEdit();
        QLineEdit *getLineEdit();

    private:
        QPlainTextEdit *edit;
        QLineEdit *lineEdit;
        QProcess *cmd;
        QMenu *menu;
        QAction *newCmd;

    public slots:
        void readStdOut();
        void execCmd();
};

#endif
