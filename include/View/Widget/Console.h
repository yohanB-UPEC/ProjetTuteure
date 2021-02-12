#ifndef CONSOLE_H
#define CONSOLE_H

#include <QtWidgets>

class Console : public QWidget {
    Q_OBJECT

    public:
        Console(QWidget *parent = nullptr);
        ~Console();
        QPlainTextEdit *getEdit();
        QLineEdit *getLineEdit();

    private:
        QPlainTextEdit *edit;
        QLineEdit *lineEdit;
        QProcess *cmd;

    public slots:
        void readStdOut();
        void execCmd();
};

#endif
