#ifndef TREEITEM
#define TREEITEM

#include <QtWidgets>

class TreeItem{
	
	public:
		TreeItem(TreeItem* parent = nullptr);
		~TreeItem();
		TreeItem* child(int row);
		TreeItem* parent(){return this->m_parent;}
		int childCount() const {return this->m_children.size();}
		QString label() const {return m_label;}
		bool hasChildren() const {return !m_children.isEmpty();}
		void setLabel(QString label){this->m_label = label;}
		void appendChild(TreeItem* item){this->m_children.push_back(item);}
		int row(){return (m_parent==nullptr)?m_parent->m_children.indexOf(this):0;}
		
	private:
		QList<TreeItem*> m_children;
		TreeItem* m_parent;
		QString m_label;
};

#endif