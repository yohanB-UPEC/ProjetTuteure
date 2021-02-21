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

void DPackage::create(QString *path){
	QDir dir;
	if(path == nullptr){
		dir.setPath(this->getPath());
	}else{
		QString p(m_label);
		p.replace(".","/");
		dir.setPath(*path+"/"+p);
	}
	qDebug() << "creation du dossier " << dir.path();
	dir.mkpath(dir.path());
}

bool DPackage::setLabel(QString label){
    QString path(label);
    path.replace(".","/");
    QString parentPath(this->m_parent->getPath());
    QString nPath(parentPath+"/"+path);
    QString oldPath(getPath());

    QDir dir(parentPath);
    if(!dir.mkpath(nPath)){
        QMessageBox::warning(nullptr,"erreur renommage","impossible créer l'arborescence du package "+label);
        return false;
    }

    dir.cd(oldPath);
    dir.setFilter(QDir::Files | QDir::Hidden);
    QFileInfoList list = dir.entryInfoList();
    for(int i = 0; i < list.size();i++){
        QFile::rename(list[i].absoluteFilePath(),nPath+"/"+list[i].fileName());
    }
    int tmp = m_label.count(".")+1;
    while(tmp > 0 && dir.isEmpty()){
        QString suppr(dir.dirName());
        dir.cd("..");
        dir.rmdir(suppr);
        tmp--;
    }

    this->m_label = label;
    emit rename(nPath);
    this->propagRename();
    return true;
}

void DPackage::removeFiles(){
    Q_CHECK_PTR(m_parent);
    QDir dir(getPath());
    if(!dir.exists()){
        return;
    }
    qDebug() << "suppression du package";
    int tmp = m_label.count(".");
    dir.removeRecursively();
    dir.cd("..");
    while(tmp >0 && dir.isEmpty()){
        QString name(dir.dirName());
        qDebug() << "remove le dossier " << name;
        dir.cd("..");
        dir.rmdir(name);
        tmp--;
    }
}
