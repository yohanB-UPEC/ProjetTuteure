#include "include/View/Widget/DCodeEditor.h"

DCodeEditor::DCodeEditor(QWidget *parent) : QPlainTextEdit(parent) {
	leftArea = new LeftLineArea(this);	
	QFont font("Consolas",11,QFont::Medium,false);
	this->setFont(font);
	new JavaHighLighter(this->document());
	this->setTabStopDistance(32);
	connect(this,SIGNAL(blockCountChanged(int)),this,SLOT(leftAreaWidthUpdate()));
	connect(this,SIGNAL(updateRequest(QRect,int)),this,SLOT(scrollLeftAreaUpdate(QRect,int)));
	connect(this,SIGNAL(cursorPositionChanged()), this, SLOT(highlightCurrentLine()));
	leftAreaWidthUpdate();
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
	painter.fillRect(0,event->rect().y(),event->rect().width(),event->rect().height(),QColor::fromRgb(230,230,230));
	
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

	QColor lineColor = QColor::fromRgb(230,230,230);

	selection.format.setBackground(lineColor);
	selection.format.setProperty(QTextFormat::FullWidthSelection, true);
	selection.cursor = textCursor();
	selection.cursor.clearSelection();
	extraSelections.append(selection);


    setExtraSelections(extraSelections);
}

void DCodeEditor::scrollLeftAreaUpdate(const QRect &rect,int dy){
	if(dy){
		leftArea->scroll(0,dy);
		//printf("%s\n",this->toPlainText().toStdString().c_str());
	}else{
		leftArea->update(0,rect.y(),leftArea->width(),rect.height());
	}
}
