#ifndef DFOLDER
#define DFOLDER

#include "TreeItem.h"

class DFolder : public TreeItem {
	
	public:
		DFolder(QString label);
		DFolder(QDomElement *e);
		QVariant getIcon();
		void save(QXmlStreamWriter *out=nullptr);
	private:
	
};

#endif