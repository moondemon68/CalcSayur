#include "SubtractExpression.h"

SubtractExpression::SubtractExpression(Expression* x, Expression* y) : BinaryExpression(x, y) {
    //
}

double SubtractExpression::solve() {
    return x->solve() - y->solve();
}
