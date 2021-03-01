#ifndef CONSOLEMODEL_H
#define CONSOLEMODEL_H

#include <QtWidgets>

class ConsoleModel : public QAbstractTableModel{
    Q_OBJECT
    public:
        ConsoleModel(QSettings *settings, QObject *parent = nullptr);
        ~ConsoleModel();
        int rowCount(const QModelIndex &parent = QModelIndex()) const;
        int columnCount(const QModelIndex &parent = QModelIndex()) const;
        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
        QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
        bool addConsole(QString name, QString cmd);
        bool modify(int row, QString name, QString cmd);
        void removeConsole(int row);
        void valider();
        void reload();
    private:
        typedef struct Console{
            Console(const QString name,const QString cmd){
                this->name = name;
                this->cmd = cmd;
            }
            QString name;
            QString cmd;
        } Console;


    private:
        QSettings *m_settings;
        QList<Console*> m_consoles;
        void defaultInit();
};

#endif // CONSOLEMODEL_H
