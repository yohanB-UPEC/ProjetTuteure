#include "include/Model/Model.h"

Model::Model(): QAbstractItemModel(), root("root"), settings("config.ini",QSettings::IniFormat){
	settings.beginGroup("Projects");
	QStringList keys = settings.allKeys();
	for(int i = 0; i < keys.size(); i++){
		QVariant path = settings.value(keys.at(i),QVariant());
		if(!path.isNull() && path.isValid()){
			root.appendChild(new DProject(path.toString()));
		}
	}
	settings.endGroup();
	printf("Constructeur\n");
}

QModelIndex Model::index(int row, int column, const QModelIndex &parent) const {
	TreeItem* p;
	if(!parent.isValid()){
		p = (TreeItem*)&root;
	}else{
		p = (TreeItem*)parent.internalPointer();
	}
	TreeItem *child = p->child(row);
	if(child != nullptr){
		return createIndex(row,0,child);
	}
	return QModelIndex();
}

QModelIndex Model::parent(const QModelIndex &index) const{
	if(!index.isValid()){
		return QModelIndex();
	}
	TreeItem* parent = ((TreeItem*)index.internalPointer())->parent();
	if(parent == &root){
		return QModelIndex();
	}
	return createIndex(parent->row(),0,parent);
}

int Model::rowCount(const QModelIndex &parent) const{
	if(!parent.isValid()){
		return root.childCount();
	}
	TreeItem* i = (TreeItem*)parent.internalPointer();
	return i->childCount();
}

int Model::columnCount(const QModelIndex &parent) const{
	return 1;
}

QVariant Model::data(const QModelIndex &index, int role) const{
	if(!index.isValid()){
		return QVariant();
	}
	TreeItem* i = (TreeItem*)index.internalPointer();
	if (role == Qt::DisplayRole){	
		return QVariant(i->label());	
	}else if(role == Qt::DecorationRole){
		return i->getIcon();
	}
	
	return QVariant();
}

bool Model::hasChildren(const QModelIndex &parent) const{
	bool res;
	if(!parent.isValid()){
		res = root.hasChildren();
	}else{
		res = ((TreeItem*)parent.internalPointer())->hasChildren();
	}
	return res;
}

Qt::ItemFlags Model::flags(const QModelIndex &index) const{
	if (!index.isValid())
        return Qt::NoItemFlags;
	return (Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable);
}

bool Model::setData(const QModelIndex &index, const QVariant &value, int role){
	if(index.isValid()){
		if(role == Qt::DisplayRole){
			((TreeItem*)index.internalPointer())->setLabel(value.toString());
			emit dataChanged(index,index);
			return true;
		}
	}
	
	return false;
}

QVariant Model::headerData(int section, Qt::Orientation orientation,int role) const{
	if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return QVariant(root.label());

    return QVariant();
}

bool Model::insertRow(int row, TreeItem *item, const QModelIndex &parent){
	TreeItem *p;
	if(parent.isValid()){
		p = (TreeItem*)parent.internalPointer();
	}else{
		p = &root;
		settings.beginGroup("Projects");
		int key = settings.allKeys().size();
		settings.setValue(QString("pro"+key),item->getPath());
		settings.endGroup();
	}

	
	if(row > p->childCount()){
		row = p->childCount();
	}else if(row < 0){
		row = 0;
	}
	emit beginInsertRows(parent,row,row);
	p->appendChild(item, row);
	item->save();
	emit endInsertRows();
}

QModelIndex Model::getItem(QString path){
    QStringList l = path.split("/");
    QModelIndex res;
    TreeItem *tmp = &root;
    for(int i = 0; i < l.size();i++){
        tmp = tmp->getChild(l[i]);
        if(tmp == nullptr)
            break;
        res = createIndex(i,0,tmp);
    }
    return res;
}
