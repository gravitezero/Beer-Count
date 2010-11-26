#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "facadedb.h"

#include <QDebug>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlDatabase>

void MainWindow::addDrinker()
{
    if(!ui->drinkerName->text().isEmpty())
    {
        facadeDb->addDrinker(ui->drinkerName->text(), ui->drinkerCount->value());
    }
}

void MainWindow::delDrinker()
{
    facadeDb->delDrinker(ui->tableView->currentIndex());
}

MainWindow::MainWindow(FacadeDb *facadeDb, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    facadeDb(facadeDb)
{    
    ui->setupUi(this);
    connect(ui->addDrinkerButton, SIGNAL(clicked()), this, SLOT(addDrinker()));
    connect(ui->drinkerName, SIGNAL(returnPressed()), this, SLOT(addDrinker()));

    connect(ui->delDrinkerButton, SIGNAL(clicked()), this, SLOT(delDrinker()));

    ui->tableView->setModel(facadeDb->getModel());
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
