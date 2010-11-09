#include "facadedb.h"

#include <QDebug>

#include <QString>
#include <QtSql>
#include <QSqlTableModel>

void FacadeDb::addDrinker(QString name, int count = 0)
{
    /*QSqlQuery query;
    query.exec("insert into beer_count values ('" + name + "', " + QString::number(count) + ");");
    model->select();*/

    QSqlRecord record = model->record();
    record.setValue("name", name);
    record.setValue("count", count);

    model->insertRecord(-1, record);
}

void FacadeDb::delDrinker(QModelIndex index)
{
    model->removeRow(index.row());
}

QSqlTableModel *FacadeDb::getModel()
{
    return model;
}

void FacadeDb::initializeDb()
{
    db->setDatabaseName("database");
    db->open();

    QSqlQuery query;
    query.exec("create table if not exists beer_count ( name TEXT PRIMARY KEY, count INTEGER );");
}

void FacadeDb::initializeModel()
{
    model->setTable("beer_count");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Compteur"));
}

FacadeDb::FacadeDb():
    db(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
    model(new QSqlTableModel())
{
    initializeDb();
    initializeModel();
}

FacadeDb::~FacadeDb()
{
    delete model;
    delete db;
}
