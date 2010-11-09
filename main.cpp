#include <QtGui/QApplication>
#include "mainwindow.h"
#include "facadedb.h"

#include <QTableView>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FacadeDb facadeDb;

    MainWindow w(&facadeDb);
    w.show();

    return a.exec();
}
