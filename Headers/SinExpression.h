#ifndef SINEXPRESSION_H
#define SINEXPRESSION_H

#include "UnaryExpression.h"

class SinExpression : public UnaryExpression {
public:
    SinExpression(Expression* x);
    /* Konstruktor yang menerima pointer ke satu buah ekspresi */
    double solve();
};

#endif // SINEXPRESSION_H
