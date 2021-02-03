#ifndef MODEL
#define MODEL

#include <QtWidgets>
#include "TreeItem.h"
#include "DProject.h"
#include "DSourceFolder.h"
#include "DFolder.h"
#include "DPackage.h"

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
		QVariant headerData(int section, Qt::Orientation orientation,int role) const;
		bool insertRow(int row, TreeItem *item, const QModelIndex &parent = QModelIndex());

	public slots:
	
	private:
		TreeItem root;
	
};
#endif