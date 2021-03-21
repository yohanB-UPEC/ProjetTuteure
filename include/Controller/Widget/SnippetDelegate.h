#ifndef SNIPPETDELEGATE_H
#define SNIPPETDELEGATE_H

#include <QtWidgets>
#include "include/Model/DIcons.h"

class SnippetDelegate : public QStyledItemDelegate {
    Q_OBJECT
    public:
        SnippetDelegate(QWidget *parent = nullptr);
        void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
        bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) override;
    signals:
        void remove(const QModelIndex&);
        void copy(const QModelIndex&);
    private:

};

#endif // SNIPPETDELEGATE_H
