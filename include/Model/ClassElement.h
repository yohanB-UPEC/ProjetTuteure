#ifndef CLASSELEMENT
#define CLASSELEMENT

#include <QString>

class ClassElement{
	
	
	public:
        ClassElement(QString label, QString scope, QString type):mType(type),mLabel(label),mScope(scope),mFinal(false),mAbstract(false){}
		// getter
		QString type(){return this->mType;}
		QString label(){return this->mLabel;}
		QString scope(){return this->mScope;}
		bool isFinal(){return this->mFinal;}
		bool isAbstract(){return this->mAbstract;}
		// setter
		void setType(QString type){this->mType = type;}
		void setLabel(QString label){this->mLabel = label;}
		void setScope(QString scope){this->mScope = scope;}
		void setFinal(bool isFinal){this->mFinal = isFinal;}
		void setAbstract(bool isAbstract){this->mAbstract = isAbstract;}
		
	private:
		QString mType; 
		QString mLabel;
		QString mScope;  
		bool mFinal;
		bool mAbstract;
};
#endif
