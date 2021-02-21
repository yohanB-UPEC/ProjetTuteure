#ifndef DFOLDER
#define DFOLDER

#include "TreeItem.h"
#include "DPackage.h"

class DFolder : public TreeItem {
	
	public:
		DFolder(QString label);
		DFolder(QDomElement *e);
		QVariant getIcon();
		void save(QXmlStreamWriter *out=nullptr);
		virtual const QString className() const;
		void create(QString *path =nullptr);

    protected:
        void removeFiles();

	private:
	
};

#endif
