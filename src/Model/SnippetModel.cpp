#include "include/Model/SnippetModel.h"

SnippetModel::SnippetModel(){
    QDir dir(QCoreApplication::applicationDirPath()+"/Snippets");
    QFileInfoList list = dir.entryInfoList();
    qDebug() << "Liste des snippets trouvée :";
    for(int i =0; i < list.size();i++){
        if(list.at(i).baseName() != ""){
            qDebug() << "\t- " << list.at(i).absoluteFilePath();
            snippets << (list.at(i).absoluteFilePath());
        }
    }
}

int SnippetModel::rowCount(const QModelIndex &parent) const{
	return snippets.size();
}

QVariant SnippetModel::data(const QModelIndex &index, int role) const{
    if(role == Qt::DisplayRole || role == Qt::EditRole){
		return QVariant(QFileInfo(snippets.at(index.row())).baseName());
	}
	return QVariant();
}

bool SnippetModel::exist(const QString& name){
    if(this->snippets.contains(name)){
        return true;
    }
    return false;
}

bool SnippetModel::addSnippet(const QString &name){
    qDebug() << "initialisation de " << name ;
    QFile file(QCoreApplication::applicationDirPath()+"/Snippets/"+name+".java");
    if(!file.open(QIODevice::WriteOnly | QIODevice::NewOnly)){
        qDebug() << "impossible de créer le fichier de snippet";
        return false;
    }
    file.close();
    qDebug() << "lancement du signal beginInsertRows";
    emit this->beginInsertRows(QModelIndex(), snippets.size(),snippets.size());
    snippets << name;
    emit this->endInsertRows();
    return true;
}

bool SnippetModel::removeRows(int row, int count, const QModelIndex &parent){
   Q_ASSERT(row < rowCount());
   Q_ASSERT(row+count <= rowCount());

    emit beginRemoveRows(parent,row,row+count-1);
    QStringListIterator it(snippets);
    int i = 0;
    while (it.hasNext() && i < row+count){
        QString str = it.next();
        if(i >= row){
            QFile::remove(str);
            snippets.removeAt(i);
        }
        i++;
    }
    emit endRemoveRows();
    return true;
}

const QString SnippetModel::getText(const QModelIndex& index){
    QString name = snippets.at(index.row());
    QFile file(name);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "impossible d'ouvrir le snippet pour le copier";
        QMessageBox::warning(nullptr,"ouvertur impossible","impossible d'ouvrir le snippet "+file.fileName());
        return "";
    }
    QString res = file.readAll();
    file.close();
    return res;
}
