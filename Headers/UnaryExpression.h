#ifndef UNARYEXPRESSION_H
#define UNARYEXPRESSION_H

#include "Expression.h"

class UnaryExpression : public Expression {
protected:
    Expression* x;

public:
    UnaryExpression(Expression* x);
    virtual double solve() = 0;
};

#endif // UNARYEXPRESSION_H
