#include "include/Controller/Widget/SnippetDelegate.h"


SnippetDelegate::SnippetDelegate(QWidget *parent): QStyledItemDelegate(parent) {

}

bool SnippetDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index) {

    if(event->type() == QEvent::MouseMove){
        QMouseEvent *e = (QMouseEvent*)event;
        int x,y,w,h;
        h = option.rect.height();
        x = option.rect.right()-h;
        y = option.rect.top()+0.12*h;
        w = 0.8*h;
        h = 0.8*h;
        if( QRect(x, y,w,h).contains(e->pos()) || QRect(x-2*option.rect.height(), y,w,h).contains(e->pos()) ){
            QCursor c = ((QTreeView*)this->parent())->cursor();
            c.setShape(Qt::PointingHandCursor);
            ((QTreeView*)this->parent())->setCursor(c);
        }else{
            QCursor c = ((QTreeView*)this->parent())->cursor();
            c.setShape(Qt::ArrowCursor);
            ((QTreeView*)this->parent())->setCursor(c);
        }
    }else if(event->type() == QEvent::MouseButtonRelease){
        QMouseEvent *e = (QMouseEvent*)event;
        int x,y,w,h;
        h = option.rect.height();
        x = option.rect.right()-h;
        y = option.rect.top()+0.12*h;
        w = 0.8*h;
        h = 0.8*h;
        if( QRect(x, y,w,h).contains(e->pos())){
            emit remove(index);
        }else if(QRect(x-2*option.rect.height(), y,w,h).contains(e->pos())){
            emit copy(index);
        }
    }
}


void SnippetDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QStyledItemDelegate::paint(painter, option, index);
    int x,y,w,h;
    h = option.rect.height();
    x = option.rect.right()-h;
    y = option.rect.top()+0.12*h;
    w = 0.8*h;
    h = 0.8*h;
    DIcons::remove.paint(painter, x, y,w,h);
    x -= 2*option.rect.height();
    DIcons::copy.paint(painter, x, y,w,h);
}
