#include "facadedb.h"

#include <QDebug>

#include <QString>
#include <QtSql>
#include <QSqlTableModel>

FacadeDb::FacadeDb()
{
}

QSqlDatabase *FacadeDb::initializeDb()
{
    sqlDb->setDatabaseName("database");
    if(!sqlDb->open())
    {
        qDebug() << "error : database not opened" << endl;
    }

    QSqlQuery query;
    query.exec("create table if not exists beer_count ( nom TEXT PRIMARY KEY, count INTEGER );");

    query.exec("insert into beer_count values ('Mr. Connard', 5);");

    return sqlDb;
}

void FacadeDb::initializeModel(QSqlTableModel *model)
{
    model->setTable("beer_count");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Compteur"));
}

void FacadeDb::addDrinker(QString name, int count = 0)
{
    QSqlQuery query;
    query.exec("insert into beer_count values (" + name + ", " + QString(count) + ");");
}