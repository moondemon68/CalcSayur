#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression* x;
    Expression* y;

public:
    /**
     * Konstruktor untuk BinaryExpression.
     *
     * @param Pointer ekspresi x
     * @param Pointer ekspresi y
     */
    BinaryExpression(Expression* x, Expression* y);
    /**
     *
     * method abstract yang merupakan polymorphism
     */
    virtual double solve() = 0;
};

#endif // BINARYEXPRESSION_H
