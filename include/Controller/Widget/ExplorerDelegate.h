#ifndef EXPLORERDELEGATE_H
#define EXPLORERDELEGATE_H

#include <QtWidgets>
#include "include/Model/Model.h"

class ExplorerDelegate: public QStyledItemDelegate{

    public:
        ExplorerDelegate();
        void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    private:
};

#endif
