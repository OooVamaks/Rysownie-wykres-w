#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->timer1 = new QTimer();
    this->timer2 = new QTimer();
    this->timer3 = new QTimer();
    connect(this->timer1, SIGNAL(timeout()),this, SLOT(on_TimerInterrupt1()));
    connect(this->timer2, SIGNAL(timeout()),this, SLOT(on_TimerInterrupt2()));
    connect(this->timer3, SIGNAL(timeout()),this, SLOT(on_TimerInterrupt3()));
    ui->ekran1->addGraph();
    ui->ekran2->addGraph();
    ui->ekran3->addGraph();
    this->StartStop1 = false;
    this->StartStop2 = false;
    this->StartStop3 = false;
}
double sin_a = 0;
int sin_b = 1;
double sin_f = 0;
int sqr_a = 0;
int sqr_b = 1;
 int sqr_f = 0;
double trian_a = 0;
int trian_f = 1;
double trian_b = 0;
bool zmienna1=false;
 bool zmienna2=false;
double zmienna3 = 0;
int wynik1;
double wynik2;


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    if(this->StartStop1){
        timer1->stop();
        this->StartStop1 = false;
    }
    else{
        timer1->start(100);
        this->StartStop1 = true;
    }

}
void MainWindow::on_pushButton_2_clicked()
{
    if(this->StartStop3){
        timer3->stop();
            this->StartStop3 = false;
    }
    else{
        timer3->start(100);
        this->StartStop3 = true;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(this->StartStop2){
         timer2->stop();
        this->StartStop2 = false;
    }
    else{
        timer2->start(100);
        this->StartStop2 = true;
    }
}




void MainWindow::on_TimerInterrupt1() {
    static unsigned int licznik = 0;
    static QList<double> time;
    static QList<double> value;
     double t = licznik * 0.01;
    double val = sin_b+sin_a*sin(sin_f*3.1416*t);
    time.append(t);
    value.append(val);
    ui->ekran1->graph(0)->setData(time.toVector(),value.toVector());
    if(licznik<250) {
        ui->ekran1->xAxis->setRange(0,10);
    } else {
        ui->ekran1->xAxis->setRange(t-5,t+5);
    }
    ui->ekran1->yAxis->setRange(sin_b-(sin_a+1),sin_b+(sin_a+1));
    ui->ekran1->replot();
    licznik++;

}

void MainWindow::on_asin_valueChanged(int value)
{
    ui->lcdSA->display(QString::number(value));
    sin_a=value;
}


void MainWindow::on_fsin_valueChanged(int value)
{
        ui->lcdSF->display(QString::number(value));
    sin_f=value;
}


void MainWindow::on_bsin_valueChanged(int value)
{
    ui->lcdSB->display(QString::number(value));
    sin_b=value;
}

void MainWindow::on_TimerInterrupt2() {
    static unsigned int licznik = 0;
    static QList<double> time;
    static QList<double> value;
        double t = licznik * 0.01;

    if(int i = (licznik%(100/sqr_f)) == 0) {
        zmienna1 = !zmienna1;
    }

    if(zmienna1 == true) {
        wynik1 = sqr_a+sqr_b;
    } else {
        wynik1 = -sqr_a+sqr_b;
    }

    time.append(t);
    value.append(wynik1);
    ui->ekran2->graph(0)->setData(time.toVector(),value.toVector());

    if(licznik<250) {
        ui->ekran2->xAxis->setRange(0,10);
    } else {
        ui->ekran2->xAxis->setRange(t-5,t+5);
    }

    ui->ekran2->yAxis->setRange(sqr_b-sqr_a-2,sqr_b+sqr_a+2);
    ui->ekran2->replot();
    licznik++;

}

void MainWindow::on_asqr_valueChanged(int value)
{
    ui->lcdSqa->display(QString::number(value));
    sqr_a=value;
}


void MainWindow::on_fsqr_valueChanged(int value)
{
    ui->lcdSqf->display(QString::number(value));
    sqr_f=value;
}


void MainWindow::on_bsqr_valueChanged(int value)
{
    ui->lcdSqb->display(QString::number(value));
    sqr_b=value;
}


void MainWindow::on_TimerInterrupt3() {
    static unsigned int licznik = 0;
    static QList<double> time;
    static QList<double> value;
    double t = licznik * 0.01;

    if(int i = (licznik%(100/trian_f)) == 0) {
        zmienna2 = false;
    }
    if(zmienna2==true) {
        wynik2=2*trian_a*(t-zmienna3)*trian_f-trian_a+trian_b;
    } else {
        wynik2=-trian_a+trian_b;
        if (t!=0) {
            zmienna3=t;
        }
        zmienna2=true;
    }
    time.append(t);
    value.append(wynik2);
    ui->ekran3->graph(0)->setData(time.toVector(),value.toVector());

    if(licznik<250) {
        ui->ekran3->xAxis->setRange(0,10);
    } else {
        ui->ekran3->xAxis->setRange(t-5,t+5);
    }

    ui->ekran3->yAxis->setRange(trian_b-trian_a-2,trian_b+trian_a+2);
    ui->ekran3->replot();
    licznik++;
}





void MainWindow::on_atrian_valueChanged(int value)
{
    ui->lcdTA->display(QString::number(value));
    trian_a=value;
}


void MainWindow::on_ftrian_valueChanged(int value)
{
    ui->lcdTF->display(QString::number(value));
    trian_f=value;
}


void MainWindow::on_btrian_valueChanged(int value)
{
    ui->lcdTB->display(QString::number(value));
    trian_b=value;
}

