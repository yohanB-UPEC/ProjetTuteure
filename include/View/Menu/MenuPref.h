#ifndef MENUPREF
#define MENUPREF

#include <QMenu>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include "include/Controller/Menu/MenuPrefController.h"

class Fenetre;
class Console;

class MenuPref : public QMenu {
	Q_OBJECT

    friend class MenuPrefController;
	
	public:
		MenuPref(Fenetre *fen);
        QString getNom(){return this->file;};
        QRadioButton *getClear();

    private:
        Fenetre *fen;
        MenuPref *m_mp;
        QAction *term;
        QAction *theme;
        QLineEdit *loc;
        QPushButton *valider;
        QString file = "powershell.exe";
        QRadioButton *radio2;
        MenuPrefController mp;
};

#endif
