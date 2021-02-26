#include "include/Model/ConsoleModel.h"

ConsoleModel::ConsoleModel(QSettings *settings, QObject *parent): QAbstractTableModel(parent), m_settings(settings){
    this->reload();
    if(m_consoles.size() == 0){
        this->defaultInit();
    }
}
ConsoleModel::~ConsoleModel(){
    for(QList<Console*>::iterator i=m_consoles.begin();i != m_consoles.end();++i){
        delete *i;
    }
}
int ConsoleModel::rowCount(const QModelIndex &parent) const{
    if(parent.isValid()){
        return 0;
    }
    return m_consoles.size();
}

int ConsoleModel::columnCount(const QModelIndex &parent) const{
    if(parent.isValid()){
        return 0;
    }
    return 2;
}

QVariant ConsoleModel::data(const QModelIndex &index, int role) const{
    if(!index.isValid()){
        return QVariant();
    }

    QString *c = (QString*)index.internalPointer();
    if(role == Qt::DisplayRole){
        if(index.column() == 0){
            return QVariant(*c);
        }else if(index.column() == 1){
            return QVariant(*c);
        }
    }
    return QVariant();
}

void ConsoleModel::defaultInit(){
    #ifdef _WIN32
        Console *c = new Console("cmd", "cmd.exe");
        m_consoles.append(c);
    #elif __linux__
        qDebug() << "linux";
        m_consoles.append(new Console("terminal", "terminal"));
    #endif
    this->valider();
}

QModelIndex ConsoleModel::index(int row, int column, const QModelIndex &parent) const{
    if(!(row < m_consoles.size())){
        return QModelIndex();
    }
    if(!parent.isValid()){
        if(column == 0){
            return createIndex(row,column,&m_consoles[row]->name);
        }else if (column == 1){
            return createIndex(row,column,&m_consoles[row]->cmd);
        }
    }
    return QModelIndex();
}

QVariant ConsoleModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if(orientation == Qt::Horizontal && role == Qt::DisplayRole){
        if(section == 0){
            return QVariant("nom");
        }else if(section == 1){
            return QVariant("commande de lancement");
        }
    }
    return QVariant();
}

bool ConsoleModel::addConsole(QString name, QString cmd){
    QList<Console*>::iterator it;
    for(it = m_consoles.begin();it != m_consoles.end();++it){
        if((*it)->name == name){
            return false;
        }
    }

    emit beginInsertRows(QModelIndex(),m_consoles.size(),m_consoles.size());
    m_consoles.append(new Console(name,cmd));
    emit endInsertRows();
    return true;
}

bool ConsoleModel::modify(int row, QString name, QString cmd){
    for(int i = 0; i < m_consoles.size(); i++){
        Console *c = m_consoles[i];
        if(c->name == name && row != i){
            return false;
        }
    }
    Console *c = m_consoles[row];
    c->cmd = cmd;
    c->name = name;
    emit dataChanged(this->index(row,0),this->index(row,1));
    return true;
}

void ConsoleModel::removeConsole(int row){
    emit beginRemoveRows(QModelIndex(),row,row);
    Console *tmp = m_consoles[row];
    this->m_consoles.removeAt(row);
    delete tmp;
    emit endRemoveRows();
}

void ConsoleModel::valider(){
    m_settings->beginGroup("Consoles");
    QList<Console*>::iterator it;
    for(it = m_consoles.begin();it != m_consoles.end();++it){
        m_settings->setValue((*it)->name,(*it)->cmd);
    }
    m_settings->endGroup();
}
void ConsoleModel::reload(){
    for(QList<Console*>::iterator i=m_consoles.begin();i != m_consoles.end();++i){
        delete *i;
    }
    m_consoles.clear();
    m_settings->beginGroup("Consoles");
    QStringList keys = m_settings->allKeys();
    for(int i = 0; i < keys.size(); i++){
        m_consoles.append(new Console(keys[i], m_settings->value(keys[i],"noname").toString()));
    }
    m_settings->endGroup();
}


