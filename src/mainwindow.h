#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <qcustomplot.h>
#include <QVector>
#include <QMessageBox>
#include <QDialog>

extern "C" {
#include "s21_smartcalc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
//    void digit_numbers();

    void on_pushButton_AC_clicked();
    void on_pushButton_poit_clicked();
    void on_pushButton_plus_clicked();
    void on_pushButton_minus_clicked();
    void on_pushButton_drob_clicked();
    void on_pushButton_stepen_clicked();
    void on_pushButton_umnosenie_clicked();
    void on_pushButton_prav_scob_clicked();
    void on_pushButton_lev_scob_clicked();
    void on_pushButton_x_clicked();
    void on_pushButton_sin_clicked();
    void on_pushButton_cos_clicked();
    void on_pushButton_tan_clicked();
    void on_pushButton_atan_clicked();
    void on_pushButton_acos_clicked();
    void on_pushButton_asin_clicked();
    void on_pushButton_log_clicked();
    void on_pushButton_sqrt_clicked();
    void on_pushButton_mod_clicked();
    void on_pushButton_ln_clicked();
    void on_pushButton_0_clicked();
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
    void on_pushButton_8_clicked();
    void on_pushButton_9_clicked();
    void on_pushButton_ravno_clicked();

    void on_pushButton_Graphics_clicked();

    void on_pushButton_kr_clicked();

    void on_pushButton_kr_2_clicked();

private:
    Ui::MainWindow *ui;
    double xBegin, xEnd, h, X;
    int N;
    QVector<double> x, y;
};

#endif // MAINWINDOW_H
