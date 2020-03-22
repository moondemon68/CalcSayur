#ifndef SQRTEXPRESSION_H
#define SQRTEXPRESSION_H

#include "UnaryExpression.h"
#include <QErrorMessage>

class SqrtExpression : public UnaryExpression {
public:
    SqrtExpression(Expression* x);
    /* Konstruktor yang menerima pointer ke satu buah ekspresi */
    double solve();
};

#endif // SQRTEXPRESSION_H
