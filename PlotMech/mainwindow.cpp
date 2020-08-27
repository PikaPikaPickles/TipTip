#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <unistd.h>     //первая попавшаяся библиотека для задержки
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->addGraph();                                             // Добавляем график сюда
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle );  // Выбираем форму точек
    ui->widget->graph(0)->setPen((QColor(Qt::green)));                  // Выбираем цвет
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);               // Линиями не соединяем
    ui->widget->setInteraction(QCP::iRangeDrag, true);                  // Включаем проползание при нажатии и переносе мышки
    ui->widget->setInteraction(QCP::iRangeZoom, true);                  // Включаем масштабирование
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow:: plot(double x, double y)                              //Функция запоминания данных и отрисовке их
{    XX.append(x);
     YY.append(y);
     ui->widget->graph(0)->setData(MainWindow::XX,MainWindow::YY);      //Передаем векторы
     ui->widget->replot();                                              //Перестраиваем
     ui->widget->update();                                              //Обновляем
}



void MainWindow::on_StartButton_clicked()                               //Слот кнопки старта

{
    if (!no_two_times){
    pMyThread = new QThread;                                            //Выделили память под экземпляры класса
    pGen =new Generate;                                                 //Выделили память под экземпляры класса (2)
    pGen->is_working = 1;                                               //Флажок включен
    pGen->moveToThread(pMyThread);                                      //Поместили метод в поток
    connect(pGen,SIGNAL(emitDATA(double , double )), this, SLOT(plot(double , double )));           //Связываем сигнал передачи чисел со слотом отрисовки
   // connect(pGen, &Generation:: emitData, this, &MainWindow::slotButton);
    connect(pMyThread,SIGNAL(started()), pGen, SLOT(generation()));                                 // Сигнал запуска потока и слот генерации чисел
    pMyThread->start();                                                                             // Запускаем поток
    no_two_times = 1;
    }
}
void MainWindow::on_StopButton_clicked()                                //Слот кнопки стопа
{

    pGen->is_working =0;                                                //Флажок на выкл
  //pGen->X_X.clear();                                                  //Очищаем вектор с абсциссой
  //pGen->Y_Y.clear();                                                  //Очищаем вектор с ординатой
    ui->widget->graph(0)->data()->clear();                              //Очищаем массив данных в самом графике
    this->XX.clear();                                                   //Очищаем вектор с абсциссой
    this->YY.clear();                                                   //Очищаем вектор с ординатой
    ui->widget->replot();                                               //Обновление и перестроение
    ui->widget->update();
    no_two_times = 0;
}

void MainWindow::on_PauseButton_clicked()                               //Слот кнопки памяти
{
    pGen->is_working =0;                                                //Флажок на Выкл
    no_two_times = 0;
}
