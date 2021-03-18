#include "include/Model/SnippetModel.h"

SnippetModel::SnippetModel(){
	QDirIterator it(QCoreApplication::applicationDirPath()+"/Snippets");
    while(it.hasNext()){
        QFile file(it.next());
        QFileInfo info(file);
        if(info.baseName() != ""){
            snippets << (info.absoluteFilePath());
        }
    }
}

int SnippetModel::rowCount(const QModelIndex &parent) const{
	return snippets.size();
}

QVariant SnippetModel::data(const QModelIndex &index, int role) const{
	if(role == Qt::DisplayRole){
		return QVariant(QFileInfo(snippets.at(index.row())).baseName());
	}
	return QVariant();
}