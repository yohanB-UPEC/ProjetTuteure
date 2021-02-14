#include "include/Model/DSourceFolder.h"

DSourceFolder::DSourceFolder(QString label): DFolder(label){
	
}
DSourceFolder::DSourceFolder(QDomElement *e): DFolder(e){

}

QVariant DSourceFolder::getIcon(){
	return QVariant(DIcons::src_folder);
}

const QString DSourceFolder::className() const{
	return "DSourceFolder";
}