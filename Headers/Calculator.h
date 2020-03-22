#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Button.h"
#include "Solver.h"


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
    void parenthesis_onClick();

private:
    Button *createButton(const QString &text, const char *member);
    bool afterEqual;
    bool nextNegative;
    QQueue<double> Memory;
    QString currentNum;
    QString previousAns;
    QList<QString> Tokens;
    int lastToken;  // 0 - nothing, 1 - unary, 2 - binary, 3 - number
    int countParenthesis;
    QLineEdit *display;
    enum { NumDigitButtons = 10 };
    Button *digitButtons[NumDigitButtons];
};

#endif // CALCULATOR_H
