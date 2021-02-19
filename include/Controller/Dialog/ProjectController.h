#ifndef PROJECTCONTROLLER2
#define PROJECTCONTROLLER2

#include <QtWidgets>
#include "include/Model/Model.h"

class ProjectDialog;

class ProjectController : public QObject {
	Q_OBJECT
	
	public:
		ProjectController(Model *model, ProjectDialog *dial);
	
	public slots:
		void parcourir();
		void validate();
		void createProject();
        bool caracteresSpeciaux();
        bool isExisted();
		
	private:
		ProjectDialog *m_dial;
		Model *m_model;
};
#endif
