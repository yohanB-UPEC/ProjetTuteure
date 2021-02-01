#ifndef DMETHOD
#define DMETHOD

#include "ClassSubElement.h"
#include <QVector>
#include <memory>

class Parametre 
{
	public:
		Parametre(QString type=nullptr, QString label=nullptr): mType(type),mLabel(label){}
		~Parametre(){printf("destruction du parametre\n");}
		
		// setter
		void setType(QString& type){this->mType = type;}
		void setLabel(QString& label){this->mLabel = label;}
		// getter
		QString type(){return this->mType;}
		QString label(){return this->mLabel;}

	private:
		QString mType;
		QString mLabel;
};

class DMethod : public ClassSubElement {
	
	public:
		DMethod(QString label, QString scope, QString type): ClassSubElement(label,scope,type), mParametres(){}
		~DMethod(){
			printf("destruction de la méthode\n");
			while(!this->mParametres.empty()){
				delete this->mParametres.back();
				this->mParametres.pop_back();
			}
		}
		
		void addParametre(QString type, QString label){this->mParametres.push_back(new Parametre(type,label));}
		std::vector<Parametre*>& parametres(){return this->mParametres;}
		
	private:
		std::vector<Parametre*> mParametres;

};

#endif