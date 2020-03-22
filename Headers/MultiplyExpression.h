#ifndef MULTIPLYEXPRESSION_H
#define MULTIPLYEXPRESSION_H

#include "BinaryExpression.h"

class MultiplyExpression : public BinaryExpression {
public:
    MultiplyExpression(Expression* x, Expression* y);
    double solve();
};

#endif // MULTIPLYEXPRESSION_H
