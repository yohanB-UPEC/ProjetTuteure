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

void TreeItem::create(QString *path){
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
		QMessageBox::critical(nullptr,"TreeItem::create(QString *path): l.67","impossible de créer le fichier: " +file.absoluteFilePath());
		m_label="Error: Fichiers illisible";
	}
	f.close();
}

TreeItem* TreeItem::getChild(QString str){
    int size = m_children.size();
    for(int row = 0; row<size;row++){
        if(m_children.at(row)->label() == str ){
            return m_children.at(row);
        }
    }
    return nullptr;
}

bool TreeItem::setLabel(QString label){
    QFileInfo fi(getPath());
    if(!QFile::rename(fi.path()+"/"+m_label,fi.path()+"/"+label)){
        QMessageBox::warning(nullptr,"erreur renommage","impossible de renommer le fichier "+fi.path()+"/"+label);
        return false;
    }
    this->m_label = label;
    emit rename(fi.path()+"/"+label);
    propagRename();
    return true;
}

void TreeItem::propagRename(){
    QList<TreeItem*>::iterator next;
    for(next=m_children.begin();next != m_children.end();++next){
        emit (*next)->rename((*next)->getPath());
        (*next)->propagRename();
    }
}

bool TreeItem::exist(const QString& label){
    QList<TreeItem*>::iterator next;
    for(next=m_children.begin();next != m_children.end();++next){
        if((*next)->label() == label){
            return true;
        }
    }
    return false;
}

void TreeItem::propagSuppr(){
    QList<TreeItem*>::iterator next;
    for(next=m_children.begin();next != m_children.end();++next){
        emit (*next)->suppr();
        (*next)->propagSuppr();
    }
}

void TreeItem::removeChild(int row, bool deleteFiles){
    TreeItem *child = this->m_children.at(row);
    this->m_children.removeAt(row);
    emit child->suppr();
    child->propagSuppr();
    if(deleteFiles){
        child->removeFiles();
    }
    delete child;
}

void TreeItem::removeFiles(){
    QFile::remove(getPath());
}
