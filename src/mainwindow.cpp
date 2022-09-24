#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->step->setText("0.1");
    ui->Xmax->setText("10");
    ui->Xmin->setText("-10");
    ui->Ymax->setText("10");
    ui->Ymin->setText("-10");
    ui->Xvalue->setText("0");

    ui->widget->xAxis->setRange(-10, 10);
    ui->widget->yAxis->setRange(-10, 10);

    ui->lineEdit_esssh->setReadOnly(true);
    ui->lineEdit_obchya->setReadOnly(true);
    ui->lineEdit_pereplata->setReadOnly(true);

    ui->lineEdit_sum_konec->setReadOnly(true);
    ui->lineEdit_nachisl->setReadOnly(true);
    ui->lineEdit_sum_nal->setReadOnly(true);

//    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_AC, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_Graphics, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_drob, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(digit_numbers()));
//    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(digit_numbers()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::digit_numbers() {
//    QPushButton *button = (QPushButton *)sender();

//    double all_numbers;
//    QString new_label;
//    all_numbers = (ui->label->text() + button->text()).toDouble();
//    new_label = QString::number(all_numbers);
//    ui->label->setText(new_label);
//}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->label->setText("");
}

void MainWindow::on_pushButton_poit_clicked()
{
    if (!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text() + ".");
}

void MainWindow::on_pushButton_plus_clicked()
{
    ui->label->setText(ui->label->text() + "+");
}

void MainWindow::on_pushButton_minus_clicked()
{
    ui->label->setText(ui->label->text() + "-");
}

void MainWindow::on_pushButton_drob_clicked()
{
    ui->label->setText(ui->label->text() + "/");
}

void MainWindow::on_pushButton_stepen_clicked()
{
    ui->label->setText(ui->label->text() + "^");
}

void MainWindow::on_pushButton_umnosenie_clicked()
{
    ui->label->setText(ui->label->text() + "*");
}

void MainWindow::on_pushButton_prav_scob_clicked()
{
    ui->label->setText(ui->label->text() + ")");
}

void MainWindow::on_pushButton_lev_scob_clicked()
{
    ui->label->setText(ui->label->text() + "(");
}

void MainWindow::on_pushButton_x_clicked()
{
    ui->label->setText(ui->label->text() + "x");
}

void MainWindow::on_pushButton_sin_clicked()
{
    ui->label->setText(ui->label->text() + "sin(");
}

void MainWindow::on_pushButton_cos_clicked()
{
    ui->label->setText(ui->label->text() + "cos(");
}

void MainWindow::on_pushButton_tan_clicked()
{
    ui->label->setText(ui->label->text() + "tan(");
}

void MainWindow::on_pushButton_atan_clicked()
{
    ui->label->setText(ui->label->text() + "atan(");
}

void MainWindow::on_pushButton_acos_clicked()
{
    ui->label->setText(ui->label->text() + "acos(");
}

void MainWindow::on_pushButton_asin_clicked()
{
    ui->label->setText(ui->label->text() + "asin(");
}

void MainWindow::on_pushButton_log_clicked()
{
    ui->label->setText(ui->label->text() + "log(");
}

void MainWindow::on_pushButton_sqrt_clicked()
{
    ui->label->setText(ui->label->text() + "sqrt(");
}

void MainWindow::on_pushButton_mod_clicked()
{
    ui->label->setText(ui->label->text() + "mod");
}

void MainWindow::on_pushButton_ln_clicked()
{
    ui->label->setText(ui->label->text() + "ln(");
}



void MainWindow::on_pushButton_0_clicked()
{
    ui->label->setText(ui->label->text() + "0");
}

void MainWindow::on_pushButton_1_clicked()
{
    ui->label->setText(ui->label->text() + "1");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->label->setText(ui->label->text() + "2");
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->label->setText(ui->label->text() + "3");
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->label->setText(ui->label->text() + "4");
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->label->setText(ui->label->text() + "5");
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->label->setText(ui->label->text() + "6");
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->label->setText(ui->label->text() + "7");
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->label->setText(ui->label->text() + "8");
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->label->setText(ui->label->text() + "9");
}

void MainWindow::on_pushButton_ravno_clicked()
{
    QByteArray temp = ui->label->text().toLocal8Bit();
    char* math = temp.data();

    if (s21_valid_math(math)) {
        double value = ui->Xvalue->text().toDouble();
        stack* rev_perv_el = NULL;

        for (int i = 0; math[i] != '\0'; i++) {
                    s21_zapolnyaem_stack(math, &i, &rev_perv_el, value);
                }

        stack* perv_el = NULL;
        s21_perevorachivaem_stack(&rev_perv_el, &perv_el);

        stack* RPN_num = NULL;
        stack* RPN_sup = NULL;
        s21_RPN(&perv_el, &RPN_num, &RPN_sup);

        stack* res = NULL;
        s21_perevorachivaem_stack(&RPN_num, &res);

        stack* calc_stack = NULL;
        s21_smartcalc(&res, &calc_stack);
        QString valueAsDouble = QString::number((double)calc_stack->value);
        ui->label->setText(valueAsDouble);
        s21_popBack(&calc_stack);
    } else {
        ui->label->setText("Ошибка. Некорректный ввод");
    }
}


void MainWindow::on_pushButton_Graphics_clicked()
{
    ui->widget->clearGraphs();

    QString xMa = ui->Xmax->text();
    long double Xmax = xMa.toDouble();

    QString xMi = ui->Xmin->text();
    long double Xmin = xMi.toDouble();

    QString yMa = ui->Ymax->text();
    long double Ymax = yMa.toDouble();

    QString yMi = ui->Ymin->text();
    long double Ymin = yMi.toDouble();

    QString ste = ui->step->text();
    long double step = ste.toDouble();

    if (s21_graphics(Xmax, Xmin, Ymin, Ymax)) {
        xBegin = Xmin;
        xEnd = Xmax;
        h = step;
        N = (xEnd - xBegin)/h + 2;
        ui->widget->xAxis->setRange(Xmin, Xmax);
        ui->widget->yAxis->setRange(Ymin, Ymax);

        QByteArray tmp = ui->label->text().toLocal8Bit();
        char* math = tmp.data();
        long double result;
        for (X = xBegin; X <= xEnd; X += h) {
            x.push_back(X);
            s21_calc(math, X, &result);
            y.push_back(result);
        }

        ui->widget->addGraph();
        ui->widget->graph(0)->addData(x, y);
        ui->widget->replot();
        x.clear();
        y.clear();
    } else {
        QMessageBox::about(this, "Ошибка", "Некорректный ввод");
    }
}


// погнал кредитный

void MainWindow::on_pushButton_kr_clicked()
{
        double summkr = 0;
        double interes_rate = 0;
        double term = 0;
        double monthly_payment = 0;
        double first_month_payment = 0;
        double last_month_payment = 0;
        double pereplata = 0;
        double total_payment = 0;

        summkr = ui->lineEdit_summkr->text().toDouble();
        interes_rate = ui->lineEdit_procst->text().toDouble();
        term = ui->lineEdit_srok_kr->text().toDouble();
        double monthly_interes_rate = interes_rate / (100 * 12);

        QString str_monthly_payment = "";
        QString str_pereplata = "";
        QString str_total_payment = "";
        QString str_first_month_payment = "";
        QString str_last_month_payment = "";

        if (ui->radioButton_ann->isChecked()) {
            if (ui->lineEdit_summkr->text() != "" && ui->lineEdit_procst->text() != "" && ui->lineEdit_srok_kr->text() != "") {
                monthly_payment = summkr * (monthly_interes_rate / (1 - pow((1 + monthly_interes_rate), -term)));
                total_payment = monthly_payment * term;
                pereplata = total_payment - summkr;
                str_monthly_payment = QString::number(monthly_payment);
                str_total_payment = QString::number(total_payment);
                str_pereplata = QString::number(pereplata);
                ui->lineEdit_esssh->setText(str_monthly_payment);
                ui->lineEdit_obchya->setText(str_total_payment);
                ui->lineEdit_pereplata->setText(str_pereplata);
            }
        }
        if (ui->radioButton_diff->isChecked()) {
            if (ui->lineEdit_summkr->text() != "" && ui->lineEdit_procst->text() != "" && ui->lineEdit_srok_kr->text() != "") {
                double rest = summkr;
                double monthly = 0;
                for (int i = 0; i < term; i++) {
                    if (i == 0) {
                        first_month_payment = rest * monthly_interes_rate + summkr / term;
                        total_payment += first_month_payment;
                        rest -= first_month_payment;
                    } else if (i == (term - 1)) {
                        last_month_payment = rest * monthly_interes_rate + summkr / term;
                        total_payment += last_month_payment;
                        rest -= last_month_payment;
                    } else {
                        monthly = rest * monthly_interes_rate + summkr / term;
                        total_payment += monthly;
                        rest -= monthly;
                    }
                }
                pereplata = total_payment - summkr;
                str_first_month_payment = QString::number(first_month_payment);
                str_last_month_payment = QString::number(last_month_payment);
                str_total_payment = QString::number(total_payment);
                str_pereplata = QString::number(pereplata);
                ui->lineEdit_esssh->setText(str_first_month_payment + "..." + str_last_month_payment);
                ui->lineEdit_obchya->setText(str_total_payment);
                ui->lineEdit_pereplata->setText(str_pereplata);
            }
        }
}

//погнал депозитный


void MainWindow::on_pushButton_kr_2_clicked()
{
    double sumdep = 0;
    double srokvkl = 0;
    double proc_st = 0;
    double nal_st = 0;
    double per_plat = 0;
    double sum1 = 0;
    double mes1 = 0;
    double sum2 = 0;
    double mes2 = 0;

    double sum_konec = 0;
    double nachisl = 0;
    double sum_nal = 0;

    sumdep = ui->lineEdit_sumdep->text().toDouble();
    srokvkl = ui->lineEdit_srokvkl->text().toDouble();
    proc_st = ui->lineEdit_proc_st->text().toDouble();
    nal_st = ui->lineEdit_nal_st->text().toDouble();
    per_plat = ui->lineEdit_per_plat->text().toDouble();
    sum1 = ui->lineEdit_sum1->text().toDouble();
    mes1 = ui->lineEdit_mes1->text().toDouble();
    sum2 = ui->lineEdit_sum2->text().toDouble();
    mes2 = ui->lineEdit_mes2->text().toDouble();

    QString str_sum_konec = "";
    QString str_nachisl = "";
    QString str_sum_nal = "";

    if (ui->checkBox->isChecked()) {
        double nachisl_proc_mes = 0;
        double nalog_v_mes = 0;
        for (int i = 0; i < srokvkl; i++) {
            nachisl_proc_mes = (((sumdep/100)*proc_st)/12);
            nalog_v_mes = nachisl_proc_mes * (nal_st / 100);
            nachisl_proc_mes = nachisl_proc_mes - nalog_v_mes;
            sumdep += nachisl_proc_mes;
            nachisl += nachisl_proc_mes;
            sum_nal += nalog_v_mes;
            if (i == mes1 && sum1 > 0) {
                sumdep += sum1;
            }
            if (i == mes2 && sum2 > 0) {
                sumdep -= sum2;
            }
        }
    } else if (mes2 != 0 || mes1 != 0) {
        double nachisl_proc_mes = 0;
        for (int i = 0; i < srokvkl; i++) {
            nachisl_proc_mes = (((sumdep/100)*proc_st)/12);
            nachisl += nachisl_proc_mes;
            if (i == mes1 && sum1 > 0) {
                sumdep += sum1;
            }
            if (i == mes2 && sum2 > 0) {
                sumdep -= sum2;
            }
        }
        sum_nal = nachisl * (nal_st / 100);
        nachisl = nachisl - sum_nal;
    } else {
        nachisl = (((sumdep/100)*proc_st)/12)*srokvkl;
        sum_nal = nachisl * (nal_st / 100);
        nachisl = nachisl - sum_nal;
    }

    sum_konec = nachisl + sumdep;

    str_nachisl = QString::number(nachisl);
    str_sum_konec = QString::number(sum_konec);
    str_sum_nal= QString::number(sum_nal);

    ui->lineEdit_sum_konec->setText(str_sum_konec);
    ui->lineEdit_nachisl->setText(str_nachisl);
    ui->lineEdit_sum_nal->setText(str_sum_nal);
}

