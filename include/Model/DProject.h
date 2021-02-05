#ifndef DPROJECT
#define DPROJECT

#include "TreeItem.h"

class DProject : public TreeItem {
	
	public:
		DProject(QString label);
		QVariant getIcon();
	private:
	
};

#endif