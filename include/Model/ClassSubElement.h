#ifndef CLASSSUBELEMENT
#define CLASSSUBELEMENT

#include "ClassElement.h"

class ClassSubElement : public ClassElement {
	
	public:	
		ClassSubElement(QString label, QString scope, QString type):ClassElement(label,scope,type),mStatic(false),mTransient(false),mSynchronized(false),mVolatile(false){}
		// getter
		bool isStatic(){return this->mStatic;}
		bool isTransient(){return this->mTransient;}
		bool isSynchronized(){return this->mSynchronized;}
		bool isVolatile(){return this->mVolatile;}
		// setter
		void setStatic(bool isStatic){this->mStatic = isStatic;}
		void setTransient(bool isTransient){this->mTransient = isTransient;}
		void setSynchronized(bool isSynchronized){this->mSynchronized=isSynchronized;}
		void setVolatile(bool isVolatile){this->mVolatile = isVolatile;}
        virtual QString toString();
	private:
		bool mStatic;
		bool mTransient;
		bool mSynchronized;
		bool mVolatile;
};

#endif
