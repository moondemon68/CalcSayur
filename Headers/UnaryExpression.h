#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include "Expression.h"

class UnaryExpression : public Expression {
protected:
    Expression* x;

public:
    UnaryExpression(Expression* x);
    /* Konstruktor yang menerima pointer ke satu buah ekspresi */
    virtual double solve() = 0;
    /* Abstract f
};

#endif // UNARYEXPRESSION_H
