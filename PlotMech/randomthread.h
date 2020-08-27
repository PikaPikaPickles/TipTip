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
    bool key = 0;
    explicit RandomThread(QObject *parent = nullptr);
    QVector <double> Data_x;
    QVector <double> Data_y;

    double Random_double();
public slots:
    void GiveData();
    void KeyFunc();
signals:

};

#endif // RANDOMTHREAD_H
