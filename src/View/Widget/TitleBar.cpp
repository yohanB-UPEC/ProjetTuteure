#include "include/View/Widget/TitleBar.h"

TitleBar::TitleBar(QWidget *parent): QWidget(parent){
    m_layout.setColumnStretch(1,2);
    m_layout.addWidget(&m_title,0,0);
    this->setLayout(&m_layout);
    this->setProperty("titlebar", true);

    m_layout.setContentsMargins(0,0,0,0);
    this->setContentsMargins(0,0,0,0);
    m_title.setIndent(8);
}

void TitleBar::changeEvent(QEvent *event){
    if(event->type() == QEvent::ParentChange){
        m_parent = qobject_cast<QDockWidget*>(parentWidget());
        m_parent->setMinimumHeight(22);
        this->setMinimumHeight(19);
        this->setMaximumHeight(19);
        m_title.setText(m_parent->windowTitle());
    }
}

void TitleBar::paintEvent(QPaintEvent* event){
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void TitleBar::addLayout(QLayout *layout){

    qDebug() << "setLayout";
    this->m_layout.addLayout(layout,0,1);
}
