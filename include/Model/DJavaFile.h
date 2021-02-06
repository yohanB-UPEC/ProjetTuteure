#ifndef DJAVAFILE
#define DJAVAFILE

#include "TreeItem.h"
#include <QDomElement>
#include "DClass.h"


class DJavaFile : public TreeItem{
	public:
		DJavaFile(QDomElement *e);
		DJavaFile(QString label): TreeItem(label){}
		
		~DJavaFile();
		// setter
		void setPublicClass(DClass * publicClass){this->mPublicClass = publicClass;}
		void addImport(QString & import){this->mImports.push_front(import);}
		// getter
		DClass* publicClass(){return this->mPublicClass;};
		std::list<QString>& imports(){return this->mImports;}
		
		QVariant getIcon();
		std::list<DClass*> findClasses(QString regex);

		
	private:
		DClass* mPublicClass;
		std::list<DClass*> mClasses;
		std::list<QString> mImports;
			
};
#endif