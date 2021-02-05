#include "include/model/DProject.h"

DProject::DProject(QString label): TreeItem(label){
	
}

QVariant DProject::getIcon(){
	return QVariant(DIcons::projet);
}