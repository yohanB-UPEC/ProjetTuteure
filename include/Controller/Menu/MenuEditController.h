#ifndef MENUEDITCONTROLLER_H
#define MENUEDITCONTROLLER_H

#include <QtWidgets>
#include "include/View/Widget/DCodeEditor.h"
class MenuEdit;

class MenuEditController : public QObject {
    Q_OBJECT

    public:
        MenuEditController(MenuEdit *me);

    private:
        MenuEdit *m_me;

    public slots:
        void s_Copy();
        void s_Paste();
        void s_Cut();
        void s_SelectAll();
        void s_Undo();
        void s_Redo();
        void s_Search();
        void s_SearchNext();
        void s_SearchPrev();
        void s_Suppr();
        void find(QString mot);
        void s_Replace();
        void replaceAll();
};

#endif
