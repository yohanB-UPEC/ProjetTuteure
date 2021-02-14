#ifndef ENUMCONTROLLER_H
#define ENUMCONTROLLER_H

#include <QtWidgets>

class EnumDialog;

class EnumController : public QObject {
    Q_OBJECT

    public:
        EnumController(EnumDialog *ed);

    private:
        EnumDialog *m_ed;

    public slots:
        void validate();
        bool caracteresSpeciaux();
        bool isExisted();
        void parcourir();
        void parcourir2();
};

#endif
