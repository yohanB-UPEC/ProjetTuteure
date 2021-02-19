#ifndef FILTEREDMODEL_H
#define FILTEREDMODEL_H

#include <QtWidgets>
#include "Javora.h"
#include "Model.h"

class FilteredModel : public QSortFilterProxyModel{

    public:
        FilteredModel(QFlags<Javora::ModelType> filtre = Javora::Project);
        bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
        Qt::ItemFlags flags(const QModelIndex &index) const;
    private:
        QFlags<Javora::ModelType> m_filtre;

};

#endif // FILTEREDMODEL_H
