#ifndef DJAVAFILE
#define DJAVAFILE

#include "TreeItem.h"
#include <QDomElement>
#include "DClass.h"


class DJavaFile : public TreeItem{
	public:
		DJavaFile(QDomElement *e);
		DJavaFile(QString label): TreeItem(label){}		
		~DJavaFile();

		// setter
        void setPublicClass(DClass * publicClass);
        void addImport(QString import){this->m_Imports.push_front(import);}
        void addClass(DClass *c){this->m_Classes.push_back(c);}
		// getter
        DClass* publicClass(){return this->m_PublicClass;};
        QList<QString>& imports(){return this->m_Imports;}
		QVariant getIcon();
        QList<DClass*> findClasses(QString regex);

    public:
        void create(QString *path=nullptr);
        void save(QXmlStreamWriter *out);
        bool setLabel(QString label);
		
	private:
        DClass* m_PublicClass;
        QList<DClass*> m_Classes;
        QList<QString> m_Imports;
			
};
#endif
