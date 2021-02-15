#include "include/View/Menu/MenuEdit.h"
#include "include/View/Fenetre.h"

MenuEdit::MenuEdit(Fenetre *fen) : QMenu("Edition"){
	this->fen = fen;
	
	cancel = this->addAction("Annuler");
    cancel->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Z));
	restore = this->addAction("Rétablir");
    restore->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y));
	
	this->addSeparator();
	cut = this->addAction("Couper");
    cut->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X));
	copy = this->addAction("Copier");
    copy->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
	paste = this->addAction("Coller");
    paste->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_V));
	
	this->addSeparator();
	suppr = this->addAction("supprimer");
    suppr->setShortcut(Qt::Key_Delete);
	selectAll = this->addAction("Tout Selectionner");
    selectAll->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_A));
	
	this->addSeparator();
    search = this->addAction("Rechercher");
    search->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F));
	search_next = this->addAction("Recherche Suivante");
    search_next->setShortcut(QKeySequence(Qt::Key_F3));
	search_previous = this->addAction("Recherche Précédente");
    search_previous->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_F3));
    replace = this->addAction("Remplacer");
    replace->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_H));
	
    this->fen->menuBar()->addMenu(this);

    connect(cancel,SIGNAL(triggered()),this,SLOT(s_Undo()));
    connect(restore,SIGNAL(triggered()),this,SLOT(s_Redo()));
    connect(cut,SIGNAL(triggered()),this,SLOT(s_Cut()));
    connect(copy,SIGNAL(triggered()),this,SLOT(s_Copy()));
    connect(paste,SIGNAL(triggered()),this,SLOT(s_Paste()));
    connect(suppr,SIGNAL(triggered()),this,SLOT(s_Suppr()));
    connect(selectAll,SIGNAL(triggered()),this,SLOT(s_SelectAll()));
    connect(search,SIGNAL(triggered()),this,SLOT(s_Search()));
    connect(search_next,SIGNAL(triggered()),this,SLOT(s_SearchNext()));
    connect(search_previous,SIGNAL(triggered()),this,SLOT(s_SearchPrev()));
    connect(replace,SIGNAL(triggered()),this,SLOT(s_Replace()));
}

void MenuEdit::find(QString mot){
    DCodeEditor *editor = (DCodeEditor*) this->fen->getCentral()->currentWidget();
    editor->moveCursor(QTextCursor::Start);
    QColor color(Qt::yellow);
    motTmp = mot;
    while(editor->find(mot)){
        QTextEdit::ExtraSelection extra;
        extra.format.setBackground(color);
        extra.cursor = editor->textCursor();
        extraSelections.append(extra);
    }
    editor->setExtraSelections(extraSelections);
    if(extraSelections.size() == 0 && !mot.isEmpty()){
        QMessageBox msgBox(QMessageBox::Warning, "Recherche introuvable", "Le mot recherché est introuvable.");
        msgBox.exec();
    }
    extraSelections.clear();
}

void MenuEdit::s_SearchPrev(){
    if(motTmp.isEmpty()){
        QMessageBox msgBox(QMessageBox::Warning, "Mot incorrect", "Le mot est vide.");
        msgBox.exec();
        s_Search();
        return;
    }
    DCodeEditor *editor = (DCodeEditor*) this->fen->getCentral()->currentWidget();
    if(extraSelections.size() > 0){
        extraSelections.clear();
    }
    editor->moveCursor(QTextCursor::PreviousWord);
    QColor color(Qt::blue);
    if(editor->find(motTmp, QTextDocument::FindBackward)){
        QTextEdit::ExtraSelection extra;
        extra.format.setBackground(color);
        extra.cursor = editor->textCursor();
        extraSelections.append(extra);
    }
    editor->setExtraSelections(extraSelections);
}

void MenuEdit::s_SearchNext(){
    if(motTmp.isEmpty()){
        QMessageBox msgBox(QMessageBox::Warning, "Mot incorrect", "Le mot est vide.");
        msgBox.exec();
        s_Search();
        return;
    }
    DCodeEditor *editor = (DCodeEditor*) this->fen->getCentral()->currentWidget();
    if(extraSelections.size() > 0){
        extraSelections.clear();
    }
    editor->moveCursor(QTextCursor::NextWord);
    QColor color(Qt::red);
    if(editor->find(motTmp)){
        QTextEdit::ExtraSelection extra;
        extra.format.setBackground(color);
        extra.cursor = editor->textCursor();
        extraSelections.append(extra);
    }
    editor->setExtraSelections(extraSelections);
}


void MenuEdit::s_Undo(){
    DCodeEditor *editor = (DCodeEditor*) this->fen->getCentral()->currentWidget();
    editor->undo();
}

void MenuEdit::s_Redo(){
    DCodeEditor *editor = (DCodeEditor*) this->fen->getCentral()->currentWidget();
    editor->redo();
}

void MenuEdit::s_Cut(){
    DCodeEditor *editor = (DCodeEditor*) this->fen->getCentral()->currentWidget();
    editor->cut();
}

void MenuEdit::s_Copy(){
    DCodeEditor *editor = (DCodeEditor*) this->fen->getCentral()->currentWidget();
    editor->copy();
}

void MenuEdit::s_Paste(){
    DCodeEditor *editor = (DCodeEditor*) this->fen->getCentral()->currentWidget();
    editor->paste();
}

void MenuEdit::s_Suppr(){
    DCodeEditor *editor = (DCodeEditor*) this->fen->getCentral()->currentWidget();
    editor->clear();
}


void MenuEdit::s_SelectAll(){
    DCodeEditor *editor = (DCodeEditor*) this->fen->getCentral()->currentWidget();
    editor->selectAll();
}

void MenuEdit::s_Search(){
    QDialog *dial = new QDialog();
    dial->resize(300,50);
    dial->setMinimumWidth(100);
    dial->setWindowTitle("Recherche");

    QVBoxLayout *lay = new QVBoxLayout();

    QHBoxLayout *h = new QHBoxLayout();
    QLabel *lab = new QLabel("Find ");
    QLineEdit *mot = new QLineEdit();
    h->addWidget(lab);
    h->addWidget(mot);

    QHBoxLayout *h1 = new QHBoxLayout();
    h1->setAlignment(Qt::AlignRight);
    QPushButton *valider = new QPushButton("Find");

    h1->addWidget(valider);

    lay->addLayout(h);
    lay->addLayout(h1);
    dial->setLayout(lay);

    connect(valider,SIGNAL(clicked()),dial,SLOT(accept()));
    connect(mot,SIGNAL(textChanged(QString)),this,SLOT(find(QString)));
    dial->exec();
}

void MenuEdit::s_Replace(){
    QDialog *dial = new QDialog();
    dial->resize(300,50);
    dial->setMinimumWidth(100);
    dial->setWindowTitle("Remplacer");

    QVBoxLayout *lay = new QVBoxLayout();

    QHBoxLayout *h = new QHBoxLayout();
    QLabel *lab = new QLabel("Remplacer ");
    mot = new QLineEdit();
    newMot = new QLineEdit();
    h->addWidget(lab);
    h->addWidget(mot);
    h->addWidget(newMot);

    QHBoxLayout *h1 = new QHBoxLayout();
    h1->setAlignment(Qt::AlignRight);
    QPushButton *valider = new QPushButton("Remplacer");

    h1->addWidget(valider);

    lay->addLayout(h);
    lay->addLayout(h1);
    dial->setLayout(lay);

    connect(valider,SIGNAL(clicked()),dial,SLOT(accept()));
    connect(valider,SIGNAL(clicked()),this,SLOT(replaceAll()));
    dial->exec();
}

void MenuEdit::replaceAll(){
    if(newMot->text().isEmpty()) return;
    DCodeEditor *editor = (DCodeEditor*) this->fen->getCentral()->currentWidget();
    QList<QTextEdit::ExtraSelection> extraSelections;
    editor->moveCursor(QTextCursor::Start);
    QColor color(Qt::yellow);
    while(editor->find(mot->text())){
        QTextEdit::ExtraSelection extra;
        extra.format.setBackground(color);
        extra.cursor = editor->textCursor();
        extraSelections.append(extra);
        QTextCursor qc = editor->textCursor();
        if(qc.hasSelection()){
            qc.insertText(newMot->text());
        } else
            break;
    }
    editor->setExtraSelections(extraSelections);
}
