#ifndef PROJECTDIALOG
#define PROJECTDIALOG

#include <QtWidgets>

class ProjectDialog : public QDialog {
	Q_OBJECT
	
	public:
		ProjectDialog(QWidget *parent);
		// getter
		const QString getName();
		const QString getLocation();
		const QString getJDK();
		
	private:
		QLineEdit *name;
		QLineEdit *loc;
		QComboBox *jdk;
		QPushButton *valider;
		
	public slots:
		void parcourir();
		void validate();
		
};

#endif