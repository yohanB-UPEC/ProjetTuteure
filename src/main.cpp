#include <QApplication>
#include "include/View/Fenetre.h"

int main(int argc,char **argv){
	
	QApplication app(argc,argv);
	app.setStyle(QStyleFactory::create("macintosh"));
	QStringList tmp = QStyleFactory::keys();
	qDebug() << "liste des themes par défaut:";
	for (int i = 0; i < tmp.size(); ++i){
		qDebug() << "\t- " << tmp.at(i);
	}
	QResource::registerResource("resources.rcc");
	DIcons::init();
	Model model;
	Fenetre fen(&model);
	fen.show();
	return app.exec();
}
