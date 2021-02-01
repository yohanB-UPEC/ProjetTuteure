#include "include/Model/Model.h"

Model::Model(): QAbstractItemModel(){
	TreeItem *projet = new TreeItem(&root);
	projet->setLabel("Javora");
	
	TreeItem *src = new TreeItem(projet);
	src->setLabel("src");
	
	TreeItem *package = new TreeItem(src);
	package->setLabel("fr.SylarAdes.javora");
	
	TreeItem *file1 = new TreeItem(package);
	file1->setLabel("Fichier #1");
	TreeItem *file2 = new TreeItem(package);
	file2->setLabel("Fichier #2");
	TreeItem *file3 = new TreeItem(package);
	file3->setLabel("Fichier #3");
	
	package->appendChild(file1);
	package->appendChild(file2);
	package->appendChild(file3);	
	src->appendChild(package);
	projet->appendChild(src);
	root.appendChild(projet);
	
}

QModelIndex Model::index(int row, int column, const QModelIndex &parent) const {
	TreeItem* p;
	if(!parent.isValid()){
		p = (TreeItem*)&root;
	}else{
		p = (TreeItem*)parent.internalPointer();
	}
	printf("index\n");
	TreeItem *child = p->child(row);
	if(child){
		printf("index = %s\n", child->label().toUtf8().constData());
		return createIndex(row,column,child);
	}
	return QModelIndex();
}

QModelIndex Model::parent(const QModelIndex &index) const{
	if(!index.isValid()){
		return QModelIndex();
	}
	TreeItem* i = (TreeItem*)index.internalPointer();
	TreeItem* parent = i->parent();
	if(parent == &root){
		return QModelIndex();
	}
	return createIndex(parent->row(),0,parent);
}

int Model::rowCount(const QModelIndex &parent) const{
	if(!parent.isValid()){
		return 0;
	}
	TreeItem* i = (TreeItem*)parent.internalPointer();
	return i->childCount();
}

int Model::columnCount(const QModelIndex &parent) const{
	return 0;
}

QVariant Model::data(const QModelIndex &index, int role) const{
	if(!index.isValid()){
		return QVariant();
	}
	TreeItem* i = (TreeItem*)index.internalPointer();
	return QVariant(i->label());
}

bool Model::hasChildren(const QModelIndex &parent) const{
	if(!parent.isValid()){
		return false;
	}
	return ((TreeItem*)parent.internalPointer())->hasChildren();
}

Qt::ItemFlags Model::flags(const QModelIndex &index) const{
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