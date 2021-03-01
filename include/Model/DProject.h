#ifndef DPROJECT
#define DPROJECT

#include "TreeItem.h"
#include "DFolder.h"
#include "DSourceFolder.h"
#include "MakefileFactory.h"

class DProject : public TreeItem {
	
	public:
		DProject(QString label,QString path);
		DProject(QString path);
		QVariant getIcon();
		QString getPath();
        QString getId() {return this->m_id;}
		void save(QXmlStreamWriter *out=nullptr);
        bool setLabel(QString label);
        void createMakefile();
    protected:
        void removeFiles();

	private:
		QString m_path;
        QString m_id;
};

#endif
