#include "include/Model/DPackage.h"

DPackage::DPackage(QString label): TreeItem(label){
	
}
DPackage::DPackage(QDomElement *e): TreeItem(e){
	QDomNode n = e->firstChild();
	while(!n.isNull()){
		QDomElement c = n.toElement();
		if(!c.isNull()){
			if(c.tagName() == "DJavaFile"){
				this->appendChild(new DJavaFile(&c));
			}else{
				qDebug() << "fichier de config du projet incorrect balise:" << c.tagName() ;
				QMessageBox::critical(nullptr,"DPackage::DPackage(QDomElement *e): l.12","fichier de configuration du projet incorrect balise: " +c.tagName());
				return;
			}
		}
		n = n.nextSibling();
	}
}
QVariant DPackage::getIcon(){
	return QVariant(DIcons::package);
}

QString DPackage::getPath(){
	if(m_parent != nullptr){
		QString path(m_label);
		path.replace(".","/");
		return m_parent->getPath() + "/" + path;
	}
	return QString();
}

void DPackage::save(QXmlStreamWriter *out){
	if(out == nullptr){
		if(m_parent != nullptr){
			m_parent->save();
		}
		return;
	}
	out->writeStartElement("DPackage");
	out->writeAttribute("label",m_label);
	for(int i = 0; i < m_children.size();i++){
		m_children.at(i)->save(out);
	}
	out->writeEndElement();
}