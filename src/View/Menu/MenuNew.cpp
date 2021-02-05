#include "include/View/Menu/MenuNew.h"
#include "include/View/Fenetre.h"

MenuNew::MenuNew(Fenetre* fen) : QMenu(){
    this->fen = fen;
    javaProject = this->addAction("Java Project");
    this->addSeparator();
    package = this->addAction("Package");
    aClass = this->addAction("Class");
    aInterface = this->addAction("Interface");
    aEnum = this->addAction("Enum");
    folder = this->addAction("Folder");
    srcfolder = this->addAction("Source Folder");
    file = this->addAction("File");

    connect(javaProject,SIGNAL(triggered()),this,SLOT(s_Project()));
    connect(file,SIGNAL(triggered()),this,SLOT(s_File()));
    connect(package,SIGNAL(triggered()),this,SLOT(s_Package()));
    connect(aClass,SIGNAL(triggered()),this,SLOT(s_Class()));
    connect(aInterface,SIGNAL(triggered()),this,SLOT(s_Interface()));
    connect(aEnum,SIGNAL(triggered()),this,SLOT(s_Enum()));
    connect(folder,SIGNAL(triggered()),this,SLOT(s_Folder()));
    connect(srcfolder,SIGNAL(triggered()),this,SLOT(s_SrcFolder()));
}

void MenuNew::s_File(){
    this->fen->getCentral()->addTab(new DCodeEditor(),"nouveau");
}
void MenuNew::s_Project(){
    ProjectDialog proDia(this->fen, this->fen->getModel());
    int res = proDia.exec();
    printf("ProDia= %d\n",res);
}

void MenuNew::s_Package(){
    PackageDialog packageDia(this->fen);
    int res = packageDia.exec();
    printf("packageDia = %d\n", res);
}

void MenuNew::s_Class(){
    ClassDialog classDia(this->fen);
    int res = classDia.exec();
    printf("classDia = %d\n", res);
}

void MenuNew::s_Interface(){
    InterfaceDialog interfaceDia(this->fen);
    int res = interfaceDia.exec();
    printf("InterfaceDia = %d\n", res);
}

void MenuNew::s_Enum(){
    EnumDialog enumDia(this->fen);
    int res = enumDia.exec();
    printf("EnumDia = %d\n", res);
}

void MenuNew::s_Folder(){
    FolderDialog folderDia(this->fen);
    int res = folderDia.exec();
    printf("folderDia = %d\n", res);
}

void MenuNew::s_SrcFolder(){
    SrcFolderDialog srcFolderDia(this->fen);
    int res = srcFolderDia.exec();
    printf("SrcfolderDia = %d\n", res);
}
