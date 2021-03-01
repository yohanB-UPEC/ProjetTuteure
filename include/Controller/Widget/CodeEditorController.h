#ifndef CODEEDITORCONTROLLER_H
#define CODEEDITORCONTROLLER_H

#include <QtWidgets>

class TreeItem;
class DCodeEditor;

class CodeEditorController : public QObject {
    Q_OBJECT
    public:
        CodeEditorController(DCodeEditor *view,TreeItem *item);
        CodeEditorController(DCodeEditor *view,QString path);
        void open();
        void save();
        bool close();
        bool isItem(TreeItem *test);
        bool isFile(const QString file);
    private slots:
        void rename(QString path);
        void fileSuppr();
    private:
        TreeItem *m_item;
        DCodeEditor *m_view;
        QString m_path;
};

#endif
