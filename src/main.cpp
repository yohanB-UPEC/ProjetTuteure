#include <QApplication>
#include "include/View/Fenetre.h"

int main(int argc,char **argv){
	
	QApplication app(argc,argv);
	printf("commencement\n");
	Model model;
	Fenetre fen(&model);
	fen.show();
	return app.exec();
}