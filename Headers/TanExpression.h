#ifndef TANEXPRESSION_H
#define TANEXPRESSION_H

#include "UnaryExpression.h"

class TanExpression : public UnaryExpression {
public:
    TanExpression(Expression* x);
    /* Konstruktor yang menerima pointer ke satu buah ekspresi */
    double solve();
};

#endif // TANEXPRESSION_H
