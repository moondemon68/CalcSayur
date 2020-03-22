#ifndef SOLVER_H
#define SOLVER_H

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

#include <iostream>
#include <QStack>
#include <QList>
#include <QSet>

class Solver {
public:
    static double calculateBinary(QString left, QString op, QString right);
    static double calculateUnary(QString op, QString num);
    static double calculateTokens(QList<QString> Tokens);
    static bool isNumber(QString token);
    static bool isUnary(QString token);
    static bool isBinary(QString token);
    static int priority(QString token);
    static void process(QStack<QString>& Value, QString op);
    static void initializeSet();
    static QSet<QString> binaryOperator;
    static QSet<QString> unaryOperator;

private:
    Solver() {}
};

#endif // SOLVER_H
