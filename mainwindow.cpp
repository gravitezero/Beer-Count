#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "facadedb.h"

#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>

void MainWindow::AddDrinker()
{
    facadeDb->addDrinker(ui->drinkerName->text(), ui->drinkerCount->value());
    facadeDb->refreshModel(model);
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    facadeDb(new FacadeDb()),
    db(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
    model(new QSqlTableModel())
{    
    ui->setupUi(this);
    connect(ui->addDrinkerButton, SIGNAL(clicked()), this, SLOT(AddDrinker()));

    facadeDb->initializeDb(db);
    facadeDb->initializeModel(model);

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete model;
    delete facadeDb;
    delete db;
    delete ui;
}
