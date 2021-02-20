#include "include/View/Menu/MenuPref.h"
#include "include/View/Fenetre.h"
#include "include/View/Widget/Console.h"


MenuPref::MenuPref(Fenetre *fen) : QMenu("Préférences"){
	this->fen = fen;

    theme = this->addAction("Thème");
    term = this->addAction("Terminal");
	
	this->fen->menuBar()->addMenu(this);

    connect(theme,SIGNAL(triggered()),this,SLOT(s_Theme()));
    connect(term,SIGNAL(triggered()),this,SLOT(s_Term()));
	
}

void MenuPref::s_Theme(){
    QDialog *dial = new QDialog();
    const QSize size(320, 100);
    dial->setFixedSize(size);
    dial->setWindowTitle("Thème");

    QVBoxLayout *lay = new QVBoxLayout();

    QHBoxLayout *h = new QHBoxLayout();
    QLabel *lab = new QLabel();
    lab->setText("Choix du thème :\n\n\n\n");
    QRadioButton *radio1 = new QRadioButton(tr("clair"));
    radio2 = new QRadioButton(tr("sombre"));

    radio1->setChecked(true);

    h->addWidget(lab);
    h->addWidget(radio1);
    h->addWidget(radio2);
    h->addWidget(lab);

    QHBoxLayout *h1 = new QHBoxLayout();
    h1->setAlignment(Qt::AlignRight);
    QPushButton *valider = new QPushButton("Valider");

    h1->addWidget(valider);

    lay->addLayout(h);
    lay->addLayout(h1);
    dial->setLayout(lay);

    connect(radio1,SIGNAL(clicked()),this,SLOT(s_Clair()));
    connect(radio2,SIGNAL(clicked()),this,SLOT(s_Dark()));
    connect(valider,SIGNAL(clicked()),dial,SLOT(accept()));
    dial->exec();
}

QRadioButton *MenuPref::getClear(){
    return radio2;
}

void MenuPref::s_Dark(){
    qApp->setStyle(QStyleFactory::create("Fusion"));

    QPalette newPalette;
    newPalette.setColor(QPalette::Window, QColor("#272822"));
    newPalette.setColor(QPalette::WindowText, Qt::white);
    newPalette.setColor(QPalette::Base, QColor("#272822"));
    newPalette.setColor(QPalette::AlternateBase, QColor( 45,  45, 45));
    newPalette.setColor(QPalette::PlaceholderText, QColor(127, 127, 127));
    newPalette.setColor(QPalette::Text, QColor(212, 212, 212));
    newPalette.setColor(QPalette::Button, QColor(45, 45, 45));
    newPalette.setColor(QPalette::ButtonText, QColor(212, 212, 212));
    newPalette.setColor(QPalette::BrightText, QColor(240, 240, 240));
    newPalette.setColor(QPalette::Highlight, QColor(38, 79, 120));
    newPalette.setColor(QPalette::HighlightedText, QColor(240, 240, 240));

    newPalette.setColor(QPalette::Light, QColor("#272822"));
    newPalette.setColor(QPalette::Midlight, QColor(52, 52, 52));
    newPalette.setColor(QPalette::Dark, QColor(30, 30, 30));
    newPalette.setColor(QPalette::Mid, QColor("#272822"));
    newPalette.setColor(QPalette::Shadow, QColor(0, 0, 0));

    newPalette.setColor(QPalette::Disabled, QPalette::Text, QColor(127, 127, 127));

    qApp->setPalette(newPalette);
}

void MenuPref::s_Clair(){
    qApp->setStyle(QStyleFactory::create("default"));

    QPalette newPalette;
    newPalette.setColor(QPalette::Window, Qt::white);
    newPalette.setColor(QPalette::WindowText, Qt::black);
    /*newPalette.setColor(QPalette::Base, Qt::);
    newPalette.setColor(QPalette::AlternateBase, QColor( 45,  45, 45));
    newPalette.setColor(QPalette::PlaceholderText, QColor(127, 127, 127));
    newPalette.setColor(QPalette::Text, Qt::black);
    newPalette.setColor(QPalette::Button, QColor(45, 45, 45));
    newPalette.setColor(QPalette::ButtonText, QColor(212, 212, 212));
    newPalette.setColor(QPalette::BrightText, QColor(240, 240, 240));
    newPalette.setColor(QPalette::Highlight, QColor(38, 79, 120));
    newPalette.setColor(QPalette::HighlightedText, QColor(240, 240, 240));*/

    /*newPalette.setColor(QPalette::Light, QColor("#272822"));
    newPalette.setColor(QPalette::Midlight, QColor(52, 52, 52));
    newPalette.setColor(QPalette::Dark, QColor(30, 30, 30));
    newPalette.setColor(QPalette::Mid, QColor("#272822"));
    newPalette.setColor(QPalette::Shadow, QColor(0, 0, 0));*/

    //newPalette.setColor(QPalette::Disabled, QPalette::Text, QColor(127, 127, 127));

    qApp->setPalette(newPalette);
}

void MenuPref::s_Term(){
    if(this->fen->getConsole() == nullptr){
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

    loc = new QLineEdit();
    QPushButton *browse = new QPushButton("Parcourir");
    h->addWidget(lab);
    h->addWidget(loc);
    h->addWidget(browse);


    QVBoxLayout *h2 = new QVBoxLayout();
    QLabel *lab2 = new QLabel("Réouvrez un terminal pour que la modification s'applique");
    h2->addWidget(lab2);

    QHBoxLayout *h1 = new QHBoxLayout();
    h1->setAlignment(Qt::AlignRight);
    valider = new QPushButton("valider");
    valider->setEnabled(false);
    QPushButton *fermer = new QPushButton("Fermer");

    h1->addWidget(valider);
    h1->addWidget(fermer);

    lay->addLayout(h);
    lay->addLayout(h2);
    lay->addLayout(h1);

    dial->setLayout(lay);

    connect(browse,SIGNAL(clicked()),this,SLOT(parcourir()));
    connect(valider,SIGNAL(clicked()),dial,SLOT(accept()));
    connect(fermer,SIGNAL(clicked()),dial,SLOT(reject()));
    dial->exec();
}

void MenuPref::parcourir(){
    file = QFileDialog::getOpenFileName(this, tr("Selectionnez un fichier"));
    QList<QString> list = file.split(".");
    if(list.size() > 0 && list.at(list.size()-1) == "exe" && file.size() > 0){
        loc->setText(file);
        valider->setEnabled(true);
    } else {
        QMessageBox msgBox(QMessageBox::Warning, "Mauvaise extension", "Mauvaise extension");
        msgBox.setText("Le fichier doit avoir l'extension .exe (" + list.at(list.size()-1) + ")");
        msgBox.exec();
    }
    this->fen->getConsole()->setCmd(file);
}

