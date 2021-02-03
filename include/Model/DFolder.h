#ifndef DFOLDER
#define DFOLDER

#include "TreeItem.h"

class DFolder : public TreeItem {
	
	public:
		DFolder(QString label);
		QVariant getIcon();
	private:
	
};

#endif