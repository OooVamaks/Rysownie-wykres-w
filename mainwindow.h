#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_TimerInterrupt1();
    void on_TimerInterrupt2();
    void on_TimerInterrupt3();



    void on_asin_valueChanged(int value);

    void on_fsin_valueChanged(int value);

    void on_bsin_valueChanged(int value);

    void on_asqr_valueChanged(int value);

    void on_fsqr_valueChanged(int value);

    void on_bsqr_valueChanged(int value);

    void on_atrian_valueChanged(int value);

    void on_ftrian_valueChanged(int value);

    void on_btrian_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    QTimer * timer1;
    QTimer * timer2;
    QTimer * timer3;
    bool StartStop1;
    bool StartStop2;
    bool StartStop3;
};
#endif // MAINWINDOW_H
