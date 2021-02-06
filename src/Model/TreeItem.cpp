#include "include/Model/TreeItem.h"

TreeItem::TreeItem(QString label): m_parent(nullptr), m_label(label){
	
}

TreeItem::TreeItem(QDomElement *e): m_label(e->attribute("label","inconnue")){
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

QString TreeItem::getPath(){
	if(m_parent != nullptr){
		return m_parent->getPath() + "/" + this->m_label;
	}
	return QString();
}

void TreeItem::save(QXmlStreamWriter *out){
	if(out == nullptr){
		if(m_parent != nullptr){
			m_parent->save();
		}
		return;
	}
	out->writeStartElement("TreeItem");
	out->writeAttribute("label",m_label);
	out->writeEndElement();
}