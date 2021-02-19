#ifndef CODEEDITORCONTROLLER_H
#define CODEEDITORCONTROLLER_H

#include <QtWidgets>

class TreeItem;
class DCodeEditor;

class CodeEditorController : public QObject {
    Q_OBJECT
    public:
        CodeEditorController(TreeItem *item, DCodeEditor *view);
        void open();
        void save();
        bool close();
        bool isItem(TreeItem *test);
    private slots:
        void rename(QString path);
    private:
        TreeItem *m_item;
        DCodeEditor *m_view;
        QString m_path;
};

#endif // CODEEDITORCONTROLLER_H
