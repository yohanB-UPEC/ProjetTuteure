#include "include/View/Menu/MenuPref.h"
#include "include/View/Fenetre.h"
#include "include/View/Widget/Console.h"

MenuPref::MenuPref(Fenetre *fen) : QMenu("Préférences"), mp(this){
	this->fen = fen;

    theme = this->addAction("Thème");
    term = this->addAction("Terminal");
	
    QMenu *sub = new QMenu();
    QActionGroup *grp = new QActionGroup(theme);
    QAction *sombre = sub->addAction("Sombre",&mp,SLOT(s_Dark()));
    QAction *clair = sub->addAction("Clair",&mp,SLOT(s_Clair()));
    sombre->setCheckable(true);
    clair->setCheckable(true);
    clair->setChecked(true);
    grp->addAction(sombre);
    grp->addAction(clair);
    theme->setMenu(sub);

	this->fen->menuBar()->addMenu(this);

    connect(term,SIGNAL(triggered()),&mp,SLOT(s_Term()));
	
}





