#include <QApplication>
#include "include/Widget/Fenetre.h"
int main(int argc,char **argv){
	
	QApplication app(argc,argv);
	printf("commencement\n");
	Fenetre fen;
	fen.show();
	
	return app.exec();
}