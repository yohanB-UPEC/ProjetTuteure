#ifndef MENUPREFCONTROLLER_H
#define MENUPREFCONTROLLER_H

#include <QtWidgets>
class MenuPref;

class MenuPrefController : public QObject {
    Q_OBJECT

    public:
        MenuPrefController(MenuPref *mp);

    private:
        MenuPref *m_mp;

    public slots:
        void s_Term();
        /*void s_Theme();
        void s_Dark();
        void s_Clair();
        void parcourir();*/
};

#endif
