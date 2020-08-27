#include "generate.h"
#include <unistd.h>
Generate::Generate(QObject *parent) : QObject(parent)
{

}
void Generate:: generation()
{
    for(int i=0; i<10; i++)
    {
        sleep(1);
        emit  emitDATA((random()%100-0.1),(random()%100-0.1) );
    }
}
