#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>

#include "facade.h"
#include "database.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSqlTableModel *GetModel();

public slots:
    void BeerButtonClicked();
    void GetButtonClicked();

private:
    void initializeModel();

    Ui::MainWindow *ui;
    Facade facade;
    QSqlTableModel model;
};

#endif // MAINWINDOW_H
