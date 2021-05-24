#include "calculatevalue.h"

CalculateValue::CalculateValue(QObject *parent) : QObject(parent)
{
   countPointInCircle=0;
   countPoint=0;
    interation=0;
   flag=false;

}

double CalculateValue::getPi() const
{
    if(countPoint==0) return 0;
    return (double)countPointInCircle*4/countPoint;
}

int CalculateValue::getInter() const
{
    return interation;
}

bool CalculateValue::getFlag() const
{
    return flag;
}

void CalculateValue::changeFlag()
{
    flag=!flag;
}

void CalculateValue::reset()
{
    countPointInCircle=0;
    countPoint=0;
     interation=0;
}

void CalculateValue::calculate()
{
    double x = (double) rand()/RAND_MAX;
    double y = (double) rand()/RAND_MAX;
    if(x*x+y*y<=1) countPointInCircle++;
    countPoint++;
    interation++;


}
