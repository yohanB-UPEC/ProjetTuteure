#ifndef MENUPREF
#define MENUPREF

#include <QMenu>
#include <QLineEdit>
#include <QPushButton>

class Fenetre;
class Console;

class MenuPref : public QMenu {
	Q_OBJECT
	
	public:
		MenuPref(Fenetre *fen);
        bool isDark = false;
        QString getNom(){return this->file;};
		
	private:
		Fenetre *fen;
        QAction *term;
        QAction *theme;
        QLineEdit *loc;
        QPushButton *valider;
        QString file = "powershell.exe";

    public slots:
        void s_Term();
        void s_Theme();
        void s_Dark();
        void s_Clair();
        void parcourir();
};

#endif
