// Райков ИВТ-20
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "calculatorclass.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

CalculatorClass calc;                   // создаем объект класса калькулятора

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void read();

    void on_Button_equals_clicked();    // равно

    void on_Button_plus_clicked();      // плюс

    void on_Button_minus_clicked();     // минус

    void on_Button_mult_clicked();      // умножить

    void on_Button_division_clicked();  // разделить

    void on_Button_power_clicked();     // возвести в степень

    void on_Button_sin_clicked();       // синус

    void on_Button_cos_clicked();       // косинус

    void on_Button_tan_clicked();       // тангнс

    void on_Button_exp_clicked();       // експонента

    void on_Button_ln_clicked();        // натуральный логарифм

    void on_Button_clean_clicked();     // очистка

    void on_Button_dot_clicked();       // точка

    /*________Цыферки________*/
    void on_Button_0_clicked();

    void on_Button_1_clicked();

    void on_Button_2_clicked();

    void on_Button_3_clicked();

    void on_Button_4_clicked();

    void on_Button_5_clicked();

    void on_Button_6_clicked();

    void on_Button_7_clicked();

    void on_Button_8_clicked();

    void on_Button_9_clicked();
    /*________Конец цыферок________*/

    void on_about_developer_triggered();    // о разработчике

    void on_about_programm_triggered();     // о программе

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
