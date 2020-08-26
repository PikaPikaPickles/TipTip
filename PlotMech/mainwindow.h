#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <randomthread.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void plot();
    bool terminated=0;
    void plotting();
    RandomThread DataTread;
public slots:
   /* void on_pushButton_clicked();

    void on_pushButton_2_clicked();
*/

    private slots:
    void on_StartButton_clicked();

    void on_StopButton_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
