#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QSqlTableModel>

class FacadeDb
{
public:
    FacadeDb();
    void initializeDb(QSqlDatabase *db);
    void initializeModel(QSqlTableModel *model);
    void refreshModel(QSqlTableModel *model);
    void addDrinker(QString name, int count);

private:
    QSqlDatabase *sqlDb;
};

#endif // DATABASE_H
