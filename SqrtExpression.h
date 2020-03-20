#ifndef SQRTEXPRESSION_H
#define SQRTEXPRESSION_H

#include "UnaryExpression.h"

class SqrtExpression : UnaryExpression {
public:
    SqrtExpression(Expression* x);
    double solve();
};

#endif // SQRTEXPRESSION_H
