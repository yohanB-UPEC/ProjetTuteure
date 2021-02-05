#ifndef CLASSDIALOG
#define CLASSDIALOG

#include <QtWidgets>

class ClassDialog : public QDialog {
	Q_OBJECT
	
	public:
        ClassDialog(QWidget *parent=0);
		
	private:
		QPushButton *valider;
		QLineEdit *name;
		QLineEdit *superClass;
        QLineEdit *interFace;
		QString loc;
		
	public slots:
		void validate();
	
};

#endif
