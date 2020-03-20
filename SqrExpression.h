#ifndef SQREXPRESSION_H
#define SQREXPRESSION_H

#include "UnaryExpression.h"

class SqrExpression : UnaryExpression {
public:
    SqrExpression(Expression* x);
    double solve();
};

#endif // SQREXPRESSION_H
