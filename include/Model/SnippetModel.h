#ifndef SNIPPETMODEL
#define SNIPPETMODEL

#include <QtWidgets>

class SnippetModel : public QAbstractListModel {
	Q_OBJECT
	public:
		SnippetModel();
		int rowCount(const QModelIndex &parent = QModelIndex()) const;
		QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
        bool exist(const QString& name);
        bool addSnippet(const QString &name);
        bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
        const QString getText(const QModelIndex& index);

	private:
		QList<QString> snippets;
};

#endif
