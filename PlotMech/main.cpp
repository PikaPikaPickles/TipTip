#include "mainwindow.h"
#include <QApplication>
#include <thread>
#include <unistd.h>
int main(int argc, char *argv[])
{    

    QApplication a(argc, argv);
    MainWindow w;
   /* std::thread t([&](){
        while(true){
        sleep(1000);
        w.DataTread.GiveData();
        }
    } );
*/
    w.show();
 //  t.join();
    return a.exec();
}
