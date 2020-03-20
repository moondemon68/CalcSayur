#ifndef SUBTRACTEXPRESSION_H
#define SUBTRACTEXPRESSION_H

#include "BinaryExpression.h"

class SubtractExpression : public BinaryExpression {
public:
    SubtractExpression(Expression* x, Expression* y);
    double solve();
};

#endif // SUBTRACTEXPRESSION_H
