#ifndef COSEXPRESSION_H
#define COSEXPRESSION_H

#include "UnaryExpression.h"

class CosExpression : public UnaryExpression {
public:
    /**
     * Konstruktor untuk CosExpression.
     *
     * @param Pointer ekspresi x
     */
    CosExpression(Expression* x);
    /**
     * Menyelesaikan fungsi trigonometri kosinus
     *
     * @return hasil kosinus ekspresi x
     */
    double solve();
};

#endif // COSEXPRESSION_H
