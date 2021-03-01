#include "include/View/Widget/TitleBar.h"

TitleBar::TitleBar(QWidget *parent): QWidget(parent){
    m_layout.setColumnStretch(1,2);
    m_layout.addWidget(&m_title,0,0);
    this->setLayout(&m_layout);

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
    QPainter p(this);
    QRect rect = this->rect();
    rect.setWidth(rect.width()-p.pen().width());
    rect.setHeight(rect.height()-p.pen().width());
    p.fillRect(rect,QColor(218,218,218));
    p.setPen(QColor(185,185,185));
    p.drawRect(rect);


}

void TitleBar::addLayout(QLayout *layout){

    qDebug() << "setLayout";
    this->m_layout.addLayout(layout,0,1);
}
