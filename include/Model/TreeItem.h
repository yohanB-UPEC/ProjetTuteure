#ifndef TREEITEM
#define TREEITEM

#include <QtWidgets>
#include <QDomElement>
#include "DIcons.h"

class TreeItem{
	
	public:
		TreeItem(QString label=nullptr);
		TreeItem( QDomElement *e);
		virtual ~TreeItem();
		TreeItem* child(int row);
		TreeItem* parent(){return this->m_parent;}
		int childCount() const {return this->m_children.size();}
		QString label() const {return m_label;}
		bool hasChildren() const {return !m_children.isEmpty();}
		void setLabel(QString label){this->m_label = label;}
		void appendChild(TreeItem* item, int row = 999999);
		int row(){return (m_parent==nullptr)?m_parent->m_children.indexOf(this):0;}
		virtual QVariant getIcon();
		void setParent(TreeItem* parent = nullptr){this->m_parent = parent;}
		virtual QString getPath();
		virtual void save(QXmlStreamWriter *out=nullptr);
		virtual void create(QString *path=nullptr);
		
	protected:
		QList<TreeItem*> m_children;
		TreeItem* m_parent;
		QString m_label;
};

#endif