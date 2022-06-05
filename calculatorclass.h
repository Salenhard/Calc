// Райков ИВТ-20
#ifndef CALCULATORCLASS_H
#define CALCULATORCLASS_H

enum opperator          // перечисление возможных мат. операций
{
    NONE,
    PLUS,
    MINUS,
    MULT,
    DIVISION,
    POW,
    SIN,
    COS,
    TAN,
    EXP,
    LN,
};

class CalculatorClass {
private:
    double value;           // первая переменная/ответ
    opperator op;       // узнаём, какая мат. операция выбрана (оператор)
public:
    void setValue(double x);
    void setOP(opperator op);
    void setParams(double x, opperator op);

    double neg();
    double getValue();
    opperator getOP();

    double calc(double a);
    CalculatorClass();
    };

#endif // CALCULATORCLASS_H
