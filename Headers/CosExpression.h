#ifndef COSEXPRESSION_H
#define COSEXPRESSION_H

#include "UnaryExpression.h"

class CosExpression : public UnaryExpression {
public:
    CosExpression(Expression* x);
    /* Konstruktor yang menerima pointer ke satu buah ekspresi */
    double solve();
};

#endif // COSEXPRESSION_H
