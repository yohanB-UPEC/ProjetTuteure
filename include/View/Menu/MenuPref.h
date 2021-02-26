#ifndef MENUPREF
#define MENUPREF

#include <QMenu>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
#include "include/View/Dialog/ConsoleDialog.h"

class Fenetre;
class Console;

class MenuPref : public QMenu {
	Q_OBJECT
	
	public:
		MenuPref(Fenetre *fen);
        //QString getNom(){return this->file;};
        QRadioButton *getClear();
		
	private:
		Fenetre *fen;
        QAction *term;
        QAction *theme;
        //QLineEdit *loc;
        //QPushButton *valider;
        //QString file = "powershell.exe";
        QRadioButton *radio2;

    public slots:
        void s_Term();
        void s_Theme();
        void s_Dark();
        void s_Clair();
        //void parcourir();
};

#endif
