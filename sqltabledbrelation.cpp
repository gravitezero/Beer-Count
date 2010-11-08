#include "sqltabledbrelation.h"

#include <QSqlTableModel>
#include <QTableView>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>

SqlTableDbRelation::SqlTableDbRelation(QObject *parent):
        QObject(parent),
        db(QSqlDatabase::addDatabase("QSQLITE")),
        model(this, db)
{
    db.setDatabaseName("database");
    db.open();

    QSqlQuery query;
    query.exec("create table if not exists beer_count ( nom TEXT PRIMARY KEY, count INTEGER );");

    query.exec("insert into beer_count values ('Mr. Connar', 4);");
    query.exec("insert into beer_count values ('Mme. Bite', 0);");

    model.setTable("beer_count");
    model.setEditStrategy(QSqlTableModel::OnFieldChange);
    model.select();

    model.setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model.setHeaderData(1, Qt::Horizontal, QObject::tr("Compteur"));
}
