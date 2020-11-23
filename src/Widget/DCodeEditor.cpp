#include "include/Widget/DCodeEditor.h"

DCodeEditor::DCodeEditor(QWidget *parent) : QPlainTextEdit(parent) {
	leftArea = new LeftLineArea(this);
	leftAreaWidthUpdate();
	connect(this,SIGNAL(blockCountChanged(int)),this,SLOT(leftAreaWidthUpdate()));
	connect(this,SIGNAL(updateRequest(QRect,int)),this,SLOT(scrollLeftAreaUpdate(QRect,int)));
	this->appendPlainText("c le commencement");
}

void DCodeEditor::resizeEvent(QResizeEvent *event){
	leftArea->setGeometry(0,0,leftArea->width(),event->size().height());
	this->appendPlainText("je resize");
}

void DCodeEditor::leftAreaWidthUpdate(){
	QFontMetrics fm(this->document()->defaultFont());
	int nbC = std::to_string(this->blockCount()).size();
	int width = (nbC+4) * fm.boundingRect("4").width();
	this->setViewportMargins(width,0,0,0);
	leftArea->setGeometry(0,0,width,this->height());	
}

void DCodeEditor::leftAreaPaintEvent(QPaintEvent *event){
	QPainter painter(leftArea);
	painter.fillRect(0,0,50,200,QColor::fromRgb(0,0,0));
}


void DCodeEditor::scrollLeftAreaUpdate(const QRect &rect,int dy){
	if(dy){
		leftArea->scroll(0,dy);
	}else{
		leftArea->update(0,rect.y(),leftArea->width(),rect.height());
	}
}