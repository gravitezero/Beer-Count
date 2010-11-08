#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"

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

QSqlTableModel *MainWindow::GetModel()
{
    return &model;
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(BeerButtonClicked()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(GetButtonClicked()));



    ui->tableView->setModel(&model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
