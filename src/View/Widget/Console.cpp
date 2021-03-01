#include <QProcess>
#include <QWidget>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "include/View/Widget/Console.h"
#include "include/View/Fenetre.h"


Console::Console(QString &cmdLancement, QWidget *parent) : QPlainTextEdit(parent), cmd(this){
    this->setStyleSheet("background-color: #242424; color: white; font-family: cursive; font-size: 15px;");
    cmd.setProcessChannelMode(QProcess::MergedChannels);
    QStringList arg;
    QStringList tmp = cmdLancement.split(" ");
    for(int i = 1; i < tmp.size();i++){
        arg << tmp[i];
    }
    cmd.start(tmp[0],arg);
    cmd.setProcessEnvironment(QProcessEnvironment::systemEnvironment());

    connect(&cmd, SIGNAL(readyReadStandardOutput()),this,SLOT(read()));
    new QShortcut(QKeySequence(Qt::CTRL+Qt::SHIFT+Qt::Key_C),this,SLOT(sendCtrlC()),SLOT(sendCtrlC()),Qt::WidgetWithChildrenShortcut);
}

Console::~Console(){
    cmd.close();
}

void Console::read(){
    QTextCodec *codec = QTextCodec::codecForName("IBM850");
    QTextCursor cursor = this->textCursor();
    cursor.movePosition(QTextCursor::End);
    this->setTextCursor(cursor);
    this->insertPlainText(codec->toUnicode(" " + cmd.readAllStandardOutput()));
    this->verticalScrollBar()->setValue(this->verticalScrollBar()->maximum());
    lastLineSize = this->document()->lastBlock().text().size();
}

void Console::keyPressEvent(QKeyEvent *e){

    if(e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return){
        qDebug() << "key enter pressed";
        QString res = this->document()->lastBlock().text().mid(lastLineSize);
        QTextCursor cursor = this->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.movePosition(QTextCursor::PreviousCharacter,QTextCursor::KeepAnchor,res.size());
        cursor.removeSelectedText();
        if(res == "clear"){
            this->clear();
            res= "";
        }
        cmd.write(QByteArray::fromStdString(res.toStdString() + "\n"));
        return;
    }
    if(this->textCursor().block() != this->document()->lastBlock() ||
      (this->textCursor().positionInBlock() < lastLineSize && e->key() != Qt::Key_Backspace) ||
      (this->textCursor().positionInBlock() <= lastLineSize && e->key() == Qt::Key_Backspace)){
        if((e->key() >= 'a' && e->key() <= 'z') || (e->key() >= 'A' && e->key() <= 'Z') || (e->key() >= '0' && e->key() <= '9')){
            QTextCursor cursor = this->textCursor();
            cursor.movePosition(QTextCursor::End);
            this->setTextCursor(cursor);
        }
        return;
    }

    QPlainTextEdit::keyPressEvent(e);
}


void Console::sendCtrlC(){
    qDebug() << "Ctrl-C\n";
    char str[3] = {3,'\n','\0'};
    this->cmd.write(str,3);
}
