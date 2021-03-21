#ifndef CONSOLE_H
#define CONSOLE_H

#include <QtWidgets>


class Console : public QPlainTextEdit {
    Q_OBJECT

    public:
        Console(QString &cmdLancement,QString basePath, QWidget *parent=nullptr);
        ~Console();
        QTextCursor getCurrentCmd();
        void build();
        void execute();

    protected:
        void keyPressEvent(QKeyEvent *e);

    private slots:
        void read();
    public slots:
        void sendCtrlC();

    private:
        QString path;
        int lastLineSize;
        QProcess cmd;
        QVector<QString> historique;
        QString currentCmd;
        int  histoIndex;


};

#endif
