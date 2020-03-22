#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include "Expression.h"

class UnaryExpression : public Expression {
protected:
    Expression* x;

public:
    /**
     * Konstruktor untuk UnaryExpression.
     *
     * @param Pointer ekspresi x
     */
    UnaryExpression(Expression* x);
    /**
     *
     * method abstract yang merupakan polymorphism
     */
    virtual double solve() = 0;
};

#endif // UNARYEXPRESSION_H
