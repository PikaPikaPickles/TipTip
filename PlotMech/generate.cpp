#include "generate.h"
#include <unistd.h>
Generate::Generate(QObject *parent) : QObject(parent)
{

}
void Generate:: generation()
{
    while(true)
        {
            if(is_working){ // проверяем флажок
        sleep(1);   // время на кастование одной пары чисел
        emit  emitDATA((random()%100-0.1),(random()%100-0.1) );     //сигналим цифры в слот пуша и обновления
        }
        else{
            //X_X.clear();
            //Y_Y.clear();            //если флажок false (нажата кнопка паузы или стопа, останавливаем цикл
            break;
        }
    }
}
