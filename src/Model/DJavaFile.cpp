#include "include/Model/DJavaFile.h"

DJavaFile::DJavaFile(QDomElement *e): TreeItem(e){
	
}

DJavaFile::~DJavaFile(){
    while(!this->m_Classes.empty()){
        delete this->m_Classes.front();
        this->m_Classes.pop_front();
    }
}

QVariant DJavaFile::getIcon(){
	return QVariant(DIcons::java_file);
}

void DJavaFile::save(QXmlStreamWriter *out){
    if(out == nullptr){
        if(m_parent != nullptr){
            m_parent->save();
        }
        return;
    }
    out->writeStartElement("DJavaFile");
    out->writeAttribute("label",m_label);
    out->writeEndElement();
}

void DJavaFile::setPublicClass(DClass * publicClass){
    this->m_PublicClass = publicClass;
    this->m_Classes.push_front(publicClass);
}


QList<DClass*> DJavaFile::findClasses(QString regex){
    QList<DClass*> res;
	QRegularExpression rec(regex);
	
    QList<DClass*>::iterator dc;
    for(dc=this->m_Classes.begin();dc!=this->m_Classes.end();++dc){
		if(rec.match((*dc)->label()).hasMatch()){
			res.push_back(*dc);
		}
	}
    if(rec.match(this->m_PublicClass->label()).hasMatch()){
        res.push_back(this->m_PublicClass);
	}
	return res;
}


void DJavaFile::create(QString *path){
    QFileInfo file;
    if(path == nullptr){
        file.setFile(this->getPath());
    }else{
        file.setFile(*path+"/"+m_label);
    }

    QDir dir = file.absoluteDir();
    dir.mkpath(dir.path());
    qDebug() << "creation du fichier " << file.absoluteFilePath();
    QFile f(file.absoluteFilePath());
    if(!f.open(QIODevice::WriteOnly)){
        QMessageBox::critical(nullptr,"DJavaFile::create(QString *path): l.41","impossible de créer le fichier: " +file.absoluteFilePath());
        m_label="Error: Fichiers illisible";
    }
    QTextStream out(&f);

    out << "package " << m_parent->label() << ";\n\n";
    for(int i = 0; i < m_Classes.size();i++){
        out << m_Classes[i]->toString();
    }
    f.close();
}

bool DJavaFile::setLabel(QString label){
    if(!label.endsWith(".java")){
        label.append(".java");
    }
    return TreeItem::setLabel(label);
}
