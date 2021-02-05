#ifndef DSOURCEFOLDER
#define DSOURCEFOLDER

#include "TreeItem.h"

class DSourceFolder : public TreeItem {
	
	public:
		DSourceFolder(QString label);
		QVariant getIcon();
	private:
	
};

#endif