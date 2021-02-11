#ifndef INTERFACECONTROLLER_H
#define INTERFACECONTROLLER_H

#include <QtWidgets>

class InterfaceDialog;

class InterfaceController : public QObject {
    Q_OBJECT

    public:
        InterfaceController(InterfaceDialog *ifd);

    private:
        InterfaceDialog *m_ifd;

    public slots:
        void validate();
        bool caracteresSpeciaux();
        bool isExisted();
        void parcourir();
        void parcourir2();
};

#endif
