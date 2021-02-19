#ifndef PACKAGECONTROLLER
#define PACKAGECONTROLLER

#include <QtWidgets>
#include "include/Model/Model.h"

class PackageDialog;

class PackageController : public QObject {
    Q_OBJECT

    public:
        PackageController( Model *model, PackageDialog *pkd);

    private:
        PackageDialog *m_pkd;
		Model *m_model;
        QModelIndex m_chemin;
    public slots:
        void validate();
        void selectedItem(const QItemSelection& selected, const QItemSelection& deselected);
        void createPackage();
};

#endif
