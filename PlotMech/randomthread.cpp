#include "randomthread.h"

RandomThread::RandomThread(QObject *parent) : QObject(parent)
{

}

void RandomThread:: GiveData(){
    // read two real numbers
    for(int i=0; i<300; i++)
    {
        double l = Random_double();
        this->Data_x.push_back(l);
        l = Random_double();
        this->Data_y.push_back(l);
    }
}

double RandomThread:: Random_double()
{
    return (random()/1000);
}
