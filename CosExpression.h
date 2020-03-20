#ifndef COSEXPRESSION_H
#define COSEXPRESSION_H

#include "UnaryExpression.h"

class CosExpression : UnaryExpression {
public:
    CosExpression(Expression* x);
    double solve();
};

#endif // COSEXPRESSION_H
