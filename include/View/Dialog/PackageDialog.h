#ifndef PACKAGEDIALOG
#define PACKAGEDIALOG

#include <QtWidgets>
#include "include/Controller/Dialog/PackageController.h"

class PackageDialog : public QDialog {
	Q_OBJECT

    friend class PackageController;
	
	public:
        PackageDialog(QWidget *parent=0);
		
	private:
		QPushButton *valider;
		QLineEdit *name;
        QLineEdit *path;
        QString loc;
		QItemSelectionModel* selectionModel;
		QFileSystemModel *filemodel;
        PackageController pkd;
	
};

#endif
