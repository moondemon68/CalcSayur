#ifndef SQREXPRESSION_H
#define SQREXPRESSION_H

#include "UnaryExpression.h"

class SqrExpression : public UnaryExpression {
public:
    SqrExpression(Expression* x);
    /* Konstruktor yang menerima pointer ke satu buah ekspresi */
    double solve();
};

#endif // SQREXPRESSION_H
