#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <cmath>
#include <math.h>
#include <QtMath>


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





    void on_P0_clicked();

    void on_P1_clicked();

    void on_P2_clicked();

    void on_P3_clicked();

    void on_P4_clicked();

    void on_P5_clicked();

    void on_P6_clicked();

    void on_P7_clicked();

    void on_P8_clicked();

    void on_P9_clicked();


    void on_POd_clicked();

    void on_PDod_clicked();

    void on_PMn_clicked();

    void on_PDz_clicked();

    void on_PP_clicked();

    void on_PC_clicked();

    void on_PCE_clicked();

    void on_PR_clicked();



    void on_PMod_clicked();

    void on_PSin_clicked();

    void on_PCos_clicked();

    void on_PTan_clicked();

    void on_PCot_clicked();

    void button(int x,QString Text);



    void on_Puj_clicked();

private:
    Ui::MainWindow *ui;

    enum Operation{

        Plus,
        Minus,
        Multiply,
        Divide,
        Mod
    };

    double zmienna1;
    double zmienna2;
    int Option;
    bool przecinek;
    QString pamiec;
    bool next;
};
#endif // MAINWINDOW_H
