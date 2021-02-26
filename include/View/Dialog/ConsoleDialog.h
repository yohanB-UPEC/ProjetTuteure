#ifndef CONSOLEDIALOG_H
#define CONSOLEDIALOG_H

#include <QtWidgets>
#include "include/Model/ConsoleModel.h"
#include "include/Controller/Dialog/ConsoleController.h"

class ConsoleDialog : public QDialog{
    Q_OBJECT

    friend class ConsoleController;

    public:
        ConsoleDialog(ConsoleModel *model, QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
    public slots:
        void addDialog(QString name = QString(), QString cmd = QString());

    signals:
        void validateModify(QDialog&,QString,QString);

    private:
        ConsoleModel *m_model;
        QTableView *m_table;
        ConsoleController m_controller;
        QDialog *m_dial;
        QLineEdit *m_name;
        QLineEdit *m_cmd;


};

#endif // CONSOLEDIALOG_H
