#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    zmienna1=0;
    zmienna2=0;
    Option=0;
    przecinek=false;
    pamiec="0";
    next=false;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::button(int x,QString Text)                     //Dodatkowy slot do obsługi przycisków dla optymalizacji kodu
{
    if(next==true){
        pamiec="0";
        next=false;
}

     QString text= pamiec;
     if(text.length()>=ui->LCD->digitCount())return;
     else if(text != "0")
     {
         text.append(Text);
         ui->LCD->display(text);
          pamiec=text;
     }
     else if(text=="0"){
         ui->LCD->display(x);
         pamiec=Text;
     }
}

void MainWindow::on_P0_clicked()                                   //Sloty przycisków
{
button(0,"0");
}

void MainWindow::on_P1_clicked()
{
button(1,"1");
}

void MainWindow::on_P2_clicked()
{
button(2,"2");
}

void MainWindow::on_P3_clicked()
{
button(3,"3");
}

void MainWindow::on_P4_clicked()
{
button(4,"4");
}

void MainWindow::on_P5_clicked()
{
button(5,"5");
}

void MainWindow::on_P6_clicked()
{
button(6,"6");
}

void MainWindow::on_P7_clicked()
{
button(7,"7");
}

void MainWindow::on_P8_clicked()
{
button(8,"8");
}

void MainWindow::on_P9_clicked()
{
button(9,"9");
}

void MainWindow::on_POd_clicked()                             //Odejmowanie
{
    QString text= pamiec;
    ui->EScreen->setText(text);
    text="0";
    ui->LCD->display(text);
    Option=Minus;
    pamiec="0";
}

void MainWindow::on_PDod_clicked()                            //Dodawanie
{
    QString text= pamiec;
    ui->EScreen->setText(text);
    text="0";
    ui->LCD->display(text);
    Option=Plus;
    pamiec="0";
}

void MainWindow::on_PMn_clicked()                             //Mnożenie
{
    QString text= pamiec;
    ui->EScreen->setText(text);
    text="0";
    ui->LCD->display(text);
    Option=Multiply;
    pamiec="0";
}

void MainWindow::on_PDz_clicked()                             //Dzielenie
{
    QString text= pamiec;
    ui->EScreen->setText(text);
    text="0";
    ui->LCD->display(text);
    Option=Divide;
    pamiec="0";
}

void MainWindow::on_PP_clicked()                             //Przecinek
{
    QString text= pamiec;
    text.append(".");
    ui->LCD->display(text);
    pamiec=text;
}

void MainWindow::on_PC_clicked()                             //Czyszczenie wszystkiego (wpisywana cyfra+wpisana poprzednio)
{
    ui->EScreen->clear();
    ui->LCD->display("0");
    pamiec="0";
}

void MainWindow::on_PCE_clicked()                            //Czyszczenie LCD (wpisywana cyfra)
{
    ui->LCD->display("0");
    pamiec="0";
}

void MainWindow::on_PR_clicked()                             //Przycisk "="
{
    zmienna1=ui->EScreen->text().toDouble();
    zmienna2=ui->LCD->value();
    double tymczasowa=0;

    switch(Option)
    {
    case Plus:
        tymczasowa=zmienna1+zmienna2;
        break;
    case Minus:
        tymczasowa=zmienna1-zmienna2;
        break;
    case Divide:
        tymczasowa=zmienna1/zmienna2;
        break;
    case Multiply:
        tymczasowa=zmienna1*zmienna2;
        break;
    case Mod:
        tymczasowa=std::fmod(zmienna1,zmienna2);

    };
    QString text=QString::number(tymczasowa);
    if(text.length()>=ui->LCD->digitCount())
    {
        ui->LCD->display("ERR");
    }
    else
    {
    ui->LCD->display(tymczasowa);
    }
    ui->EScreen->clear();
    pamiec=text;
    next=true;
}

void MainWindow::on_PMod_clicked()                             //Modulo
{
    QString text= pamiec;
    ui->EScreen->setText(text);
    text="0";
    ui->LCD->display(text);
    Option=Mod;
    pamiec="0";
}

void MainWindow::on_PSin_clicked()                             //Sinus
{
    zmienna1=ui->LCD->value();
    double tymczasowa=0;
    zmienna2=zmienna1*M_PI;
    zmienna1=zmienna2/180;
    tymczasowa=sin(zmienna1);
    ui->LCD->display(tymczasowa);
    pamiec="0";
    next=true;
}

void MainWindow::on_PCos_clicked()                             //Cosinus
{
    zmienna1=ui->LCD->value();
    double tymczasowa=0;
    zmienna2=zmienna1*M_PI;
    zmienna1=zmienna2/180;
    tymczasowa=cos(zmienna1);
    ui->LCD->display(tymczasowa);
    pamiec="0";
    next=true;
}

void MainWindow::on_PTan_clicked()                             //Tangens
{
    zmienna1=ui->LCD->value();
    double tymczasowa=0;
    zmienna2=zmienna1*M_PI;
    zmienna1=zmienna2/180;
    tymczasowa=tan(zmienna1);
    ui->LCD->display(tymczasowa);
    pamiec="0";
    next=true;
}

void MainWindow::on_PCot_clicked()                             //Cotangens
{
    zmienna1=ui->LCD->value();
    if(zmienna1==0)
    {
    ui->LCD->display("ERR");
    }
    else{
    double tymczasowa=0;
    zmienna2=zmienna1*M_PI;
    zmienna1=zmienna2/180;
    tymczasowa=tan(zmienna1);
    tymczasowa=1/tymczasowa;
    ui->LCD->display(tymczasowa);
    pamiec="0";
    next=true;
    }
}
void MainWindow::on_Puj_clicked()                             //Dodawanie minusa przed liczbą
{
     QString text= pamiec;
     if(text=="0"||text.contains("-")==true||text.length()>=ui->LCD->digitCount())return;
     else if(text != "0")
     {
         text.prepend("-");
         ui->LCD->display(text);
         pamiec=text;
     }
}
