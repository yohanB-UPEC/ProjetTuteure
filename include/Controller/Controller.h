#ifndef CONTROLLER
#define CONTROLLER

#include <QtWidgets>

class Fenetre;
class Model;

class Controller : public QObject{
	Q_OBJECT
	
	public:
		Controller(Fenetre *fen, Model *model);
		
	public slots:
	
	private:
		Fenetre * fen;
		Model *model;
	
};
#endif