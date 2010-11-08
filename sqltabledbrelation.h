#ifndef SQLTABLEDBRELATION_H
#define SQLTABLEDBRELATION_H

#include <QObject>
#include <QTableView>

#include <QSqlDatabase>
#include <QSqlTableModel>

class SqlTableDbRelation : public QObject
{
    Q_OBJECT

public:
    SqlTableDbRelation(QObject *parent);
private:

};

#endif // SQLTABLEDBRELATION_H
