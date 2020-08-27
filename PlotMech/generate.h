#ifndef GENERATE_H
#define GENERATE_H

#include <QObject>
#include <random>
class Generate : public QObject
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);
    QVector <double> X_X;
    QVector <double> Y_Y;
    double Random_double();
public slots:
    void generation();
signals:
    void emitDATA(double x, double y);
};

#endif // GENERATE_H
