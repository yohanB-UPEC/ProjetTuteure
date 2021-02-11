#include "include/Model/DSourceFolder.h"

DSourceFolder::DSourceFolder(QString label): TreeItem(label){
	
}
DSourceFolder::DSourceFolder(QDomElement *e): TreeItem(e){
	QDomNode n = e->firstChild();
	while(!n.isNull()){
		QDomElement c = n.toElement();
		if(!c.isNull()){
			if(c.tagName() == "DPackage"){
				this->appendChild(new DPackage(&c));
			}else{
				qDebug() << "fichier de config du projet incorrect balise:" << c.tagName() ;
				QMessageBox::critical(nullptr,"DSourceFolder::DSourceFolder(QDomElement *e): l.12","fichier de configuration du projet incorrect balise: " +c.tagName());
				return;
			}
		}
		n = n.nextSibling();
	}
}

QVariant DSourceFolder::getIcon(){
	return QVariant(DIcons::src_folder);
}

void DSourceFolder::save(QXmlStreamWriter *out){
	if(out == nullptr){
		if(m_parent != nullptr){
			m_parent->save();
		}
		return;
	}
	out->writeStartElement("DSourceFolder");
	out->writeAttribute("label",m_label);
	for(int i = 0; i < m_children.size();i++){
		m_children.at(i)->save(out);
	}
	out->writeEndElement();
}