#ifndef MULTIPLYEXPRESSION_H
#define MULTIPLYEXPRESSION_H

#include "BinaryExpression.h"

class MultiplyExpression : public BinaryExpression {
public:
    /**
     * Konstruktor untuk MultiplyExpression.
     *
     * @param Pointer ekspresi x
     * @param Pointer ekspresi y
     */
    MultiplyExpression(Expression* x, Expression* y);
    /**
     * Menyelesaikan perkalian
     *
     * @return hasil perkalian ekspresi x dan y
     */
    double solve();
};

#endif // MULTIPLYEXPRESSION_H
