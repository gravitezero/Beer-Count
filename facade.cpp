#include "facade.h"
#include "beer.h"

#include <QDebug>

Facade::Facade()
{
}

void Facade::AddBeer(int number)
{
    beer.Add(number);
}

int Facade::GetCount()
{
    return beer.GetCount();
}
