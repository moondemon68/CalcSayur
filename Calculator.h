#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Button.h"
#include "Expression.h"
#include "BinaryExpression.h"
#include "AddExpression.h"
#include "SubtractExpression.h"
#include "MultiplyExpression.h"
#include "DivideExpression.h"
#include "UnaryExpression.h"
#include "SinExpression.h"
#include "CosExpression.h"
#include "TanExpression.h"
#include "SqrExpression.h"
#include "SqrtExpression.h"
#include "TerminalExpression.h"

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
    double calculateBinary();
    double calculateUnary();
    bool afterEqual;
    QQueue<double> Memory;
    QString currentNum;
    QString currentUnary;
    QString previousAns;
    QStack<double> Operands;
    QStack<QString> Operators;
    QLineEdit *display;
    enum { NumDigitButtons = 10 };
    Button *digitButtons[NumDigitButtons];
};

#endif // CALCULATOR_H
