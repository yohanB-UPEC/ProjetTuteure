#include <QProcess>
#include <QWidget>
#include "include/View/Widget/Console.h"

Console::Console(QWidget *parent) : QWidget(parent){

        QVBoxLayout *vb = new QVBoxLayout();

        edit = new QPlainTextEdit(this);
        edit->setStyleSheet("QPlainTextEdit {background-color: #252424; color: white; font-family: sans-serif; font-size: 15px;}");
        edit->setBackgroundVisible(true);
        edit->setReadOnly(true);

        lineEdit = new QLineEdit(this);

        vb->addWidget(edit);
        vb->addWidget(lineEdit);

        this->setLayout(vb);
        cmd = new QProcess(parent);
        cmd->setProcessChannelMode(QProcess::MergedChannels);
        cmd->start("C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe", QStringList());
        connect(cmd, SIGNAL(readyRead()), this, SLOT(readStdOut()));
        connect(lineEdit, SIGNAL(editingFinished()), this, SLOT(execCmd()));
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
}

Console::~Console(){
    cmd->close();
}

void Console::execCmd(){
    QByteArray arr = QByteArray::fromStdString(lineEdit->text().toStdString() + "\r\n");
    lineEdit->setText("");
    cmd->write(arr);
}
