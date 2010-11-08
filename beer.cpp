#include "beer.h"
#include <QDebug>

Beer::Beer()
{
    count = 0;
}


void Beer::Add(int number)
{
    if (number > 0)
    {
        count += number;
        qDebug() << number << ", count:" << count;
    }
}

int Beer::GetCount()
{
    qDebug() << "count:" << count;
    return count;
}
