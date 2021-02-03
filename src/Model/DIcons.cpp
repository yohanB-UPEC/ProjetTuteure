#include "include/Model/DIcons.h"

QIcon DIcons::logo;
QIcon DIcons::projet;
QIcon DIcons::file;
QIcon DIcons::text_file;
QIcon DIcons::java_file;
QIcon DIcons::package;
QIcon DIcons::folder;
QIcon DIcons::src_folder;

void DIcons::init(){
	DIcons::logo.addFile(":/res/icons/logo.png");
	DIcons::file.addFile(":/res/icons/file.png");
	DIcons::text_file.addFile(":/res/icons/text_file.png",QSize(128,128));
	DIcons::java_file.addFile(":/res/icons/java_file.png");
	DIcons::package.addFile(":/res/icons/package_f.png",QSize(),QIcon::Normal,QIcon::Off);
	DIcons::package.addFile(":/res/icons/package_o.png",QSize(),QIcon::Normal,QIcon::On);
	DIcons::projet.addFile(":/res/icons/projet.png");
	DIcons::folder.addFile(":/res/icons/folder.png");
	DIcons::src_folder.addFile(":/res/icons/java_folder.png");
}
