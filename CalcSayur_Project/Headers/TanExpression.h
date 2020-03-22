#ifndef TANEXPRESSION_H
#define TANEXPRESSION_H

#include "UnaryExpression.h"

class TanExpression : public UnaryExpression {
public:
    /**
     * Konstruktor untuk TanExpression.
     *
     * @param Pointer ekspresi x
     */
    TanExpression(Expression* x);
    /**
     * Menyelesaikan fungsi trigonometri tangent
     *
     * @return hasil tangent ekspresi x
     */
    double solve();
};

#endif // TANEXPRESSION_H
