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


