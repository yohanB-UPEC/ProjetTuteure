#ifndef DPROJECT
#define DPROJECT

#include "TreeItem.h"
#include "DFolder.h"
#include "DSourceFolder.h"

class DProject : public TreeItem {
	
	public:
		DProject(QString label,QString path);
		DProject(QString path);
		QVariant getIcon();
		QString getPath();
		void save(QXmlStreamWriter *out=nullptr);
        bool setLabel(QString label);
	private:
		QString m_path;
};

#endif
