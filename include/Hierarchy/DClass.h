#ifndef DCLASS
#define DCLASS

#include "DMethod.h"
#include "DAttribut.h"
#include <QRegularExpressionMatch>
#include <QRegularExpression>

class DClass : public ClassElement {
	
	
	public:
		DClass(QString label, QString scope, QString type);
		~DClass();
		std::list<DClass*>& classes(){return this->mClasses;}
		std::list<DAttribut*>& attributs(){return this->mAttributs;}
		std::list<DMethod*>& methods(){return this->mMethods;}
		std::list<QString>& superClasses(){return this->mSuperClasses;}
		std::list<QString>& implementedClasses(){return this->mImplementedClasses;}
		std::list<DClass*> findClasses(QString regex);
		std::list<DMethod*> findMethods(QString regex);
		std::list<DAttribut*> findAttributs(QString regex);
		DMethod* getMethod(QString label,unsigned int nbArgs, ...);
		DAttribut* getAttribut(QString label);
		
	private:
		std::list<DClass*> mClasses;
		std::list<DAttribut*> mAttributs;
		std::list<DMethod*> mMethods;
		std::list<QString> mSuperClasses;
		std::list<QString> mImplementedClasses;
};

#endif