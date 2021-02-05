#include "include/model/DPackage.h"

DPackage::DPackage(QString label): TreeItem(label){
	
}

QVariant DPackage::getIcon(){
	return QVariant(DIcons::package);
}