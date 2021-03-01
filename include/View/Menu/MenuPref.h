#ifndef MENUPREF
#define MENUPREF

#include <QMenu>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include "include/Controller/Menu/MenuPrefController.h"
#include "include/View/Dialog/ConsoleDialog.h"

class Fenetre;
class Console;

class MenuPref : public QMenu {
	Q_OBJECT

    friend class MenuPrefController;
	
	public:
		MenuPref(Fenetre *fen);
        QRadioButton *getClear();

    private:
        Fenetre *fen;
        MenuPref *m_mp;
        QAction *term;
        QAction *theme;
        QRadioButton *radio2;
        MenuPrefController mp;

};

#endif
