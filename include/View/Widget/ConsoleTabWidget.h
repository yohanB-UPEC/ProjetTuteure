#ifndef CONSOLETABWIDGET_H
#define CONSOLETABWIDGET_H

#include <QtWidgets>
#include "include/View/Widget/TitleBar.h"
#include "include/View/Widget/Console.h"
#include "include/Model/DIcons.h"
#include "include/Model/ConsoleModel.h"

class ConsoleTabWidget : public QStackedWidget {
    Q_OBJECT
    public:
        ConsoleTabWidget(TitleBar *title,ConsoleModel *model,QWidget *parent=nullptr);
        void addConsole(Console *c, const QString &label);
    public slots:
        void removeConsole(int index = -1);
    private slots:
        void openMenuAdd();
        void addConsole();
    private:
        TitleBar *m_title;
        QComboBox m_selection;
        QPushButton m_add;
        ConsoleModel *m_model;
};

#endif // CONSOLETABWIDGET_H
