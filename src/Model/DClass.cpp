#include "include/Model/DClass.h"

DClass::DClass(QString label, QString scope, QString type): ClassElement(label,scope,type){
}
DClass::~DClass(){
	printf("destruction d'une classe\n");
	while(!this->mMethods.empty()){
		delete this->mMethods.front();
		this->mMethods.pop_front();
	}
	while(!this->mAttributs.empty()){
		delete this->mAttributs.front();
		this->mAttributs.pop_front();
	}
	while(!this->mClasses.empty()){
		delete this->mClasses.front();
		this->mClasses.pop_front();
	}
}

std::list<DClass*> DClass::findClasses(QString regex){
	std::list<DClass*> res;
	QRegularExpression rec(regex);
	
	std::list<DClass*>::iterator dc;
	for(dc=this->mClasses.begin();dc!=this->mClasses.end();++dc){
		if(rec.match((*dc)->label()).hasMatch()){
			res.push_back(*dc);
		}
	}
	return res;
}

std::list<DMethod*> DClass::findMethods(QString regex){
	std::list<DMethod*> res;
	QRegularExpression rec(regex);
	
	std::list<DMethod*>::iterator dm;
	for(dm=this->mMethods.begin();dm!=this->mMethods.end();++dm){
		if(rec.match((*dm)->label()).hasMatch()){
			res.push_back(*dm);
		}
	}
	return res;
}

std::list<DAttribut*> DClass::findAttributs(QString regex){
	std::list<DAttribut*> res;
	QRegularExpression rec(regex);
	
	std::list<DAttribut*>::iterator da;
	for(da=this->mAttributs.begin();da!=this->mAttributs.end();++da){
		if(rec.match((*da)->label()).hasMatch()){
			res.push_back(*da);
		}
	}
	return res;
}

DMethod* DClass::getMethod(QString label,unsigned int nbArgs, ...){
	va_list ap;
	va_start(ap,nbArgs);
	std::list<DMethod*> methods = this->findMethods(label);
	unsigned int count = 0;

	while(count <  nbArgs){
		QString tmp(va_arg(ap, char*));
		std::list<DMethod*>::iterator j = methods.begin();
		
		while(j != methods.end()){			
			if((*j)->parametres().size() != nbArgs || ((*j)->parametres())[count]->type() != tmp)
				j = methods.erase(j);
			else
				++j;
		}
		count++;
	}
	if(!methods.empty()){
		return methods.front();
	}
	return nullptr;
}

DAttribut* DClass::getAttribut(QString label){
	for(DAttribut* & da : this->mAttributs){
		if(da->label() == label){
			return da;
		}
	}
	return nullptr;
}