#ifndef CLASSDIALOG_H
#define CLASSDIALOG_H

#include <QtWidgets>
#include "include/Controller/Dialog/ClassController.h"
#include "include/Model/Javora.h"
#include "include/Model/FilteredModel.h"
#include "include/View/Fenetre.h"

class ClassDialog : public QDialog {
	Q_OBJECT
	
	friend class ClassController;

	public:
        ClassDialog(QWidget *parent, Model *model, QFlags<Javora::ClassType> type);
		
	private:
        Model *m_model;
        FilteredModel *fm;
        QFlags<Javora::ClassType> m_type;
        QLineEdit *loc;
        QLineEdit *name;
        QButtonGroup *radioMod;
        QCheckBox *abstract;
        QCheckBox *final;
        QLineEdit *superClass;
        QLineEdit *interfaces;
        QCheckBox *main;
        QCheckBox *constructor;
		QPushButton *valider;
        QPushButton *diaV;
        ClassController clc;
        QDialog locDia;
        void createLocDia();
        void locationInit();
};

#endif
