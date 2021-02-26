#ifndef MODEL
#define MODEL

#include <QtWidgets>
#include "TreeItem.h"
#include "DProject.h"
#include "DSourceFolder.h"
#include "DFolder.h"
#include "DPackage.h"
#include "ConsoleModel.h"


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
        QModelIndex getItem(QString path);
        QString getRelativePath(TreeItem* item);
        bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex(),bool deleteFiles=false);
        ConsoleModel* getConsole(){return &console;};
	public slots:
	
	private:
		TreeItem root;
		QSettings settings;
        ConsoleModel console;

};

#endif
