#include "include/Controller/Menu/MenuEditController.h"
#include "include/View/Menu/MenuEdit.h"
#include "include/View/Fenetre.h"

MenuEditController::MenuEditController(MenuEdit *me){
    this->m_me = me;
}

void MenuEditController::s_SearchPrev(){
    if(m_me->motTmp.isEmpty()){
        QMessageBox msgBox(QMessageBox::Warning, "Mot incorrect", "Le mot est vide.");
        msgBox.exec();
        s_Search();
        return;
    }
    DCodeEditor *editor = (DCodeEditor*) m_me->fen->getCentral()->currentWidget();
    if(editor == nullptr) return;
    if(m_me->extraSelections.size() > 0){
        m_me->extraSelections.clear();
    }
    editor->moveCursor(QTextCursor::PreviousWord);
    QColor color(Qt::blue);
    if(m_me->casse->isChecked()){
        if(m_me->radio2->isChecked()){
            if(editor->find(QRegExp(m_me->motTmp), QTextDocument::FindBackward | QTextDocument::FindCaseSensitively)){
                QTextEdit::ExtraSelection extra;
                extra.format.setBackground(color);
                extra.cursor = editor->textCursor();
                m_me->extraSelections.append(extra);
            }
        } else{
            if(editor->find(m_me->motTmp, QTextDocument::FindBackward | QTextDocument::FindCaseSensitively)){
                QTextEdit::ExtraSelection extra;
                extra.format.setBackground(color);
                extra.cursor = editor->textCursor();
                m_me->extraSelections.append(extra);
            }
        }
    } else {
        if(m_me->radio2->isChecked()){
            if(editor->find(QRegExp(m_me->motTmp), QTextDocument::FindBackward)){
                QTextEdit::ExtraSelection extra;
                extra.format.setBackground(color);
                extra.cursor = editor->textCursor();
                m_me->extraSelections.append(extra);
            }
        } else {
            if(editor->find(m_me->motTmp, QTextDocument::FindBackward)){
                QTextEdit::ExtraSelection extra;
                extra.format.setBackground(color);
                extra.cursor = editor->textCursor();
                m_me->extraSelections.append(extra);
            }
        }
    }
    editor->setExtraSelections(m_me->extraSelections);
}

void MenuEditController::s_SearchNext(){
    if(m_me->motTmp.isEmpty()){
        QMessageBox msgBox(QMessageBox::Warning, "Mot incorrect", "Le mot est vide.");
        msgBox.exec();
        s_Search();
        return;
    }
    DCodeEditor *editor = (DCodeEditor*) m_me->fen->getCentral()->currentWidget();
    if(editor == nullptr) return;
    if(m_me->extraSelections.size() > 0){
        m_me->extraSelections.clear();
    }
    editor->moveCursor(QTextCursor::NextWord);
    QColor color(Qt::red);

    if(m_me->casse->isChecked()){
        if(m_me->radio2->isChecked()){
            if(editor->find(QRegExp(m_me->motTmp), QTextDocument::FindCaseSensitively)){
                QTextEdit::ExtraSelection extra;
                extra.format.setBackground(color);
                extra.cursor = editor->textCursor();
                m_me->extraSelections.append(extra);
            }
        } else{
            if(editor->find(m_me->motTmp, QTextDocument::FindCaseSensitively)){
                QTextEdit::ExtraSelection extra;
                extra.format.setBackground(color);
                extra.cursor = editor->textCursor();
                m_me->extraSelections.append(extra);
            }
        }
    } else {
        if(m_me->radio2->isChecked()){
            if(editor->find(QRegExp(m_me->motTmp))){
                QTextEdit::ExtraSelection extra;
                extra.format.setBackground(color);
                extra.cursor = editor->textCursor();
                m_me->extraSelections.append(extra);
            }
        } else {
            if(editor->find(m_me->motTmp)){
                QTextEdit::ExtraSelection extra;
                extra.format.setBackground(color);
                extra.cursor = editor->textCursor();
                m_me->extraSelections.append(extra);
            }
        }
    }
    editor->setExtraSelections(m_me->extraSelections);
}


void MenuEditController::s_Undo(){
    DCodeEditor *editor = (DCodeEditor*) m_me->fen->getCentral()->currentWidget();
    if(editor == nullptr) return;
    editor->undo();
}

void MenuEditController::s_Redo(){
    DCodeEditor *editor = (DCodeEditor*) m_me->fen->getCentral()->currentWidget();
    if(editor == nullptr) return;
    editor->redo();
}

void MenuEditController::s_Cut(){
    DCodeEditor *editor = (DCodeEditor*) m_me->fen->getCentral()->currentWidget();
    if(editor == nullptr) return;
    editor->cut();
}

void MenuEditController::s_Copy(){
    DCodeEditor *editor = (DCodeEditor*) m_me->fen->getCentral()->currentWidget();
    if(editor == nullptr) return;
    editor->copy();
}

void MenuEditController::s_Paste(){
    DCodeEditor *editor = (DCodeEditor*) m_me->fen->getCentral()->currentWidget();
    if(editor == nullptr) return;
    editor->paste();
}

void MenuEditController::s_Suppr(){
    DCodeEditor *editor = (DCodeEditor*) m_me->fen->getCentral()->currentWidget();
    if(editor == nullptr) return;
    editor->clear();
}


void MenuEditController::s_SelectAll(){
    DCodeEditor *editor = (DCodeEditor*) m_me->fen->getCentral()->currentWidget();
    if(editor == nullptr) return;
    editor->selectAll();
}

void MenuEditController::find(QString mot){
    DCodeEditor *editor = (DCodeEditor*) m_me->fen->getCentral()->currentWidget();
    if(editor == nullptr) return;
    editor->moveCursor(QTextCursor::Start);
    QColor color(Qt::yellow);
    m_me->motTmp = mot;
    m_me->count = 0;
    if(m_me->radio2->isChecked()){
         if(m_me->casse->isChecked()){
            while(editor->find(QRegExp(mot), QTextDocument::FindCaseSensitively)){
                m_me->count++;
                QTextEdit::ExtraSelection extra;
                extra.format.setBackground(color);
                extra.cursor = editor->textCursor();
                m_me->extraSelections.append(extra);
            }
         } else {
             while(editor->find(QRegExp(mot))){
                 m_me->count++;
                 QTextEdit::ExtraSelection extra;
                 extra.format.setBackground(color);
                 extra.cursor = editor->textCursor();
                 m_me->extraSelections.append(extra);
             }
         }
    }
    if(m_me->casse->isChecked()){
        while(editor->find(mot, QTextDocument::FindCaseSensitively)){
            m_me->count++;
            QTextEdit::ExtraSelection extra;
            extra.format.setBackground(color);
            extra.cursor = editor->textCursor();
            m_me->extraSelections.append(extra);
        }
    } else {
        while(editor->find(mot)){
            m_me->count++;
            QTextEdit::ExtraSelection extra;
            extra.format.setBackground(color);
            extra.cursor = editor->textCursor();
            m_me->extraSelections.append(extra);
        }
    }
    if(m_me->count > 0)
        m_me->lab3->setText(QString::number(m_me->count) + " résultats trouvés");
    else m_me->lab3->setText("Aucun résultats trouvés");

    editor->setExtraSelections(m_me->extraSelections);
    m_me->extraSelections.clear();
}

void MenuEditController::s_Search(){
    m_me->dial = new QDialog();
    m_me->dial->setModal(true);
    m_me->dial->resize(300,50);
    m_me->dial->setMinimumWidth(100);
    m_me->dial->setWindowTitle("Recherche");

    QVBoxLayout *lay = new QVBoxLayout();

    QHBoxLayout *h = new QHBoxLayout();
    QLabel *lab = new QLabel("Find ");
    QLineEdit *mot = new QLineEdit();
    h->addWidget(lab);
    h->addWidget(mot);

    QVBoxLayout *h2 = new QVBoxLayout();
    h2->setAlignment(Qt::AlignLeft);
    m_me->casse = new QCheckBox("Respecter la casse");
    h2->addWidget(m_me->casse);
    QPushButton *prev = new QPushButton("Recherche précédente");
    h2->addWidget(prev);
    QPushButton *next = new QPushButton("Recherche suivante");
    h2->addWidget(next);

    QLabel *lab2 = new QLabel();
    lab2->setStyleSheet("padding-bottom: 5px; border-style: outset; border-bottom-width: 2px; border-bottom-color: rgb(127,127,255);");
    lab2->setText("\nMode de recherche");
    QRadioButton *radio1 = new QRadioButton(tr("Mode normal"));
    m_me->radio2 = new QRadioButton(tr("Expression régulière"));

    radio1->setChecked(true);

    h2->addWidget(lab2);
    h2->addWidget(radio1);
    h2->addWidget(m_me->radio2);

    QHBoxLayout *h1 = new QHBoxLayout();
    h1->setAlignment(Qt::AlignRight);
    QPushButton *valider = new QPushButton("Find");
    h1->addWidget(valider);

    QVBoxLayout *h3 = new QVBoxLayout();
    h3->setAlignment(Qt::AlignLeft);
    m_me->lab3 = new QLabel();
    m_me->lab3->setStyleSheet("border-style: outset; border-top-width: 2px; border-top-color: blue;");
    h3->addWidget(m_me->lab3);

    lay->addLayout(h);
    lay->addLayout(h1);
    lay->addLayout(h2);
    lay->addLayout(h3);
    m_me->dial->setLayout(lay);

    connect(valider,SIGNAL(clicked()),m_me->dial,SLOT(accept()));
    connect(mot,SIGNAL(textChanged(QString)),this,SLOT(find(QString)));
    connect(next,SIGNAL(clicked()),this,SLOT(s_SearchNext()));
    connect(prev,SIGNAL(clicked()),this,SLOT(s_SearchPrev()));
    m_me->dial->exec();
}

void MenuEditController::s_Replace(){
    QDialog *dial = new QDialog();
    dial->resize(300,50);
    dial->setMinimumWidth(100);
    dial->setWindowTitle("Remplacer");

    QVBoxLayout *lay = new QVBoxLayout();

    QHBoxLayout *h = new QHBoxLayout();
    QLabel *lab = new QLabel("Remplacer ");
    m_me->mot = new QLineEdit();
    m_me->newMot = new QLineEdit();
    h->addWidget(lab);
    h->addWidget(m_me->mot);
    h->addWidget(m_me->newMot);

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

void MenuEditController::replaceAll(){
    if(m_me->newMot->text().isEmpty()) return;
    DCodeEditor *editor = (DCodeEditor*) m_me->fen->getCentral()->currentWidget();
    if(editor == nullptr) return;
    QList<QTextEdit::ExtraSelection> extraSelections;
    editor->moveCursor(QTextCursor::Start);
    QColor color(Qt::yellow);
    bool isExist = false;
    while(editor->find(m_me->mot->text())){
        QTextEdit::ExtraSelection extra;
        extra.format.setBackground(color);
        extra.cursor = editor->textCursor();
        extraSelections.append(extra);
        QTextCursor qc = editor->textCursor();
        if(qc.hasSelection()){
            isExist = true;
            qc.insertText(m_me->newMot->text());
        } else
            break;
    }
    if(!isExist){
        QMessageBox msgBox(QMessageBox::Warning, "Mot inexistant", "Le mot n'existe pas.");
        msgBox.exec();
        s_Replace();
        return;
    }
    editor->setExtraSelections(extraSelections);
}
