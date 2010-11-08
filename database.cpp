#include "database.h"

#include <QString>
#include <QtSql>
#include <QSqlTableModel>

DataBase::DataBase():
    sqlDb(QSqlDatabase::addDatabase("QSQLITE"))
{
    sqlDb.setDatabaseName("database");
    sqlDb.open();
}

void DataBase::initializeDb()
{
    QSqlQuery query;
    query.exec("create table if not exists beer_count ( nom TEXT PRIMARY KEY, count INTEGER );");
}

void DataBase::initializeModel(QSqlTableModel *model)
{
    model->setTable("beer_count");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Compteur"));
}

void DataBase::addDrinker(QString name, int count = 0)
{
    QSqlQuery query;
    query.exec("insert into beer_count values (" + name + ", " + QString(count) + ");");
}
