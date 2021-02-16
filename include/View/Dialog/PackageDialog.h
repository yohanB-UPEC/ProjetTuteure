#ifndef PACKAGEDIALOG
#define PACKAGEDIALOG

#include <QtWidgets>
#include "include/Model/Javora.h"
#include "include/Controller/Dialog/PackageController.h"
#include "include/Model/FilteredModel.h"

class PackageDialog : public QDialog {
	Q_OBJECT

    friend class PackageController;
	
	public:
        PackageDialog(QWidget *parent, Model *model);
		
	private:
		QPushButton *valider;
		QLineEdit *name;
        QLineEdit *path;
        QTreeView *pkgTree;
        PackageController pkd;
        FilteredModel *fm;
	
};

#endif
