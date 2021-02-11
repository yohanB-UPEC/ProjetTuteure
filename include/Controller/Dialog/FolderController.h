#ifndef FOLDERCONTROLLER_H
#define FOLDERCONTROLLER_H

#include <QtWidgets>

class FolderDialog;

class FolderController : public QObject {
    Q_OBJECT

    public:
        FolderController(FolderDialog *fd);

    public slots:
        void parcourir();
        void validate();
        bool caracteresSpeciaux();
        bool isExisted();

    private:
        FolderDialog *m_fd;
};

#endif
