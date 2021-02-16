#include "include/Model/DSourceFolder.h"

DSourceFolder::DSourceFolder(QString label): DFolder(label){
	
}
DSourceFolder::DSourceFolder(QDomElement *e): DFolder(e->attribute("label","inconnue")){
    QDomNode n = e->firstChild();
    while(!n.isNull()){
        QDomElement c = n.toElement();
        if(!c.isNull()){
            if(c.tagName() == "DPackage"){
                this->appendChild(new DPackage(&c));
            }else{
                qDebug() << "className=" << className();
                qDebug() << "fichier de config du projet incorrect balise:" << c.tagName() ;
                QMessageBox::critical(nullptr,"DFolder::DFolder(QDomElement *e): l.17","fichier de configuration du projet incorrect balise: " +c.tagName());
                return;
            }
        }
        n = n.nextSibling();
    }
}

QVariant DSourceFolder::getIcon(){
	return QVariant(DIcons::src_folder);
}

const QString DSourceFolder::className() const{
	return "DSourceFolder";
}
