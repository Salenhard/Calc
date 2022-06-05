// Райков ИВТ-20
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
// todo... +- button
void MainWindow::read()                                         // читаем из Edit и делаем предидущую мат. операцию
{
    double a=0;                                                 // создаём временную переменную
    a = ui->Edit_screen->text().toDouble();                     // присваеваем ей значение из QLineEdit
    ui->Edit_screen->setText("");                               // очищаем поле для дальнейших расчётов

    try
    {
        calc.setValue(calc.calc(a));                               // выполняем пред. операцию (если была) и записываем результат в x
    }
    catch (const QString &str)
    {
        QMessageBox::information(this, "Ошибка", str);          // окно с сообщением
    }
}

void MainWindow::on_Button_equals_clicked()                     // равно - показать ответ
{
    read();                                                     // выполнение пред. мат. операции
    calc.setOP(NONE);                                          // сбрасываем мат. операцию для дальнейшей работы

    ui->Edit_screen->setText(QString::number(calc.getValue()));    // выводим результат вычислений
}

void MainWindow::on_Button_plus_clicked()                       // сложение
{
    read();                                                     // выполнение пред. мат. операции

    calc.setOP(PLUS);                                          // запоминаем мат. операцию
}

void MainWindow::on_Button_minus_clicked()                      // вычитание
{
    read();                                                     // выполнение пред. мат. операции

    calc.setOP(MINUS);                                         // запоминаем мат. операцию
}

void MainWindow::on_Button_mult_clicked()                       // умножение
{
    read();                                                     // выполнение пред. мат. операции

    calc.setOP(MULT);                                          // запоминаем мат. операцию
}

void MainWindow::on_Button_division_clicked()                   // деление
{
    read();                                                     // выполнение пред. мат. операции

    calc.setOP(DIVISION);                                      // запоминаем мат. операцию
}

void MainWindow::on_Button_power_clicked()                      // возв. в степень
{
    read();                                                     // выполнение пред. мат. операции

    calc.setOP(POW);                                           // запоминаем мат. операцию
}

void MainWindow::on_Button_sin_clicked()                        // синус
{
    read();                                                     // выполнение пред. мат. операции

    calc.setOP(SIN);                                           // запоминаем мат. операцию
}

void MainWindow::on_Button_cos_clicked()                        // косинус
{
    read();                                                     // выполнение пред. мат. операции

    calc.setOP(COS);                                           // запоминаем мат. операцию
}

void MainWindow::on_Button_tan_clicked()                        // тангенс
{
    read();                                                     // выполнение пред. мат. операции

    calc.setOP(TAN);                                           // запоминаем мат. операцию
}

void MainWindow::on_Button_exp_clicked()                        // експонента
{
    read();                                                     // выполнение пред. мат. операции

    calc.setOP(EXP);                                           // запоминаем мат. операцию
}

void MainWindow::on_Button_ln_clicked()                         // натуральный логарифм
{
    read();                                                     // выполнение пред. мат. операции

    calc.setOP(LN);                                            // запоминаем мат. операцию
}

void MainWindow::on_Button_dot_clicked()                        // точка для цыфр после запятой
{
    ui->Edit_screen->insert(".");
}

void MainWindow::on_Button_clean_clicked()                      // очистка всего  (полей класа и Edit)
{
    ui->Edit_screen->setText("");                               // очищаем поле для дальнейших расчётов
    calc.setParams(0,PLUS);                                       // устанавливаем значения по умолчанию
}

/*___________Цыферки___________*/

void MainWindow::on_Button_0_clicked()
{
    ui->Edit_screen->insert("0");
}

void MainWindow::on_Button_1_clicked()
{
    ui->Edit_screen->insert("1");
}

void MainWindow::on_Button_2_clicked()
{
    ui->Edit_screen->insert("2");
}

void MainWindow::on_Button_3_clicked()
{
    ui->Edit_screen->insert("3");
}

void MainWindow::on_Button_4_clicked()
{
    ui->Edit_screen->insert("4");
}

void MainWindow::on_Button_5_clicked()
{
    ui->Edit_screen->insert("5");
}

void MainWindow::on_Button_6_clicked()
{
    ui->Edit_screen->insert("6");
}

void MainWindow::on_Button_7_clicked()
{
    ui->Edit_screen->insert("7");
}

void MainWindow::on_Button_8_clicked()
{
    ui->Edit_screen->insert("8");
}

void MainWindow::on_Button_9_clicked()
{
    ui->Edit_screen->insert("9");
}


void MainWindow::on_about_developer_triggered()                     // о разработчике
{
    QMessageBox::information(this, "О разработчике", "Райков Алексей \n ИВТ-20");
}


void MainWindow::on_about_programm_triggered()                      // о программе
{
    QMessageBox::information(this, "О программе", "Калькулятор на языке C++ в фреймворке Qt Creator \n"
                             "Для взаимодействия Вы можете использовать мышь и/или клавиатуру \n"
                             "Клавиатурые сокращения (EN): \n\n"
                             "Delite - очистить всё \n"
                             "Shift+6 - возведение в степень \n"
                             "S - синус \n"
                             "C - косинус \n"
                             "T - тангенс \n"
                             "E - експонента \n"
                             "L - натуральный логарифм \n");
}

void MainWindow::on_pushButton_clicked()
{
   double a = ui->Edit_screen->text().toDouble();
   a = -1*a;
   ui->Edit_screen->setText(QString::number(a));
}

