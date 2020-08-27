#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QThread>
#include <unistd.h>
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


void MainWindow:: plot(double x, double y)
{    XX.append(x);
     YY.append(y);
     ui->widget->graph(0)->setData(MainWindow::XX,MainWindow::YY);
     ui->widget->replot();
     ui->widget->update();
}



void MainWindow::on_StartButton_clicked()

{
    pMyThread = new QThread;
    pGen =new Generate;
    pGen->moveToThread(pMyThread);
    connect(pGen,SIGNAL(emitDATA(double , double )), this, SLOT(plot(double , double )));
   // connect(pGen, &Generation:: emitData, this, &MainWindow::slotButton);
    connect(pMyThread,SIGNAL(started()), pGen, SLOT(generation()));
    pMyThread->start();
}
void MainWindow::on_StopButton_clicked()
{


}
