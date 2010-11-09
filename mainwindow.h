#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QtSql/QSqlDatabase>

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
    void AddDrinker();

private:
    Ui::MainWindow *ui;
    FacadeDb *facadeDb;
    QSqlDatabase *db;
    QSqlTableModel *model;
};

#endif // MAINWINDOW_H
