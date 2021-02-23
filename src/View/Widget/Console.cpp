#include <QProcess>
#include <QWidget>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "include/View/Widget/Console.h"
#include "include/View/Fenetre.h"

Console::Console(Fenetre *fen, QWidget *parent) : QWidget(parent){
        this->fen = fen;
        QVBoxLayout *vb = new QVBoxLayout();

        edit = new QPlainTextEdit(this);
        edit->setStyleSheet("QPlainTextEdit {background-color: #242424; color: white; font-family: cursive; font-size: 15px;}");
        edit->setBackgroundVisible(true);
        edit->setReadOnly(true);

        lineEdit = new QLineEdit(this);
        qApp->installEventFilter(this);
        vb->addWidget(edit);
        vb->addWidget(lineEdit);

        this->setLayout(vb);
        cmd = new QProcess(parent);
        cmd->setProcessChannelMode(QProcess::MergedChannels);

        cmd->start(this->fen->getMenuPref()->getNom(), QStringList());
        connect(cmd, SIGNAL(readyRead()), this, SLOT(readStdOut()));
        connect(lineEdit, SIGNAL(editingFinished()), this, SLOT(execCmd()));
}

bool Console::eventFilter(QObject *obj, QEvent *event){
    if (obj == lineEdit && event->type() == QEvent::KeyPress) {
        QKeyEvent *key = static_cast<QKeyEvent *>(event);
         if(key->matches(QKeySequence::Copy)){
             QProcess *proc = new QProcess(nullptr);
             proc->start("java.exe", QStringList());
             if(proc->state() == QProcess::Running)
                system("taskkill /im java.exe /f");
        }
    }
    return QObject::eventFilter(obj, event);
}

QPlainTextEdit* Console::getEdit(){
    return this->edit;
}

QLineEdit* Console::getLineEdit(){
    return this->lineEdit;
}

void Console::readStdOut(){
    QTextCodec *codec = QTextCodec::codecForName("IBM850");
    edit->insertPlainText(codec->toUnicode(" " + cmd->readAllStandardOutput()));
    edit->verticalScrollBar()->setValue(edit->verticalScrollBar()->maximum());
}

Console::~Console(){
    cmd->close();
}

void Console::execCmd(){
    QByteArray arr = QByteArray::fromStdString(lineEdit->text().toStdString() + "\r\n");
    if(lineEdit->text().compare("clear") == 0){
        edit->clear();
    }
    lineEdit->setText("");
    cmd->write(arr);
}
