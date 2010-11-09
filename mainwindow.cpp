#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "facadedb.h"

#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>

void MainWindow::BeerButtonClicked()
{
    facade.AddBeer(ui->spinBox->value());
}

void MainWindow::GetButtonClicked()
{
    ui->lcdNumber->display(facade.GetCount());
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    facadeDb(),
    //db(facadeDb->initializeDb()),
    db(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
    model(new QSqlTableModel())
{    
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(BeerButtonClicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(GetButtonClicked()));

    //QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db->setDatabaseName("database");
    db->open();

    model->setTable("beer_count");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("count"));

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete model;
    delete facadeDb;
    delete db;
    delete ui;
}
