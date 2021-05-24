#ifndef CALCULATEVALUE_H
#define CALCULATEVALUE_H

#include <QObject>

class CalculateValue : public QObject
{
    Q_OBJECT
public:
    explicit CalculateValue(QObject *parent = nullptr);
    double getPi () const;
    int getInter() const;
    bool getFlag()const;
    void changeFlag();
    void reset();
private:
    int countPointInCircle;
    int countPoint;
    int interation;
    bool flag;

private slots:
    void calculate();

};

#endif // CALCULATEVALUE_H
