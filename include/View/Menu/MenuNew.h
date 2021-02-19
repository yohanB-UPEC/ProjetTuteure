#ifndef MENUNEW
#define MENUNEW

#include <QMenu>
#include "../Dialog/ProjectDialog.h"
#include "../Dialog/PackageDialog.h"
#include "../Dialog/ClassDialog.h"
#include "../Dialog/FolderDialog.h"

class Fenetre; 

class MenuNew : public QMenu {
	Q_OBJECT
	
	public:
		MenuNew(Fenetre* fen);
	
	public slots:
		void s_File();
		void s_Project();
		void s_Package();
		void s_Class();
        void s_Interface();
        void s_Enum();
        void s_Folder();
        void s_SrcFolder();
		
	private:
		QAction *javaProject;
		QAction *package;
		QAction *aClass;
		QAction *aInterface;
		QAction *aEnum;
		QAction *folder;
        QAction *srcfolder;
		QAction *file;
		Fenetre *fen;
};

#endif
