// Райков ИВТ-20
#include "calculatorclass.h"
#include <cmath>
#include <QString>

CalculatorClass::CalculatorClass()                      // конструктор по умолчанию
{
    setParams(0,PLUS);                                    // op=PLUS - выбрано сложение (позволить начинать не с 0)
}

void CalculatorClass::setParams(double value, opperator op)  // установить x и op
{
    setValue(value);
    setOP(op);
}

void CalculatorClass::setValue(double value)                   // установить x
{
    this->value=value;
}

void CalculatorClass::setOP(opperator op)              // установить op
{
    this->op=op;
}

double CalculatorClass::getValue()                         // получить x
{
    return value;
}

opperator CalculatorClass::getOP()                     // получить op
{
    return op;
}

double CalculatorClass::calc(double secondValue)                  // вычисления
{
    double r=0;                                         // результат мат. операции

    if (op==NONE)                                       // мат. операция не выбрана
        r=getValue();                                      // x остаётся прежним

    else if (op==PLUS)                                  // сложение
        r=(getValue()+secondValue);

    else if (op==MINUS)                                 // вычитание
        r=(getValue()-secondValue);

    else if (op==MULT)                                  // умножение
        r=(getValue()*secondValue);


    else if (op==DIVISION)                              // деление
    {
        if (secondValue!=0)
            r=(getValue()/secondValue);
        else                                            // если делим на 0, то приводим объект класса к первноначальным значениям
        {
            QString str="Делить на 0 нельзя!";
            throw str;
        }
    }
    else if (op==POW)                                   // возведение x в степень a
        r=pow(getValue(), secondValue);

    else if (op==SIN)                                   // синус
        r=sin(getValue());

    else if (op==COS)                                   // косинус
        r=cos(getValue());

    else if (op==TAN)                                   // тангенс
        r=tan(getValue());

    else if (op==EXP)                                   // експонента (примерно)
        r=exp(getValue());

    else if (op==LN)                                    // натуральный логарифи (почему-то записывается, как "log")
    {
        if (getValue()>0)
            r=log(getValue());
        else if (getValue()==0)
        {
            QString str="Ln(0) не определен";
            throw str;
        }
        else if (getValue()<0)
        {
            QString str="Ln() не может быть от отрицательного числа!";
            throw str;
        }
    }
    return r;
}
