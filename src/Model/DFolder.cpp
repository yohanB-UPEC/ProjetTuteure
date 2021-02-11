#include "include/Model/DFolder.h"

DFolder::DFolder(QString label): TreeItem(label){
	
}

DFolder::DFolder(QDomElement *e): TreeItem(e){
	QDomNode n = e->firstChild();
	while(!n.isNull()){
		QDomElement c = n.toElement();
		if(!c.isNull()){
			if(c.tagName() == "DFolder"){
				this->appendChild(new DFolder(&c));
			}else if(c.tagName() == "TreeItem"){
				this->appendChild(new TreeItem(&c));
			}else{
				qDebug() << "fichier de config du projet incorrect balise:" << c.tagName() ;
				QMessageBox::critical(nullptr,"DFolder::DFolder(QDomElement *e): l.17","fichier de configuration du projet incorrect balise: " +c.tagName());
				return;
			}
		}
		n = n.nextSibling();
	}
}

QVariant DFolder::getIcon(){
	return QVariant(DIcons::folder);
}

void DFolder::save(QXmlStreamWriter *out){
	if(out == nullptr){
		if(m_parent != nullptr){
			m_parent->save();
		}
		return;
	}
	out->writeStartElement("DFolder");
	out->writeAttribute("label",m_label);
	for(int i = 0; i < m_children.size();i++){
		m_children.at(i)->save(out);
	}
	out->writeEndElement();
}