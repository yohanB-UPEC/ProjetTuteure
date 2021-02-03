#include "include/Model/Model.h"

Model::Model(): QAbstractItemModel(), root("root"){
	DProject *projet = new DProject("Javora");
	DSourceFolder *src = new DSourceFolder("src");
	DFolder *res = new DFolder("res");
	DPackage *package = new DPackage("fr.SylarAdes.javora");
	TreeItem *file1 = new TreeItem("Fichier #1");
	TreeItem *file2 = new TreeItem("Fichier #2");
	TreeItem *file3 = new TreeItem("Fichier #3");
	TreeItem *img1 = new TreeItem("Image #1");
	TreeItem *img2 = new TreeItem("Image #2");
	TreeItem *make = new TreeItem("Makefile");
	
	package->appendChild(file1);
	package->appendChild(file2);
	package->appendChild(file3);	
	src->appendChild(package);
	res->appendChild(img1);
	res->appendChild(img2);
	projet->appendChild(src);
	projet->appendChild(res);
	projet->appendChild(make);
	root.appendChild(projet);
	root.setLabel("root");
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
	}

	
	if(row > p->childCount()){
		row = p->childCount();
	}else if(row < 0){
		row = 0;
	}
	emit beginInsertRows(parent,row,row);
	p->appendChild(item, row);
	emit endInsertRows();
}
