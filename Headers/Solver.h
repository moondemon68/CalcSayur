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
    /**
     * Method calculateBinary.
     *
     * @param QString left
     * @param QString op
     * @param QString right
     *
     * @return hasil perhitungan binary dalam double
     */
    static double calculateBinary(QString left, QString op, QString right);

    /**
     * Method calculateUnary.
     *
     * @param QString op
     * @param QString num
     *
     * @return hasil perhitungan unary dalam double
     */
    static double calculateUnary(QString op, QString num);

    /**
     * Method calculateTokens.
     *
     * @param List of QString Tokens
     *
     * @return hasil perhitungan kalkulator dalam double
     */
    static double calculateTokens(QList<QString> Tokens);

    /**
     * Method isNumber.
     *
     * @param QString token
     *
     * @return hasil boolean apakah token merupakan angka
     */
    static bool isNumber(QString token);

    /**
     * Method isUnary.
     *
     * @param QString token
     *
     * @return hasil boolean apakah token termasuk dalam operator unary
     */
    static bool isUnary(QString token);

    /**
     * Method isBinary.
     *
     * @param QString token
     *
     * @return hasil boolean apakah token termasuk dalam operator binary
     */
    static bool isBinary(QString token);

    /**
     * Method priority.
     *
     * @param QString token
     *
     * @return hasil operator yang harus diprioritaskan dalam int
     */
    static int priority(QString token);

    /**
     * Method process.
     *
     * @param address Stack of Qstring Value
     * @param QString op
     *
     * Proses bagaimana kalkulator menghandle operator binary dan unary
     */
    static void process(QStack<QString>& Value, QString op);
    static void initializeSet();
    static QSet<QString> binaryOperator;
    static QSet<QString> unaryOperator;

private:
    Solver() {}
};

#endif // SOLVER_H
