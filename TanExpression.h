#ifndef TANEXPRESSION_H
#define TANEXPRESSION_H

#include "UnaryExpression.h"

class TanExpression : public UnaryExpression {
public:
    TanExpression(Expression* x);
    double solve();
};

#endif // TANEXPRESSION_H
