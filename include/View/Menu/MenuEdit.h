#ifndef MENUEDIT
#define MENUEDIT

#include <QMenu>
#include <QLineEdit>
#include <QTextEdit>

class Fenetre;

class MenuEdit : public QMenu {
	Q_OBJECT
	
	public:
		MenuEdit(Fenetre *fen);
		
	private:
        Fenetre *fen;
        QList<QTextEdit::ExtraSelection> extraSelections;
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
        QString motTmp;
        QLineEdit *mot;
        QLineEdit *newMot;

    public slots:
        void s_Copy();
        void s_Paste();
        void s_Cut();
        void s_SelectAll();
        void s_Undo();
        void s_Redo();
        void s_Search();
        void s_SearchNext();
        void s_SearchPrev();
        void s_Suppr();
        void find(QString mot);
        void s_Replace();
        void replaceAll();
};

#endif
