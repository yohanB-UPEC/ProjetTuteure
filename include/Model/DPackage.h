#ifndef DPACKAGE
#define DPACKAGE

#include "TreeItem.h"

class DPackage : public TreeItem {
	
	public:
		DPackage(QString label);
		QVariant getIcon();
		
	private:
	
};

#endif