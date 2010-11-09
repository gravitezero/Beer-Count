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
    explicit MainWindow(FacadeDb *facadeDb, QWidget *parent = 0);
    ~MainWindow();

public slots:
    void addDrinker();
    void delDrinker();

private:
    Ui::MainWindow *ui;
    FacadeDb *facadeDb;
};

#endif // MAINWINDOW_H
