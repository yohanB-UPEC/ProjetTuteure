#ifndef CLASSDIALOG_H
#define CLASSDIALOG_H

#include <QtWidgets>
#include "include/Controller/Dialog/ClassController.h"

class ClassDialog : public QDialog {
	Q_OBJECT
	
	friend class ClassController;

	public:
        ClassDialog(QWidget *parent=0);
		
	private:
		QPushButton *valider;
		QLineEdit *name;
		QLineEdit *superClass;
        QLineEdit *interFace;
		QLineEdit *loc;
		QLineEdit *loc2;
		ClassController clc;
};

#endif
