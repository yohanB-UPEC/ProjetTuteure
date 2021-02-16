#ifndef FOLDERCONTROLLER_H
#define FOLDERCONTROLLER_H

#include <QtWidgets>
#include "include/Model/Model.h"

class FolderDialog;

class FolderController : public QObject {
    Q_OBJECT

    public:
        FolderController(Model *model, FolderDialog *fd);

    public slots:
        void selectedItem(const QItemSelection& selected, const QItemSelection& deselected);
        void validate();
        void createFolder();

    private:
        FolderDialog *m_fd;
        Model *m_model;
        QModelIndex m_chemin;
};

#endif
