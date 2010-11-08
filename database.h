#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql>
#include <QSqlTableModel>

class DataBase
{
public:
    DataBase();
    void initializeDb();
    void initializeModel(QSqlTableModel *model);
    void addDrinker(QString name, int count);

private:
    QSqlDatabase sqlDb;
};

#endif // DATABASE_H
