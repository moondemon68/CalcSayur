#ifndef SUBTRACTEXPRESSION_H
#define SUBTRACTEXPRESSION_H

#include "BinaryExpression.h"

class SubtractExpression : public BinaryExpression {
public:
    /**
     * Konstruktor untuk SubtractExpression.
     *
     * @param Pointer ekspresi x
     * @param Pointer ekspresi y
     */
    SubtractExpression(Expression* x, Expression* y);
    /**
     * Menyelesaikan pengurangan
     *
     * @return hasil pengurangan ekspresi x dan y
     */
    double solve();
};

#endif // SUBTRACTEXPRESSION_H
