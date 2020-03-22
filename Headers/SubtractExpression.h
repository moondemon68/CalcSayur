#ifndef SUBTRACTEXPRESSION_H
#define SUBTRACTEXPRESSION_H

#include "BinaryExpression.h"

class SubtractExpression : public BinaryExpression {
public:
    SubtractExpression(Expression* x, Expression* y);
    /* Konstruktor yang menerima pointer ke dua buah ekspresi */
    double solve();
};

#endif // SUBTRACTEXPRESSION_H
