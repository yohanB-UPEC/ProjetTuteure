#ifndef DCODEEDITOR
#define DCODEEDITOR

#include <QtWidgets>
#include "include/Model/TreeItem.h"
#include "include/Controller/Widget/CodeEditorController.h"
#include "JavaHighLighter.h"


class DCodeEditor : public QPlainTextEdit {
	Q_OBJECT
	
	public:
        DCodeEditor(TreeItem *item=nullptr,QWidget *parent = nullptr);
        DCodeEditor(QString &path,QWidget *parent = nullptr);
		void leftAreaPaintEvent(QPaintEvent *event);
        CodeEditorController& getController(){return this->cec;}
	
	private:
		QWidget *leftArea;
        CodeEditorController cec;
        JavaHighLighter *highlighter;
        void constructeur();

		
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
