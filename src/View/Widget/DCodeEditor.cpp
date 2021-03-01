#include "include/View/Widget/DCodeEditor.h"

DCodeEditor::DCodeEditor(TreeItem *item, QWidget *parent) : QPlainTextEdit(parent), cec(this,item){
    this->constructeur();
}
DCodeEditor::DCodeEditor(QString &path,QWidget *parent) : QPlainTextEdit(parent), cec(this,path){
    this->constructeur();
}
void DCodeEditor::constructeur(){
    leftArea = new LeftLineArea(this);
    QFont font("Consolas",14,QFont::Medium,false);
    this->setFont(font);

    highlighter = new JavaHighLighter(this->document());
    this->setTabStopDistance(this->fontMetrics().horizontalAdvance(' ') * 4);
    connect(this,SIGNAL(blockCountChanged(int)),this,SLOT(leftAreaWidthUpdate()));
    connect(this,SIGNAL(updateRequest(QRect,int)),this,SLOT(scrollLeftAreaUpdate(QRect,int)));
    connect(this,SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
    connect(this,SIGNAL(cursorPositionChanged()), this, SLOT(highlightCouples()));
    connect(this,SIGNAL(selectionChanged()), this, SLOT(tab()));
    leftAreaWidthUpdate();
}

void DCodeEditor::tab(){
    QString newText = this->textCursor().selection().toPlainText().replace("\n", "\n\t");
    if(newText != "" && newText != "\t")
        textTab = newText;
}

void DCodeEditor::highlightCouplePrev(QString left, QString right){
    int pos = this->textCursor().positionInBlock();
    if(pos >= this->textCursor().block().text().size() || pos < 0) return;
    QChar suivChar = this->textCursor().block().text().at(pos);
    if(suivChar != right) return;
    QTextBlock next = this->textCursor().block();
    int count = 0, index = -1;
    while(1){
        QString str = next.text();
        for(; pos >= 0; pos--){
            if(str[pos] == left){
                count++;
            }
            else if(str[pos] == right)
                count--;
            if(count == 0){
                index = next.position() + pos;
                break;
            }
        }
        if(count == 0) break;
        if(next == this->document()->begin()){
            if(index == -1){
                break;
            }
        }
        pos = next.previous().text().length()-1;
        next = next.previous();
    }

    QList<QTextEdit::ExtraSelection> extraSelections;
    QTextEdit::ExtraSelection selection;

    selection.format.setForeground(Qt::red);
    selection.format.setBackground(Qt::black);
    selection.cursor = textCursor();
    selection.cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);

    QTextEdit::ExtraSelection selection2;

    selection2.format = selection.format;
    selection2.cursor = textCursor();
    selection2.cursor.setPosition(index, QTextCursor::MoveAnchor);
    selection2.cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
    extraSelections.append(selection2);

    extraSelections.append(selection);
    setExtraSelections(extraSelections);
}

void DCodeEditor::highlightCoupleNext(QString left, QString right){
    int pos = this->textCursor().positionInBlock();
    if(pos >= this->textCursor().block().text().size()) return;
    QChar suivChar = this->textCursor().block().text().at(pos);
    if(suivChar != left) return;

    QTextBlock next = this->textCursor().block();
    int count = 0, index = -1;
    while(next != this->document()->end()){
        QString str = next.text();
        for(; pos < str.length(); pos++){
            if(str[pos] == left)
                count++;
            else if(str[pos] == right)
                count--;
            if(count == 0){
                index = next.position() + pos;
                break;
            }
        }
        if(count == 0) break;
        next = next.next();
        pos = 0;
    }
    QList<QTextEdit::ExtraSelection> extraSelections;
    QTextEdit::ExtraSelection selection;

    selection.format.setForeground(Qt::red);
    selection.format.setBackground(Qt::black);
    selection.cursor = textCursor();
    selection.cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);

    QTextEdit::ExtraSelection selection2;

    selection2.format = selection.format;
    selection2.cursor = textCursor();
    selection2.cursor.setPosition(index, QTextCursor::MoveAnchor);
    selection2.cursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);
    extraSelections.append(selection2);

    extraSelections.append(selection);
    setExtraSelections(extraSelections);
}

void DCodeEditor::highlightCouples(){
    highlightCoupleNext("{", "}");
    highlightCoupleNext("(", ")");
    highlightCoupleNext("[", "]");
    highlightCouplePrev("{", "}");
    highlightCouplePrev("(", ")");
    highlightCouplePrev("[", "]");
}
void DCodeEditor::keyPressEvent(QKeyEvent *event) {
    int pos = this->textCursor().positionInBlock();
    QChar prevChar;
    if(pos > 0)
        prevChar = this->textCursor().block().text().at(pos-1);
    QChar suivChar;
    if(pos < this->textCursor().block().text().size())
        suivChar = this->textCursor().block().text().at(pos);
    QPlainTextEdit::keyPressEvent(event);
    int nombreTabulations = 0;

    if(event->key() == Qt::Key_Tab){
        this->insertPlainText(textTab);
        textTab = "";
    }
    if(event->key() == Qt::Key_ParenLeft){
        this->insertPlainText(")");
        this->moveCursor(QTextCursor::PreviousCharacter);
    }
    if(event->key() == Qt::Key_Apostrophe){
        this->insertPlainText("'");
        this->moveCursor(QTextCursor::PreviousCharacter);
    }
    if(event->key() == Qt::Key_QuoteDbl){
        this->insertPlainText("\"");
        this->moveCursor(QTextCursor::PreviousCharacter);
    }

    if(event->key() == Qt::Key_BracketLeft){
        this->insertPlainText("]");
        this->moveCursor(QTextCursor::PreviousCharacter);
    }
    if(event->key() == Qt::Key_BraceLeft){
        this->insertPlainText("}");
        this->moveCursor(QTextCursor::PreviousCharacter);
    }
    if(event->key() == Qt::Key_Backspace){
        if(!suivChar.isNull() && !prevChar.isNull() && prevChar == '(' && suivChar == ')'){
            this->textCursor().deleteChar();
        }
        if(!suivChar.isNull() && !prevChar.isNull() && prevChar == '[' && suivChar == ']'){
            this->textCursor().deleteChar();
        }
        if(!suivChar.isNull() && !prevChar.isNull() && prevChar == '{' && suivChar == '}'){
            this->textCursor().deleteChar();
        }
        if(!suivChar.isNull() && !prevChar.isNull() && prevChar == '\'' && suivChar == '\''){
            this->textCursor().deleteChar();
        }
        if(!suivChar.isNull() && !prevChar.isNull() && prevChar == '\"' && suivChar == '\"'){
            this->textCursor().deleteChar();
        }
    }
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        QString prevLine = this->textCursor().block().previous().text();
        int pos = this->textCursor().positionInBlock();
        if(prevLine.isEmpty()) return;
        int i = 0, nbSpace = 0;
        while(i < prevLine.length() && prevLine[i] == "\t"){
            nombreTabulations++;
            i++;
        }
        i = 0;
        if(nombreTabulations == 0){
            while(i < prevLine.length() && prevLine[i] == " "){
                nbSpace++;
                if(nbSpace == 4){
                    nombreTabulations++;
                    nbSpace = 0;
                }
                i++;
            }
        }
        if(prevLine.trimmed().endsWith("{")){
            nombreTabulations++;
        }

        QChar prevChar = this->textCursor().block().previous().text().at(this->textCursor().block().previous().text().size()-1);
        QChar suivChar;
        if(pos < this->textCursor().block().text().size())
            suivChar = this->textCursor().block().text().at(pos);

        for(int j = 0; j < nombreTabulations; j++){
            this->insertPlainText("\t");
        }
        if(!suivChar.isNull() && prevChar == '{' && suivChar == '}'){
            this->insertPlainText("\n");
            for(int j = 0; j < nombreTabulations-1; j++){
                this->insertPlainText("\t");
            }
            this->moveCursor(QTextCursor::PreviousBlock);
            this->moveCursor(QTextCursor::EndOfBlock);
        }
    }
}

void DCodeEditor::resizeEvent(QResizeEvent *event){
    leftArea->setGeometry(0,0,leftArea->width(),event->size().height());
}

void DCodeEditor::leftAreaWidthUpdate(){
    QFontMetrics fm(this->font());
    int nbC = std::to_string(this->blockCount()+1).size();
    int width = (nbC+4) * fm.boundingRect("4").width();
    this->setViewportMargins(width,0,0,0);
    leftArea->setGeometry(0,0,width,this->height());
}

void DCodeEditor::leftAreaPaintEvent(QPaintEvent *event){
    QPainter painter(leftArea);
    painter.setFont(this->font());
    //painter.fillRect(0,event->rect().y(),event->rect().width(),event->rect().height(),QColor::fromRgb(54,50,50));

    QTextBlock qtb = this->firstVisibleBlock();
    QRect rect = blockBoundingGeometry(qtb).translated(contentOffset()).toRect();
    while(qtb.isValid() && rect.y() <= event->rect().bottom()){
        if(qtb.isVisible() && rect.bottom() >= event->rect().top() ){
            painter.drawText(0,rect.y(),leftArea->width(),fontMetrics().height(),Qt::AlignRight,QString::number(qtb.blockNumber()+1)+" ");
        }
        qtb = qtb.next();
        rect = blockBoundingGeometry(qtb).translated(contentOffset()).toRect();
    }

}

void DCodeEditor::highlightCurrentLine(){
    QList<QTextEdit::ExtraSelection> extraSelections;


    QTextEdit::ExtraSelection selection;

    //QColor lineColor = QColor::fromRgb(54,50,50);

    //selection.format.setBackground(lineColor);
    selection.format.setProperty(QTextFormat::FullWidthSelection, true);
    selection.cursor = textCursor();
    selection.cursor.clearSelection();
    extraSelections.append(selection);

    setExtraSelections(extraSelections);
}

void DCodeEditor::scrollLeftAreaUpdate(const QRect &rect,int dy){
    if(dy){
        leftArea->scroll(0,dy);
    }else{
        leftArea->update(0,rect.y(),leftArea->width(),rect.height());
    }
}
