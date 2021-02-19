#ifndef DCODEEDITOR
#define DCODEEDITOR

#include <QtWidgets>
#include "JavaHighLighter.h"

class DCodeEditor : public QPlainTextEdit {
	Q_OBJECT
	
	public:
		DCodeEditor(QWidget *parent = nullptr);
		void leftAreaPaintEvent(QPaintEvent *event);
	
	private:
        QWidget *leftArea;
        JavaHighLighter *highlighter;
		
	protected:
		void resizeEvent(QResizeEvent *event);
		
	public slots:
		void leftAreaWidthUpdate();
		void scrollLeftAreaUpdate(const QRect &rect,int dy);
		void highlightCurrentLine();
        void keyPressEvent(QKeyEvent *event);
};

class LeftLineArea : public QWidget {
	Q_OBJECT
	public:
		LeftLineArea(DCodeEditor *parent) : QWidget(parent), dce(parent){}
		
	private:
		DCodeEditor *dce;
	
	protected:
		void paintEvent(QPaintEvent *event){
			dce->leftAreaPaintEvent(event);
		}	
};

#endif
