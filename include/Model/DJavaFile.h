#ifndef DJAVAFILE
#define DJAVAFILE

#include "DClass.h"

class DJavaFile{
	public:
		DJavaFile(QString label): mLabel(label){}
		~DJavaFile();
		// setter
		void setLabel(QString & label){this->mLabel = label;}
		void setPackage(QString & package){this->mPackage = package;}
		void setPublicClass(DClass * publicClass){this->mPublicClass = publicClass;}
		void addImport(QString & import){this->mImports.push_front(import);}
		// getter
		DClass* publicClass(){return this->mPublicClass;};
		QString label(){return this->mLabel;}
		QString package(){return this->mPackage;}
		std::list<QString>& imports(){return this->mImports;}
		
			
	public:
		std::list<DClass*> findClasses(QString regex);

		
	private:
		DClass* mPublicClass;
		std::list<DClass*> mClasses;
		QString mLabel;
		QString mPackage;
		std::list<QString> mImports;
			
};
#endif