#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H

#include <QtWidgets>


class ConsoleDialog;

class ConsoleController : public QObject{
    Q_OBJECT
    public:
        ConsoleController(ConsoleDialog *view);

    public slots:
        void modifyButton();
        void supprimer();
        void modify();
        void addConsole();
        void deleted();
        void cancelAll();
        void validateAll();
    private:
        ConsoleDialog *m_view;
        int selectedRow;

};

#endif
