#ifndef DIVIDEEXPRESSION_H
#define DIVIDEEXPRESSION_H

#include "BinaryExpression.h"
#include <QErrorMessage>

class DivideExpression : public BinaryExpression {
public:
    DivideExpression(Expression* x, Expression* y);
    double solve();
};

#endif // DIVIDEEXPRESSION_H
