#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>

#include "facade.h"
#include "facadedb.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void BeerButtonClicked();
    void GetButtonClicked();

private:
    Ui::MainWindow *ui;
    Facade facade;
    FacadeDb *facadeDb;
    QSqlDatabase *db;
    QSqlTableModel *model;
};

#endif // MAINWINDOW_H
