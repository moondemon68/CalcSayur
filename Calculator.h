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
#include "NegativeExpression.h"
#include "TerminalExpression.h"

#include <QWidget>
#include <QQueue>
#include <QStack>
#include <QList>
#include <QLineEdit>
#include <QGridLayout>
#include <QErrorMessage>
#include <QSet>

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
    double calculateBinary(QString left, QString op, QString right);
    double calculateUnary(QString op, QString num);
    double calculateTokens();
    bool isNumber(QString token);
    bool isUnary(QString token);
    bool isBinary(QString token);
    QSet<QString> binaryOperator;
    QSet<QString> unaryOperator;
    bool afterEqual;
    QQueue<double> Memory;
    QString currentNum;
    QString previousAns;
    QList<QString> Tokens;
    int lastToken;  // 0 - nothing, 1 - unary, 2 - binary, 3 - number
    QLineEdit *display;
    enum { NumDigitButtons = 10 };
    Button *digitButtons[NumDigitButtons];
};

#endif // CALCULATOR_H
