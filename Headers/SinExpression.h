#ifndef SINEXPRESSION_H
#define SINEXPRESSION_H

#include "UnaryExpression.h"

class SinExpression : public UnaryExpression {
public:
    SinExpression(Expression* x);
    double solve();
};

#endif // SINEXPRESSION_H
