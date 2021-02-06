#ifndef DSOURCEFOLDER
#define DSOURCEFOLDER

#include "TreeItem.h"
#include "DPackage.h"

class DSourceFolder : public TreeItem {
	
	public:
		DSourceFolder(QString label);
		DSourceFolder(QDomElement *e);
		QVariant getIcon();
		void save(QXmlStreamWriter *out=nullptr);
		
	private:
	
};

#endif