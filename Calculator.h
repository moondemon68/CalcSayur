#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Button.h"
#include "Expression.h"

#include <QWidget>
#include <QQueue>
#include <QStack>
#include <QLineEdit>
#include <QGridLayout>
#include <QErrorMessage>

class Calculator : public QWidget
{
    Q_OBJECT
public:
    Calculator(QWidget *parent = nullptr);

private slots:
    void digit_onClick();
    void point_onClick();
    void binaryOperator_onClick();
    void unaryOperator_onClick();
    void equal_onClick();
    void ans_onClick();
    void MC_onClick();
    void MR_onClick();
    void clear_onClick();

private:
    Button *createButton(const QString &text, const char *member);
    void calculate();
    QQueue<double> Memory;
    QString currentNum;
    double previousAns;
//    QStack<Expression> Expressions;
    QLineEdit *display;
    enum { NumDigitButtons = 10 };
    Button *digitButtons[NumDigitButtons];
};

#endif // CALCULATOR_H
