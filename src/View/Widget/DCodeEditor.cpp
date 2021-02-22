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
    this->setTabStopDistance(32);
    connect(this,SIGNAL(blockCountChanged(int)),this,SLOT(leftAreaWidthUpdate()));
    connect(this,SIGNAL(updateRequest(QRect,int)),this,SLOT(scrollLeftAreaUpdate(QRect,int)));
    connect(this,SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
    leftAreaWidthUpdate();
}
void DCodeEditor::keyPressEvent(QKeyEvent *event) {
    QPlainTextEdit::keyPressEvent(event);
    int nombreTabulations = 0;
    if(event->key() == Qt::Key_ParenLeft){
        this->insertPlainText(")");
        this->moveCursor(QTextCursor::PreviousCharacter);
    }
    if(event->key() == Qt::Key_BracketLeft){
        this->insertPlainText("]");
        this->moveCursor(QTextCursor::PreviousCharacter);
    }
    /*if(event->key() == Qt::Key_BraceLeft){
        this->insertPlainText("}");
        this->moveCursor(QTextCursor::PreviousCharacter);
    }*/
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
        QStringList lignes = this->toPlainText().split('\n');
            int positionCurseur = this->textCursor().position();
            int indexLigneCourante = -1;
            int nombreCaracteres = 0;

            for (int i = 0; i < lignes.size(); i++){
                nombreCaracteres += lignes[i].size();
                if (nombreCaracteres-1 == positionCurseur){
                    indexLigneCourante = i;
                    break;
                }
            }
            if (indexLigneCourante == -1)
                indexLigneCourante = lignes.size()-1;

            nombreTabulations = lignes[indexLigneCourante-1].count('\t');

            if(lignes[indexLigneCourante-1].contains('{'))
                nombreTabulations++;

            else if(lignes[indexLigneCourante-1].contains('}'))
                nombreTabulations--;

            for (int i = 0; i < nombreTabulations; i++)
                this->insertPlainText("\t");
            //this->moveCursor(QTextCursor::PreviousBlock);

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
