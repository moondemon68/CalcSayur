#ifndef NEGATIVEEXPRESSION_H
#define NEGATIVEEXPRESSION_H

#include "UnaryExpression.h"

class NegativeExpression : public UnaryExpression {
public:
    NegativeExpression(Expression* x);
    double solve();
};

#endif // NEGATIVEEXPRESSION_H
