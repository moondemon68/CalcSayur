#ifndef NEGATIVEEXPRESSION_H
#define NEGATIVEEXPRESSION_H

#include "UnaryExpression.h"

class NegativeExpression : public UnaryExpression {
public:
    /**
     * Konstruktor untuk NegativeExpression.
     *
     * @param Pointer ekspresi x
     */
    NegativeExpression(Expression* x);
    /**
     *
     * @return hasil negatif ekspresi x
     */
    double solve();
};

#endif // NEGATIVEEXPRESSION_H
