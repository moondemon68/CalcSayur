#ifndef SINEXPRESSION_H
#define SINEXPRESSION_H

#include "UnaryExpression.h"

class SinExpression : public UnaryExpression {
public:
    /**
     * Konstruktor untuk SinExpression.
     *
     * @param Pointer ekspresi x
     */
    SinExpression(Expression* x);
    /**
     * Menyelesaikan fungsi trigonometri sinus
     *
     * @return hasil sinus ekspresi x
     */
    double solve();
};

#endif // SINEXPRESSION_H
