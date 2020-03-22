#ifndef SQRTEXPRESSION_H
#define SQRTEXPRESSION_H

#include "UnaryExpression.h"
#include <QErrorMessage>

class SqrtExpression : public UnaryExpression {
public:
    /**
     * Konstruktor untuk SqrtExpression.
     *
     * @param Pointer ekspresi x
     */
    SqrtExpression(Expression* x);
    /**
     * Menyelesaikan pengakaran kuadrat
     *
     * @return hasil akar kuadrat ekspresi x
     */
    double solve();
};

#endif // SQRTEXPRESSION_H
