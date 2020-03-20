#ifndef ADDEXPRESSION_H
#define ADDEXPRESSION_H

#include "BinaryExpression.h"

class AddExpression : public BinaryExpression {
public:
    AddExpression(Expression* x, Expression* y);
    double solve();
};

#endif // ADDEXPRESSION_H
