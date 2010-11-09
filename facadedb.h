#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QSqlTableModel>

class FacadeDb
{
public:
    FacadeDb();
    ~FacadeDb();

    void addDrinker(QString name, int count);
    void delDrinker(QModelIndex index);
    QSqlTableModel *getModel();

private:
    QSqlDatabase *db;
    QSqlTableModel *model;

    void initializeModel();
    void initializeDb();
};

#endif // DATABASE_H
