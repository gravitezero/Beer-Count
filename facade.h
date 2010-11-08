#ifndef FACADE_H
#define FACADE_H

#include "beer.h"
#include <QObject>

class Facade : public QObject
{
    Q_OBJECT

public:
    Facade();
    void AddBeer(int number);
    int GetCount();

private:
    Beer beer;

};

#endif // FACADE_H
