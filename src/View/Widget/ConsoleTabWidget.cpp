#include "include/View/Widget/ConsoleTabWidget.h"

ConsoleTabWidget::ConsoleTabWidget(TitleBar *title,ConsoleModel *model, QWidget *parent): QStackedWidget(parent), m_title(title), m_model(model){
    QPushButton *croix = new QPushButton(this->style()->standardIcon(QStyle::SP_TitleBarCloseButton),"");
    QPushButton *start = new QPushButton(this->style()->standardIcon(QStyle::SP_MediaPlay),"");
    QPushButton *stop = new QPushButton(this->style()->standardIcon(QStyle::SP_MediaStop),"");
    m_add.setIcon(DIcons::add);
    croix->setPalette(QPalette(Qt::red));
    QHBoxLayout *layout = new QHBoxLayout;
    m_selection.setMinimumWidth(150);
    layout->addWidget(&m_selection);
    layout->addWidget(croix);
    layout->addWidget(start);
    layout->addWidget(stop);
    layout->addWidget(&m_add);
    layout->addItem(new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Expanding));
    m_title->addLayout(layout);

    connect(&m_add,SIGNAL(clicked()),this,SLOT(openMenuAdd()));
    connect(croix,SIGNAL(clicked()),this,SLOT(removeConsole()));
    connect(&m_selection,SIGNAL(currentIndexChanged(int)), this, SLOT(setCurrentIndex(int)));
}

void ConsoleTabWidget::addConsole(Console *c, const QString &label){
    QRegularExpression regex("^"+QRegularExpression::escape(label)+" #(\\d*)$");
    int size = this->m_selection.count();
    int count = 1;
    bool plus=false;
    for(int i = 0; i < size; i++){
        QRegularExpressionMatch tmp = regex.match(m_selection.itemText(i));
        if(tmp.hasMatch()){
            count++;
            plus = tmp.captured(1).toInt() == count;
        }
    }
    if(plus){
        count++;
    }
    this->addWidget(c);
    this->m_selection.addItem(label + " #" + QString::number(count));
    m_selection.setCurrentIndex(size);
    this->setMinimumHeight(0);
}

void ConsoleTabWidget::removeConsole(int index){
    if(index <0){
        index = m_selection.currentIndex();
    }
    if(index <0){
        return;
    }
    m_selection.removeItem(index);
    Console *c = (Console*)this->widget(index);
    this->removeWidget(c);
    c->deleteLater();
    if(this->count() == 0){
        c->setMinimumHeight(0);
        c->parentWidget()->parentWidget()->setMinimumHeight(0);
    }
}

void ConsoleTabWidget::openMenuAdd(){
    QMenu menu;
    menu.addAction("console par défaut");
    menu.addSeparator();
    int size = m_model->rowCount();
    for(int i = 0; i < size; i++){
        QString *str = (QString*)m_model->index(i,0).internalPointer();
        QAction *tmp = menu.addAction(*str,this,SLOT(addConsole()));
    }
    menu.exec(m_add.mapToGlobal(m_add.rect().bottomLeft()));
}

void ConsoleTabWidget::addConsole(){
    QAction *tmp = (QAction*)sender();
    int size = m_model->rowCount();
    for(int i = 0; i < size; i++){
        if(*(QString*)m_model->index(i,0).internalPointer() == tmp->text()){
            this->addConsole(new Console(*(QString*)m_model->index(i,1).internalPointer()),tmp->text());
            return;
        }
    }
}
