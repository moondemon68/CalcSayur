#ifndef NEGATIVEEXPRESSION_H
#define NEGATIVEEXPRESSION_H

#include "UnaryExpression.h"

class NegativeExpression : public UnaryExpression {
public:
    NegativeExpression(Expression* x);
    /* Konstruktor yang menerima pointer ke satu buah ekspresi */
    double solve();
};

#endif // NEGATIVEEXPRESSION_H
