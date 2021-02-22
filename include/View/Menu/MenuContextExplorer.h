#ifndef MENUCONTEXTEXPLORER_H
#define MENUCONTEXTEXPLORER_H

#include "include/Model/Model.h"

class Fenetre;

class MenuContextExplorer : public QMenu{
    Q_OBJECT
    public:
        MenuContextExplorer(QModelIndex item, Model *model, Fenetre *fen);

    public slots:
        void s_rename();
        void s_suppr();
        void s_makefile();

    private:
        QModelIndex m_item;
        Model *m_model;
        Fenetre *m_fen;
};

#endif // MENUCONTEXTEXPLORER_H
