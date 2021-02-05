#ifndef PACKAGEDIALOG
#define PACKAGEDIALOG

#include <QtWidgets>

class PackageDialog : public QDialog {
	Q_OBJECT
	
	public:
		PackageDialog(QWidget *parent);
		
	private:
		QPushButton *valider;
		QLineEdit *name;
		QString loc;
		QItemSelectionModel* selectionModel;
		QFileSystemModel *filemodel;
		
	public slots:
		void validate();
		void selectedItem(const QItemSelection &selected, const QItemSelection &deselected);
	
};

#endif