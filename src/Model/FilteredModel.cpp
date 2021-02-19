#include "include/Model/FilteredModel.h"

FilteredModel::FilteredModel(QFlags<Javora::ModelType> filtre): QSortFilterProxyModel(), m_filtre(filtre){
}


bool FilteredModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const{
    QModelIndex index = sourceModel()->index(source_row, 0, source_parent);
    if(!index.isValid()){
        return false;
    }

    TreeItem *item = (TreeItem*)index.internalPointer();
    if((typeid(*item) == typeid(DProject) && m_filtre.testFlag(Javora::Project)) ||
       (typeid(*item) == typeid(DFolder) && m_filtre.testFlag(Javora::Folder)) ||
       (typeid(*item) == typeid(DSourceFolder) && m_filtre.testFlag(Javora::SourceFolder)) ||
       (typeid(*item) == typeid(DPackage) && m_filtre.testFlag(Javora::Package)) ||
       (typeid(*item) == typeid(DJavaFile) && m_filtre.testFlag(Javora::JavaFile)) ||
       (typeid(*item) == typeid(TreeItem) && m_filtre.testFlag(Javora::TreeItem))  ){
            return true;
    }
    return false;
}

Qt::ItemFlags FilteredModel::flags(const QModelIndex &index) const{
    if (!index.isValid())
        return Qt::NoItemFlags;
    return (Qt::ItemIsEnabled | Qt::ItemIsSelectable);
}
