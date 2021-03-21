#include <QProcess>
#include <QWidget>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "include/View/Widget/Console.h"
#include "include/View/Fenetre.h"


Console::Console(QString &cmdLancement,QString basePath, QWidget *parent) : QPlainTextEdit(parent), cmd(this),lastLineSize(0), histoIndex(0) {
    this->setStyleSheet("background-color: #242424; color: white; font-family: Arial, cursive; font-size: 15px;");
    this->cmd.setWorkingDirectory(basePath);
    path = basePath;
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
    QMenu menu("salut", parent);
    QAction *action = new QAction("build");
    menu.addAction(action);
    QLabel *lab = new QLabel("build", &menu);
    qDebug() << "from parent = " << parent->mapFromParent(QPoint(0, 0));
    qDebug() << "to parent = " << parent->mapToParent(QPoint(0, 0));
    qDebug() << "to global = " << parent->mapToGlobal(QPoint(0, 0));
    qDebug() << "from global = " << parent->mapFromGlobal(QPoint(0, 0));
    menu.exec(parent->mapToGlobal(QPoint(0, 0)));
}

void Console::build(){
    cmd.write("make\n");
    execute();
}

void Console::execute(){
    cmd.write("make run\n");
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

QTextCursor Console::getCurrentCmd(){
        int res = this->document()->lastBlock().text().mid(lastLineSize).size();
        QTextCursor cursor = this->textCursor();
        cursor.movePosition(QTextCursor::End);
        cursor.movePosition(QTextCursor::PreviousCharacter,QTextCursor::KeepAnchor,res);
        return cursor;
}
void Console::keyPressEvent(QKeyEvent *e){

    if(e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return){    
        QTextCursor cursor = this->getCurrentCmd();
        QString res = cursor.selectedText();
        cursor.removeSelectedText();
        if(res == "clear"){
            this->clear();
            res= "";
        }
        this->historique.append(res);
        histoIndex = this->historique.size()-1;
        currentCmd = "";
        cmd.write(QByteArray::fromStdString(res.toStdString() + "\n"));
        return;
    }

    if(e->key() == Qt::Key_Up){
    	QTextCursor cursor = this->getCurrentCmd();
    	if(histoIndex == this->historique.size()-1){
    		currentCmd = cursor.selectedText();
    	}
        cursor.removeSelectedText();
        if(this->historique.size() > 0)
            this->insertPlainText(this->historique[histoIndex]);
        if(histoIndex>0)
        	histoIndex--;
        return;
    }else if(e->key() == Qt::Key_Down){
    	QTextCursor cursor = this->getCurrentCmd();
        cursor.removeSelectedText();
        if(histoIndex<historique.size())
        	histoIndex++;
        if(histoIndex==historique.size()){
        	this->insertPlainText(currentCmd);
        	histoIndex--;
        }else{
        	this->insertPlainText(this->historique[histoIndex]);
        }
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
