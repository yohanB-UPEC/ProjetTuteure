#ifndef CLASSCONTROLLER
#define CLASSCONTROLLER

#include <QtWidgets>
#include "include/Model/Model.h"

class ClassDialog;

class ClassController : public QObject {
	Q_OBJECT

	public:
        ClassController(Model *model, ClassDialog *clc);

    private:
    	ClassDialog *m_clc;
        Model *m_model;
        QModelIndex m_chemin;
        QModelIndex m_chemintmp;
        bool name=false;

	public slots:
		void validate();
        void selectLocation(const QItemSelection& selected, const QItemSelection& deselected);
        void validateLocation();
        void validateName(const QString &text);
        void createClass();
};

#endif
