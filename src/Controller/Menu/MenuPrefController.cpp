#include "include/Controller/Menu/MenuPrefController.h"
#include "include/View/Menu/MenuPref.h"
#include "include/View/Fenetre.h"

MenuPrefController::MenuPrefController(MenuPref *mp){
    this->m_mp = mp;
}

void MenuPrefController::s_Term(){
    ConsoleDialog cd(this->m_mp->fen->getModel()->getConsole(), this->m_mp->fen);
    cd.exec();
}

/*
void MenuPrefController::s_Theme(){
    QDialog *dial = new QDialog();
    const QSize size(320, 100);
    dial->setFixedSize(size);
    dial->setWindowTitle("Thème");

    QVBoxLayout *lay = new QVBoxLayout();

    QHBoxLayout *h = new QHBoxLayout();
    QLabel *lab = new QLabel();
    lab->setText("Choix du thème :\n\n\n\n");
    QRadioButton *radio1 = new QRadioButton(tr("clair"));
    m_mp->radio2 = new QRadioButton(tr("sombre"));

    radio1->setChecked(true);

    h->addWidget(lab);
    h->addWidget(radio1);
    h->addWidget(m_mp->radio2);
    h->addWidget(lab);

    QHBoxLayout *h1 = new QHBoxLayout();
    h1->setAlignment(Qt::AlignRight);
    QPushButton *valider = new QPushButton("Valider");

    h1->addWidget(valider);

    lay->addLayout(h);
    lay->addLayout(h1);
    dial->setLayout(lay);

    connect(radio1,SIGNAL(clicked()),this,SLOT(s_Clair()));
    connect(m_mp->radio2,SIGNAL(clicked()),this,SLOT(s_Dark()));
    connect(valider,SIGNAL(clicked()),dial,SLOT(accept()));
    dial->exec();
}

QRadioButton *MenuPref::getClear(){
    return radio2;
}

void MenuPrefController::s_Dark(){
    QFile f(":/res/qss/style.qss");
    if(f.open(QFile::ReadOnly)) {
        qApp->setStyleSheet(QString(f.readAll()));
        f.close();
    }
}

void MenuPrefController::s_Clair(){
    qApp->setStyleSheet("");
}

void MenuPrefController::s_Term(){
    if(m_mp->fen->getConsole() == nullptr){
        QMessageBox msgBox(QMessageBox::Warning, "Erreur Terminal", "Erreur Terminal");
        msgBox.setText("Ouvrez un terminal pour modifier le terminal par défaut");
        msgBox.exec();
        return;
    }
    QDialog *dial = new QDialog();
    const QSize size(470, 170);
    dial->setFixedSize(size);
    dial->setWindowTitle("Choix du terminal");

    QVBoxLayout *lay = new QVBoxLayout();

    QHBoxLayout *h = new QHBoxLayout();
    QLabel *lab = new QLabel("Emplacement du terminal (exe): ");

    m_mp->loc = new QLineEdit();
    QPushButton *browse = new QPushButton("Parcourir");
    h->addWidget(lab);
    h->addWidget(m_mp->loc);
    h->addWidget(browse);


    QVBoxLayout *h2 = new QVBoxLayout();
    QLabel *lab2 = new QLabel("Réouvrez un terminal pour que la modification s'applique");
    h2->addWidget(lab2);

    QHBoxLayout *h1 = new QHBoxLayout();
    h1->setAlignment(Qt::AlignRight);
    m_mp->valider = new QPushButton("valider");
    m_mp->valider->setEnabled(false);
    QPushButton *fermer = new QPushButton("Fermer");

    h1->addWidget(m_mp->valider);
    h1->addWidget(fermer);

    lay->addLayout(h);
    lay->addLayout(h2);
    lay->addLayout(h1);

    dial->setLayout(lay);

    connect(browse,SIGNAL(clicked()),this,SLOT(parcourir()));
    connect(m_mp->valider,SIGNAL(clicked()),dial,SLOT(accept()));
    connect(fermer,SIGNAL(clicked()),dial,SLOT(reject()));
    dial->exec();
}
*/
