#ifndef CONTROLLER
#define CONTROLLER

#include <QtWidgets>
#include "include/Model/TreeItem.h"
#include "include/View/Widget/DCodeEditor.h"
#include "include/View/Menu/MenuContextExplorer.h"

class Fenetre;
class Model;

class Controller : public QObject{
	Q_OBJECT
	
	public:
		Controller(Fenetre *fen, Model *model);
		
	public slots:
        void openEditor(const QModelIndex &index);
        void openEditor(QString path=QString());
        void closeEditor(int index = -1);
        void closeAllEditor();
        void saveEditor();
        void saveAllEditor();
        void explorerContextMenu(const QPoint& pos);
	private:
		Fenetre * fen;
		Model *model;
	
};
#endif
