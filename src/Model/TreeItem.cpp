#include "include/Model/TreeItem.h"

TreeItem::TreeItem(TreeItem* parent): m_parent(parent){
	
}
TreeItem::~TreeItem(){
	while (!m_children.isEmpty())
		delete m_children.takeFirst();
}

TreeItem* TreeItem::child(int row){
	if(row < 0 && row < m_children.size()){
		return m_children.at(row);
	}
	return nullptr;
}