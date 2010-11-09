#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QTableView>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database");
    db.open();*/

    //QSqlQuery query;
    //query.exec("create table if not exists beer_count ( nom TEXT PRIMARY KEY, count INTEGER );");
    //query.exec("insert into beer_count values ('Mr. Connard', 5);");

    /*QSqlTableModel model;
    model.setTable("beer_count");
    model.setEditStrategy(QSqlTableModel::OnFieldChange);
    model.select();

    model.setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model.setHeaderData(1, Qt::Horizontal, QObject::tr("count"));

    QTableView *view = new QTableView;
    view->setModel(&model);
    view->show();*/

    MainWindow w;
    w.show();

    return a.exec();
}
