#ifndef MENUEDIT
#define MENUEDIT

#include <QMenu>
#include <QLineEdit>
#include <QTextEdit>
#include "include/Controller/Menu/MenuEditController.h"

class Fenetre;

class MenuEdit : public QMenu {
	Q_OBJECT

    friend class MenuEditController;
	
	public:
        MenuEdit(Fenetre *fen=0);
		
	private:
        Fenetre *fen;
        QList<QTextEdit::ExtraSelection> extraSelections;
        QDialog *dial;
		QAction *cancel;
		QAction *restore;
		QAction *cut;
		QAction *copy;
		QAction *paste;
		QAction *suppr;
		QAction *selectAll;
		QAction *search;
		QAction *search_next;
		QAction *search_previous;
        QAction *replace;
        QLabel *lab3;
        QCheckBox *casse;
        QRadioButton *radio2;
        QString motTmp;
        QLineEdit *mot;
        QLineEdit *newMot;
        MenuEditController me;
        int count = 0;
};

#endif
