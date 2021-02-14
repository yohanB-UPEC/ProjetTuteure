#ifndef PACKAGECONTROLLER
#define PACKAGECONTROLLER

#include <QtWidgets>

class PackageDialog;

class PackageController : public QObject {
    Q_OBJECT

    public:
        PackageController(PackageDialog *pkd);

    private:
        PackageDialog *m_pkd;

    public slots:
        void validate();
        bool caracteresSpeciaux();
        bool isExisted();
        void selectedItem(const QItemSelection &selected, const QItemSelection &deselected);
};

#endif
