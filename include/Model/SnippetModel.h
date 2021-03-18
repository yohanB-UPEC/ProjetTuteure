#ifndef SNIPPETMODEL
#define SNIPPETMODEL

#include <QtWidgets>

class SnippetModel : public QAbstractListModel {
	Q_OBJECT
	public:
		SnippetModel();
		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	private:
		QList<QString> snippets;
};

#endif