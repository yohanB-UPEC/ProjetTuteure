/*#ifndef SNIPPETCONTROLLER_H
#define SNIPPETCONTROLLER_H

#include <QtWidgets>

class Snippet;

class SnipetController : public QObject {
    Q_OBJECT

    public:
        SnipetController(Snippet *sni);

    private:
        Snippet *m_sni;

    public slots:
        void validate();
        bool caracteresSpeciaux();
        bool isExisted();
        void parcourir();
        void parcourir2();
};

#endif
*/
