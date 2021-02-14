#ifndef CLASSCONTROLLER
#define CLASSCONTROLLER

#include <QtWidgets>

class ClassDialog;

class ClassController : public QObject {
	Q_OBJECT

	public:
        ClassController(ClassDialog *clc);

    private:
    	ClassDialog *m_clc;
		
	public slots:
		void validate();
		bool caracteresSpeciaux();
		bool isExisted();
        void parcourir();
        void parcourir2();
};

#endif
