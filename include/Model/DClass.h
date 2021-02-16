#ifndef DCLASS
#define DCLASS

#include "DMethod.h"
#include "DAttribut.h"
#include <QRegularExpressionMatch>
#include <QRegularExpression>

class DClass : public ClassElement {
	
	
	public:
        DClass(QString label="", QString scope="", QString type="");
		~DClass();
		// getter
        QList<DClass*>& classes(){return this->mClasses;}
        QList<DAttribut*>& attributs(){return this->mAttributs;}
        QList<DMethod*>& methods(){return this->mMethods;}
        QList<QString>& superClasses(){return this->mSuperClasses;}
        QList<QString>& implementedClasses(){return this->mImplementedClasses;}
		// getter
        QList<DClass*> findClasses(QString regex);
        QList<DMethod*> findMethods(QString regex);
        QList<DAttribut*> findAttributs(QString regex);
		DMethod* getMethod(QString label,unsigned int nbArgs, ...);
		DAttribut* getAttribut(QString label);
        QString toString();
		
	private:
        QList<DClass*> mClasses;
        QList<DAttribut*> mAttributs;
        QList<DMethod*> mMethods;
        QList<QString> mSuperClasses;
        QList<QString> mImplementedClasses;
};

#endif
