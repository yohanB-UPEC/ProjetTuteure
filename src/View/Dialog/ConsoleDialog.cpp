#include "include/View/Dialog/ConsoleDialog.h"

ConsoleDialog::ConsoleDialog(ConsoleModel *model, QWidget *parent, Qt::WindowFlags f): QDialog(parent,f), m_model(model), m_controller(this){
    this->setMinimumWidth(500);
    this->setWindowTitle("Modifier les terminaux");
    this->setMinimumHeight(400);
    QVBoxLayout *layout = new QVBoxLayout;

    QGroupBox *grp = new QGroupBox("Changer les terminaux intégrés");
    QVBoxLayout *grpl = new QVBoxLayout;
    m_table = new QTableView;
    m_table->horizontalHeader()->setStretchLastSection(true);
    m_table->horizontalHeader()->setHighlightSections(false);
    m_table->verticalHeader()->setHidden(true);
    m_table->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_table->setModel(m_model);
    QPushButton *nouvelle = new QPushButton("Nouvelle...");
    QPushButton *modifier = new QPushButton("Modifier...");
    QPushButton *supprimer = new QPushButton("Supprimer");


    QHBoxLayout *grpl2 = new QHBoxLayout();
    grpl2->addItem(new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum));
    grpl2->addWidget(nouvelle);
    grpl2->addWidget(modifier);
    grpl2->addWidget(supprimer);

    grpl->addWidget(m_table);
    grpl->addLayout(grpl2);
    grp->setLayout(grpl);


    QHBoxLayout *bot = new QHBoxLayout;
    QPushButton *valider = new QPushButton("Valider");
    QPushButton *annuler = new QPushButton("Annuler");
    bot->addItem(new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum));
    bot->addWidget(annuler);
    bot->addWidget(valider);

    layout->addWidget(grp);
    layout->addLayout(bot);
    this->setLayout(layout);

    connect(annuler,SIGNAL(clicked()),&m_controller,SLOT(cancelAll()));
    connect(valider,SIGNAL(clicked()),&m_controller,SLOT(validateAll()));
    connect(modifier,SIGNAL(clicked()),&m_controller, SLOT(modifyButton()));
    connect(nouvelle,SIGNAL(clicked()),this, SLOT(addDialog()));
    connect(supprimer,SIGNAL(clicked()),&m_controller, SLOT(supprimer()));


}

void ConsoleDialog::addDialog(QString name, QString cmd){
    qDebug() << "ConsoleDialog::addDialog";
    m_dial = new QDialog(this);
    m_dial->setMinimumWidth(400);
    m_dial->setMaximumHeight(150);
    m_dial->resize(450,100);
    if(name.isNull()){
        m_dial->setWindowTitle("Créer d'une console");
    }else{
        m_dial->setWindowTitle("Modifier d'une console");
    }


    QGridLayout *layout = new QGridLayout;

    QLabel *lname = new QLabel("Nom: ");
    m_name = new QLineEdit(name);
    layout->addWidget(lname,0,0);
    layout->addWidget(m_name,0,1);

    QLabel *lcmd = new QLabel("Commande de lancement");
    m_cmd = new QLineEdit(cmd);
    layout->addWidget(lcmd,1,0);
    layout->addWidget(m_cmd,1,1);

    QPushButton *valider = new QPushButton("Valider");
    QPushButton *annuler = new QPushButton("Annuler");
    QHBoxLayout *hb = new QHBoxLayout();
    hb->addWidget(annuler);
    hb->addWidget(valider);
    layout->addLayout(hb,2,1,Qt::AlignRight);

    m_dial->setLayout(layout);

    connect(annuler, SIGNAL(clicked()),m_dial,SLOT(reject()));
    if(name.isNull()){
        connect(valider, SIGNAL(clicked()),&m_controller,SLOT(addConsole()));
    }else{
        connect(valider, SIGNAL(clicked()),&m_controller,SLOT(modify()));
    }
    connect(m_dial,SIGNAL(destroyed()),&m_controller,SLOT(deleted()));

    m_dial->exec();
    m_dial->deleteLater();
    m_cmd = nullptr;
    m_dial = nullptr;
    m_name = nullptr;
}
