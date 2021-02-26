#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QtWidgets>
#include <QDockWidget>

class TitleBar : public QWidget {
    Q_OBJECT
    public:
        TitleBar(QWidget *parent = nullptr);
        void addLayout(QLayout *layout);

    protected:
        void changeEvent(QEvent *event);
        void paintEvent(QPaintEvent* event);

    private:
        QLabel m_title;
        QDockWidget *m_parent;
        QGridLayout m_layout;
};

#endif // TITLEBAR_H
