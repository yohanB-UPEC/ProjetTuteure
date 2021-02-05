#include "include/model/DSourceFolder.h"

DSourceFolder::DSourceFolder(QString label): TreeItem(label){
	
}

QVariant DSourceFolder::getIcon(){
	return QVariant(DIcons::src_folder);
}