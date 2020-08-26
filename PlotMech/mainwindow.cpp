#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <thread>
#include <chrono>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->addGraph();
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle );
    ui->widget->graph(0)->setPen((QColor(Qt::green)));
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->setInteraction(QCP::iRangeDrag, true);
    ui->widget->setInteraction(QCP::iRangeZoom, true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow:: plot()
{
     ui->widget->graph(0)->setData(MainWindow::DataTread.Data_x,MainWindow::DataTread.Data_y);
     ui->widget->replot();
     ui->widget->update();
}



void MainWindow::on_StartButton_clicked()

{   DataTread.GiveData();
    terminated = 1;
    plot();
   /* for (int i=0;i< 1000 ;i++ )
    {
            DataTread.GiveData();
            plot();
        }*/
}
/*void MainWindow::plotting(){
    while(true){
    DataTread.GiveData();
    }
}*/
void MainWindow::on_StopButton_clicked()
{
    DataTread.Data_x.clear();
    DataTread.Data_y.clear();
    plot();
    terminated =0;
}
