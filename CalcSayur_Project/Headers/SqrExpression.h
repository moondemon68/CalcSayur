#ifndef SQREXPRESSION_H
#define SQREXPRESSION_H

#include "UnaryExpression.h"

class SqrExpression : public UnaryExpression {
public:
    /**
     * Konstruktor untuk SqrExpression.
     *
     * @param Pointer ekspresi x
     */
    SqrExpression(Expression* x);
    /**
     * Menyelesaikan pangkat 2 (persegi)
     *
     * @return hasil persegi ekspresi x
     */
    double solve();
};

#endif // SQREXPRESSION_H
