#include "include/Model/TreeItem.h"

TreeItem::TreeItem(QString label): m_label(label){
	
}
TreeItem::~TreeItem(){
	while (!m_children.isEmpty())
		delete m_children.takeFirst();
}
void TreeItem::appendChild(TreeItem* item,int row){
	if(row >= this->m_children.size()){
		this->m_children.push_back(item);
	}else if(row <= 0){
		this->m_children.push_front(item);
	}else{
		this->m_children.insert(row,item);
	}
	
	item->setParent(this);
}

TreeItem* TreeItem::child(int row){
	if(row >= 0 && row < m_children.size()){
		return m_children.at(row);
	}
	return nullptr;
}

QVariant TreeItem::getIcon(){
	return QVariant(DIcons::text_file);
}