#ifndef DIVIDEEXPRESSION_H
#define DIVIDEEXPRESSION_H

#include "BinaryExpression.h"
#include <QErrorMessage>

class DivideExpression : public BinaryExpression {
public:
    /**
     * Konstruktor untuk DivideExpression.
     *
     * @param Pointer ekspresi x
     * @param Pointer ekspresi y
     */
    DivideExpression(Expression* x, Expression* y);
    /**
     * Menyelesaikan pembagian
     *
     * @throws bila terjadi pembagian dengan 0
     * @return hasil pembagian ekspresi x dan y
     */
    double solve();
};

#endif // DIVIDEEXPRESSION_H
