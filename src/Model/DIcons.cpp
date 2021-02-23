#include "include/Model/DIcons.h"

QIcon DIcons::logo;
QIcon DIcons::projet;
QIcon DIcons::file;
QIcon DIcons::text_file;
QIcon DIcons::java_file;
QIcon DIcons::package;
QIcon DIcons::folder;
QIcon DIcons::src_folder;
QIcon DIcons::add;
QIcon DIcons::copy;
QIcon DIcons::modify;
QIcon DIcons::remove;
QIcon DIcons::copyDark;
QIcon DIcons::modifyDark;
QIcon DIcons::removeDark;
QIcon DIcons::stop;

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
    DIcons::add.addFile(":/res/icons/add.png");
    DIcons::copy.addFile(":/res/icons/copy.png");
    DIcons::modify.addFile(":/res/icons/modify.png");
    DIcons::remove.addFile(":/res/icons/delete.png");
    DIcons::copyDark.addFile(":/res/icons/copyDark.png");
    DIcons::modifyDark.addFile(":/res/icons/modifyDark.png");
    DIcons::removeDark.addFile(":/res/icons/deleteDark.png");
    DIcons::stop.addFile(":/res/icons/stop.png");
}
