#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression* x;
    Expression* y;

public:
    BinaryExpression(Expression* x, Expression* y);
    virtual double solve() = 0;
};

#endif // BINARYEXPRESSION_H
