#include "Headers/MultiplyExpression.h"

MultiplyExpression::MultiplyExpression(Expression* x, Expression* y) : BinaryExpression(x, y) {
    //
}

double MultiplyExpression::solve() {
    return x->solve() * y->solve();
}
