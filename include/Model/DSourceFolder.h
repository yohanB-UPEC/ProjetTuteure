#ifndef DSOURCEFOLDER
#define DSOURCEFOLDER

#include "DFolder.h"


class DSourceFolder : public DFolder {
	
	public:
		DSourceFolder(QString label);
		DSourceFolder(QDomElement *e);
		QVariant getIcon();
		const QString className() const;
		
	private:
	
};

#endif