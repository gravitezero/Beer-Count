#include <QtGui/QApplication>
#include "mainwindow.h"
#include "database.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DataBase db;
    db.initializeDb();

    MainWindow w;
    db.initializeModel(w.GetModel());
    w.show();

    return a.exec();
}
