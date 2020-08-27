#ifndef GENERATE_H
#define GENERATE_H

#include <QObject>
#include <random>
class Generate : public QObject
{
    Q_OBJECT
public:
    bool is_working = 0;                            //Переменная - флажок
    explicit Generate(QObject *parent = nullptr);
    // QVector <double> X_X;
    // QVector <double> Y_Y;
    double Random_double();                         //Генератор случайных чисел
public slots:
    void generation();                              //Слот передачи этих самых чисел
signals:
    void emitDATA(double x, double y);              //Сигнал передачи чисел
};

#endif // GENERATE_H
