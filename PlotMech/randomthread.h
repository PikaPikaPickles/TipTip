#ifndef RANDOMTHREAD_H
#define RANDOMTHREAD_H
#include <iomanip>
#include <limits>
#include <random>
#include <iostream>
#include <QObject>

class RandomThread : public QObject
{
    Q_OBJECT
public:
    explicit RandomThread(QObject *parent = nullptr);
    QVector <double> Data_x;
    QVector <double> Data_y;
    void GiveData();
    double Random_double();

signals:

};

#endif // RANDOMTHREAD_H
