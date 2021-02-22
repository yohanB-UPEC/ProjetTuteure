#include "include/Model/DProject.h"

DProject::DProject(QString label, QString path): TreeItem(label), m_path(path),m_id(QUuid::createUuid().toString(QUuid::WithoutBraces)){
    qDebug() << "uuid= " << getId();
}
DProject::DProject(QString path): TreeItem(), m_path(path){
	QDomDocument doc(".javora");
	QFile file(path+"/.javora.jpml");
	if(!file.open(QIODevice::ReadOnly)){
		qDebug() << "impossible de lire le fichier de config du projet " <<  path+"/.javora.jpml";
        QMessageBox::critical(nullptr,"DProject::DProject(QString path): l.11","impossible de lire le fichier de configuration du projet: " +path+"/.javora.jpml");
		m_label="Error: Fichiers illisible";
		return;
	}
	if(!doc.setContent(&file)){
		file.close();
		return;
	}
	file.close();
	
	QDomElement root = doc.documentElement();
	QDomElement projet = root.lastChildElement("DProject");
    m_id = projet.attribute("id",QUuid::createUuid().toString(QUuid::WithoutBraces));
	m_label = projet.attribute("label","inconnue");
	QDomNode n = projet.firstChild();
	while(!n.isNull()){
		QDomElement e = n.toElement();
		if(!e.isNull()){
            if(e.tagName() == "DSourceFolder"){
                this->appendChild(new DSourceFolder(&e));
            }else if(e.tagName() == "DFolder"){
				this->appendChild(new DFolder(&e));
            }else if(e.tagName() == "TreeItem"){
				this->appendChild(new TreeItem(&e));
			}else{
				qDebug() << "fichier de config du projet incorrect balise:" << e.tagName() ;
				QMessageBox::critical(nullptr,"DProject::DProject(QString path): l.34","fichier de configuration du projet incorrect balise: " +e.tagName());
				return;
			}
		}
		n = n.nextSibling();
	}
}

QVariant DProject::getIcon(){
	return QVariant(DIcons::projet);
}

QString DProject::getPath(){
    return this->m_path;
}

void DProject::save(QXmlStreamWriter *out){
	QString path = getPath();
	QDir dir(path);
	if(dir.mkpath(path) == false){
		qDebug() << "impossible de creer les dossiers parents " <<  path;
		QMessageBox::critical(nullptr,"creation de dossier impossible","impossible de creer les dossier du path: " +path);
		return;
	}
    QFile file(path+"/.javora.jpml");
	if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
		qDebug() << "impossible d'écrire dans le fichier " << file.fileName() ;
		QMessageBox::critical(nullptr,"erreur d'ecriture","impossible d'écrire dans le fichier .javora.jpml");
		return;
	}
	qDebug() << "ecriture du fichier XML " << file.fileName() ;
	out = new QXmlStreamWriter(&file);
	out->setAutoFormatting(true);
	out->writeStartDocument();
	
	out->writeStartElement("Root");
	out->writeStartElement("DProject");
	out->writeAttribute("label",m_label);
	out->writeAttribute("path",m_path);
    out->writeAttribute("id",m_id);
	
	for(int i = 0; i < m_children.size();i++){
		m_children.at(i)->save(out);
	}
	
	out->writeEndElement();
	out->writeEndDocument();
	delete out;
	file.close();
}

bool DProject::setLabel(QString label){
    bool res;
    QFileInfo fi(m_path);
    m_path = fi.path()+"/"+label;
    if(!(res = TreeItem::setLabel(label))){
        QFileInfo fi(m_path);
        m_path = fi.path()+"/"+m_label;
    }
}

void DProject::removeFiles(){
    QDir dir(getPath());
    if(!dir.exists()){
        return;
    }
    dir.removeRecursively();
}

void DProject::createMakefile(){
    MakefileFactory mff(this);
    mff.writeMakefile();
}
