#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QThread>
#include <unistd.h>
#include <generate.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool terminated=0;
    void plotting();
    QVector <double> XX;
    QVector <double> YY;

public slots:
   /* void on_pushButton_clicked();

    void on_pushButton_2_clicked();
*/
    void plot(double x, double y);

private slots:
    void on_StartButton_clicked();

    void on_StopButton_clicked();

signals:

private:
    Ui::MainWindow *ui;
    QThread *pMyThread;
    Generate *pGen;
};
#endif // MAINWINDOW_H
