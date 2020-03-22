#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "Expression.h"

class BinaryExpression : public Expression {
protected:
    Expression* x;
    Expression* y;

public:
    BinaryExpression(Expression* x, Expression* y);
    /* Konstruktor yang menerima pointer ke dua buah ekspresi */
    virtual double solve() = 0;
};

#endif // BINARYEXPRESSION_H
