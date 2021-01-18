#ifndef DJAVAFILE
#define DJAVAFILE

#include "include/Hierarchy/DClass.h"

class DJavaFile{
	public:
		DJavaFile(QString label): mLabel(label){}
		~DJavaFile();
		std::list<DClass*> findClasses(QString regex);
		
		

		
		
	public:
		void setLabel(QString & const label){this->mLabel = label;}
		void setPackage(QString & const package){this->mPackage = package;}
		DClass* publicClass(){return this->mPublicClass;};
		QString label(){return this->mLabel;}
		QString package(){return this->mPackage;}
		void setPublicClass(DClass * publicClass){this->mPublicClass = publicClass;}
		std::list<QString>& imports(){return this->mImports;}
		
	private:
		DClass* mPublicClass;
		std::list<DClass*> mClasses;
		QString mLabel;
		QString mPackage;
		std::list<QString> mImports
			
};
#endif