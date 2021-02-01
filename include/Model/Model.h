#ifndef MODEL
#define MODEL

#include <QtWidgets>
#include "TreeItem.h"


class Model : public QAbstractItemModel{
	Q_OBJECT
	
	public:
		Model();
		QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
		QModelIndex parent(const QModelIndex &index) const;
		int rowCount(const QModelIndex &parent=QModelIndex()) const;
		int columnCount(const QModelIndex &parent = QModelIndex()) const;
		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
		bool hasChildren(const QModelIndex &parent = QModelIndex()) const;
		Qt::ItemFlags flags(const QModelIndex &index) const;
		bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
		
	public slots:
	
	private:
		TreeItem root;
	
};
#endif