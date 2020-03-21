#ifndef SQRTEXPRESSION_H
#define SQRTEXPRESSION_H

#include "UnaryExpression.h"
#include <QErrorMessage>

class SqrtExpression : UnaryExpression {
public:
    SqrtExpression(Expression* x);
    double solve();
};

#endif // SQRTEXPRESSION_H
