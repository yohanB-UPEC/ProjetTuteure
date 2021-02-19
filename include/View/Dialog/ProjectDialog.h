#ifndef PROJECTDIALOG
#define PROJECTDIALOG

#include "include/Controller/Dialog/ProjectController.h"

class ProjectDialog : public QDialog {
	Q_OBJECT
	
	friend class ProjectController;
	
	public:
		ProjectDialog(QWidget *parent, Model *model);

		// getter
		const QString getName();
		const QString getLocation();
		const QString getJDK();
		
	private:
		QLineEdit *name;
		QLineEdit *loc;
		QComboBox *jdk;
		QPushButton *valider;
		ProjectController pc;
		
	public slots:
		
};

#endif
