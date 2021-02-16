#ifndef DPACKAGE
#define DPACKAGE

#include "TreeItem.h"
#include "DJavaFile.h"

class DPackage : public TreeItem {
	
	public:
		DPackage(QString label);
		DPackage(QDomElement *e);
		QVariant getIcon();
		QString getPath();
		void save(QXmlStreamWriter *out=nullptr);
        void create(QString *path=nullptr);
		
	private:
	
};

#endif
