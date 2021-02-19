#ifndef DATTRIBUT
#define DATTRIBUT

#include "ClassSubElement.h"

class DAttribut : public ClassSubElement {
	
	public:
		DAttribut(QString label, QString scope, QString type): ClassSubElement(label,scope,type){}
        QString toString();
	private:

};

#endif
