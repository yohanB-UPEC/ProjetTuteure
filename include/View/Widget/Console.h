#ifndef CONSOLE_H
#define CONSOLE_H

#include <QtWidgets>

class Fenetre;

class Console : public QWidget {
    Q_OBJECT

    public:
        Console(Fenetre *fen, QWidget *parent);
        ~Console();
        QPlainTextEdit *getEdit();
        QLineEdit *getLineEdit();
        QString getCmd(){return this->nomCmd;}
        void setCmd(QString nomCmd){this->nomCmd = nomCmd;}

    private:
        Fenetre *fen;
        QPlainTextEdit *edit;
        QLineEdit *lineEdit;
        QProcess *cmd;
        QMenu *menu;
        QAction *newCmd;
        QString nomCmd;

    public slots:
        void readStdOut();
        void execCmd();
};

#endif
