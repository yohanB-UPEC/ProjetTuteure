#include "include/Model/DJavaFile.h"

std::list<DClass*> DJavaFile::findClasses(QString regex){
	std::list<DClass*> res;
	QRegularExpression rec(regex);
	
	std::list<DClass*>::iterator dc;
	for(dc=this->mClasses.begin();dc!=this->mClasses.end();++dc){
		if(rec.match(dc->label()).hasMatch()){
			res.push_back(*dc);
		}
	}
	if(rec.match(this->mPublicClass.label()).hasMatch()){
		res.push_back(this->mPublicClass);
	}
	return res;
}

DJavaFile::~DJavaFile(){
	delete mPublicClass;
	while(!this->mClasses.empty()){
		delete this->mClasses.front();
		this->mClasses.pop_front();
	}
}