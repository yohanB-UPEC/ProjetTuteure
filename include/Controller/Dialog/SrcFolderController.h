#ifndef SRCFOLDERCONTROLLER_H
#define SRCFOLDERCONTROLLER_H

#include <QtWidgets>

class SrcFolderDialog;

class SrcFolderController : public QObject {
    Q_OBJECT

    public:
        SrcFolderController(SrcFolderDialog *sfd);

    public slots:
        void parcourir();
        void validate();
        bool caracteresSpeciaux();
        bool isExisted();

    private:
        SrcFolderDialog *m_sfd;
};

#endif
