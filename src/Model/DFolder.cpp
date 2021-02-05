#include "include/model/DFolder.h"

DFolder::DFolder(QString label): TreeItem(label){
	
}

QVariant DFolder::getIcon(){
	return QVariant(DIcons::folder);
}